//Unji  by Alexeenko Vsevolod 06.05.2013 23:29 ver. alpha alpha 2.0.0 (ASCII)
#include "un.h"

int main()
{
    Un*one = new Un("bbe.txt");
    one->Find();
    delete one;
    return 0;
}
