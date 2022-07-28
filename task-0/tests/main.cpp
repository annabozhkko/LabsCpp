#include <gtest/gtest.h>

#include "fileReader.h"
#include "fileWriter.h"
#include "sorting.h"
#include "splitString.h"
#include "statistics.h"

TEST(TestReader, TestReader) {
    FileReader fileReader("in.txt");
    EXPECT_TRUE(fileReader.fileOpen());
}

TEST(TestSplit1, TestSplit){
    SplitString splitString;
    vector <string> v;
    v.push_back("Anna");
    v.push_back("Bozhko");
    EXPECT_EQ(v, splitString.split("Anna Bozhko"));
}

TEST(TestSplit2, TestSplit){
    SplitString splitString;
    vector <string> v;
    v.push_back("qwerty");
    v.push_back("ahahah");
    v.push_back("ANNA");
    v.push_back("qwerty");
    EXPECT_EQ(v, splitString.split("qwerty, ahahah. ANNA    qwerty"));
}

TEST(TestStatistics1, TestStatistics){
    Statistics statistics;
    statistics.statisticsWords("Anna");
    statistics.statisticsWords("Anna");
    statistics.statisticsWords("Bozhko");
    vector <pair<string, int> > v;
    v.push_back(make_pair("anna", 2));
    v.push_back(make_pair("bozhko", 1));
    EXPECT_EQ(v, statistics.getStatistics());
    EXPECT_EQ(statistics.getCountWords(), 3);
}

TEST(TestStatistics2, TestStatistics){
    Statistics statistics;
    statistics.statisticsWords("A");
    statistics.statisticsWords("a");
    statistics.statisticsWords("aaa");
    statistics.statisticsWords("Bozhko");
    statistics.statisticsWords("qwerty");
    vector <pair<string, int> > v;
    v.push_back(make_pair("a", 2));
    v.push_back(make_pair("aaa", 1));
    v.push_back(make_pair("bozhko", 1));
    v.push_back(make_pair("qwerty", 1));
    EXPECT_EQ(v, statistics.getStatistics());
    EXPECT_EQ(statistics.getCountWords(), 5);
}

TEST(TestSorting1, TestSorting){
    Sorting sorting;
    vector <pair<string, int> > v;
    v.push_back(make_pair("anna", 5));
    v.push_back(make_pair("bozhko", 3));
    v.push_back(make_pair("aaa", 8));
    sorting.sort(v);

    vector <pair<string, int> > v1;
    v1.push_back(make_pair("bozhko", 3));
    v1.push_back(make_pair("anna", 5));
    v1.push_back(make_pair("aaa", 8));

    EXPECT_EQ(v, v1);
}

TEST(TestSorting2, TestSorting){
    Sorting sorting;
    vector <pair<string, int> > v;
    v.push_back(make_pair("oop", 5));
    v.push_back(make_pair("task0", 5));
    v.push_back(make_pair("aaa", 8));
    v.push_back(make_pair("ahaha", 1));
    v.push_back(make_pair("qwerty", 2));
    sorting.sort(v);

    vector <pair<string, int> > v1;
    v1.push_back(make_pair("ahaha", 1));
    v1.push_back(make_pair("qwerty", 2));
    v1.push_back(make_pair("oop", 5));
    v1.push_back(make_pair("task0", 5));
    v1.push_back(make_pair("aaa", 8));

    EXPECT_EQ(v, v1);
}
