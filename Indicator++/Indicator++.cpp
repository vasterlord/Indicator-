// Indicator++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>  
#include "Counter.h"  
#include "Electricity_meter.h" 
#include <conio.h>
using namespace std;
 

int main()
{  /////////////// Testing Counter class:
	Counter counter(0, 10000, 100); 	
	counter.operator++(); 
	counter.operator+=(50);   
	///system("Color E1"); //good color
	system("Color F3");  
	cout << counter;     
	counter(0, 10000, 1223); 
	cout << counter; 
	////////////////// Testing Electricity_metter class: 
	Electricity_meter meter(0, 10000, 123, 7, 2); 
	meter.operator++(); 
	system("Color F1");
	cout << meter; 
	double res = meter.CalcResult(); 
	cout << " Result: " << res << endl; 
	meter.Show();
	_getch();
    return 0;
}

