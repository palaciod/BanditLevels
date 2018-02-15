#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/**
* Author : Daniel Palacio
*/

/**
* The strangeText method returns a string that has filtered the strange test that appears within
* dataLevel9.txt file. It also filters numbers and letters that aren't part of the password.
* I do this by iterating through each character of the string and determine whether that character
* is part of the alphabet or is a digit. Now keep in mind we would have to filter out the letters and
* digits that are not part of the password. So we just set the string password to an empty string and start over.
* @return - A filtered string that returns the password.
*/
string strangeText(string line){
  string password = "";
  for(int i = 0;i<line.size();i++){
    if(isalpha(line.at(i))){
      password.push_back(line.at(i));
    }else if(isdigit(line.at(i))){
      password.push_back(line.at(i));
    }else{
      password = "";
    }
  }
  return password;
}

/**
* Once you've copied and pasted the text file onto your local device, you'll now
* use ifstream to go through each line to determine where the password is located.
* The password is next to a string of equal signs ("=="). It's not mentioned how many equal signs
* are included before the password. So we just look for the string line with two consecutive equal signs.
* Once it appears we use the strangeText(@parem string) method to filter the line to return the password
* in it's final form.
*
*/
int main(int argc, char const *argv[]) {
  ifstream find_pass(argv[1]);
  string line;
  int count  = 0;
  if(find_pass.is_open()){
    getline(find_pass,line);
    count++;
    while(count<195){
      if(line.find("==")!= string::npos){
        std::cout << strangeText(line) << '\n';
      }
      getline(find_pass,line);
      count++;
    }
  }
  return 0;
}
/*
* I should probably mention the command line that would get the password.
* It's pretty stright foward in unix command line.
* The command line : strings data.txt | grep '='
*/
