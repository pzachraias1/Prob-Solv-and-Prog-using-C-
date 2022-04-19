#ifndef Pattern_hpp
#define Pattern_hpp
#include <iostream>
#include <fstream>
#include <unordered_map>

class Pattern{
private:
    std::string word;
    int count;
    
public:
    Pattern(std::string word, int count);
    virtual ~Pattern();
    
    std::string getString();
    int getNum();
};

#endif
