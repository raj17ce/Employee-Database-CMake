#ifndef __DBManager_H__
#define __DBManager_H__

#include <iostream>
#include "sqlite3.h"

namespace EmployeeDB {
	class DBManager {
	public:
		static DBManager& instance();
		int executeQuery(const char* queryString);
		int executeCustomQuery(const char* queryString, int (*callback)(void*, int, char**, char**), void* arg);
		int executeSelectQuery(const char* queryString);
		int executeSelectSalaryQuery(const char* queryString);
		int executeRowCountQuery(const char* queryString);
		static void executeConfigQuery();
		static void executeTruncateQuery(const char* tableName);

		char* getErrorMessage() const {
			return m_ErrorMessage;
		}
	private:
		DBManager() {
			openConnection();
		}
		~DBManager() {
			closeConnection();
		}
		int openConnection();
		int closeConnection();
		static int selectCallback(void* arg, int argc, char** argv, char** azColName);
		static int selectSalaryCallback(void* arg, int argc, char** argv, char** azColName);
		static int rowCountCallback(void* arg, int argc, char** argv, char** azColName);
		sqlite3* m_DB;
		int m_ResultCode;
		char* m_ErrorMessage;
	};
}
#endif