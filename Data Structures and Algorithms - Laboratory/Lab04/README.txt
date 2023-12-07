Q1. Write a program to implement the Doubly linked list. Perform the following operations on
the doubly linked list:
 Creating an empty doubly linked list
 Adding the new element at the beginning of the linked list.
 Deletion of a node after a particular location.
 Counting the no of nodes.
 Displaying the linked list.

Q2. Write a program to remove the duplicate elements from a sorted linked list.

Q3. Write a program to print all the elements of the single linked list in reverse order. The
algorithm should have linear time complexity and constant space complexity.

Q4. Repeatedly Delete N nodes after M nodes of a Linked list:
Given a linked list and two integers M and N. Traverse the linked list such that you retain M
nodes then delete next N nodes, continue the same until end of the linked list.
Input:
M = 2, N = 2
Linked List: 1->2->3->4->5->6->7->8
Output:
Linked List: 1->2->5->6
The main part of the problem is to maintain proper links between nodes, make sure that all
corner cases are handled.