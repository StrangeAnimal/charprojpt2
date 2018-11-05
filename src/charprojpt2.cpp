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

	std::vector<int> numbers = {0, 1, 2, 3};
			std::vector<int> line;
			int size =0;
			int numberofchars = 0;
			char *chararray;
			std::string charcompare;



			perams(argc,argv,numberofchars,size);



		//numberofchars = numchars();
	   chararray = new char [numberofchars];

	   generatearay(numberofchars, chararray);
	  printarray(chararray,numberofchars);
	printCombinations(numbers, size,line,charcompare);

    search(chararray, charcompare,size);
        delete chararray;
		return 0;
}
