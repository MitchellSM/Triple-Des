#include "../include/Key_Handling.h"
#include <bitset>
#include <algorithm>
//#include <iostream>

void Key_Handling::generateKeys(std::bitset<64> key, char ED)
{
    run_PC1(key, &C, &D);
    for(int i = 1; i <= 16; i++)
    {
        LHS(i);
        run_PC2(combine(&C, &D), &subkeys[i]);
        //std::cout << "K" << i << ": " << subkeys[i] << std::endl;
    }
    if (ED == 'd') reverse_subkeys();
}

void Key_Handling::reverse_subkeys()
{
    for (unsigned int i = 0; i < subkeys->size()/2; ++i)
        std::swap(subkeys[i], subkeys[subkeys->size()-i-1]);
}

void Key_Handling::run_PC1(std::bitset<64>key, std::bitset<28>* C, std::bitset<28>* D)
{
    static const int c_split[] = {57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36};
    static const int d_split[] = {63,55,47,39,31,23,15,7,62,54,36,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
    for (int i = 0; i <= 27; i++)
    {
        C->set(27 - i,key[64 - (c_split[i])]);
        D->set(27 - i,key[64 - (d_split[i])]);
    }
}

void Key_Handling::LHS(int round)
{
    int shift_num [] = {0,1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    C = (C<< shift_num[round]) | (C >> (32-shift_num[round]));
    D = (D<< shift_num[round]) | (D >> (32-shift_num[round]));
}

std::bitset<56> Key_Handling::combine(std::bitset<28>* C, std::bitset<28>* D)
{
    std::string newKey = C->to_string() + D->to_string();
    return std::bitset<56>(newKey);
}

void Key_Handling::run_PC2(std::bitset<56>pre_subkey, std::bitset<48>* subkey)
{
    const int PC2 [] = {14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
    for (int i = 0; i <= 47; i++) subkey->set(47 - i,pre_subkey[56 - PC2[i]]);
}
