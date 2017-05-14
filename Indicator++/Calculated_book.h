#pragma once 
#include "stdafx.h"
#include "Counter.h" 
#include "Electricity_meter.h" 
#include "Iterator.h"
#include <iostream>
#include <string>   
#include <windows.h>
class Calculated_book
{ 
private:  
	int _numberMonth;
	double _price;  
	Electricity_meter *_book; 
	int _size; 
	double * Total_prices; 
	double * Total_electricity; 
	string * Name_month;
public:
	Calculated_book();   
	Calculated_book(int numberMonth, double price, int size);

	void SetNumberMonth();
	void SetNumberMonth(int numberMoth);
	 
	void SetPrice();  
	void SetPrice(double price); 
	 
	int GetNumberMonth();  
	double GetElectricityPerMonth();
	double	GetPricePerMonth();
	double GetPrice();
	
	double GetTotalElectricity();  
	double GetTotalPrice();  
	string GetMonthName();
	void SafeToMonth(); 
	void InputMeters();
	void OutputMeters();   
	void ResetAll();

	Electricity_meter& operator[](int x);
	virtual ~Calculated_book();
};

