#ifndef _OPERATIONS_H
#define _OPERATIONS_H 1

#include <math.h>

#include "symbol.h"
#include "expression.h"
#include "stacks.h"
#include "convert.h"
#include "varmap.h"

/** 
 * Parses a string to an expression
 */
Expression* parse(char* expression_str, ExpressionType type);

/** 
 * Evaluates a given postfix expression
 */
long double evaluate(Expression* expression, VarMap* var_map);

#endif

