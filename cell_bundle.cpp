#include "cell_bundle.h"

cell_bundle::cell_bundle():
    my_next(0),
    my_data(0)
{
}

cell_bundle::cell_bundle(Bundle *data):
    my_data(data),
    my_next(0)
{
}


cell_bundle::~cell_bundle()
{
    delete my_data;
    my_data = 0;
    delete my_next;
    my_next = 0;

}

Bundle * cell_bundle::show()
{
    return my_data;
}

cell_bundle * cell_bundle::next()
{
    return my_next;
}

void cell_bundle::set_next(cell_bundle *next)
{
    my_next = next;
}

void cell_bundle::set_my_data(Bundle *data)
{
    my_data = data;
}

Bundle * cell_bundle::get_my_data()
{
    return my_data;
}

cell_bundle * cell_bundle::add(Bundle *data)
{
    cell_bundle*  cell = new cell_bundle(data);
    my_next = cell;
    return cell;
}

void cell_bundle::show_all()
{
    cout << "\n" << my_data->word << "   " << my_data->quantity << endl;
}
