#include "WordCombinations.h"
#include <ctype.h>


using namespace std;

WordCombinations::WordCombinations(string& wordDictionary)
{
    // Initialize the dictionary
    for(char& c : wordDictionary) 
    {
        if(isalpha(c))
        {
            m_dictionary.insert(tolower(c));            
        }
    }

    if(m_dictionary.size() == 0)
    {
        throw std::invalid_argument("The input does not contain any letter");
    }

    // Initialize the list which contain the next words to return.
    // At the first loop on the Next() function, the words return
    // will be the letters of the dictionary.
    set<char>::iterator itDictionary = m_dictionary.begin();
    set<char>::iterator itDictionaryEnd = m_dictionary.end();
    while(itDictionary != itDictionaryEnd)
    {
        m_list.push_back(string(1, *itDictionary));
        ++itDictionary;
    }
    // Initialize iterators on the list
    m_itList = m_list.begin();
    m_itListEnd = m_list.end();
}

/**
*    Function: Reload
*
*    Description: Create a new list of word using the previous list and the dictionary.
*                  The new word are added in m_listTmp.
*                When it is complete, the m_list is swapped with m_listTmp.
*                 m_listTmp is cleared, ready to be used for the next time.
**/
void WordCombinations::Reload()
{
    string newWord;
    set<char>::iterator itDictionary;
    set<char>::iterator itDictionaryFirst = m_dictionary.begin();
    set<char>::iterator itDictionaryEnd = m_dictionary.end();
    list<string>::iterator itList;

    for(itList = m_list.begin(); itList != m_itListEnd; ++itList)
    {
        for(itDictionary = itDictionaryFirst; itDictionary != itDictionaryEnd; ++itDictionary)
        {
            newWord = *itList;
            newWord.push_back(*itDictionary);
            m_listTmp.push_back(newWord);
        }
    }
    m_list.clear();
    m_list = m_listTmp;
    m_listTmp.clear();
    m_itList = m_list.begin();
    m_itListEnd = m_list.end();
}

/**
*    Function: Next
*
*    Description: Return the next combination of words
**/
string WordCombinations::Next()
{
    if(m_itList == m_itListEnd)
    {
        Reload();
    }
    string word = *m_itList;
    m_itList++;
    return word;
}