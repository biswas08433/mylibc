#pragma once

#include "defines.h"

// Returns an integer within [min, max] range. Returns (max+1) if error happens.
i32 input_int(char *prompt, i32 min, i32 max);

// Returns a double within [min, max] range. Returns (max+1) if error happens.
f64 input_double(char *prompt, f64 min, f64 max);