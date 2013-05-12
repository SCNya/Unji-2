#include "cell_str.h"

cell_str::cell_str():
    my_next(0),
    str(0)
{
}

cell_str::cell_str(string * data):
    str(data),
    my_next(0)
{
}

cell_str::~cell_str()
{
    delete str;
    str = 0;
}

string* cell_str::show()
{
    return str;
}

cell_str* cell_str::next()
{
    return my_next;
}

void cell_str::set_next(cell_str *next)
{
    my_next = next;
}

void cell_str::set_my_data(string *data)
{
    str = data;
}

cell_str * cell_str::add(string *data)
{
    my_next = new cell_str(data);
    return my_next;
}

cell_str* cell_str::del()
{
    return my_next;
}
