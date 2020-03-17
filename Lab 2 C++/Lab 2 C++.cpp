#include <iostream>

using namespace std;

struct Date
{
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	if ((day < 1) || (month < 1) || (year < 1))
		result = false;
	else {
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if ((day <= 31) && (day > 0))
				result = true;
			break;
		}

		case 4:
		case 6:
		case 9:
		case 11:
		{
			if ((day <= 30) && (day > 0))
				result = true;
			break;
		}

		case 2:
		{
			if (year % 4 != 0)
			{
				if ((day <= 28) && (day > 0))
					result = true;
			}
			else
				if (year % 400 == 0)
				{
					if ((day <= 29) && (day > 0))
						result = true;
				}
				else
					if ((year % 100 == 0) && (year % 400 != 0))
					{
						if ((day == 28) && (day > 0))
							result = true;
					}
					else
						if ((year % 4 == 0) && (year % 100 != 0))
							if ((day <= 29) && (day > 0))
								result = true;
			break;
		}

		default:
			result = false;
		}
	}
	return result;
}

struct Address
{
	int Index;
	char Country[56], Region[56], Area[56], Town[32], Street[32];
	int House;
	int Apartment;
};


struct Person
{
	char FirstName[56], SecondName[32], LastName[32];
	char Sex[7];
	char Nationality[115];
	int Height;
	int Weight;
	Date Birthday;
	int Tele;
	Address Home;
};

Person InitPerson();
Person* InitArray(int);
void DisplayArray(Person*, int);
void DisplayChoise(Person*, int, char*, int, int);
void DisplayPerson(Person);
void SortFirstName(Person*, int);

int main(void)
{
	int Dimension;
	char SexTag[7];
	int LowHeight, UpperHeight;
	Person* MassiveStruct;

	cout << "Input the number of person: ";
	while (!(cin >> Dimension))
	{
		cout << "Input the number of person: ";
		cin >> Dimension;
		cin.clear();
		cin.ignore(std::cin.rdbuf()->in_avail());
	}
	if (Dimension < 1)
	{
		cout << "\nDynamic array don't exist!\n";
		return 0;
		exit(1);
	}

	MassiveStruct = InitArray(Dimension);

	cout << "The list af persons:" << endl;
	DisplayArray(MassiveStruct, Dimension);

	cout << "Input Gender :";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(SexTag, 7);

	cout << "Input the boundary of height :";
	cin >> LowHeight >> UpperHeight;
	while (UpperHeight <= LowHeight)
	{
		cout << "Input the boundary of height :";
		cin >> LowHeight >> UpperHeight;
	}

	cout << "\nThe list of choise-persons" << endl;
	DisplayChoise(MassiveStruct, Dimension, SexTag, LowHeight, UpperHeight);

	cout << "\nThe list of sorting persons" << endl;
	SortFirstName(MassiveStruct, Dimension);
	DisplayArray(MassiveStruct, Dimension);

	free(MassiveStruct);
	return 0;
}

Person InitPerson()
{
	Person Man;

	cout << "------------------" << endl;
	cout << "Input first name: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(Man.FirstName, 56);

	cout << "Input second name: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(Man.SecondName, 32);

	cout << "Input last name: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(Man.SecondName, 32);

	cout << "Input sex: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(Man.Sex, 7);

	cout << "Input nationality: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(Man.Nationality, 115);

	cout << "Input height: ";
	while (!(cin >> Man.Height))
	{
		cout << "Input height: ";
		cin >> Man.Height;
		cin.clear();
		cin.ignore(std::cin.rdbuf()->in_avail());
	}

	cout << "Input weight: ";
	while (!(cin >> Man.Weight))
	{
		cout << "Input weight: ";
		cin >> Man.Weight;
		cin.clear();
		cin.ignore(std::cin.rdbuf()->in_avail());
	}

	do
	{
		cout << "Input birthday: ";
		cin.clear();
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> Man.Birthday.day >> Man.Birthday.month >> Man.Birthday.year;
	} while (!Man.Birthday.isCorrect());

	cout << "Input telephone number: ";
	while (!(cin >> Man.Tele))
	{
		cout << "Input telephone number: ";
		cin >> Man.Tele;
		cin.clear();
		cin.ignore(std::cin.rdbuf()->in_avail());
	}

	cout << "Input index: ";
	while (!(cin >> Man.Home.Index))
	{
		cout << "Input index: ";
		cin >> Man.Home.Index;
		cin.clear();
		cin.ignore(std::cin.rdbuf()->in_avail());
	}

	cout << "Input country: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(Man.Home.Country, 56);

	cout << "Input region: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(Man.Home.Region, 56);

	cout << "Input area: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(Man.Home.Area, 56);

	cout << "Input town: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(Man.Home.Town, 56);

	cout << "Input street: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(Man.Home.Street, 32);

	cout << "Input house: ";
	while (!(cin >> Man.Home.House))
	{
		cout << "Input house: ";
		cin >> Man.Home.House;
		cin.clear();
		cin.ignore(std::cin.rdbuf()->in_avail());
	}

	cout << "Input apartment: ";
	while (!(cin >> Man.Home.Apartment))
	{
		cout << "Input apartment: ";
		cin >> Man.Home.Apartment;
		cin.clear();
		cin.ignore(std::cin.rdbuf()->in_avail());
	}
	cout << "------------------" << endl;

	return Man;
}

Person* InitArray(int Dimansion)
{
	Person* Massive = (Person*)malloc(Dimansion * sizeof(Person));
	if (Massive == NULL) return NULL;
	for (int i = 0; i < Dimansion; i++)
	{
		cout << "Enter information about person(" << i + 1 << ")" << endl;
		Massive[i] = InitPerson();
	}
	return Massive;
}

void DisplayArray(Person* Massive, int Dimansion)
{
	for (int i = 0; i < Dimansion; i++)
	{
		DisplayPerson(Massive[i]);
	}
}

void DisplayChoise(Person* Massive, int Dimension, char* SexTag, int LowHeight, int UpperHeight)
{
	for (size_t i = 0; i < Dimension; i++)
	{
		if (
			strcmp(Massive[i].Sex, SexTag) == 0 &&
			Massive[i].Height <= UpperHeight &&
			Massive[i].Height >= LowHeight
			)
		{
			DisplayPerson(Massive[i]);
		}
	}
}

void DisplayPerson(Person Man)
{
	cout << "-------------------------------" << endl;
	cout << "Full name: " << Man.FirstName << " " << Man.SecondName << " " << Man.LastName << endl;
	cout << "Gender: " << Man.Sex<< endl;
	cout << "Nationality: " << Man.Nationality << endl;
	cout << "Height: " << Man.Height << endl;
	cout << "Weight: " << Man.Weight << endl;
	cout << "Birthday: " << Man.Birthday.day << "." << Man.Birthday.month << "." << Man.Birthday.year << endl;
	cout << "Telephone number: " << Man.Tele << endl;
	cout << "=====Adress=====" << endl;
	cout << "Index: " << Man.Home.Index << endl;
	cout << "Country: " << Man.Home.Country << endl;
	cout << "Region: " << Man.Home.Region << endl;
	cout << "Area: " << Man.Home.Area << endl;
	cout << "Town: " << Man.Home.Town << endl;
	cout << "Street: " << Man.Home.Street << endl;
	cout << "House: " << Man.Home.House << endl;
	cout << "Apartment: " << Man.Home.Apartment << endl;
	cout << "================" << endl;
	cout << "-------------------------------" << endl;
}

void SortFirstName(Person* Massive, int Dimension)
{
	Person Temp;
	for (size_t i = 0; i <= Dimension; i++)
	{
		for (size_t q = Dimension - 1; q > i; q--)
		{
			if (strcmp(Massive[q].FirstName, Massive[q - 1].FirstName) < 0)
			{
				Temp = Massive[q];
				Massive[q] = Massive[q - 1];
				Massive[q - 1] = Temp;
			}
		}
	}
}