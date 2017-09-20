#include "LZWAlg.h"
#include <fstream>


LZWAlg::LZWAlg() : count(0), len(1), countStr(-1), strBuffInDictionary(false)
{
}

LZWAlg::LZWAlg(string s) : count(0), len(1), countStr(-1), strBuffInDictionary(false), inputStream(s)
{
}




LZWAlg::~LZWAlg()
{
}

//составл€ем корневую часть таблицы цепочек
void LZWAlg::rootOfDictionary() {
    for (int i = 0; i < inputStream.size(); i++) {
        strBuff = inputStream[i];
        for (auto it = dictionary.begin(); it != dictionary.end(); ++it)      //провер€ем наличие символа в таблице
        {
            if (strBuff == it->second) {
                strBuffInDictionary = true;
            }
        }
        if (!strBuffInDictionary) {                                       //если символа нет в map, то добавл€ем его и присваиваем номер
            dictionary.insert(pair<int, string>(count, strBuff));
            count++;
        }
        strBuffInDictionary = false;
    }
    rootDict = dictionary;
}


void LZWAlg::dynamicOfDictionary() {
    for (int i = 0; i < inputStream.size() - 1; i++) {
        strBuff = inputStream[i];
        for (auto it = dictionary.begin(); it != dictionary.end(); ++it)      //провер€ем наличие символа в таблице
        {
            if (strBuff == it->second) {                         //если символ есть, то добавл€ем к нему следующий                
                strBuff += inputStream[i + len];
                it = dictionary.begin();
                len++;
                countStr++;
            }
        }

        if (countStr > 0) {
            i += countStr;
        }

        //если символа нет в map, то добавл€ем его и присваиваем номер
        dictionary.insert(pair<int, string>(count, strBuff));       
        
        //добавл€ем значение в поток
        strBuff.pop_back();
        for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
        {
            if (strBuff == it->second) {
                stream.push_back(it->first);
            }
        }
        //добавл€ем последний элемент строки в поток
        if (i >= inputStream.size() - 2) {
            for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
            {
                strBuff = inputStream[inputStream.size() - 1];
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
    this->inStreamFromFile();                   //читаем строку дл€ колировани€ из файла
    this->rootOfDictionary();                   //составл€ем корневой словарь
    this->dynamicOfDictionary();                //составл€ем весь словарь
    this->wOutStreamInFile(getStream());        //записываем выходной поток в файл
    this->wRootDictInFile(getRootDict());       //записываем корневой словарь в файл
}


void LZWAlg::showStream() {
    cout << endl << "¬ыходной поток при кодировании: ";
    for (auto it = stream.begin(); it != stream.end(); ++it)
    {
        cout << *it << " ";
    }
}


void LZWAlg::showDictionary() {
    cout << endl << "“аблица цепочек при кодировании:" << endl;
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

  void LZWAlg::wOutStreamInFile(vector<int> wVec)
{
    ofstream f("OutStream1.txt");
    for (unsigned int i = 0; i <wVec.size(); i++) {
        f << " " << wVec.at(i);             //запись файла
    }
    f.close();
}

void LZWAlg::wRootDictInFile(map<int, string> myMap)
{
    ofstream f("outRootDictInFile.txt");

    for (auto it = myMap.begin(); it != myMap.end(); ++it)      
    {
        f << it->first << " " << it->second << endl;        
    }
    
    f.close();
} 

void LZWAlg::inStreamFromFile() {
    string s;
    ifstream f("StringForCodding.txt");
    while (!f.eof()) {
        f >> s;
        inputStream += s;
    }
    f.close();
    cout << " одируем '" + inputStream + "'";
}
