#include <iostream>
#include <string>
#include "classes.h"

int main() {
	Order* order = new Ticket(1, 0, 1);
	order->getDescription();
	std::cout << std::endl;

	order = new Popcorn(order, 0.6);
	order->getDescription();
	std::cout << std::endl;

	order = new Chips(order, 0.4);
	order->getDescription();
	std::cout << std::endl;

	order = new Drink(order, 2, 0);
	order->getDescription();
	std::cout << std::endl;

	order = Gift::getInstance(order);
	order->getDescription();
	std::cout << std::endl;
	
	std::cout << "Total Cost: " << order->cost() << std::endl;

	return EXIT_SUCCESS;
}