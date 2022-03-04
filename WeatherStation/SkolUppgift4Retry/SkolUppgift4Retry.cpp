#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Stad {
public:
	string namn;
	int temp;
	string ToString()
	{
		return "City " + namn + " Temp " + to_string(temp);
	}
	Stad(string _namn, int _temp)
	{
		namn = _namn;
		temp = _temp;
	}
};


vector<Stad>Citys{};


int LineSearch(vector<Stad> &list, int n, int söktemp);
void BubbleSort(vector<Stad> &list, int n);
int BinarySearch(vector<Stad> &list, int left, int right, int search);
int HighestTemp(vector<Stad> &list);
int LowestTemp(vector<Stad> &list);


int main()
{
	for (int i = 0; i < 4; i++)
	{
		string CityNameInput;
		int CityTempInput;
		cout << "Enter name of city\n";
		cin >> CityNameInput;
		cout << "Enter temp of city\n";
		cin >> CityTempInput;
		while (CityTempInput < -60 || CityTempInput > 60) 
		{
			cin.clear();
			cin.ignore(10000,'\n');
			cout << "That's not accurate weather, should be between -60C & 60C! ...Enter again" << endl;
			cin >> CityTempInput;
		}
		Citys.push_back(Stad(CityNameInput, CityTempInput)); 
	}

	cout << endl;
	int LineResult = LineSearch(Citys, Citys.size(), 10); 
	(LineResult == -1) ? cout << "Temp was not found" : cout << "Linear search was done and temp was found at Index " << LineResult; 
	cout << endl << endl;
	BubbleSort(Citys, Citys.size()); 
	for (int i = 0; i < Citys.size(); i++) 
	{
		cout << Citys[i].ToString() << endl;
	}

	cout << endl;
	cout << "Highest temp: " << Citys[HighestTemp(Citys)].ToString() << endl; 
	cout << "Lowest temp: " << Citys[LowestTemp(Citys)].ToString() << endl; 
	cout << endl;

	int BinaryResult = BinarySearch(Citys, 0, Citys.size() - 1, 10); 
	(BinaryResult == -1) ? cout << "Temp was not found" : cout << "Binary search was done and temp was found at Index " << BinaryResult; 

	cout << endl << endl;
	cout << "Thank you, Goodbye!" << endl;
	return 0;
}

int LineSearch(vector<Stad> &list, int n, int searchtemp) // Deklarerar min funktion Linjesökning
{
	for (int i = 0; i < n; i++)
	{
		if (list[i].temp == searchtemp)
			return i;
	}
	return -1;
}


void BubbleSort(vector<Stad> &list, int n) // Deklarerar min funktion Bubblesort
{
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (list[j].temp > list[j + 1].temp)
			{
				Stad Sort = list[j + 1];
				list[j + 1] = list[j];
				list[j] = Sort;
			}
		}
	}
} 

int BinarySearch(vector<Stad> &list, int left, int right, int search)// Deklarerar min funktion BinarySearch som gör en binärsökning på min vector
{
	if (right >= left) {
		int mid = (left + right) / 2;

		if (list[mid].temp == search)
			return mid;
		if (list[mid].temp > search)
			return BinarySearch(list, left, mid - 1, search);
			
		return BinarySearch(list, mid + 1, right, search);
	}
	return -1;
}

int HighestTemp(vector<Stad> &list)//Deklarerar min funktion HighestTemp som tar reda på den högsta tempen i min Vector
{
	int HighestIndex = 0 ;
	for (int i = 1; i < list.size(); i++)
	{
		if (list[i].temp > list[HighestIndex].temp)
			HighestIndex = i;
	}
	return HighestIndex;
}

int LowestTemp(vector<Stad> &list)//Deklarerar min funktion LowestTemp som tar reda på den lägsta tempen i min Vector
{
	int LowestIndex = 0 ;
	for (int i = 1; i < list.size(); i++)
	{
		if (list[i].temp < list[LowestIndex].temp)
			LowestIndex = i;
	}
	return LowestIndex;
}
