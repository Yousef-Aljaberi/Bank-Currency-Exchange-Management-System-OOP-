#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"clsString.h"
class clsCurrency
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CountryCode;
	string _CurrencyName;
	 float _Rate;
	 
	 static clsCurrency _ConverCurrencyDataLineToObject(string CurrencyDataLine,string Seprator="#//#")
	 {
		 vector<string> vCurrencyDataRecord;
		 vCurrencyDataRecord = clsString::Split(CurrencyDataLine,Seprator);

		 return clsCurrency(enMode::UpdateMode, vCurrencyDataRecord[0], vCurrencyDataRecord[1],
			 vCurrencyDataRecord[2], stof(vCurrencyDataRecord[3]));
	 }
	 static string _ConvertCurrencyObjectToDataLine(clsCurrency Currency, string Seprator = "#//#")
	 {
		 string CurrencyLine = "";

		 CurrencyLine += Currency.Country() + Seprator;
		 CurrencyLine += Currency.CountryCode() + Seprator;
		 CurrencyLine += Currency.CurrencyName() + Seprator;
		 CurrencyLine += to_string(Currency.Rate());

		 return CurrencyLine;
	 }

	 static vector<clsCurrency> _LoadCurrencyDataFromFile()
	 {
		 vector<clsCurrency> vCurrencies;

		 fstream MyFile;
		 MyFile.open("Currencies.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;

			 while (getline(MyFile, Line))
			 {
				 vCurrencies.push_back(clsCurrency(_ConverCurrencyDataLineToObject(Line)));
			 }
			 MyFile.close();

		 }
		 return vCurrencies;
	 }

	 static clsCurrency _GetEmptyObject()
	 {
		 return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	 }

	 static void _SaveCurrencyDataToFile(vector<clsCurrency> Currencies)
	 {
		 fstream MyFile;
		 MyFile.open("Currencies.txt", ios::out);

		 if (MyFile.is_open())
		 {
			 string CurrencyLine;
			 for (clsCurrency C : Currencies)
			 {
				 CurrencyLine = _ConvertCurrencyObjectToDataLine(C);
				 MyFile << CurrencyLine << endl;
			 }
		 }
	 }

	 void _Update()
	 {
		 vector<clsCurrency> vCurrencies = _LoadCurrencyDataFromFile();

		 for (clsCurrency& C : vCurrencies)
		 {
			 if (C.CountryCode() == CountryCode())
			 {
				 C = *this;
				 break;
			 }
		 }
		 _SaveCurrencyDataToFile(vCurrencies);
	 }
public:

	clsCurrency(enMode Mode, string Country, string CountryCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CountryCode = CountryCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}

	string CountryCode()
	{
		return _CountryCode;
	}
	
	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float Rate)
	{
		_Rate = Rate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}


	static clsCurrency FindByCode(string CountryCode)
	{
		CountryCode = clsString::UpperAllString(CountryCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);		//read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConverCurrencyDataLineToObject(Line);

				if (Currency.CountryCode() == CountryCode)
				{
					MyFile.close();
					return Currency;
				}
			}
		}

		return _GetEmptyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);		//read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConverCurrencyDataLineToObject(Line);

				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}
		}

		return _GetEmptyObject();
	}

	static bool IsCurrencyExist(string CountryCode)
	{
		clsCurrency Currency = FindByCode(CountryCode);

		return (!Currency.IsEmpty());
	}

	static vector<clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}

	static clsCurrency GetEmptyObject()
	{
		return _GetEmptyObject();
	}
};

