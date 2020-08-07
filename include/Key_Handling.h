#ifndef KEY_HANDLING_H
#define KEY_HANDLING_H
#include <bitset>

class Key_Handling
{
    public:
        std::bitset<48> subkeys[16];
        std::bitset<28> C;
        std::bitset<28> D;

        void run_PC1(std::bitset<64> key, std::bitset<28>* C, std::bitset<28>* D);
        void LHS(int round);
        std::bitset<56> combine(std::bitset<28>* C, std::bitset<28>* D);
        void run_PC2(std::bitset<56> pre_subkey, std::bitset<48>* subkey);
        void generateKeys(std::bitset<64> key, char ED);
        void reverse_subkeys();

};

#endif // KEY_HANDLING_H
