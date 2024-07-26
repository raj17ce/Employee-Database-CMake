#ifndef __Registry_H__
#define __Registry_H__

#include "./Log.h"

namespace Logician {
	class Registry {
	public:
		std::shared_ptr<Log> getDefaultLogger() const {
			return m_DefaultLogger;
		}

		void setDefaultLogger(std::shared_ptr<Log> ptr) {
			m_DefaultLogger = ptr;
		}

		static Registry& instance() {
			static Registry registry;
			return registry;
		};

	private:
		Registry() : m_DefaultLogger{ std::make_shared<Log>("defaultLogger") } {};
		~Registry() = default;
		std::shared_ptr<Log> m_DefaultLogger;
	};
}

#endif