#include "symbol.h"

Symbol* new_Symbol(char* content, SymbolType type) {

    Symbol* symbol = malloc( sizeof(Symbol) );

    symbol->type = type;
    symbol->content = content;

    return symbol;

}

bool symbol_is(Symbol* symbol, char expression_operator) {

    return (
        symbol->type == OPERATOR &&
        symbol->content[0] == expression_operator
    );

}

long int symbol_get_numeric_value(Symbol* symbol) {

    if(symbol->type == NUMBER)
        return strtod(symbol->content, NULL);
    else
        return 0;

}

unsigned int precedence(Symbol* symbol) {
    switch (symbol->content[0]) {
        case '(':
        case ')':
            return 1;
            break;
        case '+':
        case '-':
            return 2;
            break;
        case '*':
        case '/':
            return 3;
            break;
        case '^':
            return 4;
            break;
        default:
            return 0;
    }
}
