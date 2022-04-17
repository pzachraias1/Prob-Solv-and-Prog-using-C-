#include "Pattern.hpp"
#include <iostream>
#include <fstream>
#include <unordered_map>

Pattern::Pattern(const std::string word, const int count){
    this->word = word;
    this->count = count;
}

Pattern:: ~Pattern(){
    
}

std::unordered_map<std::string, std::vector<Pattern*>> Pattern:: lookupTable(){
    std::unordered_map<std::string, std::vector<Pattern*>> lookup;
    
    return lookup;
}
