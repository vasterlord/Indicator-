#pragma once
#include "stdafx.h"
#include "Counter.h"
#include <iostream>
#include <string>   
#include <windows.h>
class Electricity_meter : public Counter
{ 
private: 
	int _bit; 
	int _accuracy;
public:
	Electricity_meter(); 
	Electricity_meter(int minValue, int maxValue, int value, int bit, int accracy); 
	 
	void SetBit();
	void SetAccuracy();

	void SetBit(int bit);
	void SetAccuracy(int accuracy);  
	int GetBit();
	int GetAccuracy();

	friend istream& operator >> (istream&, Electricity_meter&);
	friend ostream& operator << (ostream&, Electricity_meter&);

	Electricity_meter& operator=(const Electricity_meter&);
	Electricity_meter& operator()(int minValue, int maxValue, int value, int bit, int accuracy);
	Electricity_meter& operator++();
	Electricity_meter& operator--();
	Electricity_meter& operator+=(int value);
	Electricity_meter& operator-=(int value);

	void Show()override; 
	void Setting()override;
	void Reset()override;
	void Init()override; 
	double CalcResult()override;

	virtual ~Electricity_meter();
};

