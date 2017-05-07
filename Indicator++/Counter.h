#pragma once 
#include <iostream>
#include <string> 
#include <windows.h>
using namespace std; 

class Counter
{ 
private: 
	int _minValue;
	int _maxValue;
	int _value;
public:
	Counter(); 
	Counter(int minValue, int maxValue,  int value);

	void SetMinValue();
	void SetMaxValue(); 
	void SetValue();

	void SetMinValue(int minValue);
	void SetMaxValue(int maxValue);
	void SetValue(int value);

	int GetMinValue();
	int GetMaxValue();
	int GetValue();
	friend istream& operator >> (istream&, Counter&);
	friend ostream& operator << (ostream&, Counter&);

	Counter& operator=(const Counter&);
	Counter& operator()  (int minValue, int maxValue, int value); 
	Counter& operator++();
	Counter& operator--();
	Counter& operator+=(int value);
	Counter& operator-=(int value);

	virtual void Show();
	virtual ~Counter();
};

