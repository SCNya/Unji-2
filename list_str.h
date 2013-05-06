#ifndef LIST_STR_H
#define LIST_STR_H
#include "cell_str.h"

class List_str
{
public:
    List_str();
    ~List_str();
    void add(string*);
    void del();
    bool show(string**);
    void next();
    void set_pointer_in_first();
private:
    cell_str* new_cell, *first, *temp_first, *before_temp_first;
};

#endif // LIST_H
