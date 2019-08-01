#ifndef __PROG2_1_HPP__
#define __PROG2_1_HPP__
#include <vector>
#include <string>
#include <queue>


class Tokenizer{
    public:
    Tokenizer();          //constructor
    ~Tokenizer();         //destructor
    void Tokenize(std::string line);
    std::vector<std::string> GetTokens();

    private:
    int *data;                  //required to allocate memory
    std::queue<std::string> q;  //class level queue used in tokenize and gettoken methods
    int counter;                //used to count lines during tokenize method

};

#endif
