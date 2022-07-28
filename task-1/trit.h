#pragma once

enum Trit{
    FALSE = -1, /// 10
    UNKNOWN = 0,  /// 00
    TRUE = 1, /// 11
};

Trit operator|(Trit t1, Trit t2);
Trit operator&(Trit t1, Trit t2);
Trit operator~(Trit t);
