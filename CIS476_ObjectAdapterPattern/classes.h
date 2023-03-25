#pragma once
// Target
class TS {
	public:
		virtual std::string getTemp() = 0;
};

class TS1 : public TS {
	public:
		std::string getTemp() override {
			return "return to TS# with Temp 42 Fahrenheit";
		}
};

class TS2 : public TS {
	public:
		std::string getTemp() override {
			return "return to TS# with Temp 73 Fahrenheit";
		}
};

// Adaptee
class TS3 {
	public:
		std::string getTSTemp() {
			return "return to TS# with Temp 69 Celcius";
		}
};

// Adapter
class TSAdapter : public TS {
	private:
		TS3* ts3;

	public:
		TSAdapter() {
			ts3 = new TS3;
		}

		std::string getTemp() {
			std::cout << ts3->getTSTemp() << std::endl;
			return "return to TS# with Temp 156.2 Fahrenheit";
		}
};