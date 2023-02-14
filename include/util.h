#ifndef _UTIL_H
#define _UTIL_H 1

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "errors.h"

/**
 * Returns whether the
 * given string is empty
 */
bool str_is_empty(char* str);

/**
 * Returns the number of
 * spaces in the given string
 */
unsigned int count_spaces(char* str);

/**
 * Removes all spaces
 * from the given string
 */
char* remove_spaces(char* str);

#endif

