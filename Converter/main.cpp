#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "converter.cpp"
#include "destructor.cpp"

#include <mysql/mysql.h> //External Library

using namespace std;

unsigned int port = 3306;
static char *unix_socket = NULL;
unsigned int flag = 0;

int main(){

     string data = "INSERT INTO users VALUES ("; //Data string for database
     data += "null";
     data += " ,";

     convert object;
     destruct object2;

     int choice; //Integer to log user's choice
     string in;
     string out;

     cout << "Type 1 to convert a text file to a .ppm picture" << endl;
     cout << "Type 2 to revert a .ppm picture back into a text file." << endl;

     cin >> choice;

     if(choice == 1){

          string open = "xdg-open "; //String used to open file

          // Prompt user for input and output file locations
          cout << "Please enter the location of the text file you want converted." << endl;
          cin >> in;

          cout << "Please enter the desired output location of the .ppm image file." << endl;
          cin >> out;

          // Prompt user for input and output file locations
          data += " 'Text File' , '";
          data += in;
          data += "' , '";

          data += out;

          int x = object.conversion(in, out); //Call method to convert text to image
          data += "' , '";
          data += to_string(x);
          data += "')";

          open.append(out); //Add file location to open file string

          system(open.c_str()); //Open file call


     }

     if(choice == 2){

          string open = "gedit "; //String used to open file

          // Prompt user for input and output file locations
          cout << "Please enter the location of the .ppm image file you want converted." << endl;
          cin >> in;

          cout << "Please enter the desired output location of the text file you want converted." << endl;
          cin >> out;

          //Add data to string for database entry
          data += " 'Picture' , '";
          data += in;
          data += "' , '";

          data += out;

          int x = object2.destructor(in, out); //Call method to convert image to text
          data += "' , '";
          data += to_string(x+1);

          data += "')";

          open.append(out);   //Add file location to open file string

          system(open.c_str()); //Open file call


     }

     //
     // MYSQL database connection and data entry
     //

     MYSQL *conn;

     conn = mysql_init(NULL);


     if(! (mysql_real_connect(conn,"localhost","root","password","test",port,unix_socket,flag))){
          fprintf(stderr,"Error %s [%d]\n",mysql_error(conn),mysql_errno(conn));

          exit(1);
     }
     printf("connection successful\n\n");

     mysql_query(conn, data.c_str());


     mysql_close(conn);

     return EXIT_SUCCESS;
    
}
