#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "./Array/stack_array.h"

/*
#define MAX 10
typedef struct {
    int data[MAX];
    int top;
} Stack;

1. Arithmetic Expressions

infix to postfix (Normal)
ex.
2 * 3 + 5 * 4 - 9
{(2 3 *) + (5 4 *)} - 9
{(2 3 *)(5 4 *) + } - 9
{(2 3 *)(5 4 *) + } 9 -
2 3 * 5 4 * + 9 -

infix to postfix (Programmatically)
Rules/Algorithm
1. If it is an operand output directly
2. If you see operator put in stack (But)
    2.1 If you encounter a new operator that is lower or equal precedence to one in stack, just push to stack
    2.2 If you encounter a new operator that is higher precedence than one in top of stack, 
        pop the stack and output it while new_operator >= top of stack
3. If stack is not empty, output it all
ex.
2 * 3 + 5 * 4 - 9  Stack 
2               
2                   *
2 3                 *
2 3 *               +
2 3 * 5             +
2 3 * 5             * +
2 3 * 5 4           * +
2 3 * 5 4 * +       -
2 3 * 5 4 * + 9     -
2 3 * 5 4 * + 9 -                  

evaluate postfix
Rule:
1. If operand push to stack
2. If operator pop two operands and compute the result, result goes back to stack
3. repeat until empty, last item on stack is the result

2 3 * 5 4 * + 9 -   Stack
6 5 4 * + 9 -        
6 20 + 9 -
26 9 -
17

2 3 * 5 4 * + 9 -   
postfix[i]          Stack           Compute
2                   2
3                   3 2
*                   6               2 * 3 = 6
5                   5 6
4                   4 5 6
*                   20 6            5 * 4 = 20
+                   26              6 + 20 = 26
9                   9 26    
-                   17              26 - 9 = 17

*/

int operator_precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
                return 1;
        case '*':
        case '/': 
                return 2;
    }
    return -1;
}

int higher_precedence(char old_op, char new_op) {
    return operator_precedence(old_op) >= operator_precedence(new_op) ? 1 : 0;
}

char* infix_to_postfix(char *str) {
    
    char *postfix;
    Stack S; 
    int i, j;

    postfix = (char*)malloc((strlen(str)+1) * sizeof(char));
    init_stack(&S);
    j = 0;

    for (i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            postfix[j++] = str[i];        
        } else {
            while (!is_empty(S) && higher_precedence(top(S), str[i])) { 
                postfix[j++] = top(S);
                pop(&S);
            }
            push(&S, str[i]);
        }
    }

    while (!is_empty(S)) {
        postfix[j++] = top(S);
        pop(&S);
    }

    postfix[j] = '\0';
    return postfix;
}

int evaluate_postfix(char *postfix) {
    Stack S;
    init_stack(&S);
    int i, operand_1, operand_2, result;
    for (i = 0; i < strlen(postfix); i++) {
        if(isdigit(postfix[i])) {
            push(&S, postfix[i] - '0'); // char to int
        } else {
            operand_2 = top(S);
            pop(&S);
            operand_1 = top(S);
            pop(&S);
            switch (postfix[i]) {
                case '+':
                    result = operand_1 + operand_2;
                    break;
                case '-':
                    result = operand_1 - operand_2;
                    break;
                case '*':
                    result = operand_1 * operand_2;
                    break;
                case '/':
                    result = operand_1 / operand_2;
                    break;
                default: 
                    break;
            }
            push(&S, result);
        }
    }

    return top(S);
}


int main() {
    char infix[] = "2*3+5*4-9";
    char *postfix = infix_to_postfix(infix);
    int result = evaluate_postfix(postfix);

    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", result);

    free(postfix);
    return 0;
}