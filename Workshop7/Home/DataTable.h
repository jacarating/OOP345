/*
================================================================================================================
Name		: DataTable.h
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: July 12th, 2019
Workshop	: Workshop 7
Description : This file defines a template class DataTable to calculate the mean and sigma of the y cordinates from Simple.dat
================================================================================================================
*/



#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numeric>

extern int FW;
extern int ND;

namespace sict {

	template<typename T>
	class DataTable {
		std::vector<T> xCord;
		std::vector<T> yCord;

		T median;
		T mean;
		T sigma;
		T intercept;
		T slope;
	public:

		// One Arguement Constructor: Reads file, reads records and stores into sequence. Calculates the mean and sigma (variance).

		DataTable(std::ifstream& file) {
			T x, y;
			if (file.is_open()) {
				while (!file.eof()) {
					file >> x >> y;
					xCord.push_back(x);
					yCord.push_back(y);
					file.ignore(255, '\n');
				}
			}


			//1. Work out the Mean (the simple average of the numbers)
			mean = accumulate(yCord.begin(), yCord.end(), (T)0) / yCord.size();

			//2. Then for each number: subtract the Mean and square the result
			std::vector<T> temp(yCord.size());
			transform(yCord.begin(), yCord.end(), temp.begin(), [&](T i) {return pow((i - mean), 2); });

			//3. Then work out the mean of those squared differences. Square root resulting number.
			sigma = sqrt(std::accumulate(temp.begin(), temp.end(), (T)0) / (temp.size() - 1));


			//4. Calculate slope:
			T sumofx, sumofy, sumofxsqr, sumofxy;

			sumofx = std::accumulate(xCord.begin(), xCord.end(), (T)0);
			sumofy = std::accumulate(yCord.begin(), yCord.end(), (T)0);
			sumofxsqr = std::inner_product(xCord.begin(), xCord.end(), xCord.begin(), (T)0);
			sumofxy = std::inner_product(xCord.begin(), xCord.end(), yCord.begin(), (T)0);

			slope = ((xCord.size() * sumofxy) - (sumofx * sumofy)) / ((xCord.size() * sumofxsqr) - pow(sumofx, 2));

			//5. Calculate intercept
			intercept = (sumofy - (slope * sumofx)) / xCord.size();


			// To hold sorted vector
			std::vector<T> sorted(yCord.size());
			sorted = yCord;
			sort(sorted.begin(), sorted.end());
			median = sorted[sorted.size() / 2];
		
		}

		// Query: Display data in specified format.
		//
		void displayData(std::ostream& os) const {
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;
			os.setf(std::ios::fixed);
			os.setf(std::ios::right);

			os.width(FW);
			os << "x";
			os.width(FW);
			os << "y" << std::endl;

			os.precision(ND);

			for (size_t i = 0; i < xCord.size(); i++) {
				os << std::setw(FW) <<  xCord[i] << std::setw(FW) << yCord[i] << std::endl;
			}

			os.unsetf(std::ios::fixed);
			os.unsetf(std::ios::right);


		}

		// Query: Display statistics in specified format.
		//
		void displayStatistics(std::ostream& os) const {
			
			os << "\nStatistics" << std::endl;
			os << "----------" << std::endl;

			os.setf(std::ios::fixed);
			os.setf(std::ios::left);
			os.precision(ND);

			os << std::left << "  " << std::setw(FW) << "y mean" << "  = " << std::setw(FW) << std::right << mean << std::endl;
			os << std::left << "  " << std::setw(FW) << "y sigma" << "  = " << std::setw(FW) << std::right << sigma << std::endl;
			os << std::left << "  " << std::setw(FW) << "y median" << "  = " << std::setw(FW) << std::right << median << std::endl;
			os << std::left << "  " << std::setw(FW) << "slope" << "  = " << std::setw(FW) << std::right << slope << std::endl;
			os << std::left << "  " << std::setw(FW) << "intercept" << " = " << std::setw(FW) << std::right << intercept << std::endl;

		}

	};


}
#endif // !SICT_DATATABLE_H



