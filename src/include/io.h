#pragma once

#include "defines.h"

// \return an i32 within [min, max] range. Returns (max+1) if error happens.
i32 input_i32(char *prompt, i32 min, i32 max);

// \return an f64 within [min, max] range. Returns (max+1) if error happens.
f64 input_f64(char *prompt, f64 min, f64 max);