#ifndef UN_H
#define UN_H
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <time.h>
#include "fill.h"

using namespace std;

class Un
{

public:
	Un (string);
	~Un();
	void Find();
private:
    void Open();
    void Start();
    void Create();
    void Boot();
    bool err;
    unsigned short const hard_th;
    unsigned long *len, *size;
	ifstream *in;
    string *str;
	stringstream *ss;
    List_bundle *lst;
    thread *th;
};

#endif // UN_H
