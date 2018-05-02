#include <vector>
#include <fstream>
#include<iostream>
class mergeSort{
    public:
        mergeSort(){};
        bool parseFile(const char*); 
        double doSort(std::vector<int>&, int, int);
        std::vector<int>& getNumArray();
    private:
        std::vector<int> vNumber;
};

