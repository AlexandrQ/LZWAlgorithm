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

    /*
    *   buff - ��������� ������ �� ������
    *   streamStr - ����� ������
    *   stringBuff - ���������� �����
    *   newChar - ��� �������� ������ ���� � ������
    *   stringBuff_2 - ��� ������ � ���������� ������ ������ ����� for
    *
    */

    int buff,
        countDecoding; 
    bool stringBuffInDictionary, newCodeInTable;   
    string streamStr, stringBuff, stringBuff_2, newChar;
    map<int, string> dictionary;
    vector<int> streamVec;

public:
    LZWDecoding();
    LZWDecoding(vector<int> v, map<int, string> myMap);
    LZWDecoding(map<int, string> myMap);
    ~LZWDecoding();

    void decoding();
    void showStreamStr();
    void showDictionary();
    void GetStreamFromFile();
    void GetRootDictFromFile();
    void outStreamInFile();
};

