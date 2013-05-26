/**
 * Stack data structure implementation and demonstration
 * 
 * Author: Gediminas Rapolavicius <gediminas.rap@gmail.com>
 * Website: http://github.com/GedRap
 *
 * This implementation does not push the item itself (i.e. does not copy it)
 * But pushes the reference to it only.
 */
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Create a stack of a given size
 */
Stack *stack_create(int size) {
    Stack *stack_struct = (Stack*)malloc(sizeof(Stack));

    (*stack_struct).n = 0;
    (*stack_struct).size = size;

    Stack_Item **the_stack = (Stack_Item**)malloc(sizeof(Stack_Item*) * size);
    (*stack_struct).stack = the_stack;

    return stack_struct;
}

/**
 * Pop an item from the stack
 * Exit if the stack is empty
 */
Stack_Item *stack_pop(Stack *stack) {
    if(stack_num_elements(stack) == 0) {
        fprintf(stderr, "Stack is empty\n");
        exit(-1);
    }

    (*stack).n--;
    int n = (*stack).n;

    Stack_Item *item = (*stack).stack[n];
    (*stack).stack[n] = NULL;

    return item;
}

/**
 * Push an item to the stack.
 * Exit if the stack is full
 */
int stack_push(Stack *stack, Stack_Item *item) {
    if(stack_is_full(stack)) {
        fprintf(stderr, "Stack is full\n");
        exit(-1);
    }

    int n = (*stack).n;
    (*stack).stack[n] = item;
    (*stack).n++;

    return (*stack).n;
}

/**
 * Get the number of elements in the stack
 */
int stack_num_elements(Stack *stack) {
    return (*stack).n;
}

/**
 * Check if the stack is full.
 */
int stack_is_full(Stack *stack) {
    return (*stack).n == (*stack).size;
}

/**
 * Dump the contents of the stack (for debugging/demo)
 */
void stack_dump(Stack *stack) {
    printf("===== Stack Dump ======\n");
    printf("Stack at %p\n", stack);
    printf("Stack size %d\n", (*stack).size);
    printf("Stack elements %d\n\n", (*stack).n);

    int i;
    for(i = 0; i < (*stack).size; i++) {
        Stack_Item *item = (*stack).stack[i];
        printf("[%d] at %p\n", i, item);
    }

    printf("===== ========== ======\n");
}


/**
 * Get integer value of the stack item
 */
int stack_item_get_val(Stack_Item *item) {
    return (*item).value;
}

/**
 * Create a stack item with the given value
 */
Stack_Item *stack_item_create(int value) {
    Stack_Item *item = (Stack_Item*)malloc(sizeof(Stack_Item));
    (*item).value = value;
    return item;
}
