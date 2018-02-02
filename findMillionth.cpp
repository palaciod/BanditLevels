#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
* Author : Daniel Palacio
* The following code iterates through each line of the data.txt file. To import the file
* you must copy and paste into an already existing text file. You'll get permission denied
* if you try to save directly to a text file on your device.
*
* If finding mil doesn't return string::npos, then that line contains the password.
* The code then prints it. Just copy it and move onto level 8.
*/
int main(int argc, char const *argv[]) {
  ifstream my_seq(argv[1]);
  string mil = "millionth";
  string line;
  if(my_seq.is_open()){// Opens the text file
    getline(my_seq,line);
    std::cout << line << '\n';
    while(!line.empty()){
      if(line.find(mil)!= string::npos){
        std::cout << line << '\n';
        return 0;
      }else{
        getline(my_seq,line);
      }
    }
  }
  return 0;
}
