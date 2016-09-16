# LongestUpSequence

Introduction
  The purpose of this program is to find the longest up-sequence  in a undefined set of elements. The algorithm given to us to implement uses a list of “stacks” (not the quite the stack data structure due to all of the elements being accessible) that contain the elements in a particular order.  The purpose of this project is to demonstrate the students’ knowledge of data structures, and ability to properly design efficient algorithms to solve a problem. The student should be able to analyze the algorithms and the implementation to collect useful data on the efficiency and correctness of their code.

Design, Presentation, and Analysis of the Algorithms and Data Structures
	To store the input data and keep track of its location I chose to create a simple node struct that would store the integer value, as well as a pointer to the top of the previous “stack,” and a pointer to the node below it in the stack. In my final design I chose to use a vector to store the top of each “stack.” I initially considered using a linked list however, a vector is easier to access the elements and I am only appending elements to the end of the stack or changing the value and a certain index. Accessing an element in a vector is O(1), and O(n) in a linked list. Adding an element to the end is O(1) for both data structures. 
