/*
2. Korisnik unosi broj dana n, a zatim n izmjerenih temperatura.
◦ Vektor temperatura stvorite konstruktorom s n elemenata i popunite ga preko
indeksa.
◦ Napravite novi vektor promjena temperature između susjednih dana (drugi minus
prvi, treći minus drugi, …). Kroz vektor temperatura prođite iteratorima. Za novi
vektor unaprijed rezervirajte mjesto.
◦ Za izvještaj je potrebno točno 7 dana. Jednim pozivom resize skratite vektor na
7 dana ako je uneseno više, odnosno dopunite ga do 7 dana temperaturom zadnjeg
izmjerenog dana ako je uneseno manje.
Broj dana: 4 
12.5 14 13 9.5
Promjene: 1.5 -1 -3.5
Izvjestaj: 12.5 14 13 9.5 9.5 9.5 9.5
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cout << "Broj dana: ";
	cin >> n;
	
	vector<double> temperature(n);
	cout << "Unesite temperature: ";
	for (int i = 0; i < n; i++) {
		cin >> temperature[i];
	}
	
	vector<double> promjena_temperature;
	promjena_temperature.reserve(n - 1);
	for (auto it = temperature.begin(); it != temperature.end() - 1; ++it) {
		promjena_temperature.push_back(*(it + 1) - *it);
	}
	
	cout << "Promjene: ";
	for (const auto& p : promjena_temperature) {
		cout << p << " ";
	}
	
	cout << endl;
	if (n < 7) {
		temperature.resize(7, temperature.back());
	}
	else if (n > 7) {
		temperature.resize(7);
	}
	
	cout << "Izvjestaj: ";
	for (const auto& t : temperature) {
		cout << t << " ";
	}
	cout << endl;

	return 0;
}