#include "../include/llist.h"
#include "../include/mystring.h"
#include "../include/helper.h"

u32 llist_append_b8(LList* self, b8 data) {
    u32 len = llist_append(self, (Object){&data, sizeof(b8), B8});
    lnode_ctx_print_func(self, print_b8);
    return len;
}
u32 llist_append_str(LList* self, String s) {
    u32 len = llist_append(self, (Object){&(s.data), sizeof(String), STRING});
    lnode_ctx_print_func(self, print_string);
    return len;
}