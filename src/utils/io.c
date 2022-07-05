#include "../include/io.h"

// Returns an integer within [min, max] range. Returns (max+1) if error happens.
long int input_int(char *prompt, int min, int max)
{
    char buf[1024];
    bool error = false;
    long int result = 0;
    char **string_part = NULL;

    do
    {
        printf("%s ", prompt);
        fflush(stdin);
        fflush(stdout);
        if (fgets(buf, 1024, stdin) == NULL)
        {
            error = true;
            continue;
        }
        trimSpace(buf);
        result = strtol(buf, string_part, 10);
        if (string_part != NULL && *string_part == buf)
        {
            error = true;
            printf("error\n");
        }
    } while (error == true || result < min || result > max);
    return result;
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