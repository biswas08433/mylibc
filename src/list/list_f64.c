#include "../include/list_f64.h"
#include "../include/helper.h"
#include "../include/strconv.h"

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

List_f64 list_new_f64(u32 capacity) {
  List_f64 temp_slice;
  temp_slice.length = 0;
  temp_slice.capacity = capacity;
  temp_slice.w_perm = TRUE;
  temp_slice.arr = (f64 *)malloc(temp_slice.capacity * sizeof(f64));
  init_f64(temp_slice.arr, capacity, 0);

  return temp_slice;
}

// Returns a copy list from another self.
List_f64 list_copy_f64(List_f64 from) {
  List_f64 temp_slice = list_new_f64(from.capacity);
  temp_slice.length = from.length;
  copy_f64(from.arr, temp_slice.arr, from.length);
  return temp_slice;
}

// Creates a new list from existing list. The underlying array will be shared.
// w_perm set the write permission.
// range -> [start,end)
List_f64 list_from_f64(List_f64 *self, u32 start, u32 end, b8 w_perm) {
  List_f64 new_slice;
  new_slice.length = end - start;
  new_slice.capacity = w_perm ? self->capacity - start : 0;
  new_slice.w_perm = w_perm;
  new_slice.arr = self->arr + start;

  return new_slice;
}

// Creates a new list from existing self. The underlying array will be newly
// allocated.
// range -> [start,end)
List_f64 list_new_from_f64(List_f64 *self, u32 start, u32 end) {
  List_f64 new_slice;
  new_slice.length = end - start;
  new_slice.capacity = new_slice.length * 2;
  new_slice.w_perm = TRUE;
  new_slice.arr = (f64 *)malloc(new_slice.capacity * sizeof(f64));

  if (new_slice.arr == NULL) {
    return new_slice;
    fprintf(stderr, "allocation failed!");
  }
  copy_f64(self->arr + start, new_slice.arr, new_slice.length);
  return new_slice;
}

// Append an element to the list. Returns the updated length or -1 if error.
u32 list_append_f64(List_f64 *self, f64 data) {
  if (list_update_cap_f64(self, FALSE) == -1) {
    return -1;
  }
  if (self->w_perm == TRUE) {
    self->arr[self->length] = data;
    self->length += 1;
    return self->length;
  } else {
    fprintf(stderr, "Write denied!\n");
    exit(EXIT_FAILURE);
  }
}

// Insert data into given index. Returns the updated length or -1 if error.
u32 list_insert_f64(List_f64 *self, f64 data, u32 index) {
  if (list_update_cap_f64(self, FALSE) == -1) {
    return -1;
  }
  if (self->w_perm == TRUE) {
    for (u32 i = self->length - 1; i > index; i -= 1) {
      self->arr[i + 1] = self->arr[i];
    }
    self->arr[index] = data;
    self->length += 1;
    return self->length;
  } else {
    fprintf(stderr, "Write denied!\n");
    exit(EXIT_FAILURE);
  }
}

// Deletes the data at given index. Returns the updated length.
u32 list_delete_f64(List_f64 *self, u32 index) {
  if (self->w_perm == TRUE) {
    for (u32 i = index; i < self->length + 1; i += 1) {
      self->arr[i] = self->arr[i + 1];
    }
    self->length -= 1;
    list_update_cap_f64(self, TRUE);
    return self->length;
  } else {
    fprintf(stderr, "Write denied!\n");
    exit(EXIT_FAILURE);
  }
}

// Searches for the data. Returns -1 if not found.
u32 list_search_f64(List_f64 *self, f64 value) {
  for (u32 i = 0; i < self->length; i++) {
    if (fabs(self->arr[i] - value) < DBL_EPSILON) {
      return i;
    }
  }
  return -1;
}

// TODO: NOT IMPLEMENTED
u32 list_bsearch_f64(List_f64 *self, f64 value) {
  // NOT IMPLEMENTED
  return 0;
}

// Returns the maximum element from the self.
f64 list_max_f64(List_f64 *self) {
  f64 t = DBL_MIN;
  for (u32 i = 0; i < self->length; i++) {
    if (self->arr[i] - t > DBL_EPSILON) {
      t = self->arr[i];
    }
  }
  return t;
}
// Returns the minimum element from the self.
f64 list_min_f64(List_f64 *self) {
  f64 t = DBL_MAX;
  for (u32 i = 0; i < self->length; i++) {
    if (self->arr[i] - t < DBL_EPSILON) {
      t = self->arr[i];
    }
  }
  return t;
}

// Display the list.
void list_display_f64(List_f64 *self) {
  u32 length = self->length;
  f64 *arr = self->arr;

  printf("[");
  for (u32 i = 0; i < length; i++) {
    printf("%.15g", arr[i]);
    if (i != length - 1) printf(" ");
  }
  printf("]\n");
}
// Display the list with debug info.
void list_display_dbg_f64(List_f64 *self) {
  u32 length = self->length;
  f64 *arr = self->arr;

  printf("{len: %d, cap: %d, w_perm: %s, [", length, self->capacity,
         bool_str(self->w_perm));

  for (u32 i = 0; i < length; i++) {
    printf("%.15g", arr[i]);
    if (i != length - 1) printf(" ");
  }
  printf("]}\n");
}

// Gets the element by the given index.
f64 list_get_f64(List_f64 *self, u32 index) {
  if (index < self->length) {
    return self->arr[index];
  } else {
    printf("Accessing invalid index %d", index);
    exit(EXIT_FAILURE);
  }
}
// Sets the element by the given index.
void list_set_f64(List_f64 *self, f64 value, u32 index) {
  if (index < self->length) {
    self->arr[index] = value;
  } else {
    printf("Accessing invalid index %d", index);
    exit(EXIT_FAILURE);
  }
}

// \return the length of the list.
u32 list_len_f64(List_f64 *self) { return self->length; }
// \return the capacity of the list.
u32 list_cap_f64(List_f64 *self) { return self->capacity; }

// Frees the self's underlying array.
// Only delete the original list i.e. the list containing the starting pof64er.
void list_free_f64(List_f64 *self) {
  if (self->w_perm == TRUE) {
    free(self->arr);
    self->arr = NULL;
  } else {
    fprintf(stderr, "Write denied!");
    exit(EXIT_FAILURE);
  }
}

// Updates the capacity when needed.
// \return FALSE if there is error in allocation. TRUE otherwise.
b8 list_update_cap_f64(List_f64 *self, b8 can_shrink) {
  if (self->length == self->capacity && self->w_perm == TRUE) {
    self->capacity *= 2;
  } else if (self->length <= (self->capacity / 2) && self->w_perm == TRUE &&
             can_shrink) {
    self->capacity /= 2;
  }
  self->arr = (f64 *)realloc(self->arr, self->capacity * sizeof(f64));
  if (self->arr == NULL) {
    return FALSE;
  }
  return TRUE;
}