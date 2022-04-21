#ifndef Pattern_hpp
#define Pattern_hpp
#include <iostream>
#include <fstream>
#include <unordered_map>

class Pattern{
private:
    std::string word;
    int count;
    double cumProb;
    
public:
    Pattern(std::string word, int count);
    virtual ~Pattern();
    
    std::string getString();
    int getNum();
    double setCum(double total);
    double getCum();
};

#endif
