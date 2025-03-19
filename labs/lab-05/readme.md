# Lab 5 (03/19/2025)

The goal of this lab is to implement a max priority queue 
using a binary heap backed by a fixed-size array (C-style),
and then use it to calculate the top-K elements from 
a large dataset. While you can collaborate with peers, 
each student is expected to make an individual submission.

It is strongly recommended that you have access to a
`bash` shell to successfully complete this lab.  If you are 
using a Windows machine, you can use the `WSL` 
(*Windows Subsystem for Linux*) to run a `bash` shell. If
you are using a Mac, you can use the `Terminal` application. If 
you are using a Linux machine, you can use the `Terminal` 
application as well.

> [!WARNING]
> For this lab in particular, you are NOT ALLOWED to use LLMs (large language models)
> such as Copilot, ChatGPT, etc.  You are allowed to use the internet to look
> up syntax and other basic information, but you should not automatically
> generate code using LLMs.  If you have Copilot on your environment,
> please disable it for the duration of the lab.  Focus on understanding
> the concepts and writing the code yourself.

## The Priority Queue class

Due to time constraints, you will complete the implementation of a 
max priority queue class, using a binary heap backed by a fixed-size 
array (C-style), i.e., a binary heap with a fixed capacity that does not 
grow or shrink.  

We will be following closely the methods described in class.  The 
`PriorityQueue` class should have the following public member functions:

- `default constructor`: initializes an empty binary heap with a given capacity;
- `destructor`: deallocates the memory used by the internal array;

- `enqueue`: takes a reference to an element and
  adds it to the binary heap, it should throw 
  a `std::out_of_range` exception if the binary heap is full;
- `dequeue`: removes the max element (root) from the binary heap, 
it should throw a `std::out_of_range` exception if the binary 
  heap is empty;
- `front`: returns a reference to the max element (root)
  of the binary heap, it should throw a `std::out_of_range` exception
  if the binary heap is empty;
- `make_heap`: takes an array of elements and builds a binary heap
  from them in linear time, this function should throw a `std::out_of_range` exception if the
  array is larger than the capacity of the binary heap;
- `get_size`: returns the number of elements in the binary heap;
- `get_capacity`: returns the capacity of the binary heap;
- `empty`: returns `true` if the binary heap is empty, and
  `false` otherwise.

You can find starter code for the `PriorityQueue` class in the `pqueue.hpp` file, 
however, some of the member functions are not implemented yet.  Your job is to
complete the implementation of the `PriorityQueue` class by implementing the
missing methods.  

Note that the `upHeap` and `downHeap` helper functions are already implemented for you as private member functions.  Follow the `TODO` comments in the `pqueue.hpp` file to complete this part of the lab.

> [!WARNING]
> Disable Copilot on your environment before starting your work.

After all methods have been completed, you can use the `pqueue_tester.cpp` source file to test the 
functionality of the `PriorityQueue` class.  Before moving to the next task, ensure your program
works correctly according to the logic described in the `pqueue_tester.cpp` file.

To compile your program, you can use the following command:

```bash
g++ pqueue_tester.cpp -o prog
```

## Calculating top-K elements from a large dataset

In this section, you will implement a short program `top-k.cpp` that uses the `PriorityQueue` class
to calculate the top-K elements from a large dataset. The program should read a file, from the standard input, containing a large number of integers,
calculate the largest K elements from the file, and then print them to the console.

### Step 1: Generate random data

You are provided a `generator.py` script that generates `n` random
integers and writes them to the `stdout` stream.  The script takes one
command line argument, which is the number of integers to generate.
You can run the script with the following command:

```bash
python3 generator.py 1000000 > data.txt
```

This command will generate 1,000,000 random integers and its output
can be redirected to a file called `data.txt`.  You can change the
number of integers to generate by changing the command line argument.

You can inspect the contents of the file using the `head` or `cat` commands:

```bash
head data.txt
```

### Step 2: Reading data from the standard input

Your program will read the integers from the `stdin` stream. To
this end, you can use `std::cin` in C++.

```cpp
int value;

while (std::cin >> value) {
    // process `value`
}
```

`std::cin` will read integers from the `stdin` stream until
the end of the file is reached.  

### Step 3: Calculating the top-K elements

Your program should use a `PriorityQueue` internally to calculate 
the top-K elements from the file.  Your job is to design and
implement an algorithm that runs as efficiently as possible.  The 
value of `k` should be passed as a command line argument
to the program, and then output the top-K elements to the
standard output in increasing order. The line below shows an
example of how to use your program.

```bash
./prog 25 < data.txt
```

This command will run your program with `k=25` and read the integers from
the standard input.  We use the redirection operator `<` to redirect the
contents of the `data.txt` file to the standard input.

### Step 4: Testing your program

Make sure to test your program with different values of `k` and
different sizes of the input file.  You can use the `generator.py` script
to generate different sizes of input files.  You are **strongly encouraged**
to test your program, initially, with small values of `k` and small
input files, veryfing that the output is correct.  Then, you can test
your program with larger values of `k` and larger input files.  Make sure
to test your program with edge cases.  Finally, stress test your program
with large values of `k` and large input files, to make sure that it
runs efficiently.

### Step 5: Analyzing the performance

After you are done conding and testing your program, you should analyze the
computational complexity of your algorithm and write a short report
in the `analysis.txt` file.  The report should include the following:

- a description of the algorithm used to calculate the top-K elements;
- the computational complexity of the algorithm in terms of the number
  of elements `n` in the input file and the value of `k`.

## Submission

After you have completed the lab, submit the files below 
to [Gradescope](https://gradescope.com).  Your code should be well-formatted 
and easy to read.  Make sure to test your code thoroughly before 
submitting it.  You must be present in the lab to receive the 
attendance credit.  No remote submissions will be accepted.
If you have any questions, please ask the instructor or the TA for help.

- `pqueue.hpp`
- `pqueue_tester.cpp`
- `top-k.cpp`
- `analysis.txt`
