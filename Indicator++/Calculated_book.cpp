#include "stdafx.h"
#include "Calculated_book.h"
#include "Electricity_meter.h" 
#include "Counter.h" 
#include "stdafx.h"
#include <iostream>
#include <string>    
#include <math.h>
#include <windows.h> 

Calculated_book::Calculated_book()
{   
	SetNumberMonth();
	SetPrice(); 
	_book = new Counter[5];
	_book[0] = Electricity_meter(0, 100000, 15437, 7, 3); 
	Total_prices = new double[12];
	for (int i = 0; i < 12; i++)
	{
		Total_prices[i] = 0;
	}
	Total_electricity = new double[12];
	for (int i = 0; i < 12; i++)
	{
		Total_electricity[i] = 0;
	}
} 

Calculated_book::Calculated_book(int numberMonth, double price, int size)
{ 
	SetNumberMonth(numberMonth);
	SetPrice(price);   
	try
	{
		if (size <= 0)
		{ 
			_size = 5; 
			_book = new Electricity_meter[size];
			throw(" Size of calculate book can't less or equal 0! Size of calculate book setted by default to 5.");
		} 
		else
		{
			_size = size;
			_book = new Electricity_meter[size];
		}
	} 
	catch (char *str)
	{
		system("Color F4");
		cout << str << endl;
	}
	
	Total_prices = new double[12]; 
	for (int i = 0; i < 12; i++)
	{
		Total_prices[i] = 0;
	} 
	Total_electricity = new double[12];
	for (int i = 0; i < 12; i++)
	{
		Total_electricity[i] = 0;
	} 
	Name_month = new string[12];  
	string Months[] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	for (int i = 0; i < 12; i++)
	{
		Name_month[i] = Months[i];
	}
}
  
void Calculated_book::SetNumberMonth()
{ 
	try
	{
		cout << " Enter index of month : \n";
		cin >> _numberMonth;
		if (_numberMonth <= 0)
		{
			_numberMonth = 5;
			throw(" Number of moth can't be less or equal 0! Number of moth setted by default to 5");
		} 
		cout << "Current month is: " << Name_month[_numberMonth] << endl;
		
	}
	catch (char *str)
	{ 
		system("Color F4");
		cout << str << endl;
	}
}  

void Calculated_book::SetPrice()
{
	try
	{
		cout << " Enter price value for one KWh : \n";
		cin >> _price;
		if (_price <= 0)
		{
			_price = 10;
			throw(" Price for one KWh can't be less or equal 0! Price for one KWh setted by default to 10");
		}

	}
	catch (char *str)
	{ 
		system("Color F4");
		cout << str << endl;
	}
} 
 
void Calculated_book::SetNumberMonth(int numberMonth)
{
	try
	{
		if (numberMonth <= 0)
		{
			_numberMonth = 5;
			throw(" Number of moth can't be less or equal 0! Number of moth setted by default to 5");
		} 
		else
		{
			_numberMonth = numberMonth;
		}

	}
	catch (char *str)
	{ 
		system("Color F4");
		cout << str << endl;
	}
} 
 
void Calculated_book::SetPrice(double price)
{
	try
	{
		if (price <= 0)
		{
			_price = 10;
			throw(" Price for one KWh can't be less or equal 0! Price for one KWh setted by default to 10");
		} 
		else
		{
			_price = price;
		}

	}
	catch (char *str)
	{ 
		system("Color F4");
		cout << str << endl;
	}
}
 
int Calculated_book::GetNumberMonth()  
{ 
	return _numberMonth;
} 
 
double Calculated_book::GetPrice()
{
	return _price;
} 
 
string Calculated_book::GetMonthName()
{ 
	return Name_month[_numberMonth];
}  

double Calculated_book::GetElectricityPerMonth()
{
	return Total_electricity[_numberMonth];
}  

double Calculated_book::GetPricePerMonth()
{
	return Total_electricity[_numberMonth];
}
 
double Calculated_book::GetTotalElectricity()
{  
	double WholElectricity = 0;
	for (int i = 0; i < _size; i++)
	{
		WholElectricity += dynamic_cast <Electricity_meter&>(_book[i]).CalcResult();
	} 
	return WholElectricity;
} 
  
double Calculated_book::GetTotalPrice()  
{ 
	double WholElectricity = GetTotalElectricity(); 
	return WholElectricity * _price;
}

Counter& Calculated_book::operator[](int x)
{
	try
	{ 
		if (x < 0 || x > _size)
		{
			throw(" Incorrect number of electricity meter! ");
		}
		else
		{ 
			return _book[x];
		}
	}
	catch (char *str)
	{ 
		system("Color F4");
		cout << str << endl;
	} 
	catch (std::exception ex) {
		system("Color F4");
		cout << " Incorrect number of electricity meter! " << endl;
	}
} 
 
void Calculated_book::SafeToMonth()  
{ 
	Total_electricity[_numberMonth] = GetTotalElectricity(); 
	Total_prices[_numberMonth] = GetTotalPrice(); 
	cout << "Data saved to " << Name_month[_numberMonth] << endl;
}
 
void Calculated_book::OutputMeters()  
{ 
	for (int i = 0; i < _size;i++)
	{
		dynamic_cast <Electricity_meter&>(_book[i]).Show();
	}
}
  
void Calculated_book::InputMeters()
{
	for (int i = 0; i < _size; i++)
	{  
		cout << " Input data of electricity meter  number " << i << endl;
		Electricity_meter meter; 
		meter.InitMeters();   
		_book[i] = Electricity_meter(meter.GetMinValue(), meter.GetMaxValue(), meter.GetValue(), meter.GetBit(), meter.GetAccuracy()); 
	}
}
 
Calculated_book::~Calculated_book()
{ 
	OutputDebugString(L"Calculated_book destructor worked");  
	delete[] Total_prices; 
	delete[] Total_electricity;
	delete[] _book;
}
