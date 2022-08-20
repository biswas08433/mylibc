#include "../include/llist.h"
#include "../include/helper.h"

u32 llist_append_i32(LList* self, i32 data) {
    u32 len = llist_append(self, (Object){&data, sizeof(i32), I32});
    lnode_ctx_print_func(self, print_i32);
    return len;
}