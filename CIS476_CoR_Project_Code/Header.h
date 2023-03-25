#pragma once
// Abstract Handler
class HotelRoom {
	public:
		static unsigned int num_of_suites_available; // 10
		static unsigned int num_of_delux_available;  // 15
		static unsigned int num_of_standard_available;  // 45

		HotelRoom* successor;

		void setSuccessor(HotelRoom* succ) {
			this->successor = succ;
		}

		virtual void handleRequest(double purchaseAmount) = 0;
};
unsigned int HotelRoom::num_of_suites_available = 1;
unsigned int HotelRoom::num_of_delux_available = 1;
unsigned int HotelRoom::num_of_standard_available = 1;

// Handler 1
class Suite : public HotelRoom {
	public:
		void handleRequest(double purchaseAmount) override {
			if (purchaseAmount >= 280 && num_of_suites_available != 0) {
				num_of_suites_available--;
				std::cout << "Bid on Suite Successful!" << std::endl;
			}
			else if (successor != nullptr) {
				successor->handleRequest(purchaseAmount);
			}
		}
};

// Handler 2
class Deluxe : public HotelRoom {
	public:
		void handleRequest(double purchaseAmount) override {
			if ((purchaseAmount >= 150 && purchaseAmount <= 280) && num_of_delux_available != 0) {
				num_of_delux_available--;
				std::cout << "Bid on Delux Successful!" << std::endl;
			}
			else if (successor != nullptr) {
				successor->handleRequest(purchaseAmount);
			}
		}
};

// Handler 3
class Standard : public HotelRoom {
public:
	void handleRequest(double purchaseAmount) override {
		if ((purchaseAmount >= 80 && purchaseAmount <= 150) && num_of_standard_available != 0) {
			num_of_standard_available--;
			std::cout << "Bid on Standard Successful!" << std::endl;
		}
		else if (num_of_standard_available == 0 && num_of_delux_available == 0 && num_of_suites_available == 0) {
			std::cout << "All rooms are sold out!" << std::endl;
		}
		else {
			std::cout << "Bid rejected. Please provide new bid." << std::endl;
		}
	}
};