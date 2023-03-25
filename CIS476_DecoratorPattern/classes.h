#pragma once
// Abstract Component
class Order {
	public:
		//std::string description;
		virtual double cost() = 0;
		virtual void getDescription() = 0;
};

// Concrete Component
class Ticket : public Order { // Inherits from abstract component
	public:
		int num_of_adult;
		int num_of_senior;
		int num_of_student;

		Ticket(int adults, int seniors, int students) {
			num_of_adult = adults;
			num_of_senior = seniors;
			num_of_student = students;
		}

		double cost() override {
			return (10.0 * num_of_adult) + (8.0 * num_of_senior) + (8.0 * num_of_student);
		}

		void getDescription() override {
			std::cout << "Adults: " << num_of_adult << std::endl;
			std::cout << "Seniors: " << num_of_senior << std::endl;
			std::cout << "Student: " << num_of_student << std::endl;
			std::cout << "Ticket(s) Cost: " << this->cost() << std::endl;
		}
};

// Abstract Decorator
class Decorator : public Order { // Inherits from abstract component
	public:
		double itemCost;
		virtual void getDescription() = 0;
};

// Concrete Decorator A
class Drink : public Decorator { // Inherits from abstract decorator
	public:
		Order* order;
		int numCoke;
		int numSprite;

		Drink(Order* ord, int coke, int sprite) {
			this->order = ord;
			numCoke = coke;
			numSprite = sprite;
			itemCost = (numCoke * 2.0) + (numSprite * 2.0);
		}

		double cost() override {
			return itemCost + order->cost();
		}

		void getDescription() override {
			std::cout << "Coke(s): " << numCoke << std::endl;
			std::cout << "Sprite(s): " << numSprite << std::endl;
			std::cout << "Drink(s) Cost: " << itemCost << std::endl;
		}
};

// Concrete Decorator B
class Popcorn : public Decorator { // Inherits from abstract decorator
	public:
		Order* order;
		double quantity;

		Popcorn(Order* ord, double quan) {
			this->order = ord;
			quantity = quan;
			itemCost = quantity * 6.0;
		}

		double cost() override {
			return itemCost + order->cost();
		}

		void getDescription() override {
			std::cout << "Popcorn Quantity: " << quantity << std::endl;
			std::cout << "Popcorn Cost: " << itemCost << std::endl;
		}
};

// Concrete Decorator C
class Chips : public Decorator { // Inherits from abstract decorator
	public:
		Order* order;
		double quantity;

		Chips(Order* ord, double quan) {
			this->order = ord;
			quantity = quan;
			itemCost = quantity * 4.0;
		}

		double cost() override {
			return itemCost + order->cost();
		}

		void getDescription() override {
			std::cout << "Chips Quantity: " << quantity << std::endl;
			std::cout << "Chips Cost: " << itemCost << std::endl;
		}
};

// Concrete Decorator D
class Gift : public Decorator { // Inherits from abstract decorator
	private:
		static Gift* instance;
	public: 	
		Order* order;
		double quantity;

		static Gift* getInstance(Order* ord);

		double cost() override {
			return itemCost + order->cost();
		}
		
		void getDescription() override {
			std::cout << "Gift Quantity: " << quantity << std::endl;
			std::cout << "Gift Cost: " << itemCost << std::endl;
		}
};
Gift* Gift::instance = nullptr;

Gift* Gift::getInstance(Order* ord) {
	if (instance == nullptr) {
		instance = new Gift();
		instance->order = ord;
		instance->quantity = 1.0;
		instance->itemCost = 0.0;
	}
	return instance;
}