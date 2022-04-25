#include "config.hpp"
#include "cats.hpp"
#include "node.hpp"
#include "singlyLinkedList.hpp"
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

int main()
{
	cout << "Starting " << PROGRAM_NAME << endl;
	SinglyLinkedList catDB;
	catDB.push_front(new Cat("Loki", Color::CREAM, true, Gender::MALE, 1.0));
	catDB.push_front(new Cat("Milo", Color::BLACK, true, Gender::MALE, 1.1));
	catDB.push_front(new Cat("Bella", Color::BROWN, true, Gender::FEMALE, 1.2));
	catDB.push_front(new Cat("Kali", Color::CALICO, true, Gender::FEMALE, 1.3));
	catDB.push_front(new Cat("Trin", Color::WHITE, true, Gender::FEMALE, 1.4));
	catDB.insert_after(catDB.get_first(), new Cat("Chili", Color::GINGER, true,
		Gender::MALE, 1.5));
	for (Animal* pAnimal = (Animal*)catDB.get_first(); pAnimal != nullptr;
		 pAnimal = (Animal*)List::get_next((Node*)pAnimal))
	{
		cout << pAnimal->speak() << endl;
	}
	catDB.validate();
	catDB.dump();
	catDB.deleteAllNodes();
	catDB.dump();
	cout << "Done with " << PROGRAM_NAME << endl;

#ifndef NDEBUG
	cout << "Beginning testing for " << PROGRAM_NAME << endl;

	// Create Cat objects to test the Cat class
	Cat* testCat = new Cat("Loki", Color::CREAM, false, Gender::MALE, 1.0);
	assert(testCat->validate());
	// Change the name of the cat
	assert(testCat->getName() == "Loki");
	testCat->setName("Elijah");
	assert(testCat->getName() == "Elijah");
	// Test for isFixed variable
	assert(testCat->isFixed() == false);
	testCat->fixCat();
	assert(testCat->isFixed() == true);

	// Create Singly Linked List to test the Singly Linked List class
	SinglyLinkedList testList;
	testList.push_front(testCat);
	assert(testList.validate());
	assert(testList.size() == 1);

	// Test the insert_after function
	testList.insert_after(testList.get_first(), new Cat("Milo", Color::BLACK, true, Gender::MALE, 1.1));

	// Test pop_front function
	assert(testList.pop_front() == testCat);
	assert(testList.size() == 1);

	cout << "Ending testing for " << PROGRAM_NAME << endl;
#endif

	return (EXIT_SUCCESS);
}
