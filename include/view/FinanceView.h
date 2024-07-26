#ifndef __FinanceView_H__
#define __FinanceView_H__

namespace EmployeeDB::View {

	class FinanceView {
	public:
		static bool insertFinance();
		static bool updateFinance();
		static bool deleteFinance();
		static bool viewFinance();
	private:
		static bool viewFinanceConditional();
	};
}

#endif