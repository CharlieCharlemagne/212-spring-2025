# Lab 10 (04/23/2025)

The goal of this lab is to is to learn and experiment with *hash*
functions and their use in hash tables.  

> [!WARNING]
> For this lab in particular, you are NOT ALLOWED to use LLMs (large language models)
> such as Copilot, ChatGPT, etc.  You are allowed to use the internet to look
> up syntax and other basic information, but you should not automatically
> generate code using LLMs.  If you have Copilot on your environment,
> please disable it for the duration of the lab.  Focus on understanding
> the concepts and writing the code yourself.

## Hashing

Hashing refers to a technique that transforms data of arbitrary type and size into 
fixed-size values through mathematical functions called *hash functions*. 

A hash function is an algorithm that converts a given *key* into a numeric 
value called a *hash code* or *hash value*.  Effective hash functions possess several 
crucial characteristics:

- *Determinism*: same input key should always yield the same output code
- *Uniformity*: hash codes should be uniformly distributed
- *Efficiency*: hash function should compute the hash code efficiently, ideally in constant time
- *Avalanche Effect*: a small change in the input key should produce a significantly different hash code

For example, the string `"hello"` might be hashed to the integer `210714636441`, while 
`"world"` might be hashed to `210732791149`.

In this lab we will analyze two different hash functions for strings:

- `djb2`: developed by Daniel J. Bernstein, it is widely used in practice and is known for its simplicity and speed.  It calculates the hash value by iteratively multiplying the current hash value by 33 and adding the ASCII code of each character in the string.  The final hash value is then returned as an unsigned integer

```c++
unsigned long djb2_hash(const std::string& str) {
    unsigned long hash = 5381;
    
    for (char c : str) {
        // hash * 33 + c
        hash = ((hash << 5) + hash) + static_cast<unsigned long>(c);
    }

    return hash;
}
```

- `FNV-1a`: it is known for its good distribution properties and is also widely used in practice.  It calculates the hash value by initializing it to a fixed value and then iteratively XORing the current hash value with the ASCII value of each character in the string, followed by multiplying it by a prime number.

```c++
unsigned long fnv1a_hash(const std::string& str) {
    const unsigned long prime = 16777619u;
    unsigned long hash = 2166136261u;

    for (char c : str) {
        // XOR with the character
        hash ^= static_cast<unsigned long>(c);
        // multiply by the prime
        hash *= prime;
    }

    return hash;
}
```

## Bucketing

For the purpose of this lab, assume a *hash table* is simply 
a fixed-length `std::array` object that provides 
constant time access to its elements. The length of the array, 
denoted by `M`, is the number of *buckets* in the hash table.

We can map a collection of `N` elements to the hash table using a 
hash function to compute the index of the hash table where each 
element will be stored.  Note that if `N > M`, then we have more 
elements than available buckets in the hash table.  In this case,
when elements map to the same bucket, we have a *collision*.
In particular, this approach is very efficient when the load 
factor `N / M` is small, meaning that the number of elements
is much smaller than the number of buckets in the hash table.

We will analyze how good are the two hash functions shown above
in distributing the elements into a hash table.  That is, we will 
analyze how many collisions occur when we insert `N` elements 
into a hash table of size `M`.

In order to calculate the index of each element in the hash table,
we proceed by applying a *hash function* to the element, which
returns a numeric value called *hash code*.  The hash code is then
mapped to an index in the hash table using a *modulo* operation, 
which calculates the remainder of the division of the hash code by
the number of buckets in the hash table.  The index is then used
to store the element in the hash table.  Note that this approach,
when keys are uniformly distributed, will make the search operation
in the hash table very efficient, as it will take **constant time** to
access the element in the hash table (we only need to calculate the index).

The *modulo* operation is expensive to compute, especially for 
large numbers, an alternative approach is to use a *bitwise AND* operation
to calculate the index in the hash table.  This approach is only possible
when the number of buckets in the hash table is a *power of two*.

In this part of the lab we will analyze two different methods to calculate
the index of each key before inserting it into the hash table.  
The two methods are:

- `Prime number`: the index of a `key` is calculated as `hash(key) % M`, where `hash` is the hash function and `M` is a prime number.  This method is known to produce a good distribution of keys, especially when the hash function is not very good at distributing the keys uniformly.

- `Power of two`: the index of a `key` is calculated as `hash(key) & (M - 1)`, where `hash` is the hash function and `M` is a power of two.  This method is known to perform faster than the prime number method, as the bitwise AND operation is much faster than the modulo operation.  However, it is known to produce a poor distribution of elements in the hash table.

> [!WARNING]
> Disable Copilot on your environment before starting your work.

## Task 1

The data required for this task is the same collection of English words
used in the previous lab. The file is available at the following URL: 
[An English Word List](https://websites.umich.edu/~jlawler/wordlist.html)
The word list contains `69,903` words and each word is on a line by 
itself. The entire file is in lower case, including all the proper names.

You will analyze four different combinations of hash functions and
indexing methods:

- `djb2` with `Prime number`
- `djb2` with `Power of two`
- `FNV-1a` with `Prime number`
- `FNV-1a` with `Power of two`

For each of the combinations above, you will create and object `std::array<unsigned int>`
that will count the number of *collisions* for each corresponding index.
For example, if the value at index `i` is `3`, it means that three words
hash to the same index `i`.

You can initialize the array to all zeros, then iterate over the list of words and
apply the hash function to each word, calculate the index in the hash table
using the corresponding method, and then increment the count of the
corresponding index in the array.  For the prime number method, use `M = 65,537`, 
and for the power of two method, use `M = 65,536`.  Remember that `M` denotes the size of 
the hash table, and `N = 69,903` is the number of words in the list.  The fraction
`N / M` gives you an idea of how many words map to each index in the hash table.

For each of the four combinations, you will print the following information:

- the percentage of empty buckets in the table
- the percentage of buckets with one element
- the percentage of buckets with two elements
- the percentage of buckets with three elements
- the percentage of buckets with four or more elements

Given the printed information, you will select the best method to use in the next task.
You will also provide a clear explanation of why you selected that method.

Save your code into a file called `task-1.cpp` and make sure to test it thoroughly.
Save the output of your program in a file called `output.txt`.  You should also add
to this file the explanation of why you selected the method you did.

## Task 2: Find words not in the dictionary

In this task, you will create another program called `task-2.cpp` that will
read the contents of the text file `2600-0.txt`, which contains the contents 
of *War and Peace* by Leo Tolstoy, downloaded from 
[Project Gutenberg](https://www.gutenberg.org/ebooks/2600).  In the previous
lab, you used the same text file to find words that are not in the dictionary.

In this task, you will use a hash table with the method you selected in Task 1.
First, read the dictionary file and insert all the words into the hash table.
Then, read the text file and for each word in the text, check if it exists in 
the hash table.  Given that collisions are possible you will implement a hash 
table as an *array of red-black trees*.  That is, if two words hash to the same 
index in the hash table, you will store them in a red-black tree at that index.  
In C++, you can use the `std::set` class to implement a red-black tree.
See the following code snippet for an example of how to use a hash table
with an array of red-black trees:

```c++
// declaration of the hash table:
// array of red-black trees, keys are strings
// the array has a fixed length of M
// replace M by value chosen in Task 1
std::array<std::set<std::string>, M> hash_table;

// an index can be calculated in this way
// if using FNV-1a hash function and the prime number method
unsigned long index = fnv1a_hash("hello") % M;

// an insertion into the hash table can be done as follows
hash_table[index].insert("hello");

// checking if a word is in the hash table
if (hash_table[index].contains("hello")) {
    // word is in the hash table
} else {
    // word is not in the hash table
}
```

After opening the text file, read its contents line by line, 
ignore all punctuation and special characters, and convert 
all words to lower case. For each word (token) in the text, 
check if it exists in the dictionary (hash table), if the 
word does not exist in the hash table, increase a counter
of "words not in the dictionary" . After processing 
the entire text (book), print the final value of the counter.
Add this information to the output file `output.txt`.

## Submission

After you have completed the lab, submit the files below 
to [Gradescope](https://gradescope.com).  Your code should 
be well-formatted and easy to read.  Make sure to 
test your code thoroughly before 
submitting it.  You must be present in the lab to receive the 
attendance credit.  No remote submissions will be accepted.
If you have any questions, please ask the instructor or the TA for help.

- `task-1.cpp`
- `task-2.cpp`
- `output.txt`
