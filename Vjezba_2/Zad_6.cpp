/*
6. Definirajte strukturu Student koja sadrži ime, JMBAG, godinu studija, broj položenih
ECTS bodova u godini i prosjek ocjena. Napišite funkciju
void filter_students(Student s[], int n,
void (*action)(Student&),
bool (*cond)(const Student&));
koja akciju izvrši nad svakim studentom koji zadovoljava uvjet. Akcije napišite kao
funkcije, a uvjete kao lambda izraze. Pozivom funkcije filter_students:
◦ ispišite sve studente prve godine koji su položili barem jedan ispit,
◦ ispišite sve studente s prosjekom većim od 3.5,
◦ povećajte godinu studija svim studentima koji su položili barem 45 ECTS bodova.
*/

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string ime;
    string jmbag;
    int godina;
    int ects;
    double prosjek;
};

void ispis_studenta(Student& s) {
    cout << "Ime: " << s.ime << ", JMBAG: " << s.jmbag << ", Godina: " << s.godina  << ", ECTS: " << s.ects << ", Prosjek: " << s.prosjek << std::endl;
}

void povecaj_godinu(Student& s) {
    s.godina ++;
}

void filter_students(Student s[], int n, void (*action)(Student&), bool (*cond)(const Student&)) {
    for (int i = 0; i < n; i++) {
        if (cond(s[i])) {
            action(s[i]);
        }
    }
}

int main() {

	Student students[] = {
		{ "Gabrijel", "123456789", 1, 10, 3.0 },
		{ "Ivan", "987654321", 2, 50, 4.0 },
		{ "Marko", "456789123", 1, 0, 2.5 },
		{ "Ema", "321654987", 3, 60, 4.5 },
		{ "Nikola", "654987321", 2, 30, 3.8 }
	};

	int n = sizeof(students) / sizeof(students[0]);
	cout << "\nStudenti:" << endl;
	for (int i = 0; i < n; i++) {
		ispis_studenta(students[i]);
	}
	cout << endl;

	cout << "Studenti s prve godine koji su polozili barem jedan ispit:" << endl;
	filter_students(students, n, ispis_studenta, [](const Student& s) { return s.godina == 1 && s.ects > 0; });

	cout << "\nStudenti s prosjekom vecim od 3.5:" << endl;
	filter_students(students, n, ispis_studenta, [](const Student& s) { return s.prosjek > 3.5; });
	
	cout << "\nPovecavanje godine za studente s barem 45 ECTS bodova:" << endl;
	filter_students(students, n, povecaj_godinu, [](const Student& s) { return s.ects >= 45; });
	
	cout << "\nStudenti nakon azuriranja:" << endl;
	for (int i = 0; i < n; i++) {
		ispis_studenta(students[i]);
	}

	return 0;
}