#include <stdio.h>
#include <string.h>
#include "stack.h"

/*
#define MAX 10
typedef struct {
    int data[MAX];
    int top;
} Stack;

Solution:
1. scan from left to right
2. if char is opening symbol, push to stack
3. if char is closing symbol, pop stack and compare if it is valid
4. stack should be empty if string is valid
*/

int is_valid_pair(char a, char b) {
    if (a == '[' && b == ']') {
        return 1;
    } else if (a == '(' && b == ')') {
        return 1;
    } else if (a == '{' && b == '}') {
        return 1;
    }
    return 0;
}

int valid_parentheses(char *str) {
    Stack S;
    stack_init(&S);
    
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == '[' || str[i] == '(' || str[i] == '{') {
            stack_push(&S, str[i]);
        } else if(str[i] == ']' || str[i] == ')' || str[i] == '}') {
            if (stack_is_empty(S) && !is_valid_pair(stack_top(S), str[i])) {
                return 0;
            } else {
                stack_pop(&S);
            }
        }
    }
    
    return stack_is_empty(S) == 1 ? 1 : 0;
}


int main() {

    char str[] = "{[[]()]}";
    printf("is %s a valid parentheses: %s", str, valid_parentheses(str) ? "TRUE": "FALSE");
    return 0;
}