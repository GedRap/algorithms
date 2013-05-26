/**
 * Stack data structure implementation and demonstration
 * 
 * Author: Gediminas Rapolavicius <gediminas.rap@gmail.com>
 * Website: http://github.com/GedRap
 */
#include "stack.h"
#include <stdio.h>

/**
 * Demonstration of the stack implementation
 */
int main() {
    Stack_Item *item1 = stack_item_create(1);
    Stack_Item *item2 = stack_item_create(3);
    printf("[DEBUG] Stack Item 2 at %p\n", item2);
     
    Stack *stack = stack_create(5);
    stack_dump(stack);

    stack_push(stack, item1);
    stack_push(stack, item2);

    printf("Stack after pushing\n");
    stack_dump(stack);
    
    Stack_Item *popped = stack_pop(stack);
    printf("[DEBUG] Popped item at %p (expected %p)\n", popped, item2);

    int popped_value = stack_item_get_val(popped);

    printf("[DEBUG] Expected to pop 3, popped %d\n", popped_value);

    printf("[DEBUG] Stack after popping\n");
    stack_dump(stack); 
    return 1;
}
