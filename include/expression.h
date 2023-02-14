#ifndef _EXPRESSION_H
#define _EXPRESSION_H 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbol.h"
#include "util.h"

#define EXPRESSION_BUFSIZE 10

/// =======================
/// Expression
///
/// A collection of symbols
/// (operators and numbers)
/// =======================

/**
 * Represents a single
 * term of the expression
 */
typedef struct ExpressionNode {
    // The symbol contained in the term
    Symbol* symbol;
    // Reference to the next term
    struct ExpressionNode* next;
} ExpressionNode;

/**
 * Creates a new expression node
 */
ExpressionNode* new_ExpressionNode(Symbol* symbol);

/**
 * Type of the expression
 */
typedef enum {
    INFIX,
    POSTFIX
} ExpressionType;

/**
 * Representation of the expression
 */
typedef struct {
    // Type of the expression
    ExpressionType type;
    // Length of the expression
    unsigned int length;
    // Reference to the first term
    ExpressionNode* head;
    // Reference to the last term
    ExpressionNode* last;
} Expression;

Expression* new_Expression(ExpressionType type);

void expression_append(Expression* expression, Symbol* symbol);

#endif
