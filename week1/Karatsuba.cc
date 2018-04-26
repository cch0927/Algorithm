#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm> 
//int multiplier(int, int);
unsigned int multiplier(std::string, std::string);

int main(){
    //std::string n1, n2;
    //std::cin >> n1 >> n2;
    //test
    //std::cout<< multiplier("12","34") << " "<<12*34<<"\n";
    std::cout<< multiplier("1234","5678") << " "<<1234*5678<<"\n";
    std::cout<< multiplier("12345678","87654321") << " "<<12345678*87654321<<"\n";
    std::cout<< multiplier("9759571669751178","9751178519759571") << " "<<9759571669751178*9751178519759571<<"\n";
    //std::cout << multiplier(n1, n2) << std::endl;
    return 1;
}

//Assume str1 and str2's length are always a power of 2
unsigned int multiplier(std::string num1, std::string num2){
    //std::cout << "input "<< num1 << " " << num2 << std::endl;
    if (num1.size() < 2 || num2.size() < 2) {
        return std::stoul(num1) * std::stoul(num2);
    }
    int length =std::max(num1.size(), num2.size());
    int modLength = (length + 1) / 2;
    int extra1 = num1.size() < num2.size() ? num2.size()-num1.size():0;
    int extra2 = num2.size() < num1.size() ? num1.size()-num2.size():0;
    std::string num1_H = num1.substr(0, num1.size()-modLength);
    std::string num1_L = num1.substr(num1.size()-modLength, modLength);
    std::string num2_H = num2.substr(0, num2.size()-modLength);
    std::string num2_L = num2.substr(num2.size()-modLength, modLength);
    if(num1_H == ""){
        num1_H = "0";
    }
    if(num2_H == ""){
        num2_H = "0";
    }
    /*std::cout<< "length:" << modLength<<" " <<num1 <<" "<<num2<<"\n";
    std::cout << num1_H <<" "<<num1_L<<" " <<pow(10, (modLength))<<std::endl;
    std::cout << num2_H <<" "<<num2_L<<std::endl;*/
    //getchar();
    unsigned int part1 = multiplier(num1_H, num2_H);
    unsigned int part2 = multiplier(num1_L, num2_L);
    unsigned int part3 = multiplier(std::to_string(stoi(num1_H) + stoi(num1_L)), std::to_string(stoi(num2_H)+stoi(num2_L))) - part1 - part2;
    /*std::cout << num1 << "*" << num2 << "=" << pow(10, modLength*2) * part1 + 
        pow(10, (modLength)) * part3 + 
        part2 << "\n";*/
    return pow(10, modLength*2) * part1 + 
        pow(10, (modLength)) * part3 + 
        part2;
}
