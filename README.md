# SpellCheck
Used two different hashing techniques in order to achieve a spell check function for given files. 

In this specific program, two different hashing methods are utilized: chaining & quadratic. I placed all the words in the dictionary in a hash map, using an algorithm that is based on the individual characters of the word. One of the differences is when dealing with collisions. Chaining, which is an array that is filled with pointers, just adds the collision to the end of the pointer at the same spot on the array. For quadratic, the collision will find the next open position in the string array and it will do so quadratically.

Results: When running the program with a given Dictionary file and (test)file input the difference of the two ways of using hashing really showed

	Chaining: number of errors =  135, time = 0.214381
	Quadratic:  number of errors = 135 , time = 0.204047
  
 They both recorded a total number for 135 errors that are found in the given input file. The time it took them to run are fairly similar, however the quadratic method was able achieve the same task by .01 seconds. This shows that the quadratic hashing method is faster and therefore more efficient.
 

