# DrSeuss

Objective: Creating new Dr. Seuss books using HashMap.

Steps:

This program reads in a text file of Dr. Seuss stories. Each word read in will
be a key, and the values associated with each key will be an array of Strings, or the set of words that follow a word.
So, for instance, if you have the word “I” as your key, the array of values might be a list that would look like
{“do”,”see”,”have”,”am”,”do”,”need”}, etc. The value that is associated with the key “I” is every word in the Dr.
Seuss text that follows the word “I”.

There are two seperate hash functions that take a key  and uses a hash function to change that key to a particular index.
There are also functions that handles collisions if the original hash function returns an index that is already occupied by a node with a key that isn’t 
the one you are inserting.

The writeFIle method will take a key word, choose a random word from the array of values that follows that word, print that word to the file, and
make that word be the new keyword.

