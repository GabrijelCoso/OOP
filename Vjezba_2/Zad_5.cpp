/*
5. Napišite inline funkcije add, subtract, multiply i divide s prototipom
double(double, double).
◦ Spremite adrese funkcija u niz function pointera.
◦ Korisnik unosi dva broja i redni broj operacije(0–3), a program poziva odgovarajuću
funkciju iz niza.
◦ Za dijeljenje s nulom ispišite poruku umjesto rezultata.
*/

#include <iostream>
using namespace std;

inline double add(double a, double b) {
    return a + b;
}

inline double subtract(double a, double b) {
    return a - b;
}

inline double multiply(double a, double b) {
    return a * b;
}

inline double divide(double a, double b) {
    return a / b;
}

int main() {
    double num1, num2;
    int operation;

	cout << "Upisite dva broja: ";
    cin >> num1 >> num2;

    cout << "Upisite redni broj operacije [0-3]: ";
    cin >> operation;

    double (*functions[4])(double, double) = {add, subtract, multiply, divide};

    if (operation >= 0 && operation < 4) {
        if (operation == 3 && num2 == 0) {
            cout << "Ne smije se dijeliti s nulom." << endl;
        }
        else {
            cout << "Rezultat: " << functions[operation](num1, num2) << endl;
        }
    }
    else {
        cout << "Nevazeci unos." << endl;
    }

	return 0;
}