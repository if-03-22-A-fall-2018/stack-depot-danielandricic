#include "stack.h"
#include <cstdio>
typedef struct n
{
    void *v;
    struct n *next;
} * N;

struct StackImplementation
{
    N head;
};

/**
 * Used to create a stack structure.
 * @return The newly created stack.
 */
Stack create_stack()
{
    Stack s = (struct StackImplementation *)smalloc(sizeof(struct StackImplementation));
    s->head = 0;
    return s;
}

/**
 * Used to free all memory the supplied stack allocated.
 * @param stack The stack to be deleted.
 * @note delete structure, including the struct itself, but not the data!
 */
void delete_stack(Stack stack)
{
    N curr = stack->head;
    while (curr != 0)
    {
        N tmp = curr;
        curr = curr->next;
        sfree(tmp);
    }
    sfree(stack);
}

/**
 * Adds a new node with the supplied data to the top of the stack.
 * @param stack The stack onto which data has to be pushed.
 * @param data The data to be pushed.
 */
void push_stack(Stack stack, void *data)
{
    N n = (N)smalloc(sizeof(struct n));
    n->v = data;
    n->next = 0;
    if (stack->head == 0)
        stack->head = n;
    else
    {
        n->next = stack->head;
        stack->head = n;
    }
}

/**
 * @param stack The stack which number of elements to be retrieved.
 * @return The number of items currently on the stack.
 */
int get_count(Stack stack)
{
    N curr = stack->head;
    int count = 0;
    while (curr != 0)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

/**
 * Removes and returns the topmost item of the stack.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.
 */
void *pop_stack(Stack stack)
{
    if (stack->head == 0)
        return 0;
    N n = stack->head;
    void *data = stack->head->v;
    stack->head = stack->head->next;
    sfree(n);
    return data;
}

/**
 * Returns the topmost item of the stack without removing it.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.
*/
void *peek_stack(Stack stack)
{
    if (stack->head == 0)
        return 0;
    return stack->head->v;
}
