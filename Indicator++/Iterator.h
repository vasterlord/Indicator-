#include "stdafx.h"
#include "Counter.h" 
#include "Electricity_meter.h"
#include <iostream>
#include <string>   
#include <windows.h>
using namespace std;
#pragma once 

class Iterator
{
public:
	Iterator(void);
	Iterator(Electricity_meter* ctr);
	~Iterator(void);
	Iterator(const Iterator& ctr);
	Iterator& operator = (const Electricity_meter* ctr);


	Iterator& operator += (const int& ctr);
	Iterator& operator -= (const int& ctr);
	Counter& operator * (void);
	Counter* operator -> (void);
	Counter& operator [] (const int& ctr);

	Iterator& operator ++ (void);
	Iterator operator ++ (int);
	Iterator& operator -- (void);
	Iterator operator -- (int);


	bool operator == (const Iterator& rhs);
	bool operator != (const Iterator& rhs);
	bool operator > (const Iterator& rhs);
	bool operator < (const Iterator& rhs);
	bool operator >= (const Iterator& rhs);
	bool operator <= (const Iterator& rhs);

protected:
	Electricity_meter* _ctr;
};
