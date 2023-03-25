#pragma once
// Product
class Vehicle {
	public:
		std::vector<std::string> parts;
		
		void add(std::string part) {
			parts.push_back(part);
		}

		void show() {
			for (std::string part : parts) {
				std::cout << part << std::endl;
			}
		}
};

// Abstract Builder
class VehicleBuilder {
	public:
		virtual void buildDoors() = 0;
		virtual void buildSeat() = 0;
		virtual void buildWheel() = 0;
		virtual Vehicle* getResult() = 0;
};

// Concrete Builder 1
class MiniVan : public VehicleBuilder {
	private:
		Vehicle* vehicle = new Vehicle();

		void buildDoors() override {
			vehicle->add("Door: 4 Doors");
		}

		void buildSeat() override {
			vehicle->add("Seat: 7 Seats");
		}

		void buildWheel() override {
			vehicle->add("Wheel: 4 Wheels");
		}

		Vehicle* getResult() override {
			return vehicle;
		}
};

// Concrete Builder 2
class SportsCar : public VehicleBuilder {
private:
	Vehicle* vehicle = new Vehicle();

	void buildDoors() override {
		vehicle->add("Door: 2 Doors");
	}

	void buildSeat() override {
		vehicle->add("Seat: 4 Seats");
	}

	void buildWheel() override {
		vehicle->add("Wheel: 4 Wheels");
	}

	Vehicle* getResult() override {
		return vehicle;
	}
};

// Concrete Builder 3
class Motorcycle : public VehicleBuilder {
private:
	Vehicle* vehicle = new Vehicle();

	void buildDoors() override {
		vehicle->add("Door: 0 Doors");
	}

	void buildSeat() override {
		vehicle->add("Seat: 2 Seats");
	}

	void buildWheel() override {
		vehicle->add("Wheel: 2 Wheels");
	}

	Vehicle* getResult() override {
		return vehicle;
	}
};

// Director
class Shop {
	public:
		void construct(VehicleBuilder* vehicleBuilder) {
			vehicleBuilder->buildDoors();
			vehicleBuilder->buildSeat();
			vehicleBuilder->buildWheel();
		}
};