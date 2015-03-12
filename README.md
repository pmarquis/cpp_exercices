Word Combinations
=================
*   Description: 

	Return all the combinations of words from a dictionary given.
	Each time the function Next() is called, that return a new word from the list m_list.
	When the last element of the list have been given, the function Reload() add all the  
	elements with one letter more in the list.
	When the function Next() return a n letters word, the list contains n^n elements.
	That limit the words in memory.
 
*   Input: Dictionary as a string.

*   Output: Next combination of word using the Next() function.Description: return all the combinations of words from a dictionary given.
     
*   Exemple: 

    Input: "abc" 
    
    Output: a 
            b
            c
            aa
            ab
            ac
            ba
            bb
            bc
            ca
            cb
            cc
            aaa
            aab
            … forever


Build
-----
~~~
make all
~~~

Run
---
~~~
./main
~~~
Test
----
~~~
./test
~~~