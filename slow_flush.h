#pragma once

#include <aegis.hpp>

#define LSW_NO_WAIT

bool slow_flush(aegis::create_message_t, aegis::channel&, unsigned long long, std::shared_ptr<spdlog::logger>);
bool slow_flush(aegis::rest::aegis_file, aegis::channel&, unsigned long long, std::shared_ptr<spdlog::logger>);
bool slow_flush(std::string, aegis::channel&, unsigned long long, std::shared_ptr<spdlog::logger>);

bool slow_flush_embed(nlohmann::json, aegis::channel&, unsigned long long, std::shared_ptr<spdlog::logger>);
bool slow_flush_embed(aegis::gateway::objects::embed, aegis::channel&, unsigned long long, std::shared_ptr<spdlog::logger>);