# Instructions  

  ** Input Validation **

  Program Information
When the user is expected to enter a value, that value  often has constraints based on the problem we are solving. 

** Examples: **
* A time must be non-negative
* A correlation coefficient must lie between -1 and +1, 
* A menu choice must be one of a particular set of values (menu-dependent). 
	
Such input validation is easily done with a while loop:
```
    prompt & read
    while (!valid)
    {
        error message
        prompt & read
    }
```
This can become tedious if you have to redesign it or alter the code EVERY time you must use it. 
To make things easier, we can simply place this loop in a function for easy re-use.

Upon examining several specific instances, we see  the main things that change are:

1. variable you are entering, 
2. the bounds/values to be used, 
3. The prompts/messages printed to the user. 
	 
   
All of these can easily be parameterized using a function. The bounds could be passed as arguments. 
So could the prompts and messages. The variable entered would simply be assigned upon return from the function (the return value.)

You decide to write some generalized input-validation functions. 
To make them  re-usable, place them in a library called input_prot(for input protection). 

You  need to be able to handle the following situations:

1. Entry bounded at both ends of a range (i.e. grades between 0..100)
2. Entry bounded at the lower end of a range (i.e. time greater than 0)
3. Entry bounded at the upper end of a range (rare, but it does happen)
4. Entry limited to those elements in a particular list of values (i.e. menu choices)

By overloading your functions for use with ALL of the major data types (double, long, and char) you'll rarely have to re-write that validation loop again! 
(Skip float and short since they are subsets of double and long. Skip bool as it can't be directly entered.)

As an example you might call the char one with a list of "YyNn" and store whether the upper-case of the result was equal to 'Y'or not, right? That is, you'd code something like:
```
  bool ans;

    ans = toupper(input_protect("\nWould you like to continue?  ",
                                "Please enter Yes or No only!\a\n",
                                "YyNn"))
            == 'Y';
```			
			
in your main program for a bool entry.)

Of course, to make sure all your validation functions work properly, you'll have to write a driver for this library. (A driver is basically a test application that tests ALLthe functions in the library — at least once. See the library notes for more tips.)			