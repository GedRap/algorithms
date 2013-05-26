# Stack data structure implementation and demonstration

This implementation does not copy the item which is pushed to the stack but pushes
the reference to the item only.

It has a Stack\_Item data structure which allows to extend it depending on the
use case (e.g. add timestamp when the item was pushed).

# Implementation
Implementation is in stack.c

# Demo
Demonstration is in main.c

# Compiling and running
gcc -Wall main.c stack.c -o stack.o
./stack.o
