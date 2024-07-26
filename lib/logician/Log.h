#ifndef __Log_H_
#define __Log_H_

#include <fstream>
#include <filesystem>
#include <string_view>
#include <string>
#include <iostream>
#include "./Timer.h"
using Utility::Timer;

namespace Logician {
	enum class Level {
		Debug, Info, Warning, Error, Critical
	};
	class Log {
	public:
		explicit Log(const std::string_view& name, Level level = Level::Warning) : m_Name{name}, m_LogLevel{level}, m_IsFileSink{false} {}
		explicit Log(const std::string_view& name, Level level, const char * fileName) : m_Name{ name }, m_LogLevel{ level }, m_FileName{ fileName }, m_IsFileSink{ true } {}

		void setLevel(const Level& level) {
			m_LogLevel = level;
		}

		Level getLevel() const {
			return m_LogLevel;
		}

		void logToFile(const std::string_view& fileName);

		template<typename... Args>
		void debug(const std::string_view& message, Args&&... args) const;

		template<typename... Args>
		void info(const std::string_view& message, Args&&... args) const;

		template<typename... Args>
		void warning(const std::string_view& message, Args&&... args) const;

		template<typename... Args>
		void error(const std::string_view& message, Args&&... args) const;

		template<typename... Args>
		void critical(const std::string_view& message, Args&&... args) const;

	private:
		Level m_LogLevel;
		std::string_view m_Name;
		std::filesystem::path m_FileName;
		mutable std::ofstream m_OutStream;
		bool m_IsFileSink;

		static std::string getLevelString(const Level& level);
		static std::string getLevelStringColored(const Level& level);

		void print() const;

		template<typename T, typename... Args>
		void print(T arg, Args&&... args) const;

		template<typename... Args>
		void log(Level level, const std::string_view& message, Args&&... args) const;
	};

	template<typename T, typename... Args>
	void Log::print(T arg, Args&&... args) const {
		if (m_OutStream) {
			m_OutStream << arg << " ";
		}
		print(args...);
	}

	template<typename... Args>
	void Log::log(Level level, const std::string_view& message, Args&&... args) const {
		if (m_IsFileSink) {
			m_OutStream.open(m_FileName.string(), std::ios::app);
			if (m_OutStream) {
				m_OutStream << Timer::getCurrentTimeString() << " : [" << m_Name << "] : [" << getLevelString(level) << "] : " << message << " ";
			} 
		}
		print(args...);
		if (m_OutStream.is_open()) {
			m_OutStream.close();
		}
	}

	template<typename... Args>
	void Log::debug(const std::string_view& message, Args&&... args) const {
		if (m_LogLevel <= Level::Debug) {
			log(Level::Debug, message, args...);
		}
	}

	template<typename... Args>
	void Log::info(const std::string_view& message, Args&&... args) const {
		if (m_LogLevel <= Level::Info) {
			log(Level::Info, message, args...);
		}
	}

	template<typename... Args>
	void Log::warning(const std::string_view& message, Args&&... args) const {
		if (m_LogLevel <= Level::Warning) {
			log(Level::Warning, message, args...);
		}
	}

	template<typename... Args>
	void Log::error(const std::string_view& message, Args&&... args) const {
		if (m_LogLevel <= Level::Error) {
			log(Level::Error, message, args...);
		}
	}

	template<typename... Args>
	void Log::critical(const std::string_view& message, Args&&... args) const {
		if (m_LogLevel <= Level::Critical) {
			log(Level::Critical, message, args...);
		}
	}
}

#endif