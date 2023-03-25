#pragma once
class Song { // custom datatype
	private:
		std::string song_name;
		std::string band_name;
		unsigned int year_released;

	public:
		Song() {
			song_name = "N/A";
			band_name = "N/A";
			year_released = 0;
		}

		Song(std::string song, std::string band, unsigned int year) {
			song_name = song;
			band_name = band;
			year_released = year;
		}

		std::string getSongName() {
			return song_name;
		}
		std::string getBandName() {
			return band_name;
		}
		unsigned int getYearReleased() {
			return year_released;
		}

};

// Iterator Interface
template <class T>
class InterfaceIterator {
	public:
		virtual void First() = 0;

		virtual void Next() = 0;

		virtual bool IsDone() const = 0;

		virtual T CurrentItem() const = 0;
};

// Aggregate Interface
template <class T>
class InterfaceAggregate {
	public:
		virtual InterfaceIterator<T>* CreateIterator() const = 0;
};

template <class T> class VectorAggregate; // declared so 'VectorIterator' can use inside class

// Concrete Iterator
template <class T>
class VectorIterator : public InterfaceIterator<T> {
	public:
		VectorIterator(const VectorAggregate<T>* vector_aggregate) {
			aggregate = vector_aggregate;
			current = 0;
		}

		void First() override {
			current = 0;
		}

		void Next() override {
			current++;
		}

		bool IsDone() const override {
			return current >= aggregate->p_datavector.size();
		}

		T CurrentItem() const override {
			if (!IsDone()) {
				return aggregate->p_datavector[current];
			}
			else {
				std::cout << "Error!" << std::endl;
				return T();
			}
		}

	protected:
		const VectorAggregate<T>* aggregate;
		unsigned int current;
};

// Concrete Aggregate
template <class T>
class VectorAggregate : public InterfaceAggregate<T> {
private:
	std::vector<T> p_datavector;

public:
	friend class VectorIterator<T>;

	VectorAggregate(const std::vector<T>& dataset) {
		p_datavector = dataset;
	}
	InterfaceIterator<T>* CreateIterator() const override {
		return new VectorIterator<T>(this);
	}
};