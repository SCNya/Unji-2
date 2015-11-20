#include "fill.h"

Fill::Fill(List_bundle * lst, string *data, unsigned short const hard_th, unsigned long const sz, unsigned long& min_size):
    final_list(lst),
    thrd(0),
    size(sz),
    str(data),
    mass_size((2*hard_th+1)-hard_th),
    all_thrds(hard_th)
{
    mute = new mutex;
    if((size < min_size) || (hard_th <= 1))
    {
        mass_between = new unsigned long long[2];
        mass_between[0] = 0;
        mass_between[1] = size;
    }
    else
    {
        mass_between = new unsigned long long[mass_size];
        part = parting(size);
        between();
    }
}

Fill::~Fill()
{
    delete [] mass_between;
    mass_between = 0;
    delete mute;
    mute = 0;
}

void Fill::operator()()
{
    mute->lock();
    thrd++;
    mute->unlock();
    stringstream ss;
    string* data;
    List_str *mass = new List_str;
    unsigned long long begin = mass_between[thrd-1];
    unsigned long long end = mass_between[thrd];

    do
    {
        if (((((*str) [begin]<' ') || ((*str) [begin]>='&'))) && ((((*str) [begin]<='&') || ((*str) [begin]>'/'))) && ((*str) [begin]!='\n') && ((*str) [begin]!=0) && (((*str) [begin]<'[') || ((*str) [begin]>'^')) && ((*str) [begin]!='~') && (((*str) [begin]<':') || ((*str) [begin]>'?')) && (((*str) [begin]<'{') || ((*str) [begin]>'~')))
        {
            ss << (*str) [begin];
            if ((((*str) [(begin+1)]>'&') && ((*str) [(begin+1)]<='/')) || (((*str) [(begin+1)]>=' ') && ((*str) [(begin+1)]<'&')) || ((*str) [(begin+1)]==0) || (((*str) [(begin+1)]>='[') && ((*str) [(begin+1)]<='^')) || ((*str) [(begin+1)]=='~') || (((*str) [(begin+1)]>=':') && ((*str) [(begin+1)]<='?')) || (((*str) [(begin+1)]>='{') && ((*str) [(begin+1)]<='~')))
            {
                data = new string(ss.str());
                mass->add(data);
                ss.str("");
                ss.clear();
            }
        }
        begin++;
    }
    while (begin < end);
    clear(&mass);
}

void Fill::between()
{
    unsigned short end = mass_size -1;
    mass_between[0] = 0;
    mass_between[end] = size;
    for(unsigned short i(1); i < end; i++)
    {
        mass_between[i] = coordinate(mass_between[i-1] + part);
    }
}

void Fill::write(Bundle  *pkg)
{
    mute->lock();
    if(!finde_item(pkg))
        final_list->add(pkg);
    mute->unlock();
}

unsigned long long Fill::parting(unsigned long long temp_size)
{

    if(temp_size % all_thrds == 0)
        temp_size = temp_size / all_thrds;
    else
    {
        temp_size--;
        temp_size = parting(temp_size);
    }

    return temp_size;
}

unsigned long long Fill::coordinate(unsigned long long i)
{
    if (((((*str) [i]<' ') || ((*str) [i]>='&'))) && ((((*str) [i]<='&') || ((*str) [i]>'/'))) && ((*str) [i]!='\n') && ((*str) [i]!=0) && (((*str) [i]<'[') || ((*str) [i]>'^')) && ((*str) [i]!='~') && (((*str) [i]<':') || ((*str) [i]>'?')) && (((*str) [i]<'{') || ((*str) [i]>'~')))
    {
        i++;
        i = coordinate(i);
    }
    return i;
}

void Fill::clear(List_str **mass)
{
    Bundle *pkg;
    string *sample(0), *word(0);

    while((*mass)->show(&sample))
    {
        pkg = new Bundle();
        pkg->word = *sample;
        pkg->quantity = 1;
        (*mass)->del();
        while((*mass)->show(&word))
        {
            if(pkg->word == *(word))
            {
                pkg->quantity++;
                (*mass)->del();
            }
            else
                (*mass)->next();
        }
        (*mass)->set_pointer_in_first();
        write(pkg);
    }
    delete *mass;
    *mass = 0;
}

bool Fill::finde_item(Bundle *pkg)
{
    Bundle *temp_bundle;
    final_list->set_pointer_in_first();
    while(final_list->show(&temp_bundle))
    {
        if(pkg->word == temp_bundle->word)
        {
            temp_bundle->quantity += pkg->quantity;
            delete pkg;
            pkg = 0;
            return true;
        }
        final_list->next();
    }
    return false;
}
