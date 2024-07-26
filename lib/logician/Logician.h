#ifndef __DefaultLogger_H__
#define __DefaultLogger_H__

#include "./Log.h"
#include "./Registry.h"
using Logician::Log;

namespace Logician {

	inline void setDefaultLogger(std::shared_ptr<Log> ptr) {
		Registry::instance().setDefaultLogger(ptr);
	} 

	inline std::shared_ptr<Log> getDefaultLogger() {
		return Registry::instance().getDefaultLogger();
	}

	template<typename... Args>
	void debug(const std::string_view& message, Args&&... args) {
		Registry::instance().getDefaultLogger()->debug(message, args...);
	}

	template<typename... Args>
	void info(const std::string_view& message, Args&&... args) {
		Registry::instance().getDefaultLogger()->info(message, args...);
	}

	template<typename... Args>
	void warning(const std::string_view& message, Args&&... args) {
		Registry::instance().getDefaultLogger()->warning(message, args...);
	}

	template<typename... Args>
	void error(const std::string_view& message, Args&&... args) {
		Registry::instance().getDefaultLogger()->error(message, args...);
	}

	template<typename... Args>
	void critical(const std::string_view& message, Args&&... args) {
		Registry::instance().getDefaultLogger()->critical(message, args...);
	}
}

#endif