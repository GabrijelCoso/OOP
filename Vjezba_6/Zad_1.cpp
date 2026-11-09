#include <iostream>

class IntStack {
private:
	int* niz;
	int br_elemenata;
	int kapacitet;

public:
	IntStack(int n = 2) : kapacitet(n), br_elemenata(0), niz(new int[n]) {}

	~IntStack() {
		delete[] niz;
	}

	IntStack(const IntStack& kopija) : kapacitet(kopija.kapacitet), br_elemenata(kopija.br_elemenata),niz(new int[kopija.kapacitet]) {

		for (int i = 0; i < br_elemenata; i++) {
			niz[i] = kopija.niz[i];
		}
	}

	void push(int x) {
		if (br_elemenata == kapacitet) {
			int* novi = new int[kapacitet * 2];

			for (int i = 0; i < br_elemenata; i++) {
				novi[i] = niz[i];
			}

			delete[] niz;
			niz = novi;
			kapacitet *= 2;
		}

		niz[br_elemenata] = x;
		br_elemenata++;
	}

	int size() const {
		return br_elemenata;
	}

	int capacity() const {
		return kapacitet;
	}

	int top() const {
		if (empty()) {
			return -1;
		}
		return niz[br_elemenata - 1];
	}

	void pop() {
		if (!empty()) {
			br_elemenata--;
		}
	}

	bool empty() const {
		return br_elemenata == 0;
	}
};


int main()
{
	IntStack s;
	for (int i = 1; i <= 5; ++i)
		s.push(i * 10);
	std::cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';
	IntStack c = s;      // copy konstruktor; isto kao IntStack c(s);
	c.pop();
	c.push(99);
	std::cout << s.top() << ' ' << c.top() << '\n';
	while (!s.empty()) { std::cout << s.top() << ' '; s.pop(); }
	std::cout << '\n';
	return 0;
}