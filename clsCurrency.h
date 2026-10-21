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

	 static string _ConvertCurrencyObjectToDataLine(clsCurrency Currency, string Seprator = "#//#")
	 {
		 string CurrencyLine;

		 CurrencyLine = Currency.Country() + Seprator;
		 CurrencyLine = Currency.CountryCode() + Seprator;
		 CurrencyLine = Currency.CurrencyName() + Seprator;
		 CurrencyLine = to_string(Currency.Rate());

		 return CurrencyLine;
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
			 }
		 }
	 }

	 void _Update()
	 {
		 vector<clsCurrency> vCurrencies = _LoadCurrencyDataFromFile();

		 for (clsCurrency C : vCurrencies)
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
		_CurrencyName = CountryName;
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
	__declspec(property(get = Rate, put = UpdateRate)) float Rate;

	static clsCurrency FindByCode(string CountryCode)
	{
		vector<clsCurrency> vCurrencies = _LoadCurrencyDataFromFile();

		for (clsCurrency C : vCurrencies)
		{
			if (C.CountryCode() == CountryCode)
			{
				return C;
			}
		}
	}
};

