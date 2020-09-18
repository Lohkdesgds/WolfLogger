#include <aegis.hpp>
#include "guild_global.h"

#include <vector>

const auto my_bot_id = 743234486661152848;
const std::string project_name = "WolfLogger";

const unsigned long long bots_allowed[] = { 524361154294972416 };

// reminder: bot image at Adobe CC\Defaults


GuildGlobal i_know;


BOOL onConsoleEvent(DWORD event) {

	switch (event) {
	case CTRL_C_EVENT:
	case CTRL_CLOSE_EVENT:
		i_know.force_save_all();
		break;
	}
	return TRUE;
}

int main()
{
	std::shared_ptr<std::thread> thr;

	if (!SetConsoleCtrlHandler(onConsoleEvent, TRUE)) {
		if (auto logg = i_know.get_logger(); logg) logg->critical("Something went wrong when trying to setup close handling...");
		else std::cout << "Something went wrong when trying to setup close handling..." << std::endl;
		i_know.shutdown();

		std::this_thread::sleep_for(std::chrono::seconds(5));
		return 1;
	}

	bool notice_dead_early = false;

	thr = std::shared_ptr<std::thread>(new std::thread([&] {

		size_t arr_siz = 0;
		const std::function<std::string(void)> random_phrases[] = {
			[&] {return u8"Adoraria jogar Minecraft...";},
			[&] {return u8"Criado pelo Lohk em 2020!";},
			[&] {return u8"Feito com C++... quero dizer, amor";},
			[&] {return u8"Simplicidade é tudo";},
			[&] {return u8"Meu DEUS, " + std::to_string(arr_siz) + u8" possíveis modelos de mensagem?! Pois é";},
			[&] {return u8"Thank you Aegis! For real!";},
			[&] {return u8"Versão " + version + " refactored";},
			[&] {return u8"Eu sou um bot?!";},
			[&] {return u8"@Lohkdesgds para suporte!";},
			[&] {return u8"Arroz, feijão, batata e um abração";},
			[&] {return u8"Me ajude a ficar famoso!";},
			[&] {return u8"Você bem que podia procurar por Lohk no Google...";},
			[&] {return u8"Eu tenho bastante fome e sono, sabia?";},
			[&] {return u8"O Lohk tem tentado me fazer extremamente estável. Se eu tiver problemas, desculpe!";},
			[&] {return u8"Você sabia que você pode me adicionar no seu grupo?";},
			[&] {return u8"Fun Fact: o Ninja ainda é o maior streamer na Twitch de todos os tempos.";},
			[&] {return u8"Sério alguém pode comprar algo pra eu jantar?";},
			[&] {return u8"Quanto mais eu penso, menos eu durmo :o";},
			[&] {return u8"Eu sou feito de 1 e 0 no final das contas, e você?";},
			[&] {return u8"Se precisa de ajuda, procure, nem que seja no Google!";},
			[&] {return u8"No Brasil 1 + 1 pode ser 3 ou até 5, dependendo dos impostos em cima do produto ;-;";},
			[&] {return u8"Eu nunca vi um bot ter tanta mensagem diferente assim O.o";},
			[&] {return u8"Eu sinto falta de quando eu era apenas um main(){std::cout << \"hello world\";}";},
			[&] {return u8"Algumas vezes você pode pensar em algo e tentar achar uma resposta aleatória aqui mesmo!";},
			[&] {return u8"Sim";},
			[&] {return u8"Não";},
			[&] {return u8"Talvez";},
			[&] {return u8"Nunca se sabe";},
			[&] {return u8"Mas é óbvio";},
			[&] {return u8"Com certeza";},
			[&] {return u8"Com certeza que não";},
			[&] {return u8"Onde já se viu uma coisa dessas!";},
			[&] {return u8"Eu vejo tudo e todos, sempre >:3";},
			[&] {return u8"Assistindo séries no Netflix...";},
			[&] {return u8"Eu adoro meu trabalho.";},
			[&] {return u8"Seria um caos eu ficar offline, né?";},
			[&] {return u8"Eu também amo vocês";},
			[&] {return u8"Aparentemente ainda estou em testes!";},
			[&] {return u8"Sinceramente vejo coisas até demais.";},
			[&] {return u8"Isso daqui muda com o tempo, sabia?";},
			[&] {return u8"Agora mais otimizado do que nunca!";},
			[&] {return u8"Miojo não é a comida mais veloz de se fazer!";},
			[&] {return u8"Será que eu devia ter Patreon?";},
			[&] {return u8"Eu suporto acentos àéíóúçêãõü!";},
			[&] {return u8"Você sabia que se eu caio eu não caio? Exatamente...";},
			[&] {return u8"Algumas updates podem ser bugadas, mas eu arrumo, relaxa!";},
			[&] {if (auto corr = i_know.get_core(); corr) { return command_global + u8"! - " + std::to_string(corr->get_guild_count()) + " guild(s)!"; } return std::string(u8"Acho que tive uns problemas aqui O.o"); },
			[&] {return u8"Usando " + std::to_string(double(aegis::utility::getCurrentRSS()) / div_memory_calc) + " MB de RAM agora mesmo!"; },
			[&] {if (auto corr = i_know.get_core(); corr) {return u8"Acordado há " + corr->uptime_str(); } return std::string(u8"Acho que tive uns problemas aqui O.o"); },
			[&] {return u8"Isso é aleatório (tecnicamente): " + std::to_string(rand());}
		};
		arr_siz = sizeof(random_phrases) / sizeof(std::function<std::string(void)>);

		std::this_thread::sleep_for(std::chrono::seconds(2));

		auto keep = [&] {return !notice_dead_early && (i_know.get_core()); };

		int randdd = GetTickCount64() % (arr_siz);

		while (keep()) {

			for (size_t c = 0; c < 6 && keep(); c++) {
				for(size_t pause = 0; pause < 10 && keep(); pause++) std::this_thread::sleep_for(std::chrono::seconds(2));
				if (!keep()) break;

				try {
					if (auto corr = i_know.get_core(); corr) corr->update_presence(random_phrases[randdd](), aegis::gateway::objects::activity::Game, aegis::gateway::objects::presence::Idle);
				}
				catch (aegis::error e) {
					if (auto logg = i_know.get_logger(); logg) logg->critical("Presence Updater: couldn't set presence. Got error: {}", e);
				}
				catch (nlohmann::detail::type_error e) {
					if (auto logg = i_know.get_logger(); logg) logg->error("Presence Updater:: JSON failed: TYPE ERROR: {}", e.what());
				}
				catch (nlohmann::detail::invalid_iterator e) {
					if (auto logg = i_know.get_logger(); logg) logg->error("Presence Updater:: JSON failed: INVALID ITERATOR ERROR: {}", e.what());
				}
				catch (nlohmann::detail::parse_error e) {
					if (auto logg = i_know.get_logger(); logg) logg->error("Presence Updater:: JSON failed: PARSE ERROR: {}", e.what());
				}
				catch (nlohmann::detail::out_of_range e) {
					if (auto logg = i_know.get_logger(); logg) logg->error("Presence Updater:: JSON failed: OUT OF RANGE ERROR: {}",  e.what());
				}
				catch (nlohmann::detail::other_error e) {
					if (auto logg = i_know.get_logger(); logg) logg->error("Presence Updater:: JSON failed: OTHER ERROR: {}", e.what());
				}
				catch (nlohmann::detail::exception e) {
					if (auto logg = i_know.get_logger(); logg) logg->error("Presence Updater:: JSON failed: GENERIC EXCEPTION ERROR: {}", e.what());
				}
				catch (std::exception e) {
					if (auto logg = i_know.get_logger(); logg) logg->critical("Presence Updater: couldn't set presence. Got error: {}", e.what());
				}
				catch (...) {
					if (auto logg = i_know.get_logger(); logg) logg->critical("Presence Updater: couldn't set presence. Unknown error.");
				}
			}
			
			randdd = GetTickCount64() % (arr_siz);
		}
	}), [&](std::thread* t){
		notice_dead_early = true;
		if (auto logg = i_know.get_logger(); logg) logg->info("Terminating parallel threads {}...", project_name);
		else std::cout << "Terminating parallel threads " << project_name << "..." << std::endl;
		t->join();
		if (auto logg = i_know.get_logger(); logg) logg->info("Terminated parallel threads {}.", project_name);
		else std::cout << "Terminated parallel threads " << project_name << "." << std::endl;
		delete t;
	});

	//thebot->yield();

	std::string smth_n;
	while (smth_n.find("exit") != 0) {
		std::getline(std::cin, smth_n);


		if (smth_n.find("broadcast ") == 0) {
			if (size_t lenn = strlen("broadcast "); smth_n.length() > lenn) {
				std::string cutt = smth_n.substr(lenn);
				std::string confirm;

				for (size_t pp = cutt.find("\\n"); pp != std::string::npos; pp = cutt.find("\\n")) {
					cutt = cutt.substr(0, pp) + '\n' + (cutt.length() > pp + 2 ? cutt.substr(pp + 2) : "");
				}

				if (cutt.length() >= 1700) {
					if (auto logg = i_know.get_logger(); logg) logg->warn("Isn't \n\n{}\n\n too big? Sorry.", cutt);
					else std::cout << "Isn't\n\n" << cutt << "\n\ntoo big? Sorry." << std::endl;
				}
				else {
					if (auto logg = i_know.get_logger(); logg) logg->warn("Are you sure you want to send\n\n{}\n\nto every server connected? (type CONFIRM to send)", cutt);
					else std::cout << "Are you sure you want to send\n\n" << cutt << "\n\nto every server connected? (type CONFIRM to send)" << std::endl;
					std::getline(std::cin, confirm);

					if (confirm == "CONFIRM") {
						size_t total = i_know.guild_count();
						if (auto logg = i_know.get_logger(); logg) logg->info("Sending broadcast to {} guilds...", total);
						size_t amount = i_know.broadcast(cutt);
						if (auto logg = i_know.get_logger(); logg) logg->info("{} of {} guilds have received the task to broadcast.", amount, total);
						else std::cout << "All " << amount << " of " << total << " guilds have received the task to broadcast." << std::endl;
					}
				}
			}
		}

		else if (smth_n.find("exit") != 0) {
			if (auto logg = i_know.get_logger(); logg) logg->info("Commands:\n- broadcast <text>\n- exit");
			else std::cout << "Commands:\n- broadcast <text>\n- exit" << std::endl;
		}
	}
	
	notice_dead_early = true;


	if (auto logg = i_know.get_logger(); logg) logg->info("Shutting down {}...", project_name);
	else std::cout << "Shutting down " << project_name << "..." << std::endl;
	i_know.shutdown();

	//thr.join();

	if (auto logg = i_know.get_logger(); logg) logg->info("Ended {}.", project_name);
	else std::cout << "Ended " << project_name << "." << std::endl;
	//end();

	//std::cout << "Ended " << project_name << "." << std::endl;
	//thebot->yield();
}