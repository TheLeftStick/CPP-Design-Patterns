#include <iostream>
#include <string>
#include <vector>
#include "Classes.h"

int main() { // Client
	/*
	std::vector<std::string> vctr_of_nums_text{ "one", "two", "three", "four" };

	InterfaceAggregate<std::string>* vector_container = new VectorAggregate<std::string>(vctr_of_nums_text);

	InterfaceIterator<std::string>* vector_iterator = vector_container->CreateIterator();

	for (vector_iterator->First(); !vector_iterator->IsDone(); vector_iterator->Next()) {
		std::cout << vector_iterator->CurrentItem() << std::endl;
	}
	std::cout << std::endl;
	*/

	// Song 1 data
	std::string s1_name = "Lady Jane";
	std::string s1_band = "Rolling Stones";
	unsigned int s1_year = 1966;
	Song s1(s1_name, s1_band, s1_year);

	// Song 2 data
	std::string s2_name = "Birdhouse In Your Soul";
	std::string s2_band = "They Might Be Giants";
	unsigned int s2_year = 1990;
	Song s2(s2_name, s2_band, s2_year);

	// Song 3 data
	std::string s3_name = "How Many More Times";
	std::string s3_band = "Led Zeppelin";
	unsigned int s3_year = 1969;
	Song s3(s3_name, s3_band, s3_year);

	// Song 4 data
	std::string s4_name = "Can't Keep Johnny Down";
	std::string s4_band = "They Might Be Giants";
	unsigned int s4_year = 2011;
	Song s4(s4_name, s4_band, s4_year);

	// Inserting 'Song' objects into 'Song' vector
	std::vector<Song> music_playlist;
	music_playlist.emplace_back(s1);
	music_playlist.emplace_back(s2);
	music_playlist.emplace_back(s3);
	music_playlist.emplace_back(s4);

	// 'Song' aggregate is initialized by abstract aggregate class
	InterfaceAggregate<Song>* song_container = new VectorAggregate<Song>(music_playlist);
	
	// 'Song' iterator is initialized through concrete 'Song' aggregate's 'CreateIterator()' method
	InterfaceIterator<Song>* song_iterator = song_container->CreateIterator();

	// Prints out all songs in 'Song' vector while using 'Song' Iterator's class methods
	unsigned int song_counter = 1;
	for (song_iterator->First(); !song_iterator->IsDone(); song_iterator->Next()) {
		std::cout << "---Song " << song_counter << " Description---" << std::endl;
		std::cout << " Name: " << song_iterator->CurrentItem().getSongName() << std::endl;
		std::cout << " Band: " << song_iterator->CurrentItem().getBandName() << std::endl;
		std::cout << " Year: " << song_iterator->CurrentItem().getYearReleased() << std::endl;
		std::cout << std::endl;
		song_counter++;
	}

	std::cout << "Successfully iterated through playlist!" << std::endl;

	return EXIT_SUCCESS;
}