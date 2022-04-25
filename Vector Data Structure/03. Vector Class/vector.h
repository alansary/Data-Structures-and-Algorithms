template<typename T>
class Vector {
	// data members
	T * arr;
	int s;
	int c;

public:
	// constructor
	Vector(int max_s = 0) {
		s = 0;
		c = max_s;
		arr = new T[c];
	}

	// methods
	void push_back(const T d) {
		if (s == c) {
			// create a new array with double the size
			c = c ? c * 2 : 1;
			T *new_arr = new T[c];
			for (int i = 0; i < s; i++) {
				new_arr[i] = arr[i];
			}

			// delete old array
			delete [] arr;

			// old array = new array
			arr = new_arr;
		}
		arr[s++] = d;
	}

	void pop_back() {
		if (s > 0)
			s--;
	}

	bool empty() const {
		return s == 0;
	}

	T front() const {
		return arr[0];
	}

	T back() const {
		return arr[s-1];
	}

	T at(int i) const {
		return arr[i];
	}

	int size() const { // const function that doesn't change any data members of the class
		return s;
	}

	int capacity() const {
		return c;
	}

	// operator overloading
	T operator[](const int i) const { // i doesn't change in function
		return arr[i];
	}
};
