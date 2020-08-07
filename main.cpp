#include <iostream>
//#include <string>
#include "C:\Users\Mitchell Sulz-Martin\Documents\CPSC 3730\Triple_DES-3730\include\User_Input.h"
#include "C:\Users\Mitchell Sulz-Martin\Documents\CPSC 3730\Triple_DES-3730\include\Key_Handling.h"

int main()
{
    User_Input UI;
    Key_Handling KH;
    UI.get_U_IN("either \'E\' or \'D\': ", 0, 0);
    KH.generateKeys(UI.keys[0], UI.user_E_D);
}
