#pragma once

#include <aegis.hpp>
#include "custom_events_data.h"
#include "supermutex.h"

#include <codecvt>
#include <regex>

const unsigned long long mee_dev = 280450898885607425; // myself, for debugging and help
const std::string command_global = "lsw/wl";
const int color_embed_default = 0xd8954d;
const size_t max_len = 2000; // Less or equal to 2000, but it shouldn't be lower than 500 for better results. 2000 is also not very good, it may cause some issues.
const std::regex regex_link("http(?:s?)://([\\w_-]+(?:(?:\\.[\\w_-]+)+))([\\w.,@?^=%&:/~+#-]*[\\w@?^=%&/~+#-])?");
const std::string common_bar = u8"——————————————————————————————";
const auto div_memory_calc = (1 << 20);
const std::chrono::milliseconds time_to_flush = std::chrono::milliseconds((size_t)15e3);
const unsigned long long master_guild = 281976851142803456;
const std::string version = "V3.0.503a";


using namespace LSW::v5::Tools;

std::string transform_weirdo(const std::string);
std::string format_emoji(aegis::gateway::objects::emoji);
//std::string format_emoji(emoji_c);

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
	unsigned long long user_id;
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
	unsigned long long channel_log = 0;
	unsigned long long channel_alt_log = 0;
	bool deep_data = false;
	bool mega_deep = false;
	std::string region;
	std::string alias_cmd;

	//std::mutex general_mutex;
	std::vector<unsigned long long> adm_tags;
	std::vector<unsigned long long> ignore_channels;

	void load_config(nlohmann::json);
	nlohmann::json export_config();
};

class Guild {
	static Language langs;

	// new no cache aegis way to do
	//std::vector<member_c> my_users;
	///guild_c this_guild;
	//std::mutex this_guild_m;
	std::weak_ptr<aegis::shards::shard_mgr> shards;
	guild_control here;

	// only gets the member by id
	///member_c get_member(unsigned long long);
	// only cut member by id
	///member_c remove_member(unsigned long long);
	// get and update member
	///member_c get_member(member_c&);
	// cut member from there, if none, return itself. bool* if you want to save TRUE if got, FALSE if not
	///member_c remove_member(member_c&, bool* = nullptr);

	// only gets the role by id
	///role_c get_role(unsigned long long);
	// only cut role by id
	///role_c remove_role(unsigned long long);
	// get and update role
	///role_c get_role(role_c&);
	// cut role from there, if none, return itself. bool* if you want to save TRUE if got, FALSE if not
	///role_c remove_role(role_c&, bool* = nullptr);

	// only gets the channel by id
	///channel_c get_channel(unsigned long long);
	// only cut channel by id
	///channel_c remove_channel(unsigned long long);
	// get and update channel
	///channel_c get_channel(channel_c&);
	// cut channel from there, if none, return itself. bool* if you want to save TRUE if got, FALSE if not
	///channel_c remove_channel(channel_c&, bool* = nullptr);

	// old stuff

	nlohmann::json lng;

	//unsigned long long guild_id;
	std::shared_ptr<spdlog::logger> logg;
	std::shared_ptr<aegis::core> core;

	guild_data data;
	unsigned long long last_user = 0;

	//size_t last_thus_update = 0;
	//aegis::guild* thus = nullptr;
	//aegis::channel* flush_channel = nullptr;
	bool has_welcomed = false;

	//weirdMutex blocks_m;
	//std::vector<each_block> blocks;// , emergency;
	//std::mutex emergency_m;
	std::string buf, altbuf;
	std::recursive_mutex buf_control;
	std::chrono::milliseconds last;

	SuperMutex working_on;
	SuperMutex vectors_on;
	std::recursive_mutex welcome_goodbye_refresh;

	//std::function<void(void)> restart_please;
	//bool ON_RESTART = false;


	bool trycatch_auto(std::function<void(void)>);


	void load_config();
	void save_config();

	//void refresh_flush_channel();
	void refresh_language(const std::string = "default");

	// gets text in local idiom (safe), bool = first char UPPER or not
	std::string local(const std::string, const bool = false);

	// do not touch bool. This slices up buffer many times if fail (recursively).
	//bool _flush_custom(const std::string, const bool = false); 
	//void flush();

	// if needed, flush string& buffer to ULL channel
	bool _force_flush_buffer_custom(std::string&, const unsigned long long);
	// work on a each_block& in a string& buffer to ULL channel
	void _flush_block(each_block&, std::string&, const unsigned long long);

	void flush_one_block(each_block&);
	void flush_one_alt_block(each_block&);

	// ` becomes \`, @ becomes \@, links become <links>
	std::string _fix_content(const std::string&);

	bool is_chat_valid(const unsigned long long);
	bool is_user_admin(const unsigned long long);

	void send_message_default(const unsigned long long, std::string, bool, std::string = "", int = color_embed_default);

	// won't verify channel or user admin rights.
	void command(std::vector<std::string>, const unsigned long long);

	// content, chatid, userid
	bool check_command(std::string, const unsigned long long, const unsigned long long);

	void time_flush();

	//void giveup_everything_restart();

	void task_welcome_message();
	void task_reset_message();
	void task_end_message();

	void handle(the_event&);
public:
	// guild id, logger
	Guild(const unsigned long long, std::shared_ptr<aegis::core>, std::weak_ptr<aegis::shards::shard_mgr>);
	~Guild();

	// on a core restart, pause everything. Will continue on a reassign()
	//void force_pause();
	// set all emergency to blocks
	//void fix_emergency();

	void reassign(std::shared_ptr<aegis::core>);

	void force_save();

	void welcome_back();

	bool broadcast(std::string);
	bool force_flush_buffer();
	unsigned long long get_guild_id();

	bool is_guild(const unsigned long long);

	guild_control& guild_raw();

	template<typename T>
	void handle_filter(T& t) {
		here.manage(t);
	}

	//void handle(aegis::gateway::events::message_create&);
	//void handle(aegis::gateway::events::message_update&);
	//void handle(aegis::gateway::events::message_reaction_add&);
	//void handle(aegis::gateway::events::message_reaction_remove&);
	//void handle(aegis::gateway::events::message_delete&);
	//void handle(aegis::gateway::events::channel_create&);
	//void handle(aegis::gateway::events::channel_update&);
	//void handle(aegis::gateway::events::channel_delete&);
	//void handle(aegis::gateway::events::guild_ban_add&);
	//void handle(aegis::gateway::events::guild_ban_remove&);
	//void handle(aegis::gateway::events::guild_role_create&);
	//void handle(aegis::gateway::events::guild_role_update&);
	//void handle(aegis::gateway::events::guild_role_delete&);
	//void handle(aegis::gateway::events::guild_member_add&);
	//void handle(aegis::gateway::events::guild_member_update&);
	//void handle(aegis::gateway::events::guild_member_remove&);
};