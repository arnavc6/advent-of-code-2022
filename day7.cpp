#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <unordered_map>
int main(){
    std::fstream file;
    std::vector<std::string> lines;
    file.open("/Users/arnavchokshi/Downloads/advent-of-code-2022/day7input.txt",std::ios::in);
    std::string line;
    while(getline(file, line)) {
        lines.__emplace_back(line);
    }
    int final = 0;
    int max = 0;
    std::vector<int> sizes;
    for(int i = 0; i < lines.size(); i++){
        if(lines[i].size() >= 6){
            if(lines[i].substr(0, 4) == "$ cd" && lines[i].substr(5) != ".."){
                std::string dirName = lines[i].substr(5);
                int in = 1;
                int out = 0;
                int size = 0;
                for(int j = i + 1; j < lines.size(); j++){
                    if(lines[j].size() >= 6){
                        if(lines[j].substr(0, 4) == "$ cd"){
                            if(lines[j].substr(5) == ".."){
                                out++;
                            }
                            else{
                                in++;
                            }
                        }
                        else if(lines[j].substr(0, 3) != "dir"){
                            size += std::stoi(lines[j].substr(0, lines[j].find(" ")));
                        }
                        if(in == out){
                            break;
                        }
                    }
                }
                //std::cout << dirName << " " << size << "\n";
                if(size <= 100000){
                    final += size;
                }
                sizes.__emplace_back(size);
            }
        }
    }
    int current = sizes[0];
    int min = 2147483647;
    for(int i = 1; i < sizes.size(); i++){
        if(current - sizes[i] <= 40000000 && sizes[i] < min){
            min = sizes[i];
        }
    }
    std::cout << min << "\n";
}