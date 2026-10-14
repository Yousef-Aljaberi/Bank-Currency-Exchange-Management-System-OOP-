#pragma once
#include"clsPerson.h"
#include"clsString.h"
#include<fstream>
#include<vector>
#include<string>


class clsUser:public  clsPerson
{
private:
	enum enMode { EmptyMode = 1, UpdateMode = 2, AddNewMode = 3 };
	enMode _Mode;
	int _Permissions;
	string _Password;
	string _UserName;
    bool _MarkedForDelete = false;
    
    static clsUser _ConvertLineToUserObject(string Line,string Seperator="#//#")
    {
        vector<string> vUserData = clsString::Split(Line, Seperator);
        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));

    }
    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.FirstName + Seperator;
        UserRecord += User.LastName + Seperator;
        UserRecord += User.Email + Seperator;
        UserRecord += User.Phone + Seperator;
        UserRecord += User.UserName + Seperator;
        UserRecord += User.Password + Seperator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;

    }

     static vector<clsUser> _LoadUsersDataFromFile()
    {
        vector<clsUser> vUsers;
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                vUsers.push_back(User);
            }
            MyFile.close();
        }
        return vUsers;
    }
    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    
    
    void _AddNewDataLineToFile(string Line)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << Line << endl;
            MyFile.close();
        }
    }
    void _SaveUsersDataToFile(vector<clsUser> vUsers)
    {
        fstream MyFile;
        
        MyFile.open("Users.txt", ios::out); //write mode

        if (MyFile.is_open())
        {
            string Line;
            for (clsUser User : vUsers)
            {
                if (User.MarkedForDeleted() == false)
                {
                    Line = _ConverUserObjectToLine(User);
                    MyFile << Line << endl;
                }
            }
            MyFile.close();
        }
    }
    void _Update()
    {
        vector<clsUser>vUsers;
        vUsers = _LoadUsersDataFromFile();

        bool UserFound = false;

        for (clsUser& User : vUsers)
        {
            if (User.UserName == _UserName)
            {
                User = *this;
                UserFound = true;
                break;
            }
        }
        if (UserFound)
        {
            _SaveUsersDataToFile(vUsers);
        }
    }
    void _AddNew()
    {
        _AddNewDataLineToFile(_ConverUserObjectToLine(*this));
    }

public:
	
    clsUser(enMode Mode, string FirstName, string LastName,string Email, string Phone, string UserName, 
        string Password,int Permissions) :clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
        _MarkedForDelete = false; 
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }
    string GetUserName()
    {
        return _UserName;
    }
    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;
    
    void SetPassword(string Password)
    {
        _Password = Password;
    }
    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }
    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    static bool IsUserExist(string UserName)
    {
        clsUser User = Find(UserName);
        return (!User.IsEmpty());
    }

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }

        return _GetEmptyUserObject();
    }
    static clsUser Find(string UserName,string Pssword)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if ((User.UserName == UserName) && (User.Password == Pssword))
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
           
        

        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };
    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
            return enSaveResults::svFaildEmptyObject;
            break;
        case enMode::UpdateMode:
            _Update();
            return enSaveResults::svSucceeded;
        case enMode::AddNewMode:
            if (IsUserExist(_UserName))
            {
                return svFaildUserExists;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
            break;

        }
    }


    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

};

