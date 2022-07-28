#include "trit.h"

Trit operator|(Trit t1, Trit t2){
    if(t1 == TRUE || t2 == TRUE)
        return TRUE;
    if(t1 == FALSE && t2 == FALSE)
        return FALSE;
    return UNKNOWN;
}

Trit operator&(Trit t1, Trit t2){
    if(t1 == FALSE || t2 == FALSE)
        return FALSE;
    if(t1 == TRUE && t2 == TRUE)
        return TRUE;
    return UNKNOWN;
}

Trit operator~(Trit t){
    if(t == TRUE)
        return FALSE;
    if(t == FALSE)
        return TRUE;
    return UNKNOWN;
}
