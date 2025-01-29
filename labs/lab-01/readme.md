# Lab 1 (01/28/2025)
The goal of this lab is to get you familiar with the tools we will be using in this course, and to review some basic C++ concepts.  You will practice working with pointers, dynamic memory allocation, and C-style arrays.  Make sure to follow the instructions carefully and ask for help if you get stuck.

> [!WARNING]
> For this lab in particular, you are NOT ALLOWED to use LLMs (large language models) such as Copilot, ChatGPT, etc.  You are allowed to use the internet to look up syntax and other basic information, but you should not automatically generate code using LLMs.  If you have Copilot on your environment, please disable it for the duration of the lab.  Focus on understanding the concepts and writing the code yourself.

## Setting up your development environment

Labs and homework assignments require you to write code in C++.  You can use any IDE or text editor you like, however, for autograded assignments, we expect your code to compile and run on *Linux* machines using `g++`.  We recommend using Visual Studio Code (VSCode) with the C/C++ extension installed.  If you don't already have VSCode installed, you can download it [here](https://code.visualstudio.com/).  You can install the C/C++ extension by following the instructions [here](https://code.visualstudio.com/docs/languages/cpp).

## Pointer declaration and basic operations

Complete the following source file to practice pointer declaration and basic operations.  

```cpp
int main() {
    // TODOs

    // create an integer variable and a pointer to it

    // create a double variable and a pointer to it
    
    // for both variables, print their memory addresses 
    // using hexadecimal values, and their current values
    // (no need to initialize the variables)

    // modify the values of the variables using 
    // the pointers
}
```

Compile and run your code using `g++` on the command line.  Verify that it works as expected.  You can also trace your code using [pythontutor.com](http://pythontutor.com/cpp.html#mode=edit) to improve your understanding of pointers.

> [!IMPORTANT]
> After finishing this exercise, copy and paste your code into a file named `solutions-lab.txt` (to be submitted)

## Pointers to variables of different types

Complete the following source file to practice pointers to variables of different types.

```cpp
int main() {
    // TODOs

    // create an array of characters and initialize it 
    // with "hello"

    // create an integer array and initialize it 
    // with {1, 2, 3, 4, 5}

    // declare/create pointers to both arrays

    // traverse the character array using the respective 
    // pointer (ptr++) and print each character and its 
    // corresponding memory address (in hexadecimal)

    // traverse the integer array using the respective
    // pointer (ptr++) and print each integer and its
    // corresponding memory address (in hexadecimal)
}
```

Compile and run your code using `g++` on the command line.  Verify that it works as expected.  You can also trace your code using [pythontutor.com](http://pythontutor.com/cpp.html#mode=edit) to improve your understanding of pointers.

> [!IMPORTANT]
> Append your code to the `solutions-lab.txt` file, and include a written explanation on the memory addresses you observe for both arrays.

## Reversing an array using pointers

Complete the following source file to practice reversing an array using pointers.

```cpp
#include <iostream>

void reverse(int *arr, int size) {
    // TODOs

    // use two pointers to reverse the array (start and end)
    // one pointer should point to the first element
    // and the other to the last element

    // create a loop that swaps the elements pointed to by
    // the two pointers, and then moves the pointers
    // towards the center of the array, until they meet
    // use pointer arithmetic to move the pointers (ptr++ and ptr--)
}

int main() {
    int single[] = {1};
    int odd_len[] = {1, 2, 3, 4, 5};
    int even_len[] = {1, 2, 3, 4, 5, 6};

    reverse(single, 1);
    reverse(odd_len, 5);
    reverse(even_len, 6);
}
```

Compile and run your code using `g++` on the command line.  You can also trace your code using [pythontutor.com](http://pythontutor.com/cpp.html#mode=edit) to verify that it works as expected.

> [!IMPORTANT]
> Append your code to the `solutions-lab.txt` file

## Programming exercise with pointers

*Dynamic memory allocation* is a powerful feature in C++ that allows you to allocate memory at execution time.  This is useful, for example,  when you don't know the size of the data you need to store until the program is running.  A critical aspect of memory management in C++ revolves around manual memory deallocation. When a programmer allocates memory using the `new` operator, they assume direct responsibility for subsequently freeing that memory through the corresponding `delete` operator. The significance of this responsibility cannot be overstated. Failure to properly deallocate memory leads to *memory leaks*, where allocated memory remains unavailable for reuse by the program, potentially causing system performance degradation over time.

In C++, you can use the `new` operator to allocate memory for a single variable or an array of variables, and you can use the `delete` operator to free the memory when you are done with it.  The syntax is as follows:

```cpp
int *ptr = new int; // allocate memory for a single integer
int *arr = new int[10]; // allocate memory for an array of 10 integers

delete ptr; // free memory for a single integer
delete [] arr; // free memory for an array of integers
```

*Double pointers* are pointers that point to other pointers.  They are useful when you need to store the address of a pointer, or when you need to create an array of pointers.  They follow the same idea as regular pointers, i.e., they are pointer variables that store memory addresses, in this case, the memory addresses of other pointers.  The syntax is as follows:

```cpp
int value = 10; 
int *q; // declare a regular pointer to an integer
int **ptr; // declare a double pointer to an integer pointer

q = &value; // assign the address of value to q
ptr = &q; // assign the address of q to ptr
```

Now, consider the following program that uses pointers to manipulate an array of integers.  Follow the instructions in the comments to complete the program.

```cpp
void shuffler(int size) {
    // dynamically allocate memory for an array of integers
    int *numbers = new int[size];

    // create an array of pointers to integers
    int **pointers = new int *[size];

    // initialize the array of integers with values from 1 to size
    // and the array of pointers with the addresses of the integers
    for (int i = 0; i < size; i++) {
        numbers[i] = i + 1;     
        pointers[i] = &numbers[i];
    }

    // TODOs:
    // 1. randomly shuffle the array of pointers, the array of numbers
    //    should remain unchanged. you can use the std::shuffle function
    //    from the <algorithm> header
    // 2. print both arrays and inspect the results, memory addresses
    //    should be printed in hexadecimal format
    // 3. follow the pointers to print the values in shuffled order
    
    // clean up memory
    delete [] numbers;
    delete [] pointers;
}

int main() {
    shuffler(3);
    shuffler(5);
    shuffler(10);
}
```

Compile and run your code using `g++` on the command line.  Verify that it works as expected.  You can also trace your code using [pythontutor.com](http://pythontutor.com/cpp.html#mode=edit) to improve your understanding of pointers.

> [!IMPORTANT]
> Append your code to the `solutions-lab.txt` file

## Submission

After you have completed all the exercises, submit your `solutions-lab.txt` file to [Gradescope](https://gradescope.com).  Your code should be well-formatted and easy to read.  Make sure to test your code thoroughly before submitting it.  You must be present in the lab to receive the attendance credit.  No remote submissions will be accepted.  If you have any questions, please ask the instructor or the TA for help.
