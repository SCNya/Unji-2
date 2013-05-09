#include "un.h"

Un::Un (string n):
    err(false),
    hard_th(thread::hardware_concurrency()-1)
{
    str = new string(n);
    ss = new stringstream;
    len = new unsigned long long(0);
    size = new unsigned long long(0);
    Start();
}

Un::~Un()
{
    delete ss;
    ss = 0;
    delete len;
    len = 0;
    delete size;
    size = 0;
    delete str;
    str = 0;
    delete in;
    in = 0;
    if(!err)
    {
        delete lst;
        lst = 0;
    }
}

void Un::Start()
{
    Open();
    if(!err)
        Boot();
}

void Un::Open()
{
    in = new ifstream;
    (*in).open((*str).c_str());
    if (!(*in).good())
    {
        cout << "Error: 1" << endl;
        err = true;
    }
}

void Un::Create()
{
    lst = new List_bundle;
    unsigned long min_size(hard_th*1000);
    unsigned short i;
    Fill work(lst, str, hard_th, *size, min_size);
    if ((hard_th <= 1) || ((*size) <= min_size))
    {
        th = new thread(ref(work));
        th->join();
        delete th;
        th = 0;
    }
    else
    {
        thread **mass = new thread *[hard_th];
        for (i = 0; i < hard_th; i++)
            mass[i] = new thread(ref(work));
        for (i = 0; i < hard_th; i++)
        {
            th = mass[i];
            th->join();
        }
        for (i = 0; i < hard_th; i++)
        {
            delete mass[i];
            mass[i] = 0;
        }
        delete [] mass;
        mass = 0;
    }

    lst->show_all();
}

void Un::Boot()
{
    *ss << (*in).rdbuf();
    *str = (*ss).str();
    *size = (*str).size();
    (*in).close();
}

void Un::Find()
{
    if(!err)
    {
        Create();
    }
}
