#ifndef _VARS_H
#define _VARS_H 1

#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

#include "errors.h"
#include "expression.h"

/**
 * Representation of the VarMap
 */
typedef struct {
    long int data[26];
    bool exists[26];
} VarMap;

/**
 * Creates a new VarMap
 */
VarMap* new_VarMap();

/**
 * Returns the key corresponding to a variable
 * name, which can index the VarMap array
 */
unsigned int var_get_key(char var_name);

/**
 * Returns whether the given variable name
 * is contained in the given VarMap
 */
bool var_map_has(VarMap* var_map, char var_name);

/**
 * Returns the value corresponding to a variable
 * name as contained in the given VarMap
 */
long int var_map_get(VarMap* var_map, char var_name);

/**
 * Sets the value of a given variable in the given var_map
 */
void var_map_set(VarMap* var_map, char var_name, long int value);

/**
 * Returns whether a given expression has variables
 */
bool expression_has_vars(Expression* expression);

#endif

