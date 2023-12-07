Q1. Write a program to implement the stack using an array.
Note: The code should have the modularity and should include following function apart from
main ():
 Push() This function inserts an element to top of the Stack.
 Pop() This function deletes an element from top of the Stack.
 Display() This function displays all the elements of the Stack by popping them one by one.

Q2. Convert an infix expression to its equivalent postfix expression.
Note: The code should have the modularity and should include following functions apart from
main():
 getNextToken(): This functions returns the next token in the input infix expression. The token
may be an operator or “(“ or “)” or an operand. The operands can be of multiple digits. For
example the infix expression 1000/(10+240) contains operands 1000, 10, and 240.
 infixToPostfix(): Converts the input infix expression to postfix. This function calls getNextToken()
repeatedly to get the next token until it reaches the end. The token is then processed depending
on whether it is an operand or operator or ( or ).

Q3. Write a program to implement the following algorithm:
 Start with two indexes one at the left and other at the right end of the array.
 Left index simulate the first stack and second index simulate the right stack.
 If we want to put the element in the first stack then put the element at the left index. Similarly,
if we want to put the element in the second stack then put the element at the right index.
 First stack grow towards left and second stack grow towards left. A simple demonstration of dual
stack can be observed from the following figure:

