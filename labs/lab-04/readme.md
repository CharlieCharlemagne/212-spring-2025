# Lab 4 (02/25/2025)

The goal of this lab is to implement a class modeling a Stack data 
structure and use it to evaluate *fully parenthesized arithmetic expressions*.
This lab will help you practice writing code in C++ with a focus on classes,
references, and templates. While you can collaborate with peers, 
each student is expected to make an individual submission.

> [!WARNING]
> For this lab in particular, you are NOT ALLOWED to use LLMs (large language models)
> such as Copilot, ChatGPT, etc.  You are allowed to use the internet to look
> up syntax and other basic information, but you should not automatically
> generate code using LLMs.  If you have Copilot on your environment,
> please disable it for the duration of the lab.  Focus on understanding
> the concepts and writing the code yourself.

## The Stack class

Due to time constraints, you will implement a stack class backed by
a fixed-size array (C-style), i.e., a stack with a fixed capacity
that does not grow or shrink.  

> [!IMPORTANT]
> The stack should be implemented using a template class, 
> allowing it to store elements of any data type.

We will be following a similar data structure as the one implemented
by the C++ Standard Library.  The stack class should have the following
public member functions:

- a `default constructor` that initializes the stack with a capacity of 50;
- a `parameterized constructor` that initializes the stack with a given capacity;
- a `destructor` that deallocates the memory used by the stack;

- a `push` member function that takes a reference to a constant element and
  adds it to the top of the stack: `void push (const T& val)`; this function
  should throw a `std::length_error` exception if the stack is full;
- a `pop` member function that removes the top element from the stack:
  `void pop()`;
- a `top` member function that returns a reference to the top element of 
  the stack: `const T& top() const`;
- a `size` member function that returns the number of elements in the stack:
  `size_t size() const`;
  - a `empty` member function that returns `true` if the stack is empty, and
  `false` otherwise: `bool empty() const`.

### Step 1: Implement the Stack class

Implement two files, `stack.h` and `stack.cpp`, to define and implement the
`Stack` class.  The `Stack` class should be a template class, allowing it to
store elements of any data type.  The `stack.h` file should contain the class
definition, while the `stack.cpp` file should contain the implementation of
the class member functions.

> [!TIP]
> Unlike regular classes, template classes need their implementation to be
> visible to the compiler at the point of instantiation.  This means that
> the implementation of the template class should either be in the header
> file or included separately in the source file that uses the template class.
> In this lab, we implement the `Stack` class in a separate `stack.cpp` file,
> so we need to include the `stack.cpp` file into any source file that uses
> the `Stack` class. To prevent duplicated definitions, we should use the
> preprocessor directive `#ifndef` in `stach.h` to avoid multiple inclusions 
> of the same header file.

### Step 2: Test the Stack class

Create a `stack_tester.cpp` file to test the functionality of the `Stack` class.
The `stack_tester.cpp` file should include the `stack.h` header file and also
the `stack.cpp` file, due to the way we implemented the template class.
THe tester program should test the functionality of the `Stack` class as follows:

```cpp
#include "stack.h"
#include "stack.cpp"
#include <iostream>
#include <stdexcept>

int main() {
    Stack<int> s1(100);
    Stack<int> s2;

    for (int i = 0; i < 100 ; ++i) {
        s1.push(i);
    }
    for (int i = 0; i < 90 ; ++i) {
        s1.pop();
    }

    while (! s1.empty()) {
        std::cout << s1.top() << " ";
        s1.pop();
    }
    std::cout << std::endl;

    // this loop should break the program
    for (int i = 0; i < 100 ; ++i) {
        s2.push(i);
    }

    return 0;
}
```

After compiling your project with `g++ stack_tester.cpp -o stack_tester`,
run the program using `./stack_tester`.  The program should pring the numbers
`9 8 7 6 5 4 3 2 1 0` and then terminate with an error caused by the `std::length_error`
exception thrown when the stack is full.

After verifying that the program works as expected, now you can modify the
`stack_tester.cpp` file to handle the exception thrown when the stack is full.
Enclose the loop that fills the `s2` stack in a `try-catch` block to
handle the exception.  The `catch` block should print an error message and
continue with the program.

### Step 3: Evaluate arithmetic expressions

Now you will implement the two-stack algorithm shown in class to evaluate 
fully parenthesized arithmetic expressions.  The algorithm uses two stacks,
one for operands and one for operators.  Make sure to create a stack of integers
for the operands and a stack of characters for the operators.

Your program should read an input expression as a command line argument,
evaluate it using the two-stack algorithm, and then print the result to the
console.  The expression should be fully parenthesized and contain only
white spaces, '(', ')', integer operands, and the operators `+`, `-`, `*`, and `/`.
All integer operands are single-digit positive numbers, and the '/' operator
performs integer division. For example, the expression `(1 + (2 * 3))` should 
evaluate to `7` and the expression `((1 + 2) / 2)` should evaluate to `1`.

The two-stack algorithm consumes the input expression from left to right.
For each character in the expression, the algorithm performs the following steps:

- if the character is a left parenthesis or a white space, ignore it;
- if the character is an operand, push it onto the operand stack;
- if the character is an operator, push it onto the operator stack;
- if the character is a right parenthesis, pop an operator from the operator stack,
  pop the required number of operands from the operand stack, evaluate the operation,
  and push the result back onto the operand stack.

After processing the entire expression, the result should be the only element
left on the operand stack.  You can assume all expressions are valid and fully
parenthesized, so your program does not need to check for errors.

Create a `expression_evaluator.cpp` file to implement the two-stack algorithm
and evaluate the input expression.  The program should read the input expression
from the command line and print the result to the console.  You can use the
`std::stoi` function to convert a string to an integer.

> [!TIP]
> In some terminals, you may need to enclose the expression in double
> quotes to prevent the shell from interpreting the parentheses as special
> characters.  For example, you can run the program with the command
> `./expression_evaluator "(1 + (2 * 3))"`.

Make sure to test your program with different input expressions to verify
that it evaluates them correctly.

## Submission

After you have completed the lab, submit the files below 
to [Gradescope](https://gradescope.com).  Your code should be well-formatted 
and easy to read.  Make sure to test your code thoroughly before 
submitting it.  You must be present in the lab to receive the 
attendance credit.  No remote submissions will be accepted.
If you have any questions, please ask the instructor or the TA for help.

- `stack.h`
- `stack.cpp`
- `stack_tester.cpp`
- `expression_evaluator.cpp`
