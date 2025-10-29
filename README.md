[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
We expect a fully functioninig command line REPL application for an inventory querying system. Feel free to modify the skeleton code as you see fit.

### How to run the current skeleton code
`make` will compile and execute the skeleton code

Feel free to modify Makefile as you see fit.


For Missing Fields: 
I made a function within Inventory.h which checks the current line I'm parsing and checks if there are any double commas ",," like this and then shoves an "NA" in between them
It does nothing to the actual csv file. I hate csv's.

Testing:

I tested the Hashtable's functions by picking one standard case and then an edge case and using assertt to check if they meet their success condition since the functions in hashtable return a bool it;s easy using assert(whattever == true | false). Basically, I'm checking to see if 1, the function works, and 2 how it handles edge cases.