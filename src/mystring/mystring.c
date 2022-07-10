#include "../include/mystring.h"

MyString new_string(const char *literal)
{
    int req_len = strlen(literal);
    int req_cap = req_len * 2;
    MyString temp;
    temp.data = (char *)malloc(req_cap * sizeof(char));
    temp.len = req_len;
    temp.cap = req_cap;
    memcpy(temp.data, literal, req_len);
    return temp;
}

// Trims the trailing whitespace characters. Returns the filtered string.
char *trimSpace(char *str)
{
    size_t len = 0;
    char *frontp = str;
    char *endp = NULL;

    if (str == NULL)
    {
        return NULL;
    }
    if (str[0] == '\0')
    {
        return str;
    }

    len = strlen(str);
    endp = str + len;

    /* Move the front and back pointers to address the first non-whitespace
     * characters from each end.
     */
    while (isspace((unsigned char)*frontp))
    {
        ++frontp;
    }
    if (endp != frontp)
    {
        while (isspace((unsigned char)*(--endp)) && endp != frontp)
        {
        }
    }

    if (frontp != str && endp == frontp)
        *str = '\0';
    else if (str + len - 1 != endp)
        *(endp + 1) = '\0';

    /* Shift the string so that it starts at str so that if it's dynamically
     * allocated, we can still free it on the returned pointer.  Note the reuse
     * of endp to mean the front of the string buffer now.
     */
    endp = str;
    if (frontp != str)
    {
        while (*frontp)
        {
            *endp++ = *frontp++;
        }
        *endp = '\0';
    }

    return str;
}

void print_string(MyString *s)
{
    printf("%s\n", s->data);
}