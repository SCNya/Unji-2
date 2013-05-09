//Unji 2  by Alexeenko Vsevolod 09.05.2013 13:08 ver. alpha alpha 2.0.2 (ASCII)
#include "un.h"

int main()
{
    Un*one = new Un("bbe.txt");
    one->Find();
    delete one;
    return 0;
}
