# Lab 7 (04/02/2025)

The goal of this lab is to practice the implementation of
recursive algorithms.  We strongly encourage you to work
on this lab in collaboration with your peers, but you are expected to
complete the code on your own, as
each student is expected to make an individual submission.

> [!WARNING]
> For this lab in particular, you are NOT ALLOWED to use LLMs (large language models)
> such as Copilot, ChatGPT, etc.  You are allowed to use the internet to look
> up syntax and other basic information, but you should not automatically
> generate code using LLMs.  If you have Copilot on your environment,
> please disable it for the duration of the lab.  Focus on understanding
> the concepts and writing the code yourself.

## Problem 1

Write a function `draw_triangle` in C++ that takes three 
positive integers `a`, `b`, and `c` as input, where 
`0 < a <= b` and `0 < c`. The function should print a pattern 
of `+` characters according to the following rules:

1. The first line should contain `a` characters of `+`;
2. The subsequent lines should contain an increasing number of `+` characters, starting from `a + c`, then `a + 2*c`, and so on, as long as the number of characters in a line is less or equal than `b`. If the next line's length would exceed `b`, it should not be  printed;
3. After reaching the maximum line length, the pattern should then repeat in reverse order.

For example, calling `draw_triangle(4, 7, 1)` should output:

```
++++
+++++
++++++
+++++++
+++++++
++++++
+++++
++++
```

Create a file named `triangle.cpp`. Include your function in
this file along with a `main` function to test it. Test your 
function with at least the following cases:

- `draw_triangle(4, 7, 1)`
- `draw_triangle(3, 10, 3)`
- `draw_triangle(1, 1, 1)`
- `draw_triangle(1, 7, 7)`

## Problem 2

In this problem you will implemente a recursive function to change
the pixel values of an image represented as a 2D array. Given an 
input image and an arbitrary initial pixel at location $(x, y)$,
your task is to change the pixel values of the image to a new 
value `0` (white) using a flood-fill algorithm.

### Input

Your program will receive three command line arguments:

1. the name of the input image file.  Each image is a $24 \times 24$ grid of pixels, where each pixel is represented by a single integer value between 0 and 7 (inclusive). The integer values represent different colors;
2. the x-coordinate of the initial pixel (0-indexed);
3. the y-coordinate of the initial pixel (0-indexed).

Note that the coordinate system for the image is $(x, y)$ 
where $x$ is the row (vertical) and $y$ is the column 
(horizontal).  The top-left corner of the image corresponds 
to $(0, 0)$, and the bottom-right corner corresponds to $(23, 23)$.

One important decision is how to represent the image internally.
You can represent the image as a 2D array (or vector of vectors) 
of integers, where each integer corresponds to a pixel value. 
Alternatively, you can also use a 1D array (or vector) and compute 
the corresponding index of each pixel based on the row and column 
(i.e., `index = x * 24 + y`).  Discuss with your peers and 
choose the representation that you feel most comfortable with.

### Output

Your program should output the modified image to the
standard output, using the same same format as the input file. 
Each pixel should be represented by a single integer value 
between 0 and 7 (inclusive). The output should reflect 
the flood-fill operation starting from the initial pixel.

### Flood-Fill Algorithm

The flood-fill algorithm works by changing the current pixel
value at the specified coordinates `(x, y)` to `0` (white) if
it is not already `0`. Then, it *recursively* calls itself on 
the neighboring pixels (up, down, left, right) if they have 
the same original value as the starting pixel. The algorithm
stops when it reaches a pixel that is already `0` (white) or
when it goes out of bounds of the image (pixels outside the 
range of `0` to `23` for both `x` and `y`).

> [!WARNING]
> Regardless of the choice of representation, you must ensure that the recursive function receives a reference to the image data instead of a copy of it. This is to ensure that the changes made to the image persist across recursive calls. If you pass by value, each recursive call will work on a copy of the image, and the changes will not be reflected in the original image.

![Alt Text](https://upload.wikimedia.org/wikipedia/commons/7/7e/Recursive_Flood_Fill_4_%28aka%29.gif)

### Example usage

Your code will be implemente in a file named `floodfill.cpp`.
After compiling your program, you can run it from the command 
line as follows:

```bash
./prog <filename> 10 10
```

Where `<filename>>` is a file containing a $24 \times 24$ grid 
of integers (0-7) amd `10` and `10` are the coordinates of 
the initial pixel to start the flood-fill.  You are provided 
with 4 sample images for testing your flood-fill algorithm 
(`file-1.txt`, `file-2.txt`, `file-3.txt`, and `file-4.txt`). 

Note that the output should be printed to the standard output 
in the same format as the input file.  You can **redirect** 
the output to a file with the following command:

```bash
./prog <filename> 10 10 > output.txt
```

Finally, you are provided with a python script called
`vis.py` that can be used to visualize the output of your 
flood-fill algorithm. You can run it as follows:

```bash
python3 vis.py output.txt
```

You are encouraged to use this script to visualize the
input file and then the output file after running your 
flood-fill algorithm, to verify that your implementation 
is correct.

## Submission

After you have completed the lab, submit the files below 
to [Gradescope](https://gradescope.com).  Your code should be well-formatted 
and easy to read.  Make sure to test your code thoroughly before 
submitting it.  You must be present in the lab to receive the 
attendance credit.  No remote submissions will be accepted.
If you have any questions, please ask the instructor or the TA for help.

- `triangle.cpp`  (for Problem 1)
- `floodfill.cpp` (for Problem 2)
