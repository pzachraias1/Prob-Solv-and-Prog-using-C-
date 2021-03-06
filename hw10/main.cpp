#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include "Pattern.h"

int main(int argc, const char * argv[]) {
    
    
    std::ifstream in("training.txt");
    std::string s = "";
    
    int sizeOfPattern = 8;
    std::unordered_map<std::string, int> map;
    
    while (in.good()){
        std::string word;
        in >> word;
        s += word + " ";
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
        
        if (lookup.find(prefix) == lookup.end()){
            lookup [prefix] = std::vector<Pattern*>();
        }
        lookup[prefix].push_back(new Pattern(w, num));
    }
    
    
    i = 0;
    double total = 0.0;
    
    for (auto const &pair: lookup){
        i++;
        //std::cout<< i<<". " << pair.first << ": [ ";

        std::vector<Pattern*> v = pair.second;

        double prob = 0.0;
        //double total = 0.0;
        
        
        for (int ii = 0; ii < v.size(); ii++){
            std::string vString = v[ii] ->getString();
            int num = v[ii]->getNum();
            
            int j = 0;
            total = 0;
            while (j< v.size()){
                total += num;
                j++;
            }
            
            prob += (double) (num/total);
            v[ii]->setCum(prob);
            
            //std::cout << "(Pattern String: \"" << vString << "\" Pattern Count: " << num << ") ";
            //std::cout << " Probability: " << v[ii]->getCum() << std::endl;
            
        }
        //std::cout << "]\n"<< std::endl;
    }
    
    std::string input = "";
    std::cout << "Enter a word or letter: ";
    std::cin >> input;
    std::string ranName = input;
    int ranSize = ranName.length();
    double ranNum = (double) rand()/(double) RAND_MAX;
    //std::cout << "Number is : " << ranNum << std::endl;
    
    int countingSize = 0;
    
    int jj = 0;
    int position =ranName.length()-ranSize;
    
    while (countingSize != lookup.size()){
        ranNum = (double) rand()/(double) RAND_MAX;
        //std::cout << "Number is : " << jj << std::endl;
        
        countingSize = 0;
        std::cout << "Random Name: (" << ranName<<")" << std::endl;
        //std::cout << "Position: " << position << std::endl;
        for (auto const &loop: lookup){
            
            std::string word = loop.first.substr(0, ranSize);
            std::string ranHolder = ranName.substr(position, ranSize);
            std::vector<Pattern*> v = loop.second;
            
            //std::cout << "word: (" << word<<")" << "ranHolder: (" << ranHolder<<")" << std::endl;
            
            if (word == ranHolder){
                jj++;
                for (auto const &pool: v){
                    std::string placeHolder = pool->getString().substr(ranSize, sizeOfPattern);
                    //std::cout << "Vector String: (" << pool->getString()<<")" << std::endl;
                    //std::cout << "Place Holder: " << placeHolder << std::endl;
                    //std::cout << "Cum: " << jj << std::endl;
                    if (ranNum< pool->getCum()){
                        ranName += placeHolder;
                        position =ranName.length()-ranSize;
                        break;
                    }
                }
                break;
            }
            else {
                countingSize ++;
            }
        }
        
        if ( jj == 100){
            break;
        }
        std::cout << std::endl;
        //ranSize = ranName.length();
    }
    
    std::cout << "\n" << ranName << std::endl;
     
     
    in.close();
}
