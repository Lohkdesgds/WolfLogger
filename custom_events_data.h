#pragma once

#include <aegis.hpp>
#include "resources.h"

constexpr size_t max_message_len = 2000;

class guild_control {
	using handle_event = std::function<void(the_event&)>;

	std::shared_ptr<spdlog::logger> logg;
	std::shared_ptr<aegis::ratelimit::ratelimit_mgr> ratelimit;
	guild_c guild;
	static user_c& bot; // refs to static the_event::bot

	handle_event event_custom_handle; // call when info is up to date or richer

	member_c update_member(member_c&);
	member_c cut_member(const ULL);

	role_c update_role(role_c&);
	role_c cut_role(const ULL);

	channel_c update_channel(channel_c&);
	channel_c cut_channel(const ULL);

	presence_c update_and_shrink_presence(presence_c&);
	presence_c cut_presence(const ULL);

	voice_state_c update_voice_state(voice_state_c&);
	voice_state_c cut_voice_state(const ULL);
public:
	guild_control(std::shared_ptr<aegis::ratelimit::ratelimit_mgr>, std::shared_ptr<spdlog::logger>);

	guild_c& get_raw_guild();
	user_c get_bot();

	// set to trigger on event. internally the data will be as full/rich as possible so you can handle it 10/10
	void set_after_handle(handle_event);
	// new users, new channels, updates, etc, manage here
	void manage(the_event&);


	// channel id, what perm
	bool bot_has_perm(const ULL, const permissions_user);
	// user id
	int64_t get_global_user_permissions(const ULL);
	// channel id, user id, what perm
	int64_t get_local_user_permissions(const ULL, const ULL);
	// channel id
	bool does_channel_exist(const ULL);

	member_c get_member(const ULL);
	role_c get_role(const ULL);
	channel_c get_channel(const ULL);
	presence_c get_presence(const ULL);
	voice_state_c get_voice_state(const ULL);


	// channel ID, content, nonce, autosplit (if > 2000, split. returns last message)
	message_c create_message(const ULL, const std::string&, int64_t = 0, bool = true);
	// channel ID, JSON, content, nonce
	message_c create_message_embed(const ULL, const nlohmann::json&, const std::string& = "", int64_t = 0);

	// channel ID, message ID
	message_c get_message(const ULL, const ULL);
};

inline user_c the_event::bot;
inline user_c& guild_control::bot = the_event::bot;