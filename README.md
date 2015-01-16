Dictionary-HT
=============

This program uses a HashTable class to work with a dictionary program. 

The Dictionary program reads in a command line argument that corresponds to an English-French dictionary file. 

The dictionary file is formatted such that the first word is the English word, and the rest is the French definition. 

A single tab (“\t”) separates the word and the definition.

1. The program opens the file and reads in each line, separating the word from the definition. 
2. Each word/definition pair is used to construct a DictionaryEntry object, which is  hashed into a hashtable.
3. If the English word is repeated, only the first instance is used and all others are ignored. 
4. To retrieve a DictionaryEntry object from the hash table, a “retrieve” method in your HashTable class that returns a reference to a HashedObj. 
5. Once the hash table is complete, the program takes in a single word (no checks required) and output the same word and the definition (both retrieved from the hash table) on two consecutive lines. 
6. If the user enters the word “random”, the program outputs a random word and definition (again, on two consecutive lines). 
7. If the word is not found in the dictionary, two blank consecutive lines are outputted. This process is be looped infinitely.
