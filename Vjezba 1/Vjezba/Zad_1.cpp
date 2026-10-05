#include <iostream>

using namespace std;
int zbroj(int a,int b) {
	return a + b;
}

int sredina(int a,int b) {
	return (a + b) / 2;
}

bool usporedi(int a,int b) {
	return a < b;
}

int main() {

	int a = 5;
	int b = 9;
	bool usporedba = usporedi(a,b);

	cout << zbroj(a, b) << endl;
	cout << sredina(a,b) << endl;
	cout << usporedba << endl;

	return 0;
}