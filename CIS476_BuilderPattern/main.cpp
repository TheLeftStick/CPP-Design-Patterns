#include <iostream>
#include <string>
#include <vector>
#include "classes.h"

int main() {
	// Create Shop and VehicileBuilders
	Shop* shop = new Shop();

	VehicleBuilder* bMiniVan = new MiniVan();
	VehicleBuilder* bSportsCar = new SportsCar();
	VehicleBuilder* bMotorcycle = new Motorcycle();

	// Construct three vehicles
	shop->construct(bMiniVan);
	Vehicle* pMiniVan = bMiniVan->getResult();
	std::cout << "MiniVan -------" << std::endl;
	pMiniVan->show();

	shop->construct(bSportsCar);
	Vehicle* pSportsCar = bSportsCar->getResult();
	std::cout << "SportsCar -------" << std::endl;
	pSportsCar->show();

	shop->construct(bMotorcycle);
	Vehicle* pMotorcylce = bMotorcycle->getResult();
	std::cout << "Motorcycle -------" << std::endl;
	pMotorcylce->show();

	return EXIT_SUCCESS;
}