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
		logging.print("Forced exit, ending tasks...");
		_shared.f();
		logging.print("Ended everything successfully.");
		std::this_thread::sleep_for(std::chrono::seconds(3));
		break;
	}

	return TRUE;
}

int main()
{
	logging.print("> > > Initializing ", project_name, "...");

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

		logging.print("[!] Joined/Connected Guild ", g.get_name(), " #", g.get_id(), " from ", g.get_region());
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

		logging.print("[!] Joined/Connected Guild ", g.name, " #", g.id, " from ", g.region);
		my_guild_control.push_back(std::make_shared<GuildChat>(thebot, g));
		
		my_guild_mutex.unlock();

		return my_guild_control.back();
	};




	_shared.f = end; // I don't like it, but whatever


	if (!SetConsoleCtrlHandler(onConsoleEvent, TRUE)) {
		logging.print("Something went wrong when trying to setup close handling...");
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
		catch (...) { logging.print("FATAL ERROR | GIVEUP."); }
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
					logging.print("[!] Left Guild #", obj.guild_id);
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
			logging.print("FATAL ERROR | GIVEUP.");
		}
	});


	thebot->set_on_message_create([&](aegis::gateway::events::message_create obj) {
		if (ignore_all_ending_lmao) return;

		try {
			if (obj.msg.is_bot() && !is_allowed_bot(obj.msg.author.id)) return;
			get_guild(obj.channel.get_guild())->handle_specific(obj);
		}
		catch (...) { logging.print("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_message_update([&](aegis::gateway::events::message_update obj) {
		if (ignore_all_ending_lmao) return;

		try {
			if (obj.msg.is_bot() && !is_allowed_bot(obj.msg.author.id)) return;

			get_guild(obj.channel.get_guild())->handle_specific(obj);
		}
		catch (...) { logging.print("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_message_delete([&](aegis::gateway::events::message_delete obj) {
		if (ignore_all_ending_lmao) return;

		try {
			get_guild(obj.channel.get_guild())->handle_specific(obj);
		}
		catch (...) { logging.print("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_message_reaction_add([&](aegis::gateway::events::message_reaction_add obj) {
		if (ignore_all_ending_lmao) return;

		try {
			if (obj.user_id == my_bot_id) return;

			aegis::guild* gg = thebot->guild_create(obj.guild_id, &thebot->get_shard_by_guild(obj.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else logging.print("Failed to recover Guild #", obj.guild_id, "!");
		}
		catch (...) { logging.print("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_message_reaction_remove([&](aegis::gateway::events::message_reaction_remove obj) {
		if (ignore_all_ending_lmao) return;

		try {
			if (obj.user_id == my_bot_id) return;

			aegis::guild* gg = thebot->guild_create(obj.guild_id, &thebot->get_shard_by_guild(obj.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else logging.print("Failed to recover Guild #", obj.guild_id, "!");
		}
		catch (...) { logging.print("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_channel_create([&](aegis::gateway::events::channel_create obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.channel.guild_id, &thebot->get_shard_by_guild(obj.channel.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else logging.print("Failed to recover Guild #", obj.channel.guild_id, "!");
		}
		catch (...) { logging.print("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_channel_update([&](aegis::gateway::events::channel_update obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.channel.guild_id, &thebot->get_shard_by_guild(obj.channel.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else logging.print("Failed to recover Guild #", obj.channel.guild_id, "!");
		}
		catch (...) { logging.print("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_channel_delete([&](aegis::gateway::events::channel_delete obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.channel.guild_id, &thebot->get_shard_by_guild(obj.channel.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else logging.print("Failed to recover Guild #", obj.channel.guild_id, "!");
		}
		catch (...) { logging.print("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_guild_ban_add([&](aegis::gateway::events::guild_ban_add obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.guild_id, &thebot->get_shard_by_guild(obj.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else logging.print("Failed to recover Guild #", obj.guild_id, "!");
		}
		catch (...) { logging.print("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_guild_ban_remove([&](aegis::gateway::events::guild_ban_remove obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.guild_id, &thebot->get_shard_by_guild(obj.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else logging.print("Failed to recover Guild #", obj.guild_id, "!");
		}
		catch (...) { logging.print("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_guild_role_create([&](aegis::gateway::events::guild_role_create obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.guild_id, &thebot->get_shard_by_guild(obj.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else logging.print("Failed to recover Guild #", obj.guild_id, "!");
		}
		catch (...) { logging.print("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_guild_role_update([&](aegis::gateway::events::guild_role_update obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.guild_id, &thebot->get_shard_by_guild(obj.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else logging.print("Failed to recover Guild #", obj.guild_id, "!");
		}
		catch (...) { logging.print("FATAL ERROR | GIVEUP."); }
	});
	thebot->set_on_guild_role_delete([&](aegis::gateway::events::guild_role_delete obj) {
		if (ignore_all_ending_lmao) return;

		try {
			aegis::guild* gg = thebot->guild_create(obj.guild_id, &thebot->get_shard_by_guild(obj.guild_id));
			if (gg) get_guild(*gg)->handle_specific(obj);
			else logging.print("Failed to recover Guild #", obj.guild_id, "!");
		}
		catch (...) { logging.print("FATAL ERROR | GIVEUP."); }
	});

	thebot->run();

	thr = std::thread([&] {

		const size_t arr_siz = 22;
		const std::string random_phrases[arr_siz] = {
			u8"Adoraria jogar Minecraft...",
			u8"Criado pelo Lohk em 2020!",
			u8"Feito com C++... quero dizer, amor",
			u8"Simplicidade é tudo",
			u8"Thank you Aegis! For real!",
			u8"Versão 1.5.134 pre-release",
			u8"Eu sou um bot?!",
			u8"@Lohkdesgds para suporte!",
			u8"Arroz, feijão, batata e um abração",
			u8"Eu vejo tudo e todos, sempre >:3",
			u8"Assistindo séries no Netflix...",
			u8"Eu adoro meu trabalho.",
			u8"Seria um caos eu ficar offline, né?",
			u8"Eu também amo vocês",
			u8"Aparentemente ainda estou em testes!",
			u8"Sinceramente vejo coisas até demais.",
			u8"Isso daqui muda com o tempo, sabia?",
			u8"Agora mais otimizado do que nunca!",
			u8"Miojo não é a comida mais veloz de se fazer!",
			u8"Será que eu devia ter Patreon?",
			u8"Eu suporto acentos àéíóúçêãõü!", // 21
			u8"Algumas updates podem ser bugadas, mas eu arrumo, relaxa!"
		};

		std::this_thread::sleep_for(std::chrono::seconds(5));

		auto keep = [&] {return (!ignore_all_ending_lmao); };

		while (keep()) {
			int randdd = GetTickCount64() % (arr_siz + 1);
			if (randdd == arr_siz) {
				std::string endd = main_cmd + u8"! - " + std::to_string(thebot->get_guild_count()) + " guild(s)!";
				thebot->update_presence(endd, aegis::gateway::objects::activity::Game, aegis::gateway::objects::presence::Idle);
			}
			else thebot->update_presence(random_phrases[randdd], aegis::gateway::objects::activity::Game, aegis::gateway::objects::presence::Idle);
			for(size_t c = 0; c < 50 && keep(); c++) std::this_thread::sleep_for(std::chrono::seconds(6));
		}
	});

	//thebot->yield();

	std::string smth;
	while (smth != "exit") std::cin >> smth;

	logging.print("> > > Shutting down ", project_name, "...");

	end();

	logging.print("> > > Ended ", project_name, ".");
	//thebot->yield();
}