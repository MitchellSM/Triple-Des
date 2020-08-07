#ifndef USER_INPUT_H
#define USER_INPUT_H
#include <string>
#include <bitset>

class User_Input
{
    public:
        void get_U_IN(std::string out, unsigned int state, int i);
        char user_E_D;
        std::string file_name;
        std::bitset<64> keys[3];

    private:
        void valid_input(std::string in);
        void valid_file(std::string in);
        void valid_key(long long int in, int i);
};

#endif // USER_INPUT_H
