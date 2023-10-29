#include "Apartment.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <iomanip>
using namespace std;
#pragma region Special_Abilities
void ClearScrean() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tAt home" << endl;
}
void Enter() {
	string enter;
	cin.ignore();
	do {
		cout << "Press enter to continue: "; getline(cin, enter);
	} while (!enter.empty());
}
#pragma endregion

#pragma region PrintInfo

int PrintAllHome(vector<Home> home) {
	
	if (home.size() != 0) {

		for (int i = 0; i != home.size(); i++) {

			cout << i + 1 << " - " << home[i].GetNameEntrance() << "(" << home[i].GetAmountApartment()
				 << " apartments)" << endl << endl;
		}

		return 1;

	}
	else { cout << "To display it you need to add at least one house to the list!" << endl; return 0; }
}

int PrintAllApartment(vector<Home>& home,int choice_home) {
	
	if (home[choice_home].apartment.size() > 0) {

		for (int i = 0; i != home[choice_home].apartment.size(); i++) {

			cout << i + 1 << " - Apartment number " << home[choice_home].apartment[i].GetNumApartment() << "(" 
				 << home[choice_home].apartment[i].GetAmountPeople() << " peoples in apartment)" << endl << endl;

		}

		return 1;
	}
	else { cout << "No apartments have been added to this building yet!" << endl; return 0; }
}

int PrintAllPeople(vector<Home>& home, int choice_home,int choice_apartment) {

	if (home[choice_home].apartment[choice_apartment].people.size() > 0) {

		for (int i = 0; i != home[choice_home].apartment[choice_apartment].people.size(); i++) {

			cout << i + 1 << " - People full name " 
				 << home[choice_home].apartment[choice_apartment].people[i].GetFullName() << "("
				 << home[choice_home].apartment[choice_apartment].people[i].GetAge() << " age)" << endl << endl;

		}
		return 1;
	}
	else { cout << "No peoples have been added to this apartment yet!" << endl; return 0; }
}

#pragma endregion

#pragma region Selection

int HomeSelectionAdd(vector<Home>& home, int choice) {

	if (PrintAllHome(home) == 1) {

		int choice_home = 1;

		do {

			ClearScrean();
			PrintAllHome(home);

			if (choice_home >= 1 && choice_home <= home.size())cout << "Enter number home: ";
			else cout << "There is no such choice!\nEnter number home again: ";

			cin >> choice_home;

		} while (choice_home < 1 || choice_home > home.size());

		if (home[choice_home - 1].GetAmountApartment()
			> home[choice_home - 1].apartment.size() && choice != 3)return choice_home;

		else if (home[choice_home - 1].GetAmountApartment()
			>= home[choice_home - 1].apartment.size() && choice == 3)return choice_home;

		else { cout << "The number of apartments is greater than specified in this home!" << endl; return 0; }
	}
	return 0;
}

int ApartmentSelectionAdd(vector<Home>& home, int choice_home) {

	if (PrintAllApartment(home, choice_home) == 1) {

		int choice_apartment = 1;

		do {

			ClearScrean();
			PrintAllApartment(home, choice_home);

			if (choice_apartment >= 1 && choice_apartment <= home[choice_home].apartment.size())cout << "Enter number apartment: ";
			else cout << "There is no such choice!\nEnter number apartment again: ";

			cin >> choice_apartment;

		} while (choice_apartment < 1 || choice_apartment > home[choice_home].apartment.size());

		if (home[choice_home].apartment[choice_apartment - 1].GetAmountPeople()
			> home[choice_home].apartment[choice_apartment - 1].people.size())return choice_apartment;

		else { cout << "The amount people is greater than specified in this apartment!" << endl; return 0; }

	}
}

int HomeSelectionDelete(vector<Home>& home) {
	if (PrintAllHome(home) == 1) {
		int choice_home = 1;

		do {
			ClearScrean();
			PrintAllHome(home);

			if (choice_home >= 1 && choice_home <= home.size())cout << "Enter number home: ";
			else cout << "There is no such choice!\nEnter number home again: ";

			cin >> choice_home;

		} while (choice_home < 1 || choice_home > home.size());

		return choice_home;
	}return 0;
}

int ApartmenSelectionDelete(vector<Home>& home, int choice_home) {

	if (PrintAllApartment(home, choice_home) == 1) {

		int choice_apartment_delete = 1;

		do {

			ClearScrean();
			PrintAllApartment(home, choice_home);

			if (choice_apartment_delete >= 1 && choice_apartment_delete <= home.size())cout << "Enter number apartment: ";
			else cout << "There is no such choice!\nEnter number apartment again: ";

			cin >> choice_apartment_delete;

		} while (choice_apartment_delete < 1 || choice_apartment_delete > home[choice_home].apartment.size());

		return choice_apartment_delete;
	}
	else return 0;
}

int PeopleSelectionDelete(vector<Home>& home, int choice_home, int choice_apartment) {

	if (PrintAllPeople(home, choice_home, choice_apartment) == 1) {

		int choice_people = 1;

		do {
			ClearScrean();
			PrintAllPeople(home, choice_home, choice_apartment);

			if (choice_people >= 1 && choice_people <=
				home[choice_home].apartment[choice_apartment].people.size())cout << "Enter number home: ";
			else cout << "There is no such choice!\nEnter number home again: ";

			cin >> choice_people;

		} while (choice_people < 1 || choice_people > home.size());

		return choice_people;
	}
	else return 0;
}
#pragma endregion

#pragma region AddInfo

Home AddNewHome() {

	char name_entrance[30];
	int amount_apatmen;

	ClearScrean();

	cin.ignore();
	cout << "Enter new name entrance: "; cin.getline(name_entrance, 30);

	cout << "Enter amount apatmen in home: "; cin >> amount_apatmen;

	Home temp_home{ name_entrance,amount_apatmen };

	return temp_home;
}

Home::Apartment AddNewApartment(vector<Home> home) {

	int num_apartment, amount_people;

	ClearScrean();
	cout << "Enter num new apartment: "; cin >> num_apartment;
	cout << "Enter amount people in new apartment: "; cin >> amount_people;

	Home::Apartment temp_apartment{ num_apartment,amount_people };

	return temp_apartment;
}

Home::Apartment::People AddNewPeople(vector<Home> home) {

	char full_name[40];
	int age;

	ClearScrean();

	cin.ignore();
	cout << "Enter full name new people: "; cin.getline(full_name, 40);
	cout << "Enter age new people: "; cin >> age;

	Home::Apartment::People temp_people{ full_name,age };

	return temp_people;

}
#pragma endregion

#pragma region DeleteInfo

void DeleteHome(vector<Home>& home) {

	if (PrintAllHome(home) == 1) {

		int index_delete = HomeSelectionDelete(home);

		if (index_delete != 0) {

			home.erase(home.begin() + index_delete - 1);
			cout << "House information has been successfully deleted!" << endl;
		}

	}
}

void DeleteApartment(vector<Home>& home) {

	int choice_home = HomeSelectionDelete(home);

	if(choice_home != 0){
		
		int index_delete = ApartmenSelectionDelete(home, choice_home - 1);

		if (index_delete != 0) {

			home[choice_home - 1].apartment.erase(home[choice_home - 1].apartment.begin() + index_delete - 1);
			cout << "Apartmen information has been successfully deleted!" << endl;

		}

	}
}

void DeletePeople(vector<Home>& home) {
	int choice_home = HomeSelectionDelete(home);

	if (choice_home != 0) {

		int choice_apartmen = ApartmenSelectionDelete(home, choice_home - 1);
		if (choice_apartmen != 0) {

			int index_delete = PeopleSelectionDelete(home, choice_home - 1, choice_apartmen - 1);
			if (index_delete != 0) {

				home[choice_home - 1].apartment[choice_apartmen - 1].people.erase(home[choice_home - 1].apartment[choice_apartmen - 1].people.begin() + index_delete - 1);
				cout << "People information has been successfully deleted!" << endl;
			}
		}
	}

}

#pragma endregion

int main() {

	vector<Home> home;
	int choice = 0;

	do {

		do {

			ClearScrean();
			cout << "Actions\n[1] - Add new home\n[2] - Add new apartment\n[3] - Add new people in apartment\n" 
				 << "[4] - Print all home\n[5] - Print all apartment\n[6] - Print all people\n" 
				 << "[7] - Delete home\n[8] - Delete apartment\n[9] - Delete people in apartment\n" 
				 << "[0] - Exit" << endl;

			if (choice >= 0 && choice <= 9)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while (choice < 0 || choice > 9);

		ClearScrean();

		if (choice == 1)home.push_back(AddNewHome());

		else if (choice == 2) {

			if (home.size() > 0) {

				int index = HomeSelectionAdd(home, choice);

				if (index != 0)home[index - 1].apartment.push_back(AddNewApartment(home));

			}
			else PrintAllHome(home);
		}

		else if (choice == 3) {

			if (home.size() > 0) {

				int index_home = HomeSelectionAdd(home, choice);
				if (index_home != 0) {

					int index_apatment = ApartmentSelectionAdd(home, index_home - 1);
					if (index_apatment != 0) {

						home[index_home - 1].apartment[index_apatment - 1].people.push_back(AddNewPeople(home));
					}
				}
			}
			else PrintAllHome(home);
		}

		else if (choice == 4)PrintAllHome(home);

		else if (choice == 5) {
			int choice_home = HomeSelectionDelete(home);
			if (choice_home != 0) { ClearScrean(); PrintAllApartment(home, choice_home - 1); }
		}

		else if (choice == 6) {

			int choice_home = HomeSelectionDelete(home);
			if (choice_home != 0) {

				ClearScrean();

				int choice_apartment = ApartmenSelectionDelete(home, choice_home - 1);
				if (choice_apartment != 0) { ClearScrean(); PrintAllPeople(home, choice_home - 1, choice_apartment - 1); }
			}
		}

		else if (choice == 7) DeleteHome(home);

		else if (choice == 8) DeleteApartment(home);

		else if (choice == 9) DeletePeople(home);

		if (choice != 0)Enter();

	} while (choice != 0);

	return 0;
}