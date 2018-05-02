#include"mergeSort.hh"

//Parsing the numbers from text file into vector
bool mergeSort::parseFile(const char *fileName){
    std::ifstream fileHeader;
    std::string strBuf;
    fileHeader.open(fileName, std::ios::in);
    if (fileHeader.is_open()){
        while (getline(fileHeader, strBuf)){
            vNumber.push_back(std::stoi(strBuf));
        }
        fileHeader.close();
        return true;
    }
    else {
        return false;
    }
}


//   0 1 2 3 nL nL+1 , ..., nM,  nM+1, ..., nR
//   |<---Left----------------->|<---Right-->|
double mergeSort::doSort(std::vector<int>& vInt, int nL, int nR){
    if (nR - nL < 1) {
        return 0;
    } 
    int nM = (nL + nR) / 2;
    double nAns = 0;
    // Divide
    nAns += doSort(vInt, nL, nM);
    nAns += doSort(vInt, nM+1, nR);
    // Combine
    unsigned int nIterL = 0, nIterR = 0;
    std::vector<int> vTemp;
    vTemp.resize(nR - nL + 1);
    for (;nIterL + nIterR <= nR - nL ;){
        bool nRemainInLeft  = (nIterL <= nM - nL)? true:false;
        bool nRemainInRight = (nIterR <  nR - nM)? true:false;
        if (vInt[nL + nIterL] > vInt[nM + 1 + nIterR] && nRemainInLeft && nRemainInRight ){
            vTemp[nIterL+nIterR] = vInt[nM + 1 + nIterR];
            ++nIterR;
            nAns += (nM - nL) + 1 - nIterL;
        }
        else if (vInt[nL + nIterL] < vInt[nM + 1 + nIterR] && nRemainInLeft && nRemainInRight){
            vTemp[nIterL+nIterR] = vInt[nL + nIterL];
            ++nIterL;
        }
        else if(nRemainInLeft) {
            //Padding remain numbers
            vTemp[nIterL+nIterR] = vInt[nL + nIterL];
            ++nIterL;
        }
        else if(nRemainInRight) {
            //Padding remain numbers
            vTemp[nIterL+nIterR] = vInt[nM + 1 + nIterR];
            ++nIterR;
        }
    }
    for (unsigned int nIter = 0;nIter < vTemp.size();++nIter){
        vInt[nL+nIter] = vTemp[nIter];
    }
    return nAns;
}

std::vector<int>& mergeSort::getNumArray(){
    return vNumber;
}
