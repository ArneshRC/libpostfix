#include "operations.h"

Expression* parse(char* expression_str, ExpressionType type) {

    Expression* expression = new_Expression(type);

    expression_str = remove_spaces(expression_str);

    while(*expression_str != '\0') {

        // Declare a new symbol to
        // be initialized later
        Symbol* symbol;

        // Allocate a new buffer to
        // store the symbol content
        char* buffer = malloc(
            EXPRESSION_BUFSIZE
            * sizeof(char)
        );

        // If the current character in
        // the input string is a digit
        if(isdigit(*expression_str)) {

            int buffer_index;

            // Loop through all subsequent characters that
            // are digits and store them in the buffer
            for(buffer_index = 0;
                isdigit( *(expression_str + buffer_index) );
                buffer_index++) {

                buffer[buffer_index] = *(expression_str + buffer_index);
            }

            // Null-terminate the buffer
            buffer[buffer_index] = '\0';

            // Initialize the symbol with the buffer,
            // and set its type to NUMBER
            symbol = new_Symbol(buffer, NUMBER);

            // Skip to the very next token
            // (the next `buffer_index` characters
            // are all digits, and have all been
            // accounted for)
            expression_str += buffer_index;

        }

        // Both variables and operators
        // are one-character symbols
        else {

            buffer[0] = *expression_str;
            buffer[1] = '\0';

            symbol = new_Symbol(
                buffer,
                isalpha(*expression_str)
                ?   VARIABLE
                :   OPERATOR
            );

            expression_str++;

        }

        // Finally, append this new symbol
        // to the expression expression
        expression_append(expression, symbol);

    }

    return expression;

}

long double evaluate(Expression* expression, VarMap* var_map) {

    if(expression->type == INFIX)
        return evaluate(infix_to_postfix(expression), var_map);

    // Loop through the expression contents
    for(ExpressionNode* node = expression->head;
        node != NULL;
        node = node->next) {

        // Get the current symbol
        Symbol* symbol = node->symbol;

        // If the symbol is a variable or number,
        // simply push it to the evaluation stack
        if(symbol->type != OPERATOR) {

            if(symbol->type == VARIABLE) {

                assert_var_map_exists(var_map);

                assert_var_map_has_var(var_map, symbol->content[0]);

                evaluation_stack_push(
                    var_map_get(var_map, symbol->content[0])
                );

            } else {

                evaluation_stack_push(
                    symbol_get_numeric_value(symbol)
                );

            }

        }

        // If the symbol is an operator...
        else {
            // Pop twice to get the two immediate operands
            long double operand2 = evaluation_stack_pop();
            long double operand1 = evaluation_stack_pop();

            // An operator symbol is composed of a single character
            // so checking `content[0]` is necessary and sufficient
            switch (symbol->content[0]) {

                case '+':
                    evaluation_stack_push(operand1 + operand2);
                    break;
                case '-':
                    evaluation_stack_push(operand1 - operand2);
                    break;
                case '*':
                    evaluation_stack_push(operand1 * operand2);
                    break;
                case '/':
                    evaluation_stack_push(operand1 / operand2);
                    break;
                case '^': {
                    evaluation_stack_push(
                        (long double)pow(operand1, operand2)
                    );
                    break;
                }

            }
        }
    }

    // Pop the final result and return it
    return evaluation_stack_pop();

}

