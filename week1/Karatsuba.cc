#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm> 
//int multiplier(int, int);
unsigned int multiplier(std::string, std::string);

int main(){
    std::string n1, n2;
    std::cin >> n1 >> n2;
    std::cout << multiplier(n1, n2) << std::endl;
    return 1;
}

//Assume str1 and str2's length are always a power of 2
unsigned int multiplier(std::string num1, std::string num2){
    if (num1.size() < 2 && num2.size() < 2) {
        std::cout << "in "<< num1 << " " << num2 <<" = " <<std::stoul(num1) * std::stoul(num2)<< std::endl;
        return std::stoul(num1) * std::stoul(num2);
    }
    int length =std::max(num1.size(), num2.size());
    int extra1 = num1.size() < num2.size() ? num2.size()-num1.size():0;
    int extra2 = num2.size() < num1.size() ? num1.size()-num2.size():0;
    std::string num1_H = num1.substr(0+extra1, length/2 - extra1);
    std::string num1_L = num1.substr(length/2-extra1, length/2);
    std::string num2_H = num2.substr(0+extra2, length/2 - extra2);
    std::string num2_L = num2.substr(length/2-extra2, length/2);
    if(num1_H == ""){
        num1_H = "0";
    }
    if(num2_H == ""){
        num2_H = "0";
    }
    std::cout<< "length:" << length<<" " <<num1 <<" "<<num2<<"\n";
    std::cout << num1_H <<" "<<num1_L<<" " <<pow(10, (length / 2))<<std::endl;
    std::cout << num2_H <<" "<<num2_L<<std::endl;
    getchar();
    unsigned int part1 = multiplier(num1_H, num2_H);
    unsigned int part2 = multiplier(num1_L, num2_L);
    unsigned int part3 = multiplier(std::to_string(stoi(num1_H) + stoi(num1_L)), std::to_string(stoi(num2_H)+stoi(num2_L))) - part1 - part2;
    return pow(10, length) * part1 + 
        pow(10, (length/2)) * part3 + 
        part2;
}
