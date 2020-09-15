#pragma once

#include <aegis.hpp>
#include "slow_flush.h"
#include "supermutex.h"

#include <codecvt>
#include <regex>

const unsigned long long mee_dev = 280450898885607425; // myself, for debugging and help
const std::string command_global = "lsw/wl";
const int color_embed_default = 0xd8954d;
const size_t max_len = 1000; // Less or equal to 2000, but it shouldn't be lower than 500 for better results. 2000 is also not very good, it may cause some issues.
const size_t min_len = max_len / 4; // slicing tries until what size?
const bool cant_send_send_dots_then = true; // errors sending will be changed to dots if true (weird characters)
const std::chrono::milliseconds timeout_time = std::chrono::milliseconds(60000); // 1 minute
const std::regex regex_link("http(?:s?)://([\\w_-]+(?:(?:\\.[\\w_-]+)+))([\\w.,@?^=%&:/~+#-]*[\\w@?^=%&/~+#-])?");
const std::string common_bar = u8"——————————————————————————————";
const auto div_memory_calc = (1 << 20);
const std::string version = "V2.0.400";


using namespace LSW::v5::Tools;

aegis::snowflake stdstoulla(std::string);

std::string narrow(const std::wstring&);
std::wstring widen(const std::string&);

std::string transform_weirdo(const std::string);
std::string format_emoji(aegis::gateway::objects::emoji);

class Language {
	struct each {
		nlohmann::json lang;
		std::vector<std::string> names_alias;
	};

	std::vector<each> langs;
public:
	Language();

	nlohmann::json get_lang(std::string) const;
};







struct each_block {
	std::string title, subtitle;
	std::string content;
	aegis::snowflake user_id;
	bool has_emd = false;
	aegis::gateway::objects::embed emb;

	bool same_user(const each_block&);

	// block of title
	std::string generate_title();
	// prefix + end (doesn't include embed)
	std::string generate();
	// message prefix, aka timestamp, name and stuff
	std::string generate_prefix();
	// content itself (doesn't include embed)
	std::string generate_end();
};


struct guild_data {
	aegis::snowflake channel_log = 0;
	bool deep_data = false;
	std::string region;
	std::string alias_cmd;

	//std::mutex general_mutex;
	std::vector<aegis::snowflake> adm_tags;
	std::vector<aegis::snowflake> ignore_channels;

	void load_config(nlohmann::json);
	nlohmann::json export_config();
};

class Guild {
	static Language langs;

	nlohmann::json lng;

	bool firstt = true;

	aegis::snowflake guild_id;
	std::shared_ptr<spdlog::logger> logg;
	std::shared_ptr<aegis::core> core;

	guild_data data;
	aegis::snowflake last_user = 0;

	aegis::guild* thus = nullptr;
	aegis::channel* flush_channel = nullptr;

	//weirdMutex blocks_m;
	//std::vector<each_block> blocks;// , emergency;
	//std::mutex emergency_m;
	std::string buf;
	std::recursive_mutex buf_control;

	SuperMutex working_on;

	//std::function<void(void)> restart_please;
	//bool ON_RESTART = false;


	void load_config();
	void save_config();

	void refresh_flush_channel();
	void refresh_language(const std::string = "default");

	// gets text in local idiom (safe), bool = first char UPPER or not
	std::string local(const std::string, const bool = false);

	// do not touch bool. This slices up buffer many times if fail (recursively).
	bool _flush_custom(const std::string, const bool = false); 
	//void flush();

	void flush_one_block(each_block);

	// ` becomes \`, @ becomes \@, links become <links>
	std::string _fix_content(const std::string&);

	bool is_chat_valid(const aegis::snowflake);
	bool is_user_admin(const aegis::snowflake);

	void send_message_default(aegis::channel&, std::string, bool, std::string = "", int = color_embed_default);

	// won't verify channel or user admin rights.
	void command(std::vector<std::string>, aegis::channel&);

	// content, chatid, userid
	bool check_command(std::string, aegis::channel&, const aegis::snowflake);

	//void giveup_everything_restart();

	void task_welcome_message();
	void task_reset_message();
	void task_end_message();
public:
	Guild(const aegis::snowflake, std::shared_ptr<aegis::core>/*, std::function<void(void)>*/);
	~Guild();

	// on a core restart, pause everything. Will continue on a reassign()
	//void force_pause();
	// set all emergency to blocks
	//void fix_emergency();

	void reassign(std::shared_ptr<aegis::core>);

	void force_save();

	bool broadcast(std::string);
	bool force_flush_buffer();

	bool is_guild(const aegis::snowflake);

	void handle(aegis::gateway::events::message_create&);
	void handle(aegis::gateway::events::message_update&);
	void handle(aegis::gateway::events::message_reaction_add&);
	void handle(aegis::gateway::events::message_reaction_remove&);
	void handle(aegis::gateway::events::message_delete&);
	void handle(aegis::gateway::events::channel_create&);
	void handle(aegis::gateway::events::channel_update&);
	void handle(aegis::gateway::events::channel_delete&);
	void handle(aegis::gateway::events::guild_ban_add&);
	void handle(aegis::gateway::events::guild_ban_remove&);
	void handle(aegis::gateway::events::guild_role_create&);
	void handle(aegis::gateway::events::guild_role_update&);
	void handle(aegis::gateway::events::guild_role_delete&);
};