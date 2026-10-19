/*
5. Definirajte strukturu Point s koordinatama x i y (double).
◦ Napišite funkcije void move_by(Point* p, double dx, double dy) i double dist(
const Point* a, const Point* b) kao u C-u, pomoću pointera.
◦ Iste funkcije napišite pomoću referenci. Usporedite pozive u main funkciji.
◦ Za niz od pet točaka pronađite točku najbližu ishodištu.
Napomena: std::sqrt se nalazi u #include <cmath>.
*/

#include <iostream>
#include <cmath>

using namespace std;

struct Point {
	double x;
	double y;
};

void move_by ( Point* p, double dx, double dy ) {
		p->x += dx;
		p->y += dy;
}

double dist ( const Point* a, const Point* b ) {
		double dx = a->x - b->x;
		double dy = a->y - b->y;
		return sqrt( dx * dx + dy * dy );
}

void move_by ( Point& p, double dx, double dy ) {
		p.x += dx;
		p.y += dy;
}

double dist ( const Point& a, const Point& b ) {
		double dx = a.x - b.x;
		double dy = a.y - b.y;
		return sqrt( dx * dx + dy * dy);
}


int main() {
	Point niz[5] = { { -1, 2 }, { 3, -4 }, { 5, 6 }, { 7, 8 }, { 0, 0 } };
	Point najbliza = niz[0];
	Point srediste = { 0, 0 };
	
	cout << "Originalni niz:";
	for (const Point& p : niz) {
		cout << " (" << p.x << ", " << p.y << ")";
	}
	cout << endl;
	
	for(const Point& p : niz) {
		if(dist(p, srediste) < dist(najbliza, srediste)) {
			najbliza = p;
		}
	}
	cout << "Najbliza tocka ishodistu je: (" << najbliza.x << ", " << najbliza.y << ")" << endl;
	
	move_by(&niz[0], 5, 5);

	najbliza = niz[0];
	cout << "Novi niz:";
	for(const Point& p : niz) {
		cout << " (" << p.x << ", " << p.y << ")";
	}
	cout << endl;
	
	for (const Point& p : niz) {
		if (dist(p, srediste) < dist(najbliza, srediste)) {
			najbliza = p;
		}
	}

	cout << "Najbliza tocka ishodistu je: (" << najbliza.x << ", " << najbliza.y << ")" << endl;

	move_by(niz[4], 5, 5);

	najbliza = niz[0];
	for (const Point& p : niz) {
		if (dist(&p, &srediste) < dist(&najbliza, &srediste)) {
			najbliza = p;
		}
	}

	cout << "Novi niz:";
	for (const Point& p : niz) {
		cout << " (" << p.x << ", " << p.y << ")";
	}
	cout << endl;
	cout << "Najbliza tocka ishodistu je: (" << najbliza.x << ", " << najbliza.y << ")" << endl;


	return 0;
}