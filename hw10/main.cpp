#include <iostream>
#include <fstream>
#include <unordered_map>


int main(int argc, const char * argv[]) {
    
    
    std::ifstream in("test.txt");
    //std::string s;
    //int count = 0;
    std::unordered_map<std::string, int> map;
    
    while (in.good()){
        std::string word;
        in >> word;
    }
    in.close();
}
