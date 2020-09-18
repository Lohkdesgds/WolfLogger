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
		en_us.lang["log_desc"]						= u8"setup where to store log (require ID)"; //
		en_us.lang["deeplog_desc"]					= u8"set if it should deeply log or not (normal)"; //
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
		en_us.lang["log_title"]						= u8"log chat"; //
		en_us.lang["alias_title"]					= u8"alias"; //
		en_us.lang["deeplog_title"]					= u8"deep logging"; //
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
		en_us.lang["role_managed"]					= u8"managed"; //
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
		pt_br.lang["log_desc"]						= u8"define onde salvar o log (precisa de um ID)"; //
		pt_br.lang["deeplog_desc"]					= u8"define se deve salvar tudo ou só o básico (normal)"; //
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
		pt_br.lang["log_title"]						= u8"chat de registro"; //
		pt_br.lang["alias_title"]					= u8"apelido"; //
		pt_br.lang["deeplog_title"]					= u8"registrando profundamente"; //
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
		pt_br.lang["role_managed"]					= u8"dirigido"; //
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


aegis::snowflake stdstoulla(std::string str) {
	while (str.length() > 0) if (!std::isdigit(str[0])) str.erase(str.begin()); else break;
	if (str.length() == 0) return 0;
	unsigned long long t;
	if (sscanf_s(str.c_str(), "%llu", &t) == 1) {
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
	if (j.count("deep_data") && !j["deep_data"].is_null()) {
		deep_data = j["deep_data"].get<bool>();
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

	j["channel_log"] = channel_log;
	j["deep_data"] = deep_data;
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
		logg->critical("Guild #{} Guild::trycatch_auto: failed aegis. Got error: {}", max_tries, guild_id, e);
	}
	catch (nlohmann::detail::type_error e) {
		logg->error("Guild #{} Guild::trycatch_auto: JSON failed: TYPE ERROR: {}", guild_id, e.what());
	}
	catch (nlohmann::detail::invalid_iterator e) {
		logg->error("Guild #{} Guild::trycatch_auto: JSON failed: INVALID ITERATOR ERROR: {}", guild_id, e.what());
	}
	catch (nlohmann::detail::parse_error e) {
		logg->error("Guild #{} Guild::trycatch_auto: JSON failed: PARSE ERROR: {}", guild_id, e.what());
	}
	catch (nlohmann::detail::out_of_range e) {
		logg->error("Guild #{} Guild::trycatch_auto: JSON failed: OUT OF RANGE ERROR: {}", guild_id, e.what());
	}
	catch (nlohmann::detail::other_error e) {
		logg->error("Guild #{} Guild::trycatch_auto: JSON failed: OTHER ERROR: {}", guild_id, e.what());
	}
	catch (nlohmann::detail::exception e) {
		logg->error("Guild #{} Guild::trycatch_auto: JSON failed: GENERIC EXCEPTION ERROR: {}", guild_id, e.what());
	}
	catch (std::exception e) {
		logg->critical("Guild #{} Guild::trycatch_auto: failed exception. Got error: {}", guild_id, e.what());
	}
	catch (...) {
		logg->critical("Guild #{} Guild::trycatch_auto: failed. Unknown error.", guild_id);
	}
	return false;
}

void Guild::load_config()
{
	std::string pathh = "servers/" + std::to_string(guild_id) + "_log.wolflogv2";

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

		logg->info("Guild #{} loaded config successfully.", guild_id);

		fclose(fp);
	}
	else {
		logg->info("Guild #{} couldn't find the config file (new?).", guild_id);
	}
}

void Guild::save_config()
{
	std::string pathh = "servers/" + std::to_string(guild_id) + "_log.wolflogv2";

	FILE* fp = nullptr;
	if (fopen_s(&fp, pathh.c_str(), "wb") == 0) {

		auto j = data.export_config();

		auto cpy = j.dump();
		fwrite(cpy.c_str(), sizeof(char), cpy.length(), fp);

		fclose(fp);
	}
}

void Guild::refresh_flush_channel()
{
	if (!thus) return;
	flush_channel = thus->get_channel(data.channel_log);
}

void Guild::refresh_language(const std::string str)
{
	try {
		lng = langs.get_lang(str);
		data.region = str;
	}
	catch (...) {
		logg->error("Guild #{} failed to get language (exception)!", guild_id);
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
			logg->critical("Guild #{} CRITICAL ERROR: CANNOT GET LANGUAGE!", guild_id);
			return "ERRR";
		}
	}
}

bool Guild::_flush_custom(const std::string s, const bool check_size_recursiv)
{
	//if (ON_RESTART) return false;
	if (!flush_channel) {
		logg->warn("Guild #{} has not a FLUSH channel set! Trying to recover...", guild_id);
		refresh_flush_channel();
		if (!flush_channel) {
			logg->critical("Guild #{} still has NO FLUSH CHANNEL set!", guild_id);
			return false;
		}
	}

	if (check_size_recursiv && s.length() < min_len) {
		if (cant_send_send_dots_then) {
			return slow_flush(u8" `...` ", *flush_channel, guild_id, logg);
		}
		else return false;
	}

	if (s.length() > max_len) {
		auto widenn = widen(s); // utf8 should become one.
			
		const size_t each_slice_len = (max_len / sizeof(wchar_t) - 1);

		for (size_t p = 0; p * each_slice_len < widenn.length(); p++) {
			if (!slow_flush(narrow(widenn.substr(p * each_slice_len, each_slice_len)), *flush_channel, guild_id, logg)) {
				slow_flush(u8" `...(can't read, sorry)...` ", *flush_channel, guild_id, logg); // failed somehow
			}
		}
		return true;
	}
	return slow_flush(s, *flush_channel, guild_id, logg);
}

void Guild::flush_one_block(each_block i)
{
	std::lock_guard<std::recursive_mutex> luck(buf_control);

	if (last_user != i.user_id || !i.user_id) {
		auto title_gen = i.generate_title();
		if (buf.length() + title_gen.length() > max_len) {
			logg->info("Guild #{} flushed {} byte(s)", guild_id, buf.size());
			if (!force_flush_buffer()) {
				logg->critical("Guild #{} FAILED TO SEND BUFFER! ABORT MESSAGE!", guild_id);
				return;
			}
		}
		buf += title_gen;
		last_user = i.user_id;
	}

	auto content_gen = i.generate();

	if (buf.length() + content_gen.length() > max_len) {
		logg->info("Guild #{} flushed {} byte(s)", guild_id, buf.size());
		if (!force_flush_buffer()) {
			logg->critical("Guild #{} FAILED TO SEND BUFFER! ABORT MESSAGE!", guild_id);
			return;
		}
	}
	buf += content_gen;

	if (i.has_emd) { // has to flush latest so embed can be sent
		logg->info("Guild #{} flushed {} byte(s)", guild_id, buf.size());
		if (!force_flush_buffer()) {
			logg->critical("Guild #{} FAILED TO SEND BUFFER! ABORT MESSAGE!", guild_id);
			return;
		}

		if (flush_channel->perms().can_embed()) {
			if (!slow_flush_embed(i.emb, *flush_channel, guild_id, logg)) {
				logg->critical("Guild #{} FAILED TO SEND EMBED BUFFER! ABORT MESSAGE!", guild_id);
				return;
			}
			else logg->info("Guild #{} flushed one embed.", guild_id);
		}
		else {
			nlohmann::json j = i.emb;
			std::string emb_str = u8"Can't send embed. Please allow links. The embed JSON is:\n" + j.dump(2);
			emb_str = emb_str.substr(0, max_len);
			logg->info("Guild #{} flushed {} byte(s)", guild_id, emb_str.size());
			if (!_flush_custom(emb_str)) {
				logg->critical("Guild #{} FAILED TO SEND BUFFER! ABORT MESSAGE!", guild_id);
				return;
			}
		}
	}
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

bool Guild::is_chat_valid(const aegis::snowflake id)
{
	if (!data.channel_log) return false;

	for (auto& i : data.ignore_channels) {
		if (i == id) {
			return false;
		}
	}
	return true;
}

bool Guild::is_user_admin(const aegis::snowflake id)
{
	if (!thus) return false;
	if (id == thus->get_owner() || id == mee_dev) return true;
	aegis::user* usr = core->user_create(id);
	if (!usr) return false;
	auto hmm = usr->get_guild_info(guild_id).roles;

	for (auto& i : data.adm_tags) {
		for (auto& j : hmm) {
			if (j == i) {
				return true;
			}
		}
	}
	return false;
}

void Guild::send_message_default(aegis::channel& ch, std::string content, bool succeed, std::string custom_title, int color)
{
	if (ch.perms().can_embed()) {
		nlohmann::json embed = {
			{ "title",  custom_title.empty() ? (succeed ? local("success", true) : local("failed", true)) : custom_title },
			{ "description", content.substr(0, 2048) },
			{ "color", color }
		};
		aegis::channel* autoref = core->find_channel(ch.get_id()); // make sure it is a valid pointer
		if (autoref) core->async([&, embed, autoref] {slow_flush_embed(embed, *autoref, guild_id, logg); });// .then([&] {logg->info("[ASYNC] Tasked send_message_default block."); });
		else logg->critical("[SMD] Guild #{}: Once in existance chat just got deleted / disappeared!", guild_id);
	}
	else {
		aegis::channel* autoref = core->find_channel(ch.get_id()); // make sure it is a valid pointer
		if (autoref) core->async([&, content, custom_title, autoref] {slow_flush(("**" + custom_title + "**\n" + content).substr(0, 2000), *autoref, guild_id, logg); });// .then([&] {logg->info("[ASYNC] Tasked send_message_default block."); });
		else logg->critical("[SMD] Guild #{}: Once in existance chat just got deleted / disappeared!", guild_id);
	}
}

void Guild::command(std::vector<std::string> args, aegis::channel& ch)
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
				local("log_title", true) + ": <#" + std::to_string(data.channel_log) + ">\n" +
				local("alias_title", true) + ": " + data.alias_cmd + "\n" +
				local("deeplog_title", true) + ": " + std::string(data.deep_data ? local("yes") : local("no"));

			if (data.ignore_channels.size() > 0) {

				if (combo.length() > 1536) {
					send_message_default(ch, combo, true);
					combo.clear();
				}

				combo += "\n" + local("nolook_title", true) + ":";
				for (auto& i : data.ignore_channels) {
					combo += u8"\n- <#" + std::to_string(i) + u8">";
				}
			}
			if (data.adm_tags.size() > 0) {

				if (combo.length() > 1536) {
					send_message_default(ch, combo, true);
					combo.clear();
				}

				combo += u8"\n" + local("adminroles_title", true) + ":";
				for (auto& i : data.adm_tags) {
					combo += u8"\n- <@&" + std::to_string(i) + u8">";
				}
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
						send_message_default(ch, local("success", true), true);
						data.channel_log = val;
						save_config();
						fail = false;
					}
				}
			}
			if (fail) send_message_default(ch, local("failed", true), false);
		}

		// - > - > - > - > - > - > - > LOG < - < - < - < - < - < - < - //
		else if (cmd == local("deeplog")) {
			
			data.deep_data = !data.deep_data;
			send_message_default(ch,
				local("deeplog_title", true) + " -> " +
				std::string(data.deep_data ? local("enabled", true) : local("disabled", true)), true);
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
					}
				}
				else { // ADD

					combo = local("list_success", true) + "\n";

					for (size_t p = 1; p < args.size(); p++) {
						auto val = stdstoulla(args[p]);
						if (val) {
							bool found = false;
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
					}
				}
				else { // ADD

					combo = local("list_success", true) + "\n";

					for (size_t p = 1; p < args.size(); p++) {
						auto val = stdstoulla(args[p]);
						if (val) {
							bool found = false;
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
			if (thus) {
				std::string regg;
				if (args.size() > 1) regg = args[1];
				else regg = thus->get_region();

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

			int64_t guild_count = core->get_guild_count();
			int64_t user_count_unique = core->get_user_count();
			int64_t channel_count = core->get_channel_count();

			int64_t eventsseen = 0;

			for (auto& e : core->message_count)
				eventsseen += e.second;

			std::string members = fmt::format("{}", user_count_unique);
			std::string channels = fmt::format("{}", channel_count);
			std::string guilds = fmt::format("{}", guild_count);
			std::string events = fmt::format("{}", eventsseen);

			std::stringstream w;

			w << u8"[" << local("stats_github", true) << u8"](https://github.com/Lohkdesgds/WolfLogger)\n"
				<< u8"[" << local("stats_discord", true) << u8"](https://discord.gg/JkzJjCG)\n" + common_bar + u8"\n"
				<< local("stats_ram_normal", true) << u8": " << double(aegis::utility::getCurrentRSS()) / div_memory_calc << u8" MB\n"
				<< local("stats_ram_peak", true) << u8": " << double(aegis::utility::getPeakRSS()) / div_memory_calc << u8" MB";


			std::string stats = common_bar + u8"\n" + w.str() + u8"\n" + common_bar;
			std::string buffer_len = std::to_string(buf.length()) + "/" + std::to_string(max_len) + " bytes";

			if (ch.perms().can_embed()) {

				nlohmann::json t = {
					{ "title", local("stats_title", true) },
					{ "description", stats },
					{ "color", color_embed_default },
					{ "fields",
					nlohmann::json::array(
						{
							{ { "name", local("stats_members", true) },		{ "value", members },				{ "inline", true } },
							{ { "name", local("stats_channnels", true) },	{ "value", channels },				{ "inline", true } },
							{ { "name", local("stats_uptime", true) },		{ "value", core->uptime_str() },	{ "inline", true } },
							{ { "name", local("stats_guilds", true) },		{ "value", guilds },				{ "inline", true } },
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

				slow_flush_embed(t, ch, guild_id, logg);
			}
			else {

				std::string mm = "***" + local("stats_title", true) + "***\n```\n" +
					stats + "\n" +
					local("stats_members", true)	+ ": " + members + "\n" +
					local("stats_channnels", true)	+ ": " + channels + "\n" +
					local("stats_uptime", true)		+ ": " + core->uptime_str() + "\n" +
					local("stats_guilds", true)		+ ": " + guilds + "\n" +
					local("stats_events", true)		+ ": " + events + "\n" +
					local("stats_buffer", true)		+ ": " + buffer_len + "\n" +
					local("stats_region", true)		+ ": " + data.region + "\n" +
					local("stats_version", true)	+ ": " + version + "\n```";

				slow_flush(mm, ch, guild_id, logg);
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
		if (ch.perms().can_embed()) {

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

			slow_flush_embed(t, ch, guild_id, logg);
		}
		else {
			std::string msg = "*" + local("commands", true) + "*\n```\n" +
				local("flush") + ": " + local("flush_desc") + "\n" +
				local("show") + ": " + local("show_desc") + "\n" +
				local("log") + ": " + local("log_desc") + "\n" +
				local("deeplog") + ": " + local("deeplog_desc") + "\n" +
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

bool Guild::check_command(std::string str, aegis::channel& ch, const aegis::snowflake id)
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
		force_flush_buffer();
	}
	last = now;
}


void Guild::task_welcome_message()
{
	if (!data.deep_data) return;
	auto message = "` - - - - > " + local("wakeup_message") + " < - - - - `";

	core->async([&,message] {_flush_custom(message); }).then([&] {logg->info("[ASYNC] Tasked welcome block."); });
}

void Guild::task_reset_message()
{
	if (!data.deep_data) return;
	auto message = "` - - - - > " + local("rejoin_message") + " < - - - - `";

	core->async([&, message] {_flush_custom(message); }).then([&] {logg->info("[ASYNC] Tasked rejoin block."); });
}

void Guild::task_end_message()
{
	if (!data.deep_data) return;
	auto message = "` - - - - > " + local("shutdown_message") + " < - - - - `";

	_flush_custom(message);
}

Guild::Guild(const aegis::snowflake id, std::shared_ptr<aegis::core> bot/*, std::function<void(void)> giveup*/)
{
	guild_id = id;
	last = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	reassign(bot);
	load_config();
	core->async([&] {refresh_flush_channel(); }); // do later
	core->async([&] {task_welcome_message(); }); // do later	
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

	if (!trycatch_auto([&] {
		aegis::shards::shard* _shard = &core->get_shard_by_guild(guild_id);
		thus = bot->guild_create(guild_id, _shard);
	})) {
		logg->critical("Failed to get Guild #{}! Skipping event.", guild_id);
		thus = nullptr;
		return;
	}
}

void Guild::force_save()
{
	save_config();
	force_flush_buffer();
}

void Guild::welcome_back()
{
	task_reset_message();
}

bool Guild::broadcast(std::string bread)
{
	if (bread.length() == 0) {
		logg->warn("Guild #{} had issue flushing (broadcast, null). Skipped.", guild_id);
		return false;
	}
	if (!data.channel_log) {
		logg->warn("Guild #{} had issue flushing (broadcast, no channel). Skipped.", guild_id);
		return false;
	}

	try {
		if (!flush_channel) refresh_flush_channel();
		if (!flush_channel) {
			logg->critical("Guild #{} could not send broadcast. Invalid flush channel.", guild_id);
		}


		if (flush_channel->perms().can_embed()) {

			bread = "```md\n" + bread + "```";
			if (bread.length() > 2000) bread = bread.substr(0, 2000);

			nlohmann::json embed = {
				{ "title",  local("broadcast_title") },
				{ "description", bread },
				{ "color", color_embed_default }
			};

			if (slow_flush_embed(embed, *flush_channel, guild_id, logg)) logg->info("Guild #{} broadcasted message successfully.", guild_id);
			else logg->error("Guild #{} failed to broadcast the message.");

			return true;
		}
		else {
			bread = "***__" + local("broadcast_title") + "__***\n```md\n" + bread + "```";
			if (bread.length() > 2000) bread = bread.substr(0, 2000);

			if (slow_flush(bread, *flush_channel, guild_id, logg)) logg->info("Guild #{} broadcasted message successfully.", guild_id);
			else logg->error("Guild #{} failed to broadcast the message.");

			return true;
		}
	}
	catch (...) {
		logg->critical("Guild #{} has issue flushing (broadcast, exception). Skipped.", guild_id);
	}
	return false;
}

bool Guild::force_flush_buffer()
{
	//if (ON_RESTART) return false;
	std::lock_guard<std::recursive_mutex> luck(buf_control);
	if (buf.empty()) {
		return true;
	}
	if (_flush_custom(buf)) {
		buf.clear();
		return true;
	}
	return false;
}

aegis::snowflake Guild::get_guild_id()
{
	return guild_id;
}

bool Guild::is_guild(const aegis::snowflake id)
{
	return guild_id == id;
}

void Guild::handle(aegis::gateway::events::message_create& e)
{
	AutoLock luckyness(working_on);

	if (!is_chat_valid(e.channel.get_id())) return;

	/*if (check_command(e.msg.get_content(), e.channel, e.msg.author.id))
		logg->info("[ASYNC] Tasked command message create block.");*/
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
	AutoLock luckyness(working_on);

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
	AutoLock luckyness(working_on);

	if (!is_chat_valid(e.channel_id)) return;

	auto usr = core->user_create(e.user_id);
	auto chh = core->channel_create(e.channel_id);
	auto msg = chh->get_message(e.message_id).get();

	each_block b;
	b.title = "```md\n[" + std::to_string(usr->get_id()) + "](" + (usr->get_username()) + "#" + std::to_string(usr->get_discriminator()) + ")```";
	b.subtitle = "`[" + msg.timestamp + "]<m" + std::to_string(e.message_id) + "@" + std::to_string(e.channel_id) + ">(" + chh->get_name() + ")` ";
	b.content =  msg.get_content() + " `<- " + local("reacted_with") + "` " + format_emoji(e.emoji) + "\n";
	b.user_id = e.user_id;
		
		
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked reaction add block.");
}

void Guild::handle(aegis::gateway::events::message_reaction_remove& e)
{
	AutoLock luckyness(working_on);

	if (!is_chat_valid(e.channel_id)) return;

	auto usr = core->user_create(e.user_id);
	auto chh = core->channel_create(e.channel_id);
	auto msg = chh->get_message(e.message_id).get();

	each_block b;
	b.title = "```md\n[" + std::to_string(usr->get_id()) + "](" + (usr->get_username()) + "#" + std::to_string(usr->get_discriminator()) + ")```";
	b.subtitle = "`[" + msg.timestamp + "]<m" + std::to_string(e.message_id) + "@" + std::to_string(e.channel_id) + ">(" + chh->get_name() + ")` ";
	b.content = msg.get_content() + " `<- " + local("removed_reaction") + "` " + format_emoji(e.emoji) + "\n";
	b.user_id = e.user_id;
		
		
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked reaction remove block.");
}

void Guild::handle(aegis::gateway::events::message_delete& e)
{
	if (!data.deep_data) return;
	AutoLock luckyness(working_on);

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
	AutoLock luckyness(working_on);

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
	AutoLock luckyness(working_on);

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
	AutoLock luckyness(working_on);

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
	AutoLock luckyness(working_on);

	each_block b;
	b.title = "```css\n[" + local("banned_t") + "]```";
	b.subtitle = u8"🔻 `" + e.user.username + "#" + e.user.discriminator + "` [<@" + std::to_string(e.user.id) + ">, #" + std::to_string(e.user.id) + "]";

	b.user_id = 0;
		
		
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked ban add block.");
}

void Guild::handle(aegis::gateway::events::guild_ban_remove& e)
{
	AutoLock luckyness(working_on);

	each_block b;
	b.title = "```css\n[" + local("unbanned_t") + "]```";
	b.subtitle = u8"🔺 `" + e.user.username + "#" + e.user.discriminator + "` [<@" + std::to_string(e.user.id) + ">, #" + std::to_string(e.user.id) + "]";

	b.user_id = 0;

			
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked ban delete block.");
}

void Guild::handle(aegis::gateway::events::guild_role_create& e)
{
	if (!data.deep_data) return;
	AutoLock luckyness(working_on);

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
	AutoLock luckyness(working_on);

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
	AutoLock luckyness(working_on);

	each_block b;
	b.title = "```css\n[" + local("role_t") + "](" + local("delete_t") + ")```";
	b.subtitle += local("role_info", true) + ": `[#" + std::to_string(e.role_id) + "]`\n";

	b.user_id = 0;
		
		
	flush_one_block(b);
	//logg->info("[ASYNC] Tasked role delete block.");
}
