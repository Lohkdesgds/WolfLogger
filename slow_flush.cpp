#include "slow_flush.h"


slowflush_end slow_flush(aegis::create_message_t m, aegis::channel& ch, unsigned long long this_guild_orig, std::shared_ptr<spdlog::logger> logg) {
	std::this_thread::yield();
	if (m._content.empty()) {
		logg->warn("Guild #{} SlowFlush: content empty.", this_guild_orig);
		return slowflush_end().failed();
	}
	if (m._content.size() > safe_msg_limit) {
		logg->warn("Guild #{} SlowFlush: content too big ({} > {}).", this_guild_orig, m._content.size(), safe_msg_limit);
		return slowflush_end().failed();
	}	

	for (size_t tries = 0; tries < max_tries; tries++) {
		try {
			//std::lock_guard<std::mutex> luckk(slow_flush_control);
			if (min_wait.count()) std::this_thread::sleep_for(min_wait);
			std::this_thread::yield();
#ifdef LSW_NO_GET
#ifdef LSW_DONTCAREMODE
			ch.create_message(m).then([logg, this_guild_orig](aegis::gateway::objects::message u) {logg->info("Guild #{} (later) flushed {} byte(s)", this_guild_orig, u.get_content().length()); });
			return slowflush_end();
#else
			auto mmm = ch.create_message(m);
			while (!mmm.available()) { std::this_thread::sleep_for(std::chrono::milliseconds(100)); std::this_thread::yield(); }
			return mmm.get();
#endif
#else
#ifdef LSW_ALT_NO_GET_USE_THEN
			slowflush_end uu;
			bool gottem = false;
			ch.create_message(m).then([&](aegis::gateway::objects::message k) {
				uu = k;
				gottem = true;
				});
			while (!gottem) { std::this_thread::sleep_for(std::chrono::milliseconds(100)); std::this_thread::yield(); }
			return uu;
#else
			return ch.create_message(m).get();
#endif
#endif
		}
		catch (aegis::error e) {
			logg->critical("[{}/{}] Guild #{} SlowFlush couldn't send message. Got error: {}", tries + 1, max_tries, this_guild_orig, e);
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (nlohmann::detail::type_error e) {
			logg->error("Guild #{} SlowFlush: JSON failed: TYPE ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::invalid_iterator e) {
			logg->error("Guild #{} SlowFlush: JSON failed: INVALID ITERATOR ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::parse_error e) {
			logg->error("Guild #{} SlowFlush: JSON failed: PARSE ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::out_of_range e) {
			logg->error("Guild #{} SlowFlush: JSON failed: OUT OF RANGE ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::other_error e) {
			logg->error("Guild #{} SlowFlush: JSON failed: OTHER ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::exception e) {
			logg->error("Guild #{} SlowFlush: JSON failed: GENERIC EXCEPTION ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (std::exception e) {
			logg->critical("[{}/{}] Guild #{} SlowFlush couldn't send message. Got error: {}", tries + 1, max_tries, this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (...) {
			logg->critical("[{}/{}] Guild #{} SlowFlush couldn't send message. Unknown error.", tries + 1, max_tries, this_guild_orig);
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
	}
	return slowflush_end().failed();
}
slowflush_end slow_flush(aegis::rest::aegis_file f, aegis::channel& ch, unsigned long long this_guild_orig, std::shared_ptr<spdlog::logger> logg) {
	std::this_thread::yield();
	if (f.data.empty()) {
		logg->warn("Guild #{} SlowFlush: content empty.", this_guild_orig);
		return slowflush_end().failed();
	}
	if (f.data.size() > safe_file_size_limit) {
		logg->warn("Guild #{} SlowFlush: content too big ({} > {} (bytes)).", this_guild_orig, f.data.size(), safe_file_size_limit);
		return slowflush_end().failed();
	}

	aegis::create_message_t m;
	m.file(f);

	for (size_t tries = 0; tries < max_tries; tries++) {
		try {
			//std::lock_guard<std::mutex> luckk(slow_flush_control);
			if (min_wait.count()) std::this_thread::sleep_for(min_wait);
			std::this_thread::yield();
#ifdef LSW_NO_GET
#ifdef LSW_DONTCAREMODE
			ch.create_message(m).then([logg, this_guild_orig](aegis::gateway::objects::message u) {logg->info("Guild #{} (later) flushed {} byte(s)", this_guild_orig, u.get_content().length()); });
			return slowflush_end();
#else
			auto mmm = ch.create_message(m);
			while (!mmm.available()) { std::this_thread::sleep_for(std::chrono::milliseconds(100)); std::this_thread::yield(); }
			return mmm.get();
#endif
#else
#ifdef LSW_ALT_NO_GET_USE_THEN
			slowflush_end uu;
			bool gottem = false;
			ch.create_message(m).then([&](aegis::gateway::objects::message k) {
				uu = k;
				gottem = true;
				});
			while (!gottem) { std::this_thread::sleep_for(std::chrono::milliseconds(100)); std::this_thread::yield(); }
			return uu;
#else
			return ch.create_message(m).get();
#endif
#endif
		}
		catch (aegis::error e) {
			logg->critical("[{}/{}] Guild #{} SlowFlush couldn't send message. Got error: {}", tries + 1, max_tries, this_guild_orig, e);
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (nlohmann::detail::type_error e) {
			logg->error("Guild #{} SlowFlush: JSON failed: TYPE ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::invalid_iterator e) {
			logg->error("Guild #{} SlowFlush: JSON failed: INVALID ITERATOR ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::parse_error e) {
			logg->error("Guild #{} SlowFlush: JSON failed: PARSE ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::out_of_range e) {
			logg->error("Guild #{} SlowFlush: JSON failed: OUT OF RANGE ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::other_error e) {
			logg->error("Guild #{} SlowFlush: JSON failed: OTHER ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::exception e) {
			logg->error("Guild #{} SlowFlush: JSON failed: GENERIC EXCEPTION ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (std::exception e) {
			logg->critical("[{}/{}] Guild #{} SlowFlush couldn't send message. Got error: {}", tries + 1, max_tries, this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (...) {
			logg->critical("[{}/{}] Guild #{} SlowFlush couldn't send message. Unknown error.", tries + 1, max_tries, this_guild_orig);
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
	}
	return slowflush_end();
}

slowflush_end slow_flush(std::string str, aegis::channel& ch, unsigned long long this_guild_orig, std::shared_ptr<spdlog::logger> logg) {
	return slow_flush(aegis::create_message_t().content(str), ch, this_guild_orig, logg);
}

slowflush_end slow_flush_embed(nlohmann::json emb, aegis::channel& ch, unsigned long long this_guild_orig, std::shared_ptr<spdlog::logger> logg) {
	if (emb.empty()) {
		logg->warn("Guild #{} SlowFlushEmbed: content empty.", this_guild_orig);
		return slowflush_end().failed();
	}
	std::this_thread::yield();
	for (size_t tries = 0; tries < max_tries; tries++) {
		try {
			//std::lock_guard<std::mutex> luckk(slow_flush_control);
			if (min_wait.count()) std::this_thread::sleep_for(min_wait);
			std::this_thread::yield();
#ifdef LSW_NO_GET
#ifdef LSW_DONTCAREMODE
			ch.create_message_embed({}, emb).then([logg, this_guild_orig](aegis::gateway::objects::message u) {logg->info("Guild #{} (later) flushed {} byte(s)", this_guild_orig, u.get_content().length()); });
			return slowflush_end();
#else
			auto mmm = ch.create_message_embed({}, emb);
			while (!mmm.available()) { std::this_thread::sleep_for(std::chrono::milliseconds(100)); std::this_thread::yield(); }
			return mmm.get();
#endif
#else
#ifdef LSW_ALT_NO_GET_USE_THEN
			slowflush_end uu;
			bool gottem = false;
			ch.create_message_embed({}, emb).then([&](aegis::gateway::objects::message k) {
				uu = k;
				gottem = true;
			});
			while (!gottem) { std::this_thread::sleep_for(std::chrono::milliseconds(100)); std::this_thread::yield(); }
			return uu;
#else
			return ch.create_message_embed({}, emb).get();
#endif
#endif
		}
		catch (aegis::error e) {
			logg->critical("[{}/{}] Guild #{} SlowFlushEmbed couldn't send message. Got error: {}", tries + 1, max_tries, this_guild_orig, e);
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (nlohmann::detail::type_error e) {
			logg->error("Guild #{} SlowFlush: JSON failed: TYPE ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::invalid_iterator e) {
			logg->error("Guild #{} SlowFlush: JSON failed: INVALID ITERATOR ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::parse_error e) {
			logg->error("Guild #{} SlowFlush: JSON failed: PARSE ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::out_of_range e) {
			logg->error("Guild #{} SlowFlush: JSON failed: OUT OF RANGE ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::other_error e) {
			logg->error("Guild #{} SlowFlush: JSON failed: OTHER ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::exception e) {
			logg->error("Guild #{} SlowFlush: JSON failed: GENERIC EXCEPTION ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (std::exception e) {
			logg->critical("[{}/{}] Guild #{} SlowFlushEmbed couldn't send message. Got error: {}", tries + 1, max_tries, this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (...) {
			logg->critical("[{}/{}] Guild #{} SlowFlushEmbed couldn't send message. Unknown error.", tries + 1, max_tries, this_guild_orig);
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
	}
	return slowflush_end().failed();
}

slowflush_end slow_flush_embed(aegis::gateway::objects::embed emb, aegis::channel& ch, unsigned long long this_guild_orig, std::shared_ptr<spdlog::logger> logg) {
	if (nlohmann::json(emb).empty()) {
		logg->warn("Guild #{} SlowFlushEmbed: content empty.", this_guild_orig);
		return slowflush_end().failed();
	}
	std::this_thread::yield();
	for (size_t tries = 0; tries < max_tries; tries++) {
		try {
			//std::lock_guard<std::mutex> luckk(slow_flush_control);
			if (min_wait.count()) std::this_thread::sleep_for(min_wait);
			std::this_thread::yield();
#ifdef LSW_NO_GET
#ifdef LSW_DONTCAREMODE
			ch.create_message_embed({}, emb).then([logg, this_guild_orig](aegis::gateway::objects::message u) {logg->info("Guild #{} (later) flushed {} byte(s)", this_guild_orig, u.get_content().length()); });
			return slowflush_end();
#else
			auto mmm = ch.create_message_embed({}, emb);
			while (!mmm.available()) { std::this_thread::sleep_for(std::chrono::milliseconds(100)); std::this_thread::yield(); }
			return mmm.get();
#endif
#else
#ifdef LSW_ALT_NO_GET_USE_THEN
			slowflush_end uu;
			bool gottem = false;
			ch.create_message_embed({}, emb).then([&](aegis::gateway::objects::message k) {
				uu = k;
				gottem = true;
				});
			while (!gottem) { std::this_thread::sleep_for(std::chrono::milliseconds(100)); std::this_thread::yield(); }
			return uu;
#else
			return ch.create_message_embed({}, emb).get();
#endif
#endif
		}
		catch (aegis::error e) {
			logg->critical("[{}/{}] Guild #{} SlowFlushEmbed couldn't send message. Got error: {}", tries + 1, max_tries, this_guild_orig, e);
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (nlohmann::detail::type_error e) {
			logg->error("Guild #{} SlowFlush: JSON failed: TYPE ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::invalid_iterator e) {
			logg->error("Guild #{} SlowFlush: JSON failed: INVALID ITERATOR ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::parse_error e) {
			logg->error("Guild #{} SlowFlush: JSON failed: PARSE ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::out_of_range e) {
			logg->error("Guild #{} SlowFlush: JSON failed: OUT OF RANGE ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::other_error e) {
			logg->error("Guild #{} SlowFlush: JSON failed: OTHER ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (nlohmann::detail::exception e) {
			logg->error("Guild #{} SlowFlush: JSON failed: GENERIC EXCEPTION ERROR: {}", this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
		catch (std::exception e) {
			logg->critical("[{}/{}] Guild #{} SlowFlushEmbed couldn't send message. Got error: {}", tries + 1, max_tries, this_guild_orig, e.what());
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (...) {
			logg->critical("[{}/{}] Guild #{} SlowFlushEmbed couldn't send message. Unknown error.", tries + 1, max_tries, this_guild_orig);
			std::this_thread::sleep_for(error_wait);
			//for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			return slowflush_end().failed();
		}
	}
	return slowflush_end().failed();
}