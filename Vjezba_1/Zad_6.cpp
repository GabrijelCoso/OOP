/*
6. Definirajte strukturu Fraction(razlomak) s članovima numerator i denominator te
metodama :
◦ void reduce() — skraćuje razlomak(koristite najveći zajednički djelitelj),
◦ double value() — vraća decimalnu vrijednost,
◦ void print() — ispisuje razlomak u obliku 3 / 4.
Napišite i globalnu funkciju Fraction sum(const Fraction & a, const Fraction & b) koja
vraća skraćeni zbroj.
*/

#include <iostream>

using namespace std;
struct Fraction {
	int numerator;
	int denominator;

	void reduce() {
		int a = numerator;
		int b = denominator;
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		numerator /= a;
		denominator /= a;
	}

	double value() {
		return (double)numerator / denominator;
	}

	void print() {
		cout << numerator << " / " << denominator << endl;
	}

};

Fraction sum(const Fraction& a, const Fraction& b) {
	Fraction rezultat;
	rezultat.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	rezultat.denominator = a.denominator * b.denominator;
	rezultat.reduce();
	return rezultat;
}



int main() {

	Fraction prvi = { 12, 18 };
	Fraction drugi = { 24, 64 };	
	Fraction rezultat = sum(prvi, drugi);
	cout << "Prvi razlomak: ";
	prvi.print();
	cout << "Skraceni prvi razlomak: ";
	prvi.reduce();
	prvi.print();
	cout << "Decimalna vrijednost prvog razlomka: " << prvi.value() << endl;
	cout << "Drugi razlomak: ";
	drugi.print();
	cout << "Skraceni drugi razlomak: ";
	drugi.reduce();
	drugi.print();
	cout << "Decimalna vrijednost drugog razlomka: " << drugi.value() << endl;
	cout << "Rezultat zbrajanja razlomaka: ";
	rezultat.print();
	cout << "Decimalna vrijednost rezultata: " << rezultat.value() << endl;

	return 0;
}