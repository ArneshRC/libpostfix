#include "stacks.h"

OperatorStackNode* new_OperatorStackNode(Symbol* symbol) {
    OperatorStackNode* node = malloc( sizeof(OperatorStackNode) );
    node->symbol = symbol;
    node->next = NULL;
    return node;
}

OperatorStack operator_stack = { .top = NULL };

bool operator_stack_is_empty() {
    return operator_stack.top == NULL;
}

void operator_stack_push(Symbol* symbol) {
    OperatorStackNode* node = new_OperatorStackNode(symbol);
    if(operator_stack_is_empty()) {
        operator_stack.top = node;
        return;
    }
    node->next = operator_stack.top;
    operator_stack.top = node;
}

Symbol* operator_stack_pop() {
    OperatorStackNode* top = operator_stack.top;
    Symbol* symbol = top->symbol;
    operator_stack.top = top->next;
    free(top);
    return symbol;
}

Symbol* operator_stack_peek() {
    return operator_stack.top->symbol;
}

EvaluationStackNode* new_evaluationStackNode(long double number) {
    EvaluationStackNode* node = malloc( sizeof(EvaluationStackNode) );
    node->number = number;
    node->next = NULL;
    return node;
}

EvaluationStack evaluation_stack = { .top = NULL };

bool evaluation_stack_is_empty() {
    return evaluation_stack.top == NULL;
}

void evaluation_stack_push(long double number) {
    EvaluationStackNode* node = new_evaluationStackNode(number);
    if(evaluation_stack_is_empty()) {
        evaluation_stack.top = node;
        return;
    }
    node->next = evaluation_stack.top;
    evaluation_stack.top = node;
}

long double evaluation_stack_pop() {
    EvaluationStackNode* top = evaluation_stack.top;
    long double number = top->number;
    evaluation_stack.top = top->next;
    free(top);
    return number;
}

long double evaluation_stack_peek() {
    return evaluation_stack.top->number;
}

