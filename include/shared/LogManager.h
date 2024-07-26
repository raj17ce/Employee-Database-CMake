#ifndef __LogManager_H__
#define __LogManager_H__

#include "Config.h"
#include "Log.h"

using Logician::Log, Logician::Level;

namespace EmployeeDB {
	class LogManager {
	public:
		LogManager() : m_Log{ "DefaultLogger", Level::Debug, EmployeeDB::Config::LogFilePath.string().c_str()} {}
		
		static LogManager& instance();

		Log& getLogger() {
			return m_Log;
		}
	private:
		Log m_Log;
	};

	inline LogManager& LogManager::instance() {
		static LogManager instance;
		return instance;
	}
}

#endif