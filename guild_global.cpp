#include "guild_global.h"

void GuildGlobal::auto_flush_guilds()
{
	logg->info("AutoFlush started.");
	while (!on_shutdown) {
		for(size_t p = 0; p < amount_of_wait_between_flushes && !on_shutdown; p++) std::this_thread::sleep_for(between_flushes); // approx 1 sec
		if (on_shutdown) {
			logg->warn("AutoFlush got shutdown. Leaving.");
			return;
		}
		logg->info("AutoFlush flushing guilds...");
		guilds_m.lock();
		for (auto& i : guilds) {
			i->force_flush_buffer();
			if (on_shutdown) {
				logg->warn("AutoFlush got shutdown. Leaving.");
				guilds_m.unlock();
				return;
			}
		}
		guilds_m.unlock();
		logg->info("AutoFlush flushed all guilds.");
	}
}

void GuildGlobal::setup()
{
	// join in guild
	core->set_on_guild_create([&](aegis::gateway::events::guild_create obj) {
		if (on_shutdown) return;
		get_guild(obj.guild.id)->reassign(core);
	});
	// leave guild
	core->set_on_guild_delete([&](aegis::gateway::events::guild_delete obj) {
		if (on_shutdown) return;
		erase_guild(obj.guild_id); // nodel inside
	});


	core->set_on_message_create([&](aegis::gateway::events::message_create obj) {
		if (on_shutdown) return;
		if (obj.msg.author.is_bot()) return;
		auto this_guild = get_guild(obj.msg.get_guild_id());
		if (this_guild) this_guild->handle(obj);
	});
	core->set_on_message_update([&](aegis::gateway::events::message_update obj) {
		if (on_shutdown) return;
		if (obj.msg.author.is_bot() || obj.msg.get_content().empty()) return;
		auto this_guild = get_guild(obj.msg.get_guild_id());
		if (this_guild) this_guild->handle(obj);
	});
	core->set_on_message_delete([&](aegis::gateway::events::message_delete obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.channel.get_guild_id());
		if (this_guild) this_guild->handle(obj);
	});
	core->set_on_message_reaction_add([&](aegis::gateway::events::message_reaction_add obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle(obj);
	});
	core->set_on_message_reaction_remove([&](aegis::gateway::events::message_reaction_remove obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle(obj);
	});
	core->set_on_channel_create([&](aegis::gateway::events::channel_create obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.channel.guild_id);
		if (this_guild) this_guild->handle(obj);
	});
	core->set_on_channel_update([&](aegis::gateway::events::channel_update obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.channel.guild_id);
		if (this_guild) this_guild->handle(obj);
	});
	core->set_on_channel_delete([&](aegis::gateway::events::channel_delete obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.channel.guild_id);
		if (this_guild) this_guild->handle(obj);
	});
	core->set_on_guild_ban_add([&](aegis::gateway::events::guild_ban_add obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle(obj);
	});
	core->set_on_guild_ban_remove([&](aegis::gateway::events::guild_ban_remove obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle(obj);
	});
	core->set_on_guild_role_create([&](aegis::gateway::events::guild_role_create obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle(obj);
	});
	core->set_on_guild_role_update([&](aegis::gateway::events::guild_role_update obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle(obj);
	});
	core->set_on_guild_role_delete([&](aegis::gateway::events::guild_role_delete obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle(obj);
	});
}

std::shared_ptr<Guild> GuildGlobal::get_guild(const aegis::snowflake id)
{
	guilds_m.lock();
	for (auto& i : guilds) {
		if (i && i->is_guild(id)) {
			auto cpy = i;
			guilds_m.unlock();
			return cpy;
		}
	}
	guilds.push_back(std::make_shared<Guild>(id, core));
	logg->info("Created Guild #{}", id);
	auto cpy = guilds.back();
	guilds_m.unlock();
	return cpy;
}

void GuildGlobal::erase_guild(const aegis::snowflake id)
{
	//if (nodel) return;
	guilds_m.lock();
	for (size_t p = 0; p < guilds.size(); p++) {
		if (guilds[p] && guilds[p]->is_guild(id)) {
			guilds.erase(guilds.begin() + p);
			logg->info("Erased Guild #{}", id);
			guilds_m.unlock();
			return;
		}
	}
	guilds_m.unlock();
}

void GuildGlobal::wakeup(std::shared_ptr<spdlog::logger> spd)
{
	core.reset();
	logg.reset();

	if (spd) {
		core = std::shared_ptr<aegis::core>(new aegis::core(spd, std::thread::hardware_concurrency() < 4 ? 4 : std::thread::hardware_concurrency()), [](aegis::core* c) {
			c->shutdown();
			delete c;
		});
	}
	else {
		core = std::shared_ptr<aegis::core>(new aegis::core(spdlog::level::trace, std::thread::hardware_concurrency() < 4 ? 4 : std::thread::hardware_concurrency()), [](aegis::core* c) {
			c->shutdown();
			delete c;
		});
	}
	logg = spd ? spd : core->log;
	logg->info("Core has awaken.");

	setup();
	core->run();

	auto_flush = std::thread([&] {auto_flush_guilds(); });
}

/*void GuildGlobal::__del_core()
{
	assist_end = false;
	auto cpy = core;
	core->shutdown();
	core.reset(); // only unref itself
	cpy.reset(); // cleanup
	assist_end = true;
}

void GuildGlobal::_restart_thread()
{
	nodel = true;

	logg->info("[RECOVERY] Restart called. Setting up restart...");

	guilds_m.lock();
	for (auto& i : guilds) i->force_pause();
	guilds_m.unlock();

	logg->info("[RECOVERY] Paused guilds. Setting up to restart core...");

	if (assist_restartu) {
		logg->warn("[RECOVERY] Found failed traces. Erasing all possible memory...");
		::TerminateThread(assist_restartu->native_handle(), 1);
		delete assist_restartu;
		assist_restartu = nullptr;
		logg->warn("[RECOVERY] Forced end of failed task. Setting up restart core now...");
	}

	const size_t core_count = core.use_count();

	assist_restartu = new std::thread([&] {
		__del_core();
	});
	assist_restartu->detach();

	if (core) {
		logg->info("[RECOVERY] Waiting core to reset... (there was {} copies)", core_count);
		while (core) std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	//if (auto co = logg.use_count(); co > 1) logg->warn("[RECOVERY] Note: There are {} loggers in existance.", co - 1);

	logg->info("[RECOVERY] Fixing some recovery stuff...");

	guilds_m.lock();
	for (auto& i : guilds) i->fix_emergency();
	guilds_m.unlock();

	logg->info("[RECOVERY] Creating core again...");

	wakeup(logg);

	logg->info("[RECOVERY] Done restarting core. Waiting core deleter to end its job...");
	
	for (size_t pps = 0; pps < 240 && !assist_end; pps++) std::this_thread::sleep_for(std::chrono::milliseconds(500)); // 2+ min
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	if (!assist_end) logg->critical("[RECOVERY] Core deleter took too much time. This can become a big issue later (potential memory leak).");

	logg->info("[RECOVERY] Done all tasks.");

	nodel = false;
}*/


GuildGlobal::GuildGlobal()
{
	wakeup();
}

GuildGlobal::~GuildGlobal()
{
	logg->info("Shutdown is being done...");
	core.reset();
	/*restartu_m.lock();
	if (restartu) {
		if (restartu->joinable()) restartu->join();
		delete restartu;
		restartu = nullptr;
	}
	restartu_m.unlock();*/
}

/*void GuildGlobal::full_restart()
{
	restartu_m.lock();
	if (!nodel && restartu) { // nodel false means end task there
		if (restartu->joinable()) restartu->join();
		delete restartu;
		restartu = nullptr;
	}
	if (!restartu) {
		restartu = new std::thread([&] {_restart_thread(); });
	}
	restartu_m.unlock();
}*/

void GuildGlobal::shutdown()
{
	on_shutdown = true;
	guilds_m.lock();
	for (auto& i : guilds) i->force_save();
	guilds.clear();
	guilds_m.unlock();
	if (core) core->shutdown();
	if (auto_flush.joinable()) auto_flush.join();
}

void GuildGlobal::force_save_all()
{
	logg->warn("Forced save called. Saving all current guilds...");
	guilds_m.lock();
	for (auto& i : guilds) i->force_save();
	guilds_m.unlock();
	logg->info("Saved all guilds configurations successfully.");
}

size_t GuildGlobal::broadcast(const std::string whut)
{
	size_t count = 0;
	guilds_m.lock();
	for (auto& i : guilds) {
		count += i->broadcast(whut);
	}
	guilds_m.unlock();
	return count;
}

size_t GuildGlobal::guild_count()
{
	size_t count = 0;
	guilds_m.lock();
	count = guilds.size();
	guilds_m.unlock();
	return count;
}

std::shared_ptr<spdlog::logger> GuildGlobal::get_logger()
{
	return logg;
}

std::shared_ptr<aegis::core> GuildGlobal::get_core()
{
	return core;
}
