#include "guild_global.h"


void GuildGlobal::setup()
{
	// any event
	core->set_manage_myself_any_event([&](nlohmann::json j, aegis::shards::shard* sh) {
		if (on_shutdown) return;
		the_event ev;
		ev.load_raw(j, sh, logg);
		if (ev.guild_id.is_set()) {
			bool nov = true;
			auto cpy = get_guild(ev.guild_id.get(), nov);

			switch (ev.type) {
			case event_type::GUILD_CREATE:
				if (!nov && cpy) cpy->welcome_back();
				break;
			case event_type::GUILD_DELETE:
				erase_guild(ev.guild_id.get()); // nodel inside
				return; // down
			}
			if (cpy) cpy->handle_filter(ev);
		}
	});


	/*core->set_on_message_create([&](aegis::gateway::events::message_create obj) {
		if (on_shutdown) return;
		if (obj.msg.author.is_bot()) return;
		auto this_guild = get_guild(obj.msg.get_guild_id());
		if (this_guild) this_guild->handle_filter(obj);
	});
	core->set_on_message_update([&](aegis::gateway::events::message_update obj) {
		if (on_shutdown) return;
		if (obj.msg.author.is_bot() || obj.msg.get_content().empty()) return;
		auto this_guild = get_guild(obj.msg.get_guild_id());
		if (this_guild) this_guild->handle_filter(obj);
	});
	core->set_on_message_delete([&](aegis::gateway::events::message_delete obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.channel.get_guild_id());
		if (this_guild) this_guild->handle_filter(obj);
	});
	core->set_on_message_reaction_add([&](aegis::gateway::events::message_reaction_add obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle_filter(obj);
	});
	core->set_on_message_reaction_remove([&](aegis::gateway::events::message_reaction_remove obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle_filter(obj);
	});
	core->set_on_channel_create([&](aegis::gateway::events::channel_create obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.channel.guild_id);
		if (this_guild) this_guild->handle_filter(obj);
	});
	core->set_on_channel_update([&](aegis::gateway::events::channel_update obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.channel.guild_id);
		if (this_guild) this_guild->handle_filter(obj);
	});
	core->set_on_channel_delete([&](aegis::gateway::events::channel_delete obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.channel.guild_id);
		if (this_guild) this_guild->handle_filter(obj);
	});
	core->set_on_guild_ban_add([&](aegis::gateway::events::guild_ban_add obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle_filter(obj);
	});
	core->set_on_guild_ban_remove([&](aegis::gateway::events::guild_ban_remove obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle_filter(obj);
	});
	core->set_on_guild_role_create([&](aegis::gateway::events::guild_role_create obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle_filter(obj);
	});
	core->set_on_guild_role_update([&](aegis::gateway::events::guild_role_update obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle_filter(obj);
	});
	core->set_on_guild_role_delete([&](aegis::gateway::events::guild_role_delete obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle_filter(obj);
	});
	core->set_on_guild_member_add_raw([&](nlohmann::json j, aegis::shards::shard* sh) {
		if (on_shutdown || j.empty()) return;
		the_event ev;
		ev.load_raw(j, sh, logg);
		auto this_guild = get_guild(ev.guild_id.get());
		if (this_guild) this_guild->handle_filter(ev);
	});
	core->set_on_guild_member_update_raw([&](nlohmann::json j, aegis::shards::shard* sh) {
		if (on_shutdown || j.empty()) return;
		the_event ev;
		ev.load_raw(j, sh, logg);
		auto this_guild = get_guild(ev.guild_id.get());
		if (this_guild) this_guild->handle_filter(ev);
	});
	core->set_on_guild_member_remove_raw([&](nlohmann::json j, aegis::shards::shard* sh) {
		if (on_shutdown || j.empty()) return;
		the_event ev;
		ev.load_raw(j, sh, logg);
		auto this_guild = get_guild(ev.guild_id.get());
		if (this_guild) this_guild->handle_filter(ev);
	});
	core->set_on_guild_member_add([&](aegis::gateway::events::guild_member_add obj) {
		if (on_shutdown) return;
		if (showall_console) logg->info("[MEMBER_ADD] NEW #{}", obj.member.guild_id);
	});
	core->set_on_guild_member_update([&](aegis::gateway::events::guild_member_update obj) {
		if (on_shutdown) return;
		if (showall_console) logg->info("[MEMBER_UPDATE] NEW #{}", obj.guild_id);
	});
	core->set_on_guild_member_remove([&](aegis::gateway::events::guild_member_remove obj) {
		if (on_shutdown) return;
		if (showall_console) logg->info("[MEMBER_REMOVE] NEW #{}", obj.guild_id);
	});
	core->set_on_guild_member_add([&](aegis::gateway::events::guild_member_add obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.member.guild_id);
		if (this_guild) this_guild->handle_filter(obj);
	});
	core->set_on_guild_member_update([&](aegis::gateway::events::guild_member_update obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle_filter(obj);
	});
	core->set_on_guild_member_remove([&](aegis::gateway::events::guild_member_remove obj) {
		if (on_shutdown) return;
		auto this_guild = get_guild(obj.guild_id);
		if (this_guild) this_guild->handle_filter(obj);
	});*/
}

std::shared_ptr<Guild> GuildGlobal::get_guild(const aegis::snowflake id)
{
	bool temp;
	return get_guild(id, temp);
}

std::shared_ptr<Guild> GuildGlobal::get_guild(const aegis::snowflake id, bool& nov)
{
	std::lock_guard<std::mutex> luck(guilds_m);
	for (auto& i : guilds) {
		if (i && i->is_guild(id)) {
			i->reassign(core);
			nov = false;
			return i;
		}
	}
	guilds.emplace_back(std::move(std::make_shared<Guild>(id, core, shards)));
	logg->info("Created Guild #{}", id);
	nov = true;
	return guilds.back();
}

void GuildGlobal::erase_guild(const aegis::snowflake id)
{
	std::lock_guard<std::mutex> luck(guilds_m);
	for (size_t p = 0; p < guilds.size(); p++) {
		if (guilds[p] && guilds[p]->is_guild(id)) {
			guilds.erase(guilds.begin() + p);
			logg->info("Erased Guild #{}", id);
			return;
		}
	}
}

void GuildGlobal::wakeup(std::shared_ptr<spdlog::logger> spd)
{
	core.reset();
	logg.reset();

	if (spd) {
		core = std::shared_ptr<aegis::core>(new aegis::core(spd, std::thread::hardware_concurrency() < 8 ? 8 : std::thread::hardware_concurrency()), [](aegis::core* c) {
			c->shutdown();
			delete c;
		});
	}
	else {
		core = std::shared_ptr<aegis::core>(new aegis::core(spdlog::level::debug, std::thread::hardware_concurrency() < 8 ? 8 : std::thread::hardware_concurrency()), [](aegis::core* c) {
			c->shutdown();
			delete c;
		});
	}
	logg = spd ? spd : core->log;
	logg->info("Core has awaken.");

	shards = core->get_shard_mgr();

	setup();
	core->run();

	//auto_flush = std::thread([&] {auto_flush_guilds(); });
}

GuildGlobal::GuildGlobal()
{
	wakeup();
}

GuildGlobal::~GuildGlobal()
{
	logg->info("Shutdown is being done...");
	core.reset();
}

void GuildGlobal::shutdown()
{
	on_shutdown = true;
	std::lock_guard<std::mutex> luck(guilds_m);
	for (auto& i : guilds) i->force_save();
	guilds.clear();
	if (core) core->shutdown();
	//if (auto_flush.joinable()) auto_flush.join();
}

void GuildGlobal::show_all_activity(const bool b)
{
	showall_console = b;
}

void GuildGlobal::force_save_all()
{
	logg->warn("Forced save called. Saving all current guilds...");
	std::lock_guard<std::mutex> luck(guilds_m);
	for (auto& i : guilds) i->force_save();
	logg->info("Saved all guilds configurations successfully.");
}

size_t GuildGlobal::broadcast(const std::string whut)
{
	size_t count = 0;
	std::lock_guard<std::mutex> luck(guilds_m);
	for (auto& i : guilds) {
		logg->info("Sending broadcast to #{}...", i->get_guild_id());
		count += i->broadcast(whut);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	return count;
}

size_t GuildGlobal::guild_count()
{
	size_t count = 0;
	std::lock_guard<std::mutex> luck(guilds_m);
	count = guilds.size();
	return count;
}

std::string GuildGlobal::generate_guild_list()
{
	std::string str;
	std::lock_guard<std::mutex> luck(guilds_m);
	for (auto& i : guilds) {
		str += "- Guild #" + std::to_string(i->guild_raw().get_raw_guild().id.get()) + " (" + i->guild_raw().get_raw_guild().region.get() + ")";
	}

	return str;
}

std::shared_ptr<spdlog::logger> GuildGlobal::get_logger()
{
	if (!this) return nullptr;
	return logg;
}

std::shared_ptr<aegis::core> GuildGlobal::get_core()
{
	if (!this) return nullptr;
	return core;
}
