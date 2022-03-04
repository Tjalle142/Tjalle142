#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DisplayMenu();
void PrintVector(vector<int> v);
void AddNumber(vector<int>& v, int number);
void DisplaySmallestNumber(vector<int>& v);
void DisplayLargestNumber(vector<int>& v);
void FindNumber(vector<int>& v, int target);


int main()
{
	char Userinput;
	vector<int> Challenge{};
	do {
	DisplayMenu();
	cin >> Userinput;

	switch (Userinput){
	case 'P':
		PrintVector(Challenge);
		cout << endl;
		break;
	case 'A':
	{
		cout << "What number would you like to add: " << endl;
		int UserAddNumber;
		cin >> UserAddNumber;
		AddNumber(Challenge, UserAddNumber);
		cout << UserAddNumber << " Has been added!" << endl;
		cout << endl;
			break;
	}
	case 'S':
		DisplaySmallestNumber(Challenge);
		cout << endl;
		break;
	case 'L':
		DisplayLargestNumber(Challenge);
		cout << endl;
		break;
	case 'F':
	{
		cout << "What number are you looking for?\n";
		int TargetNumber;
		cin >> TargetNumber;
		FindNumber(Challenge, TargetNumber);
		cout << endl;
		break;
	}
	case 'Q':
		cout << "Goodbye!";
		cout << endl;
		break;
	default:
		cout << "Invalid input try again" << endl;
		break;
	}

	} while (Userinput != 'Q');
	return 0;
}

void DisplayMenu()
{
	cout << "P - Print numbers" << endl;
	cout << "A - Add a number" << endl;
	cout << "S - Display the smallest number" << endl;
	cout << "L - Display the largest number" << endl;
	cout << "F - Find a number" << endl;
	cout << "Q - Quit" << endl;
	cout << endl;

	cout << "Enter your choice: ";
}

void PrintVector(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

void AddNumber(vector<int>& v, int number)
{
	v.push_back(number);
}

void DisplaySmallestNumber(vector<int>& v)
{
	cout << "The smallest number in Vector is: " << * min_element(v.begin(), v.end()) << endl;
}

void DisplayLargestNumber(vector<int>& v)
{
	cout << "The largest number in Vector is: " << *max_element(v.begin(), v.end()) << endl;
}

void FindNumber(vector<int>& v, int target)
{
	if (find(v.begin(), v.end(), target) != v.end())
		cout << target << " was found";
	else
		cout << target << " was not found";
	cout << endl;
}
