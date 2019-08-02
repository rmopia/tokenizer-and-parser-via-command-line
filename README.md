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
Next we create a driver program, called "prog2_2.cpp", to utilize the Tokenizer file. To connect this file to Part 1's file we must include it like:

                #include "prog2_1.hpp"

We include the header (.hpp) instead of the actual file (.cpp) so when we can run both files in the terminal there is no repeating methods, resulting in errors.
The program should take a command line argument and consider it to be a .txt file which will contain the lines of strings that will be read.

Include The assignment project number (X), part (Y), name and email in the format below and ensure it is the first thing outputted when ran.

                Assignment X-Y, <NAME>, <EMAIL>

This file will construct a Tokenizer object if a command line argument in the form a file is found. The command line
file should be read and then go under the Tokenize function. If a tokenizing error comes up from invalidity, ensure there is appropriate exception handling. After,
the tokens should be put through the GetTokens method and printed out, line by line, in a way where any white space separating the tokens from the same line are changed
to commas. 

> Before: pop 6
>>After: pop,6

Lastly, ensure the Tokenizer destructor destructs all structures at the end of the program.

Part 3
========
Next, we create the Parser file, called "prog2_3.cpp", with a separate header file including three public members (but not limited to):
* A constructor
* A destructor
* A boolean Parse method

The Parse function takes in a vector string argument and will return a true or false, dependent on the validity of the strings given.
Similar to the Tokenizer function, we'll be looking for the same specific keywords but in this case, we'll be finding out if the keywords have any trailing tokens when
deemed appropriate. For the keywords: 
> "push", "save" and "get"

there should be a second token that must be an integer. As for all the other keywords:
> "pop","add","skip","sub","mul","div","mod"

the only token present should be one of the keywords on that line. All other inputs are considered invalid.

