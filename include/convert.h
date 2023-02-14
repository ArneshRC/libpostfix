#ifndef _CONVERT_H
#define _CONVERT_H 1

#include <stdlib.h>
#include <string.h>

#include "expression.h"
#include "stacks.h"

/**
 * Converts a given expression
 * into a new string
 */
char* expression_to_string(Expression* expression);

/**
 * Converts a given infix expression
 * into a new postfix expression
 */
Expression* infix_to_postfix(Expression* infix);

#endif

