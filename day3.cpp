#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
int main(){
    std::fstream file;
    file.open("/Users/arnavchokshi/Downloads/advent-of-code-2022/day3input.txt",std::ios::in);
    std::string line;
    int index = 0;
    int score = 0;
    bool flag = false;
    std::string str1;
    std::string str2;
    std::string str3;
    while(getline(file, line)) {
        if(index == 0){
            str1 = line;
            index++;
        }
        else if(index == 1){
            str2 = line;
            index++;
        }
        else if(index == 2){
            str3 = line;
            index = 0;
            for(int i = 0; i < str1.size(); i++){
                flag = false;
                for(int j = 0; j < str2.size(); j++){
                    for(int k = 0; k < str3.size(); k++){
                        std::cout << str1[i] << " " << str2[j] << " " << str3[k] << std::endl;
                        if(str1[i] == str2[j] && str1[i] == str3[k]){
                            if(str1[i] <= 'Z'){
                                score += str1[i] - 38;
                            }
                            else{
                                score += str1[i] - 96;
                            }
                            flag = true;
                            break;
                        }
                    }
                    if(flag){
                        break;
                    }
                }
                if(flag){
                    break;
                }
            }

        }
    }
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;
    std::cout << score << std::endl;
}