User Document

Introduction:

	This program uses recursion to implement the kSmall algorithm in the textbook Data Abstraction and Problem Solving with C++: Walls and Mirrors, 7e (Ch. 2 Section 4.4). There you will find pseudocode for an almost complete kSmall function. Next, we needed to create a partition function that would partition the user entered array, it will partition the array using the first element as the partition. If the first element in the array is the smallest, all elements will be in S2. If the first element is the largest element in the array, all other elements will be in S1. The overall goal is to implement the recursive solution to the kSmall function.

File Location:

The programs name is mainProject3.cpp. It is located in the following directory on CentOS: /home/STCLOUDSTATE/hp0106rn


How To Compile Program:

Enter: g++ mainProject3.cpp 

How To Run Program:

	Enter: ./a.out to begin the program.

Prompt> “How many integers do you need to enter?”
User Input> User enters the amount of elements (integers) they have.

Prompt> “Please enter …. Integers.”
User Input> User enters the elements of the array separated by a space

Displayed To User> “Here is your partitioned array: “  <PARTITIONED ARRAY>

Prompt> “Enter the index (k) you would like to test: “
User Input> User enters what element they would like to test.

Displayed To User> “The <kth> smallest element is <p>

Displayed To User> “The kth element <p> is in (S1, S2)/is the pivot.

Program then terminates.
