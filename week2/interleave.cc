#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "mergeSort.hh"


int main(int argc, const char **argv){
    mergeSort *obj = new mergeSort();
    obj->parseFile(argv[1]);
}


