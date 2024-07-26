#ifndef __Utility_H__
#define __Utility_H__

#include <string>
#include <optional>
#include <functional>

namespace EmployeeDB::View {
	class Utility {
	public:
		static bool proceedFurther(const std::string& operation);
		static bool repeatOperation(const std::string& operation, const std::string& Entity);
		static void removeEmptySpaces(std::string& str, const std::string& chars="\t\n\v\f\r ");
		static std::optional<int> getUserInputInt(const std::string& inputText, std::function<bool(const std::string&)> validator = 0, bool isMandatory = true);
		static std::optional<int> getUserInputInt(const std::string& inputText, std::function<bool(const std::string&, const std::string&)> validator, const std::string& entity);
		static std::optional<long long> getUserInputLL(const std::string& inputText, std::function<bool(const std::string&)> validator = 0, bool isMandatory = true);
		static std::optional<double> getUserInputDouble(const std::string& inputText, bool isMandatory = true);
		static std::optional<std::string> getUserInputString(const std::string& inputText, std::function<bool(const std::string&)> validator = 0, bool isMandatory = true);
		static std::optional<std::string> getUserInputGender(const std::string& inputText, std::function<bool(std::string&)> validator = 0, bool isMandatory = true);
		static std::optional<std::string> getUserInputDate(const std::string& inputText, std::function<bool(const std::string&)> validator = 0, bool isMandatory = true);
	};
}

#endif