/*
================================================================================================================
Name		: KVList.h
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: June 13th, 2019
Workshop	: Workshop 5
================================================================================================================
*/

/*
================================================================================================================
Description: This header file provides the logic for the class KVList manage a dynamically allocated list of type
			 T objects. Supports display, and modifiers to add to the array. Disables copy and move assignment
			 and the copy constructor functions.
================================================================================================================
*/


#ifndef SICT_KVLIST_H
#define SICT_KVLIST_H


namespace sict {

	// Templated Class:
	template<typename T>
	class KVList {
		T* iArray;
		size_t counter;
		int MAX;
	public:

		// Default Constructor: Set object to safe empty state.
		KVList() : iArray{ nullptr }, counter{ 0u } {}

		// One Argument Constructor: Sets object to safe empty state, then allocates memory from specified size.
		KVList(int n) {
			iArray = nullptr;
			counter = 0u;
			MAX = 0;
			if (n > 0) {
				delete[] iArray;
				MAX = n;
				iArray = new T[MAX];
			} 
			 else throw "The number of elements received in the constructor is not positive-valued";
			
			
		}

		// Move Constructor: Sets object to safe empty state. Then checks for validation, then moves resources from src object to current object.
		KVList(KVList&& src) {
			iArray = nullptr;
			MAX = 0;
			counter = 0u;

			if (this != &src) {
				if (!src.isEmpty()) {
					delete[] iArray;
					MAX = src.MAX;
					counter = src.counter;
					iArray = src.iArray;

					src.iArray = nullptr;
					src.MAX = 0;
					src.counter = 0u;
				}
			}
		}


		// Destructor: 
		~KVList() { 
			delete[] iArray;
			iArray = nullptr;
		}

		// Overloaded Operator: Returns an unmodifiable reference to the specified element.
		const T& operator[](size_t i) const {
			if (i >= MAX || i < 0) {
				throw "The index passed to the subscripting operator is out-of-bounds";
			} 
			else return iArray[i];
		}

		// Templated Query Function: Receives ostream and a function object that calls the display function on each element.
		template<typename F> void display(std::ostream& os, F f) const {
			if (!isEmpty()) {
				for (size_t i = 0; i < counter; i++) {
					iArray[i].display(os, f);
					os << std::endl;
				}
			}
		}

		// Modifier: Checks if there is space in the array, then inserts the received reference into the last element in the array and increments the counter.
		void push_back(const T& t) {
			if (counter < (size_t)MAX) {
				iArray[counter++] = t;
			}
		}

		// Disabled Functions:
		KVList& operator=(const KVList&) = delete; 
		KVList& operator=(KVList&&) = delete;
		KVList(const KVList&) = delete;

		// Query: Returns if the current object is empty.
		bool isEmpty() const {
			return iArray == nullptr && counter == 0u;
		}
	};
}
#endif // !SICT_KVLIST_H
