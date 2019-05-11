#include<fstream>
#include<iostream>
#include<vector>
#include<sstream>
#include "input.cpp"
#include <cmath>

using namespace std;
int width = 0, height = 0; //Height and width declerations for image bounds

class convert{
    public:
int conversion(string readTextFile, string outputPictureFile){

    in object2;
    string text = object2.read_file(readTextFile); //Read in text file 

    //Set width and height to square root of the length of the text file / 3.
    //This is because there are 3 colors per pixel. An extra line is added to
    //the width and height to account for overflows.
    width = sqrt((text.size()/3)+1);
    height = sqrt((text.size()/3)+1);

    ofstream img (outputPictureFile); //Create new image

    //.ppm headers
    img << "P3 " << endl;
    img << setfill('0') << setw(4) << width << " ";
    img << setfill('0') << setw(4) << height << endl;
    img << "255" << endl;

    //Logic to loop through entire text string and convert each character to a color in a pixel
    for(int i = 0; i < text.length()-1; i++){

            int r = text.at(i);
            img << setfill('0') << setw(3) << r << " ";

            i++;
                if(i <= text.length() -1){ //Logic to make sure string does no go out of bounds

            int g = text.at(i);
            img << setfill('0') << setw(3) << g << " ";

                }else{
                    break;
                }

            i++;

                if(i <= text.length() -1){ //Logic to make sure string does no go out of bounds

            int b = text.at(i);
            img << setfill('0') << setw(3) << b << " ";

                }else{
                    break;
                }

    }

    cout << text << endl; //Output text file to console
    return text.size(); //return text file size

}
};