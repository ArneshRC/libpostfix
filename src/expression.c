#include "expression.h"

ExpressionNode* new_ExpressionNode(Symbol* symbol) {

    ExpressionNode* node = malloc( sizeof(ExpressionNode) );

    node->symbol = symbol;
    node->next = NULL;

    return node;

}

Expression* new_Expression(ExpressionType type) {

    Expression* expression = malloc( sizeof(Expression) );

    expression->type = type;
    expression->length = 0;
    expression->head = NULL;
    expression->last = NULL;

    return expression;
}

void expression_append(Expression* expression, Symbol* symbol) {

    if(expression->head == NULL) {
        expression->head = new_ExpressionNode(symbol);
        expression->last = expression->head;
        return;
    }

    expression->last->next = new_ExpressionNode(symbol);
    expression->last = expression->last->next;

    expression->length++;

}

