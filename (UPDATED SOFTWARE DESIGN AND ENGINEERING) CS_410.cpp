// CS_410_7_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
using namespace std;

int accountOption1 = 1;
int accountOption2 = 2;
int accountOption3 = 1;
int accountOption4 = 1;
int accountOption5 = 2;

string accountName1 = "Bob Jones";
string accountName2 = "Sarah Davi";
string accountName3 = "Amy Friend";
string accountName4 = "Johny Smi";
string accountName5 = "Carol Spea";


int DisplayInfo()
{
	cout << "Client's Name    Service Slected (1 = Brokage, 2 = Retirement)" << endl
		<< "1. " << accountName1 << " selected option " << accountOption1 << endl
		<< "2. " << accountName2 << " selected option " << accountOption2 << endl
		<< "3. " << accountName3 << " selected option " << accountOption3 << endl
		<< "4. " << accountName4 << " selected option " << accountOption4 << endl
		<< "5. " << accountName5 << " selected option " << accountOption5 << endl;
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
		accountOption1 = newservice;
	}
	else if (changechoice == 2)
	{
		accountOption2 = newservice;
	}
	else if (changechoice == 3)
	{
		accountOption3 = newservice;
	}
	else if (changechoice == 4)
	{
		accountOption4 = newservice;
	}
	else if (changechoice == 5)
	{
		accountOption5 = newservice;
	}
	//Clears the reader.
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
	//Clears the reader.
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

