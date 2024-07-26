#ifndef __ExportView_H__
#define __ExportView_H__

#include <string>

namespace EmployeeDB::View {

	class ExportView {
	public:
		static bool exportToCSV(const std::string& entity);
		static bool exportAll();
	};
}

#endif