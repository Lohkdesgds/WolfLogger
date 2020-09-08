#include "handle_guild_easy.h"


bool slow_flush(aegis::create_message_t m, aegis::channel& ch, unsigned long long this_guild_orig) {
	std::this_thread::yield();
	if (m._content.empty()) return false;
	for (size_t tries = 0; tries < 7; tries++) {
		try {
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			ch.create_message(m).get();
			/*std::this_thread::sleep_for(std::chrono::milliseconds(800));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();*/
			return true;
		}
		catch (aegis::error e) {
			logging.print("[Local][", tries + 1, "/7] Guild #", this_guild_orig, " SlowFlush couldn't send message. Got error: ", e);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (std::exception e) {
			logging.print("[Local][", tries + 1, "/7] Guild #", this_guild_orig, " SlowFlush couldn't send message. Got error: ", e);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (...) {
			logging.print("[Local][", tries + 1, "/7] Guild #", this_guild_orig, " SlowFlush couldn't send message. Unknown error.");
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
	}
	return false;
}

bool slow_flush(std::string str, aegis::channel& ch, unsigned long long this_guild_orig) {
	return slow_flush(aegis::create_message_t().content(str), ch, this_guild_orig);
}

bool slow_flush_embed(nlohmann::json emb, aegis::channel& ch, unsigned long long this_guild_orig) {
	if (emb.empty()) return false;
	std::this_thread::yield();
	for (size_t tries = 0; tries < 7; tries++) {
		try {
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			ch.create_message_embed({}, emb).get();
			/*std::this_thread::sleep_for(std::chrono::milliseconds(800));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();*/
			return true;
		}
		catch (aegis::error e) {
			logging.print("[Local][", tries + 1, "/7] Guild #", this_guild_orig, " SlowFlushEmbed couldn't send message. Got error: ", e);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (std::exception e) {
			logging.print("[Local][", tries + 1, "/7] Guild #", this_guild_orig, " SlowFlushEmbed couldn't send message. Got error: ", e);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (...) {
			logging.print("[Local][", tries + 1, "/7] Guild #", this_guild_orig, " SlowFlushEmbed couldn't send message. Unknown error.");
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
	}
	return false;
}

bool slow_flush_embed(aegis::gateway::objects::embed emb, aegis::channel& ch, unsigned long long this_guild_orig) {
	std::this_thread::yield();
	for (size_t tries = 0; tries < 7; tries++) {
		try {
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
			ch.create_message_embed({}, emb).get();
			/*std::this_thread::sleep_for(std::chrono::milliseconds(800));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();*/
			return true;
		}
		catch (aegis::error e) {
			logging.print("[Local][", tries + 1, "/7] Guild #", this_guild_orig, " SlowFlushEmbed couldn't send message. Got error: ", e);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (std::exception e) {
			logging.print("[Local][", tries + 1, "/7] Guild #", this_guild_orig, " SlowFlushEmbed couldn't send message. Got error: ", e);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
		catch (...) {
			logging.print("[Local][", tries + 1, "/7] Guild #", this_guild_orig, " SlowFlushEmbed couldn't send message. Unknown error.");
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (size_t p = 0; p < 4; p++) std::this_thread::yield();
		}
	}
	return false;
}



nlohmann::json* Languages::getLang(const std::string idiom)
{
	std::lock_guard<std::mutex> keep(langs.mut);

	for (size_t p = 0; p < langs.dict.size(); p++) {
		if (langs.dict[p].first == idiom)
			return &langs.dict[p].second;
	}

	// not found, create new

	nlohmann::json lang;

	if (idiom == "brazil") {
			lang["yes"]						= u8"sim";
			lang["no"]						= u8"não";

			lang["enabled"]					= u8"habilitado";
			lang["disabled"]				= u8"desabilitado";

			lang["flush"]					= u8"flush";
			lang["show"]					= u8"mostrar";
			lang["log"]						= u8"registro";
			lang["deeplog"]					= u8"registrarprofundamente";
			lang["nolook"]					= u8"nãover";
			lang["delnolook"]				= u8"removernãover";
			lang["addroleadmin"]			= u8"addtagadmin";
			lang["delroleadmin"]			= u8"removertagadmin";
			lang["help"]					= u8"ajuda";
			lang["language"]				= u8"idioma";
			lang["ping"]					= u8"ping";
			lang["stats"]					= u8"estado";
			lang["alias"]					= u8"alias";

			lang["commands"]				= u8"Comandos disponíveis";

			lang["flush_desc"]				= u8"libera todos os bytes em memória (do log)";
			lang["show_desc"]				= u8"mostra as configurações atuais";
			lang["log_desc"]				= u8"define o chat onde deve registrar eventos do chat (passe ID)";
			lang["deeplog_desc"]			= u8"define se deve monitorar profundamente ou só o normal";
			lang["nolook_desc"]				= u8"deixa de monitorar um chat (passe um ou mais ID(s))";
			lang["delnolook_desc"]			= u8"volta a monitorar o chat (passe um ou mais ID(s))";
			lang["addroleadmin_desc"]		= u8"adiciona uma tag para usar esses comandos (passe um ou mais ID(s))";
			lang["delroleadmin_desc"]		= u8"remove a tag das permitidas a usar esses comandos (passe um ou mais ID(s))";
			lang["help_desc"]				= u8"mostra esse menu de ajuda";
			lang["language_desc"]			= u8"atualiza o idioma do bot baseado na localização do servidor";
			lang["ping_desc"]				= u8"responde de volta sem fazer mais nada";
			lang["stats_desc"]				= u8"estado e informações do bot";
			lang["alias_desc"]				= u8"forma alternativa pra chamar o bot (ex: ^)";

			lang["flushed"]					= u8"Memória liberada";
			lang["pong"]					= u8"Pong!";

			lang["config_title"]			= u8"Configurações";
			lang["log_title"]				= u8"Chat de log";
			lang["alias_title"]				= u8"Alias";
			lang["deeplog_title"]			= u8"Registro profundo";
			lang["nolook_title"]			= u8"Canais sem monitoramento";
			lang["adminroles_title"]		= u8"Tags com permissões";

			lang["success"]					= u8"Sucesso";
			lang["failed"]					= u8"Algo deu errado";
			lang["no_embed_available"]		= u8"Algo deu errado! Sem permissão pra embeds (links)";

			lang["list_success"]			= u8"A lista foi atualizada com sucesso";

			lang["new"]						= u8"novo(s)";
			lang["del"]						= u8"removido(s)";

			lang["edited_message"]			= u8"editou mensagem";
				
			lang["message_t"]				= u8"MENSAGEM";
			lang["channel_t"]				= u8"CANAL";
			lang["role_t"]					= u8"TAG";

			lang["delete_t"]				= u8"APAGOU";
			lang["update_t"]				= u8"MODIFICOU";
			lang["new_t"]					= u8"NOVO";

			lang["reacted_with"]			= u8"reagiu com";
			lang["removed_reaction"]		= u8"removeu reação";

			lang["name"]					= u8"Nome";
			lang["nsfw"]					= u8"NSFW";
			lang["audio"]					= u8"Áudio";
			lang["topic"]					= u8"Tópico";

			lang["banned"]					= u8"Banido";
			lang["unbanned"]				= u8"Desbanido";

			lang["shutdown_message"]		= u8"Desculpe, o WolfLogger foi desligado aqui (provavelmente pra uma update).";
			lang["wakeup_message"]			= u8"WolfLogger está de volta.";
			lang["rejoin_message"]			= u8"O Discord reiniciou a conexão. WolfLogger está de volta.";

			//lang["stats_line_0"]			= u8"Essa é a shard # {} de {}";
			lang["stats_line_1"]			= u8"Última versão do bot";
			lang["stats_line_2"]			= u8"Grupo oficial do bot";
			lang["stats_line_3"]			= u8"Uso de memória";
			lang["stats_line_4"]			= u8"Uso de memória máximo";
				
			lang["stats_title"]				= u8"__Informações__";

			lang["stats_member"]			= u8"Membros";
			lang["stats_channn"]			= u8"Canais";
			lang["stats_uptime"]			= u8"Ligado há";
			lang["stats_guilds"]			= u8"Guilds";
			lang["stats_events"]			= u8"Eventos vistos";
			lang["stats_buffer"]			= u8"Tamanho do buffer";
			lang["stats_region"]			= u8"Última região salva";

			lang["stats_footer"]			= u8"Feito em C++{} com {}";

	}
	else // ENGLISH
	{ 
			lang["yes"]						= u8"yes";
			lang["no"]						= u8"no";

			lang["enabled"]					= u8"enabled";
			lang["disabled"]				= u8"disabled";

			lang["flush"]					= u8"flush";
			lang["show"]					= u8"show";
			lang["log"]						= u8"log";
			lang["deeplog"]					= u8"deeplog";
			lang["nolook"]					= u8"dontlook";
			lang["delnolook"]				= u8"deldontlook";
			lang["addroleadmin"]			= u8"addroleadmin";
			lang["delroleadmin"]			= u8"delroleadmin";
			lang["help"]					= u8"help";
			lang["language"]				= u8"language";
			lang["ping"]					= u8"ping";
			lang["stats"]					= u8"stats";
			lang["alias"]					= u8"alias";

			lang["commands"]				= u8"Commands available";

			lang["flush_desc"]				= u8"flushes the memory (log buffer)";
			lang["show_desc"]				= u8"show all the settings";
			lang["log_desc"]				= u8"setup where to store log (require ID)";
			lang["deeplog_desc"]			= u8"set if it should deeply log or not (normal)";
			lang["nolook_desc"]				= u8"stop monitoring a chat (require one or more IDs)";
			lang["delnolook_desc"]			= u8"start monitoring a chat again (require one or more IDs)";
			lang["addroleadmin_desc"]		= u8"adds new role to run commands (require one or more IDs)";
			lang["delroleadmin_desc"]		= u8"remove a role from using these commands (require one or more IDs)";
			lang["help_desc"]				= u8"shows this help";
			lang["language_desc"]			= u8"updates language based on server location";
			lang["ping_desc"]				= u8"answers back without doing anything";
			lang["stats_desc"]				= u8"stats and info about the bot";
			lang["alias_desc"]				= u8"alternative way to call the bot (ex: ^)";

			lang["flushed"]					= u8"Flushed memory";
			lang["pong"]					= u8"Pong!";

			lang["config_title"]			= u8"Settings";
			lang["log_title"]				= u8"Log chat";
			lang["alias_title"]				= u8"Alias";
			lang["deeplog_title"]			= u8"DeepLog";
			lang["nolook_title"]			= u8"NoLook chats";
			lang["adminroles_title"]		= u8"Admin tags";

			lang["success"]					= u8"Success";
			lang["failed"]					= u8"Something went wrong";
			lang["no_embed_available"]		= u8"Something went wrong! No permission to send embeds (links)";

			lang["list_success"]			= u8"Updated list successfully";

			lang["new"]						= u8"new";
			lang["del"]						= u8"deleted";

			lang["edited_message"]			= u8"edited message";
				
			lang["message_t"]				= u8"MESSAGE";
			lang["channel_t"]				= u8"CHANNEL";
			lang["role_t"]					= u8"ROLE";

			lang["delete_t"]				= u8"DELETE";
			lang["update_t"]				= u8"UPDATE";
			lang["new_t"]					= u8"NEW";

			lang["reacted_with"]			= u8"reacted with";
			lang["removed_reaction"]		= u8"removed reaction";

			lang["name"]					= u8"Name";
			lang["nsfw"]					= u8"NSFW";
			lang["audio"]					= u8"Audio";
			lang["topic"]					= u8"Topic";

			lang["banned"]					= u8"Banned";
			lang["unbanned"]				= u8"Unbanned";

			lang["shutdown_message"]		= u8"Sorry, WolfLogger got shutdown (probably update).";
			lang["wakeup_message"]			= u8"WolfLogger is back online.";
			lang["rejoin_message"]			= u8"Discord restarted connection. WolfLogger is back online.";

			//lang["stats_line_0"]			= u8"This is the shard # {} of {}";
			lang["stats_line_1"]			= u8"Latest bot source";
			lang["stats_line_2"]			= u8"Official bot server";
			lang["stats_line_3"]			= u8"Memory usage";
			lang["stats_line_4"]			= u8"Peak memory usage";
				
			lang["stats_title"]				= u8"__Stats__";

			lang["stats_member"]			= u8"Members";
			lang["stats_channn"]			= u8"Channels";
			lang["stats_uptime"]			= u8"Uptime";
			lang["stats_guilds"]			= u8"Guilds";
			lang["stats_events"]			= u8"Events seen";
			lang["stats_buffer"]			= u8"Buffer";
			lang["stats_region"]			= u8"Latest region saved";

			lang["stats_footer"]			= u8"Made in C++{} with {}";

	}

	langs.dict.push_back({ idiom, lang });

	return &langs.dict.back().second; // must be at the back
}


void GuildChat::save_settings()
{
	CreateDirectoryA("servers", NULL);

	std::string pathh = "servers/" + std::to_string(guild_id) + "_log.wolflogv2";
	FILE* fpp = nullptr;
	if (fopen_s(&fpp, pathh.c_str(), "wb") == 0) {

		nlohmann::json myjson;

		myjson["last_user"] = mylog.last_user;
		myjson["channel_log"] = mylog.channel_log;
		myjson["deep_data"] = mylog.deep_data;
		myjson["alias_cmd"] = alias_cmd;
		myjson["adm_tags"] = adm_tags;
		myjson["ignore_channels"] = nolook;


		auto cpy = myjson.dump();
		fwrite(cpy.c_str(), sizeof(char), cpy.length(), fpp);

		fclose(fpp);
	}


}
bool GuildChat::load_settings()
{
	nlohmann::json j;

	std::string pathh = "servers/" + std::to_string(guild_id) + "_log.wolflogv2";
	FILE* fpp = nullptr;
	if (fopen_s(&fpp, pathh.c_str(), "rb") == 0) {

		std::string all_buf;
		char quickbuf[256];
		size_t u = 0;
		while (u = fread_s(quickbuf, 256, sizeof(char), 256, fpp)) {
			for (size_t k = 0; k < u; k++) all_buf += quickbuf[k];
		}

		j = nlohmann::json::parse(all_buf);


		if (j.count("last_user") && !j["last_user"].is_null()) {
			mylog.last_user = j["last_user"].get<unsigned long long>();
		}
		if (j.count("channel_log") && !j["channel_log"].is_null()) {
			mylog.channel_log = j["channel_log"].get<unsigned long long>();
		}
		if (j.count("deep_data") && !j["deep_data"].is_null()) {
			mylog.deep_data = j["deep_data"].get<bool>();
		}
		if (j.count("alias_cmd") && !j["alias_cmd"].is_null()) {
			alias_cmd = j["alias_cmd"].get<std::string>();
		}
		if (j.count("adm_tags") && !j["adm_tags"].is_null()) {
			for (auto& i : j["adm_tags"]) adm_tags.push_back(i.get<unsigned long long>());
		}
		if (j.count("ignore_channels") && !j["ignore_channels"].is_null()) {
			for (auto& i : j["ignore_channels"]) nolook.push_back(i.get<unsigned long long>());
		}

		fclose(fpp);
	}
	else { // old way (v1, 20200815)
		std::string path = "servers/" + std::to_string(guild_id) + "_log.wolflog";
		FILE* fp = nullptr;
		if (fopen_s(&fp, path.c_str(), "rb") != 0) { // none found
			return false;
		}
		else {
			if (!fread_s(&mylog, sizeof(mylog), sizeof(data_log), 1, fp)) {
				fclose(fp);
				return false;
			}
			while (!feof(fp)) {
				unsigned long long i;
				if (!fscanf_s(fp, "\n%llu", &i)) break;
				nolook.push_back(i);
			}
			fclose(fp);
		}
	}


	return true;
}
bool GuildChat::flushLanguage()
{
	auto* cpy = idiom;
	auto& shardd = ref->get_shard_by_guild(guild_id);
	auto guild = ref->guild_create(guild_id, &shardd);

	if (guild) {
		if (idiom = source_lang.getLang(guild->get_region())) {
			itsregion = guild->get_region();
			logging.print("[!] Defined new region at guild #", guild_id, ": ", itsregion);
			return true;
		}
	}
	idiom = cpy;
	return false;
}
void GuildChat::buffer_handle(std::string str)
{
	if (!mylog.channel_log) return;
	aegis::channel* ch = ref->channel_create(mylog.channel_log);
	if (!ch) return;

	while (str.length() + buffer_string.length() >= max_len_str) {
			
		auto temp = buffer_string.substr(0, max_len_str);
		if (temp.length()) {
			slow_flush(temp, *ch, guild_id);
			//ch->create_message(temp); // max len
			logging.print("Guild #", guild_id, " has flushed ", temp.length(), " bytes");
		}

		if (buffer_string.length() > max_len_str) buffer_string = buffer_string.substr(max_len_str); //  if bigger than max discord size, save remaining
		else buffer_string.clear(); // if less, sent all, so clear

		if (!str.empty()) buffer_string += str + '\n'; // if str, add
		str.clear(); // clear so no duplicated
	}
	if (!str.empty()) { // sum < max discord len (cause if it was it would be cleared)
		buffer_string += str + '\n';
	}
}
void GuildChat::buffer_flush()
{
	if (buffer_string.length() == 0) return;
	if (!mylog.channel_log) return;
	try {
		aegis::channel* ch = ref->channel_create(mylog.channel_log);
		if (!ch) return;

		while (buffer_string.length()) {
			slow_flush(buffer_string.substr(0, max_len_str > buffer_string.length() ? max_len_str : buffer_string.length()), *ch, guild_id);
			//ch->create_message(buffer_string.substr(0, max_len_str > buffer_string.length() ? max_len_str : buffer_string.length())); // max len

			logging.print("Guild #", guild_id, " has flushed (forced) ", buffer_string.length() > 2000 ? 2000 : buffer_string.length(), " bytes");

			if (buffer_string.length() > max_len_str) buffer_string = buffer_string.substr(max_len_str); //  if bigger than max discord size, save remaining
			else buffer_string.clear(); // if less, sent all, so clear

		}
	}
	catch (...) {
		logging.print("Guild #", guild_id, " has issue flushing (forced). Skipped.");
	}
}
std::string GuildChat::getStrL(const std::string key, const size_t tries)
{
	try {
		return (*idiom)[key].get<std::string>();
	}
	catch (...) {
		logging.print("[!] Error getting language in region ", itsregion);
		idiom = source_lang.getLang(itsregion);
		if (!idiom) return "FATAL ERROR";
	}
	return tries > 0 ? getStrL(key, tries - 1) : "FATAL ERROR LOOP";
}
void GuildChat::command(aegis::channel& ch, std::vector<std::string> arguments)
{
	auto send_message = [&](std::string content, bool succeed, std::string custom_title = "", int color = color_embed_default) {
		if (ch.perms().can_embed()) {
			nlohmann::json embed = {
				{ "title",  custom_title.empty() ? (succeed ? getStrL("success") : getStrL("failed")) : custom_title },
				{ "description", content },
				{ "color", color }
			};
			slow_flush_embed(embed, ch, guild_id);
			//ch.create_message_embed("", embed);
		}
		else {
			slow_flush(content, ch, guild_id);
			//ch.create_message(content);
		}
	};
	auto send_message_embed = [&](nlohmann::json embed) {
		if (ch.perms().can_embed()) {
			slow_flush_embed(embed, ch, guild_id);
			//ch.create_message_embed("", embed);
		}
		else {
			slow_flush(getStrL("no_embed_available"), ch, guild_id);
			//ch.create_message(getStrL("no_embed_available"));
		}
	};

	/*std::vector<std::string> arguments;
	{
		std::string buf;
		for (size_t p = 0; p < slice.length(); p++) {
			auto& i = slice[p];
			if (i != ' ') buf += slice[p];
			else arguments.push_back(std::move(buf));
		}
		if (!buf.empty()) arguments.push_back(std::move(buf));
	}*/

	if (arguments.size() > 0) {
		std::string& e = arguments[0];

		if (e == getStrL("stats")) {
			{
				int64_t guild_count = ref->get_guild_count();
				int64_t user_count_unique = ref->get_user_count();
				int64_t channel_count = ref->get_channel_count();

				int64_t eventsseen = 0;

				for (auto& e : ref->message_count)
					eventsseen += e.second;

				std::string members = fmt::format("{}", user_count_unique);
				std::string channels = fmt::format("{}", channel_count);
				std::string guilds = fmt::format("{}", guild_count);
				std::string events = fmt::format("{}", eventsseen);

				std::stringstream w;
				auto& _shard = ref->get_shard_by_guild(guild_id);

//#if defined(DEBUG) || defined(_DEBUG)
				//std::string misc = fmt::format(getStrL("stats_line_0"), _shard.get_id() + 1, ref->shard_count()); // stats_line_0 has {} {}
				const auto div = (1 << 20);

				w	<< "[" << getStrL("stats_line_1") << "](https://github.com/Lohkdesgds/WolfLogger)\n"
					<< "[" << getStrL("stats_line_2") << "](https://discord.gg/JkzJjCG)\n\n"
					<< getStrL("stats_line_3") << ": " << double(aegis::utility::getCurrentRSS()) / div << " MB\n"
					<< getStrL("stats_line_4") << ": " << double(aegis::utility::getPeakRSS()) / div << " MB";

					
/*#else
				std::string misc = fmt::format("I am shard # {} of {} running on {}", _shard.get_id(), ref->shard_count(), aegis::utility::platform::get_platform());

				w << "[Latest bot source](https://github.com/Lohkdesgds/WolfLogger)\n[Official Bot Server](https://discord.gg/JkzJjCG)\n\nMemory usage: "
					<< double(aegis::utility::getCurrentRSS()) / (1024 * 1024) << " MB\nMax Memory: "
					<< double(aegis::utility::getPeakRSS()) / (1024 * 1024) << " MB";
#endif*/

				std::string stats = w.str();
				std::string buffer_len = std::to_string(buffer_string.length()) + "/" + std::to_string(max_len_str) + " bytes";

				nlohmann::json t = {
					{ "title", getStrL("stats_title") },
					{ "description", stats },
					{ "color", color_embed_default },
					{ "fields",
					nlohmann::json::array(
						{
							{ { "name", getStrL("stats_member") },{ "value", members },{ "inline", true } },
							{ { "name", getStrL("stats_channn") },{ "value", channels },{ "inline", true } },
							{ { "name", getStrL("stats_uptime") },{ "value", ref->uptime_str() },{ "inline", true } },
							{ { "name", getStrL("stats_guilds") },{ "value", guilds },{ "inline", true } },
							{ { "name", getStrL("stats_events") },{ "value", events },{ "inline", true } },
							{ { "name", getStrL("stats_buffer") },{ "value", buffer_len },{ "inline", true } },
							{ { "name", getStrL("stats_region") },{ "value", itsregion },{ "inline", false } }

							//{ { "name", u8"\u200b" },{ "value", u8"\u200b" },{ "inline", true } },// this is clean block lmao
						}
						)
					},
					{ "footer",{ { "icon_url", "https://cdn.discordapp.com/emojis/289276304564420608.png" },{ "text", fmt::format(getStrL("stats_footer"), CXX_VERSION, AEGIS_VERSION_TEXT) } } }
				};

				send_message_embed(t);
			}				
			return;
		}
		if (e == getStrL("alias")) {

			std::string combo;

			if (arguments.size() > 1) {

				alias_cmd = arguments[1];
					
				combo = getStrL("success") + ": \"" + alias_cmd + "\".";
				save_settings();
			}
			if (!combo.empty()) send_message(combo, true);
			else send_message(getStrL("failed"), false);
			return;

			return;
		}
		if (e == getStrL("ping")) {

			send_message(getStrL("pong"), true);
				
			return;
		}
		if (e == getStrL("flush")) {

			send_message(getStrL("flushed"), true);
				
			buffer_flush();
			return;
		}
		if (e == getStrL("show")) {
			std::string combo;

			combo += 
				getStrL("config_title") + ":\n" +
				"- " + getStrL("log_title") + ": <#" + std::to_string(mylog.channel_log) + ">\n" +
				"- " + getStrL("alias_title") + ": " + alias_cmd + "\n" +
				"- " + getStrL("deeplog_title") + ": " + std::string(mylog.deep_data ? getStrL("yes") : getStrL("no"));

			if (nolook.size() > 0) {

				if (combo.length() > 1536) {
					send_message(combo, true);
					combo.clear();
				}

				combo += "\n- " + getStrL("nolook_title") + ":";
				for (auto& i : nolook) {
					combo += u8"\n- <#" + std::to_string(i) + u8"> (ID#" + std::to_string(i) + u8")";
				}
			}
			if (adm_tags.size() > 0) {

				if (combo.length() > 1536) {
					send_message(combo, true);
					combo.clear();
				}

				combo += u8"\n- " + getStrL("adminroles_title") + ":";
				for (auto& i : adm_tags) {
					combo += u8"\n- <@&" + std::to_string(i) + u8"> (ID#" + std::to_string(i) + u8")";
				}
			}

			if (combo.length()) send_message(combo, true);

			return;
		}
		if (e == getStrL("log")) {
			std::string combo;

			if (arguments.size() > 1) {

				std::string cpyy = arguments[1];
				while (cpyy.length() > 0 && (cpyy[0] < '0' || cpyy[0] > '9')) cpyy.erase(cpyy.begin());

				if (sscanf_s(cpyy.c_str(), "%llu", &mylog.channel_log)) {
					combo = getStrL("success") + ": <#" + std::to_string(mylog.channel_log) + u8">.";
					save_settings();
				}
			}
			if (!combo.empty()) send_message(combo, true);
			else send_message(getStrL("failed"), false);
			return;
		}
		if (e == getStrL("deeplog")) {
			mylog.deep_data = !mylog.deep_data;
			send_message(getStrL("deeplog_title") + " -> " + std::string(mylog.deep_data ? getStrL("enabled") : getStrL("disabled")), true);
			save_settings();
			return;
		}
		if (e == getStrL("nolook")) {
			if (arguments.size() > 1) {
				size_t added = 0;
				unsigned long long new_chat_filter;
				for (size_t u = 1; u < arguments.size(); u++) {

					std::string cpyy = arguments[u];
					while (cpyy.length() > 0 && (cpyy[0] < '0' || cpyy[0] > '9')) cpyy.erase(cpyy.begin());

					if (sscanf_s(cpyy.c_str(), "%llu", &new_chat_filter)) {
						if (add_chat_nolook(new_chat_filter)) {
							added++;
						}
					}
				}
				send_message(getStrL("list_success") + "(" + std::to_string(added) + " " + getStrL("new") + ").", true);
				save_settings();
				return;
			}
			send_message(getStrL("failed"), false);
			return;
		}
		if (e == getStrL("delnolook")) {
			if (arguments.size() > 1) {
				size_t removed = 0;
				unsigned long long del_chat_filter;
				for (size_t u = 1; u < arguments.size(); u++) {

					std::string cpyy = arguments[u];
					while (cpyy.length() > 0 && (cpyy[0] < '0' || cpyy[0] > '9')) cpyy.erase(cpyy.begin());

					if (sscanf_s(cpyy.c_str(), "%llu", &del_chat_filter)) {
						if (remove_chat_nolook(del_chat_filter)) removed++;
					}
				}
				send_message(getStrL("list_success") + "(" + std::to_string(removed) + " " + getStrL("del") + ").", true);
				save_settings();
				return;
			}
			send_message(getStrL("failed"), false);
			return;
		}
		if (e == getStrL("addroleadmin")) {
			if (arguments.size() > 1) {
				size_t added = 0;
				unsigned long long new_chat_filter;
				for (size_t u = 1; u < arguments.size(); u++) {

					std::string cpyy = arguments[u];
					while (cpyy.length() > 0 && (cpyy[0] < '0' || cpyy[0] > '9')) cpyy.erase(cpyy.begin());

					if (sscanf_s(cpyy.c_str(), "%llu", &new_chat_filter)) {
						if (add_role_admin(new_chat_filter)) {
							added++;
						}
					}
				}
				send_message(getStrL("list_success") + "(" + std::to_string(added) + " " + getStrL("new") + ").", true);
				save_settings();
				return;
			}
			send_message(getStrL("failed"), false);
			return;
		}
		if (e == getStrL("delroleadmin")) {
			if (arguments.size() > 1) {
				size_t removed = 0;
				unsigned long long del_chat_filter;
				for (size_t u = 1; u < arguments.size(); u++) {

					std::string cpyy = arguments[u];
					while (cpyy.length() > 0 && (cpyy[0] < '0' || cpyy[0] > '9')) cpyy.erase(cpyy.begin());

					if (sscanf_s(cpyy.c_str(), "%llu", &del_chat_filter)) {
						if (remove_role_admin(del_chat_filter)) removed++;
					}
				}
				send_message(getStrL("list_success") + "(" + std::to_string(removed) + " " + getStrL("del") + ").", true);
				save_settings();
				return;
			}
			send_message(getStrL("failed"), false);
			return;
		}
		if (e == getStrL("language")) {
			if (flushLanguage()) {
				send_message(getStrL("success"), true);
			}
			else {
				send_message(getStrL("failed"), false);
			}
			return;
		}
		if (e == "help" || e == getStrL("help")) {

			nlohmann::json t = {
					{ "title", getStrL("commands") },
					{ "color", color_embed_default },
					{ "fields",
					nlohmann::json::array(
						{
							{ { "name", getStrL("flush") },{ "value", "`" + getStrL("flush_desc") + "`" },{ "inline", false } },
							{ { "name", getStrL("show") },{ "value", "`" + getStrL("show_desc") + "`" },{ "inline", false } },
							{ { "name", getStrL("log") },{ "value", "`" + getStrL("log_desc") + "`" },{ "inline", false } },
							{ { "name", getStrL("deeplog") },{ "value", "`" + getStrL("deeplog_desc") + "`" },{ "inline", false } },
							{ { "name", getStrL("nolook") },{ "value", "`" + getStrL("nolook_desc") + "`" },{ "inline", false } },
							{ { "name", getStrL("delnolook") },{ "value", "`" + getStrL("delnolook_desc") + "`" },{ "inline", false } },
							{ { "name", getStrL("addroleadmin") },{ "value", "`" + getStrL("addroleadmin_desc") + "`" },{ "inline", false } },
							{ { "name", getStrL("delroleadmin") },{ "value", "`" + getStrL("delroleadmin_desc") + "`" },{ "inline", false } },
							{ { "name", getStrL("help") },{ "value", "`" + getStrL("help_desc") + "`" },{ "inline", false } },
							{ { "name", getStrL("language") },{ "value", "`" + getStrL("language_desc") + "`" },{ "inline", false } },
							{ { "name", getStrL("ping") },{ "value", "`" + getStrL("ping_desc") + "`" },{ "inline", false } },
							{ { "name", getStrL("stats") },{ "value", "`" + getStrL("stats_desc") + "`" },{ "inline", false } },
							{ { "name", getStrL("alias") },{ "value", "`" + getStrL("alias_desc") + "`" },{ "inline", false } }
						}
						)
					}
			};

			send_message_embed(t);



			/*send_message(
				"^" + getStrL("flush") + " : " + getStrL("flush_desc") + "\n"
				"^" + getStrL("show") + " : " + getStrL("show_desc") + "\n"
				"^" + getStrL("log") + " : " + getStrL("log_desc") + "\n"
				"^" + getStrL("deeplog") + " : " + getStrL("deeplog_desc") + "\n"
				"^" + getStrL("nolook") + " : " + getStrL("nolook_desc") + "\n"
				"^" + getStrL("delnolook") + " : " + getStrL("delnolook_desc") + "\n"
				"^" + getStrL("addroleadmin") + " : " + getStrL("addroleadmin_desc") + "\n"
				"^" + getStrL("delroleadmin") + " : " + getStrL("delroleadmin_desc") + "\n"
				"^" + getStrL("help") + " : " + getStrL("help_desc") + "\n"
				"^" + getStrL("language") + " : " + getStrL("language_desc") + "\n" +
				"^" + getStrL("ping") + " : " + getStrL("ping_desc") + "\n" +
				"^" + getStrL("stats") + " : " + getStrL("stats_desc") + "\n" +
				"^" + getStrL("alias") + " : " + getStrL("alias_desc") + "\n",
				true, getStrL("commands")
			);*/
		}
	}



}
bool GuildChat::remove_chat_nolook(const unsigned long long chid)
{
	for (size_t p = 0; p < nolook.size(); p++) {
		if (nolook[p] == chid) {
			//std::lock_guard<std::mutex> keep(besur);
			nolook.erase(nolook.begin() + p);
			return true;
		}
	}
	return false;
}
bool GuildChat::remove_role_admin(const unsigned long long usid)
{
	for (size_t p = 0; p < adm_tags.size(); p++) {
		if (adm_tags[p] == usid) {
			//std::lock_guard<std::mutex> keep(besur);
			adm_tags.erase(adm_tags.begin() + p);
			return true;
		}
	}
	return false;
}
bool GuildChat::add_chat_nolook(const unsigned long long chid)
{
	if (chat_canlook(chid)) {
		//std::lock_guard<std::mutex> keep(besur);
		nolook.push_back(chid);
		return true;
	}
	return false;
}
bool GuildChat::add_role_admin(const unsigned long long rlid)
{
	for (auto& i : adm_tags) {
		if (i == rlid) {
			return false;
		}
	}
	//std::lock_guard<std::mutex> keep(besur);
	adm_tags.push_back(rlid);
	return true;
}

bool GuildChat::has_admin_rights(aegis::guild& guild, aegis::user& user)
{
	if (user.get_id() == guild.get_owner() || user.get_id() == mee_dev) return true;
		
	auto tags = user.get_guild_info(guild.get_id()).roles;

	//std::lock_guard<std::mutex> keep(besur);
		
	for (auto& i : tags) {
		for (auto& j : adm_tags) {
			if (j == i) {
				return true;
			}
		}
	}
	return false;
}
bool GuildChat::chat_canlook(const unsigned long long chatid)
{
	for (auto& i : nolook) if (i == chatid) return false;
	return chatid != mylog.channel_log;
}
bool GuildChat::user_not_bot_not_null(const unsigned long long userid)
{
	if (ref) {
		return (ref->get_id() != userid && userid != 0);
	}
	return false;
}
GuildChat::GuildChat(std::shared_ptr<aegis::core> core, aegis::guild& uu) // guild_id, shard_id, region, guild
{
	ref = core;
	guild_id = uu.get_id();
	itsregion = uu.get_region();
	idiom = source_lang.getLang(itsregion);

	load_settings();
	/*for (auto& i : uu.get_channels()) {
		if (i.first == mylog.channel_log) {

			if (!i.second) {
				logging.print("[>] Failed to Welcome Guild #", guild_id);
				return;
			}
			welcome_message(*i.second);
			logging.print("[>] Welcome -> Guild #", guild_id);
			return;
		}
	}
	logging.print("[>] No settings found to Guild #", guild_id);*/
	welcome_message();
}
GuildChat::GuildChat(std::shared_ptr<aegis::core> core, aegis::gateway::objects::guild& uu) // guild_id, shard_id, region, guild
{
	ref = core;
	guild_id = uu.id;
	itsregion = uu.region;
	idiom = source_lang.getLang(itsregion);

	load_settings();
	/*for (auto& i : uu.channels) {
		if (i.id == mylog.channel_log) {

			aegis::channel* ch = nullptr;
			for (size_t tries = 0; tries < 15 && !ch; tries++) ch = ref->channel_create(i.id);

			if (!ch) {
				logging.print("[>] Failed to Welcome Guild #", guild_id);
				return;
			}
			welcome_message(*ch);
			//logging.print("[>] Welcome -> Guild #", guild_id);
			return;
		}
	}
	logging.print("[>] No settings found to Guild #", guild_id);*/
	welcome_message();
}
GuildChat::~GuildChat()
{
	// saves file
	end_message();
	logging.print("[>] Closed Guild #", guild_id);
}
void GuildChat::reset()
{
	std::string path = "servers/" + std::to_string(guild_id) + "_log.wolflog";
	std::string path2 = "servers/" + std::to_string(guild_id) + "_log.wolflogv2";
	std::remove(path.c_str());
	std::remove(path2.c_str());
	mylog.channel_log = 0;
	mylog.last_user = 0;
}
bool GuildChat::operator==(const unsigned long long id)
{
	return guild_id == id;
}
void GuildChat::handle_specific(aegis::gateway::events::message_create& obj)
{
	if (user_not_bot_not_null(obj.msg.author.id) && chat_canlook(obj.channel.get_id())) {

		if (obj.msg.get_content().find(main_cmd) == 0 || ((alias_cmd.length() > 0) && obj.msg.get_content().find(alias_cmd) == 0)) {

			if (!has_admin_rights(obj.msg.get_guild(), obj.msg.get_user())) { // adm/owner/me
				slow_flush("You have no permission.", obj.channel, guild_id);
				obj.msg.delete_message();
				return;
			}
			size_t start = obj.msg.get_content().find(main_cmd) == 0 ? main_cmd.length() : alias_cmd.size();

			std::vector<std::string> arguments;

			//arguments.push_back(main_cmd); // this is not used

			const std::string& slice = obj.msg.get_content();
			{
				std::string buf;
				for (size_t p = start; p < slice.length(); p++) {
					auto& i = slice[p];
					if (i != ' ') buf += slice[p];
					else if (!buf.empty()) arguments.push_back(std::move(buf));
				}
				if (!buf.empty()) arguments.push_back(std::move(buf));
			}
			command(obj.channel, arguments);
		}


		const std::string& content = obj.msg.get_content();

		/*if (content.find(alias_cmd) == 0 && content.length() > 1 && has_admin_rights(obj.msg.get_guild(), obj.get_user())) {
			command(obj.msg.get_channel(), content.substr(1));
		}
		*/
		if (mylog.last_user != obj.msg.author.id) {
			buffer_handle("```md\n[" + std::to_string(obj.msg.author.id) + "](" + (obj.msg.author.username) + "#" + (obj.msg.author.discriminator) + ")```");
			mylog.last_user = obj.msg.author.id;
		}

		std::string extra;
		for (size_t count = 0; count < obj.msg.attachments.size(); count++) extra += "\n > " + obj.msg.attachments[count].filename + " (" + obj.msg.attachments[count].url + ")";
		std::string channelname = obj.msg.get_channel().get_name();

		buffer_handle("`[" + obj.msg.timestamp + "]<m" + std::to_string(obj.msg.get_id()) + "@" + std::to_string(obj.msg.get_channel_id()) + ">(" + channelname + ")`**:** " + content + extra);
	}
}
void GuildChat::handle_specific(aegis::gateway::events::message_update& obj)
{
	if (user_not_bot_not_null(obj.msg.author.id) && chat_canlook(obj.channel.get_id())) {

		const std::string& content = obj.msg.get_content();

		auto* fromptr = ref->channel_create(obj.msg.get_channel_id());

		if (mylog.last_user != obj.msg.author.id) {
			buffer_handle("```md\n[" + std::to_string(obj.msg.author.id) + "](" + (obj.msg.author.username) + "#" + (obj.msg.author.discriminator) + ")\n```");
			mylog.last_user = obj.msg.author.id;
		}

		if (fromptr) {
			buffer_handle("`[" + obj.msg.timestamp + "]<m" + std::to_string(obj.msg.get_id()) + "@" + std::to_string(fromptr->get_id()) + ">(" + fromptr->get_name() + ")`**:** " + content
				+ " `<- " + getStrL("edited_message") + "`"
			);
		}
	}
}
void GuildChat::handle_specific(aegis::gateway::events::message_delete& obj)
{
	if (!mylog.deep_data) return;

	buffer_handle("```md\n[" + getStrL("message_t") + "](" + getStrL("delete_t") + ")<" + std::to_string(obj.id) + " @ " + std::to_string(obj.channel.get_id()) + ">```");
	mylog.last_user = 0;
}
void GuildChat::handle_specific(aegis::gateway::events::message_reaction_add& obj)
{
	if (user_not_bot_not_null(obj.user_id) && chat_canlook(obj.channel_id)) {

		auto* usrptr = ref->user_create(obj.user_id);

		if (usrptr) if (usrptr->is_bot()) return;

		auto* thsch = ref->channel_create(obj.channel_id);

		if (mylog.last_user != obj.user_id) {
			if (usrptr) {
				buffer_handle("```md\n[" + std::to_string(usrptr->get_id()) + "](" + (usrptr->get_full_name()) + ")\n```");
				mylog.last_user = usrptr->get_id();
			}
		}

		if (thsch) {
			std::string autoemoji = obj.emoji.id != 0 ? ((obj.emoji.animated ? u8"<a:" : u8"<:") + obj.emoji.name + u8":" + std::to_string(obj.emoji.id) + u8">") : obj.emoji.name;

			thsch->get_message(obj.message_id).then(
				[&, autoemoji](aegis::gateway::objects::message m) {
					buffer_handle("`[" + m.timestamp + "]<m" + std::to_string(m.get_id()) + "@" + std::to_string(m.get_channel_id()) + ">(" + m.get_channel().get_name() + ")`**:** " + m.get_content()
						+ " `<- " + getStrL("reacted_with") + "` " + autoemoji
					);
				}
			);
		}
	}
}
void GuildChat::handle_specific(aegis::gateway::events::message_reaction_remove& obj)
{
	if (user_not_bot_not_null(obj.user_id) && chat_canlook(obj.channel_id)) {

		auto* usrptr = ref->user_create(obj.user_id);

		if (usrptr) if (usrptr->is_bot()) return;

		auto* thsch = ref->channel_create(obj.channel_id);

		if (mylog.last_user != obj.user_id) {
			if (usrptr) {
				buffer_handle("```md\n[" + std::to_string(usrptr->get_id()) + "](" + (usrptr->get_full_name()) + ")\n```");
				mylog.last_user = usrptr->get_id();
			}
		}

		if (thsch) {

			std::string autoemoji = obj.emoji.id != 0 ? ((obj.emoji.animated ? u8"<a:" : u8"<:") + obj.emoji.name + u8":" + std::to_string(obj.emoji.id) + u8">") : obj.emoji.name;

			thsch->get_message(obj.message_id).then(
				[&, autoemoji](aegis::gateway::objects::message m) {
					buffer_handle("`[" + m.timestamp + "]<m" + std::to_string(m.get_id()) + "@" + std::to_string(m.get_channel_id()) + ">(" + m.get_channel().get_name() + ")`**:** " + m.get_content()
						+ " `<- " + getStrL("removed_reaction") + "` " + autoemoji
					);
				}
			);
		}
	}
}
void GuildChat::handle_specific(aegis::gateway::events::channel_create& obj)
{
	if (!mylog.deep_data) return;

	buffer_handle(u8"```md\n[" + getStrL("channel_t") + "](" + getStrL("new_t") + ")```\nID=" + std::to_string(obj.channel.id) + u8";" + getStrL("name") + "=" + obj.channel.name +
		u8";" + getStrL("nsfw") + "=" + (obj.channel.nsfw ? getStrL("yes") : getStrL("no")) + u8";" + getStrL("audio") + "?" + (obj.channel.bitrate > 0 ? (std::to_string(obj.channel.bitrate) + u8"bps") : u8"---") +
		u8"\n" + (obj.channel.topic.length() > 0 ? (getStrL("topic") + ":\n```\n" + obj.channel.topic + "\n```") : ""));
	mylog.last_user = 0;
}
void GuildChat::handle_specific(aegis::gateway::events::channel_update& obj)
{
	if (!mylog.deep_data) return;

	buffer_handle(u8"```md\n[" + getStrL("channel_t") + "](" + getStrL("new_t") + ")```\nID=" + std::to_string(obj.channel.id) + u8";" + getStrL("name") + "=" + obj.channel.name +
		u8";" + getStrL("nsfw") + "=" + (obj.channel.nsfw ? getStrL("yes") : getStrL("no")) + u8";" + getStrL("audio") + "?" + (obj.channel.bitrate > 0 ? (std::to_string(obj.channel.bitrate) + u8"bps") : u8"---") +
		u8"\n" + (obj.channel.topic.length() > 0 ? (getStrL("topic") + ":\n```\n" + obj.channel.topic + "\n```") : ""));
	/*u8"```md\n[" + getStrL("channel_t") + "](" + getStrL("new_t") + ")```\nID=" + std::to_string(obj.channel.id) + u8";NOME=" + obj.channel.name +
	u8";NSFW=" + (obj.channel.nsfw ? u8"S" : u8"N") + u8";AUDIO?" + (obj.channel.bitrate > 0 ? (std::to_string(obj.channel.bitrate) + u8"bps") : u8"---") +
	u8"\n- Tópico:\n```" + obj.channel.topic + "\n```");*/
	mylog.last_user = 0;
}
void GuildChat::handle_specific(aegis::gateway::events::channel_delete& obj)
{
	if (!mylog.deep_data) return;

	buffer_handle(u8"```md\n[" + getStrL("channel_t") + "](" + getStrL("new_t") + ")```\nID=" + std::to_string(obj.channel.id) + u8";" + getStrL("name") + "=" + obj.channel.name +
		u8";" + getStrL("nsfw") + "=" + (obj.channel.nsfw ? getStrL("yes") : getStrL("no")) + u8";" + getStrL("audio") + "?" + (obj.channel.bitrate > 0 ? (std::to_string(obj.channel.bitrate) + u8"bps") : u8"---") +
		u8"\n" + (obj.channel.topic.length() > 0 ? (getStrL("topic") + ":\n```\n" + obj.channel.topic + "\n```") : ""));
	/*u8"```md\n[" + getStrL("channel_t") + "](" + getStrL("new_t") + ")```\nID=" + std::to_string(obj.channel.id) + u8";NOME=" + obj.channel.name +
	u8";NSFW=" + (obj.channel.nsfw ? u8"S" : u8"N") + u8";AUDIO?" + (obj.channel.bitrate > 0 ? (std::to_string(obj.channel.bitrate) + u8"bps") : u8"---") +
	u8"\n- Tópico:\n```" + obj.channel.topic + "\n```");*/
	mylog.last_user = 0;
}
void GuildChat::handle_specific(aegis::gateway::events::guild_ban_add& obj)
{
	if (!mylog.deep_data) return;

	buffer_handle("```md\n[" + getStrL("banned") + "](" + std::to_string(obj.user.id) + ")<" + obj.user.username + "#" + obj.user.discriminator + ">```");
	mylog.last_user = 0;
}
void GuildChat::handle_specific(aegis::gateway::events::guild_ban_remove& obj)
{
	if (!mylog.deep_data) return;

	buffer_handle("```md\n[" + getStrL("unbanned") + "](" + std::to_string(obj.user.id) + ")<" + obj.user.username + "#" + obj.user.discriminator + ">```");
	mylog.last_user = 0;
}
void GuildChat::handle_specific(aegis::gateway::events::guild_role_create& obj)
{
	if (!mylog.deep_data) return;

	buffer_handle("```md\n[" + getStrL("role_t") + "](" + getStrL("new_t") + ")<" + std::to_string(obj.role.id) + " " + obj.role.name + ">```\n> <@&" + std::to_string(obj.role.id) + ">");
	mylog.last_user = 0;
}
void GuildChat::handle_specific(aegis::gateway::events::guild_role_update& obj)
{
	if (!mylog.deep_data) return;

	buffer_handle("```md\n[" + getStrL("role_t") + "](" + getStrL("update_t") + ")<" + std::to_string(obj.role.id) + " " + obj.role.name + ">```\n> <@&" + std::to_string(obj.role.id) + ">");
	mylog.last_user = 0;
}
void GuildChat::handle_specific(aegis::gateway::events::guild_role_delete& obj)
{
	if (!mylog.deep_data) return;

	buffer_handle("```md\n[" + getStrL("role_t") + "](" + getStrL("delete_t") + ")<" + std::to_string(obj.role_id) + ">");
	mylog.last_user = 0;
}
void GuildChat::end_message()
{
	save_settings();
	buffer_flush();
	if (!mylog.deep_data) return;

	if (mylog.channel_log) {
		for (size_t c = 0; c < 7; c++) {
			try {
				if (auto ch = ref->find_channel(mylog.channel_log); ch) {
					ch->create_message("` - - - - > " + getStrL("shutdown_message") + " < - - - - `").get();
					c = 7;
				}
				else {
					logging.print("[", c, "/7] Guild #", guild_id, " can't find channel to send shutdown message.");
					std::this_thread::yield();
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
					std::this_thread::yield();
				}
			}
			catch (...) {
				logging.print("[", c, "/7] Guild #", guild_id, " failed to send shutdown message once.");
				std::this_thread::yield();
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				std::this_thread::yield();
			}
		}
	}
}
void GuildChat::welcome_message()
{
	if (!mylog.deep_data) return;

	if (mylog.channel_log) {
		for (size_t c = 0; c < 7; c++) {
			try {
				if (auto ch = ref->find_channel(mylog.channel_log); ch) {
					ch->create_message("` - - - - > " + getStrL("wakeup_message") + " < - - - - `");
					c = 7;
				}
				else {
					logging.print("[", c, "/7] Guild #", guild_id, " failed to send wakeup message once.");
					std::this_thread::yield();
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
					std::this_thread::yield();
				}
			}
			catch (...) {
				logging.print("[", c, "/7] Guild #", guild_id, " failed to send wakeup message once.");
				std::this_thread::yield();
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				std::this_thread::yield();
			}
		}
	}
}
void GuildChat::rejoin_message()
{
	save_settings();
	buffer_flush();
	if (!mylog.deep_data) return;

	if (mylog.channel_log) {
		for (size_t c = 0; c < 7; c++) {
			try {
				if (auto ch = ref->find_channel(mylog.channel_log); ch) {
					ch->create_message("` - - - - > " + getStrL("rejoin_message") + " < - - - - `");
					c = 7;
				}
				else {
					logging.print("[", c, "/7] Guild #", guild_id, " can't find channel to send rejoin message.");
					std::this_thread::yield();
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
					std::this_thread::yield();
				}
			}
			catch (...) {
				logging.print("[", c, "/7] Guild #", guild_id, " failed to send rejoin message once.");
				std::this_thread::yield();
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				std::this_thread::yield();
			}
		}
	}
}