#include <vector>
#include <fstream>
#include<iostream>
class mergeSort{
    public:
        mergeSort(){};
        bool parseFile(const char*); 
        int doSort(std::vector<int>&);
    private:
        std::vector<int> vNumber;
};

