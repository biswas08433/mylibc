#include "../include/mystring.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

String new_string(const char* literal) {
    String temp;

    u32 len = strlen(literal);
    u32 cap = len * 2;

    temp.data = (char*)malloc(cap * sizeof(char));
    temp.len = len;
    temp.cap = cap;

    memcpy(temp.data, literal, len);
    return temp;
}

// Trims the trailing whitespace characters. Returns the filtered string.
void trimSpace(String* self) {
    size_t len = 0;
    char* frontp = self->data;
    char* endp = NULL;

    if (frontp == NULL) {
        return;
    }
    if (self->data[0] == '\0') {
        return;
    }

    len = self->len;
    endp = self->data + len;

    /* Move the front and back pointers to address the first non-whitespace
     * characters from each end.
     */
    while (isspace((unsigned char)*frontp)) {
        ++frontp;
    }
    if (endp != frontp) {
        while (isspace((unsigned char)*(--endp)) && endp != frontp) {
        }
    }

    if (frontp != self->data && endp == frontp)
        *(self->data) = '\0';
    else if (self->data + len - 1 != endp)
        *(endp + 1) = '\0';

    /* Shift the string so that it starts at str so that if it's dynamically
     * allocated, we can still free it on the returned pointer.  Note the reuse
     * of endp to mean the front of the string buffer now.
     */
    endp = self->data;
    if (frontp != self->data) {
        while (*frontp) {
            *endp++ = *frontp++;
        }
        *endp = '\0';
    }

    return;
}