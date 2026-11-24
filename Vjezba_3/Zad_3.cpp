/*
3. Broj dana u tjednu zadajte kao constexpr int DAYS = 7;. Sati učenja po danima čuvaju
se u std::array<double, DAYS>.
◦ Napišite funkciju double total(const std::array<double, DAYS>& hours) koja
vraća ukupan broj sati u tjednu.
◦ Napišite funkciju int best_day(const std::array<double, DAYS>& hours) koja
vraća redni broj dana (od 1) s najviše sati učenja.
◦ Za prvi tjedan korisnik unosi sate za svaki dan. Pomoću funkcija ispišite ukupan
broj sati i dan s najviše sati učenja.
◦ Drugi tjedan popunite s fill(1.5). Usporedite tjedne operatorima == i <, zamijenite ih sa swap i ponovno ispišite ukupne sate.
*/

#include <iostream>
#include <array>
using namespace std;
constexpr int DAYS = 7;

double total(const array<double, DAYS>& hours) {
    double suma = 0;

    for (int i = 0; i < DAYS; i++) {
        suma += hours[i];
    }

    return suma;
}

int best_day(const array<double, DAYS>& hours) {
    int najbolji = 0;

    for (int i = 1; i < DAYS; i++) {
        if (hours[i] > hours[najbolji]) {
            najbolji = i;
        }
    }

    return najbolji + 1;
}

int main() {
    array <double, DAYS> tjedan1;
    array <double, DAYS> tjedan2;

    cout << "Unesite sate za svaki dan:\n\n";

    for (int i = 0; i < DAYS; i++) {
		cout << "Dan " << (i + 1) << ": ";
        cin >> tjedan1[i];
    }
    cout << "\nNajvise ucenja [tjedan 1]: " << best_day(tjedan1) << ". dan\n";
    cout << "\nUkupno sati [tjedan 1]: " << total(tjedan1) << endl;
    

    tjedan2.fill(1.5);
	cout << "Ukupno sati [tjedan 2]: " << total(tjedan2) << endl;

    cout << "\nJednaki tjedni: " << (tjedan1 == tjedan2) << endl;
    cout << "Prvi manji od drugog: " << (tjedan1 < tjedan2) << endl;

    swap(tjedan1, tjedan2);

    cout << "\nNakon zamjene:\n";
    cout << "Ukupno sati [tjedan 1]: " << total(tjedan1) << endl;
    cout << "Ukupno sati [tjedan 2]: " << total(tjedan2) << endl;

    return 0;
}