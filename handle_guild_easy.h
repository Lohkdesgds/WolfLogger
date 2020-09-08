#pragma once

#include <aegis.hpp>
#include "printer.h"
#include "slow_flush.h"

const unsigned long long mee_dev = 280450898885607425; // myself, for debugging and help
const std::chrono::milliseconds each_server_delay = std::chrono::milliseconds(750);
const int color_embed_default = 0xd8954d;
const std::string main_cmd = "lsw/wl";
const std::string version = "V1.7.171";
	
class Languages {
	struct _lang {
		std::vector<std::pair<std::string, nlohmann::json>> dict;
		std::mutex mut;
	};
	static _lang langs;
public:
	nlohmann::json* getLang(const std::string);
};

inline Languages::_lang Languages::langs;



const size_t max_len_str = 2000; // discord limit

struct data_log {
	unsigned long long last_user = 0;
	unsigned long long channel_log = 0;
	bool deep_data = false;
};

class GuildChat {
	data_log mylog;
	//TaskControl tasking;
	Languages source_lang;

	nlohmann::json* idiom = nullptr;

	std::vector<unsigned long long> nolook,
		adm_tags;
	//std::mutex besur, command_guard;
	std::mutex only_one_tho;
	std::string alias_cmd = "^";

	std::string buffer_string;


	std::shared_ptr<aegis::core> ref;
	unsigned long long guild_id = 0;
	std::string itsregion;

	void save_settings();
	bool load_settings();

	// updates locale
	bool flushLanguage();

	// handles buffer_string
	void buffer_handle(std::string);
	void buffer_flush();

	// get string in language (no worry last arg)
	std::string getStrL(const std::string, const size_t = 5);

	// only arguments, no command start
	void command(aegis::channel&, std::vector<std::string>);

	// true = found one, removed, false = not found
	bool remove_chat_nolook(const unsigned long long);
	// true = found one, removed, false = not found
	bool remove_role_admin(const unsigned long long);
	// true = wasn't there, false = already there
	bool add_chat_nolook(const unsigned long long);
	// true = wasn't there, false = already there
	bool add_role_admin(const unsigned long long);

	bool has_admin_rights(aegis::guild&, aegis::user&);
	bool chat_canlook(const unsigned long long);
	bool user_not_bot_not_null(const unsigned long long);
public:
	GuildChat(std::shared_ptr<aegis::core>, aegis::guild&);
	GuildChat(std::shared_ptr<aegis::core>, aegis::gateway::objects::guild&);
	~GuildChat();

	void reset(); // erase file and data.

	bool operator==(const unsigned long long);

	template<typename T>
	void handle(T& doit) {
		if (only_one_tho.try_lock()) {
			logging.print("in");
			handle_specific(doit);
			logging.print("out");
			only_one_tho.unlock();
		}
		else logging.print("no good");
	}

	void handle_specific(aegis::gateway::events::message_create&);
	void handle_specific(aegis::gateway::events::message_update&);
	void handle_specific(aegis::gateway::events::message_delete&);
	void handle_specific(aegis::gateway::events::message_reaction_add&);
	void handle_specific(aegis::gateway::events::message_reaction_remove&);
	void handle_specific(aegis::gateway::events::channel_create&);
	void handle_specific(aegis::gateway::events::channel_update&);
	void handle_specific(aegis::gateway::events::channel_delete&);
	void handle_specific(aegis::gateway::events::guild_ban_add&);
	void handle_specific(aegis::gateway::events::guild_ban_remove&);
	void handle_specific(aegis::gateway::events::guild_role_create&);
	void handle_specific(aegis::gateway::events::guild_role_update&);
	void handle_specific(aegis::gateway::events::guild_role_delete&);

	void end_message();
	void welcome_message();
	void rejoin_message();
};

	