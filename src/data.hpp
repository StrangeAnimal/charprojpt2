#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>
#include <cmath>
#include <sstream>
#include <fstream>
#include <ctime>


using namespace std;




int countSubstring(std::string& str, std::string& sub);
int numchars();
int generatearay(int number,char* chararr);
int printarray(char* charry, int numchars);
void printCombinations(const std::vector<int>& numbers, int size, std::vector<int>& line, std::string& comparearray);
void search(char* chararr, std::string comparr,int size);
void perams(int argc, char* argv[], long long& numberofchars, int& size);




    	
    	 int numchars(){

    		int number;
    		cout << "Enter the number of chars to generate" << endl;
    		cin >> number;
    		return number;


    	}
    	
    	 int generatearay(int number, char* chararr){
    		srand(time(NULL)); //seed the random number generator
    		int y=0; //a number to store the random number

    		for(int x=0;x< number;x++){ //loop as many times as the number of charachters to be generated.

    			y = rand() %4; //generate a random number between 0 and 3

    			switch(y){

    			case 0: chararr[x] = 'A';
    	        break;
    			case 1: chararr[x] = 'C';  //use switch case to change number to character
    	        break;
    			case 2: chararr[x] = 'T';
    	        break;
    			case 3: chararr[x] = 'G';








    			}





    		}


    	return 0;

    	}
    	
    	
    	int printarray(char* charry, int numchars){

    		for(int x=0;x<numchars;x++){ //loop through each char in the array

    			cout << charry[x];  //print the current char


    		}
    	    cout <<'\n'; //print a newline

    		return 0;
    	}
    	
    	void search(char* chararr, std::string comparr,int size){

    		std::ofstream analysis;
    		analysis.open ("analysis.csv"); //open the file
    		std::string randomstring = chararr; //convert the array to a string for easier use.
    		std::string substring; //a substring variable to store the substring to be searched for


    		int a=0;

    		int number=0;
    		int total=0;
    	    float looptimes = pow(4,size); //calculate the number of times to loop

    		for(int x=0;x<looptimes;x++){





    			substring = comparr.substr(a,size); //get part of the list of every combination

    			number = countSubstring(randomstring, substring); //count the occurrences
    	        total = total + number;
    			//cout << substring << ", "<< number <<'\n';
    			analysis << substring << ", "<< number << endl; //print to file
    			a = a+size;  //Increase a to get the next substring


    		}
    	      //cout << total;
    	      analysis.close();

    	}
    	
    	int countSubstring(std::string& str, std::string& sub)
    	{

    	    int count = 0;
    	    for ( int offset = str.find(sub); offset != std::string::npos; offset = str.find(sub, offset + 1)) //start at the first instance, loop until the offset hits the end of the string
    	    	// increment to the next instance look for sub starting 1 further on to prevent finding the same string again
    	    {
    	        ++count;
    	    }
    	    return count;
    	}
    	
    	void printCombinations(const std::vector<int>& numbers, int size, std::vector<int>& line, std::string &comparearray) {

//numbers are the numbers to iterate through
//line is the vector to put the combinations in
    	    for (unsigned i = 0; i < numbers.size(); i++) {

    	        line.push_back(numbers[i]);
    	        if (size <= 1) { // Condition that prevents infinite loop in recursion, when recursed in enough times

    	        	for (const int j : line){ //loop through line
    	        	                switch(j){

    	        	                case 0:comparearray.append("A");
    	        	                break;

    	        	                case 1:comparearray.append("C");
    	        	                break;

    	        	                case 2:comparearray.append("T");
    	        	                 break;

    	        	                case 3:comparearray.append("G");




    	        	                }

    	        	}


    	        	            line.erase(line.end() - 1);
    	        } else {
    	            printCombinations(numbers, size - 1, line,comparearray); // Recursion happens here recurrs as many times as the number of chars in the iteration eg 4 for AAAA AAAC ...
    	            line.erase(line.end() - 1);       //creates a stack where each level on the stack is for one part on the number

    	        }
    	    }
    	}
    	
    	
    	void perams(int argc, char* argv[], long long& numberofchars, int& size){

    		for(int counter=0;counter<argc;counter++) {

    						if( strcmp( argv[counter], "-n") == 0){ //find -n

    							stringstream arg (argv[counter + 1]); // assume the next string contains the number

    							arg >> numberofchars;

    						}

    						if( strcmp( argv[counter], "-t") == 0){ //find -t

    											stringstream arg (argv[counter + 1]);   //assume the next string contains the value

    											arg >> size;

    										}



    					}






    	}




    	
    	
    	


