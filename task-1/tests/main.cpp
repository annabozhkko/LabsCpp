#include <gtest/gtest.h>
#include <iostream>

#include "tritSet.h"

TEST(TritSet, Tritset){
    TritSet set(1000);
    EXPECT_EQ(set.getCapacity(), 1000);
    set.clear();
}

TEST(Trit, Trit){
    Trit a = TRUE;
    TritSet set(1000);
    set[0] = a;
    EXPECT_EQ(set.set[0], 3);
    set[2] = a;
    EXPECT_EQ(set.set[0], 51);
    set[17] = a;
    EXPECT_EQ(set.set[1], 12);
    EXPECT_EQ(set.getCountTrits(), 18);
    set.clear();
}

TEST(TritSet2, TritSet){
    TritSet set(1000);
    set[0] = UNKNOWN;
    EXPECT_EQ(set.set[0], 0);
    set[1] = FALSE;
    EXPECT_EQ(set.set[0], 4);
    set[16] = TRUE;
    EXPECT_EQ(set.set[1], 3);
    EXPECT_EQ(set.getCountTrits(), 17);
    set.clear();
}

TEST(TritSet3, TritSet){
    TritSet set(1000);
    set[0] = TRUE;
    Trit a;
    a = set[0];
    EXPECT_EQ(a, TRUE);
    a = set[2];
    EXPECT_EQ(a, UNKNOWN);
    set.clear();
}

TEST(TritSet4, TritSet){
    TritSet set(1000);
    set[1] = FALSE;
    Trit a;
    a = set[1];
    EXPECT_EQ(a, FALSE);
    a = set[2];
    EXPECT_EQ(a, UNKNOWN);
    set.clear();
}

TEST(ConjunctionSet, TritSet){
    TritSet set1(1000);
    TritSet set2(1000);
    set1[0] = TRUE;
    set2[1] = TRUE;
    TritSet set3 = set1 & set2;
    EXPECT_EQ(set3.set[0], 0);
    set1[1] = FALSE;
    set3 = set1 & set2;
    EXPECT_EQ(set3.set[0], 4);
    set1.clear();
    set2.clear();
    set3.clear();
}

TEST(DisjunctionSet, TritSet){
    TritSet set1(1000);
    TritSet set2(1000);
    set1[0] = TRUE;
    set2[0] = FALSE;
    TritSet set3 = set1 | set2;
    EXPECT_EQ(set3.set[0], 3);
    set1[1] = FALSE;
    set3 = set1 | set2;
    EXPECT_EQ(set3.set[0], 3);
    set1.clear();
    set2.clear();
    set3.clear();
}

TEST(InversionSet, TritSet){
    TritSet set(1000);
    set[0] = TRUE;
    TritSet set1 = ~set;
    EXPECT_EQ(set1.set[0], 1);
    set[1] = FALSE;
    set1 = ~set;
    EXPECT_EQ(set1.set[0], 13);
    set.clear();
    set1.clear();
}

TEST(Conjunction, TritSet){
    Trit a, b;
    a = TRUE;
    b = FALSE;
    Trit c = a & b;
    EXPECT_EQ(c, FALSE);
    b = UNKNOWN;
    c = a & b;
    EXPECT_EQ(c, UNKNOWN);
}

TEST(Disjunction, TritSet){
    Trit a, b;
    a = TRUE;
    b = FALSE;
    Trit c = a | b;
    EXPECT_EQ(c, TRUE);
    b = UNKNOWN;
    c = a | b;
    EXPECT_EQ(c, TRUE);
}

TEST(Inversion, TritSet){
    Trit a;
    a = FALSE;
    Trit b = ~a;
    EXPECT_EQ(b, TRUE);
    a = UNKNOWN;
    b = ~a;
    EXPECT_EQ(b, UNKNOWN);
}

TEST(ConjunctionTrit, TritSet){
    TritSet set(1000);
    set[0] = TRUE;
    set[1] = FALSE;
    Trit a = set[0] & set[1];
    EXPECT_EQ(a, FALSE);
    set.clear();
}

TEST(DisjunctionTrit, TritSet){
    TritSet set1(1000);
    TritSet set2(1000);
    set1[0] = TRUE;
    set2[1] = FALSE;
    Trit a = set1[0] | set2[1];
    EXPECT_EQ(a, TRUE);
    set1.clear();
    set2.clear();
}

TEST(Shrink1, Shrink){
    TritSet set(1000);
    set[0] = TRUE;
    set[5] = FALSE;
    set.shrink();
    EXPECT_EQ(set.getCapacity(), 16);
    EXPECT_EQ(set.getCountTrits(), 6);
    set.clear();
}

TEST(Shrink2, Shrink){
    TritSet set(1000);
    set[35] = TRUE;
    set[70] = UNKNOWN;
    set.shrink();
    EXPECT_EQ(set.getCapacity(), 80);
    set.clear();
}
