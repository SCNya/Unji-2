#ifndef CELL_BUNDLE_H
#define CELL_BUNDLE_H
#include "bundle.h"

class cell_bundle
{
public:
    cell_bundle();
    cell_bundle(Bundle*);
    ~cell_bundle();
    cell_bundle *add(Bundle *);
    cell_bundle *next();
    Bundle *get_my_data();
    Bundle *show();
    void show_all();
    void set_next(cell_bundle*);
    void set_my_data(Bundle*);

private:
    Bundle *my_data;
    cell_bundle *my_next;
};

#endif // CELL_BUNDLE_H
