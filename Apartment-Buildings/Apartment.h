#include <iostream>
#include <vector>
using namespace std;

class Home {
private:

	char* name_entrance;
	int amount_apatmen;

public:

	class Apartment {

	private:

		int num_apartment;
		int amount_people;

	public:

		class People {

		private:

			char* full_name;
			int age;

		public:

			People(const char* full_nameP, const int ageP) :full_name{ nullptr },
				age{ ageP < 0 ? ageP * -1 : ageP } {

				if (full_nameP != nullptr) {
					this->full_name = new char[strlen(full_nameP) + 1];
					for (int i{ 0 }; i <= strlen(full_nameP); i++)full_name[i] = full_nameP[i];
				}

			}

			People(const char* full_nameP) :People{ full_nameP, 0 } {}

			People() :People{ nullptr, 0 } {}

			People(const People& temp_people):People{ temp_people.full_name, temp_people.age}{}

			~People() {
				delete[]this->full_name;
			}

			string GetFullName() { return this->full_name; }

			int GetAge() { return this->age; }

		};

		vector<People> people;

		Apartment(const int num_apartmentP, const int amount_peopleP)
			:num_apartment{ num_apartmentP < 0 ? num_apartmentP * -1 : num_apartmentP },
			amount_people{ amount_peopleP < 0 ? amount_peopleP * -1 : amount_peopleP } {}

		Apartment(const int num_apartmentP) :Apartment{ num_apartmentP, 0 } {}

		Apartment() :Apartment{ 0, 0 } {}

		Apartment(const Apartment& temp_apartment)
			      :Apartment{ temp_apartment.num_apartment, temp_apartment.amount_people }{}

		int GetNumApartment() { return this->num_apartment; }

		int GetAmountPeople() { return this->amount_people; }

	};

	vector<Apartment> apartment;

	Home(const char* name_entranceP, const int amount_apatmenP) :name_entrance{ nullptr },
		 amount_apatmen{ amount_apatmenP < 0 ? amount_apatmenP * -1 : amount_apatmenP == 0? 1: amount_apatmenP } {

		if (name_entranceP != nullptr) {
			this->name_entrance = new char[strlen(name_entranceP) + 1];
			for (int i{ 0 }; i <= strlen(name_entranceP); i++)this->name_entrance[i] = name_entranceP[i];
		}

	}

	Home(const char* name_entranceP):Home{ name_entranceP , 0}{}

	Home() :Home{ nullptr , 0 } {}

	Home(const Home& temp_home):Home{ temp_home.name_entrance, temp_home.amount_apatmen}{}

	~Home() {
		delete[]this->name_entrance;
	}

	string GetNameEntrance() { return this->name_entrance; }

	int GetAmountApartment() { return this->amount_apatmen; }
};