#include "convert.h"

char* expression_to_string(Expression* expression) {

    char* buffer = calloc(
        expression->length *
        EXPRESSION_BUFSIZE,
        sizeof(char)
    );

    strcat(buffer, expression->head->symbol->content);

    for(ExpressionNode* node = expression->head->next;
        node != NULL;
        node = node->next) {
        strcat(buffer, " ");
        strcat(buffer, node->symbol->content);
    }

    return buffer;
}

Expression* infix_to_postfix(Expression* infix) {

    // Create a new expression
    Expression* postfix = new_Expression(POSTFIX);

    // Loop through the expression contents
    for(ExpressionNode* node = infix->head;
        node != NULL;
        node = node->next) {

        // Get the current symbol
        Symbol* symbol = node->symbol;
        
        // 1. If the symbol is a number or variable,
        // simply append it to the postfix expression
        if(symbol->type != OPERATOR) {

            expression_append(postfix, symbol);

        }

        // 2. If the stack is empty or the operator
        // is an opening parenthesis, push it to the
        // operator stack
        else if(operator_stack_is_empty() || symbol_is(symbol, '(')) {

            operator_stack_push(symbol);

        }

        // 3. If the symbol is a closing parenthesis,
        // keep popping the stack (and appending to
        // the postfix expression) till an opening
        // parenthesis is encountered.
        else if(symbol_is(symbol, ')')) {

            while(!symbol_is(symbol, '(')) {
                expression_append(postfix, operator_stack_pop());
                symbol = operator_stack_peek();
            }

            // Pop the remaining '(' too
            operator_stack_pop();

        }

        // 4. If the symbol has greater precedence than
        // the one on top of the operator stack, push
        // it onto the operator stack.
        else if(precedence(symbol) > precedence(operator_stack_peek())) {

            operator_stack_push(symbol);

        }

        // 5. If a symbol has less precedence than the
        // one on top of the operator stack, pop all
        // the operators from the stack until its
        // either empty or has an operator with
        // greater precdence on top.
        else {

            while (
                !operator_stack_is_empty() && 
                precedence(symbol) <= precedence(operator_stack_peek())
            ) expression_append(postfix, operator_stack_pop());


            operator_stack_push(symbol);

        }

    }

    // Pop all the remaining operators from
    // the operator stack and append them
    // to the expression
    while (!operator_stack_is_empty()) {
        expression_append(postfix, operator_stack_pop());
    }

    // Return the newly created
    // postfix expression
    return postfix;

}
