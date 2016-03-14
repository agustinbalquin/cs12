#include <iostream>
#include <algorithm>
using namespace std;



void flipString(string &str) {
        //std::cout << str;
    
    if (str.size() <= 1) {
        return;
    }
    //char c = str.at(0);
    char c = str.at(str.size()-1);
    //swap(str.at(0), str.at(str.size() - 1));
    string temp = str.substr(0,str.size() -1);
    flipString(temp);
    str = c + temp;
    
}


int main(int argc, char * argv[]) {
    
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}
    
    
    
    
    
