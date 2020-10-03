#include "custom_events_data.h"



member_c guild_control::update_member(member_c& c)
{
	member_c result = c;
	auto& arr = guild.members;

	for (size_t p = 0; p < arr.size(); p++) {
		auto& i = arr[p];
		if (i.user.id == c.user.id) {
			i = c;
			return i;
		}
	}
	guild.members.push_back(c);

	return result;
}

member_c guild_control::cut_member(const ULL id)
{
	member_c result;
	auto& arr = guild.members;

	for (size_t p = 0; p < arr.size(); p++) {
		auto& i = arr[p];
		if (i.user.id == id) {
			result = i;
			arr.erase(p);
			return result;
		}
	}

	return result;
}

role_c guild_control::update_role(role_c& c)
{
	role_c result = c;
	auto& arr = guild.roles;

	for (size_t p = 0; p < arr.size(); p++) {
		auto& i = arr[p];
		if (i.id == c.id) {
			i = c;
			return i;
		}
	}
	guild.roles.push_back(c);

	return result;
}

role_c guild_control::cut_role(const ULL id)
{
	role_c result;
	auto& arr = guild.roles;

	for (size_t p = 0; p < arr.size(); p++) {
		auto& i = arr[p];
		if (i.id == id) {
			result = i;
			arr.erase(p);
			return result;
		}
	}

	return result;
}

channel_c guild_control::update_channel(channel_c& c)
{
	channel_c result = c;
	auto& arr = guild.channels;

	for (size_t p = 0; p < arr.size(); p++) {
		auto& i = arr[p];
		if (i.id == c.id) {
			i = c;
			return i;
		}
	}
	guild.channels.push_back(c);

	return result;
}

channel_c guild_control::cut_channel(const ULL id)
{
	channel_c result;
	auto& arr = guild.channels;

	for (size_t p = 0; p < arr.size(); p++) {
		auto& i = arr[p];
		if (i.id == id) {
			result = i;
			arr.erase(p);
			return result;
		}
	}

	return result;
}

presence_c guild_control::update_and_shrink_presence(presence_c& c)
{
	presence_c result = c;
	auto& arr = guild.presences;

	c.user = get_member(c.user.id).user;

	for (size_t p = 0; p < arr.size(); p++) {
		auto& i = arr[p];
		if (i.user.id == c.user.id) {
			// i == guild stored presences
			// c == now presence
			c.game._changed = !(c.game == i.game);

			// new data in order, just to be sure
			{
				std::lock_guard<std::recursive_mutex> sure(c.activities.get_internal_lock());
				auto& c_act = c.activities.cast_back_nolock();

				std::sort(c_act.begin(), c_act.end(), [](activity_c& a, activity_c& b)->bool {
					return a.application_id < b.application_id;
				});
			}

			if (i.activities.size() == c.activities.size()) {
				for (size_t a = 0; a < c.activities.size(); a++) {
					auto& new_p = c.activities[a];
					auto& old_p = i.activities[a];
					if (new_p.similar(old_p)) {
						new_p._changed = !(new_p == old_p);
					}
				}
			}
			// if not equal, update whole list. tsc.

			i = c;
			return i;
		}
	}
	guild.presences.push_back(c);

	return result;
}

presence_c guild_control::cut_presence(const ULL id)
{
	presence_c result;
	auto& arr = guild.presences;

	for (size_t p = 0; p < arr.size(); p++) {
		auto& i = arr[p];
		if (i.user.id == id) {
			result = i;
			arr.erase(p);
			return result;
		}
	}

	return result;
}

voice_state_c guild_control::get_voice_state(const ULL id)
{
	voice_state_c result;
	auto& arr = guild.voice_states;

	for (size_t p = 0; p < arr.size(); p++) {
		auto& i = arr[p];
		if (i.member.user.id == id) return i;
	}

	return result;
}

voice_state_c guild_control::update_voice_state(voice_state_c& c)
{
	voice_state_c result = c;
	auto& arr = guild.voice_states;

	for (size_t p = 0; p < arr.size(); p++) {
		auto& i = arr[p];
		if (i.member.user.id == c.member.user.id) {
			i = c;
			return i;
		}
	}
	guild.voice_states.push_back(c);

	return result;
}

voice_state_c guild_control::cut_voice_state(const ULL id)
{
	voice_state_c result;
	auto& arr = guild.voice_states;

	for (size_t p = 0; p < arr.size(); p++) {
		auto& i = arr[p];
		if (i.member.user.id == id) {
			result = i;
			arr.erase(p);
			return result;
		}
	}

	return result;
}

guild_control::guild_control(std::shared_ptr<aegis::ratelimit::ratelimit_mgr> mng, std::shared_ptr<spdlog::logger> l)
{
	ratelimit = mng;
	logg = l;
}


guild_c& guild_control::get_raw_guild()
{
	return guild;
}

user_c guild_control::get_bot()
{
	return bot;
}

void guild_control::set_after_handle(handle_event hev)
{
	event_custom_handle = hev;
}

void guild_control::manage(the_event& ev)
{
	switch (ev.type) {
	case event_type::GUILD_MEMBER_ADD:
	{
		auto& ref = ev.data.guild_member_add;
		if (!ref.is_set()) return;

		update_member(*ref);
	}
	break;
	case event_type::GUILD_MEMBER_UPDATE:
	{
		auto& ref = ev.data.guild_member_update;
		if (!ref.is_set()) return;

		update_member(*ref);
	}
	break;
	case event_type::GUILD_MEMBER_REMOVE:
	{
		auto& ref = ev.data.guild_member_remove;
		if (!ref.is_set()) return;

		auto cpy = cut_member(ref->user.id);
		cpy.user = ref->user; // update what it has with new info
		ref->user = cpy.user; // copy back to event
	}
	break;
	//case event_type::MESSAGE_CREATE:
	//case event_type::MESSAGE_UPDATE:
	//case event_type::MESSAGE_DELETE:
	case event_type::PRESENCE_UPDATE:
	{
		auto& ref = ev.data.presence_update;
		if (!ref.is_set()) return;

		update_and_shrink_presence(*ref);
	}
	break;
	//case event_type::TYPING_START:
	case event_type::GUILD_CREATE:
	{
		auto& ref = ev.data.guild_create;
		if (!ref.is_set()) return;

		guild = *ref;
	}
	break;
	case event_type::GUILD_UPDATE:
	{
		auto& ref = ev.data.guild_update;
		if (!ref.is_set()) return;

		guild = *ref;
	}
	break;
	//case event_type::GUILD_DELETE:
	//case event_type::MESSAGE_REACTION_ADD:
	//case event_type::MESSAGE_REACTION_REMOVE:
	//case event_type::MESSAGE_REACTION_REMOVE_ALL:
	//case event_type::MESSAGE_DELETE_BULK:
	case event_type::USER_UPDATE:
	{
		auto& ref = ev.data.user_update;
		if (!ref.is_set()) return;

		auto memb = get_member(ref->id);
		memb.user = *ref;
		update_member(memb);
	}
	break;
	//case event_type::INVITE_CREATE:
	//case event_type::INVITE_DELETE:
	case event_type::CHANNEL_CREATE:
	{
		auto& ref = ev.data.channel_create;
		if (!ref.is_set()) return;

		update_channel(*ref);
	}
	break;
	case event_type::CHANNEL_UPDATE:
	{
		auto& ref = ev.data.channel_update;
		if (!ref.is_set()) return;

		update_channel(*ref);
	}
	break;
	case event_type::CHANNEL_DELETE:
	{
		auto& ref = ev.data.channel_delete;
		if (!ref.is_set()) return;

		auto cpy = cut_channel(ref->id);
		cpy = ref; // update what it has with new info
		ref = cpy; // copy back to event
	}
	break;
	//case event_type::CHANNEL_PINS_UPDATE:
	//case event_type::GUILD_BAN_ADD:
	//case event_type::GUILD_BAN_REMOVE:
	case event_type::GUILD_EMOJIS_UPDATE:
	{
		auto& ref = ev.data.guild_emojis_update;
		if (!ref.is_set()) return;

		guild.emojis = ref->emojis;
	}
	break;
	//case event_type::GUILD_INTEGRATIONS_UPDATE:
	case event_type::GUILD_MEMBERS_CHUNK:
	{
		auto& ref = ev.data.guild_members_chunk;
		if (!ref.is_set()) return;

		for (size_t p = 0; p < ref->members.size(); p++) {
			auto& i = ref->members[p];
			update_member(i); // update member
		}
	}
	break;
	case event_type::GUILD_ROLE_CREATE:
	{
		auto& ref = ev.data.guild_role_create;
		if (!ref.is_set()) return;

		update_role(ref->role);
	}
	break;
	case event_type::GUILD_ROLE_UPDATE:
	{
		auto& ref = ev.data.guild_role_update;
		if (!ref.is_set()) return;

		update_role(ref->role);
	}
	break;
	case event_type::GUILD_ROLE_DELETE:
	{
		auto& ref = ev.data.guild_role_delete;
		if (!ref.is_set()) return;

		auto cpy = cut_role(ref->role.id);
		cpy = ref->role; // update what it has with new info
		ref->role = cpy; // copy back to event
	}
	break;
	case event_type::VOICE_STATE_UPDATE:
	{
		auto& ref = ev.data.voice_state_update;
		if (!ref.is_set()) return;

		*ref = update_voice_state(*ref);
		ref->member = get_member(ref->member.user.id);
	}
	break;
	//case event_type::VOICE_SERVER_UPDATE:
	//case event_type::WEBHOOKS_UPDATE:
	}
	if (event_custom_handle) event_custom_handle(ev);
}

bool guild_control::bot_has_perm(const ULL chid, const permissions_user p)
{
	return (get_local_user_permissions(chid, bot.id) & p);
}

int64_t guild_control::get_global_user_permissions(const ULL id)
{
	if (!id) return 0;

	member_c memb = get_member(id);

	if (!memb.user.id.is_set()) return 0;

	if (guild.owner_id == id)
		return ~0;

	role_c role_everyone = get_role(guild.id);
	int64_t permissions = role_everyone.permissions.get();

	for (size_t p = 0; p < memb.roles.size(); p++) {
		auto rl = get_role(memb.roles[p]);
		permissions |= rl.permissions.get();
	}

	if (permissions & permissions_user::ADMINISTRATOR)
		return ~0;

	return permissions;
}

int64_t guild_control::get_local_user_permissions(const ULL chid, const ULL usid)
{
	if (!usid || !chid) return 0; // no user or no channel, no perms.

	auto permissions = get_global_user_permissions(usid);
	//logg->warn("BASIC=\n{}", debug_permission(permissions));

	if (permissions & permissions_user::ADMINISTRATOR)
		return ~0;

	channel_c specific = get_channel(chid);
	member_c member = get_member(usid);

	int64_t allow = 0, user_allow = 0;
	int64_t deny = 0, user_deny = 0;
	
	for (size_t p = 0; p < specific.permission_overwrites.size(); p++) {
		auto& i = specific.permission_overwrites[p];

		if (i.type == "role") {
			if (!member.has_role(i.id) && (i.id != guild.id)) continue;
			deny |= i.deny;
			allow |= i.allow;
		}
		else if (i.id == usid) { // there should be only one you (if one)
			user_deny = i.deny;
			user_allow = i.allow;
		}
	}

	permissions &= ~deny;
	permissions |= allow;
	permissions &= ~user_deny;
	permissions |= user_allow;

	return permissions;	
}

bool guild_control::does_channel_exist(const ULL id)
{
	if (!id) return false;
	for (size_t p = 0; p < guild.channels.size(); p++) {
		if (guild.channels[p].id == id) return true;
	}
	return false;
}

member_c guild_control::get_member(const ULL id)
{
	if (!id) return member_c();
	member_c result;
	auto& arr = guild.members;

	for (size_t p = 0; p < arr.size(); p++) {
		auto& i = arr[p];
		if (i.user.id == id) return i;
	}

	return result;
}

role_c guild_control::get_role(const ULL id)
{
	if (!id) return role_c();
	role_c result;
	auto& arr = guild.roles;

	for (size_t p = 0; p < arr.size(); p++) {
		auto& i = arr[p];
		if (i.id == id) return i;
	}

	return result;
}

channel_c guild_control::get_channel(const ULL id)
{
	if (!id) return channel_c();
	channel_c result;
	auto& arr = guild.channels;

	for (size_t p = 0; p < arr.size(); p++) {
		auto& i = arr[p];
		if (i.id == id) return i;
	}

	return result;
}

presence_c guild_control::get_presence(const ULL id)
{
	if (!id) return presence_c();
	presence_c result;
	auto& arr = guild.presences;

	for (size_t p = 0; p < arr.size(); p++) {
		auto& i = arr[p];
		if (i.user.id == id) return i;
	}

	return result;
}

message_c guild_control::create_message(const ULL chid, const std::string& content, int64_t nonce, bool autosplit)
{
	if (!chid || content.empty()) return message_c();

	if (autosplit && content.length() > max_message_len) {
		auto widenn = widen(content); // utf8 should become one.

		const size_t each_slice_len = (max_message_len / sizeof(wchar_t)) - 1;

		message_c last_msg;

		for (size_t p = 0; p * each_slice_len < widenn.length(); p++) {
			auto resnow = narrow(widenn.substr(p * each_slice_len, each_slice_len)); // back utf8
			last_msg = create_message(chid, resnow, nonce, false);
		}
	}

	if (!bot_has_perm(chid, permissions_user::SEND_MESSAGES)) {
		throw std::exception("No permission to send messages.");
	}
	if (!does_channel_exist(chid)) {
		throw std::exception("Invalid channel.");
	}

	nlohmann::json obj;
	obj["content"] = content;
	if (nonce)
		obj["nonce"] = nonce;

	std::string _endpoint = fmt::format("/channels/{}/messages", chid);

	message_c message;
	aegis::rest::request_params params = { _endpoint, aegis::rest::Post, obj.dump(-1, ' ', true) };
	auto& bkt = ratelimit->get_bucket(params.path);
	aegis::rest::rest_reply res = bkt.perform(params);

	message.load(res.content);

	return message;
}

message_c guild_control::create_message_embed(const ULL chid, const nlohmann::json& embed, const std::string& content, int64_t nonce)
{
	if (!chid || embed.empty()) return message_c();

	if (!bot_has_perm(chid, permissions_user::SEND_MESSAGES) || !bot_has_perm(chid, permissions_user::EMBED_LINKS)) {
		throw std::exception("No permission to send messages.");
	}
	if (!does_channel_exist(chid)) {
		throw std::exception("Invalid channel.");
	}

	nlohmann::json obj;
	if (!content.empty())
		obj["content"] = content;
	if (!embed.empty())
		obj["embed"] = embed;
	if (nonce)
		obj["nonce"] = nonce;

	std::string _endpoint = fmt::format("/channels/{}/messages", chid);
	
	message_c message;
	aegis::rest::request_params params = { _endpoint, aegis::rest::Post, obj.dump(-1, ' ', true) };
	auto& bkt = ratelimit->get_bucket(params.path);
	aegis::rest::rest_reply res = bkt.perform(params);

	message.load(res.content);

	return message;
}

message_c guild_control::get_message(const ULL chid, const ULL mid)
{
	if (!chid || !mid) return message_c();

	if (!bot_has_perm(chid, permissions_user::READ_MESSAGE_HISTORY)) {
		throw std::exception("No permission to read messages.");
	}

	std::string _endpoint = fmt::format("/channels/{}/messages/{}", chid, mid);

	message_c message;
	aegis::rest::request_params params = { _endpoint, aegis::rest::Get };
	auto& bkt = ratelimit->get_bucket(params.path);
	aegis::rest::rest_reply res = bkt.perform(params);

	message.load(res.content);

	return message;
}
