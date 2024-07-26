#ifndef __HRView_H__
#define __HRView_H__

namespace EmployeeDB::View {

	class HRView {
	public:
		static bool insertHR();
		static bool updateHR();
		static bool deleteHR();
		static bool viewHR();
	private:
		static bool viewHRConditional();
	};
}

#endif