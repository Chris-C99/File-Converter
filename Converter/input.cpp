#include <fstream>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>

char* textArray;
int numbers = 0;
std::string file;

using namespace std;

class in{
  public:
string read_file(string loc){

  //Open file and convert it to a string.

  std::ifstream inFile;
  inFile.open(loc);

  stringstream strStream;
  strStream << inFile.rdbuf();
  string str = strStream.str();

    return str; //Return converted string
}
};