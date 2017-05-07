#pragma once 
#include "stdafx.h"
#include "Counter.h" 
#include "Electricity_meter.h"
#include <iostream>
#include <string>   
#include <windows.h>
class Calculated_book
{ 
private:  
	string _date;
	double _price;  
	Counter *_book; 
	int _size;
public:
	Calculated_book();   
	Calculated_book(string date, double price, int size); 

	/*void SetDate(); 
	void SetDate(string date);
	 
	void SetPrice();  
	void SetPrice(double price); 
	 */
	//Electricity_meter& operator[](int x);
	//double GetTotalElectricity();  
	//double GetTotalPrice();

	virtual ~Calculated_book();
};

