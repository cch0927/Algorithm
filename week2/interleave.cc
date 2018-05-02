#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "mergeSort.hh"


int main(int argc, const char **argv){
    std::vector<int> testArray;
    mergeSort *obj = new mergeSort();
    obj->parseFile(argv[1]);
    double nAns = obj->doSort(obj->getNumArray(), 0, obj->getNumArray().size()-1);
    std::cout.precision(17);
    std::cout << nAns <<"\n";
}


