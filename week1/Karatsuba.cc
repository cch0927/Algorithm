#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm> 
//int multiplier(int, int);
std::string multiplier(std::string, std::string);
std::string bigNumberAdder(std::string, std::string);
std::string bigNumberSubtracter(std::string, std::string);
std::string padZerosAtTheEnd(std::string, int);

int main(){
    //For basic testing
    std::cout<< multiplier("1234","5678") << " "<<1234*5678<<"\n";
    //For assignment
    std::cout<< multiplier("3141592653589793238462643383279502884197169399375105820974944592",
            "2718281828459045235360287471352662497757247093699959574966967627") <<"\n";
    return 1;
}

/*  Use string type to record number.
 *  Because int type will cause overflow.
 */
std::string multiplier(std::string num1, std::string num2){
    
    //  In case one of number is smaller than 10
    if (num1.size() < 2 || num2.size() < 2) {
        return std::to_string(std::stoul(num1) * std::stoul(num2));
    }
    int length =std::max(num1.size(), num2.size());
    int modLength = (length + 1) / 2;
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
    std::string part1 = multiplier(num1_H, num2_H);
    std::string part2 = multiplier(num1_L, num2_L);
    std::string part3 = multiplier(bigNumberAdder(num1_H, num1_L), 
                                   bigNumberAdder(num2_H, num2_L));
    part3 = bigNumberSubtracter(part3, part1);
    part3 = bigNumberSubtracter(part3, part2);

    std::string ans = "";
    ans = padZerosAtTheEnd(part1, modLength*2);
    ans = bigNumberAdder(ans, padZerosAtTheEnd(part3, modLength));
    ans = bigNumberAdder(ans, part2);
    return ans;
}

std::string padZerosAtTheEnd(std::string strNum, int length){
    std::string strAns = strNum;
    while(--length>=0){
        strAns = strAns + "0";
    }
    return strAns;
}

std::string bigNumberAdder(std::string strNum1, std::string strNum2){
    std::string strSum = "";
    int nTemp = 0;
    int nSum ,nCarry;
    nSum = nCarry = 0;
    for (unsigned int nIter = 0;nIter < std::max(strNum1.size(), strNum2.size());++nIter){
        if (nIter < std::min(strNum1.size(), strNum2.size())){
            const char a = strNum1[strNum1.size() - 1 - nIter];
            const char b = strNum2[strNum2.size() - 1 - nIter];
            nTemp = int(a) - '0' + int(b) - '0';
        }
        else {
            nTemp = strNum1.size() > strNum2.size() ? 
                int(strNum1[strNum1.size() - 1 - nIter]) - '0' : 
                int(strNum2[strNum2.size() - 1 - nIter]) - '0';
        }
        nSum = (nTemp + nCarry) % 10;
        nCarry = nTemp + nCarry >= 10? 1:0;
        strSum = std::to_string(nSum) + strSum;
    }
    if(nCarry == 1){
        strSum = "1" + strSum;
    }
    return strSum;
}
std::string bigNumberSubtracter(std::string strNum1, std::string strNum2){
    std::string strSum = "";
    int nTemp = 0;
    int nSum ,nCarry;
    int zeroCounter = -1;
    nSum = nCarry = 0;
    for (unsigned int nIter = 0;nIter < std::max(strNum1.size(), strNum2.size());++nIter){
        if (nIter < std::min(strNum1.size(), strNum2.size())){
            const char a = strNum1[strNum1.size() - 1 - nIter];
            const char b = strNum2[strNum2.size() - 1 - nIter];
            nTemp = int(a) - '0' -( int(b) - '0');
        }
        else {
            nTemp = strNum1.size() > strNum2.size() ? 
                int(strNum1[strNum1.size() - 1 - nIter]) - '0' : 
                int(strNum2[strNum2.size() - 1 - nIter]) - '0';
        }
        if(nTemp < 0) {
            nSum = nTemp + 10 + nCarry;
            nCarry = -1;
        }
        else{
            nSum = nTemp + nCarry;
            nCarry = 0;
        }
        if(nSum < 0) {
            nSum +=10;
            nCarry -= 1;
        }
        strSum = std::to_string(nSum) + strSum;
    }
    for(int nIter = 0;nIter < strSum.size();++nIter){
        if(strSum[nIter] == '0'){
            zeroCounter = nIter;
        }
        else{
            break;
        }
    }
    strSum = strSum.substr(zeroCounter + 1, strSum.size() - (zeroCounter + 1));
    return strSum;
}
