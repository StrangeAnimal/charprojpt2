//============================================================================
// Name        : charprojpt2.cpp
// Author      : Me
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "data.hpp"

using namespace std;


int main(int argc, char* argv[]) {
	std::ofstream statfile;
	statfile.open ("stats.csv");

	std::vector<int> numbers = {0, 1, 2, 3};
			std::vector<int> line;
			int size =0;
			int numberofchars = 0;
			char *chararray;
			int timelast;
			std::string charcompare;


			std::clock_t    start;
			start = std::clock();

			perams(argc,argv,numberofchars,size);

			timelast = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);

			statfile << "Argument Parsing," << timelast - start << " ms" << "\n";


		//numberofchars = numchars();
	   chararray = new char [numberofchars];



	   generatearay(numberofchars, chararray);
	   statfile << "Generate Random," << (std::clock() - timelast) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << "\n";
	   timelast = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
	  printarray(chararray,numberofchars);
	  statfile << "Print Array," << (std::clock() - timelast) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << "\n";
	  timelast = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
	printCombinations(numbers, size,line,charcompare);
	statfile << "Generate Combinations," << (std::clock() - timelast) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << "\n";
	timelast = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
    search(chararray, charcompare,size);

    statfile << "Search Array," << (std::clock() - timelast) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << "\n";
        delete chararray;
        statfile.close();
		return 0;
}
