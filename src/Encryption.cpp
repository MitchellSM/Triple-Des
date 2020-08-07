#include "../include/Encryption.h"

Encryption::Encryption(char type, std::string file)
{
    e_d = type;
    filename = file;
}

Encryption::~Encryption()
{

}
