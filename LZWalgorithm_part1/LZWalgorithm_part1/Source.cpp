#include <iostream>
#include "LZWAlg.h"
#include "LZWDecoding.h"

using namespace std;

int main() {   
    
    LZWAlg objOne("eedded");  //abacabadabacabae
    objOne.coding();
    objOne.showDictionary();
    objOne.showStream();

    LZWDecoding objTwo(objOne.getStream(), objOne.getRootDict());
    objTwo.decoding();
    objTwo.showDictionary();

    cout << endl << "eedded" << endl;
    objTwo.showStreamStr();

    system("Pause");
    return 0;
}