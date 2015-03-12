#ifndef __WORD_COMBINATIONS_H_INCLUDED__
#define __WORD_COMBINATIONS_H_INCLUDED__

#include <iostream>
#include <set>
#include <queue>
#include <list>
#include <stdexcept>


/**
*	Class: WordCombinations
*  
*   Description: Return all the combinations of words from a dictionary given.
* 	   			 Each time the function Next() is called, that return a new word from the list m_list.
*				 When the last element of the list have been given, the function Reload() add all the  
*				 elements with one letter more in the list.
*				 When the function Next() return a n letters word, the list contains n^n elements.
*                That limit the words in memory.
*
*   Input: Dictionary as a string.
*
*   Output: Next combination of word using the Next() function.
**/
class WordCombinations
{
public:
	WordCombinations(std::string& wordDictionary);
	WordCombinations()
	{
		// a parameter wordDictionary is required else an exception is thrown
		throw std::invalid_argument("Default constructor is forbidden");
	}
	virtual ~WordCombinations(){}
	std::string Next();

private:
	void Reload();

	std::set<char> m_dictionary;
	std::list<std::string> m_list;
	std::list<std::string> m_listTmp;
	std::list<std::string>::iterator m_itList;
	std::list<std::string>::iterator m_itListEnd;

};

#endif // __WORD_COMBINATIONS_H_INCLUDED__ 