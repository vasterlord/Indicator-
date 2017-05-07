#include "stdafx.h"
#include "Electricity_meter.h"
#include "stdafx.h"
#include <iostream>
#include <string>    
#include <math.h>
#include <windows.h>
using namespace std;

Electricity_meter::Electricity_meter():Counter()
{ 
	_bit = 8; 
	_accuracy = 3;
}
Electricity_meter::Electricity_meter(int minValue, int maxValue, int value, int bit, int accuracy) : Counter(minValue, maxValue, value)
{ 
	SetBit(bit);
	SetAccuracy(accuracy);
} 
 
void Electricity_meter::SetBit()
{
	cout << "Enter bits of value : \n";
	try
	{
		cin >> _bit; 
		if (_bit > 8)
		{
			_bit = 8;
			throw("Maximum value of bit must be less or equal 8. Bits setted by default to 8");
		}
		else if (_bit < _accuracy)
		{
			_bit = 8;
			throw("Bits can't be less then accuracy. Bits setted by default to 8");
		}
	}
	catch (char *str)
	{
		cout << str << endl;
	}
} 

void Electricity_meter::SetAccuracy()
{
	cout << "Enter accuracy of value : \n";
	try
	{
		cin >> _accuracy;
		if (_accuracy < 0 || _accuracy > _bit)
		{
			_bit = 8;
			throw("Accuracy can't be higher then bits. Accuracy setted by default to 1");
		}
	}
	catch (char *str)
	{
		cout << str << endl;
	}
} 
 
void Electricity_meter::SetBit(int bit)
{
	try
	{
		if (bit > 8)
		{
			_bit = 8;
			throw("Maximum value of bit must be less or equal 8. Bits setted by default to 8");
		}
		else if (bit < _accuracy)
		{
			_bit = 8;
			throw("Bits can't be less then accuracy. Bits setted by default to 8");
		} 
		else
		{
			_bit = bit;
		}
	}
	catch (char *str)
	{
		cout << str << endl;
	}
}

void Electricity_meter::SetAccuracy(int accuracy)
{
	try
	{
		if (accuracy < 0 || accuracy > _bit)
		{
			_bit = 8;
			throw("Accuracy can't be higher then bits. Accuracy setted by default to 1");
		} 
		else
		{
			_accuracy = accuracy;
		}
	}
	catch (char *str)
	{
		cout << str << endl;
	}
}
   
int Electricity_meter::GetBit()  
{ 
	return _bit;
}  

int Electricity_meter::GetAccuracy()
{ 
	return _accuracy;
} 

double Electricity_meter::CalcResult()
{
	return (double)this->GetValue() / pow(10, _accuracy);
} 

istream& operator >> (istream& is, Electricity_meter& meter)
{
	meter.SetMinValue(); 
	meter.SetMaxValue();  
	meter.SetValue();
	cout << "Input bits of value: " << endl;
	cin >> meter._bit; 
	cout << "Input accuracy of value: " << endl;
	cin >> meter._accuracy;
	return is;
}

ostream& operator<<(ostream& os, Electricity_meter& meter)
{
	cout << " Value = " << meter.GetValue() << ", minimum value =  " << meter.GetMinValue() 
	<< ", maximum value = " << meter.GetMaxValue() 
	<< ", bits of value value = " << meter._bit << ", accuracy of value value = " << meter._accuracy << endl;
	return os;
}

void Electricity_meter::Show()
{
	Counter::Show(); 
	cout << " Bits of value value = " << _bit << ", accuracy of value value = " << _accuracy << ";" << endl;
}

Electricity_meter& Electricity_meter::operator=(const Electricity_meter& meter)
{
	Counter::operator=(meter);
	this->_bit = meter._bit; 
	this->_accuracy = meter._accuracy;
	return *this;
}

Electricity_meter& Electricity_meter::operator()(int minValue, int maxValue, int value, int bit, int accuracy)
{
	Counter::operator()(minValue, maxValue, value);
	this->_bit = bit; 
	this->_accuracy = accuracy;
	return *this;
}
Electricity_meter& Electricity_meter::operator++()
{
	Counter::operator++();
	return *this;
}

Electricity_meter& Electricity_meter::operator--()
{
	Counter::operator--();
	return *this;
}

Electricity_meter& Electricity_meter::operator+=(int value)
{
	Counter::operator+=(value);
	return *this;
}

Electricity_meter& Electricity_meter::operator-=(int value)
{
	Counter::operator-=(value);
	return *this;
} 

Electricity_meter::~Electricity_meter()
{ 
	OutputDebugString(L"Electricity meter destructor worked");
}
