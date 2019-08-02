# tokenizer-and-parser-via-command-line
# Robert Mopia
# rmopia7587@sdsu.edu

Synopsis
========
The purpose of this project is to learn how to tokenize and parse a file from the command line in the C++ language.

Part 1
========
Here we start by creating a Tokenizer file, called "prog2_1.cpp" with a seperate header file that includes four public members (but not limited to) :
* A constructor
* A destructor
* A Tokenize method
* A GetTokens method

The constructor is used to create a Tokenizer object and allocate memory.

The destructor is used to delete objects that we're created and deallocate any allocated memory to prevent memory leaks.

The Tokenize method will be a void function that takes in string arguments. It will check the validity of strings from the file by checking if the specific tokens are written:
> push, pop, add, sub, mul, div, mod, skip, save

Also if there is another string trailing any of the tokens listed above, it must be an integer. Anything else is considered invalid. If an invalid string is found ensure
there is exception handling that specifically prints out the message shown:

                Error on line <number>: Unexpected token: <value> 

If the file passes the Tokenize function, the contents should be stored in an internal structure, preferably a queue.

The GetTokens function will return a vector of strings and take no arguments. The function should take from the queue structure where all your valid tokens exist, and
place them into the vector. If there are no tokens found ensure there is exception handling that prints out the message "No tokens".

Part 2
========
