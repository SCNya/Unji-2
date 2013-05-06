#ifndef CELL_STR_H
#define CELL_STR_H
#include <iostream>

using namespace std;

class cell_str
{
public:
    cell_str();
    cell_str(string*);
    ~cell_str();
    cell_str* add(string*);
    cell_str* del();
    cell_str* next();
    cell_str* get_next();
    string* get_my_data();
    string* show();
    void set_next(cell_str*);
    void set_my_data(string*);

private:
    string* str;
    cell_str* my_next;
};

#endif // CELL_STR_H
