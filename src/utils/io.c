#include "../include/io.h"

// Returns an integer within [min, max] range. Returns (max+1) if error happens.
int input_int(char *prompt, int min, int max)
{
    char buf[1024];
    bool error = false;
    long int result = 0;
    char **string_part = NULL;

    do
    {
        printf("%s[%d <-> %d]: ", prompt, min, max);
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

double input_dbl(char *prompt, double min, double max)
{
    char buf[1024];
    bool error = false;
    double result = 0.0;

    init_char(buf, 1024, 0);

    do
    {
        fflush(stdin);
        fflush(stdout);
        printf("%s[%g <-> %g]: ", prompt, min, max);
        if (fgets(buf, 1024, stdin) == NULL)
        {
            error = true;
            continue;
        }
        trimSpace(buf);
        result = strtod(buf, NULL);
    } while (error == true || result < min || result > max);
    return result;
}
