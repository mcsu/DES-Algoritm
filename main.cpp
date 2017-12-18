#include <iostream>
#include "data_tables.h"
#include "bit_tables.h"
#include "permutations.h"
#include "data_messages_examples.h"
using namespace std;

int main() {
    cout<<"DES"<<endl;
    cout<<"loaded datas was in data_tables.h"<<endl;
    cout<<"In data_table.h, testTable is the message to encrypt, testKey is the key"<<endl;
    cout<<"++++++++++++++++++++++++++++++++++"<<endl;
    char *init= new char[64];
    init = testTable;
    cout<<"MESSAGE:"<<endl;
    displayBitTable(init,64);
    displayAsHex(init,64);


    //生成子key
    cout<<"KEY:"<<endl;
    displayBitTable(testKey,64);
    displayAsHex(testKey,64);
    char **kn=new char *[48];
    kn = generateSubKey(testKey);
    for (int i = 0; i < 16; ++i) {

        cout<<"subKey"<<i<<endl;
        displayBitTable(kn[i],48);
        displayAsHex(kn[i],48);
    }
    char *firstperm;
//初始变换
    firstperm=permute(testTable,init_perm,64);
//分成L0R0
    char *l0,*r0;
    cout<<endl;
    cout<<"ROUND 1"<<endl;
    l0=makeLR0(firstperm,32,0);
    r0=makeLR0(firstperm,32,1);
    cout<<"L0:";
    displayBitTable(l0,32);
    displayAsHex(l0,32);
    cout<<"R0:";
    displayBitTable(r0,32);
    displayAsHex(r0,32);
    char *l,*r;

    cout<<"used key:"<<endl;
    displayBitTable(kn[0],48);
    displayAsHex(kn[0],48);
    cout<<"Expansion:";
    Iteration(r0, xOR(l0,f(r0,kn[0],0),32),0);


    return 0;
}
