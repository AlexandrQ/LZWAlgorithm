#include "LZWDecoding.h"



LZWDecoding::LZWDecoding()
{
}


LZWDecoding::LZWDecoding(vector<int> v, map<int, string> myMap) : dictionary(myMap),
streamVec(v),
countDecoding(myMap.size()),
stringBuffInDictionary(true)
{
}


LZWDecoding::~LZWDecoding()
{
}


void LZWDecoding::decoding() {
    for (auto it = streamVec.begin(); it != streamVec.end(); ++it) {
        buff = *it;
        //если символ есть в потоке, то записываем его буквенную трансляцию в строку и stringBuff
        for (auto iter = dictionary.begin(); iter != dictionary.end(); ++iter)
        {
            if (buff == iter->first) {
                streamStr += iter->second;
                stringBuff += iter->second;
                newChar = iter->second;
                break;
            }            
        }

      

        stringBuff_2 = stringBuff[0];
        for (int i = 1; i < stringBuff.size(); i++) {
            stringBuff_2 += stringBuff[i];
            stringBuffInDictionary = false;
            for (auto iter = dictionary.begin(); iter != dictionary.end(); ++iter)
            {
                //если есть, то меняем значение stringBuffInDictionary
                if (stringBuff_2 == iter->second) {
                    stringBuffInDictionary = true;
                    break;
                }
            }
            if (!stringBuffInDictionary) {
                break;
            }
        }


        //если значеие stringBuffInDictionary не было изменено
        //добавлем в словарь stringBuff и присваиваем номер
        if (!stringBuffInDictionary) {
            dictionary.insert(pair<int, string>(countDecoding, stringBuff_2));
            countDecoding++;
            stringBuff = newChar[newChar.size() - 1];
            newChar.clear();
        }
        stringBuffInDictionary = false;
    }
}


void LZWDecoding::showStreamStr() {
    cout << endl << streamStr << endl;
}


void LZWDecoding::showDictionary() {
    cout << endl;
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }
}
