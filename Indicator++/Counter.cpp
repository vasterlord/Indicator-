#include "stdafx.h"
#include "Counter.h"
#include <iostream>
#include <string>   
#include <windows.h>
using namespace std; 

Counter::Counter()
{ 
	_minValue = 0;
	_maxValue = 1000000000;
	_value = 0;
}

Counter::Counter(int minValue, int maxValue, int value)
{
	SetMinValue(minValue);
	SetMaxValue(maxValue);
	SetValue(value);
}

void Counter::SetMinValue()
{
	cout << " Enter minimum value : \n";
	try
	{
		cin >> _minValue; 
		if (_minValue < 0)
		{ 
			_minValue = 0;
			throw " Minimum value can't be less then 0! Minimum value setted by default to 0.";
		}
	}
	catch (char *str)
	{ 
		system("Color F4");
		cout << str << endl;
	}	
} 
void Counter::SetMaxValue()
{
	cout << " Enter maximum value : \n";
	try
	{
		cin >> _maxValue;
		if (_maxValue <= 0)
		{ 
			_maxValue = 1000000000;
			throw " Maximum value can't be less or equal 0! Maximum value setted by default to 1000000000.";
		}
	}
	catch (char *str)
	{		 
		system("Color F4");
		cout << str << endl;
	}
} 

void Counter::SetValue()
{
	cout << " Enter value : \n";
	try
	{
		cin >> _value;
		if ((_value >= _maxValue) || (_value < _minValue))
		{
			_value = 0;
			_minValue = 0;
			throw(" The value must be in  the correct  interval! Value setted by default to 0.");
		}
		else if (_value < 0)
		{
			_value = 0;
			_minValue = 0;
			throw(" The value must be non-negative and integer value! Value setted by default to 0.");
		}
	}
	catch (char *str)
	{ 
		system("Color F4");
		cout << str << endl;
	}
}
 
void Counter::SetMinValue(int minValue)
{  
	try
	{
		if (minValue < 0)
		{
			this->_minValue = 0;
			throw " Minimum value can't be less then 0! Minimum value setted by default to 0.";
		} 
		else  
		{ 
			this->_minValue = minValue;
		}
	}
	catch (char *str)
	{ 
		system("Color F4");
		cout << str << endl;
	}
}
void Counter::SetMaxValue(int maxValue)
{
	try
	{
		if (maxValue <= 0)
		{
			this->_maxValue = 1000000000;
			throw " Maximum value can't be less or equal 0! Maximum value setted by default to 1000000000.";
		}
		else
		{
			this->_maxValue = maxValue;
		}
	}
	catch (char *str)
	{ 
		system("Color F4");
		cout << str << endl;
	}
}
 
void Counter::SetValue(int value)
{
	try
	{
		if ((value >= _maxValue) || (value < _minValue))
		{
			this->_value = 0;
			this->_minValue = 0;
			throw(" The value must be in  the correct  interval! Value setted by default to 0.");
		}
		else if (value < 0)
		{
			this->_value = 0;
			this->_minValue = 0;
			throw(" The value must be non-negative and integer value! Value setted by default to 0.");
		} 
		else
		{
			this->_value = value;
		}
	}
	catch (char *str)
	{ 
		system("Color F4");;
		cout << str << endl;
	}
} 
 
int Counter::GetMinValue()  
{ 
	return _minValue;
}  

int Counter::GetMaxValue()
{
	return _maxValue;
}  

int Counter::GetValue()
{
	return _value;
} 

istream& operator >> (istream& is, Counter& counter)
{
	cout << " Input minimum value: " << endl;
	cin >> counter._minValue;
	cout << " Input maximum value: " << endl;
	cin >> counter._maxValue; 
	cout << " Input value: " << endl;
	cin >> counter._value;
	return is;
}

ostream& operator<<(ostream& os, Counter& counter)
{
	cout << " Value = " << counter._value<< ", minimum value =  " << counter._minValue << ", maximum value = " << counter._maxValue << endl;
	return os;
}

void Counter::Show()
{
	cout << " Value = " <<_value << ", minimum value =  " <<_minValue << ", maximum value = " <<_maxValue << endl;
} 

Counter& Counter::operator=(const Counter& counter)
{
	this->_minValue = counter._minValue;
	this->_maxValue = counter._maxValue;
	this->_value = counter._value;
	return *this;
}

Counter& Counter::operator()(int minValue, int maxValue, int value)
{
	this->_minValue = minValue;
	this->_maxValue = maxValue;
	this->_value = value;
	return *this;
}
Counter& Counter::operator++()
{
	_value++;       
	return *this;
}
 
Counter& Counter::operator--()
{
	_value--;
	return *this;
} 
 
Counter& Counter::operator+=(int value)
{  
	_value += value; 
	SetValue(_value);
	return *this;
} 
 
Counter& Counter::operator-=(int value)
{
	_value -= value;
	SetValue(_value);
	return *this;
} 

Counter::~Counter()
{   
	OutputDebugString(L"Counter destructor worked"); 
}
