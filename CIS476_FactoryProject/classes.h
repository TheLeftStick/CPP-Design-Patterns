#pragma once
// Abstract Product A
class Battery { 
	public:
		virtual ~Battery() {};
		virtual std::string getDeviceComponent() const = 0;
};

// Concrete Product A1
class BatterySmartphone : public Battery { 
	public:
		std::string getDeviceComponent() const override {
			return "Battery Smartphone";
		}
};

// Concrete Product A2
class BatteryTablet : public Battery { 
	public:
		std::string getDeviceComponent() const override {
			return "Battery Tablet";
		}
};

// Concrete Product A3
class BatteryLaptop : public Battery { 
	public:
		std::string getDeviceComponent() const override {
			return "Battery Laptop";
		}
};

// Concrete Product A4
class BatterySmartwatch : public Battery { 
	public:
		std::string getDeviceComponent() const override {
			return "Battery Smartwatch";
		}
};

// Abstract Product B
class Display { 
	public:
		virtual ~Display() {};
		virtual std::string getDeviceComponent() const = 0;
};

// Concrete Product B1
class DisplaySmartphone : public Display {
	public:
		std::string getDeviceComponent() const override {
			return "Display Smartphone";
		}
};

// Concrete Product B2
class DisplayTablet : public Display {
	public:
		std::string getDeviceComponent() const override {
			return "Display Tablet";
		}
};

// Concrete Product B3
class DisplayLaptop : public Display {
	public:
		std::string getDeviceComponent() const override {
			return "Display Laptop";
		}
};

// Concrete Product B4
class DisplaySmartwatch : public Display {
	public:
		std::string getDeviceComponent() const override {
			return "Display Smartwatch";
		}
};

// Abstract Product C
class Processor {
	public:
		virtual ~Processor() {};
		virtual std::string getDeviceComponent() const = 0;
};

// Concrete Product C1
class ProcessorSmartphone : public Processor {
	public:
		std::string getDeviceComponent() const override {
			return "Processsor Smartphone";
		}
};

// Concrete Product C2
class ProcessorTablet : public Processor {
	public:
		std::string getDeviceComponent() const override {
			return "Processsor Tablet";
		}
};

// Concrete Product C3
class ProcessorLaptop : public Processor {
	public:
		std::string getDeviceComponent() const override {
			return "Processsor Laptop";
		}
};

// Concrete Product C4
class ProcessorSmartwatch : public Processor {
	public:
		std::string getDeviceComponent() const override {
			return "Processsor Smartwatch";
		}
};

// Abstract Factory 
class AbstractDeviceFactory {
	public:
		virtual Battery* CreateBattery() const = 0;
		virtual Display* CreateDisplay() const = 0;
		virtual Processor* CreateProcessor() const = 0;
};

// Concrete Factory 1
class SmartphoneFactory : public AbstractDeviceFactory {
	private:
		static unsigned int smartphone_instance_counter;
		const unsigned int max_num_of_instances = 2;
	public:
		SmartphoneFactory() {
			if (smartphone_instance_counter < max_num_of_instances) {
				smartphone_instance_counter++;
			}		
			else {
				std::cout << "WARNING - smartphone was asked to run more than twice!" << std::endl;
			}
		}
		Battery *CreateBattery() const override {
			return new BatterySmartphone();
		}
		Display *CreateDisplay() const override {
			return new DisplaySmartphone();
		}
		Processor *CreateProcessor() const override {
			return new ProcessorSmartphone();
		}

		unsigned int getCounter() {
			return smartphone_instance_counter;
		}
};
unsigned int SmartphoneFactory::smartphone_instance_counter = 0;

// Concrete Factory 2
class TabletFactory : public AbstractDeviceFactory {
	private:
		static unsigned int tablet_instance_counter;
		const unsigned int max_num_of_instances = 2;
	public:
		TabletFactory() {
			if (tablet_instance_counter < max_num_of_instances) {
				tablet_instance_counter++;
			}
			else {
				std::cout << "WARNING - tablet was asked to run more than twice!" << std::endl;
			}
		}
		Battery *CreateBattery() const override {
			return new BatteryTablet();
		}
		Display *CreateDisplay() const override {
			return new DisplayTablet();
		}
		Processor *CreateProcessor() const override {
			return new ProcessorTablet();
		}
};
unsigned int TabletFactory::tablet_instance_counter = 0;


// Concrete Factory 3
class LaptopFactory : public AbstractDeviceFactory {
	private:
		static unsigned int laptop_instance_counter;
		const unsigned int max_num_of_instances = 2;
	public:
		LaptopFactory() {
			if (laptop_instance_counter < max_num_of_instances) {
				laptop_instance_counter++;
			}
			else {
				std::cout << "WARNING - laptop was asked to run more than twice!" << std::endl;
			}
		}
		Battery *CreateBattery() const override {
			return new BatteryLaptop();
		}
		Display *CreateDisplay() const override {
			return new DisplayLaptop();
		}
		Processor *CreateProcessor() const override {
			return new ProcessorLaptop();
		}
};
unsigned int LaptopFactory::laptop_instance_counter = 0;

// Concrete Factory 4
class SmartwatchFactory : public AbstractDeviceFactory {
	private:
		static unsigned int smartwatch_instance_counter;
		const unsigned int max_num_of_instances = 2;
	public:
		SmartwatchFactory() {
			if (smartwatch_instance_counter < max_num_of_instances) {
				smartwatch_instance_counter++;
			}
			else {
				std::cout << "WARNING - smartwatch was asked to run more than twice!" << std::endl;
			}
		}
		Battery *CreateBattery() const override {
			return new BatterySmartwatch();
		}
		Display *CreateDisplay() const override {
			return new DisplaySmartwatch();
		}
		Processor *CreateProcessor() const override {
			return new ProcessorSmartwatch();
		}
};
unsigned int SmartwatchFactory::smartwatch_instance_counter = 0;

// Client code
void Client(const AbstractDeviceFactory &factory) {
	const Battery *battery = factory.CreateBattery();
	const Display *display = factory.CreateDisplay();
	const Processor *processor = factory.CreateProcessor();
	std::cout << battery->getDeviceComponent() << std::endl;
	std::cout << display->getDeviceComponent() << std::endl;
	std::cout << processor->getDeviceComponent() << std::endl;
	std::cout << std::endl;
	delete battery;
	delete display;
	delete processor;
}