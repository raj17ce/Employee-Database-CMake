#ifndef __MainView_H__
#define __MainView_H__

namespace EmployeeDB::View {

	class MainView {
	public:
		static void mainMenuView();
	private:
		static void printMainMenu();
		static void mainMenuSelection(short int userInput);

		static void tableMenuView();
		static void tableMenuSelection(short int userInput);

		static void printTableMenu();

		static void insertMenuView();
		static void insertMenuSelection(short int userInput);

		static void updateMenuView();
		static void updateMenuSelection(short int userInput);

		static void deleteMenuView();
		static void deleteMenuSelection(short int userInput);

		static void viewMenuView();
		static void viewMenuSelection(short int userInput);

		static void printExportTableMenu();

		static void exportMenuView();
		static bool exportMenuSelection(short int userInput);
	};
}
#endif