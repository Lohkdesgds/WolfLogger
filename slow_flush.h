#pragma once

#include <aegis.hpp>

#define LSW_NO_WAIT

class slowflush_end : public aegis::gateway::objects::message {
	bool has_failed = false;
public:
	slowflush_end() = default;
	template<typename... Args>
	slowflush_end(Args... args) : aegis::gateway::objects::message(args...) {}

	slowflush_end& failed() {
		has_failed = true;
		return *this;
	}
	bool good() {
		return !has_failed;
	}
	operator bool() const{
		return !has_failed;
	}
};

slowflush_end slow_flush(aegis::create_message_t, aegis::channel&, unsigned long long, std::shared_ptr<spdlog::logger>);
slowflush_end slow_flush(aegis::rest::aegis_file, aegis::channel&, unsigned long long, std::shared_ptr<spdlog::logger>);
slowflush_end slow_flush(std::string, aegis::channel&, unsigned long long, std::shared_ptr<spdlog::logger>);

slowflush_end slow_flush_embed(nlohmann::json, aegis::channel&, unsigned long long, std::shared_ptr<spdlog::logger>);
slowflush_end slow_flush_embed(aegis::gateway::objects::embed, aegis::channel&, unsigned long long, std::shared_ptr<spdlog::logger>);