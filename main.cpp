//Unji 2  by Alexeenko Vsevolod 09.05.2013 17:20 ver. alpha 2.1.0 (ASCII)
#include "un.h"

int main()
{
    Un*one = new Un("bbe.txt");
    one->Find();
    delete one;
    return 0;
}
