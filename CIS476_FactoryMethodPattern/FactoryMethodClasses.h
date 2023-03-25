#pragma once
// Product
class Page {
	public:
		virtual ~Page() {}
		virtual std::string getPageName() const = 0;
};

/* Concrete Products for resume */

// Concrete Product A1
class SkillsPage : public Page {
	public:
		std::string getPageName() const override {
			return "SkillsPage";
		}
};

// Concrete Product A2
class EducationPage : public Page {
	public:
		std::string getPageName() const override {
			return "EducationPage";
		}
};

// Concrete Product A3
class ExperiencePage : public Page {
	public:
		std::string getPageName() const override {
			return "ExperiencePage";
		}
};

/* Concrete Products for report */

// Concrete Product B1
class SummaryPage : public Page {
	public:
		std::string getPageName() const override {
			return "SummaryPage";
		}
};

// Concrete Product B2
class IntroductionPage : public Page {
	public:
		std::string getPageName() const override {
			return "IntroductionPage";
		}
};

// Concrete Product B3
class ResultsPage : public Page {
	public:
		std::string getPageName() const override {
			return "ResultsPage";
		}
};

// Concrete Product B4
class ConclusionPage : public Page {
	public:
		std::string getPageName() const override {
			return "ConclusionPage";
		}
};

// Abstract Creator
class Document {
	public:
		std::vector<Page*> Pages;

		virtual std::string getDocName() const = 0;

		// Factory Method
		virtual void createPages() = 0;
};

// Concrete Creator A
class Resume : public Document {
	public:
		// Constructor calls abstract Factory Method
		Resume() {
			this->createPages();
		}

		void createPages() override {
			Pages.emplace_back(new SkillsPage);
			Pages.emplace_back(new EducationPage);
			Pages.emplace_back(new ExperiencePage);
		}

		std::string getDocName() const override {
			return "Resume";
		}
};

// Concrete Creator B
class Report : public Document {
	public:
		// Constructor calls abstract Factory Method
		Report() {
			this->createPages();
		}

		void createPages() override {
			Pages.emplace_back(new SummaryPage);
			Pages.emplace_back(new IntroductionPage);
			Pages.emplace_back(new ResultsPage);
			Pages.emplace_back(new ConclusionPage);
		}

		std::string getDocName() const override {
			return "Report";
		}
};