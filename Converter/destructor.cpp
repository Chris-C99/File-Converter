#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include <string>
#include <cstring>
#define FILE_PATH " " 

using namespace std;

string fullString = "";

class destruct{
  public:
int destructor(string destructPicture, string newFileLocation){

    std::ifstream inFile;
    inFile.open(destructPicture); //Open picture

  stringstream strStream;
  strStream << inFile.rdbuf();
  string str = strStream.str(); //Convert picture file to string


    //Skip passed headers and convert each numerical value to a character and append it to a string.
    //Integer has to be parsed from the string aswell.
    for(int i = 18; i < str.size()-1; i = i + 4){
        cout << str.substr(i,3) << endl;

        int x=0;
        istringstream iss (str.substr(i,3));
        iss >> x;

        char newchar = 0 + x;
        string s(1,newchar);
        fullString.append(s);
    }
    
    std::ofstream outfile (newFileLocation); //Create new text file

    outfile << fullString << endl; //Write string to text file

    outfile.close(); //Close file

    return fullString.size(); //Return size of file

}
};