// Workshop 5 - Functions
// w5.cpp
// Chris Szalwinski
// 2019/02/10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "KVPair.h"
#include "KVList.h"
#include "Taxable.h"
using namespace sict;

float HST = 0.13f;
int fieldWidth = 10;

template <typename L, typename T, typename K, typename V>
L createList(char* filename) {
	std::ifstream file(filename);
	if (!file) {
		//exception handling for errors thrown in KVList one arg constructor
		try {
			L list(0);
			return std::move(list);
		}
		catch (const char* msg) {
			std::cout << msg << std::endl;
			exit(2);  //display error message and exit normally
		}
	}
	int no_records = 0;
	do {
		char c = file.get();
		if (file.good() && c == '\n') no_records++;
	} while (!file.eof());
	file.clear();
	file.seekg(std::ios::beg);

	//exception handling for errors thrown in KVList one arg constructor
	try {
		L list(no_records);
		do {
			K key;
			V value;
			file >> key;
			if (file) {
				file >> value;
				file.ignore();
				list.push_back(T(key, value));
			}
		} while (file);
		return std::move(list);
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
		exit(2);  //display error message and exit normally
	}
}

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	// check for command line errors
	if (argc != 3) {
		std::cerr << "\nPlease enter two .txt filenames on the command line!!!";
		exit(1);  //display error message and exit normally
	}

	// set for fixed, 2-decimal point output
	std::cout << std::fixed << std::setprecision(2);

	// process price list file
	KVList<KVPair<std::string, float>> priceList = createList<
		KVList<KVPair<std::string, float>>,
		KVPair<std::string, float>,
		std::string,
		float>
		(argv[1]);
	std::cout << "\nPrice List with G+S Taxes Included\n==================================\n";
	std::cout << "Description:      Price Price+Tax\n";
	priceList.display(std::cout, Taxable(HST)); //sending functor into display function call

	//process Student.txt list
	KVList<KVPair<int, float>> gradeList = createList<
		KVList<KVPair<int, float>>,
		KVPair<int, float>,
		int,
		float>
		(argv[2]);

	std::cout << "\nStudent List Letter Grades Included\n===================================\n";
	std::cout << "Student No :      Grade    Letter\n";

	//lambda expression
		gradeList.display(std::cout, [](float grade) {
		std::string letter;
		if (grade >= 90) {
			letter = "A+";
		}
		else if (grade >= 80) {
			letter = "A ";
		}
		else if (grade >= 75) {
			letter = "B+";
		}
		else if (grade >= 70) {
			letter = "B ";
		}
		else if (grade >= 65) {
			letter = "C+";
		}
		else if (grade >= 60) {
			letter = "C ";
		}
		else if (grade >= 55) {
			letter = "D+";
		}
		else if (grade >= 50) {
			letter = "D ";
		}
		else letter = "F ";

		return letter;
	});
}