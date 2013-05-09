#include "list_str.h"

List_str::List_str()
{
    before_temp_first = temp_first = first = new_cell = new cell_str();
}

List_str::~List_str()
{
    delete first;
    new_cell = 0;
    first = 0;
    temp_first = 0;
    before_temp_first = 0;
}

void List_str::add(string *data)
{
    if(new_cell->show() != 0)
        new_cell = new_cell->add(data);

    else
        new_cell->set_my_data(data);
}

void List_str::del()
{
    if(temp_first == first)
        temp_first = first = first->del();
    else
    {
        temp_first = temp_first->del();
        before_temp_first->set_next(temp_first);
    }
}

bool List_str::show(string **str)
{
    if(temp_first != 0)
        *str = temp_first->show();
    return temp_first;
}

void List_str::next()
{
    before_temp_first = temp_first;
    temp_first = temp_first->next();
}

void List_str::set_pointer_in_first()
{
    temp_first = first;
}
