#include "guild_control.h"


Language Guild::langs;


Language::Language()
{
	// load stuff
	{
		each en_us;
		en_us.names_alias.push_back("default");
		en_us.names_alias.push_back("english");
		en_us.names_alias.push_back("en_us");
		en_us.names_alias.push_back("en");
		

		en_us.lang["yes"]							= u8"yes"; //
		en_us.lang["no"]							= u8"no"; //

		en_us.lang["enabled"]						= u8"enabled"; //
		en_us.lang["disabled"]						= u8"disabled"; //

		en_us.lang["success"]						= u8"success"; //
		en_us.lang["list_success"]					= u8"updated list successfully";
		en_us.lang["failed"]						= u8"something went wrong"; //

		en_us.lang["del_arg"]						= u8"del"; //
		en_us.lang["add_arg"]						= u8"add"; //

		en_us.lang["flush"]							= u8"flush"; //
		en_us.lang["show"]							= u8"show"; //
		en_us.lang["log"]							= u8"log"; //
		en_us.lang["deeplog"]						= u8"deeplog"; //
		en_us.lang["megadeep"]						= u8"megadeep"; //
		en_us.lang["nolook"]						= u8"ignore"; //
		en_us.lang["admin"]							= u8"admin"; //
		en_us.lang["language"]						= u8"language"; //
		en_us.lang["ping"]							= u8"ping"; //
		en_us.lang["stats"]							= u8"stats"; //
		en_us.lang["alias"]							= u8"alias"; //
		en_us.lang["help"]							= u8"help";

		en_us.lang["commands"]						= u8"commands available"; //

		en_us.lang["flush_desc"]					= u8"flushes the memory (log buffer)"; //
		en_us.lang["show_desc"]						= u8"show all the settings"; //
		en_us.lang["log_desc"]						= u8"setup where to store log (require one or two ID(s))"; //
		en_us.lang["deeplog_desc"]					= u8"set if it should deeply log or not (normal)"; //
		en_us.lang["megadeep_desc"]					= u8"set if ANY EVENT should be logged or not (even presences and typing)"; //
		en_us.lang["nolook_desc"]					= u8"stop monitoring a chat. COMMAND DEL <...> = remove from list (require one or more IDs)"; //
		en_us.lang["admin_desc"]					= u8"adds new role to run commands. COMMAND DEL <...> = remove from list (require one or more IDs)"; //
		en_us.lang["help_desc"]						= u8"shows this help"; //
		en_us.lang["language_desc"]					= u8"set a language"; //
		en_us.lang["ping_desc"]						= u8"answers back without doing anything"; //
		en_us.lang["stats_desc"]					= u8"stats and info about the bot"; //
		en_us.lang["alias_desc"]					= u8"alternative way to call the bot (ex: ^)"; //

		en_us.lang["flushed"]						= u8"flushed memory"; // 
		en_us.lang["pong"]							= u8"pong"; //

		en_us.lang["config_title"]					= u8"settings"; //
		en_us.lang["log_title"]						= u8"log chat(s)"; //
		en_us.lang["alias_title"]					= u8"alias"; //
		en_us.lang["deeplog_title"]					= u8"deep logging"; //
		en_us.lang["megadeep_title"]				= u8"megadeep logging"; //
		en_us.lang["nolook_title"]					= u8"ignore channels"; //
		en_us.lang["adminroles_title"]				= u8"admin tags"; //

		en_us.lang["broadcast_title"]				= u8"[Official Message from Developer(s)]"; //

		en_us.lang["edited_message"] 				= u8"edit"; //
		en_us.lang["del"] 							= u8"deleted"; //
		en_us.lang["reacted_with"] 					= u8"reacted with"; //
		en_us.lang["removed_reaction"] 				= u8"removed reaction"; //

		en_us.lang["category_t"] 					= u8"CATEGORY"; //
		en_us.lang["channel_t"] 					= u8"CHANNEL"; //
		en_us.lang["voice_t"]						= u8"VOICECHAT"; //
		en_us.lang["message_t"] 					= u8"MESSAGE"; //
		en_us.lang["role_t"]						= u8"ROLE"; //

		en_us.lang["create_t"] 						= u8"CREATE"; //
		en_us.lang["update_t"] 						= u8"UPDATE"; //
		en_us.lang["delete_t"] 						= u8"DELETE"; //

		en_us.lang["banned_t"] 						= u8"BANNED"; //
		en_us.lang["unbanned_t"]					= u8"UNBANNED"; //

		en_us.lang["topic"] 						= u8"topic"; //
		en_us.lang["name"] 							= u8"name"; //
		en_us.lang["nsfw"] 							= u8"NSFW"; //
		en_us.lang["bitrate"] 						= u8"bitrate"; //
		en_us.lang["user_max"] 						= u8"max users"; //

		en_us.lang["role_info"]						= u8"role info"; //
		en_us.lang["role_color"]					= u8"color"; //
		en_us.lang["role_hoist"]					= u8"hoist"; //
		en_us.lang["role_managed"]					= u8"managed by integration"; //
		en_us.lang["role_mentionable"]				= u8"mentionable"; //


		en_us.lang["shutdown_message"] 				= u8"Sorry, WolfLogger got shutdown (probably update)";
		en_us.lang["wakeup_message"] 				= u8"WolfLogger is back online";
		en_us.lang["rejoin_message"] 				= u8"Discord restarted connection. WolfLogger is back online";

		en_us.lang["stats_github"]					= u8"github"; //
		en_us.lang["stats_discord"] 				= u8"discord"; //
		en_us.lang["stats_ram_normal"] 				= u8"memory usage"; //
		en_us.lang["stats_ram_peak"]				= u8"peak memory usage"; //

		en_us.lang["stats_title"]					= u8"stats"; //

		en_us.lang["stats_members"]					= u8"members"; //
		en_us.lang["stats_channnels"]				= u8"channels"; //
		en_us.lang["stats_uptime"]					= u8"uptime"; //
		en_us.lang["stats_guilds"]					= u8"guilds"; //
		en_us.lang["stats_events"]					= u8"events"; //
		en_us.lang["stats_buffer"]					= u8"buffer"; //
		en_us.lang["stats_region"]					= u8"language"; //
		en_us.lang["stats_version"]					= u8"version"; //

		en_us.lang["stats_footer"]					= u8"made in C++{} in a LSW fork of {}"; // has to have two {}!
		
		en_us.lang["voice_member_update"]			= u8"MEMBER UPDATE IN VOICECHAT";

		en_us.lang["new_member"]					= u8"NEW MEMBER";
		en_us.lang["update_member"]					= u8"UPDATE MEMBER";
		en_us.lang["update_user"]					= u8"UPDATE USER";
		en_us.lang["del_member"]					= u8"LEFT GUILD";

		en_us.lang["member_joined_at"]				= u8"joined At";
		en_us.lang["member_nick"]					= u8"nick";
		en_us.lang["member_realnick"]				= u8"real nick";
		en_us.lang["member_is_bot"]					= u8"bot";
		en_us.lang["member_verified"]				= u8"verified";
		en_us.lang["member_webhook"]				= u8"webhook";
		en_us.lang["member_mfa"]					= u8"MFA enabled";
		en_us.lang["member_flags"]					= u8"flags";
		en_us.lang["member_publicflags"]			= u8"public flags";
		en_us.lang["member_nitro"]					= u8"nitro level";
		en_us.lang["member_locale"]					= u8"from where";
		en_us.lang["member_deaf"]					= u8"deafen";
		en_us.lang["member_mute"]					= u8"muted";
		en_us.lang["member_deaf_self"]				= u8"deafen themself";
		en_us.lang["member_mute_self"]				= u8"muted themself";
		en_us.lang["member_tags"]					= u8"current roles";
		en_us.lang["member_stream"]					= u8"livestream";
		en_us.lang["member_video"]					= u8"webcam active";
		en_us.lang["typing_event"]					= u8"typing...";

		en_us.lang["member_has_no_tags"]			= u8"no roles";

		en_us.lang["integrations_update_t"]			= u8"INTEGRATION UPDATE";
		en_us.lang["emoji_list_update_t"]			= u8"EMOJI LIST UPDATE";
		en_us.lang["pinned_message_t"]				= u8"UPDATED PINNED";
		en_us.lang["new_invite_t"]					= u8"INVITE CREATED";
		en_us.lang["del_invite_t"]					= u8"INVITE DESTROYED";

		en_us.lang["invite_inviter"]				= u8"created by";
		en_us.lang["invite_max_age"]				= u8"lasts for";
		en_us.lang["invite_max_uses"]				= u8"max uses";
		en_us.lang["invite_temporary"]				= u8"temporary";
		en_us.lang["invite_code"]					= u8"code";

		en_us.lang["presence_generic_t"]			= u8"PRESENCE UPDATE";

		en_us.lang["spotify_music_t"]				= u8"MUSIC";
		en_us.lang["spotify_album_t"]				= u8"ALBUM";
		en_us.lang["gaming_playing_t"]				= u8"PLAYING";
		en_us.lang["gaming_info_t"]					= u8"INFO";


		langs.emplace_back(std::move(en_us));
	}
	{
		each pt_br;
		pt_br.names_alias.push_back(u8"português");
		pt_br.names_alias.push_back("portuguese");
		pt_br.names_alias.push_back("portugues");
		pt_br.names_alias.push_back("brazil");
		pt_br.names_alias.push_back("brasil");
		pt_br.names_alias.push_back("pt_br");
		pt_br.names_alias.push_back("pt");
		

		pt_br.lang["yes"]							= u8"sim"; //
		pt_br.lang["no"]							= u8"não"; //

		pt_br.lang["enabled"]						= u8"habilitado"; //
		pt_br.lang["disabled"]						= u8"desabilitado"; //

		pt_br.lang["success"]						= u8"sucesso"; //
		pt_br.lang["list_success"]					= u8"atualizou lista com sucesso";
		pt_br.lang["failed"]						= u8"algo deu errado"; //

		pt_br.lang["del_arg"]						= u8"del"; //
		pt_br.lang["add_arg"]						= u8"add"; //

		pt_br.lang["flush"]							= u8"flush"; //
		pt_br.lang["show"]							= u8"mostrar"; //
		pt_br.lang["log"]							= u8"registro"; //
		pt_br.lang["deeplog"]						= u8"registrarprofundamente"; //
		pt_br.lang["megadeep"]						= u8"megaprofundo"; //
		pt_br.lang["nolook"]						= u8"ignorar"; //
		pt_br.lang["admin"]							= u8"admin"; //
		pt_br.lang["language"]						= u8"idioma"; //
		pt_br.lang["ping"]							= u8"ping"; //
		pt_br.lang["stats"]							= u8"estado"; //
		pt_br.lang["alias"]							= u8"apelido"; //
		pt_br.lang["help"]							= u8"ajuda";

		pt_br.lang["commands"]						= u8"comandos disponíveis"; //

		pt_br.lang["flush_desc"]					= u8"libera a memória"; //
		pt_br.lang["show_desc"]						= u8"mostra todas as configurações"; //
		pt_br.lang["log_desc"]						= u8"define onde salvar o log (precisa de um ou dois ID(s))"; //
		pt_br.lang["deeplog_desc"]					= u8"define se deve salvar tudo ou só o básico (normal)"; //
		pt_br.lang["megadeep_desc"]					= u8"define se deve salvar QUALQUER EVENTO (até mesmo presence e escrevendo)"; //
		pt_br.lang["nolook_desc"]					= u8"para de monitorar um chat. COMANDO DEL <...> = remove da list (precisa de um ou mais IDs)"; //
		pt_br.lang["admin_desc"]					= u8"adiciona uma tag como admin. COMANDO DEL <...> = remove da list (precisa de um ou mais IDs)"; //
		pt_br.lang["help_desc"]						= u8"mostra essa ajuda"; //
		pt_br.lang["language_desc"]					= u8"define um idioma"; //
		pt_br.lang["ping_desc"]						= u8"responde de volta sem fazer nada"; //
		pt_br.lang["stats_desc"]					= u8"estado e informações do bot"; //
		pt_br.lang["alias_desc"]					= u8"outra forma pra chamar o bot (ex: ^)"; //

		pt_br.lang["flushed"]						= u8"liberou a memória"; // 
		pt_br.lang["pong"]							= u8"pong"; //

		pt_br.lang["config_title"]					= u8"configurações"; //
		pt_br.lang["log_title"]						= u8"chat(s) de registro"; //
		pt_br.lang["alias_title"]					= u8"apelido"; //
		pt_br.lang["deeplog_title"]					= u8"registrando profundamente"; //
		pt_br.lang["megadeep_title"]				= u8"Mega profundo"; //
		pt_br.lang["nolook_title"]					= u8"canais ignorados"; //
		pt_br.lang["adminroles_title"]				= u8"tags de admin"; //

		pt_br.lang["broadcast_title"]				= u8"[Mensagem Oficial do(s) Desenvolvedor(es)]"; //

		pt_br.lang["edited_message"] 				= u8"editou"; //
		pt_br.lang["del"] 							= u8"apagou"; //
		pt_br.lang["reacted_with"] 					= u8"reagiu com"; //
		pt_br.lang["removed_reaction"] 				= u8"removeu reação"; //

		pt_br.lang["category_t"] 					= u8"CATEGORIA"; //
		pt_br.lang["channel_t"] 					= u8"CANAL"; //
		pt_br.lang["voice_t"]						= u8"VOZ"; //
		pt_br.lang["message_t"] 					= u8"MENSAGEM"; //
		pt_br.lang["role_t"]						= u8"TAG"; //

		pt_br.lang["create_t"] 						= u8"CRIADO"; //
		pt_br.lang["update_t"] 						= u8"ATUALIZADO"; //
		pt_br.lang["delete_t"] 						= u8"APAGADO"; //

		pt_br.lang["banned_t"] 						= u8"BANIU"; //
		pt_br.lang["unbanned_t"]					= u8"DESBANIU"; //

		pt_br.lang["topic"] 						= u8"tópico"; //
		pt_br.lang["name"] 							= u8"nome"; //
		pt_br.lang["nsfw"] 							= u8"NSFW"; //
		pt_br.lang["bitrate"] 						= u8"bitrate"; //
		pt_br.lang["user_max"] 						= u8"máx de usuários"; //

		pt_br.lang["role_info"]						= u8"informações"; //
		pt_br.lang["role_color"]					= u8"cor"; //
		pt_br.lang["role_hoist"]					= u8"no topo"; //
		pt_br.lang["role_managed"]					= u8"vinculado a uma integração"; //
		pt_br.lang["role_mentionable"]				= u8"mencionável"; //


		pt_br.lang["shutdown_message"] 				= u8"Desculpe, WolfLogger desligou (possivelmente uma update)";
		pt_br.lang["wakeup_message"] 				= u8"WolfLogger está de volta online";
		pt_br.lang["rejoin_message"] 				= u8"Discord reiniciou a conexão. WolfLogger está de volta online";

		pt_br.lang["stats_github"]					= u8"github"; //
		pt_br.lang["stats_discord"] 				= u8"discord"; //
		pt_br.lang["stats_ram_normal"] 				= u8"uso de memória"; //
		pt_br.lang["stats_ram_peak"]				= u8"uso máximo de memória"; //

		pt_br.lang["stats_title"]					= u8"estado"; //

		pt_br.lang["stats_members"]					= u8"membros"; //
		pt_br.lang["stats_channnels"]				= u8"canais"; //
		pt_br.lang["stats_uptime"]					= u8"ligado há"; //
		pt_br.lang["stats_guilds"]					= u8"guildas"; //
		pt_br.lang["stats_events"]					= u8"eventos"; //
		pt_br.lang["stats_buffer"]					= u8"buffer"; //
		pt_br.lang["stats_region"]					= u8"idioma"; //
		pt_br.lang["stats_version"]					= u8"versão"; //

		pt_br.lang["stats_footer"]					= u8"feito em C++{} numa fork do LSW de {}"; // has to have two {}!

		pt_br.lang["voice_member_update"]			= u8"UPDATE MEMBRO EM VOICECHAT";

		pt_br.lang["new_member"]					= u8"NOVO MEMBRO";
		pt_br.lang["update_member"]					= u8"UPDATE MEMBRO";
		pt_br.lang["update_user"]					= u8"UPDATE USUÁRIO";
		pt_br.lang["del_member"]					= u8"SAIU DA GUILD";

		pt_br.lang["member_joined_at"]				= u8"entrou";
		pt_br.lang["member_nick"]					= u8"nick";
		pt_br.lang["member_realnick"]				= u8"nick verdadeiro";
		pt_br.lang["member_is_bot"]					= u8"bot";
		pt_br.lang["member_verified"]				= u8"verificado";
		pt_br.lang["member_webhook"]				= u8"webhook";
		pt_br.lang["member_mfa"]					= u8"MFA habilitado";
		pt_br.lang["member_flags"]					= u8"flags";
		pt_br.lang["member_publicflags"]			= u8"flags públicas";
		pt_br.lang["member_nitro"]					= u8"nível do nitro";
		pt_br.lang["member_locale"]					= u8"de onde";
		pt_br.lang["member_deaf"]					= u8"surdo";
		pt_br.lang["member_mute"]					= u8"silenciado";
		pt_br.lang["member_deaf_self"]				= u8"ensurdeceu si mesmo";
		pt_br.lang["member_mute_self"]				= u8"silenciou si mesmo";
		pt_br.lang["member_tags"]					= u8"roles atuais";
		pt_br.lang["member_stream"]					= u8"ao vivo";
		pt_br.lang["member_video"]					= u8"webcam ativa";

		pt_br.lang["typing_event"]					= u8"escrevendo...";

		pt_br.lang["member_has_no_tags"]			= u8"sem roles";

		pt_br.lang["integrations_update_t"]			= u8"UPDATE NAS INTEGRAÇÕES";
		pt_br.lang["emoji_list_update_t"]			= u8"EMOJIS ATUALIZADOS";
		pt_br.lang["pinned_message_t"]				= u8"ALTERAÇÕES NOS FIXADOS";
		pt_br.lang["new_invite_t"]					= u8"CONVITE CRIADO";
		pt_br.lang["del_invite_t"]					= u8"CONVITE DESTRUÍDO";

		pt_br.lang["invite_inviter"]				= u8"criado por";
		pt_br.lang["invite_max_age"]				= u8"dura";
		pt_br.lang["invite_max_uses"]				= u8"máximo número de usos";
		pt_br.lang["invite_temporary"]				= u8"temporário";
		pt_br.lang["invite_code"]					= u8"código";
		
		pt_br.lang["presence_generic_t"]			= u8"UPDATE NA PRESENÇA";

		pt_br.lang["spotify_music_t"]				= u8"MÚSICA";
		pt_br.lang["spotify_album_t"]				= u8"ÁLBUM";
		pt_br.lang["gaming_playing_t"]				= u8"JOGANDO";
		pt_br.lang["gaming_info_t"]					= u8"INFO";

		langs.emplace_back(std::move(pt_br));
	}

}

nlohmann::json Language::get_lang(std::string str) const
{
	for (auto& k : str) k = std::tolower(k);

	for (auto& i : langs) {
		for (auto& j : i.names_alias) {
			if (j == str) return i.lang;
		}
	}

	if (str == "default") throw std::exception("Fatal error trying to get default language.");
	return get_lang("default");
}



std::string transform_weirdo(const std::string in)
{
	std::string out;
	for (auto& i : in) {
		char temp[5];
		sprintf_s(temp, "%c%X", '%', (unsigned char)(i + sizeof(char) / 2));
		out += temp;
	}
	return out;
}

std::string format_emoji(aegis::gateway::objects::emoji e) {
	return e.id ? fmt::format("<{}:{}:{}>", e.animated ? "a" : "", e.name, e.id) : e.name;
}
/*std::string format_emoji(emoji_c e) {
	return e.id.get() ? fmt::format("<{}:{}:{}>", e.animated.get() ? "a" : "", e.name.get(), e.id.get()) : e.name.get();
}*/



bool each_block::same_user(const each_block& c)
{
	return user_id == c.user_id;
}

std::string each_block::generate_title()
{
	return title;
}

std::string each_block::generate()
{
	return subtitle + content;
}

std::string each_block::generate_prefix()
{
	return subtitle;
}

std::string each_block::generate_end()
{
	return content;
}


void guild_data::load_config(nlohmann::json j)
{
	if (j.count("channel_log") && !j["channel_log"].is_null()) {
		channel_log = j["channel_log"].get<unsigned long long>();
	}
	if (j.count("channel_alt_log") && !j["channel_alt_log"].is_null()) {
		channel_alt_log = j["channel_alt_log"].get<unsigned long long>();
	}
	if (j.count("deep_data") && !j["deep_data"].is_null()) {
		deep_data = j["deep_data"].get<bool>();
	}
	if (j.count("mega_deep") && !j["mega_deep"].is_null()) {
		mega_deep = j["mega_deep"].get<bool>();
	}
	if (j.count("region") && !j["region"].is_null()) {
		region = j["region"].get<std::string>();
	}
	if (j.count("alias_cmd") && !j["alias_cmd"].is_null()) {
		alias_cmd = j["alias_cmd"].get<std::string>();
	}

	if (j.count("adm_tags") && !j["adm_tags"].is_null()) {
		for (auto& i : j["adm_tags"])
			adm_tags.push_back(i.get<unsigned long long>());
	}
	if (j.count("ignore_channels") && !j["ignore_channels"].is_null()) {
		for (auto& i : j["ignore_channels"])
			ignore_channels.push_back(i.get<unsigned long long>());
	}
}

nlohmann::json guild_data::export_config()
{
	nlohmann::json j;

	j["channel_alt_log"] = channel_alt_log;
	j["channel_log"] = channel_log;
	j["deep_data"] = deep_data;
	j["mega_deep"] = mega_deep;
	j["region"] = region;
	j["alias_cmd"] = alias_cmd;

	for (const auto& _field : adm_tags)
		j["adm_tags"].push_back(_field);
	for (const auto& _field : ignore_channels)
		j["ignore_channels"].push_back(_field);

	return j;
}


bool Guild::trycatch_auto(std::function<void(void)> f)
{
	try {
		if (f) f();
		return true;
	}
	catch (aegis::error e) {
		logg->critical("Guild #{} Guild::trycatch_auto: failed aegis. Got error: {}", here.get_raw_guild().id.get(), e);
	}
	catch (nlohmann::detail::type_error e) {
		logg->error("Guild #{} Guild::trycatch_auto: JSON failed: TYPE ERROR: {}", here.get_raw_guild().id.get(), e.what());
	}
	catch (nlohmann::detail::invalid_iterator e) {
		logg->error("Guild #{} Guild::trycatch_auto: JSON failed: INVALID ITERATOR ERROR: {}", here.get_raw_guild().id.get(), e.what());
	}
	catch (nlohmann::detail::parse_error e) {
		logg->error("Guild #{} Guild::trycatch_auto: JSON failed: PARSE ERROR: {}", here.get_raw_guild().id.get(), e.what());
	}
	catch (nlohmann::detail::out_of_range e) {
		logg->error("Guild #{} Guild::trycatch_auto: JSON failed: OUT OF RANGE ERROR: {}", here.get_raw_guild().id.get(), e.what());
	}
	catch (nlohmann::detail::other_error e) {
		logg->error("Guild #{} Guild::trycatch_auto: JSON failed: OTHER ERROR: {}", here.get_raw_guild().id.get(), e.what());
	}
	catch (nlohmann::detail::exception e) {
		logg->error("Guild #{} Guild::trycatch_auto: JSON failed: GENERIC EXCEPTION ERROR: {}", here.get_raw_guild().id.get(), e.what());
	}
	catch (std::exception e) {
		logg->critical("Guild #{} Guild::trycatch_auto: failed exception. Got error: {}", here.get_raw_guild().id.get(), e.what());
	}
	catch (...) {
		logg->critical("Guild #{} Guild::trycatch_auto: failed. Unknown error.", here.get_raw_guild().id.get());
	}
	return false;
}

void Guild::load_config()
{
	std::string pathh = "servers/" + std::to_string(here.get_raw_guild().id.get()) + "_log.wolflogv2";

	FILE* fp = nullptr;
	if (fopen_s(&fp, pathh.c_str(), "rb") == 0) {

		std::string all_buf;

		char quickbuf[256];
		size_t u = 0;

		while (u = fread_s(quickbuf, 256, sizeof(char), 256, fp)) {
			for (size_t k = 0; k < u; k++) all_buf += quickbuf[k];
		}

		auto j = nlohmann::json::parse(all_buf);
		data.load_config(j);

		logg->info("Guild #{} loaded config successfully.", here.get_raw_guild().id.get());

		fclose(fp);
	}
	else {
		logg->info("Guild #{} couldn't find the config file (new?).", here.get_raw_guild().id.get());
	}
}

void Guild::save_config()
{
	std::string pathh = "servers/" + std::to_string(here.get_raw_guild().id.get()) + "_log.wolflogv2";

	FILE* fp = nullptr;
	if (fopen_s(&fp, pathh.c_str(), "wb") == 0) {

		auto j = data.export_config();

		auto cpy = j.dump();
		fwrite(cpy.c_str(), sizeof(char), cpy.length(), fp);

		fclose(fp);
	}
}

void Guild::refresh_language(const std::string str)
{
	try {
		lng = langs.get_lang(str);
		data.region = str;
	}
	catch (...) {
		logg->error("Guild #{} failed to get language (exception)!", here.get_raw_guild().id.get());
	}
}

std::string Guild::local(const std::string key, const bool first_up)
{
	if (lng.count(key) && !lng[key].is_null()) {
		auto cpy = lng[key].get<std::string>();

		if (cpy.length() > 0 && first_up) cpy[0] = std::toupper(cpy[0]);
		return std::move(cpy);
	}
	else {
		refresh_language(data.region);
		if (lng.count(key) && !lng[key].is_null()) {
			auto cpy = lng[key].get<std::string>();

			if (cpy.length() > 0 && first_up) cpy[0] = std::toupper(cpy[0]);
			return std::move(cpy);
		}
		else {
			logg->critical("Guild #{} CRITICAL ERROR: CANNOT GET LANGUAGE!", here.get_raw_guild().id.get());
			return "ERRR";
		}
	}
}

bool Guild::_force_flush_buffer_custom(std::string& buff, const unsigned long long chid)
{
	if (!chid) return false;
	std::lock_guard<std::recursive_mutex> luck(buf_control);
	if (buff.empty()) {
		return true;
	}
	if (here.create_message(chid, buff)) {
		logg->info("Guild #{} flushed {} byte(s)", here.get_raw_guild().id.get(), buff.size());
		buff.clear();
		return true;
	}
	return false;
}

void Guild::_flush_block(each_block& i, std::string& buff, const unsigned long long chid)
{//channel_log
	std::lock_guard<std::recursive_mutex> luck(buf_control);
	if (last_user != i.user_id || !i.user_id) {
		auto title_gen = i.generate_title();
		if (buff.length() + title_gen.length() > max_len) {
			if (!_force_flush_buffer_custom(buff, chid)) {
				logg->critical("Guild #{} FAILED TO SEND BUFFER! ABORT MESSAGE!", here.get_raw_guild().id.get());
				return;
			}
		}
		buff += title_gen;
		last_user = i.user_id;
	}

	auto content_gen = i.generate();

	if (buff.length() + content_gen.length() > max_len) {
		if (!_force_flush_buffer_custom(buff, chid)) {
			logg->critical("Guild #{} FAILED TO SEND BUFFER! ABORT MESSAGE!", here.get_raw_guild().id.get());
			return;
		}
	}
	buff += content_gen;

	if (i.has_emd) { // has to flush latest so embed can be sent
		if (!_force_flush_buffer_custom(buff, chid)) {
			logg->critical("Guild #{} FAILED TO SEND BUFFER! ABORT MESSAGE!", here.get_raw_guild().id.get());
			return;
		}

		if (here.bot_has_perm(chid, permissions_user::EMBED_LINKS)) {
			//if (!slow_flush_embed(i.emb, *flush_channel, guild_id, logg)) {
			if (!here.create_message_embed(chid, i.emb)) {
				logg->critical("Guild #{} FAILED TO SEND EMBED BUFFER! ABORT MESSAGE!", here.get_raw_guild().id.get());
				return;
			}
			else logg->info("Guild #{} flushed one embed.", here.get_raw_guild().id.get());
		}
		else {
			nlohmann::json j = i.emb;
			std::string emb_str = u8"Can't send embed. Please allow links. The embed JSON is:\n" + j.dump(2);
			emb_str = emb_str.substr(0, max_len);
			//logg->info("Guild #{} flushed {} byte(s)", here.get_raw_guild().id.get(), emb_str.size());
			//if (!_flush_custom(emb_str)) {
			if (!here.create_message(chid, emb_str)) {
				logg->critical("Guild #{} FAILED TO SEND BUFFER! ABORT MESSAGE!", here.get_raw_guild().id.get());
				return;
			}
		}
	}
}

void Guild::flush_one_block(each_block& i)
{
	_flush_block(i, buf, data.channel_log);
}

void Guild::flush_one_alt_block(each_block& i)
{
	_flush_block(i, altbuf, data.channel_alt_log ? data.channel_alt_log : data.channel_log); // if not set, use default
}

std::string Guild::_fix_content(const std::string& str)
{
	std::string cpy;
	for (auto& i : str) {
		if (i == '`' || i == '@') cpy += '\\';
		cpy += i;
	}
	std::smatch m;
	std::string wrk;
	while (std::regex_search(cpy, m, regex_link)) {
		wrk += cpy.substr(0, m.position(0)) + "<" + m[0].str() + ">";
		cpy = (cpy.length() > (m[0].str().length() + m.position(0)) ? (cpy.substr(m[0].str().length() + m.position(0))) : "");
	}
	if (!cpy.empty()) wrk += cpy;

	return std::move(wrk);
}

bool Guild::is_chat_valid(const unsigned long long id)
{
	if (!id) return false;
	if (id == data.channel_log) return false;

	// # / # / # / # / # / # / # / # / # / # / # / # / # \ # \ # \ # \ # \ # \ # \ # \ # # \ # \ # \ # //
	// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
	AutoLock luckynus(vectors_on);

	for (auto& i : data.ignore_channels) {
		if (i == id) {
			return false;
		}
	}
	return true;
	// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
	// # \ # \ # \ # \ # \ # \ # \ # \ # # \ # \ # \ # - # / # / # / # / # / # / # / # / # / # / # / # //
}

bool Guild::is_user_admin(const unsigned long long id)
{
	if (!id) return false;
	//if (!thus) return false;

	if (id == here.get_raw_guild().owner_id.get() || id == mee_dev) return true;
	member_c usr = here.get_member(id);

	// # / # / # / # / # / # / # / # / # / # / # / # / # \ # \ # \ # \ # \ # \ # \ # \ # # \ # \ # \ # //
	// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
	AutoLock luckynus(vectors_on);

	for (auto& j : data.adm_tags) {
		for (size_t p = 0; p < usr.roles.size(); p++) {
			if (usr.roles[p] == j) return true;
		}
	}
	return false;
	// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
	// # \ # \ # \ # \ # \ # \ # \ # \ # # \ # \ # \ # - # / # / # / # / # / # / # / # / # / # / # / # //
}

void Guild::send_message_default(const unsigned long long chid, std::string content, bool succeed, std::string custom_title, int color)
{
	//channel_c chh = here.get_channel(chid);

	if (here.bot_has_perm(chid, permissions_user::EMBED_LINKS)) {
		nlohmann::json embed = {
			{ "title",  custom_title.empty() ? (succeed ? local("success", true) : local("failed", true)) : custom_title },
			{ "description", content.substr(0, 2048) },
			{ "color", color }
		};
		here.create_message_embed(chid, embed);
	}
	else {
		here.create_message(chid, ("```css\n[ " + (custom_title.empty() ? (succeed ? local("success", true) : local("failed", true)) : custom_title) + " ]```" + content));
	}
}

void Guild::command(std::vector<std::string> args, const unsigned long long ch)
{
	//std::function<void(void)> at_the_end;

	bool do_help = args.size() == 0;

	if (args.size() > 0) {
		auto& cmd = args[0];
		for (auto& i : cmd) i = std::tolower(i);

		// - > - > - > - > - > - > - > FLUSH < - < - < - < - < - < - < - //
		if (cmd == local("flush")) {

			core->async([&] {force_flush_buffer(); });// .then([&] { logg->info("[ASYNC] Guild #{} tasked flush (forced)", guild_id); });

			send_message_default(ch, local("flushed", true), true);
		}

		// - > - > - > - > - > - > - > SHOW < - < - < - < - < - < - < - //
		else if (cmd == local("show")) {

			std::string combo;

			combo +=
				local("config_title", true) + ":\n" +
				local("log_title", true) + ": <#" + std::to_string(data.channel_log) + ">" + (data.channel_alt_log ? (" & <#" + std::to_string(data.channel_alt_log) + ">") : std::string("")) + "\n" +
				local("alias_title", true) + ": " + data.alias_cmd + "\n" +
				local("deeplog_title", true) + ": " + std::string(data.deep_data ? local("yes") : local("no")) + "\n" +
				local("megadeep_title", true) + ": " + std::string(data.mega_deep ? local("yes") : local("no"));

			if (data.ignore_channels.size() > 0) {

				if (combo.length() > 1536) {
					send_message_default(ch, combo, true);
					combo.clear();
				}

				combo += "\n" + local("nolook_title", true) + ":";

				// # / # / # / # / # / # / # / # / # / # / # / # / # \ # \ # \ # \ # \ # \ # \ # \ # # \ # \ # \ # //
				// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
				AutoLock luckynus(vectors_on);

				for (auto& i : data.ignore_channels) {
					combo += u8"\n- <#" + std::to_string(i) + u8">";
				}
				// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
				// # \ # \ # \ # \ # \ # \ # \ # \ # # \ # \ # \ # - # / # / # / # / # / # / # / # / # / # / # / # //
			}
			if (data.adm_tags.size() > 0) {

				if (combo.length() > 1536) {
					send_message_default(ch, combo, true);
					combo.clear();
				}

				combo += u8"\n" + local("adminroles_title", true) + ":";

				// # / # / # / # / # / # / # / # / # / # / # / # / # \ # \ # \ # \ # \ # \ # \ # \ # # \ # \ # \ # //
				// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
				AutoLock luckynus(vectors_on);

				for (auto& i : data.adm_tags) {
					combo += u8"\n- <@&" + std::to_string(i) + u8">";
				}

				// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
				// # \ # \ # \ # \ # \ # \ # \ # \ # # \ # \ # \ # - # / # / # / # / # / # / # / # / # / # / # / # //
			}

			if (combo.length()) send_message_default(ch, combo, true);
		}

		// - > - > - > - > - > - > - > LOG < - < - < - < - < - < - < - //
		else if (cmd == local("log")) { // DONE

			bool fail = true;
			if (args.size() >= 2) {
				auto cpystr = args[1];

				if (cpystr.length() > 0) {
					auto val = stdstoulla(cpystr);
					if (val) {
						data.channel_log = val;
						save_config();
						fail = false;
					}
				}
				if (!fail && args.size() >= 3) {
					auto cpystr2 = args[2];

					if (cpystr2.length() > 0) {
						auto val2 = stdstoulla(cpystr2);
						if (val2) {
							data.channel_alt_log = val2;
							save_config();
							fail = false;
						}
					}
				}
				else if (!fail) {
					data.channel_alt_log = 0;
				}
			}
			if (fail) send_message_default(ch, local("failed", true), false);
			else send_message_default(ch, local("success", true), true);
		}

		// - > - > - > - > - > - > - > DEEPLOG < - < - < - < - < - < - < - //
		else if (cmd == local("deeplog")) {
			
			data.deep_data = !data.deep_data;
			send_message_default(ch,
				local("deeplog_title", true) + " -> " +
				std::string(data.deep_data ? local("enabled", true) : local("disabled", true)), true);
			save_config();

		}

		// - > - > - > - > - > - > - > MEGADEEP < - < - < - < - < - < - < - //
		else if (cmd == local("megadeep")) {
			
			data.mega_deep = !data.mega_deep;
			send_message_default(ch,
				local("megadeep_title", true) + " -> " +
				std::string(data.mega_deep ? local("enabled", true) : local("disabled", true)), true);
			save_config();

		}

		// - > - > - > - > - > - > - > NOLOOK / IGNORE < - < - < - < - < - < - < - //
		else if (cmd == local("nolook")) { // "ignore"

			if (args.size() > 0) {
				auto& cpy = args[1];
				for (auto& i : cpy) i = std::tolower(i);

				std::string combo;

				if (cpy == local("del_arg") && args.size() > 1) { // DELETE

					combo = local("list_success", true) + "\n";

					for (size_t p = 2; p < args.size(); p++) {
						auto val = stdstoulla(args[p]);
						bool found = false;

						// # / # / # / # / # / # / # / # / # / # / # / # / # \ # \ # \ # \ # \ # \ # \ # \ # # \ # \ # \ # //
						// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
						AutoLock luckynus(vectors_on);

						for (size_t s = 0; s < data.ignore_channels.size(); s++) {
							if (data.ignore_channels[s] == val) {
								data.ignore_channels.erase(data.ignore_channels.begin() + s);
								found = true;
								break;
							}
						}

						if (found) {
							combo += local("del_arg") + " -> " + args[p] + "\n";
						}
						// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
						// # \ # \ # \ # \ # \ # \ # \ # \ # # \ # \ # \ # - # / # / # / # / # / # / # / # / # / # / # / # //
					}
				}
				else { // ADD

					combo = local("list_success", true) + "\n";

					for (size_t p = 1; p < args.size(); p++) {
						auto val = stdstoulla(args[p]);
						if (val) {
							bool found = false;

							// = - = - = - = - = - = - = - = - = - = - = = - - = - = - = - = - = - = - = - = - = = - = - = - = //
							// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
							AutoLock luckynus(vectors_on);

							for (size_t s = 0; s < data.ignore_channels.size(); s++) {
								if (data.ignore_channels[s] == val) {
									found = true;
									break;
								}
							}

							if (!found) {
								data.ignore_channels.push_back(val);
								combo += local("add_arg") + " -> " + args[p] + "\n";
							}
							// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
							// = - = - = - = - = - = - = - = - = - = - = = - - = - = - = - = - = - = - = - = - = = - = - = - = //
						}
					}
				}
				if (combo.empty()) send_message_default(ch, local("failed", true), false);
				else {
					save_config();
					send_message_default(ch, combo, true, local("success", true));
				}
			}

		}

		// - > - > - > - > - > - > - > ADMIN ROLES < - < - < - < - < - < - < - //
		else if (cmd == local("admin")) {

			if (args.size() > 0) {
				auto& cpy = args[1];
				for (auto& i : cpy) i = std::tolower(i);

				std::string combo;

				if (cpy == local("del_arg") && args.size() > 1) { // DELETE

					combo = local("list_success", true) + "\n";

					for (size_t p = 2; p < args.size(); p++) {
						auto val = stdstoulla(args[p]);
						bool found = false;

						// # / # / # / # / # / # / # / # / # / # / # / # / # \ # \ # \ # \ # \ # \ # \ # \ # # \ # \ # \ # //
						// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
						AutoLock luckynus(vectors_on);

						for (size_t s = 0; s < data.adm_tags.size(); s++) {
							if (data.adm_tags[s] == val) {
								data.adm_tags.erase(data.adm_tags.begin() + s);
								found = true;
								break;
							}
						}

						if (found) {
							combo += local("del_arg") + " -> " + args[p] + "\n";
						}
						// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
						// # \ # \ # \ # \ # \ # \ # \ # \ # # \ # \ # \ # - # / # / # / # / # / # / # / # / # / # / # / # //
					}
				}
				else { // ADD

					combo = local("list_success", true) + "\n";

					for (size_t p = 1; p < args.size(); p++) {
						auto val = stdstoulla(args[p]);
						if (val) {
							bool found = false;

							// # / # / # / # / # / # / # / # / # / # / # / # / # \ # \ # \ # \ # \ # \ # \ # \ # # \ # \ # \ # //
							// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
							AutoLock luckynus(vectors_on);

							for (size_t s = 0; s < data.adm_tags.size(); s++) {
								if (data.adm_tags[s] == val) {
									found = true;
									break;
								}
							}

							if (!found) {
								data.adm_tags.push_back(val);
								combo += local("add_arg") + " -> " + args[p] + "\n";
							}
							// = - = - = - = - = - = - = - = - = - = - = LOCKED AREA = - = - = - = - = - = - = - = - = - = - = //
							// # \ # \ # \ # \ # \ # \ # \ # \ # # \ # \ # \ # - # / # / # / # / # / # / # / # / # / # / # / # //
						}
					}
				}
				if (combo.empty()) send_message_default(ch, local("failed", true), false);
				else {
					save_config();
					send_message_default(ch, combo, true, local("success", true));
				}
			}
		}

		// - > - > - > - > - > - > - > LANGUAGE < - < - < - < - < - < - < - //
		else if (cmd == local("language")) {
			if (args.size() > 1 || here.get_raw_guild().region.is_set()) {
				std::string regg;
				if (args.size() > 1) regg = args[1];
				else regg = here.get_raw_guild().region.get();

				for (auto& i : regg) i = std::tolower(i);

				refresh_language(regg);

				send_message_default(ch, local("success", true), true);
			}
			else {
				send_message_default(ch, local("failed", true), false);
			}
		}

		// - > - > - > - > - > - > - > PING  < - < - < - < - < - < - < - //
		else if (cmd == local("ping")) {

			send_message_default(ch, local("pong", true), true);

		}

		// - > - > - > - > - > - > - > STATS  < - < - < - < - < - < - < - //
		else if (cmd == local("stats")) {
			std::lock_guard<std::recursive_mutex> luck(buf_control);

			//int64_t guild_count = core->get_guild_map().size();
			//int64_t user_count_unique = core->us();
			//int64_t channel_count = core->get_channel_count();

			int64_t eventsseen = 0;

			for (auto& e : core->message_count)
				eventsseen += e.second;

			//std::string members = fmt::format("{}", user_count_unique);
			//std::string channels = fmt::format("{}", channel_count);
			//std::string guilds = fmt::format("{}", guild_count);
			std::string events = fmt::format("{}", eventsseen);

			std::stringstream w;

			w << u8"[" << local("stats_github", true) << u8"](https://github.com/Lohkdesgds/WolfLogger)\n"
				<< u8"[" << local("stats_discord", true) << u8"](https://discord.gg/JkzJjCG)\n" + common_bar + u8"\n"
				<< local("stats_ram_normal", true) << u8": " << double(aegis::utility::getCurrentRSS()) / div_memory_calc << u8" MB\n"
				<< local("stats_ram_peak", true) << u8": " << double(aegis::utility::getPeakRSS()) / div_memory_calc << u8" MB";


			std::string stats = common_bar + u8"\n" + w.str() + u8"\n" + common_bar;
			std::string buffer_len = std::to_string(buf.length()) + "/" + std::to_string(max_len) + " bytes";

			if (here.bot_has_perm(ch, permissions_user::EMBED_LINKS)) {

				nlohmann::json t = {
					{ "title", local("stats_title", true) },
					{ "description", stats },
					{ "color", color_embed_default },
					{ "fields",
					nlohmann::json::array(
						{
							//{ { "name", local("stats_members", true) },		{ "value", members },				{ "inline", true } },
							//{ { "name", local("stats_channnels", true) },	{ "value", channels },				{ "inline", true } },
							{ { "name", local("stats_uptime", true) },		{ "value", core->uptime_str() },	{ "inline", true } },
							//{ { "name", local("stats_guilds", true) },		{ "value", guilds },				{ "inline", true } },
							{ { "name", local("stats_events", true) },		{ "value", events },				{ "inline", true } },
							{ { "name", local("stats_buffer", true) },		{ "value", buffer_len },			{ "inline", true } },
							{ { "name", local("stats_region", true) },		{ "value", data.region },			{ "inline", true } },
							{ { "name", local("stats_version", true) },		{ "value", version },				{ "inline", true } }

							//{ { "name", u8"\u200b" },{ "value", u8"\u200b" },{ "inline", true } },// this is clean block lmao
						}
						)
					},
					{ "footer",{ { "icon_url", "https://cdn.discordapp.com/emojis/289276304564420608.png" },{ "text", fmt::format(local("stats_footer", true), CXX_VERSION, AEGIS_VERSION_TEXT) } } }
				};

				here.create_message_embed(ch, t);
				//slow_flush_embed(t, ch, guild_id, logg);
			}
			else {

				std::string mm = "***" + local("stats_title", true) + "***\n```\n" +
					stats + "\n" +
					//local("stats_members", true)	+ ": " + members + "\n" +
					//local("stats_channnels", true)	+ ": " + channels + "\n" +
					local("stats_uptime", true)		+ ": " + core->uptime_str() + "\n" +
					//local("stats_guilds", true)		+ ": " + guilds + "\n" +
					local("stats_events", true)		+ ": " + events + "\n" +
					local("stats_buffer", true)		+ ": " + buffer_len + "\n" +
					local("stats_region", true)		+ ": " + data.region + "\n" +
					local("stats_version", true)	+ ": " + version + "\n```";

				//slow_flush(mm, ch, guild_id, logg);
				here.create_message(ch, mm);
			}

		}

		// - > - > - > - > - > - > - > ALIAS  < - < - < - < - < - < - < - //
		else if (cmd == local("alias")) { // DONE

			std::string combo;

			if (args.size() > 1) {
				data.alias_cmd = args[1];

				combo = local("success", true) + ": \"" + data.alias_cmd + "\".";
				save_config();
			}

			if (!combo.empty()) send_message_default(ch, combo, true, local("success", true));
			else send_message_default(ch, "Failed", true);	

		}

		// - > - > - > - > - > - > - > HELP  < - < - < - < - < - < - < - //
		else {
			do_help = true;
		}
	}
	if (do_help) { // HELP
		if (here.bot_has_perm(ch, permissions_user::EMBED_LINKS)) {

			nlohmann::json t = {
				{ "title", local("commands", true) },
				{ "color", color_embed_default },
				{ "fields",
				nlohmann::json::array(
					{
						{ { "name", local("flush") },		{ "value", "`" + local("flush_desc") + "`" },		{ "inline", false } },
						{ { "name", local("show") },		{ "value", "`" + local("show_desc") + "`" },		{ "inline", false } },
						{ { "name", local("log") },			{ "value", "`" + local("log_desc") + "`" },			{ "inline", false } },
						{ { "name", local("deeplog") },		{ "value", "`" + local("deeplog_desc") + "`" },		{ "inline", false } },
						{ { "name", local("megadeep") },	{ "value", "`" + local("megadeep_desc") + "`" },	{ "inline", false } },
						{ { "name", local("nolook") },		{ "value", "`" + local("nolook_desc") + "`" },		{ "inline", false } },
						{ { "name", local("admin") },		{ "value", "`" + local("admin_desc") + "`" },		{ "inline", false } },
						{ { "name", local("help") },		{ "value", "`" + local("help_desc") + "`" },		{ "inline", false } },
						{ { "name", local("language") },	{ "value", "`" + local("language_desc") + "`" },	{ "inline", false } },
						{ { "name", local("ping") },		{ "value", "`" + local("ping_desc") + "`" },		{ "inline", false } },
						{ { "name", local("stats") },		{ "value", "`" + local("stats_desc") + "`" },		{ "inline", false } },
						{ { "name", local("alias") },		{ "value", "`" + local("alias_desc") + "`" },		{ "inline", false } }
					}
					)
				}
			};

			here.create_message_embed(ch, t);
			//slow_flush_embed(t, ch, guild_id, logg);
		}
		else {
			std::string msg = "```md\n# " + local("commands", true) + "\n" +
				local("flush") + ": " + local("flush_desc") + "\n" +
				local("show") + ": " + local("show_desc") + "\n" +
				local("log") + ": " + local("log_desc") + "\n" +
				local("deeplog") + ": " + local("deeplog_desc") + "\n" +
				local("megadeep") + ": " + local("megadeep_desc") + "\n" +
				local("nolook") + ": " + local("nolook_desc") + "\n" +
				local("admin") + ": " + local("admin_desc") + "\n" +
				local("help") + ": " + local("help_desc") + "\n" +
				local("language") + ": " + local("language_desc") + "\n" +
				local("ping") + ": " + local("ping_desc") + "\n" +
				local("stats") + ": " + local("stats_desc") + "\n" +
				local("alias") + ": " + local("alias_desc") + "\n```";

			send_message_default(ch, msg, true);
		}
	}
}

bool Guild::check_command(std::string str, const unsigned long long ch, const unsigned long long id)
{
	int found = str.find(command_global) == 0 ? 1 : (data.alias_cmd.length() > 0 ? (str.find(data.alias_cmd) == 0 ? 2 : 0) : 0); // alias == 2
	if (found > 0) {
		if (!is_user_admin(id)) {
			send_message_default(ch, u8"Not admin.", false);
		}
		else {
			size_t start = found == 2 ? data.alias_cmd.length() : command_global.length();
			std::vector<std::string> arguments;
			{
				std::string buff;
				for (size_t p = start; p < str.length(); p++) {
					auto& i = str[p];
					if (i != ' ') buff += str[p];
					else if (!buff.empty()) arguments.push_back(std::move(buff));
				}
				if (!buff.empty()) arguments.push_back(std::move(buff));
			}

			command(arguments, ch);
		}
		return true;
	}
	return false;
}

void Guild::time_flush()
{
	auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	if (now - last > time_to_flush) {
		_force_flush_buffer_custom(buf, data.channel_log);
		_force_flush_buffer_custom(altbuf, data.channel_alt_log ? data.channel_alt_log : data.channel_log);
	}
	last = now;
}


void Guild::task_welcome_message()
{
	has_welcomed = true;
	std::lock_guard<std::recursive_mutex> rluck(welcome_goodbye_refresh);
	if (data.deep_data) {
		auto message = "` - - - - > " + local("wakeup_message") + " < - - - - `";

		here.create_message(data.channel_log, message);
		//core->async([&, message] {_flush_custom(message); }).then([&] {logg->info("[ASYNC] Tasked welcome block."); });
	}
	if (here.get_raw_guild().id.get() == master_guild) {
		std::string mess = "```md\n# Hello master guild.\n";
		mess += "- Version running right now: " + version;
		mess += "```";
		here.create_message(data.channel_log, mess);
		//core->async([&, mess] {_flush_custom(mess); }).then([&] {logg->info("[ASYNC] Tasked MASTER debugging message."); });
	}
}

void Guild::task_reset_message()
{
	if (!data.deep_data) return;
	std::lock_guard<std::recursive_mutex> rluck(welcome_goodbye_refresh);
	auto message = "` - - - - > " + local("rejoin_message") + " < - - - - `";

	here.create_message(data.channel_log, message);
	//core->async([&, message] {_flush_custom(message); }).then([&] {logg->info("[ASYNC] Tasked rejoin block."); });
}

void Guild::task_end_message()
{
	if (!data.deep_data) return;
	std::lock_guard<std::recursive_mutex> rluck(welcome_goodbye_refresh);
	auto message = "` - - - - > " + local("shutdown_message") + " < - - - - `";

	here.create_message(data.channel_log, message);
	//_flush_custom(message);
}



void Guild::handle(the_event& ev)
{
	// all this is handled in lambda in constructor
	/*if (!has_welcomed) {
		refresh_flush_channel();
		task_welcome_message();
		has_welcomed = true;
	}*/
	/*for (size_t p = 0; p < 15 && !thus; p++) {
		bool good = trycatch_auto([&] {reassign(core); }); // trying to reassign.
		if (!thus || !good) {
			logg->critical("[{}/15] Guild #{} has no guild set. Trying to reset guild pointer...", p + 1, guild_id);
			std::this_thread::sleep_for(std::chrono::seconds(3));
		}
	}
	if (!thus) return;
	for (size_t p = 0; p < 15 && !trycatch_auto([&] {handle(t); }); p++) {
		logg->critical("[{}/15] Guild #{} failed to handle event.", p + 1, guild_id);
		std::this_thread::sleep_for(std::chrono::seconds(3));
	}*/

	//logg->info("GOT EVENT TYPE #{} ({})", ev.type, ev.type_str.get());

	switch (ev.type) {
	case event_type::GUILD_MEMBER_ADD:
	{
		auto& ref = ev.data.guild_member_add;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!data.deep_data) return;

		each_block b;
		b.title = "```css\n[" + local("new_member") + "](#" + std::to_string(ref->user.id.get()) + ")```";
		b.content = "```md\n- " + local("member_joined_at", true) + ": " + ref->joined_at.nice_format() + "\n"
			+ "- " + local("member_nick", true) + ": " + ref->nick.get() + "\n"
			+ "- " + local("member_realnick", true) + ": " + ref->user.get_combo_name() + "\n"
			+ "- " + local("member_is_bot", true) + ": " + std::string(ref->user.bot.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_verified", true) + ": " + std::string(ref->user.verified.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_webhook", true) + ": " + std::string(ref->user.is_webhook() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_mfa", true) + ": " + std::string(ref->user.mfa_enabled.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_locale", true) + ": " + ref->user.locale.get() + "\n"
			+ "- " + local("member_flags", true) + ": " + std::to_string(ref->user.flags.get()) + "\n"
			+ "- " + local("member_publicflags", true) + ": " + std::to_string(ref->user.public_flags.get()) + "\n"
			+ (ref->user.premium_type.get() ? ("- " + local("member_nitro", true) + ": " + (ref->user.premium_type.get() == 1 ? "Nitro Classic" : "Nitro")) : "")
			+ "```\n";

		b.user_id = 0;

		flush_one_alt_block(b);
	}
		break;
	case event_type::GUILD_MEMBER_UPDATE:
	{
		auto& ref = ev.data.guild_member_update;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!data.deep_data) return;

		std::string roles_combo;
		for (size_t p = 0; p < ref->roles.size(); p++) {
			auto& i = ref->roles[p];
			roles_combo += "#" + std::to_string(i) + (i != ref->roles.back() ? ", " : "");
		}
		if (roles_combo.empty()) roles_combo = local("member_has_no_tags");

		each_block b;
		b.title = "```css\n[" + local("update_member") + "](#" + std::to_string(ref->user.id.get()) + ")```";
		b.content = "```md\n- " + local("member_joined_at", true) + ": " + ref->joined_at.nice_format() + "\n"
			+ "- " + local("member_nick", true) + ": " + ref->nick.get() + "\n"
			+ "- " + local("member_realnick", true) + ": " + ref->user.get_combo_name() + "\n"
			+ "- " + local("member_is_bot", true) + ": " + std::string(ref->user.bot.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_verified", true) + ": " + std::string(ref->user.verified.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_webhook", true) + ": " + std::string(ref->user.is_webhook() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_mfa", true) + ": " + std::string(ref->user.mfa_enabled.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_locale", true) + ": " + ref->user.locale.get() + "\n"
			+ "- " + local("member_flags", true) + ": " + std::to_string(ref->user.flags.get()) + "\n"
			+ "- " + local("member_publicflags", true) + ": " + std::to_string(ref->user.public_flags.get()) + "\n"
			+ "- " + local("member_deaf", true) + ": " + std::string(ref->deaf.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_mute", true) + ": " + std::string(ref->mute.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_tags", true) + ": " + roles_combo
			+ "```\n";

		b.user_id = 0;

		flush_one_alt_block(b);
	}
		break;
	case event_type::GUILD_MEMBER_REMOVE:
	{
		auto& ref = ev.data.guild_member_remove;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!data.deep_data) return;

		std::string roles_combo;
		for (size_t p = 0; p < ref->roles.size(); p++) {
			auto& i = ref->roles[p];
			roles_combo += "#" + std::to_string(i) + (i != ref->roles.back() ? ", " : "");
		}
		if (roles_combo.empty()) roles_combo = local("member_has_no_tags");

		each_block b;
		b.title = "```css\n[" + local("update_member") + "](#" + std::to_string(ref->user.id.get()) + ")```";
		b.content = "```md\n- " + local("member_joined_at", true) + ": " + ref->joined_at.nice_format() + "\n"
			+ "- " + local("member_nick", true) + ": " + ref->nick.get() + "\n"
			+ "- " + local("member_realnick", true) + ": " + ref->user.get_combo_name() + "\n"
			+ "- " + local("member_is_bot", true) + ": " + std::string(ref->user.bot.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_verified", true) + ": " + std::string(ref->user.verified.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_webhook", true) + ": " + std::string(ref->user.is_webhook() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_mfa", true) + ": " + std::string(ref->user.mfa_enabled.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_locale", true) + ": " + ref->user.locale.get() + "\n"
			+ "- " + local("member_flags", true) + ": " + std::to_string(ref->user.flags.get()) + "\n"
			+ "- " + local("member_publicflags", true) + ": " + std::to_string(ref->user.public_flags.get()) + "\n"
			+ "- " + local("member_deaf", true) + ": " + std::string(ref->deaf.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_mute", true) + ": " + std::string(ref->mute.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_tags", true) + ": " + roles_combo
			+ "```\n";

		b.user_id = 0;

		flush_one_alt_block(b);
	}
		break;
	case event_type::MESSAGE_CREATE: // command disabled
	{
		auto& ref = ev.data.message_create;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}
		if (!ref->member.user.id.is_set() || ref->member.user.id.get() == 0) {
#ifdef _DEBUG // it's probably some weird return from a message that the bot answered.
			logg->warn("Event {} had invalid user", ev.type_str.get());
#endif
			return;
		}

		if (ref->member.user.bot.get()) return;

		if (!is_chat_valid(ref->channel_id.get())) return;

		check_command(ref->content.get(), ref->channel_id, ref->member.user.id);

		std::string extra;
		for (size_t count = 0; count < ref->attachments.size(); count++) extra += "\n > " + ref->attachments[count].filename.get() + " (" + ref->attachments[count].url.get() + ")";
		channel_c ch = here.get_channel(ref->channel_id);

		each_block b;
		b.title = "```md\n[" + std::to_string(ref->author.id.get()) + "](" + ref->author.get_combo_name() + ")```";
		b.subtitle = "`[" + ref->timestamp.nice_format() + "]<m" + std::to_string(ref->id.get()) + "@" + std::to_string(ch.id.get()) + ">(" + ch.name.get() + ")`**:** ";
		b.content = _fix_content(ref->content.get()) + extra + '\n';
		b.user_id = ref->author.id.get();
		if (b.has_emd = (ref->embeds.size() > 0)) b.emb = ref->embeds[0];


		flush_one_block(b);		
	}
		break;
	case event_type::MESSAGE_UPDATE:
	{
		auto& ref = ev.data.message_update;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}
		if (!ref->member.user.id.is_set() || ref->member.user.id.get() == 0) {
#ifdef _DEBUG // it's probably some weird return from a message that the bot answered.
			logg->warn("Event {} had invalid user", ev.type_str.get());
#endif
			return;
		}

		if (ref->member.user.bot.get()) return;

		if (!is_chat_valid(ref->channel_id.get())) return;

		channel_c ch = here.get_channel(ref->channel_id);

		each_block b;
		b.title = "```md\n[" + std::to_string(ref->author.id.get()) + "](" + ref->author.get_combo_name() + ")```";
		b.subtitle = "`[" + ref->timestamp.nice_format() + "]<m" + std::to_string(ref->id.get()) + "@" + std::to_string(ch.id.get()) + ">(" + ch.name.get() + ")`**:** ";
		b.content = _fix_content(ref->content.get()) + " `<- " + local("edited_message") + "`\n";
		b.user_id = ref->author.id.get();
		if (b.has_emd = (ref->embeds.size() > 0)) b.emb = ref->embeds[0];


		flush_one_block(b);

	}
		break;
	case event_type::MESSAGE_DELETE:
	{
		auto& ref = ev.data.message_delete;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		member_c memb = here.get_member(ref->id.get());
		if (memb.user.bot.get()) return;

		if (!data.deep_data) return;

		if (!is_chat_valid(ref->channel_id.get())) return;

		channel_c ch = here.get_channel(ref->channel_id);

		each_block b;
		b.title = "```css\n[" + local("message_t") + "](" + local("delete_t") + ")```";
		b.subtitle = "`<m" + std::to_string(ref->id.get()) + "@" + std::to_string(ch.id.get()) + ">(" + ch.name.get() + ")` ";
		b.content = " `<- " + local("del") + "`\n";
		b.user_id = 0;


		flush_one_block(b);
	}
		break;
	case event_type::PRESENCE_UPDATE:
	{
		auto& ref = ev.data.presence_update;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!data.mega_deep || !data.deep_data) return;

		member_c memb = here.get_member(ref->user.id);
		if (memb.user.bot) return;

		std::string final_content;

		std::vector<std::string> activities_str;

		for (size_t p = 0; p < ref->activities.size(); p++) {
			auto& i = ref->activities[p];

			if (!i.has_new_data()) continue;

			std::string curr;

			// common
			time_iso started;
			started.input_epoch_ms(i.created_at.get());

			//if (i.name == ref->game.name) curr += "# . MAIN APP/GAME/EVENT . #\n";
			curr += "# " + i.name.get() + "\n";

			switch (i.type.get()) {
			case static_cast<int64_t>(activity_types::Game):
				if (i.details.is_set() && !i.details.get().empty()) curr += "- " + local("gaming_playing_t") + ": < " + i.details.get() + " >\n";
				if (i.state.is_set() && !i.state.get().empty()) curr += "- " + local("gaming_info_t") + ": < " + i.state.get() + " >\n";
				break;
			case static_cast<int64_t>(activity_types::Streaming):
				if (i.details.is_set() && !i.details.get().empty()) curr += "< " + i.details.get() + " >\n";
				if (i.state.is_set() && !i.state.get().empty()) curr += "< " + i.state.get() + " >\n";
				curr += "* " + i.url.get() + "\n";
				break;
			case static_cast<int64_t>(activity_types::Listening): // spotify probably
				if (i.details.is_set() && !i.details.get().empty()) curr += "- " + local("spotify_music_t") + ": < " + i.details.get() + " >\n";
				if (i.state.is_set() && !i.state.get().empty()) curr += "- " + local("spotify_album_t") + ": < " + i.state.get() + " >\n";
				// nothing, maybe later add more stuff like assets and so on?
				break;
			case static_cast<int64_t>(activity_types::Custom): // custom status
				if (i.state.is_set() && !i.state.get().empty()) {
					curr += "[" + ((i.emoji.id.is_set() && !i.emoji.name.get().empty()) ? i.emoji.format() : "-") + "](" + i.state.get() + ")\n";
				}
				else if (i.emoji.id.is_set() && !i.emoji.name.get().empty()) {
					curr += "- " + i.emoji.format() + "\n";
				}
				break;
			}

			curr += "> " + started.nice_format() + "\n"; // date
			activities_str.push_back(curr);
		}

		/*if (ref->game.has_new_data())*/
		{
			std::string first;
			if (ref->status.is_set()) {
				auto& i = ref->status.get();
				if (i == "idle") {
					first += u8"🟠 > "; // orange
				}
				if (i == "dnd") {
					first += u8"🔴 > "; // red
				}
				if (i == "online") {
					first += u8"🟢 > "; // green
				}
				if (i == "offline") {
					first += u8"⚫ > "; // black
				}
			}
			
			if (ref->client_status.desktop.is_set()) {
				//first += "- ON DESKTOP: " + ref->client_status.desktop.get() + "\n";
				first += u8"💻";
			}
			if (ref->client_status.mobile.is_set()) {
				//first += "- ON MOBILE: " + ref->client_status.desktop.get() + "\n";
				first += u8"📱";
			}
			if (ref->client_status.web.is_set()) {
				//first += "- ON WEB: " + ref->client_status.desktop.get() + "\n";
				first += u8"📡";
			}

			/*if (ref->game.assets.large_image.is_set()) {
				first += "- LARGE IMG: " + ref->game.assets.large_url(ref->game.application_id, 256) + "\n";
			}
			if (ref->game.assets.small_image.is_set()) {
				first += "- SMALL IMG: " + ref->game.assets.small_url(ref->game.application_id, 256) + "\n";
			}*/
			final_content += std::string("```md\n")
				/*+ "- " + local("member_nick", true) + ": " + ref->nick.get() + "\n"
				+ "- " + local("member_realnick", true) + ": " + memb.user.get_combo_name() + "\n"
				+ "- " + local("member_is_bot", true) + ": " + std::string(memb.user.bot.get() ? local("yes") : local("no"))*/
				+ first + "``` "; // no need to \n
		}

		for (size_t p = 0; p < activities_str.size(); p++) {
			auto& k = activities_str[p];
			final_content += "```md\n" + k + "```\n";
			/*each_block b;
			b.title = "```md\n[" + local("presence_generic_t") + "](" + ref->user.get_combo_name() + ")<#" + std::to_string(p + 1) + ">```";
			b.content = "```md\n"
				+ k
				+ "```";

			b.user_id = 0;

			flush_one_block(b);*/
		}
		each_block b;
		b.title = "```md\n[" + local("presence_generic_t") + "](" + ref->user.get_combo_name() + ")```";
		//b.content = "```md\n" + default_start + first + "```";
		b.content = std::move(final_content);

		b.user_id = 0;

		flush_one_alt_block(b);

	}
		break;
	case event_type::TYPING_START:
	{
		auto& ref = ev.data.typing_start;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!data.mega_deep || !data.deep_data) return;

		auto ch = here.get_channel(ref->channel_id);
		time_iso ti;

		// typing is in seconds, damn.
		ti.input_epoch_s(ref->timestamp);

		each_block b;
		b.title = "```md\n[" + std::to_string(ref->member.user.id.get()) + "](" + ref->member.user.get_combo_name() + ")```";
		b.subtitle = "`[" + ti.nice_format() + "]<@" + std::to_string(ref->channel_id) + ">(" + ch.name.get() + ")` ";
		b.content = " `" + local("typing_event") + "`\n";
		b.user_id = ref->user_id;


		flush_one_block(b);
	}
		break;
	/*case event_type::GUILD_CREATE:
	{
		auto& ref = ev.data.guild_create;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}
	}
		break;
	case event_type::GUILD_UPDATE:
	{
		auto& ref = ev.data.guild_update;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}
	}
		break;
	case event_type::GUILD_DELETE:
	{
		auto& ref = ev.data.guild_delete;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}
	}
		break;*/
	case event_type::MESSAGE_REACTION_ADD:
	{
		auto& ref = ev.data.message_reaction_add;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!is_chat_valid(ref->channel_id)) return;

		auto memb = here.get_member(ref->user_id);

		if (memb.user.id == here.get_bot().id) return;

		auto chh = here.get_channel(ref->channel_id);
		auto msg = here.get_message(ref->channel_id, ref->message_id.get());

		each_block b;
		b.title = "```md\n[" + std::to_string(memb.user.id.get()) + "](" + memb.user.get_combo_name() + ")```";
		b.subtitle = "`[" + msg.timestamp.nice_format() + "]<m" + std::to_string(ref->message_id) + "@" + std::to_string(ref->channel_id) + ">(" + chh.name.get() + ")` ";
		b.content = msg.content.get() + " `<- " + local("reacted_with") + "` " + ref->emoji.format() + "\n";
		b.user_id = ref->user_id;


		flush_one_block(b);
	}
		break;
	case event_type::MESSAGE_REACTION_REMOVE:
	{
		auto& ref = ev.data.message_reaction_remove;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!is_chat_valid(ref->channel_id)) return;

		auto memb = here.get_member(ref->user_id);

		if (memb.user.id == here.get_bot().id) return;

		auto chh = here.get_channel(ref->channel_id);
		auto msg = here.get_message(ref->channel_id, ref->message_id.get());

		each_block b;
		b.title = "```md\n[" + std::to_string(memb.user.id.get()) + "](" + memb.user.get_combo_name() + ")```";
		b.subtitle = "`[" + msg.timestamp.nice_format() + "]<m" + std::to_string(ref->message_id) + "@" + std::to_string(ref->channel_id) + ">(" + chh.name.get() + ")` ";
		b.content = msg.content.get() + " `<- " + local("removed_reaction") + "` " + ref->emoji.format() + "\n";
		b.user_id = ref->user_id;


		flush_one_block(b);
	}
		break;
	/*case event_type::MESSAGE_REACTION_REMOVE_ALL:
	{
		auto& ref = ev.data.message_reaction_remove_all;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!is_chat_valid(ref->channel_id)) return;
		auto chh = here.get_channel(ref->channel_id);
		auto msg = here.get_message(ref->channel_id, ref->message_id.get());

		each_block b;
		b.title = "```md\n[" + std::to_string(usr.user.id.get()) + "](" + (usr.nick.get()) + ")```";
		b.subtitle = "`[" + msg.timestamp.nice_format() + "]<m" + std::to_string(ref->message_id) + "@" + std::to_string(ref->channel_id) + ">(" + chh.name.get() + ")` ";
		b.content = msg.content.get() + " `<- " + local("removed_reaction") + "` " + format_emoji(ref->emoji) + "\n";
		b.user_id = ref->user_id;


		flush_one_block(b);
	}
		break;*/
	case event_type::MESSAGE_DELETE_BULK:
	{
		auto& ref = ev.data.message_delete_bulk;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!data.mega_deep || !data.deep_data) return;

		if (!is_chat_valid(ref->channel_id.get())) return;
		if (ref->ids.size() == 0) return;

		channel_c ch = here.get_channel(ref->channel_id);

		each_block b;
		b.title = "```css\n[" + local("message_t") + "](" + local("delete_t") + ")```";
		b.subtitle = "`<@" + std::to_string(ch.id.get()) + ">(" + ch.name.get() + "):";
		b.content += "```\n";
		for (size_t p = 0; p < ref->ids.size(); p++) {
			auto& mm = ref->ids[p];
			b.content += std::to_string(mm) + " ";
		}
		b.content += "```\n";
		b.user_id = 0;

		flush_one_block(b);
	}
		break;
	case event_type::USER_UPDATE:
	{
		auto& ref = ev.data.user_update;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!data.deep_data) return;

		member_c memb = here.get_member(ref->id);

		if (memb.user.id == here.get_bot().id) return;

		std::string roles_combo;
		for (size_t p = 0; p < memb.roles.size(); p++) {
			auto& i = memb.roles[p];
			roles_combo += "#" + std::to_string(i) + (i != memb.roles.back() ? ", " : "");
		}
		if (roles_combo.empty()) roles_combo = local("member_has_no_tags");

		each_block b;
		b.title = "```css\n[" + local("update_user") + "](#" + std::to_string(memb.user.id.get()) + ")```";
		b.content = "```md\n- " + local("member_joined_at", true) + ": " + memb.joined_at.nice_format() + "\n"
			+ "- " + local("member_nick", true) + ": " + memb.nick.get() + "\n"
			+ "- " + local("member_realnick", true) + ": " + memb.user.get_combo_name() + "\n"
			+ "- " + local("member_is_bot", true) + ": " + std::string(memb.user.bot.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_verified", true) + ": " + std::string(memb.user.verified.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_webhook", true) + ": " + std::string(memb.user.is_webhook() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_mfa", true) + ": " + std::string(memb.user.mfa_enabled.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_locale", true) + ": " + memb.user.locale.get() + "\n"
			+ "- " + local("member_flags", true) + ": " + std::to_string(memb.user.flags.get()) + "\n"
			+ "- " + local("member_publicflags", true) + ": " + std::to_string(memb.user.public_flags.get()) + "\n"
			+ "- " + local("member_deaf", true) + ": " + std::string(memb.deaf.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_mute", true) + ": " + std::string(memb.mute.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_tags", true) + ": " + roles_combo
			+ "```\n";

		b.user_id = 0;

		flush_one_alt_block(b);
	}
		break;
	case event_type::INVITE_CREATE:
	{
		auto& ref = ev.data.invite_create;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!data.mega_deep || !data.deep_data) return;

		channel_c ch = here.get_channel(ref->channel_id);
		member_c memb = here.get_member(ref->inviter.id);
		time_iso tim;
		tim.input_epoch_ms(ref->max_age.get());

		each_block b;
		b.title = "```css\n[" + local("new_invite_t") + "]```";
		b.subtitle = "`[" + ref->created_at.nice_format() + "]<@" + std::to_string(ref->channel_id) + ">(" + ch.name.get() + ")` ";
		b.content = "```md\n- " + local("member_nick", true) + ": " + memb.nick.get() + "\n"
			+ "- " + local("member_realnick", true) + ": " + memb.user.get_combo_name() + "\n"
			+ "- " + local("member_is_bot", true) + ": " + std::string(memb.user.bot.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("invite_max_age", true) + ": " + tim.nice_format() + "\n"
			+ "- " + local("invite_max_uses", true) + ": " + std::to_string(ref->max_uses.get()) + "\n"
			+ "- " + local("invite_temporary", true) + ": " + std::string(ref->temporary.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("invite_code", true) + ": " + ref->code + "\n"
			+ "```\n";

		b.user_id = 0;

		flush_one_alt_block(b);
	}
		break;
	case event_type::INVITE_DELETE:
	{
		auto& ref = ev.data.invite_delete;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!data.mega_deep || !data.deep_data) return;

		channel_c ch = here.get_channel(ref->channel_id);
		

		each_block b;
		b.title = "```css\n[" + local("del_invite_t") + "]```";
		b.subtitle = "`<@" + std::to_string(ref->channel_id) + ">(" + ch.name.get() + ")` ";
		b.content = ref->code.get() + "\n";

		b.user_id = 0;

		flush_one_alt_block(b);
	}
		break;
	case event_type::CHANNEL_CREATE:
	{
		auto& ref = ev.data.channel_create;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}
		if (!data.deep_data) return;

		if (!is_chat_valid(ref->id.get())) return;

		bool is_voice = ref->type.get() == aegis::gateway::objects::channel::channel_type::Voice;
		each_block b;
		b.subtitle = "\n> " + (ref->parent_id.get() ? ("<#" + std::to_string(ref->parent_id.get()) + "> / ") : "") + (is_voice ? " " : "<#" + std::to_string(ref->id.get()) + "> ") + "(" + ref->name.get() + ")\n";
		
		switch (ref->type.get()) {
		case static_cast<int>(channel_type::GUILD_CATEGORY):
			b.title = "```css\n[" + local("category_t") + "](" + local("create_t") + ")```";
			break;
		case static_cast<int>(channel_type::GUILD_TEXT):
			b.title = "```css\n[" + local("channel_t") + "](" + local("create_t") + ")```";
			if (ref->topic.get().length()) b.subtitle += local("topic", true) + ":\n```\n" + _fix_content(ref->topic.get()) + "```";
			b.subtitle += local("nsfw") + ": `" + std::string(ref->nsfw.get() ? local("yes") : local("no")) + "`\n";
			break;
		case static_cast<int>(channel_type::GUILD_VOICE):
			b.title = "```css\n[" + local("voice_t") + "](" + local("create_t") + ")```";
			b.subtitle += local("bitrate", true) + ": `" + std::to_string(ref->bitrate.get() / 1000) + " kbps`\n";
			b.subtitle += local("user_max", true) + ": `" + std::to_string(ref->user_limit.get()) + "`\n";
			break;
		}

		b.user_id = 0;

		flush_one_alt_block(b);
	}
		break;
	case event_type::CHANNEL_UPDATE:
	{
		auto& ref = ev.data.channel_update;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}
		if (!data.deep_data) return;

		if (!is_chat_valid(ref->id.get())) return;

		bool is_voice = ref->type.get() == aegis::gateway::objects::channel::channel_type::Voice;
		each_block b;
		b.subtitle = "\n> " + (ref->parent_id.get() ? ("<#" + std::to_string(ref->parent_id.get()) + "> / ") : "") + (is_voice ? " " : "<#" + std::to_string(ref->id.get()) + "> ") + "(" + ref->name.get() + ")\n";
		
		switch (ref->type.get()) {
		case static_cast<int>(channel_type::GUILD_CATEGORY):
			b.title = "```css\n[" + local("category_t") + "](" + local("update_t") + ")```";
			break;
		case static_cast<int>(channel_type::GUILD_TEXT):
			b.title = "```css\n[" + local("channel_t") + "](" + local("update_t") + ")```";
			if (ref->topic.get().length()) b.subtitle += local("topic", true) + ":\n```\n" + _fix_content(ref->topic.get()) + "```";
			b.subtitle += local("nsfw") + ": `" + std::string(ref->nsfw.get() ? local("yes") : local("no")) + "`\n";
			break;
		case static_cast<int>(channel_type::GUILD_VOICE):
			b.title = "```css\n[" + local("voice_t") + "](" + local("update_t") + ")```";
			b.subtitle += local("bitrate", true) + ": `" + std::to_string(ref->bitrate.get() / 1000) + " kbps`\n";
			b.subtitle += local("user_max", true) + ": `" + std::to_string(ref->user_limit.get()) + "`\n";
			break;
		}

		b.user_id = 0;

		flush_one_alt_block(b);
	}
		break;
	case event_type::CHANNEL_DELETE:
	{
		auto& ref = ev.data.channel_delete;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}
		if (!data.deep_data) return;

		if (!is_chat_valid(ref->id.get())) return;

		bool is_voice = ref->type.get() == aegis::gateway::objects::channel::channel_type::Voice;
		each_block b;
		b.subtitle = "\n> " + (ref->parent_id.get() ? ("<#" + std::to_string(ref->parent_id.get()) + "> / ") : "") + (is_voice ? " " : "<#" + std::to_string(ref->id.get()) + "> ") + "(" + ref->name.get() + ")\n";

		switch (ref->type.get()) {
		case static_cast<int>(channel_type::GUILD_CATEGORY):
			b.title = "```css\n[" + local("category_t") + "](" + local("delete_t") + ")```";
			break;
		case static_cast<int>(channel_type::GUILD_TEXT):
			b.title = "```css\n[" + local("channel_t") + "](" + local("delete_t") + ")```";
			if (ref->topic.get().length()) b.subtitle += local("topic", true) + ":\n```\n" + _fix_content(ref->topic.get()) + "```";
			b.subtitle += local("nsfw") + ": `" + std::string(ref->nsfw.get() ? local("yes") : local("no")) + "`\n";
			break;
		case static_cast<int>(channel_type::GUILD_VOICE):
			b.title = "```css\n[" + local("voice_t") + "](" + local("delete_t") + ")```";
			b.subtitle += local("bitrate", true) + ": `" + std::to_string(ref->bitrate.get() / 1000) + " kbps`\n";
			b.subtitle += local("user_max", true) + ": `" + std::to_string(ref->user_limit.get()) + "`\n";
			break;
		}

		b.user_id = 0;

		flush_one_alt_block(b);
	}
		break;
	case event_type::CHANNEL_PINS_UPDATE:
	{
		auto& ref = ev.data.channel_pins_update;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!data.deep_data) return;

		channel_c ch = here.get_channel(ref->channel_id);

		each_block b;
		b.title = "```css\n[" + local("pinned_message_t") + "]```";
		b.subtitle = "`[" + ref->last_pin_timestamp.nice_format() + "]<@" + std::to_string(ref->channel_id) + ">(" + ch.name.get() + ")` ";

		b.user_id = 0;

		flush_one_block(b);
	}
		break;
	case event_type::GUILD_BAN_ADD:
	{
		auto& ref = ev.data.guild_ban_add;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		each_block b;
		b.title = "```css\n[" + local("banned_t") + "]```";
		b.subtitle = u8"🔻 `" + ref->user.get_combo_name() + "` [<@" + std::to_string(ref->user.id.get()) + ">, #" + std::to_string(ref->user.id.get()) + "]";

		b.user_id = 0;


		flush_one_alt_block(b);
	}
		break;
	case event_type::GUILD_BAN_REMOVE:
	{
		auto& ref = ev.data.guild_ban_remove;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		each_block b;
		b.title = "```css\n[" + local("unbanned_t") + "]```";
		b.subtitle = u8"🔺 `" + ref->user.get_combo_name() + "` [<@" + std::to_string(ref->user.id.get()) + ">, #" + std::to_string(ref->user.id.get()) + "]";

		b.user_id = 0;


		flush_one_alt_block(b);
	}
		break;
	case event_type::GUILD_EMOJIS_UPDATE:
	{
		auto& ref = ev.data.guild_emojis_update;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!data.mega_deep || !data.deep_data) return;

		std::string emojilist;
		for (size_t p = 0; p < ref->emojis.size(); p++) {
			if (emojilist.length() + ref->emojis[p].format().length() > 2000) {
				each_block b;
				b.title = "```css\n[" + local("emoji_list_update_t") + "]```";
				b.content = emojilist + "\n";

				b.user_id = 0;

				flush_one_alt_block(b);
				emojilist.clear();
			}

			emojilist += ref->emojis[p].format() + " ";
		}
		if (!emojilist.empty()) {
			emojilist.pop_back(); // ' '

			each_block b;
			b.title = "```css\n[" + local("emoji_list_update_t") + "]```";
			b.content = emojilist + "\n";

			b.user_id = 0;

			flush_one_alt_block(b);
		}
	}
		break;
	case event_type::GUILD_INTEGRATIONS_UPDATE:
	{
		auto& ref = ev.data.guild_integrations_update;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!data.mega_deep || !data.deep_data) return;

		each_block b;
		b.title = "```css\n[" + local("integrations_update_t") + "]```";
		b.user_id = 0;


		flush_one_alt_block(b);
	}
		break;
	/*case event_type::GUILD_MEMBERS_CHUNK:
	{
		auto& ref = ev.data.guild_members_chunk;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}
	}
		break;*/
	case event_type::GUILD_ROLE_CREATE:
	{
		if (!data.deep_data) return;

		auto& ref = ev.data.guild_role_create;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		each_block b;
		b.title = "```css\n[" + local("role_t") + "](" + local("create_t") + ")```";
		b.subtitle += local("role_info", true) + ": <#" + std::to_string(ref->role.id.get()) + "> `[" + ref->role.name.get() + ", #" + std::to_string(ref->role.id.get()) + "]`\n";
		b.subtitle += local("role_color", true) + ": `" + std::to_string(ref->role.color.get()) + "`\n";
		b.subtitle += local("role_hoist", true) + ": `" + std::string(ref->role.hoist.get() ? local("yes") : local("no")) + "`\n";
		b.subtitle += local("role_managed", true) + ": `" + std::string(ref->role.managed.get() ? local("yes") : local("no")) + "`\n";
		b.subtitle += local("role_mentionable", true) + ": `" + std::string(ref->role.mentionable.get() ? local("yes") : local("no")) + "`\n";

		b.user_id = 0;


		flush_one_alt_block(b);
	}
		break;
	case event_type::GUILD_ROLE_UPDATE:
	{
		if (!data.deep_data) return;

		auto& ref = ev.data.guild_role_update;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		each_block b;
		b.title = "```css\n[" + local("role_t") + "](" + local("update_t") + ")```";
		b.subtitle += local("role_info", true) + ": <#" + std::to_string(ref->role.id.get()) + "> `[" + ref->role.name.get() + ", #" + std::to_string(ref->role.id.get()) + "]`\n";
		b.subtitle += local("role_color", true) + ": `" + std::to_string(ref->role.color.get()) + "`\n";
		b.subtitle += local("role_hoist", true) + ": `" + std::string(ref->role.hoist.get() ? local("yes") : local("no")) + "`\n";
		b.subtitle += local("role_managed", true) + ": `" + std::string(ref->role.managed.get() ? local("yes") : local("no")) + "`\n";
		b.subtitle += local("role_mentionable", true) + ": `" + std::string(ref->role.mentionable.get() ? local("yes") : local("no")) + "`\n";

		b.user_id = 0;


		flush_one_alt_block(b);
	}
		break;
	case event_type::GUILD_ROLE_DELETE:
	{
		if (!data.deep_data) return;

		auto& ref = ev.data.guild_role_delete;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		each_block b;
		b.title = "```css\n[" + local("role_t") + "](" + local("delete_t") + ")```";
		b.subtitle += local("role_info", true) + ": <#" + std::to_string(ref->role.id.get()) + "> `[" + ref->role.name.get() + ", #" + std::to_string(ref->role.id.get()) + "]`\n";
		b.subtitle += local("role_color", true) + ": `" + std::to_string(ref->role.color.get()) + "`\n";
		b.subtitle += local("role_hoist", true) + ": `" + std::string(ref->role.hoist.get() ? local("yes") : local("no")) + "`\n";
		b.subtitle += local("role_managed", true) + ": `" + std::string(ref->role.managed.get() ? local("yes") : local("no")) + "`\n";
		b.subtitle += local("role_mentionable", true) + ": `" + std::string(ref->role.mentionable.get() ? local("yes") : local("no")) + "`\n";

		flush_one_alt_block(b);

	}
		break;
	case event_type::VOICE_STATE_UPDATE:
	{
		auto& ref = ev.data.voice_state_update;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!data.mega_deep || !data.deep_data) return;

		each_block b;
		b.title = "```css\n[" + local("voice_member_update") + "](#" + std::to_string(ref->user_id.get()) + ")```";
		b.content = "```md\n- " + local("member_nick", true) + ": " + ref->member.nick.get() + "\n"
			+ "- " + local("member_realnick", true) + ": " + ref->member.user.get_combo_name() + "\n"
			+ "- " + local("member_is_bot", true) + ": " + std::string(ref->member.user.bot.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_verified", true) + ": " + std::string(ref->member.user.verified.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_webhook", true) + ": " + std::string(ref->member.user.is_webhook() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_deaf", true) + ": " + std::string(ref->deaf.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_mute", true) + ": " + std::string(ref->mute.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_deaf_self", true) + ": " + std::string(ref->self_deaf.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_mute_self", true) + ": " + std::string(ref->self_mute.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_stream", true) + ": " + std::string(ref->self_stream.get() ? local("yes") : local("no")) + "\n"
			+ "- " + local("member_video", true) + ": " + std::string(ref->self_video.get() ? local("yes") : local("no")) + "\n"
			+ "```\n";

		b.user_id = 0;

		flush_one_block(b);
		
	}
		break;
	/*case event_type::VOICE_SERVER_UPDATE:
	{
		auto& ref = ev.data.voice_server_update;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!data.mega_deep || !data.deep_data) return;

		
	}
		break;
	case event_type::WEBHOOKS_UPDATE:
	{
		auto& ref = ev.data.webhook_update;
		if (!ref.is_set()) {
			logg->warn("Event {} was nullptr", ev.type_str.get());
			return;
		}

		if (!data.mega_deep || !data.deep_data) return;
	}
		break;	*/		
	}

	//time_flush();
}




Guild::Guild(const unsigned long long id, std::shared_ptr<aegis::core> bot, std::weak_ptr<aegis::shards::shard_mgr> shrs)
	: here(bot->get_ratelimit(), bot->log)
{
	shards = shrs;
	here.get_raw_guild().id = id;
	last = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	reassign(bot);
	load_config();

	here.set_after_handle([&](the_event& ev) {
		if (!has_welcomed) {
			task_welcome_message();
		}
		/*for (size_t p = 0; p < 15 && !thus; p++) {
			bool good = trycatch_auto([&] {reassign(core); }); // trying to reassign.
			if (!thus || !good) {
				logg->critical("[{}/15] Guild #{} has no guild set. Trying to reset guild pointer...", p + 1, guild_id);
				std::this_thread::sleep_for(std::chrono::seconds(3));
			}
		}
		if (!thus) return;*/
		for (size_t p = 0; p < 4 && !trycatch_auto([&] {handle(ev); }); p++) {
			logg->critical("[{}/4] Guild #{} failed to handle event.", p + 1, here.get_raw_guild().id.get());
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
		time_flush();
	});

	//refresh_flush_channel();
	//task_welcome_message();
	//core->async([&] {refresh_flush_channel(); }); // do later
	//core->async([&] {task_welcome_message(); }); // do later	
}

Guild::~Guild()
{
	save_config();
	task_end_message();
}

void Guild::reassign(std::shared_ptr<aegis::core> bot)
{
	core = bot;
	logg = bot->log;

	/*if (!thus || ++last_thus_update > update_thus) {
		last_thus_update = 0;
		if (!trycatch_auto([&] {
			aegis::shards::shard* _shard = &core->get_shard_by_guild(guild_id);
			thus = bot->guild_create(guild_id, _shard);
		})) {
			logg->critical("Failed to get Guild #{}! Skipping event.", guild_id);
			thus = nullptr;
			return;
		}
	}*/
}

void Guild::force_save()
{
	save_config();
	_force_flush_buffer_custom(buf, data.channel_log);
	_force_flush_buffer_custom(altbuf, data.channel_alt_log ? data.channel_alt_log : data.channel_log);
}

void Guild::welcome_back()
{
	task_reset_message();
}

bool Guild::broadcast(std::string bread)
{
	if (bread.length() == 0) {
		logg->warn("Guild #{} had issue flushing (broadcast, null). Skipped.", here.get_raw_guild().id.get());
		return false;
	}
	if (!data.channel_log) {
		logg->warn("Guild #{} had issue flushing (broadcast, no channel). Skipped.", here.get_raw_guild().id.get());
		return false;
	}

	try {
		/*if (!flush_channel) refresh_flush_channel();
		if (!flush_channel) {
			logg->critical("Guild #{} could not send broadcast. Invalid flush channel.", guild_id);
		}*/


		if (here.bot_has_perm(data.channel_log, permissions_user::EMBED_LINKS)) {

			bread = "```md\n" + bread + "```";
			if (bread.length() > 2000) bread = bread.substr(0, 2000);

			nlohmann::json embed = {
				{ "title",  local("broadcast_title") },
				{ "description", bread },
				{ "color", color_embed_default }
			};

			//if (slow_flush_embed(embed, *flush_channel, guild_id, logg)) logg->info("Guild #{} broadcasted message successfully.", guild_id);
			if (here.create_message_embed(data.channel_log, embed)) logg->info("Guild #{} broadcasted message successfully.", here.get_raw_guild().id.get());
			else logg->error("Guild #{} failed to broadcast the message.");

			return true;
		}
		else {
			bread = "***__" + local("broadcast_title") + "__***\n```md\n" + bread + "```";
			if (bread.length() > 2000) bread = bread.substr(0, 2000);

			//if (slow_flush(bread, *flush_channel, guild_id, logg)) logg->info("Guild #{} broadcasted message successfully.", guild_id);
			if (here.create_message(data.channel_log, bread)) logg->info("Guild #{} broadcasted message successfully.", here.get_raw_guild().id.get());
			else logg->error("Guild #{} failed to broadcast the message.");

			return true;
		}
	}
	catch (...) {
		logg->critical("Guild #{} has issue flushing (broadcast, exception). Skipped.", here.get_raw_guild().id.get());
	}
	return false;
}

bool Guild::force_flush_buffer()
{
	//if (ON_RESTART) return false;
	/*std::lock_guard<std::recursive_mutex> luck(buf_control);
	if (buff.empty()) {
		return true;
	}
	if (here.create_message(data.channel_log, buff)) {
		logg->info("Guild #{} flushed {} byte(s)", here.get_raw_guild().id.get(), buff.size());
		buff.clear();
		return true;
	}
	return false;*/
	return _force_flush_buffer_custom(buf, data.channel_log);
}

unsigned long long Guild::get_guild_id()
{
	return here.get_raw_guild().id.get();
}

bool Guild::is_guild(const unsigned long long id)
{
	return here.get_raw_guild().id.get() == id;
}

guild_control& Guild::guild_raw()
{
	return here;
}

/*void Guild::handle(aegis::gateway::events::message_create& e)
{
	//AutoLockluckyness(working_on);

	if (!is_chat_valid(e.channel.get_id())) return;

	//if (check_command(e.msg.get_content(), e.channel, e.msg.author.id))
	//	logg->info("[ASYNC] Tasked command message create block.");
	check_command(e.msg.get_content(), e.channel, e.msg.author.id);


	std::string extra;
	for (size_t count = 0; count < e.msg.attachments.size(); count++) extra += "\n > " + e.msg.attachments[count].filename + " (" + e.msg.attachments[count].url + ")";

	each_block b;
	b.title = "```md\n[" + std::to_string(e.msg.author.id) + "](" + (e.msg.author.username) + "#" + (e.msg.author.discriminator) + ")```";
	b.subtitle = "`[" + e.msg.timestamp + "]<m" + std::to_string(e.msg.get_id()) + "@" + std::to_string(e.msg.get_channel_id()) + ">(" + e.channel.get_name() + ")`**:** ";
	b.content = _fix_content(e.msg.get_content()) + extra + '\n';
	b.user_id = e.msg.author.id;
	if (b.has_emd = (e.msg.embeds.size() > 0)) b.emb = e.msg.embeds[0];

	
		
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked message create block.");
}

void Guild::handle(aegis::gateway::events::message_update& e)
{
	//AutoLockluckyness(working_on);

	if (!is_chat_valid(e.channel.get_id())) return;

	each_block b;
	b.title = "```md\n[" + std::to_string(e.msg.author.id) + "](" + (e.msg.author.username) + "#" + (e.msg.author.discriminator) + ")```";
	b.subtitle = "`[" + e.msg.timestamp + "]<m" + std::to_string(e.msg.get_id()) + "@" + std::to_string(e.msg.get_channel_id()) + ">(" + e.channel.get_name() + ")`**:** ";
	b.content = _fix_content(e.msg.get_content()) + " `<- " + local("edited_message") + "`\n";
	b.user_id = e.msg.author.id;
	if (b.has_emd = (e.msg.embeds.size() > 0)) b.emb = e.msg.embeds[0];
		
		
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked message update block.");
}

void Guild::handle(aegis::gateway::events::message_reaction_add& e)
{
	//AutoLockluckyness(working_on);

	if (!is_chat_valid(e.channel_id)) return;

	auto usr = get_member(e.user_id);
	auto chh = core->channel_create(e.channel_id);
	auto msg = chh->get_message(e.message_id).get();

	each_block b;
	b.title = "```md\n[" + std::to_string(usr.user.id.get()) + "](" + (usr.nick.get()) + ")```";
	b.subtitle = "`[" + msg.timestamp + "]<m" + std::to_string(e.message_id) + "@" + std::to_string(e.channel_id) + ">(" + chh->get_name() + ")` ";
	b.content =  msg.get_content() + " `<- " + local("reacted_with") + "` " + format_emoji(e.emoji) + "\n";
	b.user_id = e.user_id;
		
		
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked reaction add block.");
}

void Guild::handle(aegis::gateway::events::message_reaction_remove& e)
{
	//AutoLockluckyness(working_on);

	if (!is_chat_valid(e.channel_id)) return;

	auto usr = get_member(e.user_id);
	auto chh = core->channel_create(e.channel_id);
	auto msg = chh->get_message(e.message_id).get();

	each_block b;
	b.title = "```md\n[" + std::to_string(usr.user.id.get()) + "](" + (usr.nick.get()) + ")```";
	b.subtitle = "`[" + msg.timestamp + "]<m" + std::to_string(e.message_id) + "@" + std::to_string(e.channel_id) + ">(" + chh->get_name() + ")` ";
	b.content = msg.get_content() + " `<- " + local("removed_reaction") + "` " + format_emoji(e.emoji) + "\n";
	b.user_id = e.user_id;
		
		
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked reaction remove block.");
}

void Guild::handle(aegis::gateway::events::message_delete& e)
{
	if (!data.deep_data) return;
	//AutoLockluckyness(working_on);

	if (!is_chat_valid(e.channel.get_id())) return;

	each_block b;
	b.title = "```css\n[" + local("message_t") + "](" + local("delete_t") + ")```";
	b.subtitle = "`<m" + std::to_string(e.id) + "@" + std::to_string(e.channel.get_id()) + ">(" + e.channel.get_name() + ")` ";
	b.content = " `<- " + local("del") + "`\n";
	b.user_id = 0;
		
		
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked message delete block.");
}

void Guild::handle(aegis::gateway::events::channel_create& e)
{
	if (!data.deep_data) return;
	//AutoLockluckyness(working_on);

	if (!is_chat_valid(e.channel.id)) return;

	bool is_voice = e.channel.type == aegis::gateway::objects::channel::channel_type::Voice;
	each_block b;
	b.subtitle = "\n> " + (e.channel.parent_id ? ("<#" + std::to_string(e.channel.parent_id) + "> / ") : "") + (is_voice ? " " : "<#" + std::to_string(e.channel.id) + "> ") + "(" + e.channel.name + ")\n";

	switch (e.channel.type) {
	case aegis::gateway::objects::channel::channel_type::Category:
		b.title = "```css\n[" + local("category_t") + "](" + local("create_t") + ")```";
		break;
	case aegis::gateway::objects::channel::channel_type::Text:
		b.title = "```css\n[" + local("channel_t") + "](" + local("create_t") + ")```";
		if (e.channel.topic.length()) b.subtitle += local("topic", true) + ":\n```\n" + _fix_content(e.channel.topic) + "```";
		b.subtitle += local("nsfw") + ": `" + std::string(e.channel.nsfw ? local("yes") : local("no")) + "`\n";
		break;
	case aegis::gateway::objects::channel::channel_type::Voice:
		b.title = "```css\n[" + local("voice_t") + "](" + local("create_t") + ")```";
		b.subtitle += local("bitrate", true) + ": `" + std::to_string(e.channel.bitrate / 1000) + " kbps`\n";
		b.subtitle += local("user_max", true) + ": `" + std::to_string(e.channel.userlimit) + "`\n";
		break;
	}

	b.user_id = 0;
		
		
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked channel create block.");
}

void Guild::handle(aegis::gateway::events::channel_update& e)
{
	if (!data.deep_data) return;
	//AutoLockluckyness(working_on);

	if (!is_chat_valid(e.channel.id)) return;

	bool is_voice = e.channel.type == aegis::gateway::objects::channel::channel_type::Voice;
	each_block b;
	b.subtitle = "\n> " + (e.channel.parent_id ? ("<#" + std::to_string(e.channel.parent_id) + "> / ") : "") + (is_voice ? " " : "<#" + std::to_string(e.channel.id) + "> ") + "(" + e.channel.name + ")\n";

	switch (e.channel.type) {
	case aegis::gateway::objects::channel::channel_type::Category:
		b.title = "```css\n[" + local("category_t") + "](" + local("update_t") + ")```";
		break;
	case aegis::gateway::objects::channel::channel_type::Text:
		b.title = "```css\n[" + local("channel_t") + "](" + local("update_t") + ")```";
		if (e.channel.topic.length()) b.subtitle += local("topic", true) + ":\n```\n" + _fix_content(e.channel.topic) + "```";
		b.subtitle += local("nsfw") + ": `" + std::string(e.channel.nsfw ? local("yes") : local("no")) + "`\n";
		break;
	case aegis::gateway::objects::channel::channel_type::Voice:
		b.title = "```css\n[" + local("voice_t") + "](" + local("update_t") + ")```";
		b.subtitle += local("bitrate", true) + ": `" + std::to_string(e.channel.bitrate / 1000) + " kbps`\n";
		b.subtitle += local("user_max", true) + ": `" + std::to_string(e.channel.userlimit) + "`\n";
		break;
	}

	b.user_id = 0;

			
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked channel update block.");
}


void Guild::handle(aegis::gateway::events::channel_delete& e)
{
	if (!data.deep_data) return;
	//AutoLockluckyness(working_on);

	if (!is_chat_valid(e.channel.id)) return;

	bool is_voice = e.channel.type == aegis::gateway::objects::channel::channel_type::Voice;
	each_block b;
	b.subtitle = "\n> " + (e.channel.parent_id ? ("<#" + std::to_string(e.channel.parent_id) + "> / ") : "") + (is_voice ? " " : "<#" + std::to_string(e.channel.id) + "> ") + "(" + e.channel.name + ")\n";

	switch (e.channel.type) {
	case aegis::gateway::objects::channel::channel_type::Category:
		b.title = "```css\n[" + local("category_t") + "](" + local("delete_t") + ")```";
		break;
	case aegis::gateway::objects::channel::channel_type::Text:
		b.title = "```css\n[" + local("channel_t") + "](" + local("delete_t") + ")```";
		if (e.channel.topic.length()) b.subtitle += local("topic", true) + ":\n```\n" + _fix_content(e.channel.topic) + "```";
		b.subtitle += local("nsfw") + ": `" + std::string(e.channel.nsfw ? local("yes") : local("no")) + "`\n";
		break;
	case aegis::gateway::objects::channel::channel_type::Voice:
		b.title = "```css\n[" + local("voice_t") + "](" + local("delete_t") + ")```";
		b.subtitle += local("bitrate", true) + ": `" + std::to_string(e.channel.bitrate / 1000) + " kbps`\n";
		b.subtitle += local("user_max", true) + ": `" + std::to_string(e.channel.userlimit) + "`\n";
		break;
	}

	b.user_id = 0;

			
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked channel delete block.");
}
void Guild::handle(aegis::gateway::events::guild_ban_add& e)
{
	//AutoLockluckyness(working_on);

	each_block b;
	b.title = "```css\n[" + local("banned_t") + "]```";
	b.subtitle = u8"🔻 `" + e.user.username + "#" + e.user.discriminator + "` [<@" + std::to_string(e.user.id) + ">, #" + std::to_string(e.user.id) + "]";

	b.user_id = 0;
		
		
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked ban add block.");
}

void Guild::handle(aegis::gateway::events::guild_ban_remove& e)
{
	//AutoLockluckyness(working_on);

	
	//logg->info("[ASYNC] Tasked ban delete block.");
}

void Guild::handle(aegis::gateway::events::guild_role_create& e)
{
	if (!data.deep_data) return;
	//AutoLockluckyness(working_on);

	each_block b;
	b.title = "```css\n[" + local("role_t") + "](" + local("create_t") + ")```";
	b.subtitle += local("role_info", true) + ": <#" + std::to_string(e.role.id) + "> `[" + e.role.name + ", #" + std::to_string(e.role.id) + "]`\n";
	b.subtitle += local("role_color", true) + ": `" + std::to_string(e.role.color) + "`\n";
	b.subtitle += local("role_hoist", true) + ": `" + std::string(e.role.hoist ? local("yes") : local("no")) + "`\n";
	b.subtitle += local("role_managed", true) + ": `" + std::string(e.role.managed ? local("yes") : local("no")) + "`\n";
	b.subtitle += local("role_mentionable", true) + ": `" + std::string(e.role.mentionable ? local("yes") : local("no")) + "`\n";

	b.user_id = 0;
		
		
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked role create block.");
}

void Guild::handle(aegis::gateway::events::guild_role_update& e)
{
	if (!data.deep_data) return;
	//AutoLockluckyness(working_on);

	each_block b;
	b.title = "```css\n[" + local("role_t") + "](" + local("update_t") + ")```";
	b.subtitle += local("role_info", true) + ": <#" + std::to_string(e.role.id) + "> `[" + e.role.name + ", #" + std::to_string(e.role.id) + "]`\n";
	b.subtitle += local("role_color", true) + ": `" + std::to_string(e.role.color) + "`\n";
	b.subtitle += local("role_hoist", true) + ": `" + std::string(e.role.hoist ? local("yes") : local("no")) + "`\n";
	b.subtitle += local("role_managed", true) + ": `" + std::string(e.role.managed ? local("yes") : local("no")) + "`\n";
	b.subtitle += local("role_mentionable", true) + ": `" + std::string(e.role.mentionable ? local("yes") : local("no")) + "`\n";

	b.user_id = 0;
		
		
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked role update block.");
}

void Guild::handle(aegis::gateway::events::guild_role_delete& e)
{
	if (!data.deep_data) return;
	//AutoLockluckyness(working_on);

	each_block b;
	b.title = "```css\n[" + local("role_t") + "](" + local("delete_t") + ")```";
	b.subtitle += local("role_info", true) + ": `[#" + std::to_string(e.role_id) + "]`\n";

	b.user_id = 0;
		
		
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked role delete block.");
}*/

