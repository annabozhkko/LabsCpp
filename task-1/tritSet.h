#include <iostream>

#pragma once

#include "proxyTrit.h"
#include "trit.h"

class ProxyTrit;

class TritSet{
public:
    TritSet(int size);
    int getCapacity();
    int getCountTrits();
    int *set;

    Trit operator[](int index) const;
    ProxyTrit operator[](int index);

    void clear();
    void shrink();

    friend TritSet operator|(TritSet ts1, TritSet ts2);
    friend TritSet operator&(TritSet ts1, TritSet ts2);
    friend TritSet operator~(TritSet ts);

    void insertTrit(int index, Trit trit);

private:
    int capacity;
    int countTrits;
    void expand(int index);
};
