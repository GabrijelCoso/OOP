/*
4. U prostoru imena(namespace) geo definirajte konstantu PI.Napišite preopterećene funkcije :
◦ double area(double r) — površina kruga,
◦ double area(double a, double b) — površina pravokutnika,
◦ int area(int a) — površina kvadrata.
Napišite i funkciju void print_line(char c = '-', int length = 30) koja ispisuje liniju
znakova.Koristite je za odvajanje ispisa.
Prije pokretanja predvidite koja se funkcija poziva za area(5), area(5.0), area(2,3) i area('A'), a zatim provjerite.
*/

#include <iostream>
#include <cmath>

using namespace std;

namespace geo {
	const double PI = 3.14159265358979323846;
	
	double area(double r) {
		return PI * r * r;
	}

	double area(double a, double b) {
		return a * b;
	}

	int area(int a) {
		return a * a;
	}

	void print_line(char c = '-', int length = 30) {
		for (int i = 0; i < length; i++) {
			cout << c;
		}
		cout << endl;
	}
}


int main() {
	geo::print_line();
	cout <<"Povrsina kvadrata: " << geo::area(5) << endl;
	geo::print_line();
	cout << "Povrsina pravokutnika: " << geo::area(2, 3) << endl;
	geo::print_line();
	cout << "Povrsina kruga: " << geo::area(5.0) << endl;
	geo::print_line();
	cout << "Povrsina za slovo 'A': " << geo::area('A') << endl;
	geo::print_line();
	
	return 0;
}