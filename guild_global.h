#pragma once

#include <aegis.hpp>
#include "guild_control.h"

const std::chrono::milliseconds between_flushes = std::chrono::milliseconds(2000);
const size_t amount_of_wait_between_flushes = 90; // 2 sec * 90 = 3 min

class GuildGlobal {
	std::shared_ptr<aegis::core> core;
	std::shared_ptr<spdlog::logger> logg;

	std::vector<std::shared_ptr<Guild>> guilds;
	std::mutex guilds_m;
	bool on_shutdown = false;

	//bool nodel = false;

	/*std::thread* restartu = nullptr;
	std::thread* assist_restartu = nullptr;
	bool assist_end = false;
	std::mutex restartu_m;*/

	///std::thread auto_flush; // for now

	// automatic flush
	///void auto_flush_guilds();

	void setup();

	std::shared_ptr<Guild> get_guild(const aegis::snowflake);
	void erase_guild(const aegis::snowflake);

	void wakeup(std::shared_ptr<spdlog::logger> = nullptr);

	//void __del_core();
	//void _restart_thread();
public:
	GuildGlobal();
	~GuildGlobal();

	//void full_restart();

	void shutdown();

	void force_save_all();

	size_t broadcast(const std::string);
	size_t guild_count();

	std::shared_ptr<spdlog::logger> get_logger();
	std::shared_ptr<aegis::core> get_core();
};