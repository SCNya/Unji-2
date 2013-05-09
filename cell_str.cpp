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
    delete my_next;
    my_next = 0;
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
    cell_str *cell = new cell_str(data);
    my_next = cell;
    return cell;
}

cell_str* cell_str::del()
{
    delete str;
    str = 0;
    return my_next;
}
