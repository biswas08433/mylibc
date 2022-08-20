#include "../include/llist.h"
#include "../include/helper.h"

u32 llist_append_f64(LList* self, f64 data) {
    u32 len = llist_append(self, (Object){&data, sizeof(f64), F64});
    lnode_ctx_print_func(self, print_f64);
    return len;
}