#pragma once
// Abstract Product A
class AbstractTextField {
	public:
		virtual std::string displayName() const = 0;
};

// Concrete Product A1
class TextFieldWindow : public AbstractTextField {
	public:
		std::string displayName() const override {
			return "This is Window Text Field as TextFieldWindow";
		}
};

// Concrete Product A2
class TextFieldMac : public AbstractTextField {
	public:
		std::string displayName() const override {
			return "This is Mac Text Field as TextFieldMac";
		}
};

// Abstract Product B
class AbstractPushButton {
	public:
		virtual std::string displayName() const = 0;
};

// Concrete Product B1
class PushButtonWindow : public AbstractPushButton {
	public:
		std::string displayName() const override {
			return "This is Window Button as PushButtonWindow";
		}
};

// Concrete Product B2
class PushButtonMac : public AbstractPushButton {
	public:
		std::string displayName() const override {
			return "This is Mac Button as PushButtonMac";
		}
};

// Abstract Widget Factory
class AbstractFactoryWidget {
	public:
		virtual AbstractTextField* createTextField() const = 0;
		virtual AbstractPushButton* createPushButton() const = 0;
};

// Concrete Factory 1
class ConcreteWindow : public AbstractFactoryWidget {
	public:
		AbstractTextField* createTextField() const override { // creates Concrete Product A1
			return new TextFieldWindow();
		}
		AbstractPushButton* createPushButton() const override { // creates Concrete Product B1
			return new PushButtonWindow();
		}
};

// Concrete Factory 2
class ConcreteMac : public AbstractFactoryWidget {
	public:
		AbstractTextField* createTextField() const override { // creates Concrete Product A2
			return new TextFieldMac();
		}
		AbstractPushButton* createPushButton() const override { // creates Concrete Product B2
			return new PushButtonMac();
		}
};

void Client(const AbstractFactoryWidget &factory) {
	const AbstractPushButton* push_button = factory.createPushButton();
	const AbstractTextField* text_field = factory.createTextField();

	std::cout << push_button->displayName() << std::endl;
	std::cout << text_field->displayName() << std::endl;

	delete push_button;
	delete text_field;
}