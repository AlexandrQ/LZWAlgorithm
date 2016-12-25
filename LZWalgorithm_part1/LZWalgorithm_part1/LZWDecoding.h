#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class LZWDecoding
{
private:

    int buff,
        countDecoding; 
    bool stringBuffInDictionary;   
    string streamStr, stringBuff, stringBuff_2, newChar;
    map<int, string> dictionary;
    vector<int> streamVec;

public:
    LZWDecoding();
    LZWDecoding(vector<int> v, map<int, string> myMap);
    ~LZWDecoding();

    void decoding();
    void showStreamStr();
    void showDictionary();
};

