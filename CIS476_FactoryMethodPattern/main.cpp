#include <iostream>
#include <string>
#include <vector>
#include "FactoryMethodClasses.h"

int main() {
	std::vector<Document*> documents;

	documents.emplace_back(new Resume);
	documents.emplace_back(new Report);

	for (Document* document : documents) {
		std::cout << document->getDocName() << "-----" << std::endl;
		for (Page* page : document->Pages) {
			std::cout << page->getPageName() << std::endl;
		}
	}



	return EXIT_SUCCESS;
}