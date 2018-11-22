//============================================================================
// Name        : charprojpt2.cpp
// Author      : Me
// Version     :  1.0
// Copyright   : Pls no stealy stealy
// Description :  Data library for charachter search project.
//============================================================================

#include <iostream>

#include "data.hpp"

using namespace std;


int main(int argc, char* argv[]) {
	std::ofstream statfile; //open output file stream

	statfile.open ("stats.csv");


	std::vector<int> numbers = {0, 1, 2, 3};
			std::vector<int> line;
			int size =0;
			 long long numberofchars = 0;
			char *chararray;

			std::string charcompare;


			std::clock_t    start; //new instance of clock class
			start = std::clock(); //start the clock

			perams(argc,argv,numberofchars,size); //parse the command line parameters.



			statfile << "Argument Parsing," << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000)<< " ms" << "\n"; //output the time taken to the file


			start = std::clock(); //start the clock
		//numberofchars = numchars();
	   chararray = new char [numberofchars]; //generate a new dynamic array.



	   generatearay(numberofchars, chararray);

	   statfile << "Generate Random," << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << "\n";

	  //printarray(chararray,numberofchars); //not needed
	   start = std::clock(); //start the clock

	printCombinations(numbers, size,line,charcompare);
	statfile << "Generate Combinations," << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << "\n";
	start = std::clock(); //start the clock
    search(chararray, charcompare,size);

    statfile << "Search Array," << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << "\n";
    cout << "Done " << numberofchars << " Characters generated and searched";
        delete chararray; //prevent a memory leak
        statfile.close(); //close the file

		return 0;
}
