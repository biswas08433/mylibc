#include "../include/llist_f64.h"

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

LList_f64 llist_new_f64()
{
    LList_f64 temp;
    temp.head = NULL;
    temp.tail = NULL;
    temp.len = 0;
    return temp;
}

// Internal function for newly allocated node.
LNode_f64 *lnode_new_f64(f64 value)
{
    LNode_f64 *temp = (LNode_f64 *)malloc(sizeof(LNode_f64));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// Internal function for deleting and freeing a node.
void lnode_free_f64(LNode_f64 *self)
{
    if (self != NULL)
    {
        free(self);
        self = NULL;
    }
}

LNode_f64 *llist_getnode_f64(LList_f64 *self, u32 index)
{
    if (self->head == NULL)
    {
        printf("llist empty: %s:%d", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
    if (index >= self->len || index < 0)
    {
        printf("invalid access, %s:%d", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
    LNode_f64 *iter = self->head;
    for (u32 i = 0; i < index; i++)
    {
        iter = iter->next;
    }
    return iter;
}

u32 llist_append_f64(LList_f64 *self, f64 value)
{
    LNode_f64 *temp = lnode_new_f64(value);

    // Exit if allocation failed
    if (temp == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // if list is uninitialized
    if (self->head == NULL)
    {
        self->head = temp;
        self->tail = temp;
    }
    else
    {
        self->tail->next = temp;
        self->tail = temp;
    }
    self->len += 1;
    return self->len;
}

u32 llist_prepend_f64(LList_f64 *self, f64 value)
{
    LNode_f64 *temp = lnode_new_f64(value);

    // Exit if allocation failed
    if (temp == NULL)
    {
        exit(EXIT_FAILURE);
    }
    // if list is uninitialized
    if (self->head == NULL)
    {
        self->head = temp;
        self->tail = temp;
    }
    else
    {
        temp->next = self->head;
        self->head = temp;
    }
    self->len += 1;
    return self->len;
}

u32 llist_insert_f64(LList_f64 *self, u32 index, f64 value)
{
    if (index >= self->len || index < 0)
    {
        printf("invalid access, %s:%d", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
    else if (index == 0)
    {
        return llist_prepend_f64(self, value);
    }
    else
    {
        LNode_f64 *temp = lnode_new_f64(value);
        // Exit if allocation failed
        if (temp == NULL)
        {
            exit(EXIT_FAILURE);
        }

        // if list is uninitialized
        if (self->head == NULL)
        {
            self->head = temp;
            self->tail = temp;
            // TODO log that the given index is not valid as list is uninitialized
            self->len += 1;
            return self->len;
        }
        LNode_f64 *prev = llist_getnode_f64(self, index - 1);
        temp->next = prev->next;
        prev->next = temp;
        self->len += 1;
    }
    return self->len;
}

u32 llist_delete_f64(LList_f64 *self, u32 index)
{
    LNode_f64 *prev = llist_getnode_f64(self, index - 1);
    LNode_f64 *del = prev->next;
    prev->next = del->next;
    lnode_free_f64(del);
    self->len -= 1;
    return self->len;
}

f64 llist_get_f64(LList_f64 *self, u32 index)
{
    return llist_getnode_f64(self, index)->data;
}
void llist_set_f64(LList_f64 *self, u32 index, f64 value)
{
    llist_getnode_f64(self, index)->data = value;
}

u32 llist_search_f64(LList_f64 *self, f64 value)
{
    if (self->head == NULL)
    {
        printf("llist empty: %s:%d", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
    u32 i = 0;
    for (LNode_f64 *iter = self->head; iter != NULL; iter = iter->next)
    {
        if (fabs(iter->data - value) <= EPSILON)
        {
            return i;
        }
        i += 1;
    }
    return -1;
}

void llist_free_f64(LList_f64 *self)
{
    if (self->head != NULL)
    {
        LNode_f64 *temp2 = self->head;
        for (LNode_f64 *temp1 = self->head; temp1 != NULL; temp1 = temp2)
        {
            temp2 = temp2->next;
            lnode_free_f64(temp1);
        }
        self->head = NULL;
    }
}

// --------------------------------------------------------PRINTING UTILITY------------------------------------------------------

void display_llist_f64(LList_f64 *self)
{
    printf("{");
    if (self->head != NULL)
    {
        for (LNode_f64 *iter = self->head; iter != NULL; iter = iter->next)
        {
            printf("%.15g", iter->data);
            if (iter->next != NULL)
            {
                printf(" -> ");
            }
        }
    }
    printf("}\n");
}
void display_debug_llist_f64(LList_f64 *self)
{
    printf("[head: %p, tail: %p, len: %d, ", self->head, self->tail, self->len);
    printf("{");
    if (self->head != NULL)
    {
        u32 i = 0;
        for (LNode_f64 *iter = self->head; iter != NULL; iter = iter->next)
        {
            printf("%d:%.15g", i, iter->data);
            if (iter->next != NULL)
            {
                printf(" -> ");
            }
            i += 1;
        }
    }
    printf("}]\n");
}