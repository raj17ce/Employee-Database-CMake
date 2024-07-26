#include "TableController.h"
#include "DBManager.h"

using EmployeeDB::Controller::TableController;
using EmployeeDB::DBManager;

std::string TableController::getCreateTableQuery(Table& obj) {	
	std::string queryString = "CREATE TABLE \"" + obj.getTableName() + "\" (";

	auto isFirstAttribute{ true };

	for (auto& [attributeName, attributeType, attributeConstraints] : obj.getAttributesVector()) {

		if (!isFirstAttribute) {
			queryString += ", ";
		}
		else {
			isFirstAttribute = false;
		}

		queryString += "\"" + attributeName + "\" ";
		queryString += attributeType + " ";

		if (attributeConstraints.size() != 0) {
			queryString += attributeConstraints;
		}
	}

	for (auto& [keyAttributeName, referencedTableName, referencedAttributeName, keyConstraints] : obj.getForeignKeysVector()) {

		queryString += ", ";

		queryString += "FOREIGN KEY (\"" + keyAttributeName + "\") ";
		queryString += "REFERENCES \"" + referencedTableName + "\"(\"" + referencedAttributeName + "\") ";
		queryString += keyConstraints;
	}

	queryString += ");";

	return queryString;
}

bool TableController::createTable(Table& obj) {
	std::string queryString = getCreateTableQuery(obj);

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\x1B[32m" << "Successfully Created Table : "<< obj.getTableName() << "\033[0m\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
		std::cerr << "\x1B[31m" << "Table " << obj.getTableName() << " could not be created." << "\033[0m\n";
		return false;
	}
	return true;
}

bool TableController::deleteTable(const std::string& tableName) {
	std::string queryString = "DROP TABLE " + tableName;

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\x1B[32m" << "Successfully Deleted Table : " << tableName << "\033[0m\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
		std::cerr << "\x1B[31m" << "Table " << tableName << " could not be deleted." << "\033[0m\n";
		return false;
	}
	return true;
}