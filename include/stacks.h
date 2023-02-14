#ifndef _STACKS_H
#define _STACKS_H 1

#include <stdlib.h>
#include <stdbool.h>

#include "symbol.h"

/// ===================================
/// Operator Stack
/// 
/// Used to temporarily store operators
/// during converstion from infix
/// to postfix expression
/// ===================================

/**
 * Representation of an
 * operator stack node
 */
typedef struct OperatorStackNode {
    // Symbol contained in the node
    Symbol* symbol;
    // Reference to the next node
    struct OperatorStackNode* next;
} OperatorStackNode;

OperatorStackNode* new_OperatorStackNode(Symbol* symbol);

/**
 * Representation of
 * the operator stack
 */
typedef struct {
    // Reference to the top of the stack
    OperatorStackNode* top;
} OperatorStack;

/**
 * Pushes a value onto the
 * global operator stack
 */
void operator_stack_push(Symbol* symbol);

/**
 * Returns whether the global
 * operator stack is empty
 */
bool operator_stack_is_empty();

/**
 * Pops a value from the
 * global operator stack
 */
Symbol* operator_stack_pop();

/**
 * Returns the value on top of 
 * the global operator stack
 */
Symbol* operator_stack_peek();

/// =========================
/// Evaluation Stack
///
/// Used to temporarily store
/// numbers during evaluation
/// of a postfix expression
/// =========================

/**
 * Representation of an
 * evaluation stack node
 */
typedef struct EvaluationStackNode {
    // Number contained in the node
    long double number;
    // Reference to the next node
    struct EvaluationStackNode* next;
} EvaluationStackNode;

EvaluationStackNode* new_EvaluationStackNode(long double number);

/**
 * Representation of the
 * evaluation stack
 */
typedef struct {
    // Reference to the top of the stack
    EvaluationStackNode* top;
} EvaluationStack;

/**
 * Pushes a value onto the
 * global evaluation stack
 */
void evaluation_stack_push(long double number);

/**
 * Returns whether the global
 * evaluation stack is empty
 */
bool evaluation_stack_is_empty();

/**
 * Pops a value from the
 * global evaluation stack
 */
long double evaluation_stack_pop();

/**
 * Returns the value on top of 
 * the global evaluation stack
 */
long double evaluation_stack_peek();

#endif
