# Post Game Analysis

## Intuition
1. transfer elements of orig stack to temp stack until suitable inserting condition is satisfied
2. insert element
3. transfer back temp stack elements to orig stack

No need to use pop, push or peek when transferring elements to a temporary stack. Just manually connect and disconnect their links.

Here is what transferring an entire stack to another stack looks like:

```
while(stack != NULL){
    temp = i->top;
    i->top = stack;
    stack = stack->link;
    i->top->link = temp;
  }
```

The stack where you want to transfer the elements to will need a temp pointer to hold the elements temporarily so that you can insertFirst.

stackDestination: the stack where you want to transfer the elements to
stackSource: the stack that has the elements where you want them transferred

Steps:
1. Let temp hold stackDestination's elements (if there are any).
2. Set stackDestination to stackSource' first elem
3. Set stackSource to point to its next elem
4. Let stackDestination's link pointer point back to temp