#include "resources.h"


bool operator==(const std::string i, const guild_features& v)
{
	switch (v) {		
	case guild_features::INVITE_SPLASH:
		return i == "INVITE_SPLASH";
	case guild_features::VIP_REGIONS:
		return i == "VIP_REGIONS";
	case guild_features::VANITY_URL:
		return i == "VANITY_URL";
	case guild_features::VERIFIED:
		return i == "VERIFIED";
	case guild_features::PARTNERED:
		return i == "PARTNERED";
	case guild_features::PUBLIC:
		return i == "PUBLIC";
	case guild_features::COMMERCE:
		return i == "COMMERCE";
	case guild_features::NEWS:
		return i == "NEWS";
	case guild_features::DISCOVERABLE:
		return i == "DISCOVERABLE";
	case guild_features::FEATURABLE:
		return i == "FEATURABLE";
	case guild_features::ANIMATED_ICON:
		return i == "ANIMATED_ICON";
	case guild_features::BANNER:
		return i == "BANNER";
	case guild_features::PUBLIC_DISABLED:
		return i == "PUBLIC_DISABLED";
	case guild_features::WELCOME_SCREEN_ENABLED:
		return i == "WELCOME_SCREEN_ENABLED";
	}
	return false;
}


bool operator==(const int64_t& i, const user_premium_type& v)
{
	return i == static_cast<int64_t>(v);
}
bool operator&(const int64_t& i, const user_flags& v)
{
	return i & static_cast<int64_t>(v);
}
bool operator&(const int64_t& i, const system_channel_flags& v)
{
	return i & static_cast<int64_t>(v);
}
bool operator&(const int64_t& i, const activity_flags& v)
{
	return i & static_cast<int64_t>(v);
}
bool operator&(const int64_t& i, const permissions_user& v)
{
	return i & static_cast<int64_t>(v);
}


ULL stdstoulla(std::string str) {
	while (str.length() > 0) if (!std::isdigit(str[0])) str.erase(str.begin()); else break;
	if (str.length() == 0) return 0;
	ULL t;
	if (sscanf_s(str.c_str(), "%llu", &t) == 1) {
		return t;
	}
	return 0;
}

int64_t stdstointa(std::string str) {
	while (str.length() > 0) if (!std::isdigit(str[0])) str.erase(str.begin()); else break;
	if (str.length() == 0) return 0;
	int64_t t;
	if (sscanf_s(str.c_str(), "%I64d", &t) == 1) {
		return t;
	}
	return 0;
}

std::string narrow(const std::wstring& ws)
{
	std::wstring_convert <std::codecvt_utf8 <wchar_t>, wchar_t> convert;
	return convert.to_bytes(ws);
}

std::wstring widen(const std::string& s)
{
	std::wstring_convert <std::codecvt_utf8 <wchar_t>, wchar_t> convert;
	return convert.from_bytes(s);
}

std::string debug_permission(const int64_t p) {
	std::string out;
	if (p & permissions_user::CREATE_INSTANT_INVITE)	out += "CREATE_INSTANT_INVITE;";
	if (p & permissions_user::KICK_MEMBERS)				out += "KICK_MEMBERS;";
	if (p & permissions_user::BAN_MEMBERS)				out += "BAN_MEMBERS;";
	if (p & permissions_user::ADMINISTRATOR)			out += "ADMINISTRATOR;";
	if (p & permissions_user::MANAGE_CHANNELS)			out += "MANAGE_CHANNELS;";
	if (p & permissions_user::MANAGE_GUILD)				out += "MANAGE_GUILD;";
	if (p & permissions_user::ADD_REACTIONS)			out += "ADD_REACTIONS;";
	if (p & permissions_user::VIEW_AUDIT_LOG)			out += "VIEW_AUDIT_LOG;";
	if (p & permissions_user::PRIORITY_SPEAKER)			out += "PRIORITY_SPEAKER;";
	if (p & permissions_user::STREAM)					out += "STREAM;";
	if (p & permissions_user::VIEW_CHANNEL)				out += "VIEW_CHANNEL;";
	if (p & permissions_user::SEND_MESSAGES)			out += "SEND_MESSAGES;";
	if (p & permissions_user::SEND_TTS_MESSAGES)		out += "SEND_TTS_MESSAGES;";
	if (p & permissions_user::MANAGE_MESSAGES)			out += "MANAGE_MESSAGES;";
	if (p & permissions_user::EMBED_LINKS)				out += "EMBED_LINKS;";
	if (p & permissions_user::ATTACH_FILES)				out += "ATTACH_FILES;";
	if (p & permissions_user::READ_MESSAGE_HISTORY)		out += "READ_MESSAGE_HISTORY;";
	if (p & permissions_user::MENTION_EVERYONE)			out += "MENTION_EVERYONE;";
	if (p & permissions_user::USE_EXTERNAL_EMOJIS)		out += "USE_EXTERNAL_EMOJIS;";
	if (p & permissions_user::VIEW_GUILD_INSIGHTS)		out += "VIEW_GUILD_INSIGHTS;";
	if (p & permissions_user::CONNECT)					out += "CONNECT;";
	if (p & permissions_user::SPEAK)					out += "SPEAK;";
	if (p & permissions_user::MUTE_MEMBERS)				out += "MUTE_MEMBERS;";
	if (p & permissions_user::DEAFEN_MEMBERS)			out += "DEAFEN_MEMBERS;";
	if (p & permissions_user::MOVE_MEMBERS)				out += "MOVE_MEMBERS;";
	if (p & permissions_user::USE_VAD)					out += "USE_VAD;";
	if (p & permissions_user::CHANGE_NICKNAME)			out += "CHANGE_NICKNAME;";
	if (p & permissions_user::MANAGE_NICKNAMES)			out += "MANAGE_NICKNAMES;";
	if (p & permissions_user::MANAGE_ROLES)				out += "MANAGE_ROLES;";
	if (p & permissions_user::MANAGE_WEBHOOKS)			out += "MANAGE_WEBHOOKS;";
	if (p & permissions_user::MANAGE_EMOJIS)			out += "MANAGE_EMOJIS;";
	return out;
}


bool time_iso::operator==(const time_iso& t)
{
	return 
		year == t.year &&
		month == t.month &&
		day == t.day &&
		hour == t.hour &&
		minute == t.minute &&
		second == t.second;
}

void time_iso::input(const std::string iso) // format: 2020-09-23T18:15:46.827642+00:00
{
	if (iso.empty()) throw std::exception("null iso time format");
	sscanf_s(iso.c_str(), "%u-%u-%uT%u:%u:%f", year.get_ptr(), month.get_ptr(), day.get_ptr(), hour.get_ptr(), minute.get_ptr(), second.get_ptr());
	iso_format = iso;
}

void time_iso::input_epoch_ms(const int64_t dt)
{
	time_t temp = dt / 1e3;
	tm tn;
	if (errno_t err = _gmtime64_s(&tn, &temp); err) {
		throw std::exception(("time_t can't be set, errno = " + std::to_string(err)).c_str());
	}
	year = tn.tm_year + 1900;
	month = tn.tm_mon + 1;
	day = tn.tm_mday;
	hour = tn.tm_hour;
	minute = tn.tm_min;
	second = (float)(tn.tm_sec) + (float)((dt % 1000) * 1e-3f);
}

void time_iso::input_epoch_s(const int64_t t)
{
	input_epoch_ms(t * 1000ull);
}

std::string time_iso::nice_format() const
{
	char buf[64];
	sprintf_s(buf, "%04u/%02u/%02u %02u:%02u:%06.3f", year.get(), month.get(), day.get(), hour.get(), minute.get(), second.get());
	return buf;
}



overwrite_c& overwrite_c::load(const nlohmann::json& j)
{
	if (j.count("id") && !j["id"].is_null())						id = stdstoulla(j["id"].get<std::string>());
	if (j.count("type") && !j["type"].is_null())					type = j["type"].get<std::string>();
	if (j.count("allow") && !j["allow"].is_null())					allow = j["allow"].get<int64_t>();
	if (j.count("allow_new") && !j["allow_new"].is_null())			allow_new = j["allow_new"].get<std::string>();
	if (j.count("deny") && !j["deny"].is_null())					deny = j["deny"].get<int64_t>();
	if (j.count("deny_new") && !j["deny_new"].is_null())			deny_new = j["deny_new"].get<std::string>();	

	return *this;
}




bool user_c::is_public_discord_employee() const {
	return public_flags.get() & user_flags::Discord_Employee;
}
bool user_c::is_public_discord_partner() const {
	return public_flags.get() & user_flags::Discord_Partner;
}
bool user_c::is_public_hypesquad_events() const {
	return public_flags.get() & user_flags::HypeSquad_Events;
}
bool user_c::is_public_bug_hunter_level_1() const {
	return public_flags.get() & user_flags::Bug_Hunter_Level_1;
}
bool user_c::is_public_house_bravery() const {
	return public_flags.get() & user_flags::House_Bravery;
}
bool user_c::is_public_house_brilliance() const {
	return public_flags.get() & user_flags::House_Brilliance;
}
bool user_c::is_public_house_balance() const {
	return public_flags.get() & user_flags::House_Balance;
}
bool user_c::is_public_early_supporter() const {
	return public_flags.get() & user_flags::Early_Supporter;
}
bool user_c::is_public_team_user() const {
	return public_flags.get() & user_flags::Team_User;
}
bool user_c::is_public_system() const {
	return public_flags.get() & user_flags::System;
}
bool user_c::is_public_bug_hunter_level_2() const {
	return public_flags.get() & user_flags::Bug_Hunter_Level_2;
}
bool user_c::is_public_verified_bot() const {
	return public_flags.get() & user_flags::Verified_Bot;
}
bool user_c::is_public_verified_bot_developer() const {
	return public_flags.get() & user_flags::Verified_Bot_Developer;
}


bool user_c::is_discord_employee() const {
	return flags.get() & user_flags::Discord_Employee;
}
bool user_c::is_discord_partner() const {
	return flags.get() & user_flags::Discord_Partner;
}
bool user_c::is_hypesquad_events() const {
	return flags.get() & user_flags::HypeSquad_Events;
}
bool user_c::is_bug_hunter_level_1() const {
	return flags.get() & user_flags::Bug_Hunter_Level_1;
}
bool user_c::is_house_bravery() const {
	return flags.get() & user_flags::House_Bravery;
}
bool user_c::is_house_brilliance() const {
	return flags.get() & user_flags::House_Brilliance;
}
bool user_c::is_house_balance() const {
	return flags.get() & user_flags::House_Balance;
}
bool user_c::is_early_supporter() const {
	return flags.get() & user_flags::Early_Supporter;
}
bool user_c::is_team_user() const {
	return flags.get() & user_flags::Team_User;
}
bool user_c::is_system() const {
	return flags.get() & user_flags::System;
}
bool user_c::is_bug_hunter_level_2() const {
	return flags.get() & user_flags::Bug_Hunter_Level_2;
}
bool user_c::is_verified_bot() const {
	return flags.get() & user_flags::Verified_Bot;
}
bool user_c::is_verified_bot_developer() const {
	return flags.get() & user_flags::Verified_Bot_Developer;
}

bool user_c::is_webhook() const
{
	return (bot.is_set()) && (discriminator.get() == "0000" || discriminator.get() == "0");
}

// classic nitro
bool user_c::is_nitro_classic() const {
	return premium_type.get() == user_premium_type::Nitro_Classic;
}
// full nitro
bool user_c::is_nitro() const {
	return premium_type.get() == user_premium_type::Nitro;
}

std::string user_c::get_combo_name()
{
	return username.get() + "#" + discriminator.get();
}


user_c& user_c::load(const nlohmann::json& j)
{
	if (j.count("id") && !j["id"].is_null())						id = stdstoulla(j["id"].get<std::string>());
	if (j.count("username") && !j["username"].is_null())			username = j["username"].get<std::string>();
	if (j.count("discriminator") && !j["discriminator"].is_null())	discriminator = j["discriminator"].get<std::string>();
	if (j.count("avatar") && !j["avatar"].is_null())				avatar = j["avatar"].get<std::string>();
	if (j.count("bot") && !j["bot"].is_null())						bot = j["bot"].get<bool>();
	if (j.count("system") && !j["system"].is_null())				system = j["system"].get<bool>();
	if (j.count("mfa_enabled") && !j["mfa_enabled"].is_null())		mfa_enabled = j["mfa_enabled"].get<bool>();
	if (j.count("locale") && !j["locale"].is_null())				locale = j["locale"].get<std::string>();
	if (j.count("verified") && !j["verified"].is_null())			verified = j["verified"].get<bool>();
	if (j.count("email") && !j["email"].is_null())					email = j["email"].get<std::string>();
	if (j.count("flags") && !j["flags"].is_null())					flags = j["flags"].get<int64_t>();
	if (j.count("premium_type") && !j["premium_type"].is_null())	premium_type = j["premium_type"].get<int64_t>();
	if (j.count("public_flags") && !j["public_flags"].is_null())	public_flags = j["public_flags"].get<int64_t>();

	return *this;
}


bool member_c::has_role(const ULL roleid)
{
	for (size_t p = 0; p < roles.size(); p++) {
		if (roles[p] == roleid) return true;
	}
	return false;
}

member_c& member_c::load(const nlohmann::json& j)
{
	if (j.count("guild_id") && !j["guild_id"].is_null())			guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("user") && !j["user"].is_null())					user.load(j["user"]);

	if (j.count("roles") && !j["roles"].is_null()) {
		for (const auto& _field : j["roles"])
			roles.push_back(stdstoulla(_field.get<std::string>()));
	}

	if (j.count("joined_at") && !j["joined_at"].is_null())			joined_at.input(j["joined_at"].get<std::string>());
	if (j.count("premium_since") && !j["premium_since"].is_null())	premium_since.input(j["premium_since"].get<std::string>());
	if (j.count("deaf") && !j["deaf"].is_null())					deaf = j["deaf"].get<bool>();
	if (j.count("mute") && !j["mute"].is_null())					mute = j["mute"].get<bool>();

	return *this;
}



channel_c& channel_c::load(const nlohmann::json& j)
{
	if (j.count("id") && !j["id"].is_null())									id = stdstoulla(j["id"].get<std::string>());
	if (j.count("type") && !j["type"].is_null())								type = j["type"].get<int64_t>();
	if (j.count("guild_id") && !j["guild_id"].is_null())						guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("position") && !j["position"].is_null())						position = j["position"].get<int64_t>();

	//std::vector<overwrite_c> permission_overwrites;
	if (j.count("permission_overwrites") && !j["permission_overwrites"].is_null()) {
		for (const auto& _field : j["permission_overwrites"])
			permission_overwrites.emplace_back(std::move(overwrite_c().load(_field)));
	}

	if (j.count("name") && !j["name"].is_null())								name = j["name"].get<std::string>();
	if (j.count("topic") && !j["topic"].is_null())								topic = j["topic"].get<std::string>();
	if (j.count("nsfw") && !j["nsfw"].is_null())								nsfw = j["nsfw"].get<bool>();
	if (j.count("last_message_id") && !j["last_message_id"].is_null())			last_message_id = stdstoulla(j["last_message_id"].get<std::string>());
	if (j.count("bitrate") && !j["bitrate"].is_null())							bitrate = j["bitrate"].get<int64_t>();
	if (j.count("user_limit") && !j["user_limit"].is_null())					user_limit = j["user_limit"].get<int64_t>();
	if (j.count("rate_limit_per_user") && !j["rate_limit_per_user"].is_null())	rate_limit_per_user = j["rate_limit_per_user"].get<int64_t>();

	//std::vector<user_c> recipients;
	if (j.count("recipients") && !j["recipients"].is_null()) {
		for (const auto& _field : j["recipients"])
			recipients.emplace_back(std::move(user_c().load(_field)));
	}

	if (j.count("icon") && !j["icon"].is_null())								icon = j["icon"].get<std::string>();
	if (j.count("owner_id") && !j["owner_id"].is_null())						owner_id = stdstoulla(j["owner_id"].get<std::string>());
	if (j.count("application_id") && !j["application_id"].is_null())			application_id = stdstoulla(j["application_id"].get<std::string>());;
	if (j.count("parent_id") && !j["parent_id"].is_null())						parent_id = stdstoulla(j["parent_id"].get<std::string>());;
	if (j.count("last_pin_timestamp") && !j["last_pin_timestamp"].is_null())	last_pin_timestamp = j["last_pin_timestamp"].get<std::string>();

	return *this;
}

channel_pin_update_c& channel_pin_update_c::load(const nlohmann::json& j)
{
	if (j.count("guild_id") && !j["guild_id"].is_null())						guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("channel_id") && !j["channel_id"].is_null())					channel_id = stdstoulla(j["channel_id"].get<std::string>());
	if (j.count("last_pin_timestamp") && !j["last_pin_timestamp"].is_null())	last_pin_timestamp.input(j["last_pin_timestamp"].get<std::string>());

	return *this;
}


channel_mention_c& channel_mention_c::load(const nlohmann::json& j)
{
	if (j.count("id") && !j["id"].is_null())				id = stdstoulla(j["id"].get<std::string>());
	if (j.count("guild_id") && !j["guild_id"].is_null())	guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("type") && !j["type"].is_null())			type = j["type"].get<int64_t>();
	if (j.count("name") && !j["name"].is_null())			name = j["name"].get<std::string>();

	return *this;
}


attachment_c& attachment_c::load(const nlohmann::json& j)
{
	if (j.count("id") && !j["id"].is_null())				id = stdstoulla(j["id"].get<std::string>());
	if (j.count("filename") && !j["filename"].is_null())	filename = j["filename"].get<std::string>();
	if (j.count("size") && !j["size"].is_null())			size = j["size"].get<int64_t>();
	if (j.count("url") && !j["url"].is_null())				url = j["url"].get<std::string>();
	if (j.count("proxy_url") && !j["proxy_url"].is_null())	proxy_url = j["proxy_url"].get<std::string>();
	if (j.count("height") && !j["height"].is_null())		height = j["height"].get<int64_t>();
	if (j.count("width") && !j["width"].is_null())			width = j["width"].get<int64_t>();

	return *this;
}



role_c& role_c::load(const nlohmann::json& j)
{
	if (j.count("id") && !j["id"].is_null())							id = stdstoulla(j["id"].get<std::string>());
	if (j.count("name") && !j["name"].is_null())						name = j["name"].get<std::string>();
	if (j.count("color") && !j["color"].is_null())						color = j["color"].get<int64_t>();
	if (j.count("hoist") && !j["hoist"].is_null())						hoist = j["hoist"].get<bool>();
	if (j.count("position") && !j["position"].is_null())				position = j["position"].get<int64_t>();
	if (j.count("permissions") && !j["permissions"].is_null())			permissions = j["permissions"].get<int64_t>();
	if (j.count("permissions_new") && !j["permissions_new"].is_null())	permissions_new = j["permissions_new"].get<std::string>();
	if (j.count("managed") && !j["managed"].is_null())					managed = j["managed"].get<bool>();
	if (j.count("mentionable") && !j["mentionable"].is_null())			mentionable = j["mentionable"].get<bool>();

	return *this;
}



bool emoji_c::operator==(const emoji_c& c)
{
	return 
		id == c.id &&
		name == c.name &&
		animated == c.animated;
}

std::string emoji_c::format()
{
	return id.get() ? fmt::format("<{}:{}:{}>", animated.get() ? "a" : "", name.get(), id.get()) : name.get();
}

emoji_c& emoji_c::load(const nlohmann::json& j)
{
	if (j.count("id") && !j["id"].is_null())							id = stdstoulla(j["id"].get<std::string>());
	if (j.count("name") && !j["name"].is_null())						name = j["name"].get<std::string>();

	//std::vector<role_c> roles;
	if (j.count("roles") && !j["roles"].is_null()) {
		for (const auto& _field : j["roles"])
			roles.emplace_back(std::move(role_c().load(_field)));
	}

	if (j.count("user") && !j["user"].is_null())						user.load(j["user"]);
	if (j.count("require_colons") && !j["require_colons"].is_null())	require_colons = j["require_colons"].get<bool>();
	if (j.count("managed") && !j["managed"].is_null())					managed = j["managed"].get<bool>();
	if (j.count("animated") && !j["animated"].is_null())				animated = j["animated"].get<bool>();
	if (j.count("available") && !j["available"].is_null())				available = j["available"].get<bool>();

	return *this;
}


reaction_c& reaction_c::load(const nlohmann::json& j)
{
	if (j.count("count") && !j["count"].is_null())				count = j["count"].get<int64_t>();
	if (j.count("me") && !j["me"].is_null())					me = j["me"].get<bool>();
	if (j.count("emoji") && !j["emoji"].is_null())				emoji.load(j["emoji"]);

	return *this;
}

message_activity_c& message_activity_c::load(const nlohmann::json& j)
{
	if (j.count("type") && !j["type"].is_null())				type = j["type"].get<int64_t>();
	if (j.count("party_id") && !j["party_id"].is_null())		party_id = j["party_id"].get<std::string>();

	return *this;
}


message_application_c& message_application_c::load(const nlohmann::json& j)
{
	if (j.count("id") && !j["id"].is_null())					id = stdstoulla(j["id"].get<std::string>());
	if (j.count("cover_image") && !j["cover_image"].is_null())	cover_image = j["cover_image"].get<std::string>();
	if (j.count("description") && !j["description"].is_null())	description = j["description"].get<std::string>();
	if (j.count("icon") && !j["icon"].is_null())				icon = j["icon"].get<std::string>();
	if (j.count("name") && !j["name"].is_null())				name = j["name"].get<std::string>();	

	return *this;
}

message_reference_c& message_reference_c::load(const nlohmann::json& j)
{
	if (j.count("message_id") && !j["message_id"].is_null())	message_id = stdstoulla(j["message_id"].get<std::string>());
	if (j.count("channel_id") && !j["channel_id"].is_null())	channel_id = stdstoulla(j["channel_id"].get<std::string>());
	if (j.count("guild_id") && !j["guild_id"].is_null())		guild_id = stdstoulla(j["guild_id"].get<std::string>());

	return *this;
}

/*message_c::message_c(aegis::core* c)
{
	c->log->warn("[IN_] Got Message_C no body");
}

message_c::message_c(const std::string& sj, aegis::core* c)
{
	c->log->info("[IN_] Got Message_C with body. Parsing.");
	load(nlohmann::json::parse(sj));
}*/

void message_c::operator=(const message_c& c)
{
	id = c.id;
	channel_id = c.channel_id;
	guild_id = c.guild_id;
	member = c.member;
	content = c.content;
	timestamp = c.timestamp;
	edited_timestamp = c.edited_timestamp;
	tts = c.tts;
	mention_everyone = c.mention_everyone;
	mentions = c.mentions;
	mention_roles = c.mention_roles;
	mention_channels = c.mention_channels;
	attachments = c.attachments;
	embeds = c.embeds;
	reactions = c.reactions;
	pinned = c.pinned;
	webhook_id = c.webhook_id;
	type = c.type;
	activity = c.activity;
	application = c.application;
	message_reference = c.message_reference;
	flags = c.flags;
}

message_c::operator bool() const
{
	return id.is_set() || author.id.is_set(); // if id is set, probably it is fine.
}

message_c& message_c::load(const nlohmann::json& j)
{
	if (j.count("id") && !j["id"].is_null())								id = stdstoulla(j["id"].get<std::string>());
	if (j.count("channel_id") && !j["channel_id"].is_null())				channel_id = stdstoulla(j["channel_id"].get<std::string>());
	if (j.count("guild_id") && !j["guild_id"].is_null())					guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("author") && !j["author"].is_null())						author.load(j["author"]);
	if (j.count("member") && !j["member"].is_null())						member.load(j["member"]);
	if (j.count("content") && !j["content"].is_null())						content = j["content"].get<std::string>();
	if (j.count("timestamp") && !j["timestamp"].is_null())					timestamp.input(j["timestamp"].get<std::string>());
	if (j.count("edited_timestamp") && !j["edited_timestamp"].is_null())	edited_timestamp.input(j["edited_timestamp"].get<std::string>());
	if (j.count("tts") && !j["tts"].is_null())								tts = j["tts"].get<bool>();
	if (j.count("mention_everyone") && !j["mention_everyone"].is_null())	mention_everyone = j["mention_everyone"].get<bool>();

	//std::vector<user_c> mentions;
	if (j.count("mentions") && !j["mentions"].is_null()) {
		for (const auto& _field : j["mentions"])
			mentions.emplace_back(std::move(user_c().load(_field)));
	}

	//std::vector<std::string> mention_roles;
	if (j.count("mention_roles") && !j["mention_roles"].is_null()) {
		for (const auto& _field : j["mention_roles"])
			mention_roles.push_back(_field);
	}

	//std::vector<channel_mention_c> mention_channels;
	if (j.count("mention_channels") && !j["mention_channels"].is_null()) {
		for (const auto& _field : j["mention_channels"])
			mention_channels.emplace_back(std::move(channel_mention_c().load(_field)));
	}

	//std::vector<attachment_c> attachments;
	if (j.count("attachments") && !j["attachments"].is_null()) {
		for (const auto& _field : j["attachments"])
			attachments.emplace_back(std::move(attachment_c().load(_field)));
	}

	//std::vector<nlohmann::json> embeds;
	if (j.count("embeds") && !j["embeds"].is_null()) {
		for (const auto& _field : j["embeds"])
			embeds.push_back(_field);
	}

	//std::vector<reaction_c> reactions;
	if (j.count("reactions") && !j["reactions"].is_null()) {
		for (const auto& _field : j["reactions"])
			reactions.emplace_back(std::move(reaction_c().load(_field)));
	}

	if (j.count("pinned") && !j["pinned"].is_null())						pinned = j["pinned"].get<bool>();
	if (j.count("webhook_id") && !j["webhook_id"].is_null())				webhook_id = stdstoulla(j["webhook_id"].get<std::string>());
	if (j.count("type") && !j["type"].is_null())							type = j["type"].get<int64_t>();
	if (j.count("activity") && !j["activity"].is_null())					activity.load(j["activity"]);
	if (j.count("application") && !j["application"].is_null())				application.load(j["application"]);
	if (j.count("message_reference") && !j["message_reference"].is_null())	message_reference.load(j["message_reference"]);
	if (j.count("flags") && !j["flags"].is_null())							flags = j["flags"].get<int64_t>();

	return *this;
}

message_delete_c& message_delete_c::load(const nlohmann::json& j)
{
	if (j.count("id") && !j["id"].is_null())						id = stdstoulla(j["id"].get<std::string>());
	if (j.count("channel_id") && !j["channel_id"].is_null())		channel_id = stdstoulla(j["channel_id"].get<std::string>());
	if (j.count("guild_id") && !j["guild_id"].is_null())			guild_id = stdstoulla(j["guild_id"].get<std::string>());

	return *this;
}

message_delete_bulk_c& message_delete_bulk_c::load(const nlohmann::json& j)
{
	//safe_vector<ULL> ids;
	if (j.count("ids") && !j["ids"].is_null()) {
		for (const auto& _field : j["ids"])
			ids.push_back(_field);
	}

	if (j.count("channel_id") && !j["channel_id"].is_null())		channel_id = stdstoulla(j["channel_id"].get<std::string>());
	if (j.count("guild_id") && !j["guild_id"].is_null())			guild_id = stdstoulla(j["guild_id"].get<std::string>());

	return *this;
}

message_reaction_add_c& message_reaction_add_c::load(const nlohmann::json& j)
{
	if (j.count("user_id") && !j["user_id"].is_null())				user_id = stdstoulla(j["user_id"].get<std::string>());
	if (j.count("channel_id") && !j["channel_id"].is_null())		channel_id = stdstoulla(j["channel_id"].get<std::string>());
	if (j.count("message_id") && !j["message_id"].is_null())		message_id = stdstoulla(j["message_id"].get<std::string>());
	if (j.count("guild_id") && !j["guild_id"].is_null())			guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("member") && !j["member"].is_null())				member.load(j["member"]);
	if (j.count("emoji") && !j["emoji"].is_null())					emoji.load(j["emoji"]);

	return *this;
}

message_reaction_remove_c& message_reaction_remove_c::load(const nlohmann::json& j)
{
	if (j.count("user_id") && !j["user_id"].is_null())				user_id = stdstoulla(j["user_id"].get<std::string>());
	if (j.count("channel_id") && !j["channel_id"].is_null())		channel_id = stdstoulla(j["channel_id"].get<std::string>());
	if (j.count("message_id") && !j["message_id"].is_null())		message_id = stdstoulla(j["message_id"].get<std::string>());
	if (j.count("guild_id") && !j["guild_id"].is_null())			guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("emoji") && !j["emoji"].is_null())					emoji.load(j["emoji"]);

	return *this;
}

message_reaction_remove_all_c& message_reaction_remove_all_c::load(const nlohmann::json& j)
{
	if (j.count("channel_id") && !j["channel_id"].is_null())		channel_id = stdstoulla(j["channel_id"].get<std::string>());
	if (j.count("message_id") && !j["message_id"].is_null())		message_id = stdstoulla(j["message_id"].get<std::string>());
	if (j.count("guild_id") && !j["guild_id"].is_null())			guild_id = stdstoulla(j["guild_id"].get<std::string>());

	return *this;
}

message_reaction_remove_emoji_c& message_reaction_remove_emoji_c::load(const nlohmann::json& j)
{
	if (j.count("channel_id") && !j["channel_id"].is_null())		channel_id = stdstoulla(j["channel_id"].get<std::string>());
	if (j.count("guild_id") && !j["guild_id"].is_null())			guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("message_id") && !j["message_id"].is_null())		message_id = stdstoulla(j["message_id"].get<std::string>());
	if (j.count("emoji") && !j["emoji"].is_null())					emoji.load(j["emoji"]);

	return *this;
}


voice_state_c& voice_state_c::load(const nlohmann::json& j)
{
	if (j.count("guild_id") && !j["guild_id"].is_null())				guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("channel_id") && !j["channel_id"].is_null())			channel_id = stdstoulla(j["channel_id"].get<std::string>());
	if (j.count("user_id") && !j["user_id"].is_null())					user_id = stdstoulla(j["user_id"].get<std::string>());
	if (j.count("member") && !j["member"].is_null())					member.load(j["user_id"]);
	if (j.count("session_id") && !j["session_id"].is_null())			session_id = j["user_id"].get<std::string>();
	if (j.count("deaf") && !j["deaf"].is_null())						deaf = j["deaf"].get<bool>();
	if (j.count("mute") && !j["mute"].is_null())						mute = j["mute"].get<bool>();
	if (j.count("self_deaf") && !j["self_deaf"].is_null())				self_deaf = j["self_deaf"].get<bool>();
	if (j.count("self_mute") && !j["self_mute"].is_null())				self_mute = j["self_mute"].get<bool>();
	if (j.count("self_stream") && !j["self_stream"].is_null())			self_stream = j["self_stream"].get<bool>();
	if (j.count("self_video") && !j["self_video"].is_null())			self_video = j["self_video"].get<bool>();
	if (j.count("suppress") && !j["suppress"].is_null())				suppress = j["suppress"].get<bool>();

	return *this;
}

voice_server_update_c& voice_server_update_c::load(const nlohmann::json& j)
{
	if (j.count("token") && !j["token"].is_null())					token = j["token"].get<std::string>();
	if (j.count("guild_id") && !j["guild_id"].is_null())			guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("endpoint") && !j["endpoint"].is_null())			endpoint = j["endpoint"].get<std::string>();

	return *this;
}



bool activity_secrets_c::operator==(const activity_secrets_c& c)
{
	return 
		join == c.join &&
		spectate == c.spectate &&
		match == c.match;
}

activity_secrets_c& activity_secrets_c::load(const nlohmann::json& j)
{
	if (j.count("join") && !j["join"].is_null())			join = j["join"].get<std::string>();
	if (j.count("spectate") && !j["spectate"].is_null())	spectate = j["spectate"].get<std::string>();
	if (j.count("match") && !j["match"].is_null())			match = j["match"].get<std::string>();

	return *this;
}

std::string activity_assets_c::large_url(const int64_t appid, const size_t size)
{
	if (!appid) return "";
	return url_assets + std::to_string(appid) + "/" + large_image.get() + "?size=" + std::to_string(size);
}

std::string activity_assets_c::small_url(const int64_t appid, const size_t size)
{
	if (!appid) return "";
	return url_assets + std::to_string(appid) + "/" + small_image.get() + "?size=" + std::to_string(size);
}

activity_assets_c& activity_assets_c::load(const nlohmann::json& j)
{
	if (j.count("large_image") && !j["large_image"].is_null())	large_image = j["large_image"].get<std::string>();
	if (j.count("large_text") && !j["large_text"].is_null())	large_text = j["large_text"].get<std::string>();
	if (j.count("small_image") && !j["small_image"].is_null())	small_image = j["small_image"].get<std::string>();
	if (j.count("small_text") && !j["small_text"].is_null())	small_text = j["small_text"].get<std::string>();

	return *this;
}

activity_party_c& activity_party_c::load(const nlohmann::json& j)
{
	if (j.count("id") && !j["id"].is_null())			id = j["id"].get<std::string>();

	//std::vector<int64_t> size;
	if (j.count("size") && !j["size"].is_null()) {
		for (const auto& _field : j["size"])
			size.push_back(_field);
	}

	return *this;
}

bool activity_c::has_new_data()
{
	return _changed;
}

bool activity_c::operator==(const activity_c& c)
{
	return
		name == c.name &&
		type == c.type &&
		url == c.url &&
		created_at == c.created_at &&
		timestamp == c.timestamp &&
		application_id == c.application_id &&
		details == c.details &&
		state == c.state &&
		emoji == c.emoji &&
		party.id == c.party.id &&
		secrets == c.secrets &&
		instance == c.instance &&
		flags == c.flags;
}

bool activity_c::similar(const activity_c& c)
{
	return
		name == c.name &&
		//details == c.details &&
		type == c.type &&
		application_id == c.application_id;
}

activity_c& activity_c::load(const nlohmann::json& j)
{
	if (j.count("name") && !j["name"].is_null())						name = j["name"].get<std::string>();
	if (j.count("type") && !j["type"].is_null())						type = j["type"].get<int64_t>();
	if (j.count("url") && !j["url"].is_null())							url = j["url"].get<std::string>();
	if (j.count("created_at") && !j["created_at"].is_null())			created_at = j["created_at"].get<int64_t>();
	if (j.count("timestamp") && !j["timestamp"].is_null())				timestamp.input(j["timestamp"].get<std::string>());
	if (j.count("application_id") && !j["application_id"].is_null())	application_id = stdstoulla(j["application_id"].get<std::string>());
	if (j.count("details") && !j["details"].is_null())					details = j["details"].get<std::string>();
	if (j.count("state") && !j["state"].is_null())						state = j["state"].get<std::string>();
	if (j.count("emoji") && !j["emoji"].is_null())						emoji.load(j["emoji"]);
	if (j.count("party") && !j["party"].is_null())						party.load(j["party"]);
	if (j.count("assets") && !j["assets"].is_null())					assets.load(j["assets"]);
	if (j.count("secrets") && !j["secrets"].is_null())					secrets.load(j["secrets"]);
	if (j.count("instance") && !j["instance"].is_null())				instance = j["instance"].get<bool>();
	if (j.count("flags") && !j["flags"].is_null())						flags = j["flags"].get<int64_t>();

	return *this;
}


client_status_c& client_status_c::load(const nlohmann::json& j)
{
	if (j.count("desktop") && !j["desktop"].is_null())	desktop = j["desktop"].get<std::string>();
	if (j.count("mobile") && !j["mobile"].is_null())	mobile = j["mobile"].get<std::string>();
	if (j.count("web") && !j["web"].is_null())			web = j["web"].get<std::string>();

	return *this;
}
/*
bool presence_c::update(const presence_c& n)
{
	bool changed = false;
	
	user = n.user; // user shouldn't be a trigger
	
	changed |= roles.size() != n.roles.size();
	if (roles.size() == n.roles.size()) {
		for (size_t p = 0; p < roles.size(); p++) {
			if (roles[p] != n.roles[p]) {
				changed = true;
				roles = n.roles;
				break;
			}
		}
	}
	else roles = n.roles;
	

}*/

presence_c& presence_c::load(const nlohmann::json& j)
{
	if (j.count("user") && !j["user"].is_null())						user.load(j["user"]);

	//std::vector<ULL> roles;
	if (j.count("roles") && !j["roles"].is_null()) {
		for (const auto& _field : j["roles"])
			roles.push_back(stdstoulla(_field.get<std::string>()));
	}

	if (j.count("game") && !j["game"].is_null())						game.load(j["game"]);
	if (j.count("guild_id") && !j["guild_id"].is_null())				guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("status") && !j["status"].is_null())					status = j["status"].get<std::string>();

	//std::vector<activity_c> activities;
	if (j.count("activities") && !j["activities"].is_null()) {
		for (const auto& _field : j["activities"])
			activities.emplace_back(std::move(activity_c().load(_field)));
	}

	if (j.count("client_status") && !j["client_status"].is_null())		client_status.load(j["client_status"]);
	if (j.count("premium_since") && !j["premium_since"].is_null())		premium_since.input(j["premium_since"].get<std::string>());
	if (j.count("nick") && !j["nick"].is_null())						nick = j["nick"].get<std::string>();

	return *this;
}



guild_c& guild_c::load(const nlohmann::json& j)
{
	if (j.count("id") && !j["id"].is_null())														id = stdstoulla(j["id"].get<std::string>());
	if (j.count("name") && !j["name"].is_null())													name = j["name"].get<std::string>();
	if (j.count("icon") && !j["icon"].is_null())													icon = j["icon"].get<std::string>();
	if (j.count("splash") && !j["splash"].is_null())												splash = j["splash"].get<std::string>();
	if (j.count("discovery_splash") && !j["discovery_splash"].is_null())							discovery_splash = j["discovery_splash"].get<std::string>();
	if (j.count("owner_id") && !j["owner_id"].is_null())											owner_id = stdstoulla(j["owner_id"].get<std::string>());
	if (j.count("permissions") && !j["permissions"].is_null())										permissions = j["permissions"].get<int64_t>();
	if (j.count("permissions_new") && !j["permissions_new"].is_null())								permissions_new = j["permissions_new"].get<std::string>();
	if (j.count("region") && !j["region"].is_null())												region = j["region"].get<std::string>();
	if (j.count("afk_channel") && !j["afk_channel"].is_null())										afk_channel = stdstoulla(j["afk_channel"].get<std::string>());
	if (j.count("verification_level") && !j["verification_level"].is_null())						verification_level = j["verification_level"].get<int64_t>();
	if (j.count("default_message_notifications") && !j["default_message_notifications"].is_null())	default_message_notifications = j["default_message_notifications"].get<int64_t>();
	if (j.count("explicit_content_filter") && !j["explicit_content_filter"].is_null())				explicit_content_filter = j["explicit_content_filter"].get<int64_t>();

	//std::vector<role_c> roles;
	if (j.count("roles") && !j["roles"].is_null()) {
		for (const auto& _field : j["roles"])
			roles.emplace_back(std::move(role_c().load(_field)));
	}

	//std::vector<emoji_c> emojis;
	if (j.count("emojis") && !j["emojis"].is_null()) {
		for (const auto& _field : j["emojis"])
			emojis.emplace_back(std::move(emoji_c().load(_field)));
	}

	//std::vector<std::string> features;
	if (j.count("features") && !j["features"].is_null()) {
		for (const auto& _field : j["features"])
			features.push_back(_field); // std::string
	}

	if (j.count("mfa_level") && !j["mfa_level"].is_null())											mfa_level = j["mfa_level"].get<int64_t>();
	if (j.count("application_id") && !j["application_id"].is_null())								application_id = stdstoulla(j["application_id"].get<std::string>());
	if (j.count("widget_enabled") && !j["widget_enabled"].is_null())								widget_enabled = j["widget_enabled"].get<bool>();
	if (j.count("widget_channel_id") && !j["widget_channel_id"].is_null())							widget_channel_id = stdstoulla(j["widget_channel_id"].get<std::string>());
	if (j.count("system_channel_id") && !j["system_channel_id"].is_null())							system_channel_id = stdstoulla(j["system_channel_id"].get<std::string>());
	if (j.count("system_channel_flags") && !j["system_channel_flags"].is_null())					system_channel_flags = j["system_channel_flags"].get<int64_t>();
	if (j.count("rules_channel_id") && !j["rules_channel_id"].is_null())							rules_channel_id = stdstoulla(j["rules_channel_id"].get<std::string>());
	if (j.count("joined_at") && !j["joined_at"].is_null())											joined_at.input(j["joined_at"]);
	if (j.count("large") && !j["large"].is_null())													large = j["large"].get<bool>();
	if (j.count("unavailable") && !j["unavailable"].is_null())										unavailable = j["unavailable"].get<bool>();
	if (j.count("member_count") && !j["member_count"].is_null())									member_count = j["member_count"].get<int64_t>();

	//std::vector<voice_state_c> voice_states;
	if (j.count("voice_states") && !j["voice_states"].is_null()) {
		for (const auto& _field : j["voice_states"])
			voice_states.emplace_back(std::move(voice_state_c().load(_field)));
	}

	//std::vector<member_c> members;
	if (j.count("members") && !j["members"].is_null()) {
		for (const auto& _field : j["members"])
			members.emplace_back(std::move(member_c().load(_field)));
	}

	//std::vector<channel_c> channels;
	if (j.count("channels") && !j["channels"].is_null()) {
		for (const auto& _field : j["channels"])
			channels.emplace_back(std::move(channel_c().load(_field)));
	}

	//std::vector<presence_c> presences;
	if (j.count("presences") && !j["presences"].is_null()) {
		for (const auto& _field : j["presences"])
			presences.emplace_back(std::move(presence_c().load(_field)));
	}

	if (j.count("max_presences") && !j["max_presences"].is_null())									max_presences = j["max_presences"].get<int64_t>();
	if (j.count("max_members") && !j["max_members"].is_null())										max_members = j["max_members"].get<int64_t>();
	if (j.count("vanity_url_code") && !j["vanity_url_code"].is_null())								vanity_url_code = j["vanity_url_code"].get<std::string>();
	if (j.count("description") && !j["description"].is_null())										description = j["description"].get<std::string>();
	if (j.count("banner") && !j["banner"].is_null())												banner = j["banner"].get<std::string>();
	if (j.count("premium_tier") && !j["premium_tier"].is_null())									premium_tier = j["premium_tier"].get<int64_t>();
	if (j.count("premium_subscription_count") && !j["premium_subscription_count"].is_null())		premium_subscription_count = j["premium_subscription_count"].get<int64_t>();
	if (j.count("preferred_locale") && !j["preferred_locale"].is_null())							preferred_locale = j["preferred_locale"].get<std::string>();
	if (j.count("public_updates_channel_id") && !j["public_updates_channel_id"].is_null())			public_updates_channel_id = stdstoulla(j["public_updates_channel_id"].get<std::string>());
	if (j.count("max_video_channel_users") && !j["max_video_channel_users"].is_null())				max_video_channel_users = j["max_video_channel_users"].get<int64_t>();

	return *this;
}

guild_ban_add_c& guild_ban_add_c::load(const nlohmann::json& j)
{
	if (j.count("guild_id") && !j["guild_id"].is_null())	guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("user") && !j["user"].is_null())			user.load(j["user"]);

	return *this;
}

guild_ban_remove_c& guild_ban_remove_c::load(const nlohmann::json& j)
{
	if (j.count("guild_id") && !j["guild_id"].is_null())	guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("user") && !j["user"].is_null())			user.load(j["user"]);

	return *this;
}

guild_emojis_update_c& guild_emojis_update_c::load(const nlohmann::json& j)
{
	if (j.count("guild_id") && !j["guild_id"].is_null())	guild_id = stdstoulla(j["guild_id"].get<std::string>());

	//std::vector<emoji_c> emojis;
	if (j.count("emojis") && !j["emojis"].is_null()) {
		for (const auto& _field : j["emojis"])
			emojis.emplace_back(std::move(emoji_c().load(_field)));
	}

	return *this;
}

guild_integrations_update_c& guild_integrations_update_c::load(const nlohmann::json& j)
{
	if (j.count("guild_id") && !j["guild_id"].is_null())	guild_id = stdstoulla(j["guild_id"].get<std::string>());

	return *this;
}

members_chunk_c& members_chunk_c::load(const nlohmann::json& j)
{
	if (j.count("guild_id") && !j["guild_id"].is_null())				guild_id = stdstoulla(j["guild_id"].get<std::string>());

	//std::vector<member_c> members;
	if (j.count("members") && !j["members"].is_null()) {
		for (const auto& _field : j["members"])
			members.emplace_back(std::move(member_c().load(_field)));
	}

	if (j.count("chunk_index") && !j["chunk_index"].is_null())			chunk_index = j["chunk_index"].get<int64_t>();
	if (j.count("chunk_count") && !j["chunk_count"].is_null())			chunk_count = j["chunk_count"].get<int64_t>();

	//std::vector<ULL> not_found;
	if (j.count("not_found") && !j["not_found"].is_null()) {
		for (const auto& _field : j["not_found"])
			not_found.push_back(stdstoulla(_field.get<std::string>())); // std::string
	}

	//std::vector<presence_c> presences;
	if (j.count("presences") && !j["presences"].is_null()) {
		for (const auto& _field : j["presences"])
			presences.emplace_back(std::move(presence_c().load(_field)));
	}

	if (j.count("nonce") && !j["nonce"].is_null())						nonce = j["nonce"].get<std::string>();
	
	return *this;
}


guild_role_event_c& guild_role_event_c::load(const nlohmann::json& j)
{
	if (j.count("guild_id") && !j["guild_id"].is_null())	guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("role") && !j["role"].is_null())			role.load(j["role"]);

	return *this;
}

invite_create_c& invite_create_c::load(const nlohmann::json& j)
{
	if (j.count("channel_id") && !j["channel_id"].is_null())				channel_id = stdstoulla(j["channel_id"].get<std::string>());
	if (j.count("code") && !j["code"].is_null())							code = j["code"].get<std::string>();
	if (j.count("created_at") && !j["created_at"].is_null())				created_at.input(j["created_at"].get<std::string>());
	if (j.count("guild_id") && !j["guild_id"].is_null())					guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("inviter") && !j["inviter"].is_null())						inviter.load(j["inviter"]);
	if (j.count("max_age") && !j["max_age"].is_null())						max_age = j["max_age"].get<int64_t>();
	if (j.count("max_uses") && !j["max_uses"].is_null())					max_uses = j["max_uses"].get<int64_t>();
	if (j.count("target_user") && !j["target_user"].is_null())				target_user.load(j["target_user"]);
	if (j.count("target_user_type") && !j["target_user_type"].is_null())	target_user_type = j["target_user_type"].get<int64_t>();
	if (j.count("temporary") && !j["temporary"].is_null())					temporary = j["temporary"].get<bool>();
	if (j.count("uses") && !j["uses"].is_null())							uses = j["uses"].get<int64_t>();

	return *this;
}

invite_delete_c& invite_delete_c::load(const nlohmann::json& j)
{
	if (j.count("channel_id") && !j["channel_id"].is_null())				channel_id = stdstoulla(j["channel_id"].get<std::string>());
	if (j.count("code") && !j["code"].is_null())							code = j["code"].get<std::string>();
	if (j.count("guild_id") && !j["guild_id"].is_null())					guild_id = stdstoulla(j["guild_id"].get<std::string>());

	return *this;
}

typing_start_c& typing_start_c::load(const nlohmann::json& j)
{
	if (j.count("channel_id") && !j["channel_id"].is_null())				channel_id = stdstoulla(j["channel_id"].get<std::string>());
	if (j.count("guild_id") && !j["guild_id"].is_null())					guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("user_id") && !j["user_id"].is_null())						user_id = stdstoulla(j["user_id"].get<std::string>());
	if (j.count("timestamp") && !j["timestamp"].is_null())					timestamp = j["timestamp"].get<int64_t>();
	if (j.count("member") && !j["member"].is_null())						member.load(j["member"]);

	return *this;
}

webhook_update_c& webhook_update_c::load(const nlohmann::json& j)
{
	if (j.count("guild_id") && !j["guild_id"].is_null())					guild_id = stdstoulla(j["guild_id"].get<std::string>());
	if (j.count("channel_id") && !j["channel_id"].is_null())				channel_id = stdstoulla(j["channel_id"].get<std::string>());

	return *this;
}



the_event& the_event::load_raw(const nlohmann::json& j, aegis::shards::shard* sh, std::shared_ptr<spdlog::logger> logg)
{
	try {
		shard = sh;
		if (j.count("t") && !j["t"].is_null()) {
			type_str = j["t"].get<std::string>();
#ifdef _DEBUG
			logg->set_level(spdlog::level::level_enum::debug);
			logg->debug("> Received event type: {}", type_str.get());
#endif

			if (type_str.get() == "TYPING_START") type = event_type::TYPING_START;
			else if (type_str.get() == "MESSAGE_CREATE") type = event_type::MESSAGE_CREATE;
			else if (type_str.get() == "MESSAGE_UPDATE") type = event_type::MESSAGE_UPDATE;
			else if (type_str.get() == "MESSAGE_DELETE") type = event_type::MESSAGE_DELETE;
			else if (type_str.get() == "GUILD_MEMBER_ADD") type = event_type::GUILD_MEMBER_ADD;
			else if (type_str.get() == "GUILD_MEMBER_REMOVE") type = event_type::GUILD_MEMBER_REMOVE;
			else if (type_str.get() == "GUILD_MEMBER_UPDATE") type = event_type::GUILD_MEMBER_UPDATE;
			else if (type_str.get() == "MESSAGE_REACTION_ADD") type = event_type::MESSAGE_REACTION_ADD;
			else if (type_str.get() == "MESSAGE_REACTION_REMOVE") type = event_type::MESSAGE_REACTION_REMOVE;
			else if (type_str.get() == "MESSAGE_REACTION_REMOVE_ALL") type = event_type::MESSAGE_REACTION_REMOVE_ALL;
			else if (type_str.get() == "MESSAGE_REACTION_REMOVE_EMOJI") type = event_type::MESSAGE_REACTION_REMOVE_EMOJI;
			else if (type_str.get() == "PRESENCE_UPDATE") type = event_type::PRESENCE_UPDATE;
			else if (type_str.get() == "USER_UPDATE") type = event_type::USER_UPDATE;
			else if (type_str.get() == "CHANNEL_CREATE") type = event_type::CHANNEL_CREATE;
			else if (type_str.get() == "CHANNEL_UPDATE") type = event_type::CHANNEL_UPDATE;
			else if (type_str.get() == "CHANNEL_DELETE") type = event_type::CHANNEL_DELETE;
			else if (type_str.get() == "GUILD_BAN_ADD") type = event_type::GUILD_BAN_ADD;
			else if (type_str.get() == "GUILD_BAN_REMOVE") type = event_type::GUILD_BAN_REMOVE;
			else if (type_str.get() == "GUILD_ROLE_CREATE") type = event_type::GUILD_ROLE_CREATE;
			else if (type_str.get() == "GUILD_ROLE_UPDATE") type = event_type::GUILD_ROLE_UPDATE;
			else if (type_str.get() == "GUILD_ROLE_DELETE") type = event_type::GUILD_ROLE_DELETE;
			else if (type_str.get() == "INVITE_CREATE") type = event_type::INVITE_CREATE;
			else if (type_str.get() == "INVITE_DELETE") type = event_type::INVITE_DELETE;
			else if (type_str.get() == "CHANNEL_PINS_UPDATE") type = event_type::CHANNEL_PINS_UPDATE;
			else if (type_str.get() == "GUILD_EMOJIS_UPDATE") type = event_type::GUILD_EMOJIS_UPDATE;
			else if (type_str.get() == "GUILD_INTEGRATIONS_UPDATE") type = event_type::GUILD_INTEGRATIONS_UPDATE;
			else if (type_str.get() == "MESSAGE_DELETE_BULK") type = event_type::MESSAGE_DELETE_BULK;
			else if (type_str.get() == "GUILD_MEMBERS_CHUNK") type = event_type::GUILD_MEMBERS_CHUNK;
			else if (type_str.get() == "GUILD_CREATE") type = event_type::GUILD_CREATE;
			else if (type_str.get() == "GUILD_UPDATE") type = event_type::GUILD_UPDATE;
			else if (type_str.get() == "GUILD_DELETE") type = event_type::GUILD_DELETE;
			else if (type_str.get() == "VOICE_STATE_UPDATE") type = event_type::VOICE_STATE_UPDATE;
			else if (type_str.get() == "VOICE_SERVER_UPDATE") type = event_type::VOICE_SERVER_UPDATE;
			else if (type_str.get() == "WEBHOOKS_UPDATE") type = event_type::WEBHOOKS_UPDATE;
			else if (type_str.get() == "READY") type = event_type::READY;
			else {
				if (logg) logg->warn("> Unknown event type {}", type_str.get());
				//return *this;
			}
			//if (logg) logg->debug("Tasked RAW:\n{}", j.dump(1));


			// each case is a case
			// see format: https://discord.com/developers/docs/topics/gateway#commands-and-events-gateway-events

			if (j.count("d") && !j["d"].is_null()) {
				//logg->info("[__IN] Full data:\n{}", j["d"].dump(1));
				original_data = j["d"];
				if (original_data.count("guild_id") && !original_data["guild_id"].is_null()) {
					guild_id = stdstoulla(original_data["guild_id"].get<std::string>());
				}
				if (!guild_id.is_set()) { // GUILD ones
					if (original_data.count("id") && !original_data["id"].is_null()) {
						guild_id = stdstoulla(original_data["id"].get<std::string>());
					}
				}

				switch (type) {
				case event_type::READY:
					bot.load(original_data["user"]);
					break;
				case event_type::MESSAGE_CREATE:
					data.message_create->load(original_data);
					break;
				case event_type::MESSAGE_UPDATE:
					data.message_update->load(original_data);
					break;
				case event_type::MESSAGE_DELETE:
					data.message_delete->load(original_data);
					break;
				case event_type::GUILD_MEMBER_ADD:
					data.guild_member_add->load(original_data);
					break;
				case event_type::GUILD_MEMBER_REMOVE:
					data.guild_member_remove->load(original_data);
					break;
				case event_type::GUILD_MEMBER_UPDATE:
					data.guild_member_update->load(original_data);
					break;
				case event_type::PRESENCE_UPDATE:
					data.presence_update->load(original_data);
					break;
				case event_type::TYPING_START:
					data.typing_start->load(original_data);
					break;
				case event_type::GUILD_CREATE:
					data.guild_create->load(original_data);
					break;
				case event_type::GUILD_UPDATE:
					data.guild_update->load(original_data);
					break;
				case event_type::GUILD_DELETE:
					data.guild_delete->load(original_data);
					break;
				case event_type::MESSAGE_REACTION_ADD:
					data.message_reaction_add->load(original_data);
					break;
				case event_type::MESSAGE_REACTION_REMOVE:
					data.message_reaction_remove->load(original_data);
					break;
				case event_type::MESSAGE_REACTION_REMOVE_ALL:
					data.message_reaction_remove_all->load(original_data);
					break;
				case event_type::MESSAGE_DELETE_BULK:
					data.message_delete_bulk->load(original_data);
					break;
				case event_type::USER_UPDATE:
					data.user_update->load(original_data);
					break;
				case event_type::INVITE_CREATE:
					data.invite_create->load(original_data);
					break;
				case event_type::INVITE_DELETE:
					data.invite_delete->load(original_data);
					break;
				case event_type::CHANNEL_CREATE:
					data.channel_create->load(original_data);
					break;
				case event_type::CHANNEL_UPDATE:
					data.channel_update->load(original_data);
					break;
				case event_type::CHANNEL_DELETE:
					data.channel_delete->load(original_data);
					break;
				case event_type::CHANNEL_PINS_UPDATE:
					data.channel_pins_update->load(original_data);
					break;
				case event_type::GUILD_BAN_ADD:
					data.guild_ban_add->load(original_data);
					break;
				case event_type::GUILD_BAN_REMOVE:
					data.guild_ban_remove->load(original_data);
					break;
				case event_type::GUILD_EMOJIS_UPDATE:
					data.guild_emojis_update->load(original_data);
					break;
				case event_type::GUILD_INTEGRATIONS_UPDATE:
					data.guild_integrations_update->load(original_data);
					break;
				case event_type::GUILD_MEMBERS_CHUNK:
					data.guild_members_chunk->load(original_data);
					break;
				case event_type::GUILD_ROLE_CREATE:
					data.guild_role_create->load(original_data);
					break;
				case event_type::GUILD_ROLE_UPDATE:
					data.guild_role_update->load(original_data);
					break;
				case event_type::GUILD_ROLE_DELETE:
					data.guild_role_delete->load(original_data);
					break;
				case event_type::VOICE_STATE_UPDATE:
					data.voice_state_update->load(original_data);
					break;
				case event_type::VOICE_SERVER_UPDATE:
					data.voice_server_update->load(original_data);
					break;
				case event_type::WEBHOOKS_UPDATE:
					data.webhook_update->load(original_data);
					break;
				}
			}
		}
	}
	catch (aegis::error e) {
		logg->critical("AEGIS error at load_raw: {}", e);
	}
	catch (nlohmann::detail::type_error e) {
		logg->critical("JSON error (type): {}", e.what());
	}
	catch (nlohmann::detail::invalid_iterator e) {
		logg->critical("JSON error (invalid iterator): {}", e.what());
	}
	catch (nlohmann::detail::parse_error e) {
		logg->critical("JSON error (parse): {}", e.what());
	}
	catch (nlohmann::detail::out_of_range e) {
		logg->critical("JSON error (out of range): {}", e.what());
	}
	catch (nlohmann::detail::other_error e) {
		logg->critical("JSON error (other): {}", e.what());
	}
	catch (nlohmann::detail::exception e) {
		logg->critical("JSON error (exception): {}", e.what());
	}
	catch (std::exception e) {
		logg->critical("STD error (exception default): {}", e.what());
	}
	catch (...) {
		logg->critical("UNKNOWN error.");
	}

	return *this;
}