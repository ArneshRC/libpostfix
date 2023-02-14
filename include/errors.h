#ifndef _ERRORS_H
#define _ERRORS_H 1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define assert_var_name_valid(var_name) \
    abort_if_not(isalpha(var_name), "[varmap] Error: Variable name is invalid!")

#define assert_var_map_exists(var_map) \
    abort_if_not(var_map != NULL, "[evaluate] Error: No vars were provided!")

#define assert_var_map_has_var(var_map, var) \
    abort_if_not(var_map_has(var_map, var), "[evaluate] Error: Some vars were not provided!")

#define assert_input_not_empty(infix_str) \
    abort_if_not(!str_is_empty(infix_str), "[infix_input] Error: Input cannot be empty!")

/**
 * Aborts the program with an error message
 * if the given condition is true
 */
void abort_if_not(bool condition, const char* message);

#endif

