/**
 * Stack data structure implementation and demonstration
 * 
 * Author: Gediminas Rapolavicius <gediminas.rap@gmail.com>
 * Website: http://github.com/GedRap
 */

/**
 * Data structure to hold data for an individual item in the stack.
 * Can be easily extended (that's why I created a separate structure, rather
 * than just pushing an integer)
 */
typedef struct {
    int value;
} Stack_Item;

/**
 * Data structure to hold the stack and it's internal data
 */
typedef struct {
    int size; //stack array's size
    int n; //number of items currently in the stack
    Stack_Item **stack; //the stack itself (array of pointers to the elements)
} Stack;

Stack *stack_create(int size);
Stack_Item *stack_pop(Stack *stack);
int stack_push(Stack *stack, Stack_Item *item);
int stack_num_elements(Stack *stack);
int stack_is_full(Stack *stack);
void stack_dump(Stack *stack);

int stack_item_get_val(Stack_Item *item);
Stack_Item *stack_item_create(int value);
