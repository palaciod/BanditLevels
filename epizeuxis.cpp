#include <iostream>
#include <fstream>
#include <string>
#include<map>
using namespace std;
/**
* Author: Daniel Palacio
* The following code can be used to solve level 8 to aquire
* the password for level 9.
* ~ I used an ordered map that doesn't allow repeated keys to be
* emplaced(added), while going through each line of the
* dataLevel8.txt file(data.txt within the bandit8 server).
* If a certain key has already apeared, then value shall be incremented.
* The for loop at the bottom will iterate through the map and check
* which of the values has a score of 1. If so, then that is your
* answer/password for level 9.
*/
int main(int argc, char const *argv[]) {
  ifstream rep_seq(argv[1]);
  string line;
  std::map<string,int> myMap;
  std::map<string, int>:: iterator it;
  std::map<string, int>::iterator addValIt;
  if(rep_seq.is_open()){
    getline(rep_seq,line);
    while(!line.empty()){
      addValIt = myMap.find(line);
      if(myMap.find(line)!= myMap.end()){
        addValIt->second++;
      }
      myMap.emplace(line,1);
      getline(rep_seq,line);
    }
  }
  for(it = myMap.begin();it!=myMap.end();it++){
    if(it->second==1){
      std::cout << it->first << '\n';
    }
  }
  return 0;
}
