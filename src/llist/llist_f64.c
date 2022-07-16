#include "../include/llist_f64.h"

#include <stdio.h>
#include <stdlib.h>

LList_f64 llist_new_f64()
{
    LList_f64 temp;
    temp.head = NULL;
    temp.tail = NULL;
    temp.len = 0;
    return temp;
}

LNode_f64 *lnode_new_f64(f64 value)
{
    LNode_f64 *temp = (LNode_f64 *)malloc(sizeof(LNode_f64));
    temp->data = value;
    temp->next = NULL;
    return temp;
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

void display_llist_f64(LList_f64 *self)
{
    printf("{");
    if (self->head != NULL)
    {
        for (LNode_f64 *temp = self->head; temp != NULL; temp = temp->next)
        {
            printf("%g", temp->data);
            if (temp->next != NULL)
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
        for (LNode_f64 *temp = self->head; temp != NULL; temp = temp->next)
        {
            printf("%g", temp->data);
            if (temp->next != NULL)
            {
                printf(" -> ");
            }
        }
    }
    printf("}]\n");
}