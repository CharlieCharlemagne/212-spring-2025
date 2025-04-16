# Lab 9 (04/16/2025)

The goal of this lab is to implement a binary search tree class,
and then use it to support a text processing task involving
a dictionary of words. 

> [!WARNING]
> For this lab in particular, you are NOT ALLOWED to use LLMs (large language models)
> such as Copilot, ChatGPT, etc.  You are allowed to use the internet to look
> up syntax and other basic information, but you should not automatically
> generate code using LLMs.  If you have Copilot on your environment,
> please disable it for the duration of the lab.  Focus on understanding
> the concepts and writing the code yourself.

## The Binary Search Tree class

We will be following closely the methods described in class.  The 
`BST` class should have the following **public member functions**:

- `default constructor`: initializes an empty BST;
- `destructor`: deallocates the memory used by the BST;
- `insert`: adds an element to the tree;
- `remove`: removes an element (key) from the BST, if the key exists;
- `clear`: removes all elements from the BST;
- `search`: searches for an element (key) in the BST, it should return
    `true` if found, or `false` otherwise;
- `get_size`: returns the number of elements in the BST;
- `get_height`: returns the height of the BST;
- `empty`: returns `true` if the BST is empty, and `false` otherwise;
- `print_in_order`: prints the elements of the BST in increasing order.

You can find starter code for the `BST` class in the `bst.hpp` file
with most of the public/private member functions already defined.
However, `get_height` is not implemented yet.  
Your job is to carefully read the comments and the code provided 
in the `bst.hpp` file, and then implement the missing method.

Note that for most **public** member functions, we also implement
a corresponding **private** member function that does the actual work.
This is a common practice to separate the interface
from the implementation.  The **public** member function is
usually a simple wrapper that calls the **private** member function
with the appropriate parameters.  The **private** member 
function, in the case of this BST implementation, are **recursive**
and require a pointer to the current node as a parameter,
not visible outside the class.

> [!WARNING]
> Disable Copilot on your environment before starting your work.

After all methods have been completed, you can use the 
`bst_tester.cpp` source file to test the functionality of 
the `BST` class.  Before moving to the next task, ensure 
your program works correctly according to the logic described 
in the `bst_tester.cpp` file.  In particular, add a few lines
at the end of the `bst_tester.cpp` file to test the `get_height`
method you implemented.  You can try inserting a few elements
in increasing order, and then check the height of the tree.
Also insert a few elements in random order and check the height again.

To compile your program, you can use the following command:

```bash
g++ bst_tester.cpp -o prog
```

## Finding words not in the dictionary

The first step is to implement a program that uses the `BST` class to store 
a collection of English words. This collection is an alphabetized list of 
English words produced from a number of texts from the internet. 
The file is available at the following URL: 
[An English Word List](https://websites.umich.edu/~jlawler/wordlist.html)
The word list itself contains 69,903 words and each word is on a line by 
itself. The entire file is in lower case, including all the proper names.

### Step 1: Read a word list file

- Download the word list file from the URL above and save it as `words.txt`;
- Implement a program `find_words.cpp` that reads ALL the words from `words.txt`, initially into a `vector<std::string>` of words;
- Shuffle the words in the vector using `std::random_shuffle` or `std::shuffle`, this will ensure that the words are not in alphabetical order before inserting them into the BST (remind our tree is not a balanced tree and inserting words in alphabetical order will lead to a degenerate tree);
- Insert all the words from the vector into an object of the class BST;
- Print the size of the BST using the `get_size` method;
- Print the height of the BST using the `get_height` method;
- Print the value of `log2(n)` where `n` is the size of the BST (can use `std::log2` from the `<cmath>` library to compute this value). This will give you an idea of how balanced your tree is compared to a perfectly balanced tree.

### Step 2: Find words not in the dictionary

- Within the same program, you will now open the provided text file `2600-0.txt`, which contains the contents of *War and Peace* by Leo Tolstoy, downloaded from [Project Gutenberg](https://www.gutenberg.org/ebooks/2600);
- Read the contents of the file line by line, ignore all punctuation and special characters, and convert all words to lower case. For each word (token) in the text, check if it exists in the BST (created in step 1), if the word does not exist in the BST, add it to another BST object called `not_found`, this will store all the words that are not found in the dictionary with no duplicates;
- After processing the entire text (book), print the words that were *not found* in the dictionary in alphabetical order using the `print_in_order` method of the `BST` class.

>[!NOTE]
> You are provided an example of how to read a text file line by line and how to split the lines into valid words, removing all punctuation and special characters, in the `tokenizer.cpp` file.  Take a look and use it as a reference for your implementation.  You can copy and paste the code from `tokenizer.cpp` into your `find_words.cpp` file, adapting it as necessary.

## Submission

After you have completed the lab, submit the files below 
to [Gradescope](https://gradescope.com).  Your code should be well-formatted 
and easy to read.  Make sure to test your code thoroughly before 
submitting it.  You must be present in the lab to receive the 
attendance credit.  No remote submissions will be accepted.
If you have any questions, please ask the instructor or the TA for help.

- `bst.hpp`
- `bst_tester.cpp`
- `find_words.cpp`
- `output.txt`

> [!NOTE]
> Collect the output of your program, specifically, the output of Step 1 and Step 2 above, and save it in a file called `output.txt`.
