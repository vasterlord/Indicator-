// Indicator++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>  
#include "Counter.h"  
#include "Electricity_meter.h"  
#include "Calculated_book.h" 
#include <conio.h>
using namespace std;
 

int main()
{ 
	system("Color F1");  
	int choose; 
	string choice = "y";  
	int size = 1; 
	double price = 0; 
	int numberMonth = 5;
	cout << " Input size of calculated book :" << endl; 
	cin >> size;  
	cout << " Enter index of month : \n";
	cin >> numberMonth;
	cout << " Enter price value for one KWh : \n";
	cin >> price; 
	int number = 0; 
	int additionalValue = 2; 
		Calculated_book c(numberMonth, price, size);	
	while (choice == "y")
	{
		system("Color F1");
		cout << " 1 - Input electricity meters" << endl; 
		cout << " 2 - Ascending value one of electricity meters by 1 " << endl; 
		cout << " 3 - Descending value one of electricity meters by 1 " << endl; 
		cout << " 4 - Ascending value one of electricity meters by value " << endl;
		cout << " 5 - Descending value one of electricity meters by value " << endl; 
		cout << " 6 - Get total price and electricity " << endl;  
		cout << " 7 - Save total price and electricity to month " << endl; 
		cout << " 8 - Get total price and electricity per month " << endl; 
		cout << " 9 - Change number of month " << endl; 
		cout << " 10 - Change price for one KWh " << endl;
		cout << " 11 - Change data of one electricity meter (without change value) " << endl; 
		cout << " 12 - Reset one of electricity meters " << endl;
		cout << " 13 - Output one electricity meter " << endl;
		cout << " 14 - Output electricity meters " << endl;
			cout << "Your choice: "; cin >> choose;
			cout << endl;
			switch (choose)
			{
			case 1:  
				system("Color F1");
				c.InputMeters();
				break;
			case 2:  
				system("Color F1");
				cout << " Input number of electricity meter :" << endl;
				cin >> number;  
				cout << " Old value of electricity meter : " << c.operator[](number).GetValue() << endl;
				c.operator[](number).operator++(); 
				cout << " New value of electricity meter : " << c.operator[](number).GetValue() << endl;
				break;
			case 3:  
				system("Color F1");
				cout << " Input number of electricity meter :" << endl;
				cin >> number; 
				cout << " Old value of electricity meter : " << c.operator[](number).GetValue() << endl;
				c.operator[](number).operator--(); 
				cout << " New value : " << c.operator[](number).GetValue() << endl;
				break;
			case 4:  
				system("Color F1");
				cout << " Input number of electricity meter :" << endl;
				cin >> number; 
				cout << " Input value for changing :" << endl;
				cin >> additionalValue; 
				cout << " Old value of electricity meter : " << c.operator[](number).GetValue() << endl;
				c.operator[](number).operator+=(additionalValue); 
				cout << " New value of electricity meter : " << c.operator[](number).GetValue() << endl;
				break; 
			case 5:  
				system("Color F1");
				cout << " Input number of electricity meter :" << endl;
				cin >> number;
				cout << " Input value for changing :" << endl;
				cin >> additionalValue; 
				cout << " Old value of electricity meter : " << c.operator[](number).GetValue() << endl;
				c.operator[](number).operator-=(additionalValue); 
				cout << " New value of electricity meter : " << c.operator[](number).GetValue() << endl;
				break;
			case 6:  
				system("Color F1");
				cout << " Total electricity: " << c.GetTotalElectricity() << endl;  
				cout << " Total price: " << c.GetTotalPrice() << endl;
				break;
			case 7: 
				c.SafeToMonth();
				break;
			case 8:  
				system("Color F1");
				cout << " Total electricity and price per " << c.GetMonthName() << " :" << endl; 
				cout << " total electricity: " << c.GetElectricityPerMonth() << endl;
				cout << " total price: " << c.GetPricePerMonth() << endl;
				break; 
			case 9:  
				system("Color F1");
				c.SetNumberMonth();
				break;
			case 10:  
				system("Color F1");
				c.SetPrice();
				cout << "Current price is " << c.GetPrice() << endl;
				break;
			case 11:  
				system("Color F1");
				cout << " Input number of electricity meter :" << endl;
				cin >> number;  
				//c.operator[](number).FullySetting();
				break;  
			case 12:    
				system("Color F4");
				cout << " Input number of electricity meter :" << endl;
				cin >> number;
				//c.operator[](number).Reset(); 
				cout << " Reset of electricity meter with number " << number << " done successfully" << endl;
				break;
			case 13: 
				system("Color F1");
				cout << " Input number of electricity meter :" << endl;
				cin >> number;
				c.operator[](number).Show();
				break; 
			case 14: 
				system("Color F1");
				c.OutputMeters();
				break; 
			default:
				break;
			}
			system("Color E1");
		cout << "Do you want to continue? Press 'y' if you want to continue and something else if you don't want to continue: "; cin >> choice;
	} 
	_getch();
    return 0;
}

