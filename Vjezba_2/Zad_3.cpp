/*
3. Funkciju my_sort iz prethodnog zadatka napišite kao function template.
◦ Pokušajte sortirati niz tipa double pomoću funkcije ascending iz prethodnog zadatka.
◦ Napišite ascending i descending kao function template i testirajte sortiranje za
nizove tipa int, double i char.
Zašto se poziv s ascending iz prethodnog zadatka ne prevodi ?
*/

#include <iostream>
using namespace std;

template <typename T>
bool ascending(T a, T b) {
	return a < b;
}

template <typename T>
bool descending(T a, T b) {
	return a > b;
}

template <typename T>
void my_sort(T niz[], int n, bool (*cmp)(T, T)) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
            if (cmp(niz[i], niz[j])) {
            }
            else {
                T temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }
}



int main() {
    int a[] = { 5, 2, 8, 1, 4 };
    double b[] = { 3.5, 1.2, 8.7, 2.4 };
    char c[] = { 'd', 'a', 'c', 'b' };

    my_sort(a, 5, ascending<int>);  
    my_sort(b, 4, ascending<double>);
    my_sort(c, 4, ascending<char>);

    cout << "Uzlazno\nInt: ";
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }

    cout << "\nDouble: ";
    for (int i = 0; i < 4; i++) {
        cout << b[i] << " ";
    }

    cout << "\nChar: ";
    for (int i = 0; i < 4; i++) {
        cout << c[i] << " ";
    }

    cout << endl << endl;

    my_sort(a, 5, descending<int>);
    my_sort(b, 4, descending<double>);
    my_sort(c, 4, descending<char>);

    cout << "Silazno\nInt: ";
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }

    cout << "\nDouble: ";
    for (int i = 0; i < 4; i++) {
        cout << b[i] << " ";
    }

    cout << "\nChar: ";
    for (int i = 0; i < 4; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}