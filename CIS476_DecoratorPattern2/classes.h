#pragma once
// Abstract Component
class Beverage {
	public:
		std::string description;

		virtual std::string getDescription() = 0;

		virtual double cost() = 0;
};

// Concrete Component 1
class DarkRoast : public Beverage { // Inherits from abstract component
	public:
		DarkRoast() {
			description = "DarkRoast";
		}

		std::string getDescription() override {
			return description;
		}

		double cost() override {
			return 1.99;
		}
};

// Concrete Component 2
class Decaf : public Beverage { // Inherits from abstract component
public:
	Decaf() {
		description = "Decaf";
	}

	std::string getDescription() override {
		return description;
	}

	double cost() override {
		return 2.49;
	}
};

// Concrete Component 3
class Espresso : public Beverage { // Inherits from abstract component
public:
	Espresso() {
		description = "Espresso";
	}

	std::string getDescription() override {
		return description;
	}

	double cost() override {
		return 2.99;
	}
};

// Abstract Decorator
class CondimentDecorator : public Beverage { // Inherits from abstract component
	public:
		virtual std::string getDescription() = 0;
};

// Concrete Decorator A
class Milk : public CondimentDecorator { // Inherits from abstract decorator
	public:
		Beverage* beverage;
		
		Milk(Beverage* bev) {
			this->beverage = bev;
		}

		std::string getDescription() override {
			return beverage->getDescription() + ",Milk";
		}

		double cost() override {
			return 0.3 + beverage->cost();
		}
};

// Concrete Decorator B
class Mocha : public CondimentDecorator { // Inherits from abstract decorator
public:
	Beverage* beverage;

	Mocha(Beverage* bev) {
		this->beverage = bev;
	}

	std::string getDescription() override {
		return beverage->getDescription() + ",Mocha";
	}

	double cost() override {
		return 0.2 + beverage->cost();
	}
};

// Concrete Decorator C
class WhippedCream : public CondimentDecorator { // Inherits from abstract decorator
public:
	Beverage* beverage;

	WhippedCream(Beverage* bev) {
		this->beverage = bev;
	}

	std::string getDescription() override {
		return beverage->getDescription() + ",WhippedCream";
	}

	double cost() override {
		return 0.1 + beverage->cost();
	}
};