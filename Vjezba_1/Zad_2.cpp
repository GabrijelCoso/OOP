/* 
2. Učitajte godinu rođenja(std::cin >> ), a zatim ime i prezime u jedan std::string
koristeći std::getline.Ispišite:
◦ inicijale(npr.Ana Horvat → A.H.),
◦ broj znakova imena i prezimena bez razmaka(koristite range - based for),
◦ koliko godina osoba navršava ove godine.
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {

	int godina_rodenja;
	string ime_prezime;

	cout << "Unesite godinu rodenja: ";
	cin >> godina_rodenja;
	cin.ignore();
	cout << "Unesite ime i prezime: ";
	getline(cin, ime_prezime);

	cout << "Inicijali: ";
	cout << (ime_prezime[0]) << ".";
	for (int i = 0; i < ime_prezime.length(); i++) {
		if (ime_prezime[i] == ' ') {
			cout << (ime_prezime[i + 1]) << ".";
		}
	}
	cout << endl;

	int brojZnakova = 0;
	for (char c : ime_prezime) {
		if (c != ' ') {
			brojZnakova++;
		}
	}

	cout << "Broj znakova u imenu i prezimenu: " << brojZnakova << endl;
	cout << "Godine: " << 2026 - godina_rodenja << endl;

	return 0;
}
