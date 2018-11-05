#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
int countSubstring(std::string& str, std::string& sub);
int numchars();
int generatearay(int number,char* chararr);
int printarray(char* charry, int numchars);
void printCombinations(const std::vector<int>& numbers, int size, std::vector<int>& line, std::string& comparearray);
int search(char* chararr, std::string comparr,int size);
