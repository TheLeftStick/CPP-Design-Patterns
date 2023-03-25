#include <iostream>
#include <string>
#include "classes.h"

int main() {

	AbstractFactoryWidget* windows = new ConcreteWindow();
	AbstractFactoryWidget* mac = new ConcreteMac();

	Client(*windows);
	Client(*mac);



	return EXIT_SUCCESS;
}