// Heap Data Member
// Demonstrates an object with a dynamically allocated data Member

#include <iostream>
#include <string>

class Critter {
	public:
		Critter(const std::string& name = "", int age = 0);
		~Critter(); // destructor prototype
		Critter(const Critter& c); // copy constructor prototype
		Critter& operator=(const Critter& c); // overloaded assignment op
		void Greet() const;
	private:
		std::string* m_pName;
		int m_Age;
};

Critter::Critter(const std::string& name, int age) {
	std::cout << "Constructor called\n";
	m_pName = new std::string(name);
	m_Age = age;
}

// destructor definition
Critter::~Critter() {
	std::cout << "Destructor called\n";
	delete m_pName;
}

// copy constructor
Critter::Critter(const Critter& c) {
	std::cout << "Copy constructor called\n";
	m_pName = new std::string(*(c.m_pName));
	m_Age = c.m_Age;
}

// overloaded assignment op
Critter& Critter::operator=(const Critter& c) {
	std::cout << "Overloaded Assignment Operator called\n";
	if (this == &c) {
		return *this;
	}

	delete m_pName;
	m_pName = new std::string(*(c.m_pName));
	m_Age = c.m_Age;
	return *this;
}

void Critter::Greet() const {
	std::cout << "I'm " << *m_pName << " and I'm " << m_Age << " years old. ";
	std::cout << "&m_pName: " << &m_pName << std::endl;
}

void testDestructor();
void testCopyConstructor(Critter aCopy);
void testAssignmentOp();

int main() {
	testDestructor();

	std::cout << std::endl;
	Critter crit("Poochie", 5);
	crit.Greet();
	testCopyConstructor(crit);
	crit.Greet();
	std::cout << std::endl;

	testAssignmentOp();
	return 0;
}

void testDestructor() {
	Critter toDestroy("Rover", 3);
	toDestroy.Greet();
}

void testCopyConstructor(Critter aCopy) {
	aCopy.Greet();
}

void testAssignmentOp() {
	Critter crit1("crit1", 7);
	Critter crit2("crit2", 9);
	crit1 = crit2;
	crit1.Greet();
	crit2.Greet();
	std::cout << std::endl;

	Critter crit3("crit", 11);
	crit3= crit3;
	crit3.Greet();
}
