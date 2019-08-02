#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include "prog2_1.hpp"
using namespace std;

Tokenizer::Tokenizer(){
    this->data = new int[50];   //temporary arbitrary amount of mem allocated
    counter = 0;                //global line counter

}
Tokenizer::~Tokenizer(){
    delete this->data;  //helps prevent any memory leakage when the program finishes 

}

void Tokenizer::Tokenize(string line){ //will tokenize one line; will loop it outside from the driver program
    counter++;
    stringstream lineCount;
    lineCount << counter;
    string currentLine = lineCount.str();   //used for error exception

    stringstream ss(line);              //convert a .txt line to stringstream
    string tok;

    while(getline(ss,tok,' ')){         //loop iterates for each token denoted from white space in given line
        int isNum;
        double db;
        stringstream(tok) >> db;        //converts token to a double via stringstream
        stringstream(tok) >> isNum;     //converts token to an integer via stringstream usage
        double diff = db - isNum;       //finds the difference between a double and its int counterpart

        if( ((tok == "push")  || (tok == "pop")  || (tok == "add")  || (tok == "sub")  ||
             (tok == "mul")   || (tok == "div")  || (tok == "mod")  || (tok == "skip") ||
            (tok == "save"))  || (tok == "get") || ((db != 0) && (diff == 0))){   // using '==' returns boolean whereas '.compare()' would return int
            //requirements are being one of the 9 keywords OR being an integer
                continue;
            }
        else   
            cout << "Error on line " << currentLine << ": Unexpected token: " << tok << endl;
            exit(-1);
            //exits program entirely error message
            }
    q.push(line); //if successful pushes line into a queue initialized in header
    
}

vector<string> Tokenizer::GetTokens(){
    vector<string> v;   //LIFO
    if(q.empty()){
        throw runtime_error("No tokens");
    }
    while(!q.empty()){
        v.push_back(q.front()); //FIFO queue to LIFO vector
        q.pop();                //rather than copy, we iterate to empty the queue while also filling the vector
    }      
    return v;
}
