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
} 

Calculated_book::Calculated_book(string date, double price, int size)
{ 
	/*SetDate(date); 
	SetPrice(price); */ 
	_book = new Counter[size];
}
 
Calculated_book::~Calculated_book()
{ 
	OutputDebugString(L"Calculated_book destructor worked"); 
	delete[] _book;
}
