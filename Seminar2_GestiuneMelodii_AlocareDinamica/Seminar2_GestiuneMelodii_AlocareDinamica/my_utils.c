#pragma once
#include <assert.h>
#include <string.h>
#include <stdlib.h>
void trimTrailing(char* str)
{
    int index, i;

    /* Set default index */
    index = -1;

    /* Find last index of non-white space character */
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            index = i;
        }

        i++;
    }

    /* Mark next character to last non-white space character as NULL */
    str[index + 1] = '\0';
}


void testTrim(){
    char* t1 = malloc(5*sizeof(char));
    strcpy(t1, "abcd");
    trimTrailing(t1);
    assert(strcmp(t1, "abcd") == 0);
    free(t1);

    char* t2 = malloc(9*sizeof(char));
    strcpy(t2, "abcd    ");
    trimTrailing(t2);
    assert(strcmp(t2, "abcd") == 0);
    free(t2);

    char* t3 = malloc(8*sizeof(char));
    strcpy(t3, "abcd\n \n");
    trimTrailing(t3);
    assert(strcmp(t3, "abcd") == 0);
    free(t3);
}
