#include <iostream>

#pragma once

#include "tritSet.h"
#include "trit.h"

class TritSet;

class ProxyTrit{
public:
    ProxyTrit(TritSet *set, int idx){
        ts = set;
        index = idx;
    };
    void operator=(Trit a);
    operator Trit(){
        return getValue();
    }

private:
    int index;
    TritSet *ts;
    Trit getValue();
};
