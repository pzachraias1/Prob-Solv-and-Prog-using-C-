#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "Pattern.h"

int main(int argc, const char * argv[]) {
    
    
    std::ifstream in("test.txt");
    std::string s = "";
    int sizeOfPattern = 4;
    std::unordered_map<std::string, int> map;
    
    while (in.good()){
        std::string word;
        in >> word;
        s += word + " ";
        //std::cout << word << std::endl;
    }
    for (int i = 0; i< s.length() -(sizeOfPattern+1); i++){
        std::string buff = s.substr(i, sizeOfPattern);
        if (map.find(buff) == map.end()){
            map[buff] = 1;
        }
        else {
            map[buff] += 1;
        }
    }
    
    std::unordered_map<std::string, std::vector<Pattern*>> lookup;
    
    int i = 0;
    for (auto const &pair: map) {
        std::string w = pair.first;
        int num = pair.second;
        std::string prefix = w.substr(0, w.length()-1);
        
        /*for (int j = 0; j<=num; j++){
            if (w.substr(j, prefix.size()) == prefix){
                lookup [prefix] = std::vector<Pattern*>();
                //std::cout << "blank" << std::endl;
            }
            else{
                lookup[prefix].push_back(new Pattern(w, num));
                //std::cout << "working"<< std::endl;
            }
        }
        
        
        //int j = 0;
        */
        i++;
        std::cout << std::endl;
        std::cout << "\n" << i<< ". Word: " << w<< std::endl;
        std::cout << "Prefix: " << prefix<< std::endl;
        
        for (auto const &pair2: map){
            std::string w2 = pair2.first;
            for (int j = 0; j< (w2.size() - prefix.size() +1 ); j++){
                if (w2.substr(j, prefix.size()) != prefix){
                    lookup [prefix] = std::vector<Pattern*>();
                    std::cout << w2.substr(j, prefix.size()) << " ][ ";
                }
                else{
                    lookup[prefix].push_back(new Pattern(w, num));
                    std::cout << w2.substr(j, prefix.size()) << " ][ ";
                    std::cout << " WORKING ";
                }
            }
        }
        
        /*if (map.find(prefix) == map.end()){
            lookup [prefix] = std::vector<Pattern*>();
            std::cout << "blank" << std::endl;
        }
        else {
            lookup[prefix].push_back(new Pattern(w, num));
            std::cout << "working"<< std::endl;
        }
         */
        //std::cout<< i<<". " << .first << ": " << pair.second << "\n";
    }
    i = 0;
    for (auto const &pair: lookup){
        i++;
        std::cout<< i<<". " << pair.first << ": [ ";
        std::vector<Pattern*> v = pair.second;

        for (auto const ii : v){
            std::string vString = ii->getString();
            int num = ii->getNum();
            std::cout << vString << ", " << num;
        }
        std::cout << " ]\n"<< std::endl;
    }
    
    in.close();
}
