#ifndef __EmployeeDB_H__
#define __EmployeeDB_H__

#include "MainView.h"
#include "DBManager.h"

namespace EmployeeDB {
	inline void run() {
		DBManager::instance().executeConfigQuery();
		EmployeeDB::View::MainView::mainMenuView();
	}
}

#endif