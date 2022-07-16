#include "../include/io.h"

#include "../include/helper.h"
#include "../include/mystring.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <float.h>

// Returns an integer within [min, max] range. Returns (max+1) if error happens.
i32 input_int(char *prompt, i32 min, i32 max)
{
    i32 buf_length = 1024;
    char buf[buf_length];
    b8 error = FALSE;
    i32 result = 0;
    char **string_part = NULL;

    do
    {
        printf("%s[%d <-> %d]: ", prompt, min, max);
        fflush(stdin);
        fflush(stdout);
        if (fgets(buf, 1024, stdin) == NULL)
        {
            error = TRUE;
            continue;
        }
        trimSpace(buf);
        result = strtol(buf, string_part, 10);
        if (string_part != NULL && *string_part == buf)
        {
            error = TRUE;
            printf("error\n");
        }
    } while (error == TRUE || result < min || result > max);
    return result;
}

// Returns a double within [min, max] range. Returns (max+1) if error happens.
f64 input_dbl(char *prompt, f64 min, f64 max)
{
    i32 buf_length = 1024;
    char buf[buf_length];
    b8 error = FALSE;
    f64 result = 0.0;

    init_char(buf, 1024, 0);

    do
    {
        fflush(stdin);
        fflush(stdout);
        printf("%s[%g <-> %g]: ", prompt, min, max);
        if (fgets(buf, 1024, stdin) == NULL)
        {
            error = TRUE;
            continue;
        }
        trimSpace(buf);
        result = strtod(buf, NULL);
    } while (error == TRUE || result < min || result > max);
    return result;
}
