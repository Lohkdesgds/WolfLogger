#pragma once

#include <aegis.hpp>
#include "guild_control.h"

const std::chrono::milliseconds between_flushes = std::chrono::milliseconds(2000);
const size_t amount_of_wait_between_flushes = 90; // 2 sec * 90 = 3 min

class GuildGlobal {
	std::shared_ptr<aegis::core> core;
	std::shared_ptr<spdlog::logger> logg;
	std::weak_ptr<aegis::shards::shard_mgr> shards;

	std::vector<std::shared_ptr<Guild>> guilds;
	std::mutex guilds_m;
	bool on_shutdown = false;

#ifdef _DEBUG
	bool showall_console = true;
#else 
	bool showall_console = false;
#endif

	void setup();

	std::shared_ptr<Guild> get_guild(const aegis::snowflake);
	std::shared_ptr<Guild> get_guild(const aegis::snowflake, bool&);
	void erase_guild(const aegis::snowflake);

	void wakeup(std::shared_ptr<spdlog::logger> = nullptr);
public:
	GuildGlobal();
	~GuildGlobal();

	void shutdown();
	void show_all_activity(const bool);

	void force_save_all();

	size_t broadcast(const std::string);
	size_t guild_count();

	std::string generate_guild_list();

	std::shared_ptr<spdlog::logger> get_logger();
	std::shared_ptr<aegis::core> get_core();
};