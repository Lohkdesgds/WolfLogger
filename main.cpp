#include "handle_guild_easy.h"
#include <aegis.hpp>
#include "keys.h"

#include <vector>

const auto my_bot_id = 743234486661152848;
const std::string project_name = "WolfLogger";

const unsigned long long bots_allowed[] = { 524361154294972416 };

// reminder: bot image at Adobe CC\Defaults


struct share {
	std::function<void(void)> f;
} _shared;

bool is_allowed_bot(const unsigned long long a) {
	for (auto& i : bots_allowed) if (i == a) return true;
	return false;
}



BOOL onConsoleEvent(DWORD event) {

	switch (event) {
	case CTRL_C_EVENT:
	case CTRL_CLOSE_EVENT:
		std::cout << "Forced exit, ending tasks..." << std::endl;
		_shared.f();
		std::cout << "Ended everything successfully." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(3));
		break;
	}

	return TRUE;
}

int main()
{
	//setlocale(LC_ALL, "");
	std::cout << "> > > Initializing " << project_name << "..." << std::endl;

	std::vector<std::shared_ptr<GuildChat>> my_guild_control;
	std::mutex my_guild_mutex;
	bool ignore_all_ending_lmao = false;
	std::thread thr;
	std::shared_ptr<aegis::core> thebot;

	auto end = [&] {
		ignore_all_ending_lmao = true;

		my_guild_mutex.lock();
		for (auto& i : my_guild_control) i.reset();
		my_guild_mutex.unlock();

		thebot->shutdown();

		std::this_thread::sleep_for(std::chrono::seconds(2));
		if (thr.joinable()) thr.join();
	};



	auto get_guild = [&] (aegis::guild& g) {
		my_guild_mutex.lock();
		for (auto i : my_guild_control) {
			if (*i == g.get_id()) {
				my_guild_mutex.unlock();
				return i;
			}
		}

		thebot->log->info("Joined/Connected Guild {} #{} from {}", g.get_name(), g.get_id(), g.get_region());
		my_guild_control.push_back(std::make_shared<GuildChat>(thebot, g));

		my_guild_mutex.unlock();

		return my_guild_control.back();
	};
	auto get_guild_c = [&] (aegis::gateway::objects::guild& g) {
		my_guild_mutex.lock();
		for (auto i : my_guild_control) {
			if (*i == g.id) {
				my_guild_mutex.unlock();
				return i;
			}
		}

		thebot->log->info("Joined/Connected Guild {} #{} from {}", g.name, g.id, g.region);
		my_guild_control.push_back(std::make_shared<GuildChat>(thebot, g));
		
		my_guild_mutex.unlock();

		return my_guild_control.back();
	};




	_shared.f = end; // I don't like it, but whatever


	if (!SetConsoleCtrlHandler(onConsoleEvent, TRUE)) {
		thebot->log->critical("Something went wrong when trying to setup close handling...");
		std::this_thread::sleep_for(std::chrono::seconds(5));
		return 1;
	}


	thebot = std::shared_ptr<aegis::core>(new aegis::core(aegis::create_bot_t().log_level(spdlog::level::trace).token(token)), [](aegis::core* c) {
		c->shutdown();
		delete c;
	});

	
	// join in guild
	thebot->set_on_guild_create([&](aegis::gateway::events::guild_create obj) {
		if (ignore_all_ending_lmao) return;
		try {
			get_guild_c(obj.guild);
		}
		catch (...) { thebot->log->critical("FATAL ERROR | GIVEUP."); }
	});
	// leave guild
	thebot->set_on_guild_delete([&](aegis::gateway::events::guild_delete obj) {
		if (ignore_all_ending_lmao) return;
		bool was_locked = false;

		try {
			my_guild_mutex.lock();
			was_locked = true;
			for (size_t p = 0; p < my_guild_control.size(); p++) {
				auto& i = my_guild_control[p];
				if (*i == obj.guild_id) {
					thebot->log->info("Left Guild #{}", obj.guild_id);
					i->reset();
					my_guild_control.erase(my_guild_control.begin() + p);
					my_guild_mutex.unlock();
					was_locked = false;
					return;
				}
			}
			was_locked = false;
			my_guild_mutex.unlock();
		}
		catch (...) { 
			if (was_locked) my_guild_mutex.unlock();
			thebot->log->critical("FATAL ERROR | GIVEUP.");
		}
	});


	thebot->set_on_message_create([&](aegis::gateway::events::message_create obj) {
		if (ignore_all_ending_lmao) return;

		try {
			if (obj.msg.is_bot() && !is_allowed_bot(obj.msg.author.id)) return;
			get_guild(obj.channel.get_guild())->handle_specific(obj);
		}
		catch (...) { thebot->log->critical("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_message_update([&](aegis::gateway::events::message_update obj) {
		if (ignore_all_ending_lmao) return;

		try {
			if (obj.msg.is_bot() && !is_allowed_bot(obj.msg.author.id)) return;

			get_guild(obj.channel.get_guild())->handle_specific(obj);
		}
		catch (...) { thebot->log->critical("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_message_delete([&](aegis::gateway::events::message_delete obj) {
		if (ignore_all_ending_lmao) return;

		try {
			get_guild(obj.channel.get_guild())->handle_specific(obj);
		}
		catch (...) { thebot->log->critical("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_message_reaction_add([&](aegis::gateway::events::message_reaction_add obj) {
		if (ignore_all_ending_lmao) return;

		try {
			if (obj.user_id == my_bot_id) return;

			aegis::guild* gg = thebot->guild_create(obj.guild_id, &thebot->get_shard_by_guild(obj.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else thebot->log->error("Failed to recover Guild #{}!", obj.guild_id);
		}
		catch (...) { thebot->log->critical("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_message_reaction_remove([&](aegis::gateway::events::message_reaction_remove obj) {
		if (ignore_all_ending_lmao) return;

		try {
			if (obj.user_id == my_bot_id) return;

			aegis::guild* gg = thebot->guild_create(obj.guild_id, &thebot->get_shard_by_guild(obj.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else thebot->log->error("Failed to recover Guild #{}!", obj.guild_id);
		}
		catch (...) { thebot->log->critical("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_channel_create([&](aegis::gateway::events::channel_create obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.channel.guild_id, &thebot->get_shard_by_guild(obj.channel.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else thebot->log->error("Failed to recover Guild #{}!", obj.channel.guild_id);
		}
		catch (...) { thebot->log->critical("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_channel_update([&](aegis::gateway::events::channel_update obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.channel.guild_id, &thebot->get_shard_by_guild(obj.channel.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else thebot->log->error("Failed to recover Guild #{}!", obj.channel.guild_id);
		}
		catch (...) { thebot->log->critical("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_channel_delete([&](aegis::gateway::events::channel_delete obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.channel.guild_id, &thebot->get_shard_by_guild(obj.channel.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else thebot->log->error("Failed to recover Guild #{}!", obj.channel.guild_id);
		}
		catch (...) { thebot->log->critical("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_guild_ban_add([&](aegis::gateway::events::guild_ban_add obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.guild_id, &thebot->get_shard_by_guild(obj.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else thebot->log->error("Failed to recover Guild #{}!", obj.guild_id);
		}
		catch (...) { thebot->log->critical("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_guild_ban_remove([&](aegis::gateway::events::guild_ban_remove obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.guild_id, &thebot->get_shard_by_guild(obj.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else thebot->log->error("Failed to recover Guild #{}!", obj.guild_id);
		}
		catch (...) { thebot->log->critical("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_guild_role_create([&](aegis::gateway::events::guild_role_create obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.guild_id, &thebot->get_shard_by_guild(obj.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else thebot->log->error("Failed to recover Guild #{}!", obj.guild_id);
		}
		catch (...) { thebot->log->critical("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_guild_role_update([&](aegis::gateway::events::guild_role_update obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.guild_id, &thebot->get_shard_by_guild(obj.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else thebot->log->error("Failed to recover Guild #{}!", obj.guild_id);
		}
		catch (...) { thebot->log->critical("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_guild_role_delete([&](aegis::gateway::events::guild_role_delete obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.guild_id, &thebot->get_shard_by_guild(obj.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else thebot->log->error("Failed to recover Guild #{}!", obj.guild_id);
		}
		catch (...) { thebot->log->critical("FATAL ERROR | GIVEUP."); }
	});

	thebot->run();

	thr = std::thread([&] {

		const size_t arr_siz = 28;
		const std::function<std::string(void)> random_phrases[arr_siz] = {
			[&] {return u8"Adoraria jogar Minecraft...";},
			[&] {return u8"Criado pelo Lohk em 2020!";},
			[&] {return u8"Feito com C++... quero dizer, amor";},
			[&] {return u8"Simplicidade é tudo";},
			[&] {return u8"Meu DEUS, " + std::to_string(arr_siz) + " possíveis modelos de mensagem?! Pois é";},
			[&] {return u8"Thank you Aegis! For real!";},
			[&] {return u8"Versão " + version + " pre-release";},
			[&] {return u8"Eu sou um bot?!";},
			[&] {return u8"@Lohkdesgds para suporte!";},
			[&] {return u8"Arroz, feijão, batata e um abração";},
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
			[&] {return main_cmd + u8"! - " + std::to_string(thebot->get_guild_count()) + " guild(s)!";},
			[&] {return u8"Usando " + std::to_string(double(aegis::utility::getCurrentRSS()) / div_memory_calc) + " MB de RAM agora mesmo!"; },
			[&] {return u8"Acordado há " + thebot->uptime_str();},
			[&] {return u8"Isso é aleatório (tecnicamente): " + std::to_string(rand());}
		};

		std::this_thread::sleep_for(std::chrono::seconds(2));

		auto keep = [&] {return (!ignore_all_ending_lmao); };

		int randdd = arr_siz - 1;

		while (keep()) {

			for (size_t c = 0; c < 6 && keep(); c++) {
				std::this_thread::sleep_for(std::chrono::seconds(10));
				if (!keep()) break;
				thebot->update_presence(random_phrases[randdd](), aegis::gateway::objects::activity::Game, aegis::gateway::objects::presence::Idle);
			}
			
			randdd = GetTickCount64() % (arr_siz);
		}
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

				if (cutt.length() >= 1800) {
					thebot->log->warn("Isn't '{}' too big? Sorry.", cutt);
				}
				else {
					thebot->log->warn("Are you sure you want to send\n\n{}\n\nto every server connected? (type CONFIRM to send)", cutt);
					std::getline(std::cin, confirm);

					if (confirm == "CONFIRM") {
						for (size_t k = 0; k < my_guild_control.size(); k++) {
							my_guild_mutex.lock();
							auto u = my_guild_control[k];
							my_guild_mutex.unlock();
							u->broadcast(cutt);
						}
						thebot->log->info("All guilds have received the message.");
					}
				}
			}
		}

		else if (smth_n.find("exit") != 0) {
			thebot->log->info("Commands:\n- broadcast <text>\n- exit");
		}
	}

	thebot->log->info("Shutting down {}...", project_name);

	end();

	std::cout << "Ended " << project_name << "." << std::endl;
	//thebot->yield();
}