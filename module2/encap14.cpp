#include<vector>
#include<iostream>
using namespace std;

// Game character base class
class GameCharacter {
	int health;
	int mana;
	
public:
	// constructor with setter validation
	GameCharacter(int health, int mana) {
		if (health < 0 || health > 100) {
			cout << "Health cannot be negative or more than 100!" << endl;
			health = 0;
		}

		if (mana < 0 || mana > 100) {
			cout << "Mana cannot be negative or more than 100!" << endl;
			mana = 0;
		}
		
		this->health = health;
		this->mana = mana;
	}

	// getters
	int getHealth() const { return health; }
	int getMana() const { return mana; }

	// virtual function to be implemented
	virtual void attack() const = 0; 
};

// derived warrior class
class Warrior : public GameCharacter {
public:
	// construct the base class
	Warrior(int health, int mana) : GameCharacter(health, mana) {

	}
	
	// implement attack class
	void attack() const override {
		if (getHealth() > 0) {
			cout << "Slashes his sword!" << endl;
		}
		else {
			cout << "Health too low! Regain some health before attacking.." << endl;
		}
	}
};

// derived mage class
class Mage : public GameCharacter {
public:
	// construct the base class
	Mage(int health, int mana) : GameCharacter(health, mana) {

	}

	// implement attack function
	void attack() const override {
		if (getMana() > 0) {
			cout << "Casts his spell!" << endl;
		}
		else {
			cout << "Mana too low! Regain some mana before attacking.." << endl;
		}
	}
};

int main() {
	// create vector of game characters
	vector<GameCharacter*> squad;

	// populate the squad with different testcases
	squad.push_back(new Mage(0, 0));
	squad.push_back(new Mage(0, 100));
	squad.push_back(new Mage(100, 100));
	squad.push_back(new Mage(100, 0));
	squad.push_back(new Warrior(0, 0));
	squad.push_back(new Warrior(0, 100));
	squad.push_back(new Warrior(100, 100));
	squad.push_back(new Warrior(100, 0));

	// start attacking
	for (GameCharacter* player : squad) {
		player->attack();
	}

}