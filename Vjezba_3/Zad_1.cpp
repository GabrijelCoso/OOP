/*
1. Napišite funkcije
◦ void input_vector(std::vector<int>& v) koja unosi cijele brojeve dok se ne unese
0 (nula se ne sprema),
◦ void print_vector(const std::vector<int>& v) koja ispisuje elemente vektora.
Unesite i ispišite vektor, a zatim ga ispišite obrnutim redoslijedom(rbegin(), rend()).
◦ U prazan vektor dodajte brojeve od 1 do 20 i nakon svakog push_back ispišite
size() i capacity().
◦ Ponovite s vektorom za koji je prije petlje pozvan reserve(100), a na kraju pozovite
shrink_to_fit() i ispišite kapacitet.
*/

#include <iostream>
#include <vector>
using namespace std;

void input_vector(vector<int>& v) {
	int broj;
	while (true) {
		cin >> broj;
		if (broj == 0) break;
		v.push_back(broj);
	}
}

void print_vector(const vector<int>& v) {
	for (const auto& x : v) { cout << x << " "; }
	cout << endl;
}

int main() {
    vector<int> v1;

    cout << "Unosi brojeve (0 za kraj): ";
    input_vector(v1);

    cout << "Vektor v1: ";
    print_vector(v1);

    cout << "Obrnuti redoslijed v1: ";
    for (auto it = v1.rbegin(); it != v1.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\nVektor v2 bez reserve:\n";

    vector<int> v2;

    for (int i = 1; i <= 20; i++) {
        v2.push_back(i);
        cout << "size = " << v2.size()
            << ", capacity = " << v2.capacity() << endl;
    }

    cout << "\nVektor v3 sa reserve(100):\n";

    vector<int> v3;
    v3.reserve(100);

    for (int i = 1; i <= 20; i++) {
        v3.push_back(i);
        cout << "size = " << v3.size()
            << ", capacity = " << v3.capacity() << endl;
    }

    v3.shrink_to_fit();

    cout << "\nNakon shrink_to_fit():\n";
    cout << "size = " << v3.size()
        << ", capacity = " << v3.capacity() << endl;

    return 0;
}