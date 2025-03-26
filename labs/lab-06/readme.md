# Lab 6 (03/26/2025)

The goal of this lab is to implement a doubly-linked list.
While you can collaborate with peers, 
each student is expected to make an individual submission.

> [!WARNING]
> For this lab in particular, you are NOT ALLOWED to use LLMs (large language models)
> such as Copilot, ChatGPT, etc.  You are allowed to use the internet to look
> up syntax and other basic information, but you should not automatically
> generate code using LLMs.  If you have Copilot on your environment,
> please disable it for the duration of the lab.  Focus on understanding
> the concepts and writing the code yourself.

## The DoublyLinkedList class

Due to time constraints, you will complete the implementation of a 
doubly-linked list class that stores integer values, without using templates.  The 
`DoublyLinkedList` class should have the following public member functions:

- `default constructor`: initializes an empty list;
- `destructor`: deallocates the memory used by all nodes in the list;

- `push_back`: appends a new element `v` to the end of the list;
- `push_front`: inserts a new element `v` at the beginning of the list;
- `push_at`: inserts a new element `v` at a given position `idx` in the list, it should throw a `std::out_of_range` exception if the index is invalid;
- `pop_back`: removes the last element from the list, it should throw a `std::out_of_range` exception if the list is empty;
- `pop_front`: removes the first element from the list, it should throw a `std::out_of_range` exception if the list is empty;
- `pop_at`: removes the element at a given position `idx` in the list, it should throw a `std::out_of_range` exception if the index is invalid;
- `back`: returns a copy of the last element in the list, it should throw a `std::out_of_range` exception if the list is empty;
- `front`: returns a copy of the first element in the list, it should throw a `std::out_of_range` exception if the list is empty;
- `at`: returns a copy of the element at a given position `idx` in the list, it should throw a `std::out_of_range` exception if the index is invalid;
- `size`: returns the number of elements in the list;
- `empty`: returns `true` if the list is empty, and `false` otherwise;
- `clear`: removes all elements from the list;
- `contains`: returns `true` if the element `v` is in the list, and `false` otherwise;
- `print`: prints the elements of the list to the standard output.

You can find starter code for the `DoublyLinkedList` class in the
`doublylinkedlist.h` and `doublylinkedlist.cpp` files, 
however, the member functions are not implemented yet.  Your job is to
complete the implementation of the `DoublyLinkedList` class by implementing the
missing methods.  

> [!WARNING]
> Disable Copilot on your environment before starting your work.

After all methods have been completed, you can use the `dll_tester.cpp` 
source file to test the functionality of the `DoublyLinkedList` class.  

To compile your program, you can use the following command:

```bash
g++ -std=c++11 doublylinkedlist.cpp dll_tester.cpp -o prog
```

## Submission

After you have completed the lab, submit the files below 
to [Gradescope](https://gradescope.com).  Your code should be well-formatted 
and easy to read.  Make sure to test your code thoroughly before 
submitting it.  You must be present in the lab to receive the 
attendance credit.  No remote submissions will be accepted.
If you have any questions, please ask the instructor or the TA for help.

- `doublylinkedlist.h`
- `doublylinkedlist.cpp`
- `dll_tester.cpp`
