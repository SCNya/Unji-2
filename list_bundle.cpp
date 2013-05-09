#include "list_bundle.h"

List_bundle::List_bundle()
{
    temp_first = first = new_cell = new cell_bundle();
}

List_bundle::~List_bundle()
{
    delete first;
    new_cell = 0;
    first = 0;
    temp_first = 0;
}

void List_bundle::add(Bundle *data)
{
    if(new_cell->show() != 0)
        new_cell = new_cell->add(data);
    else
        new_cell->set_my_data(data);
}

bool List_bundle::show(Bundle **temp_bundle)
{
    if((temp_first != 0) && (temp_first->show() != 0))
        *temp_bundle = temp_first->show();
    else
        temp_first = 0;
    return temp_first;
}

void List_bundle::next()
{
    temp_first = temp_first->next();
}

void List_bundle::set_pointer_in_first()
{
    temp_first = first;
}

void List_bundle::show_all()
{
    temp_first->show_all();
    temp_first = temp_first->next();
    if(temp_first)
    show_all();
}
