#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
int main(){
    std::fstream file;
    file.open("/Users/arnavchokshi/Downloads/advent-of-code-2022/day4input.txt",std::ios::in);
    std::string line;
    int final = 0;
    std::string d1 = ",";
    std::string d2 = "-";
    while(getline(file, line)) {
        int s = line.find(d1);
        std::string r1 = line.substr(0, s);
        std::string r2 = line.substr(s + 1);
        int s1 = r1.find(d2);
        int s2 = r2.find(d2);
        int r1a = stoi(r1.substr(0, s1));
        int r1b = stoi(r1.substr(s1 + 1));
        int r2a = stoi(r2.substr(0, s2));
        int r2b = stoi(r2.substr(s2 + 1));
        if(!(r1b < r2a || r2b < r1a)){
            final++;
        }
    }
    std::cout << final << std::endl;
}