#include <iostream>
#include "LZWAlg.h"
#include "LZWDecoding.h"
#include <conio.h>
#include <string>

using namespace std;

int main() {   

    setlocale(LC_ALL, "Russian"); 
    
    LZWAlg objOne;    
    objOne.coding();            
    objOne.showDictionary();    
    objOne.showStream(); 
    
    LZWDecoding objTwo;
    
    objTwo.decoding();
    objTwo.showDictionary();    
    objTwo.showStreamStr();
    cout << "Done!";
    _getch();
    
    return 0;
}