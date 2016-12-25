#include "LZWAlg.h"


LZWAlg::LZWAlg()
{
}

LZWAlg::LZWAlg(string s) : count(0), len(1), countStr(-1), strBuffInDictionary(false), str(s)
{
}


LZWAlg::~LZWAlg()
{
}


void LZWAlg::rootOfDictionary() {
    for (int i = 0; i < str.size(); i++) {
        strBuff = str[i];
        for (auto it = dictionary.begin(); it != dictionary.end(); ++it)      //��������� ������� ������� � �������
        {
            if (strBuff == it->second) {
                strBuffInDictionary = true;
            }
        }
        if (!strBuffInDictionary) {                                       //���� ������� ��� � map, �� ��������� ��� � ����������� �����
            dictionary.insert(pair<int, string>(count, strBuff));
            count++;
        }
        strBuffInDictionary = false;
    }
    rootDict = dictionary;
}


void LZWAlg::dynamicOfDictionary() {
    for (int i = 0; i < str.size() - 1; i++) {
        strBuff = str[i];
        for (auto it = dictionary.begin(); it != dictionary.end(); ++it)      //��������� ������� ������� � �������
        {
            if (strBuff == it->second) {                         //���� ������ ����, �� ��������� � ���� ���������                
                strBuff += str[i + len];
                it = dictionary.begin();
                len++;
                countStr++;
            }
        }

        if (countStr > 0) {
            i += countStr;
        }

        //??���� ������� ��� � map, �� ��������� ��� � ����������� �����
        dictionary.insert(pair<int, string>(count, strBuff));       
        //��������� �������� � �����
        strBuff.pop_back();
        for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
        {
            if (strBuff == it->second) {
                stream.push_back(it->first);
            }
        }
        //��������� ��������� ������� ������ � �����
        if (i >= str.size() - 2) {
            for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
            {
                strBuff = str[str.size() - 1];
                if (strBuff == it->second) {
                    stream.push_back(it->first);
                }
            }
        }        
        count++;
        len = 1;
        countStr = -1;
    }
}


void LZWAlg::coding() {
    this->rootOfDictionary();
    this->dynamicOfDictionary();
}


void LZWAlg::showStream() {
    for (auto it = stream.begin(); it != stream.end(); ++it)
    {
        cout << *it << " ";
    }
}


void LZWAlg::showDictionary() {
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }
}

map<int, string> LZWAlg::getRootDict() {
    return rootDict;
}

vector<int> LZWAlg::getStream() {
    return stream;
}

