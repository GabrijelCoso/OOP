#include <iostream>
#include <string>




int main() {
	using namespace std;
	
	int godina_rodenja;
	string ImePrezime;
	
	cout << "Upisi godinu rodjenja: " << endl;
	cin >> godina_rodenja;
	cout << "Upisi ime i prezime: " << endl;
	getline(cin, ImePrezime);
	cout << "Ime i prezime: " << ImePrezime << '\n';

	/*
	for (int i = 0; i < ImePrezime.length; i++) {
		
	}
	*/
	return 0;
}