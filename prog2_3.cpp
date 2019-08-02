#include <iostream>
#include <sstream>
#include "prog2_3.hpp"
using namespace std;

Parser::Parser(){
    this->data = new int[50];
}

Parser::~Parser(){
    delete this-> data;
}

bool Parser::Parse(vector<string> v){   //iterating inside the method instead of iterating outside in main()
    int counter = 0;
    string last;

    for(string line : v){   //checking vector line by line
        
        double check;
        last = line.substr(line.length()-2, line.back());   //substring that takes last 2 chars from string line
        stringstream ss(last);
        ss >> check;                                        //substring is converted into a double

        counter++;                                          //counter iterates for each line read via for-each loop
        stringstream lineCount;
        lineCount << counter;                               //counter converted into stringstream and then into a string used during parsing error
        string currentLine = lineCount.str();

        if(((line.substr(0,4) == "push") || (line.substr(0,4) == "save") || (line.substr(0,3) == "get")) && (check != 0)){ 
            continue;
        //checks if the line has an integer following these specific strings
        }       
        else if((line == "pop") || (line == "add") || (line == "mul") || (line == "sub")
            || (line == "div") || (line == "mod") || (line == "skip")) {   
            continue;
        //checks that the whole line only has the one specific string and no following strings
        }
        else{
            cout << "Parse error on line " << currentLine << ": " << line << endl;
            return false;
        }
    }
    return true;
}
