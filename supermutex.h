#pragma once

#include <mutex>
#include <condition_variable>
#include <chrono>

namespace LSW {
	namespace v5 {
		namespace Tools {

			class SuperMutex {
				class weird_mtx {
					std::mutex m;
					bool locked = false;
				public:
					bool try_lock();
					void unlock();
					bool is_locked() const;
				} mu;
				std::condition_variable cond;
			public:
				void lock();
				void unlock();
			};

			class AutoLock {
				SuperMutex* you = nullptr;
				bool hasunlocked = false;
			public:
				AutoLock(SuperMutex&);
				~AutoLock();
				void unlock();
				void lock();
			};

			class Waiter {
				std::condition_variable cond;
			public:
				void wait_signal(const size_t = 0);
				void signal_one();
				void signal_all();
			};
		}
	}
}