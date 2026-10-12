/*

Zadan je niz int numbers[] = { 4, -7, 12, 0, 9, -3 };
◦ Koristeći range - based for ispišite niz, a zatim svaki negativni element zamijenite njegovom apsolutnom vrijednošću.
◦ Napišite funkciju int& find_max(int arr[], int n) koja vraća referencu na najveći element niza.Koristeći povratnu vrijednost kao lvalue, postavite najveći element na 0 i ispišite niz.

*/

#include <iostream>

int& najveci(int niz[], int n) {
	int maxIndex = 0;

	for (int i = 1; i < n; i++) {
		if (niz[i] > niz[maxIndex]) {
			maxIndex = i;
		}
	}
	return niz[maxIndex];
}

int main() {
	
	using namespace std;
	int numbers[] = { 4, -7, 12, 0, 9, -3 };

	for (int& broj:numbers) {
		cout << broj << " ";
		if (broj < 0) {
			broj = abs(broj);
		}
	}
	cout << endl;

	for (int& broj : numbers) {
		cout << broj << " ";
	}
	cout << endl;

	najveci(numbers, 6) = 0;
	for (int& broj : numbers) {
		cout << broj << " ";
	}
	cout << endl;

	return 0;
}