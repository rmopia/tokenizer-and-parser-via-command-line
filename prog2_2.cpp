#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "prog2_1.hpp"
using namespace std;

int main(int argc, char *argv[]){   //takes single command line arg i.e. 'test.txt'
    if(argc < 2){                   //argc must atleast be 2 since main counts as argv[0]
        return -1;                  //exits program when no arguments (other than main) are given
    }

    Tokenizer t;                //calls instance of Tokenizer
    ifstream file(argv[1]);     //opens command-line file
    string content;

    while(getline(file, content)){      //while loop that iterates one string line from file
        t.Tokenize(content);            //calls tokenize method for content      
    }

    file.close();

    vector<string> vec = t.GetTokens();
    for(string tokens : vec){
        char space = ' ';
        for(int i = 0; i < tokens.size(); i++){  //traverses a string and compares indexed chars to white space
            if(tokens[i] == space)
                tokens[i] = ',';                //replaces white space with a comma
        }
        cout << tokens << endl; 
       } 
    //deconstructor automatically runs when the program is considered complete
}
