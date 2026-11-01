/*
4. Napišite funkciju void my_transform(int arr[], int n, int (*f)(int)) koja svaki
element niza zamijeni s f(element).
◦ Napišite funkciju twice koja broj udvostruči i predajte je funkciji my_transform.
◦ Pozovite my_transform s lambdom bez konteksta koja parne brojeve prepolovi, a
neparne udvostruči.
◦ U funkciji main(ne koristeći my_transform) lambdom s kontekstom[&] izračunajte
sumu i produkt članova niza, a lambdom s kontekstom[prag, &s] sumu članova
većih od zadanog praga.
Može li se lambda s kontekstom predati funkciji my_transform ? Zašto ?
*/

#include <iostream>
using namespace std;

void my_transform(int niz[], int n, int (*funkcija)(int)){
	for (int i = 0; i < n; i++) {
		niz[i] = funkcija(niz[i]);
	}
}

int twice(int x) {
	return x * 2;
}

int main() {
	int niz[] = { 2, 3, 4, 5, 6 };
	int n = 5;
	int prag = 10;
	int s = 0;
	int sum = 0;
	int prod = 1;

	auto suma =	[&]() {
		sum = 0;
		prod = 1;
		for (int i = 0; i < n; i++) {
			sum += niz[i];
			prod *= niz[i];
		}
	};

	auto suma_prag = [prag,&s](int niz[],int n) {
		for (int i = 0; i < n; i++) {
			if (niz[i] > prag) {
				s += niz[i];
			}
		}
	};

	cout << "Niz: " << endl;
	for (int i = 0; i < n; i++) {
		cout << niz[i] << " ";
	}
	cout << endl;

	my_transform(niz, n, [](int x) { return (x % 2 == 0) ? x / 2 : x * 2; });
	cout <<endl <<"Niz nakon transformacije: " << endl;
	for (int i=0; i<n; i++) {
		cout << niz[i] << " ";
	}
	cout << endl;

	my_transform(niz, n, twice);
	cout << endl << "Niz nakon twice: " << endl;
	for (int i = 0; i < n; i++) {
		cout << niz[i] << " ";
	}
	cout << endl << endl;

	suma();
	cout << "Suma: " << sum << endl << endl;
	cout << "Produkt: " << prod << endl << endl;

	suma_prag(niz, n);
	cout << "Suma vecih od " << prag << ": " << s << endl;
	return 0;
} 