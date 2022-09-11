#include <iostream>
#include <vector>
using namespace std;

class Prototype {
public:
	virtual Prototype* clone()=0;
	virtual void show();
	virtual ~Prototype() {
	}
};

class ConcretePrototype: public Prototype {
	int x, y, z;
public:
	ConcretePrototype(int x = 0, int y = 0, int z = 0) :
			x { x }, y { y }, z { z } {
	}
	ConcretePrototype(ConcretePrototype *tmp) {
		this->x = tmp->x;
		this->y = tmp->y;
		this->z = tmp->z;
	}
	ConcretePrototype* clone() {
		return new ConcretePrototype(this);
	}
	void show() {
		cout << "C1 " << x << " " << y << " " << z << endl;
	}

};

class ConcretePrototype2: public Prototype {
	int x, y, z;
public:
	ConcretePrototype2(int x = 0, int y = 0, int z = 0) :
			x { x }, y { y }, z { z } {
	}
	ConcretePrototype2(ConcretePrototype2 *tmp) {
		this->x = tmp->x;
		this->y = tmp->y;
		this->z = tmp->z;
	}
	ConcretePrototype2* clone() {
		return new ConcretePrototype2(this);
	}
	void show() {
		cout << "C2 " << x << " " << y << " " << z << endl;
	}
};

int main() {
	vector<Prototype*> prots = { new ConcretePrototype, new ConcretePrototype2 };
	Prototype *tmp = prots[0]->clone();
	tmp->show();
	return 0;
}
