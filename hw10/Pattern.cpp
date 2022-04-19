#include "Pattern.h"
#include <iostream>
#include <fstream>
#include <unordered_map>

Pattern::Pattern(std::string word, int count){
    this->word = word;
    this->count = count;
}

Pattern:: ~Pattern(){
    
}

std::string Pattern:: getString(){
    return this->word;
}

int Pattern::getNum(){
    return this->count;
}
