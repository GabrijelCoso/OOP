#include <iostream>
#include <string>

#define MAX(a,b) ((a > b) ? (a) : (b))

using namespace std;

inline int my_max(int i, int broj) {
	return (i > broj) ? i : broj;
}

template<typename T>
inline T my_maxx(const T& a, const T& b) {
	return (a > b) ? a : b;
}


int main() {

	int a = MAX(3, 5);
	int b = 2 * MAX(3, 5);
	int c = MAX(3, 5) + 1;

	cout << "a: " << a << endl << "b: " << b << endl << "c: " << c << endl << endl;

	int i = 3;
	int max = MAX(++i, 2);
	cout << "MAX:" << max << endl;
	cout << "i nakon MAX:" << i << endl << endl;
	cout << "my_max:" << my_max(++i, 2) << endl;
	cout << "i nakon my_max:" << i << endl << endl;
	cout << "my_max za int:" << my_maxx(2, 3) << endl;
	cout << "my_max za double:" << my_maxx(1.2, 2.3) << endl;
	cout << "my_max za char:" << my_maxx('a', 'b') << endl;
	cout << "my_max za string:" << my_maxx<string>("abc", "abd") << endl;

	return 0;
}