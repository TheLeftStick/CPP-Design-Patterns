#include <iostream>
#include <string>

class Spooler {
	private:
		static Spooler* p_spooler;
		std::string p_value;
		Spooler(const std::string value) {
			p_value = value;
		}
	public:
		static Spooler* getSpooler(const std::string value);
		std::string getValue() const {
			return p_value;
		}
};
Spooler* Spooler::p_spooler = nullptr;

Spooler* Spooler::getSpooler(const std::string value) {
	if (p_spooler == nullptr) {
		p_spooler = new Spooler(value);
	}
	return p_spooler;
}

int main() {

	Spooler* sp1 = Spooler::getSpooler("FOO");

	if (sp1 != nullptr) {
		std::cout << "Got 1 Spooler" << std::endl;
		std::cout << sp1->getValue() << std::endl;
	}

	Spooler* sp2 = Spooler::getSpooler("BAR");

	if (sp2 == sp1) {
		std::cout << "Spooler 2 has same memory address as Spooler 1" << std::endl;
		std::cout << sp2->getValue() << std::endl;
	}

	return EXIT_SUCCESS;
}