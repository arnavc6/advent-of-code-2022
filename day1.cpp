#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file = fopen("/Users/arnavchokshi/Downloads/advent-of-code-2022/day1input.txt", "r");
    char mystring[100];
    int max = 0;
    int max2 = 0;
    int max3 = 0;
    int holda = 0; 
    while(fgets(mystring, 100, file)){
        if (!strcmp(mystring, "\n")) {
            if(holda > max3){
                max3 = holda;
                if(max3 > max2){
                    int temp = max3;
                    max3 = max2;
                    max2 = temp;
                    if(max2 > max){
                        int t2 = max2;
                        max2 = max;
                        max = t2;
                    }
                }
            }
            holda = 0;
        } else {
            holda += atoi(mystring);
        }
    }
    std::cout << max + max2 + max3 << std::endl;
}