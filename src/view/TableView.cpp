#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "TableView.h"
#include "Utility.h"

using EmployeeDB::View::TableView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::TableController;

void TableView::getAttributesInput(Table& obj) {
	std::vector<std::array<std::string, 3>> attributesVector;
	attributesVector.reserve(10);

	while (true) {
		auto attributeName = Utility::getUserInputString("Attribute name").value();
		auto attributeType = Utility::getUserInputString("Attribute type").value();
		auto attributeConstraints = Utility::getUserInputString("Attribute constraints", 0, false).value_or("");

		attributesVector.emplace_back(std::move(std::array<std::string, 3>{attributeName, attributeType, attributeConstraints}));

		if (!Utility::repeatOperation("add", "Attribute")) {
			break;
		}
	}

	obj.setAttributesVector(attributesVector);
}

void TableView::getForeignKeysInput(Table& obj) {
	std::vector<std::array<std::string, 4>> foreignKeysVector;
	foreignKeysVector.reserve(3);

	auto foreignKeyInsertion{ true };
	if (!Utility::proceedFurther("Foreign key insertion")) {
		foreignKeyInsertion = false;
	}

	while (foreignKeyInsertion) {
		auto keyAttributeName = Utility::getUserInputString("Attribute Name(Foreign Key)").value();
		auto referencedTableName = Utility::getUserInputString("Referenced Table Name").value();
		auto referencedAttributeName = Utility::getUserInputString("Referenced Attribute Name").value();
		auto keyConstraints = Utility::getUserInputString("Key Constraints").value_or("");

		foreignKeysVector.emplace_back(std::move(std::array<std::string, 4>{ keyAttributeName, referencedTableName, referencedAttributeName, keyConstraints }));

		if (!Utility::repeatOperation("Add", "foreign key")) {
			foreignKeyInsertion = false;
		}
	}

	obj.setForeignKeysVector(std::move(foreignKeysVector));
}

bool TableView::createTable() {
	Table obj;

	system("cls");
	std::cout << "------------------------------------------" << "\x1B[36m" << "Create Table" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "\x1B[36m" << "Fields with * are required fields" << "\x1B[0m\n";


	{
		auto tableName = Utility::getUserInputString("Table name").value();
		obj.setTableName(tableName);
	}

	getAttributesInput(obj);
	getForeignKeysInput(obj);

	TableController::createTable(obj);

	return Utility::repeatOperation("Create", "Table");
}

bool TableView::deleteTable() {
	system("cls");
	std::cout << "------------------------------------------" << "\x1B[36m" << "Delete Table" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "\x1B[33m" << "Enter the name of the Table you want to delete." << "\x1B[0m\n";

	auto tableName = Utility::getUserInputString("Table name").value();

	TableController::deleteTable(tableName);

	return Utility::repeatOperation("Delete", "Table");
}