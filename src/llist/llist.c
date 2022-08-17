#include "../include/llist.h"
#include "../include/mystring.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LList llist_new() {
  LList temp;
  temp.head = NULL;
  temp.tail = NULL;
  temp.len = 0;
  return temp;
}

// Internal function for newly allocated node.
LNode *lnode_new(Object src) {
  void *data = calloc(1, src.size);
  memcpy(data, src.data, src.size);
  LNode *temp = (LNode *)calloc(1, sizeof(LNode));
  temp->core.data = data;
  temp->core.size = src.size;
  temp->next = NULL;
  temp->print_node = NULL;
  return temp;
}

// Internal function for deleting and freeing a node.
void lnode_free(LNode *self) {
  if (self != NULL) {
    if (self->core.data != NULL) {
      free(self->core.data);
      self->core.data = NULL;
    }
    free(self);
    self = NULL;
  }
}

LNode *llist_getnode(LList *self, u32 index) {
  if (self->head == NULL) {
    printf("llist empty");
    exit(EXIT_FAILURE);
  }
  if (index >= self->len || index < 0) {
    printf("invalid access of llist");
    exit(EXIT_FAILURE);
  }
  LNode *iter = self->head;
  for (u32 i = 0; i < index; i++) {
    iter = iter->next;
  }
  return iter;
}

u32 llist_append(LList *self, Object src) {
  LNode *temp = lnode_new(src);

  // Exit if allocation failed
  if (temp == NULL) {
    exit(EXIT_FAILURE);
  }

  // if list is uninitialized
  if (self->head == NULL) {
    self->head = temp;
    self->tail = temp;
  } else {
    self->tail->next = temp;
    self->tail = temp;
  }
  self->ctx = temp;
  self->len += 1;
  return self->len;
}

u32 llist_prepend(LList *self, Object src) {
  LNode *temp = lnode_new(src);

  // Exit if allocation failed
  if (temp == NULL) {
    exit(EXIT_FAILURE);
  }
  // if list is uninitialized
  if (self->head == NULL) {
    self->head = temp;
    self->tail = temp;
  } else {
    temp->next = self->head;
    self->head = temp;
  }
  self->ctx = temp;
  self->len += 1;
  return self->len;
}

u32 llist_insert(LList *self, u32 index, Object src) {
  if (index >= self->len || index < 0) {
    printf("invalid access, %s:%d", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  } else if (index == 0) {
    return llist_prepend(self, src);
  } else {
    LNode *temp = lnode_new(src);
    // Exit if allocation failed
    if (temp == NULL) {
      exit(EXIT_FAILURE);
    }

    // if list is uninitialized
    if (self->head == NULL) {
      self->head = temp;
      self->tail = temp;
      // TODO log that the given index is not valid as list is uninitialized
      self->len += 1;
      return self->len;
    }
    LNode *prev = llist_getnode(self, index - 1);
    temp->next = prev->next;
    prev->next = temp;
    self->ctx = temp;
    self->len += 1;
  }
  return self->len;
}

u32 llist_delete(LList *self, u32 index) {
  LNode *prev = llist_getnode(self, index - 1);
  LNode *del = prev->next;
  prev->next = del->next;
  lnode_free(del);
  self->ctx = NULL;
  self->len -= 1;
  return self->len;
}

Object llist_get(LList *self, u32 index) { return llist_getnode(self, index)->core; }

void llist_set(LList *self, u32 index, Object src) {
  LNode *dst = llist_getnode(self, index);
  if (dst->core.size != src.size) {
    fprintf(stderr, "Node size not compatible");
    exit(EXIT_FAILURE);
  }
  memcpy(dst->core.data, src.data, src.size);
}

u32 llist_search(LList *self, Object src, i32 (*compare)(void *data, void *data_src)) {
  if (self->head == NULL) {
    printf("llist empty");
    exit(EXIT_FAILURE);
  }
  u32 i = 0;
  for (LNode *iter = self->head; iter != NULL; iter = iter->next) {
    if (compare(iter->core.data, src.data) == 0) {
      self->ctx = iter;
      return i;
    }
    i += 1;
  }
  return -1;
}

void llist_free(LList *self) {
  if (self->head != NULL) {
    LNode *temp2 = self->head;
    for (LNode *temp1 = self->head; temp1 != NULL; temp1 = temp2) {
      temp2 = temp2->next;
      lnode_free(temp1);
    }
    self->head = NULL;
    self->tail = NULL;
    self->ctx = NULL;
    self->len = 0;
  }
}

// -------------------------------------------PRINTING UTILITY------------------------------------------

void llist_display(const LList *self) {
  printf("{");
  if (self->head != NULL) {
    for (LNode *iter = self->head; iter != NULL; iter = iter->next) {
      if (iter->print_node != NULL) {
        iter->print_node(iter->core.data);
      } else if (self->print_node_default != NULL) {
        self->print_node_default(iter->core.data);
      } else {
        printf("no printing funtion found\n");
        return;
      }
      if (iter->next != NULL) {
        printf(" -> ");
      }
    }
  }
  printf("}\n");
}
void llist_display_dbg(const LList *self) {
  printf("[head: %p, tail: %p, len: %d, ", self->head, self->tail, self->len);
  printf("{");
  if (self->head != NULL) {
    u32 i = 0;
    for (LNode *iter = self->head; iter != NULL; iter = iter->next) {
      printf("(%d): ", i);
      // Checking if node-specific printing func exist.
      if (iter->print_node != NULL) {
        iter->print_node(iter->core.data);
      } else if (self->print_node_default != NULL) {
        // if no node-specific found, then trying default
        self->print_node_default(iter->core.data);
      } else {
        printf("no printing funtion found\n");
        return;
      }
      if (iter->next != NULL) {
        printf(" -> ");
      }
      i += 1;
    }
  }
  printf("}]\n");
}

void lnode_print_func(LList *self, void (*handler)(void *data)) {
  if (self->head != NULL && self->ctx != NULL) {
    self->ctx->print_node = handler;
  }
}
void llist_default_print_func(LList *self, void (*handler)(void *data)) { self->print_node_default = handler; }