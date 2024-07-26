#ifndef __QAView_H__
#define __QAView_H__

namespace EmployeeDB::View {

	class QAView {
	public:
		static bool insertQA();
		static bool updateQA();
		static bool deleteQA();
		static bool viewQA();
	private:
		static bool viewQAConditional();
	};
}

#endif