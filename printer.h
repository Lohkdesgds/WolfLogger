#pragma once

#include <string>
#include <mutex>
#include <aegis.hpp>

class easy_log {
	static std::mutex m;

	template<typename T, typename... Args>
	void printl(T arg, Args... args) {
		printl(arg);
		printl(args...);
	}
	template<typename T>
	void printl(T arg) {
		std::cout << arg;
	}
    void printl(aegis::error& e) {
        switch (e)
        {
        case aegis::error::general:
            std::cout << "Generic error";
            break;
        case aegis::error::invalid_token:
            std::cout << "Token invalid";
            break;
        case aegis::error::invalid_state:
            std::cout << "Invalid state";
            break;
        case aegis::error::get_gateway:
            std::cout << "Unable to retrieve gateway data";
            break;
        case aegis::error::no_gateway:
            std::cout << "No gateway url set";
            break;
        case aegis::error::no_permission:
            std::cout << "No permission for this action";
            break;
        case aegis::error::not_implemented:
            std::cout << "Feature not yet implemented";
            break;
        case aegis::error::member_not_found:
            std::cout << "Member not found";
            break;
        case aegis::error::channel_not_found:
            std::cout << "Channel not found";
            break;
        case aegis::error::guild_not_found:
            std::cout << "Guild not found";
            break;
        case aegis::error::rate_limited:
            std::cout << "Rate limited";
            break;
        case aegis::error::global_rate_limited:
            std::cout << "Globally rate limited";
            break;
        case aegis::error::member_error:
            std::cout << "Member related error";
            break;
        case aegis::error::channel_error:
            std::cout << "Channel related error";
            break;
        case aegis::error::guild_error:
            std::cout << "Guild related error";
            break;
        case aegis::error::shard_error:
            std::cout << "Shard related error";
            break;
        case aegis::error::bad_request:
            std::cout << "Bad request";
            break;
        case aegis::error::bad_redis_request:
            std::cout << "Bad Redis request";
            break;
        case aegis::error::bulk_delete_out_of_range:
            std::cout << "Bulk delete invalid message amount";
            break;
        case aegis::error::invalid_intents:
            std::cout << "Invalid intents";
            break;
        case aegis::error::disallowed_intents:
            std::cout << "Disallowed intents";
            break;
        default:
            std::cout << "Unknown";
            break;
        }
    }
    void printl(std::exception& e) {
        std::cout << e.what();
    }
public:
	template<typename... Args>
	void print(Args... args) {
		m.lock();
		printl(args...);
		std::cout << std::endl;
		m.unlock();
	}
};

inline std::mutex easy_log::m;
inline easy_log logging;