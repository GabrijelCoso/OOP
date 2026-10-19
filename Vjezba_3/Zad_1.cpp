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
#include <algorithm>
using namespace std;
void input_vector(vector<int>& v) {
	int broj = 1;
	while (broj != 0) {
		cin >> broj;
		v.push_back(broj);
		cout << endl;
		cout <<"Velicina:"<<v.size()<<endl;
		cout <<"Kapacitet:"<< v.capacity()<<endl;
	}
	v.pop_back();
}

void print_vector(const vector<int>& v) {
	for (const auto& x : v) { cout << x << " "; }
	cout << endl;
	for (auto it = v.rbegin(); it != v.rend(); ++it) {
		cout << *it << " ";
	}
}



void shrink_to_fit() {

}

int main() {
	vector <int> v1;
	vector <int> v2;
	input_vector(v1);
	print_vector(v1);
	
	

	return 0;
}