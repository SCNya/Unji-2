#ifndef FILL_H
#define FILL_H
#include <sstream>
#include <mutex>
#include "list_str.h"
#include "list_bundle.h"

using namespace std;

class Fill
{
public:
    Fill(List_bundle *, string *, unsigned short const, unsigned long const, unsigned long&);
    ~Fill();
    void operator()();
private:
    bool finde_item(Bundle *);
    void write(Bundle *);
    void between();
    void clear(List_str **);
    unsigned long long parting(unsigned long long);
    unsigned long long coordinate(unsigned long long);
    const unsigned long long  size;
    unsigned long long part;
    unsigned short thrd, all_thrds, mass_size;
    unsigned long long* mass_between;
    List_bundle* final_list;
    string* str;
    mutex* mute;
};

#endif // FILL_H
