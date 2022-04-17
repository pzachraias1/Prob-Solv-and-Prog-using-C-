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
    Pattern(const std::string word, const int count);
    virtual ~Pattern();
    
    std::unordered_map<std::string, std::vector<Pattern*>> lookupTable();
};

#endif
