#include "LZWDecoding.h"
#include <fstream>



LZWDecoding::LZWDecoding() : stringBuffInDictionary(true)
{
}


LZWDecoding::LZWDecoding(vector<int> v, map<int, string> myMap) : dictionary(myMap),
    streamVec(v),
    countDecoding(myMap.size()),
    stringBuffInDictionary(true)
{
}

 LZWDecoding::LZWDecoding(map<int, string> myMap) : dictionary(myMap),
    countDecoding(myMap.size()),
    stringBuffInDictionary(true)
{
}


LZWDecoding::~LZWDecoding()
{
}


void LZWDecoding::decoding() {
    this->GetStreamFromFile();
    this->GetRootDictFromFile();
    countDecoding = dictionary.size();
    for (auto it = streamVec.begin(); it != streamVec.end(); ++it) {
        //����� ��������� ������ �� ������
        buff = *it;
        newCodeInTable = false;
        //���� ������ ���� � ������, �� ���������� ��� ��������� ���������� � ��������� ����� � stringBuff
        for (auto iter = dictionary.begin(); iter != dictionary.end(); ++iter)
        {
            if (buff == iter->first) {
                streamStr += iter->second;
                stringBuff += (iter->second)[0];
                newChar = iter->second;
                newCodeInTable = true;
                break;
            }
            
        }
        
        //���� ������� ��� ����������� � �������
        if (newCodeInTable == false) {            
            stringBuff += stringBuff[0];
            streamStr += stringBuff;
        }
        
        
      

        stringBuff_2 = stringBuff[0];

        for (int i = 1; i < stringBuff.size(); i++) {
            stringBuff_2 += stringBuff[i];
            stringBuffInDictionary = false;
            for (auto iter = dictionary.begin(); iter != dictionary.end(); ++iter)
            {
                //���� ����, �� ������ �������� stringBuffInDictionary
                if (stringBuff_2 == iter->second) {
                    stringBuffInDictionary = true;
                    break;
                }
            }
            if (!stringBuffInDictionary) {
                break;
            }
        }


        //���� ������� stringBuffInDictionary �� ���� ��������
        //�������� � ������� stringBuff � ����������� �����
        if (!stringBuffInDictionary) {
            dictionary.insert(pair<int, string>(countDecoding, stringBuff_2));
            countDecoding++;
            stringBuff = newChar;
            newChar.clear();
        }
        stringBuffInDictionary = false;
    }
    this->outStreamInFile();
}


void LZWDecoding::showStreamStr() {
    cout << endl << "�������� ����� ��� �������������: ";
    cout << streamStr << endl;
}


void LZWDecoding::showDictionary() {
    cout << endl << endl;
    cout << "������� ������� ��� �������������:" << endl;
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }
}

 void LZWDecoding::GetStreamFromFile() {
    ifstream f("OutStream1.txt");
    int s;
    while (!f.eof()) {
        f >> s;
        streamVec.push_back(s);
    }
    f.close();
}

 void LZWDecoding::GetRootDictFromFile() {
     ifstream f("outRootDictInFile.txt");
     int s;
     string str;
     while (!f.eof()) {
         f >> s;
         f >> str;
         dictionary.insert(pair<int, string>(s, str));
     }
     f.close();
 }

 void LZWDecoding::outStreamInFile() {
     ofstream f("OutStream2.txt");
     f << streamStr;
     f.close();
 }

 
