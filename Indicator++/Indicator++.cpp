// Indicator++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>  
#include "Counter.h" 
#include <conio.h>
using namespace std;

int main()
{  
	Counter counter(0, 10000, 100); 	
	counter.operator++(); 
	counter.operator+=(50);   
	///system("Color E1"); //good color
	system("Color F5");
	cout << counter;  
	_getch();
    return 0;
}

