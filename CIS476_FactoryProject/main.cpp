#include <string>
#include <iostream>
#include <fstream>
#include "classes.h"

int main() {
	std::ifstream device_list("device_list.txt");
	std::string device_name;

	if (device_list.is_open()) {
		while (device_list.good()) {
			getline(device_list, device_name);

			if (device_name == "Smartphone") {
				SmartphoneFactory *smrtphn_factory = new SmartphoneFactory();
				Client(*smrtphn_factory);
			}

			else if (device_name == "Tablet") {
				TabletFactory *tblt_factory = new TabletFactory();
				Client(*tblt_factory);
			}
			
			else if (device_name == "Laptop") {
				LaptopFactory* lptp_factory = new LaptopFactory();
				Client(*lptp_factory);
			}

			else if (device_name == "Smartwatch") {
				SmartwatchFactory* smrtwtch_factory = new SmartwatchFactory();
				Client(*smrtwtch_factory);
			}

			else {
				std::cout << "Non-compatible device!" << std::endl;
			}
		}
	}
	device_list.close();
	return EXIT_SUCCESS;
}