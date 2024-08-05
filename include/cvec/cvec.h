#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define __vec_concat(a, b) __CONCAT(a, b)
#define __vec_i __vec_concat(__i, __LINE__)
#define __vec_elem_size(vec) sizeof(struct { typeof(*(vec)->data) data; })

#define Vec(type)                                                              \
    struct {                                                                   \
        type *data;                                                            \
        size_t len;                                                            \
        size_t cap;                                                            \
    }

#define vec_new(type) {NULL, 0, 0}

#define vec_init(vec)                                                          \
    do {                                                                       \
        (vec)->data = NULL;                                                    \
        (vec)->len = 0;                                                        \
        (vec)->cap = 0;                                                        \
    } while (0)

#define vec_free(vec)                                                          \
    do {                                                                       \
        free((vec)->data);                                                     \
        (vec)->data = NULL;                                                    \
        (vec)->len = 0;                                                        \
        (vec)->cap = 0;                                                        \
    } while (0)

#define vec_clear(vec)                                                         \
    do {                                                                       \
        (vec)->len = 0;                                                        \
    } while (0)

#define vec_copy(dst, src)                                                     \
    do {                                                                       \
        while ((dst)->cap < (src)->len)                                        \
            vec_grow(dst);                                                     \
                                                                               \
        (dst)->len = (src)->len;                                               \
        memcpy((dst)->data, (src)->data, __vec_elem_size(src) * (src)->len);   \
    } while (0)

#define vec_grow(vec)                                                          \
    do {                                                                       \
        (vec)->cap = (vec)->cap * 2 + 1;                                       \
        (vec)->data = realloc((vec)->data, __vec_elem_size(vec) * (vec)->cap); \
    } while (0)

#define vec_push(vec, elem)                                                    \
    do {                                                                       \
        if ((vec)->len == (vec)->cap) {                                        \
            vec_grow(vec);                                                     \
        }                                                                      \
        (vec)->data[(vec)->len++] = elem;                                      \
    } while (0)

#define vec_pop(vec) (((vec)->len) ? &(vec)->data[--(vec)->len] : NULL)

#define vec_for(vec, elem)                                                     \
    size_t __vec_i = 0;                                                        \
    for (typeof(*(vec)->data) elem;                                            \
         __vec_i < (vec)->len && ((elem) = (vec)->data[__vec_i], 1);           \
         __vec_i++)

#define vec_for_each(vec, elem)                                                \
    size_t __vec_i = 0;                                                        \
    for (typeof(*(vec)->data) *elem;                                           \
         __vec_i < (vec)->len && ((elem) = &(vec)->data[__vec_i], 1);          \
         __vec_i++)
