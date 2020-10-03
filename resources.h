#pragma once

#include <aegis.hpp>
#include <codecvt>
#include <time.h>


/*
  BASED ON https://discord.com/developers/docs/intro stuff
*/

const auto timeout = std::chrono::seconds(20);

using ULL = unsigned long long;

const std::string url_assets = "https://cdn.discordapp.com/app-assets/"; // application_id/icon.png?size=size
//const std::string url_icon = "https://cdn.discordapp.com/app-icons/"; // application_id/asset_id.png?size=size

// event_type based on core.cpp L#605-637 of AEGIS 2.6.0

enum class event_type{UNKNOWN,
	READY,
	CHANNEL_CREATE,
	CHANNEL_UPDATE,
	CHANNEL_DELETE,
	CHANNEL_PINS_UPDATE,
	GUILD_CREATE,
	GUILD_UPDATE,
	GUILD_DELETE,
	GUILD_BAN_ADD,
	GUILD_BAN_REMOVE,
	GUILD_EMOJIS_UPDATE,
	GUILD_INTEGRATIONS_UPDATE,
	GUILD_MEMBER_ADD,
	GUILD_MEMBER_REMOVE,
	GUILD_MEMBER_UPDATE,
	GUILD_MEMBERS_CHUNK,
	GUILD_ROLE_CREATE,
	GUILD_ROLE_UPDATE,
	GUILD_ROLE_DELETE,
	INVITE_CREATE,
	INVITE_DELETE,
	MESSAGE_CREATE,
	MESSAGE_UPDATE,
	MESSAGE_DELETE,
	MESSAGE_DELETE_BULK,
	MESSAGE_REACTION_ADD,
	MESSAGE_REACTION_REMOVE,
	MESSAGE_REACTION_REMOVE_ALL,
	MESSAGE_REACTION_REMOVE_EMOJI,
	PRESENCE_UPDATE,
	TYPING_START,
	USER_UPDATE,
	VOICE_STATE_UPDATE,
	VOICE_SERVER_UPDATE,
	WEBHOOKS_UPDATE
};
enum class user_flags {
	Discord_Employee		= 1 << 0,
	Discord_Partner			= 1 << 1,
	HypeSquad_Events		= 1 << 2,
	Bug_Hunter_Level_1		= 1 << 3,
	House_Bravery			= 1 << 6,
	House_Brilliance		= 1 << 7,
	House_Balance			= 1 << 8,
	Early_Supporter			= 1 << 9,
	Team_User				= 1 << 10,
	System					= 1 << 12,
	Bug_Hunter_Level_2		= 1 << 14,
	Verified_Bot			= 1 << 16,
	Verified_Bot_Developer	= 1 << 17
};
enum class user_premium_type {
	Nitro_Classic			= 1,
	Nitro					= 2
};
enum class channel_type {
	GUILD_TEXT,
	DM,
	GUILD_VOICE,
	GROUP_DM,
	GUILD_CATEGORY,
	GUILD_NEWS,
	GUILD_STORE
};
enum class message_type {
	DEFAULT,
	RECIPIENT_ADD,
	RECIPIENT_REMOVE,
	CALL,
	CHANNEL_NAME_CHANGE,
	CHANNEL_ICON_CHANGE,
	CHANNEL_PINNED_MESSAGE,
	GUILD_MEMBER_JOIN,
	USER_PREMIUM_GUILD_SUBSCRIPTION,
	USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1,
	USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2,
	USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3,
	CHANNEL_FOLLOW_ADD,
	GUILD_DISCOVERY_DISQUALIFIED			= 14,
	GUILD_DISCOVERY_REQUALIFIED				= 15
};
enum class message_flags {
	DEFAULT,
	CROSSPOSTED				= 1 << 0, // this message has been published to subscribed channels (via Channel Following)
	IS_CROSSPOST			= 1 << 1, // this message originated from a message in another channel (via Channel Following)
	SUPPRESS_EMBEDS			= 1 << 2, // do not include any embeds when serializing this message
	SOURCE_MESSAGE_DELETED	= 1 << 3, // the source message for this crosspost has been deleted(via Channel Following)
	URGENT					= 1 << 4  // this message came from the urgent message system
};
enum class explicit_content_filter_level {
	DISABLED,
	MEMBERS_WITHOUT_ROLES,
	ALL_MEMBERS
};
enum class default_message_notification_level {
	ALL_MESSAGES,
	ONLY_MENTIONS
};
enum class verification_level {
	NONE,
	LOW,
	MEDIUM,
	HIGH,
	VERY_HIGH
};
enum class guild_features {
	INVITE_SPLASH,			// guild has access to set an invite splash background
	VIP_REGIONS,			// guild has access to set 384kbps bitrate in voice(previously VIP voice servers)
	VANITY_URL,				// guild has access to set a vanity URL
	VERIFIED,				// guild is verified
	PARTNERED,				// guild is partnered
	PUBLIC,					// guild is public
	COMMERCE,				// guild has access to use commerce features(i.e.create store channels)
	NEWS,					// guild has access to create news channels
	DISCOVERABLE,			// guild is able to be discovered in the directory
	FEATURABLE,				// guild is able to be featured in the directory
	ANIMATED_ICON,			// guild has access to set an animated guild icon
	BANNER,					// guild has access to set a guild banner image
	PUBLIC_DISABLED,		// guild cannot be public
	WELCOME_SCREEN_ENABLED	// guild has enabled the welcome screen
};
enum class mfa_level {
	NONE,
	ELEVATED
};
enum class system_channel_flags {
	SUPPRESS_JOIN_NOTIFICATIONS		= 1 << 0,	// Suppress member join notifications
	SUPPRESS_PREMIUM_SUBSCRIPTIONS	= 1 << 1	// Suppress server boost notifications
};
enum class activity_flags {
	INSTANCE		= 1 << 0,
	JOIN			= 1 << 1,
	SPECTATE		= 1 << 2,
	JOIN_REQUEST	= 1 << 3,
	SYNC			= 1 << 4,
	PLAY			= 1 << 5
};
enum class activity_types {
	Game = 0,		//Playing{ name }	"Playing Rocket League"
	Streaming = 1,	//Streaming{ details }	"Streaming Rocket League"
	Listening = 2,	//Listening to{ name }	"Listening to Spotify"
	Custom = 4		//{ emoji } {name}	":smiley: I am cool"
};
enum class permissions_user {
	CREATE_INSTANT_INVITE = 0x00000001,			// Allows creation of instant invites	T, V
	KICK_MEMBERS = 0x00000002,					// Allows kicking members
	BAN_MEMBERS = 0x00000004,					// Allows banning members
	ADMINISTRATOR = 0x00000008,					// Allows all permissions and bypasses channel permission overwrites
	MANAGE_CHANNELS = 0x00000010,				// Allows management and editing of channels	T, V
	MANAGE_GUILD = 0x00000020,					// Allows management and editing of the guild
	ADD_REACTIONS = 0x00000040,					// Allows for the addition of reactions to messages	T
	VIEW_AUDIT_LOG = 0x00000080,				// Allows for viewing of audit logs
	PRIORITY_SPEAKER = 0x00000100,				// Allows for using priority speaker in a voice channel	V
	STREAM = 0x00000200,						// Allows the user to go live	V
	VIEW_CHANNEL = 0x00000400,					// Allows guild members to view a channel, which includes reading messages in text channels	T, V
	SEND_MESSAGES = 0x00000800,					// Allows for sending messages in a channel	T
	SEND_TTS_MESSAGES = 0x00001000,				// Allows for sending of / tts messages	T
	MANAGE_MESSAGES = 0x00002000,				// Allows for deletion of other users messages	T
	EMBED_LINKS = 0x00004000,					// Links sent by users with this permission will be auto - embedded	T
	ATTACH_FILES = 0x00008000,					// Allows for uploading imagesand files	T
	READ_MESSAGE_HISTORY = 0x00010000,			// Allows for reading of message history	T
	MENTION_EVERYONE = 0x00020000,				// Allows for using the @everyone tag to notify all users in a channel, and the @here tag to notify all online users in a channel	T
	USE_EXTERNAL_EMOJIS = 0x00040000,			// Allows the usage of custom emojis from other servers	T
	VIEW_GUILD_INSIGHTS = 0x00080000,			// Allows for viewing guild insights
	CONNECT = 0x00100000,						// Allows for joining of a voice channel	V
	SPEAK = 0x00200000,							// Allows for speaking in a voice channel	V
	MUTE_MEMBERS = 0x00400000,					// Allows for muting members in a voice channel	V
	DEAFEN_MEMBERS = 0x00800000,				// Allows for deafening of members in a voice channel	V
	MOVE_MEMBERS = 0x01000000,					// Allows for moving of members between voice channels	V
	USE_VAD = 0x02000000,						// Allows for using voice - activity - detection in a voice channel	V
	CHANGE_NICKNAME = 0x04000000,				// Allows for modification of own nickname
	MANAGE_NICKNAMES = 0x08000000,				// Allows for modification of other users nicknames
	MANAGE_ROLES = 0x10000000,					// Allows management and editing of roles	T, V
	MANAGE_WEBHOOKS = 0x20000000,				// Allows management and editing of webhooks	T, V
	MANAGE_EMOJIS = 0x40000000					// Allows management and editing of emojis
};

bool operator==(const std::string, const guild_features&);
bool operator==(const int64_t&, const user_premium_type&);
bool operator&(const int64_t&, const user_flags&);
bool operator&(const int64_t&, const system_channel_flags&);
bool operator&(const int64_t&, const activity_flags&);
bool operator&(const int64_t&, const permissions_user&);

ULL stdstoulla(std::string);
int64_t stdstointa(std::string);

std::string narrow(const std::wstring&);
std::wstring widen(const std::string&);

std::string debug_permission(const int64_t);

template<typename T>
class safe_vector : protected std::vector<T> {
	mutable std::recursive_mutex m;
public:
	safe_vector() : std::vector<T>() {}
	safe_vector(safe_vector&& v) noexcept {
		std::lock_guard<std::recursive_mutex> l(m);
		*(std::vector<T>*)this = v.copy();
	}
	safe_vector(const safe_vector& v) {
		std::lock_guard<std::recursive_mutex> l(m);
		*(std::vector<T>*)this = v.copy();
	}
	void operator=(safe_vector&& v) {
		std::lock_guard<std::recursive_mutex> l(m);
		*(std::vector<T>*)this = v.copy();
	}
	void operator=(const safe_vector& v) {
		std::lock_guard<std::recursive_mutex> l(m);
		*(std::vector<T>*)this = v.copy();
	}
	template<class... _Valty>
	auto emplace_back(_Valty&&... _Val) {
		std::lock_guard<std::recursive_mutex> l(m);
		std::vector<T>::emplace_back(_Val...);
	}
	void push_back(const T& val) {
		std::lock_guard<std::recursive_mutex> l(m);
		std::vector<T>::push_back(val);
	}
	void push_back(T&& val) {
		std::lock_guard<std::recursive_mutex> l(m);
		std::vector<T>::push_back(val);
	}
	void erase(const size_t p) {
		std::lock_guard<std::recursive_mutex> l(m);
		std::vector<T>::erase(std::vector<T>::begin() + p);
	}
	void erase(const size_t s, const size_t e) {
		std::lock_guard<std::recursive_mutex> l(m);
		std::vector<T>::erase(std::vector<T>::begin() + s, std::vector<T>::begin() + e);
	}
	bool empty() const {
		std::lock_guard<std::recursive_mutex> l(m);
		return std::vector<T>::empty();
	}
	size_t size() const {
		std::lock_guard<std::recursive_mutex> l(m);
		return std::vector<T>::size();
	}
	T& operator[](const size_t p) {
		std::lock_guard<std::recursive_mutex> l(m);
		if (p > size()) return std::vector<T>::operator[](size() - 1);
		return std::vector<T>::operator[](p);
	}
	const T& operator[](const size_t p) const {
		std::lock_guard<std::recursive_mutex> l(m);
		if (p > size()) return std::vector<T>::operator[](size() - 1);
		return std::vector<T>::operator[](p);
	}
	T& front() {
		std::lock_guard<std::recursive_mutex> l(m);
		return std::vector<T>::front();
	}
	const T& front() const{
		std::lock_guard<std::recursive_mutex> l(m);
		return std::vector<T>::front();
	}
	T& back(){
		std::lock_guard<std::recursive_mutex> l(m);
		return std::vector<T>::back();
	}
	const T& back() const{
		std::lock_guard<std::recursive_mutex> l(m);
		return std::vector<T>::back();
	}

	void clear() {
		std::lock_guard<std::recursive_mutex> l(m);
		std::vector<T>::clear();
	}

	std::vector<T> copy() const {
		std::lock_guard<std::recursive_mutex> l(m);
		std::vector<T> thus = *this;
		return std::move(thus);
	}
	std::recursive_mutex& get_internal_lock() {
		return m;
	}
	// ONLY USE THIS IF YOU KNOW WHAT YOU'RE DOING!
	std::vector<T>& cast_back_nolock() const {
		return *((std::vector<T>*)this);
	}

};

template<typename T>
class varset {
	T var{};
	bool isset = false;
public:
	varset() = default;
	varset(const T& val) {
		var = val;
		isset = true;
	}
	varset(T&& val) {
		var = std::move(val);
		isset = true;
	}
	varset(const varset<T>& val) {
		var = val.get();
		isset = true;
	}
	varset(varset<T>&& val) noexcept {
		var = val.get();
		isset = true;
	}
	void operator=(const T& val) {
		var = val;
		isset = true;
	}
	void operator=(T&& val) {
		var = std::move(val);
		isset = true;
	}
	void operator=(const varset<T>& val) {
		if (!val.is_set()) return;
		var = val.get();
		isset = true;
	}
	void operator=(varset<T>&& val) noexcept {
		if (!val.is_set()) return;
		var = val.get();
		isset = true;
	}
	bool operator==(const T& val) const {
		return var == val;
	}
	bool operator==(const varset<T>& val) const {
		return var == val.get();
	}
	operator T() const {
		return var;
	}
	T& get_to_set() { // probably modified
		isset = true;
		return var;
	}
	T* get_ptr() {
		return &var;
	}
	const T& get() const { // can't modify
		return var;
	}
	bool is_set() const {
		return isset;
	}
	void reset() { // just set as unmodified
		isset = false;
	}
};

template<typename T>
class notsetyet {
	T* ptr = nullptr;
public:
	~notsetyet() {
		if (ptr) {
			delete ptr;
			ptr = nullptr;
		}
	}
	notsetyet() = default;

	notsetyet(const T& val) {
		if (!ptr) ptr = new T();
		*ptr = val;
	}
	notsetyet(T&& val) {
		if (!ptr) ptr = new T();
		*ptr = val;
	}
	void operator=(const T& val) {
		if (!ptr) ptr = new T();
		*ptr = val;
	}
	void operator=(T&& val) {
		if (!ptr) ptr = new T();
		*ptr = val;
	}
	bool is_set() const {
		return ptr;
	}
	T& operator*() {
		if (!ptr) ptr = new T();
		return *ptr;
	}
	T* operator->() {
		if (!ptr) ptr = new T();
		return ptr;
	}
	operator T() const {
		if (!ptr) ptr = new T();
		return *ptr;
	}
	operator T() {
		if (!ptr) ptr = new T();
		return *ptr;
	}
};


struct time_iso {// GMT0
	varset<unsigned> year;
	varset<unsigned> month;
	varset<unsigned> day;
	varset<unsigned> hour;
	varset<unsigned> minute;
	varset<float> second;
	varset<std::string> iso_format;

	bool operator==(const time_iso&);

	void input(const std::string); // format: 2020-09-23T18:15:46.827642+00:00
	void input_epoch_ms(const int64_t);
	void input_epoch_s(const int64_t);
	std::string nice_format() const;
};
struct overwrite_c {
	varset<ULL> id;					// role or user id
	varset<std::string> type;		// either role or member
	varset<int64_t> allow;				// legacy permission bit set
	varset<std::string> allow_new;	// permission bit set
	varset<int64_t> deny;				// legacy permission bit set
	varset<std::string> deny_new;	// permission bit set

	overwrite_c& load(const nlohmann::json&);
};
struct user_c {
	varset<ULL> id;
	varset<std::string> username;
	varset<std::string> discriminator;
	varset<std::string> avatar;
	varset<bool> bot;
	varset<bool> system;
	varset<bool> mfa_enabled;
	varset<std::string> locale;
	varset<bool> verified;
	varset<std::string> email;
	varset<ULL> flags;
	varset<int64_t> premium_type;
	varset<int64_t> public_flags;

	// tools

	bool is_public_discord_employee() const;
	bool is_public_discord_partner() const;
	bool is_public_hypesquad_events() const;
	bool is_public_bug_hunter_level_1() const;
	bool is_public_house_bravery() const;
	bool is_public_house_brilliance() const;
	bool is_public_house_balance() const;
	bool is_public_early_supporter() const;
	bool is_public_team_user() const;
	bool is_public_system() const;
	bool is_public_bug_hunter_level_2() const;
	bool is_public_verified_bot() const;
	bool is_public_verified_bot_developer() const;

	bool is_discord_employee() const;
	bool is_discord_partner() const;
	bool is_hypesquad_events() const;
	bool is_bug_hunter_level_1() const;
	bool is_house_bravery() const;
	bool is_house_brilliance() const;
	bool is_house_balance() const;
	bool is_early_supporter() const;
	bool is_team_user() const;
	bool is_system() const;
	bool is_bug_hunter_level_2() const;
	bool is_verified_bot() const;
	bool is_verified_bot_developer() const;

	bool is_webhook() const;

	// classic nitro
	bool is_nitro_classic() const;
	// full nitro
	bool is_nitro() const;

	std::string get_combo_name();

	user_c& load(const nlohmann::json&);
};
struct member_c {
	varset<ULL> guild_id; // set on member_add
	user_c user; // note: won't be attached to message_create and message_update events!
	varset<std::string> nick;
	safe_vector<ULL> roles;
	time_iso joined_at;
	time_iso premium_since;
	varset<bool> deaf;
	varset<bool> mute;

	bool has_role(const ULL);

	member_c& load(const nlohmann::json&);
};
struct channel_c {
	varset<ULL> id;				// id of the channel
	varset<int64_t> type;			// type of the channel (see channel_type)
	varset<ULL> guild_id;		// guild id
	varset<int64_t> position;		// sorting position of the channel
	safe_vector<overwrite_c> permission_overwrites;		// explicit permission overwrites for members and roles
	varset<std::string> name;		// name of the channel
	varset<std::string> topic;		// topic of the channel
	varset<bool> nsfw;		// whether the channel is nsfw
	varset<ULL> last_message_id;// last message sent in this channel (may not be valid)
	varset<int64_t> bitrate;		// bitrate (in bits) of voice channel
	varset<int64_t> user_limit;		// user limit of voice channel
	varset<int64_t> rate_limit_per_user; // channel message delay
	safe_vector<user_c> recipients; // users in DM
	varset<std::string> icon;		// icon hash
	varset<ULL> owner_id;		// ID of the owner of the DM group
	varset<ULL> application_id; // ID of the application if group DM was created by a bot
	varset<ULL> parent_id;		// ID of the category;
	varset<std::string> last_pin_timestamp; // last pinned message time;

	channel_c& load(const nlohmann::json&);
};
struct channel_pin_update_c {
	varset<ULL> guild_id;
	varset<ULL> channel_id;
	time_iso last_pin_timestamp;

	channel_pin_update_c& load(const nlohmann::json&);
};
struct channel_mention_c {
	varset<ULL> id;
	varset<ULL> guild_id;
	varset<int64_t> type; // see channel_type
	varset<std::string> name;

	channel_mention_c& load(const nlohmann::json&);
};
struct attachment_c {
	varset<ULL> id;
	varset<std::string> filename;
	varset<int64_t> size;
	varset<std::string> url;
	varset<std::string> proxy_url;
	varset<int64_t> height;
	varset<int64_t> width;

	attachment_c& load(const nlohmann::json&);
};
struct role_c {
	varset<ULL> id;
	varset<std::string> name;
	varset<int64_t> color;
	varset<bool> hoist;
	varset<int64_t> position;
	varset<int64_t> permissions;
	varset<std::string> permissions_new;
	varset<bool> managed;
	varset<bool> mentionable;

	role_c& load(const nlohmann::json&);
};
struct emoji_c {
	varset<ULL> id;
	varset<std::string> name;
	safe_vector<role_c> roles; // roles that can use this emoji
	user_c user; // user that created the emoji
	varset<bool> require_colons;
	varset<bool> managed; // managed by integration
	varset<bool> animated;
	varset<bool> available; // can be false if server boosts go down and the emoji was 50+

	bool operator==(const emoji_c&);
	std::string format();

	emoji_c& load(const nlohmann::json&);
};
struct reaction_c {
	varset<int64_t> count;
	varset<bool> me;
	emoji_c emoji;

	reaction_c& load(const nlohmann::json&);
};
struct message_activity_c {
	varset<int64_t> type;
	varset<std::string> party_id;

	message_activity_c& load(const nlohmann::json&);
};
struct message_application_c {
	varset<ULL> id;
	varset<std::string> cover_image;
	varset<std::string> description;
	varset<std::string> icon;
	varset<std::string> name;

	message_application_c& load(const nlohmann::json&);
};
struct message_reference_c {
	varset<ULL> message_id;
	varset<ULL> channel_id;
	varset<ULL> guild_id;

	message_reference_c& load(const nlohmann::json&);
};
struct message_c {
	varset<ULL> id;
	varset<ULL> channel_id;
	varset<ULL> guild_id;
	member_c member;
	user_c& author = member.user;
	varset<std::string> content;
	time_iso timestamp;
	time_iso edited_timestamp;
	varset<bool> tts;
	varset<bool> mention_everyone;
	safe_vector<user_c> mentions;
	safe_vector<std::string> mention_roles;
	safe_vector<channel_mention_c> mention_channels;
	safe_vector<attachment_c> attachments;
	safe_vector<nlohmann::json> embeds;
	safe_vector<reaction_c> reactions;
	varset<bool> pinned;
	varset<ULL> webhook_id;
	varset<int64_t> type; // see message_type
	message_activity_c activity; // sent with Rich Presence
	message_application_c application; // sent with Rich Presence
	message_reference_c message_reference; // reference data sent with crossposted messages
	varset<int64_t> flags; // see message_flags

	//message_c() = default;
	//message_c(aegis::core*);
	//message_c(const std::string&, aegis::core*);
	void operator=(const message_c&);

	operator bool() const;

	message_c& load(const nlohmann::json&);
};
struct message_delete_c {
	varset<ULL> id;
	varset<ULL> guild_id;
	varset<ULL> channel_id;

	message_delete_c& load(const nlohmann::json&);
};
struct message_delete_bulk_c {
	safe_vector<ULL> ids;
	varset<ULL> guild_id;
	varset<ULL> channel_id;

	message_delete_bulk_c& load(const nlohmann::json&);
};
struct message_reaction_add_c {
	varset<ULL> user_id;
	varset<ULL> channel_id;
	varset<ULL> message_id;
	varset<ULL> guild_id;
	member_c member;
	emoji_c emoji;

	message_reaction_add_c& load(const nlohmann::json&);
};
struct message_reaction_remove_c {
	varset<ULL> user_id;
	varset<ULL> channel_id;
	varset<ULL> message_id;
	varset<ULL> guild_id;
	emoji_c emoji;

	message_reaction_remove_c& load(const nlohmann::json&);
};
struct message_reaction_remove_all_c {
	varset<ULL> channel_id;
	varset<ULL> message_id;
	varset<ULL> guild_id;

	message_reaction_remove_all_c& load(const nlohmann::json&);
};
struct message_reaction_remove_emoji_c {
	varset<ULL> channel_id;
	varset<ULL> guild_id;
	varset<ULL> message_id;
	emoji_c emoji;

	message_reaction_remove_emoji_c& load(const nlohmann::json&);
};
struct voice_state_c {
	varset<ULL> guild_id;
	varset<ULL> channel_id;
	varset<ULL> user_id;
	member_c member;
	varset<std::string> session_id;
	varset<bool> deaf; // deafen by server
	varset<bool> mute; // mute by server
	varset<bool> self_deaf;
	varset<bool> self_mute;
	varset<bool> self_stream; // GO LIVE
	varset<bool> self_video; // camera
	varset<bool> suppress;

	voice_state_c& load(const nlohmann::json&);
};
struct voice_server_update_c {
	varset<std::string> token;
	varset<ULL> guild_id;
	varset<std::string> endpoint;

	voice_server_update_c& load(const nlohmann::json&);
};
struct activity_secrets_c {
	varset<std::string> join;
	varset<std::string> spectate;
	varset<std::string> match;

	bool operator==(const activity_secrets_c&);

	activity_secrets_c& load(const nlohmann::json&);
};
struct activity_assets_c {
	varset<std::string> large_image;
	varset<std::string> large_text;
	varset<std::string> small_image;
	varset<std::string> small_text;

	// app id, size
	std::string large_url(const int64_t, const size_t);
	// app id, size
	std::string small_url(const int64_t, const size_t);

	activity_assets_c& load(const nlohmann::json&);
};
struct activity_party_c {
	varset<std::string> id;
	safe_vector<int64_t> size; // two integers: current & max size

	activity_party_c& load(const nlohmann::json&);
};
struct activity_c {
	varset<std::string> name;
	varset<int64_t> type; // see activity_types
	varset<std::string> url;
	varset<int64_t> created_at; // unix timestamp
	time_iso timestamp; // start/end of the game
	varset<ULL> application_id;
	varset<std::string> details;
	varset<std::string> state;
	emoji_c emoji; // emoji for custom status
	activity_party_c party;
	activity_assets_c assets;
	activity_secrets_c secrets;
	varset<bool> instance; // activity is instanced game?
	varset<int64_t> flags; // activity flags
	bool _changed = true; // if this presence is different from previous presence (aka new?)

	// if previous presence is or is not equal to this. if different, true (new information)
	bool has_new_data();
	bool operator==(const activity_c&);
	bool similar(const activity_c&);

	activity_c& load(const nlohmann::json&);
};
struct client_status_c {
	varset<std::string> desktop; // "online", "idle", "dnd" or ""
	varset<std::string> mobile; // "online", "idle", "dnd" or ""
	varset<std::string> web; // "online", "idle", "dnd" or ""

	client_status_c& load(const nlohmann::json&);
};
struct presence_c {
	user_c user;
	safe_vector<ULL> roles;
	activity_c game; // right now, or null
	varset<ULL> guild_id;
	varset<std::string> status;
	safe_vector<activity_c> activities; // all activities
	client_status_c client_status; // online on what platforms
	time_iso premium_since; // boost since
	varset<std::string> nick;

	presence_c& load(const nlohmann::json&);
};
struct guild_c {
	varset<ULL> id;
	varset<std::string> name;
	varset<std::string> icon;
	varset<std::string> splash;
	varset<std::string> discovery_splash;
	varset<ULL> owner_id;
	varset<int64_t> permissions;
	varset<std::string> permissions_new;
	varset<std::string> region;
	varset<ULL> afk_channel;
	varset<int64_t> verification_level; // see verification_level
	varset<int64_t> default_message_notifications; // see default_message_notification_level
	varset<int64_t> explicit_content_filter; // see explicit_content_filter_level
	safe_vector<role_c> roles;
	safe_vector<emoji_c> emojis;
	safe_vector<std::string> features; // see guild_features, has operator==
	varset<int64_t> mfa_level; // see mfa_level
	varset<ULL> application_id; // id of the application/bot that created the guild, if it was created by one.
	varset<bool> widget_enabled;
	varset<ULL> widget_channel_id;
	varset<ULL> system_channel_id; // boosts and welcome system messages channel id
	varset<int64_t> system_channel_flags; // & the system_channel_flags
	varset<ULL> rules_channel_id; // if public, rules channel
	time_iso joined_at;
	varset<bool> large; // if guild is considered large
	varset<bool> unavailable; // outage
	varset<int64_t> member_count; // member_count
	safe_vector<voice_state_c> voice_states;
	safe_vector<member_c> members;
	safe_vector<channel_c> channels;
	safe_vector<presence_c> presences;
	varset<int64_t> max_presences;
	varset<int64_t> max_members;
	varset<std::string> vanity_url_code;
	varset<std::string> description;
	varset<std::string> banner;
	varset<int64_t> premium_tier; // boost tier level
	varset<int64_t> premium_subscription_count; // amount of boosts
	varset<std::string> preferred_locale;
	varset<ULL> public_updates_channel_id; // if public, chat where discord send notifications
	varset<int64_t> max_video_channel_users; // how many can watch a video in a vc at the same time

	guild_c& load(const nlohmann::json&);
};
struct guild_ban_add_c {
	varset<ULL> guild_id;
	user_c user;

	guild_ban_add_c& load(const nlohmann::json&);
};
struct guild_ban_remove_c {
	varset<ULL> guild_id;
	user_c user;

	guild_ban_remove_c& load(const nlohmann::json&);
};
struct guild_emojis_update_c {
	varset<ULL> guild_id;
	safe_vector<emoji_c> emojis;

	guild_emojis_update_c& load(const nlohmann::json&);
};
struct guild_integrations_update_c {
	varset<ULL> guild_id;

	guild_integrations_update_c& load(const nlohmann::json&);
};
struct members_chunk_c {
	varset<ULL> guild_id;
	safe_vector<member_c> members;
	varset<int64_t> chunk_index;
	varset<int64_t> chunk_count;
	safe_vector<ULL> not_found;
	safe_vector<presence_c> presences;
	varset<std::string> nonce;

	members_chunk_c& load(const nlohmann::json&);
};
struct guild_role_event_c {
	varset<ULL> guild_id;
	role_c role;

	guild_role_event_c& load(const nlohmann::json&);
};
struct invite_create_c {
	varset<ULL> channel_id;
	std::string code;
	time_iso created_at;
	varset<ULL> guild_id;
	user_c inviter;
	varset<int64_t> max_age;
	varset<int64_t> max_uses;
	user_c target_user; // partial
	varset<int64_t> target_user_type;
	varset<bool> temporary;
	varset<int64_t> uses;

	invite_create_c& load(const nlohmann::json&);
};
struct invite_delete_c {
	varset<ULL> channel_id;
	varset<std::string> code;
	varset<ULL> guild_id;

	invite_delete_c& load(const nlohmann::json&);
};
struct typing_start_c {
	varset<ULL> channel_id;
	varset<ULL> guild_id;
	varset<ULL> user_id;
	varset<int64_t> timestamp;
	member_c member;

	typing_start_c& load(const nlohmann::json&);
};
struct webhook_update_c {
	varset<ULL> guild_id;
	varset<ULL> channel_id;

	webhook_update_c& load(const nlohmann::json&);
};

struct the_event {
	event_type type = event_type::UNKNOWN;
	static user_c bot;

	struct data {
		notsetyet<channel_c> channel_create; // CHANNEL_CREATE
		notsetyet<channel_c> channel_update; // CHANNEL_UPDATE
		notsetyet<channel_c> channel_delete; // CHANNEL_DELETE
		notsetyet<channel_pin_update_c> channel_pins_update; // CHANNEL_PINS_UPDATE
		notsetyet<guild_c> guild_create; // GUILD_CREATE
		notsetyet<guild_c> guild_update; // GUILD_UPDATE
		notsetyet<guild_c> guild_delete; // (unavailable guild flag) GUILD_DELETE
		notsetyet<guild_ban_add_c> guild_ban_add; // GUILD_BAN_ADD
		notsetyet<guild_ban_remove_c> guild_ban_remove; // GUILD_BAN_REMOVE
		notsetyet<guild_emojis_update_c> guild_emojis_update; // GUILD_EMOJIS_UPDATE
		notsetyet<guild_integrations_update_c> guild_integrations_update; //GUILD_INTEGRATIONS_UPDATE
		notsetyet<member_c> guild_member_add; // GUILD_MEMBER_ADD
		notsetyet<member_c> guild_member_remove; // GUILD_MEMBER_REMOVE (has guild_id and user only)
		notsetyet<member_c> guild_member_update; // GUILD_MEMBER_UPDATE
		notsetyet<members_chunk_c> guild_members_chunk; // GUILD_MEMBERS_CHUNK
		notsetyet<guild_role_event_c> guild_role_create; // GUILD_ROLE_CREATE
		notsetyet<guild_role_event_c> guild_role_update; // GUILD_ROLE_UPDATE
		notsetyet<guild_role_event_c> guild_role_delete; // GUILD_ROLE_DELETE
		notsetyet<invite_create_c> invite_create; // INVITE_CREATE
		notsetyet<invite_delete_c> invite_delete; // INVITE_DELETE
		notsetyet<message_c> message_create; // MESSAGE_CREATE
		notsetyet<message_c> message_update; // MESSAGE_UPDATE
		notsetyet<message_delete_c> message_delete; // MESSAGE_DELETE
		notsetyet<message_delete_bulk_c> message_delete_bulk; // MESSAGE_DELETE_BULK
		notsetyet<message_reaction_add_c> message_reaction_add; // MESSAGE_REACTION_ADD
		notsetyet<message_reaction_remove_c> message_reaction_remove; // MESSAGE_REACTION_REMOVE
		notsetyet<message_reaction_remove_all_c> message_reaction_remove_all; // MESSAGE_REACTION_REMOVE_ALL
		notsetyet<message_reaction_remove_emoji_c> message_reaction_remove_emoji; // MESSAGE_REACTION_REMOVE_EMOJI
		notsetyet<presence_c> presence_update; // PRESENCE_UPDATE
		notsetyet<typing_start_c> typing_start; // TYPING_START
		notsetyet<user_c> user_update; // USER_UPDATE
		notsetyet<voice_state_c> voice_state_update; // VOICE_STATE_UPDATE
		notsetyet<voice_server_update_c> voice_server_update; // VOICE_SERVER_UPDATE
		notsetyet<webhook_update_c> webhook_update; // WEBHOOKS_UPDATE
	};

	data data;
	aegis::shards::shard* shard = nullptr;
	varset<ULL> guild_id;
	varset<std::string> type_str;
	nlohmann::json original_data;

	the_event() = default;
	the_event& load_raw(const nlohmann::json&, aegis::shards::shard*, std::shared_ptr<spdlog::logger>);
};
