# Lab 3 (02/12/2025)

The goal of this lab is to practice writing code in C++ with a focus on classes
and object-oriented programming, operator overloading to manipulate objects,
and dynamic memory allocation.  While you can collaborate with peers, 
each student is expected to make an individual submission.

> [!WARNING]
> For this lab in particular, you are NOT ALLOWED to use LLMs (large language models)
> such as Copilot, ChatGPT, etc.  You are allowed to use the internet to look
> up syntax and other basic information, but you should not automatically
> generate code using LLMs.  If you have Copilot on your environment,
> please disable it for the duration of the lab.  Focus on understanding
> the concepts and writing the code yourself.

## The Date class

Classes are a fundamental concept in object-oriented programming.  They allow 
you to define a blueprint for objects that can be created and manipulated 
in your program.  In this lab, you will study the starter code provided and
then complete the implementation of a class called `Date`.  The class has the 
following data members:

- `day`: an integer representing the day of the month;
- `month`: an integer representing the month of the year;
- `year`: an integer representing the year.

The class should include the following public member functions:

- a default constructor that prints a message when the object is
  created and initializes the date to January 1, 2000;
- a parameterized constructor that prints a message when the object
  is created, takes three integers (day, month, year), and initializes
  the date to the given values;
- a destructor that prints a message when the object is destroyed;
- a member function `print` that prints the date in the format
  `mm/dd/yyyy` (e.g., `01/01/2000`);
- a member function `add_days` that takes an integer `n` as a parameter
  and adds `n` days to the date, `n>=0`;
- an overloaded `+=` operator that takes an integer `n` as a parameter
  and adds `n` days to the current date, `n>=0`;
- an overloaded `==` operator that compares two `Date` objects and
  returns `true` if they represent the same date, and `false` otherwise;
- an overloaded `!=` operator that compares two `Date` objects and
  returns `true` if they represent different dates, and `false` otherwise;
- an overloaded `<` operator that compares two `Date` objects and returns
  `true` if the first date is earlier than the second date, and `false` otherwise.

Ideally, additional operators like `<=`, `>`, `>=`, `+`, and `-` should also 
be implemented to provide a complete set of comparison and arithmetic 
operators for the `Date` class.  However, for this lab, you are only required 
to implement the operators listed above.

In order to modularize and facilitate the implementation of the `Date` class, a few 
private member functions are recommended.  The idea behind these helper 
functions is to break down the implementation into smaller, more manageable 
parts.  Private member functions are not accessible from outside the class 
and are used internally to help implement the public member functions.  
Consider the following private member functions:

- a member function `is_valid_date` that takes a day, month, and year as
  parameters and returns `true` if the date is valid, and `false` otherwise;
- a member function `days_in_month` that takes a month and year as
  parameters and returns the number of days in that month;
- a member function `is_leap_year` that returns `true` if the year is a
- leap year, and `false` otherwise;
- a member function `add_one_day` that adds one day to the current date.

## Implementation details

The `Date` class must be defined in the `date.h` header file and implemented 
in the `date.cpp` source file.  Additionally, you will create a `date-tester.cpp` 
file to test the functionality of the `Date` class.  Starter code is provided 
in [this folder](#).  To ensure proper encapsulation, the data members of 
the `Date` class should be private, and the member functions should be 
public, unless the function is a helper function that is only used 
internally by the class.  Encapsulation is a key concept in object-oriented 
programming that helps to keep the implementation details of a class hidden 
from the user of the class.

Download the provided starter code, **read carefully each line of code**, 
and complete the implementation of the `Date` class according to the 
specifications outlined above, under the specified ` TODO ` comments.  
The `date-tester.cpp` file contains a number of tests to verify that 
your implementation works correctly.  

To compile this project use the following command: 
`g++ date.cpp date-tester.cpp -o date-tester`.  To run the compiled program, 
use the command `./date-tester`.

> [!IMPORTANT]
> The recommended approach to complete this lab is to focus on one
> member function at a time.  Implement each member function following
> the order provided in the starter code, test the functino using the
> `date-tester.cpp` file, making sure it works correctly before moving
> on to the next member function.  This incremental approach will
> help you catch and fix errors early in the development process.

## Submission

After you have completed all the exercises, submit the files below 
to [Gradescope](https://gradescope.com).  Your code should be well-formatted 
and easy to read.  Make sure to test your code thoroughly before 
submitting it.  You must be present in the lab to receive the 
attendance credit.  No remote submissions will be accepted.  
If you have any questions, please ask the instructor or the TA for help.

- `date.h`
- `date.cpp`
- `date-tester.cpp`: add comments to the top of the file with your name(s) and answer the following question: What is the purpose of constructors and destructors in C++ classes?  Explain why the messages 'constructor called' and 'destructor called' are printed when your program is executed.
- `output.txt`: After you are done implementing the `Date` class and successfully passing all tests, redirect the output of your program to a text file using the command `./date_tester > output.txt`.
