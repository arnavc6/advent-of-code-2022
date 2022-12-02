#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file = fopen("/Users/arnavchokshi/Downloads/advent-of-code-2022/day2input.txt", "r");
    char mystring[100];
    int score = 0;
    while(fgets(mystring, 100, file)){
        if(mystring[0] == 'A'){
            if(mystring[2] == 'X'){
                score += 3;
            }
            else if(mystring[2] == 'Y'){
                score += 4;
            }
            else if(mystring[2] == 'Z'){
                score += 8;
            }
        }
        else if(mystring[0] == 'B'){
            if(mystring[2] == 'X'){
                score += 1;
            }
            else if(mystring[2] == 'Y'){
                score += 5;
            }
            else if(mystring[2] == 'Z'){
                score += 9;
            }
        }
        else if(mystring[0] == 'C'){
            if(mystring[2] == 'X'){
                score += 2;
            }
            else if(mystring[2] == 'Y'){
                score += 6;
            }
            else if(mystring[2] == 'Z'){
                score += 7;
            }
        }
    }
    std::cout << score << std::endl;
}