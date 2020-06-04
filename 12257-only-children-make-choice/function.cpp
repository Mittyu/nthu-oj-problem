#include "function.h"

Animal::Animal(Zoo *zoo, string name) : belong(zoo), species(name), legs(0) {
  zoo->born(name);
}

Dog::Dog(Zoo *zoo) : Animal(zoo, "Dog") {}
Dog::~Dog() {}

Cat::Cat(Zoo *zoo) : Animal(zoo, "Cat") {}
Cat::~Cat() {}

Caog::Caog(Zoo *zoo) : Animal(zoo, "Caog"), Dog(zoo), Cat(zoo) {}
void Caog::barking() { cout << "woof!woof!meow!\n"; }
void Caog::carton() { Cat::carton(); }
void Caog::throwBall() { Dog::throwBall(); }
Caog::~Caog() {}