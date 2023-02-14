#include "varmap.h"

VarMap* new_VarMap() {
    VarMap* var_map = malloc( sizeof(VarMap) );
    return var_map;
}

unsigned int var_get_key(char var_name) {
    return (unsigned int) toupper(var_name) - 'A';
}

bool var_map_has(VarMap* var_map, char var_name) {
    return var_map->exists[ var_get_key(var_name) ];
}

long int var_map_get(VarMap* var_map, char var_name) {
    assert_var_name_valid(var_name);
    return var_map->data[ var_get_key(var_name) ];
}

void var_map_set(VarMap* var_map, char var_name, long int value) {
    assert_var_name_valid(var_name);
    var_map->data[ var_get_key(var_name) ] = value;
    var_map->exists[ var_get_key(var_name) ] = true;
}

bool expression_has_vars(Expression* expression) {

    for(ExpressionNode* node = expression->head;
        node != NULL;
        node = node->next) {

        if(node->symbol->type == VARIABLE)
            return true;

    }

    return false;

}

