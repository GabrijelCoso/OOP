// Vjezba 8, zadatak 2: napisite klase Enemy, Goblin, Bat, Ghost i Level iznad main.

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// ovdje napisite klase

class Enemy {
protected:
	string ime;
	int zdravlje;
public:
	Enemy(string ime,int zdravlje) : ime(ime), zdravlje(zdravlje) {}

	virtual ~Enemy() {
		cout << "Neprijatelj nestaje!" << endl;
	}

	virtual void take_damage(int d) {
		if ((zdravlje - d) < 0) {
			zdravlje = 0;
		}
		else {
			zdravlje -= d;
		}
	}


};

class Goblin : public Enemy {
protected:
	string ime;
	int zdravlje;
public:
	Goblin() : Enemy("Goblin",20) {}
};

class Bat : public Enemy {
protected:
	int udarac = 0;
public:
	Bat() : Enemy("Bat", 15) {}
	
	virtual void take_damage(){

	}
};

class Ghost : public Enemy {
protected:
	string ime;
	int zdravlje;
public:
	Ghost() :ime("Ghost"), zdravlje(30) {}
};

class Level {
private:
	vector <Enemy*> neprijatelji;
public:
	void add(Enemy neprijatelj) {

	}

	void explode(int d) {

	}

	void print() {

	}

	void remove_dead() {

	}

	int size() {

	}
};

int main()
{
    Level cave;
    cave.add(new Goblin);            // od sada je cave vlasnik neprijatelja
    cave.add(new Bat);
    cave.add(new Ghost);
    cave.add(new Goblin);
    std::cout << cave.size() << '\n';

    cave.explode(10);                // bomba pogodi sve neprijatelje
    cave.print();
    std::cout << "---\n";
    cave.explode(10);
    cave.print();
    std::cout << "---\n";
    cave.remove_dead();
    std::cout << cave.size() << '\n';
    std::cout << "--- kraj ---\n";
    return 0;                        // destruktor klase Level brise preostale neprijatelje
}

/*
Ocekivani ispis:

    4
    Goblin 10
    Bat 5
    Ghost 25
    Goblin 10
    ---
    Bat izbjegne udarac
    Goblin 0
    Bat 5
    Ghost 20
    Goblin 0
    ---
    Goblin nestaje
    Goblin nestaje
    2
    --- kraj ---
    Bat nestaje
    Ghost nestaje
*/
