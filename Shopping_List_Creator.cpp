// ConsoleApplication118.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
	
using namespace std;

void Greet();

void Greet2();

void new_line();

int main()
{
	int choice;
	Greet();
	cin >> choice;

	while (choice != 3)
	{
		switch (choice)
		{
		case 1:
		{
			ofstream fout;
			string file_name;
			cout << "Please enter the file name: ";
			cin >> file_name;
			string full_file_name = file_name + ".txt";
			fout.open(full_file_name, ios::app);
			if (fout.fail())
			{
				cout << "Output file opening failed.\n";
				exit(1);
			}

			time_t t = time(NULL);
			tm timeinfo;
			localtime_s(&timeinfo, &t);

			fout << "\nShopping List" << "\t\t\t\t\t";
			fout << "Date:  " << (timeinfo.tm_mday) << "/" << (timeinfo.tm_mon) + 1 << "/" << (timeinfo.tm_year) + 1900 << endl << endl;
			fout << "Item" << "\t\t\t\t\t\t\t" << "Quantity" << endl << endl;

			char response;
			char item, quantity;
			do
			{
				cout << "Please enter the item you need to buy: ";
				new_line();

				int dyn_width = 57;

				cin.get(item);
				while (item != '\n')
				{
					fout << item;
					cin.get(item);
					--dyn_width;
				}

				fout << setw(dyn_width);

				cout << "Please enter the quantity of the item you need: ";
				
				//fout << "\t\t\t\t\t\t\t";
				
				do
				{
					cin.get(quantity);
					fout << quantity;
				} while (quantity != '\n');

				fout << endl;

				cout << "Is there any more item you'd like to add? (y/n) ";
				cin >> response;
			} while ((response != 'N') && (response != 'n'));

			fout.close();
			Greet2();
			cin >> choice;
			break;
		}

		case 2:
		{
			ofstream fout;
			string file_name;
			cout << "Please enter the file name: ";
			cin >> file_name;
			string full_file_name = file_name + ".txt";
			fout.open(full_file_name, ios::app);
			if (fout.fail())
			{
				cout << "Output file opening failed.\n";
				exit(1);
			}
			double price;
			cout << "How much did you spend on your last shopping? " << (char)156;
			cin >> price;
			fout << "\t\t\t" << "Total Cost: £" << price << endl;
			cout << "Thanks. The amount has been added to your last shopping list as a record.\n";
			fout.close();
			Greet2();
			cin >> choice;
			break;
		}

		default:
			cout << "You have entered an invalid choice. Please choose again.\n";
			Greet();
			cin >> choice;
			break;
		}
	}
	
	
    return 0;
}

void Greet()
{
	cout << "Hello Alastair, how can I help you today?\n";
	cout << "1 - Create a shopping list.\n";
	cout << "2 - Enter total cost for previous shopping list.\n";
	cout << "3 - Exit the programme.\n";
}

void Greet2()
{
	cout << "Alastair, is there anything else I can help you with today?\n";
	cout << "1 - Create a shopping list.\n";
	cout << "2 - Enter total cost for previous shopping list.\n";
	cout << "3 - Exit the programme.\n";
}

void new_line()
{
	char symbol;
	do
	{
		cin.get(symbol);
	} while (symbol != '\n');
}