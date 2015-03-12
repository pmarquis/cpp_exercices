#include "TestWordCombinations.h"
#include <iostream>
#include <cassert>
#include "WordCombinations.h"
    
using namespace std;

/**
*    Test WordCombinations with 1 character
**/
void TestWordCombinations::Test1()
{
    string input("a");
    list<string> outputs;
    outputs.push_back("a");
    outputs.push_back("aa");
    outputs.push_back("aaa");

    WordCombinations wc(input);

    list<string>::iterator itOutput = outputs.begin();
    list<string>::iterator itOutputEnd     = outputs.end();
    while(itOutput != itOutputEnd)
    {
        assert(wc.Next() == *itOutput);
        itOutput++;
    }
}
    
/**
*    Test WordCombinations with 2 characters
**/
void TestWordCombinations::Test2()
{
    string input("ab");
    list<string> outputs;
    outputs.push_back("a");
    outputs.push_back("b");
    outputs.push_back("aa");
    outputs.push_back("ab");
    outputs.push_back("ba");
    outputs.push_back("bb");
    outputs.push_back("aaa");

    WordCombinations wc(input);

    list<string>::iterator itOutput = outputs.begin();
    list<string>::iterator itOutputEnd     = outputs.end();
    while(itOutput != itOutputEnd)
    {
        assert(wc.Next() == *itOutput);
        itOutput++;
    }
}
    
/**
*    Test WordCombinations with capital letters
**/
void TestWordCombinations::Test3()
{
    string input("AB");
    list<string> outputs;
    outputs.push_back("a");
    outputs.push_back("b");
    outputs.push_back("aa");
    outputs.push_back("ab");
    outputs.push_back("ba");
    outputs.push_back("bb");
    outputs.push_back("aaa");

    WordCombinations wc(input);

    list<string>::iterator itOutput = outputs.begin();
    list<string>::iterator itOutputEnd     = outputs.end();
    while(itOutput != itOutputEnd)
    {
        assert(wc.Next() == *itOutput);
        itOutput++;
    }
}
    
/**
*    Test WordCombinations with empty string
**/
void TestWordCombinations::Test4()
{
    string input("");
    string error("The input does not contain any letter");
    try
    {
        WordCombinations wc(input);
    }
    catch(const std::invalid_argument& ia)
    {
        assert(ia.what() == error);
    }
}
    
/**
*    Test WordCombinations with a string without letters
**/
void TestWordCombinations::Test5()
{
    string input("&(-'(-324535");
    string error("The input does not contain any letter");
    try
    {
        WordCombinations wc(input);
    }
    catch(const std::invalid_argument& ia)
    {
        assert(ia.what() == error);
    }
}


void TestWordCombinations::TestAll()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    cout << "Tests succeed!" 
         << endl;
}