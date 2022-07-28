#include "tritSet.h"

TritSet::TritSet(int size){
    capacity = size;
    int memorySize = capacity * 2 / 8 / sizeof(int) + ((size * 2 % (8 * sizeof(int)) == 0) ? 0 : 1);
    set = new int[memorySize];
    for(int i = 0; i < memorySize; ++i){
        set[i] = 0;
    }
    countTrits = 0;
}

TritSet operator|(TritSet ts1, TritSet ts2){
    TritSet tmp(((ts1.getCapacity() > ts2.getCapacity()) ? ts1.getCapacity() : ts2.getCapacity()));
    for(int i = 0; i < tmp.getCapacity(); ++i){
        tmp[i] = ts1[i] | ts2[i];
    }
    tmp.countTrits = (ts1.getCapacity() > ts2.getCapacity()) ? ts1.countTrits : ts2.countTrits;
    return tmp;
}

TritSet operator&(TritSet ts1, TritSet ts2){
    TritSet tmp((ts1.getCapacity() > ts2.getCapacity()) ? ts1.getCapacity() : ts2.getCapacity());
    for(int i = 0; i < tmp.getCapacity(); ++i){
        tmp[i] = ts1[i] & ts2[i];
    }
    tmp.countTrits = (ts1.getCapacity() > ts2.getCapacity()) ? ts1.countTrits : ts2.countTrits;
    return tmp;
}

TritSet operator~(TritSet ts){
    TritSet tmp(ts.getCapacity());
    for(int i = 0; i < tmp.getCapacity(); ++i){
        tmp[i] = ~ts[i];
    }
    tmp.countTrits = ts.countTrits;
    return tmp;
}

int TritSet::getCapacity(){
    return capacity;
}

void TritSet::expand(int index){
    int newCapacity = index;
    int *newSet = new int[index * 2 / 8 / sizeof(int) + ((index * 2 % (8 * sizeof(int)) == 0) ? 0 : 1)];
    for(int i = 0; i < capacity; ++i){
        newSet[i] = set[i];
    }
    delete []set;
    set = newSet;
    capacity = newCapacity;
}

ProxyTrit TritSet::operator[](int index){
    if(index >= capacity)
        expand(index);
    ProxyTrit tmp(this, index);
    return tmp;
}

Trit TritSet::operator[](int index) const{
    int tmp = this->set[index / 16];
    tmp = (tmp << index % 16) | 3;
    if(tmp == 1)
        return FALSE;
    if(tmp == 3)
        return TRUE;
    return UNKNOWN;
}

int TritSet::getCountTrits(){
    return countTrits;
}

void TritSet::shrink() {
    if(countTrits == 0){
        delete []set;
        return;
    }
    int memorySize = countTrits * 2 / 8 / sizeof(int) + ((countTrits * 2 % (8 * sizeof(int)) == 0) ? 0 : 1);
    int *newSet = new int[memorySize];
    for(int i = 0; i < memorySize; ++i){
        newSet[i] = set[i];
    }
    delete []set;
    set = newSet;
    capacity = countTrits + (16 - countTrits % 16);
}

void TritSet::clear() {
    delete []set;
}

void TritSet::insertTrit(int index, Trit trit) {
    if(index + 1 > countTrits)
        countTrits = index + 1;

    int newTrit = 0;
    if(trit == TRUE)
        newTrit = 3;
    if(trit == FALSE)
        newTrit = 1;

    int *tsTrit = &set[index / 16];
    index %= 16;
    newTrit = newTrit << index * 2;
    *tsTrit = *tsTrit & (~(3 << index * 2));
    *tsTrit += newTrit;
}
