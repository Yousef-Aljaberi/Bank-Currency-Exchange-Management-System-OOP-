#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUsersListScreen.h"
#include"clsAddNewUserScreen.h"

class clsManageUsersScreen:protected clsScreen
{
private:
	static short _ReadManageUsersScreenMenuOption()
	{
		short Chiose;
		Chiose = clsInputValidate::ReadShortNumberBetween(1, 6, "\tNumber must be between [ 1 , 6 ]");
		return Chiose;
	}
	enum enManageUsersMenueOption { eListUsers = 1, eAddUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenu = 6 };
	static void _ShowListUsersScreen()
	{
		clsListUsersScreen::ShowUsersList();
	}

	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\nPress any key to go back to manage users menue.....";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowAddUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	
	static void _ShowDeleteUserScreen()
	{
		cout << "\nDelete screen will be here";
	}

	static void _ShowUpdateUserScreen()
	{
		cout << "\nUpdate User screen will be here";
	}

	static void _ShowFindUserScreen()
	{
		cout << "\nFind User screen will be here";
	}

	static void _PerformManageUsersMenuOption(enManageUsersMenueOption ManageUsersMenueOption)
	{
		switch (ManageUsersMenueOption)
		{
		case enManageUsersMenueOption::eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOption::eAddUser:
			system("cls");
			_ShowAddUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOption::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		
		case enManageUsersMenueOption::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		
		case enManageUsersMenueOption::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		
		case enManageUsersMenueOption::eMainMenu:
		{


		}
		}
	}

public:
	static void ShowManageUsersMenue()
	{
		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformManageUsersMenuOption((enManageUsersMenueOption)_ReadManageUsersScreenMenuOption());
	}
};

