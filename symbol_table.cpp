#include <iostream>
#include <string>

using namespace std;

//Error list
const string INVALID = "Invalid input!!!";

//data type list
const int CHAR = 1;
const int REAL = 8;
const int STR = 24;
const int PTR = 64;
const int YN = 1;
const int HEX = 4;
const int NONE = 1;
const int INT = 4;


enum CHOICES 
{
	input = 1,
	lookup = 2,
	print = 3,
	quit = 4
};

struct Symbol
{
	string name;
	string type;
	string kind;
	int scope;
	int address;
};

//Parameter list
void print_line();
void menu();
void uppercase(string&);
Symbol InputSymbol(int&, int&);


int main()
{
	int choice = 0;			//choice from the menu
	int const SIZE = 100;	//size of the symbol table
	int counter = 0;
	Symbol sym;

	//global bs???????
	static int current_scope = 0;
	static int current_address = 0;

	Symbol table [SIZE];
	
	//intro
	cout << "This program is to implement a symbol table!" << endl;
	print_line();

	do 
	{
		menu();
		cin >> choice;

		switch (choice)
		{
		case input:

			print_line();
			break;
		case lookup:

			print_line();
			break;
		case print:

			print_line();
			break;
		case quit:
			//do nothing
			print_line();
			break;
		default:
			cout << INVALID << endl;
			print_line();
		}

	} while (choice != quit);

	return 0;
}

/*
1. Input a symbol
2. Look up a symbol
3. Print table
4. quit
*/
void menu()
{
	cout << "1. Input a symbol" << endl;
	cout << "2. Look up a symbol" << endl;
	cout << "3. Print table" << endl;
	cout << "4. Quit" << endl;
	cout << "Please choose an option: " << endl;
}

//print a seperate line
void print_line()
{
	cout << endl;
	for (int i = 0; i <= 100; i++) cout << "=";
	cout << endl;
}

//turn a string into upercase
void uppercase(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = (char)toupper(str[i]);
	}
}

/*
Get info for the new input symbol
@param current_address: of top of the stack
@return input: a new Symbol
*/
Symbol InputSymbol(int& current_address, int& current_scope)
{
    Symbol input;
    string nm, tp, kd;

    //get name
    cout << "What is the name of the symbol? ";
    cin >> nm;
    uppercase(nm);
    input.name = nm;

    //get type
    cout << "What is the type of the symbol? (char, int, real, hex, none, str, ptr, YN) ";
    cin >> tp;
    uppercase(tp);
    input.type = tp;

    //get kind
    cout << "What is the kind of symbol? (var, fun, param) ";
    cin >> kd;
	uppercase(kd);
	input.kind = kd;

    //get scope
	input.scope = current_scope;
	if (kd == "FUN") current_scope++;
    
    //get address
	switch (tp[0])
	{
	case 'C':
		input.address = current_address;
		current_address + CHAR;
		break;
	case 'I':
		input.address = current_address;
		current_address + INT;
		break;
	case 'R':
		input.address = current_address;
		current_address + REAL;
		break;
	case 'H':
		input.address = current_address;
		current_address + HEX;
		break;
	case 'N':
		input.address = current_address;
		current_address + NONE;
		break;
	case 'S':
		input.address = current_address;
		current_address + STR;
		break;
	case 'P':
		input.address = current_address;
		current_address + PTR;
		break;
	case 'Y':
		input.address = current_address;
		current_address + YN;
		break;
	}

	return input;
}
