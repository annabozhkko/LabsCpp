#include "proxyTrit.h"

using namespace std;

void ProxyTrit::operator=(Trit trit){
    ts->insertTrit(index, trit);
}

Trit ProxyTrit::getValue() {
    int *tsTrit = &ts->set[index / 16];
    int value = (*tsTrit >> (index % 16 * 2)) & 3;
    if(value == 1)
        return FALSE;
    if(value == 3)
        return TRUE;
    return UNKNOWN;
}
