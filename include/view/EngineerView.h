#ifndef __EngineerView_H__
#define __EngineerView_H__

namespace EmployeeDB::View {

	class EngineerView {
	public:
		static bool insertEngineer();
		static bool updateEngineer();
		static bool deleteEngineer();
		static bool viewEngineer();
	private:
		static bool viewEngineerConditional();
	};
}

#endif