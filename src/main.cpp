#include "WordCombinations.h"
#include <iostream>


int main()
{
	std::string word;
	std::cout << "Enter a word:" << std::endl;
	std::cin >> word;
	WordCombinations wc(word);
	int counter = 20;
	while (counter > 0)
	{
		std::cout << wc.Next() 
				  << std::endl;
		counter--;
	}
	return 0;
}