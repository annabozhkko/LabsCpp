#include "tritSet.h"

using namespace std;

int main(){
    TritSet set1(1000);
    TritSet set2(1000);
    set1[0] = TRUE;
    set2[1] = TRUE;
    TritSet set3 = set1 & set2;
    set1.clear();
    set2.clear();
    set3.clear();
    return 0;
}
