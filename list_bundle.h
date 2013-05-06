#ifndef LIST_BUNDLE_H
#define LIST_BUNDLE_H
#include "cell_bundle.h"

class List_bundle
{
public:
    List_bundle();
    ~List_bundle();
    void add(Bundle *);
    bool show(Bundle **);
    void show_all();
    void next();
    void set_pointer_in_first();
private:
    cell_bundle* new_cell, *first, *temp_first;
};

#endif // LIST_H
