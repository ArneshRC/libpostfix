#include "util.h"

bool str_is_empty(char* str) {
    return str[0] == '\0';
}

unsigned int count_spaces(char* str) {

    unsigned int count = 0;
    
    while(*str != '\0') {
        if(isspace(*str)) count++;
        str++;
    }

    return count;

}

char* remove_spaces(char* str) {

    if(str[strcspn(str, " ")] == '\0')
        return str;

    char* trimmed_str = malloc(
        (strlen(str) - count_spaces(str)) *
        sizeof(char)
    );

    char* ch = str;
    char* trimmed_ch = trimmed_str;

    while(*ch != '\0') {
        if(!isspace(*ch)) {
            *trimmed_ch = *ch;
            trimmed_ch++;
        }
        ch++;
    }

    *trimmed_ch = '\0';

    free(str);

    return trimmed_str;

}

