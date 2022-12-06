#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stack>
int main(){
    std::fstream file;
    file.open("/Users/arnavchokshi/Downloads/advent-of-code-2022/day5input.txt",std::ios::in);
    std::string line;
    int l = 0;
    bool crates = true;
    std::vector<std::string> crateLines;
    std::vector<std::stack<char> > stacks;
    std::vector<std::vector<int> > instructions;
    std::string d1 = "move ";
    std::string d2 = " from ";
    std::string d3 = " to ";
    while(getline(file, line)) {
        l++;
        if(line == ""){
            crates = false;
            for(int i = 0; i < crateLines.size(); i++){
                std::stack<char> s;
                stacks.__emplace_back(s);
            }
            for(int i = crateLines.size() - 1; i >= 0; i--){
                for(int j = 1; j < crateLines[i].size(); j += 4){
                    if(crateLines[i][j] != ' '){
                        stacks[(j - 1) / 4].push(crateLines[i][j]);
                    }
                }
            }
            continue;
        }
        if(crates){
            crateLines.__emplace_back(line);
        }
        else{
            std::vector<int> instr;
            int i1 = line.find(d1) + 5;
            int i2 = line.find(d2) + 6;
            int i3 = line.find(d3) + 4;
            instr.__emplace_back(std::stoi(line.substr(i1, i2 - 6)));
            instr.__emplace_back(std::stoi(line.substr(i2, i3 - 4)));
            instr.__emplace_back(std::stoi(line.substr(i3)));
            instructions.__emplace_back(instr);
        }
    }
    for(int i = 0; i < instructions.size(); i++){
        std::stack<char> s;
        for(int j = 0; j < instructions[i][0]; j++){
            s.push(stacks[instructions[i][1] - 1].top());
            stacks[instructions[i][1] - 1].pop();
        }
        int ssize = s.size();
        for(int j = 0; j < ssize; j++){
            stacks[instructions[i][2] - 1].push(s.top());
            s.pop();
        }
    }
    for(int i = 0; i < stacks.size(); i++){
        std::cout << stacks[i].top();
    }
}