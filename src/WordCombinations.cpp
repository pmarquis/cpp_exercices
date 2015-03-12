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

	// Initialize the list which contain the next words to return
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
*	Function: Reload
*
*	Description: Add the next words with one letter more than the last reload
**/
void WordCombinations::Reload()
{
	string newWord;
	set<char>::iterator itDictionary;
	set<char>::iterator itDictionaryFirst = m_dictionary.begin(); // set as member
	set<char>::iterator itDictionaryEnd = m_dictionary.end(); // set as member
	list<string>::iterator it;

	for(it = m_list.begin(); it != m_itListEnd; ++it)
	{
		for(itDictionary = itDictionaryFirst; itDictionary != itDictionaryEnd; ++itDictionary)
		{
			newWord = *it;
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
*	Function: Next
*
*	Description: Return the next combination of words
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