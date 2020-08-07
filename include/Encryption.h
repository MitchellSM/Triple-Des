#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <string>


class Encryption
{
    public:
        Encryption(char, std::string);
        virtual ~Encryption();

    protected:

    private:
        char e_d;
        std::string filename;

};

#endif // ENCRYPTION_H
