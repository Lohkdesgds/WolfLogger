#include "slow_flush.h"


bool slow_flush(aegis::create_message_t m, aegis::channel& ch, unsigned long long this_guild_orig, std::shared_ptr<spdlog::logger> logg) {
	std::this_thread::yield();
	if (m._content.empty()) return false;
	for (size_t tries = 0; tries < 7; tries++) {
		try {
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
#ifdef LSW_NO_WAIT
			auto mmm = ch.create_message(m);
			while (!mmm.available()) std::this_thread::sleep_for(std::chrono::milliseconds(100));
#else
			ch.create_message(m).get();
#endif
			return true;
		}
		catch (aegis::error e) {
			logg->error("[Local][{}/7] Guild #{} SlowFlush couldn't send message. Got error: {}", tries + 1, this_guild_orig, e);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (std::exception e) {
			logg->error("[Local][{}/7] Guild #{} SlowFlush couldn't send message. Got error: {}", tries + 1, this_guild_orig, e.what());
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (...) {
			logg->error("[Local][{}/7] Guild #{} SlowFlush couldn't send message. Unknown error.", tries + 1, this_guild_orig);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
	}
	return false;
}
bool slow_flush(aegis::rest::aegis_file f, aegis::channel& ch, unsigned long long this_guild_orig, std::shared_ptr<spdlog::logger> logg) {
	std::this_thread::yield();
	if (f.data.empty()) return false;

	aegis::create_message_t m;
	m.file(f);

	for (size_t tries = 0; tries < 7; tries++) {
		try {
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
#ifdef LSW_NO_WAIT
			auto mmm = ch.create_message(m);
			while (!mmm.available()) std::this_thread::sleep_for(std::chrono::milliseconds(100));
#else
			ch.create_message(m).get();
#endif
			return true;
		}
		catch (aegis::error e) {
			logg->error("[Local][{}/7] Guild #{} SlowFlush couldn't send message. Got error: {}", tries + 1, this_guild_orig, e);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (std::exception e) {
			logg->error("[Local][{}/7] Guild #{} SlowFlush couldn't send message. Got error: {}", tries + 1, this_guild_orig, e.what());
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (...) {
			logg->error("[Local][{}/7] Guild #{} SlowFlush couldn't send message. Unknown error.", tries + 1, this_guild_orig);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
	}
	return false;
}

bool slow_flush(std::string str, aegis::channel& ch, unsigned long long this_guild_orig, std::shared_ptr<spdlog::logger> logg) {
	return slow_flush(aegis::create_message_t().content(str), ch, this_guild_orig, logg);
}

bool slow_flush_embed(nlohmann::json emb, aegis::channel& ch, unsigned long long this_guild_orig, std::shared_ptr<spdlog::logger> logg) {
	if (emb.empty()) return false;
	std::this_thread::yield();
	for (size_t tries = 0; tries < 7; tries++) {
		try {
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
#ifdef LSW_NO_WAIT
			auto mmm = ch.create_message_embed({}, emb);
			while (!mmm.available()) std::this_thread::sleep_for(std::chrono::milliseconds(100));
#else
			ch.create_message_embed({}, emb).get();
#endif
			return true;
		}
		catch (aegis::error e) {
			logg->error("[Local][{}/7] Guild #{} SlowFlushEmbed couldn't send message. Got error: {}", tries + 1, this_guild_orig, e);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (std::exception e) {
			logg->error("[Local][{}/7] Guild #{} SlowFlushEmbed couldn't send message. Got error: {}", tries + 1, this_guild_orig, e.what());
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (...) {
			logg->error("[Local][{}/7] Guild #{} SlowFlushEmbed couldn't send message. Unknown error.", tries + 1, this_guild_orig);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
	}
	return false;
}

bool slow_flush_embed(aegis::gateway::objects::embed emb, aegis::channel& ch, unsigned long long this_guild_orig, std::shared_ptr<spdlog::logger> logg) {
	std::this_thread::yield();
	for (size_t tries = 0; tries < 7; tries++) {
		try {
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
#ifdef LSW_NO_WAIT
			auto mmm = ch.create_message_embed({}, emb);
			while (!mmm.available()) std::this_thread::sleep_for(std::chrono::milliseconds(100));
#else
			ch.create_message_embed({}, emb).get();
#endif
			return true;
		}
		catch (aegis::error e) {
			logg->error("[Local][{}/7] Guild #{} SlowFlushEmbed couldn't send message. Got error: {}", tries + 1, this_guild_orig, e);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (std::exception e) {
			logg->error("[Local][{}/7] Guild #{} SlowFlushEmbed couldn't send message. Got error: {}", tries + 1, this_guild_orig, e.what());
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (...) {
			logg->error("[Local][{}/7] Guild #{} SlowFlushEmbed couldn't send message. Unknown error.", tries + 1, this_guild_orig);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
	}
	return false;
}