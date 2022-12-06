#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
bool isUnique(std::string str){
    for(int i = 0; i < str.size() - 1; i++){
        for(int j = i + 1; j < str.size(); j++){
            if(str[i] == str[j]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    std::fstream file;
    file.open("/Users/arnavchokshi/Downloads/advent-of-code-2022/day6input.txt",std::ios::in);
    std::string line;
    std::string sub;
    while(getline(file, line)) {
        int j = 14;
        for(int i = 0; i < line.size(); i++){
            sub = line.substr(i, j);
            std::cout << sub << " ";
            if(isUnique(sub)){
                std::cout << i + 14 << "\n";
                break;
            }
        }
    }
}