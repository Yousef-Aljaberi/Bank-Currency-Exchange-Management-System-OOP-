#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
class clsFindCurrencyScreen :protected clsScreen
{
private:
	enum enFindScreenOption { eByCode = 1, eByCountry = 2 };

	static short _ReadFindScreenOptions()
	{
		cout << "Find By: [1] Code, [2] Country ?  ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Please enter 1 or 2 ? ");
		return Choice;
	}

	static clsCurrency _FindByCode()
	{
		string CountryCode;

		cout << "\nPlease Enter Currency Code? ";
		cin >> CountryCode;

		return clsCurrency::FindByCode(CountryCode);
	}

	static clsCurrency _FindCountry()
	{
		string CountryCode;

		cout << "\nPlease Enter Currency Code? ";
		cin >> CountryCode;

		return clsCurrency::FindByCountry(CountryCode);
	}

	static void _PrintCurrecyCard(clsCurrency Currency)
	{
		cout << "Currency Card:\n";
		cout << "__________________________________________\n";
		cout << "\nCountry		: " << Currency.Country();
		cout << "\nCode    	: " << Currency.CountryCode();
		cout << "\nName    	: " << Currency.CurrencyName();
		cout << "\nRate    	: " << Currency.Rate();
		cout << "\n__________________________________________\n";
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen");

		short chois = _ReadFindScreenOptions();

		clsCurrency Currency = clsCurrency::GetEmptyObject();

		if (chois == enFindScreenOption::eByCode)
		{
			Currency = _FindByCode();
		}

		else
		{
			Currency = _FindCountry();
		}

		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrecyCard(Currency);
		}

		else
		{
			cout << "\nCurrency Not Found :-(\n";
		}

	
		
	}
};

