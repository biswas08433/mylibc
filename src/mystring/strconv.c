#include "../include/strconv.h"

// Returns the string version of bool value.
char *bool_str(b8 b)
{
    char *t = "TRUE";
    char *f = "FALSE";

    return b ? t : f;
}