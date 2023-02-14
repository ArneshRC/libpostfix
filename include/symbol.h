#ifndef _SYMBOL_H
#define _SYMBOL_H 1

#include <stdlib.h>
#include <stdbool.h>

/// ============================
/// Symbol
///
/// A discrete token which forms
/// a part of an expression
/// ============================

/**
 * Type of the symbol
 */
typedef enum {
    OPERATOR,
    VARIABLE,
    NUMBER
} SymbolType;

/**
 * Representation of the symbol
 */
typedef struct {
    // Type of the symbol
    SymbolType type;
    // Content of the symbol
    char* content;
} Symbol;

/**
 * Creates a new symbol, given type and content
 */
Symbol* new_Symbol(char* content, SymbolType type);

/**
 * Compares the content of a symbol with a given operator
 */
bool symbol_is(Symbol* symbol, char expression_operator);

/**
 * Gets the numeric value contained in the symbol
 */
long int symbol_get_numeric_value(Symbol* symbol);

/**
 * Returns the precedence of a supplied
 * operator as per the general convention
 */
unsigned int precedence(Symbol* symbol);

#endif

