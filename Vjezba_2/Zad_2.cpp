/*
2. Napišite funkciju za sortiranje niza s prototipom
void my_sort(int arr[], int n, bool (*cmp)(int, int));
Napišite inline funkcije ascending i descending koje primaju dva int - a i vraćaju bool.
U main funkciji inicijalizirajte niz i sortirajte ga prvo uzlazno, a zatim silazno.
*/
#include <iostream>
using namespace std;
void my_sort(int arr[], int n, bool(*cmp)(int, int)) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cmp(arr[i], arr[j])) {
            }
            else {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

inline bool ascending(int a, int b) {
    return a < b;
}

inline bool descending(int a, int b) {
    return a > b;
}

int main() {
    int niz[] = { 5,2,8,1,4 };
    int n = 5;
	cout << "Niz: "<<endl;
    for (int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
    cout << endl;
	cout << "Sortiranje uzlazno: "<<endl;
    my_sort(niz, n, ascending);
    for (int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
    cout << endl;
	cout << "Sortiranje silazno: "<<endl;
    my_sort(niz, n, descending);
    for (int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
    return 0;
}