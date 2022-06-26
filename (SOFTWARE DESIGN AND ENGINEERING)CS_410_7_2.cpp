// CS_410_7_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
using namespace std;

int num1 = 1;
int num2 = 2;
int num3 = 1;
int num4 = 1;
int num5 = 2;

string name1 = "Bob Jones";
string name2 = "Sarah Davi";
string name3 = "Amy Friend";
string name4 = "Johny Smi";
string name5 = "Carol Spea";


int DisplayInfo()
{
	cout << "Client's Name    Service Slected (1 = Brokage, 2 = Retirement)" << endl
		<< "1. " << name1 << " selected option " << num1 << endl
		<< "2. " << name2 << " selected option " << num2 << endl
		<< "3. " << name3 << " selected option " << num3 << endl
		<< "4. " << name4 << " selected option " << num4 << endl
		<< "5. " << name5 << " selected option " << num5 << endl;
	return 0;
}

int ChangeCustomerChoice()
{
	int changechoice;
	int newservice;

	cout << "Enter the number of the client that you wish to change\n";
	cin >> changechoice;
	cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)\n";
	cin >> newservice;

	if (changechoice == 1)
	{
		num1 = newservice;
	}
	else if (changechoice == 2)
	{
		num2 = newservice;
	}
	else if (changechoice == 3)
	{
		num3 = newservice;
	}
	else if (changechoice == 4)
	{
		num4 = newservice;
	}
	else if (changechoice == 5)
	{
		num5 = newservice;
	}
	return 0;
}

int CheckUserPermissionAccess()
{
	string username;
	string password;
	int buffer = 2;
	cout << "Enter your username: \n";
	cin >> username;
	cout << "Enter your password: \n";
	cin >> password;
	if (password == "123")
	{
		buffer = 1;
	}
	return buffer;
}

int main()
{
	int index = 0;
	int choice = 0;

	cout << "Hello! Welcome to our investment Company\n";

	while (index == 0)
	{
		//Lets the user log in or exit.
		cout << "Enter 1 to log in, or 2 to exit.\n";
		cin >> choice;
		if (choice == 1)
		{
			int passwordBuffer = CheckUserPermissionAccess();
			if (passwordBuffer == 2)
			{
				cout << "Invalid Password. Please try again\n";
			}
			else if (passwordBuffer == 1)
			{
				//Keeps user logged in until they exit the program.
				while (index == 0)
				{
					cout << "\nWhat would you like to do?\n"
						<< "DISPLAY the client list (enter 1)\n"
						<< "CHANGE a client's chocie (enter 2)\n"
						<< "Exit the program. . (enter 3)\n";

					cin >> choice;

					cout << "You chose " << choice << endl;

					if (choice == 1)
					{
						DisplayInfo();
					}
					else if (choice == 2)
					{
						ChangeCustomerChoice();
					}
					else if (choice == 3)
					{
						index = 1;
						break;
					}
					//Clears the reader.
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
		}
		else if (choice == 2)
		{
			index = 1;
		}

		//Clears the reader.
		cin.clear();  
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return 0;
}

	
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

