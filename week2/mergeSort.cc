#include "mergeSort.hh"
bool mergeSort::parseFile(const char *fileName){
    std::ifstream fileHeader;
    std::string strBuf;
    fileHeader.open(fileName, std::ios::in);
    if (fileHeader.is_open())
    {
        while (getline(fileHeader, strBuf)){
            vNumber.push_back(std::stoi(strBuf));
            std::cout << vNumber.back() <<"\n";
        }
        fileHeader.close();
        return true;
    }
    else {
        return false;
    }
}

int mergeSort::doSort(std::vector<int>& vInt){
}
