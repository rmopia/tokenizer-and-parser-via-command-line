#ifndef __PROG2_3_HPP__
#define __PROG2_3_HPP__
#include <string>
#include <vector>

class Parser{
    public:
    Parser();
    ~Parser();
    bool Parse(std::vector<std::string> v);

    private:
    int *data;
};

#endif
