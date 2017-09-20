#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class LZWAlg
{
private:

    int count,
        len,
        countStr;
    string inputStream, strBuff;
    bool strBuffInDictionary;
        
    map<int, string> dictionary, rootDict;
    vector<int> stream;
    
public:

    LZWAlg();
    LZWAlg(string s);
    ~LZWAlg();

    void rootOfDictionary();
    void dynamicOfDictionary();
    void coding();
    void showStream();
    void showDictionary();
    map<int, string> getRootDict();
    vector<int> getStream();
    void wOutStreamInFile(vector<int> wVec);
    void wRootDictInFile(map<int, string>);

    void inStreamFromFile();
 };

