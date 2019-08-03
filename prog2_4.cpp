#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "prog2_1.hpp"
#include "prog2_3.hpp"
using namespace std;

int main(int argc, char *argv[]){
    if(argc < 2){  
        return -1;             
    }

    Tokenizer t;
    Parser p;
    ifstream file(argv[1]);
    string content;

    while(getline(file, content)){
        t.Tokenize(content);
    }

    file.close();
    
    vector<string> vec = t.GetTokens();
    bool b = p.Parse(vec);

    if(b == true){                          //if parsing is successful then print, replacing white space with commas
        for(string parsedLine : vec){
            char space = ' ';
            for(int i = 0; i < parsedLine.size(); i++){
                if(parsedLine[i] == space){
                    parsedLine[i] = ',';
                }
            }
            cout << parsedLine << endl;
        }
    }
    else
        exit(-1); //if false exits program with "-1" meaning error

}
