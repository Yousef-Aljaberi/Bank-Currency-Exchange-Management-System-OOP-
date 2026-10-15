#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsUser.h"
#include"clsScreen.h"
class clsDeleteUserScreen:protected clsScreen
{private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";
	}
public:
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\t Delete User Screen");

		string UserName;

		cout << "Please Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nErorr! UserName Not Found, Choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);

		char answer;
		cout << "Are you sure you want to delete this User? y/n?  ";
		cin >> answer;
		if (tolower(answer) == 'y')
		{
			if (User.Delete())
			{
				cout << "\nUser Deleted Successfully :-)" << endl;
				_PrintUser(User);
			}
			else
			{
				cout << "\n Error Client Was not Deleted\n";
			}
		}
		

		
	}
};

