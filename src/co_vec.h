/**
 * 向量
 *              by colin
 */
#ifndef __CO_VEC__
#define __CO_VEC__
#include "co_utils.h"

// 向量结构 
typedef struct covec {
    void * data;            // 数据
    int cap;                // 容量
    int size;               // 当前大小
    uint32_t itemsize;      // 项大小
} covec_t;

// 初始化向量，itemsize为子项大小
void covec_init(covec_t *vec, uint16_t itemsize);
// 释放向量
void covec_free(covec_t *vec);
// 清除向量内容
void covec_clear(covec_t *vec);
// 取向量大小
static inline int covec_size(covec_t *vec) { return vec->size; }
// 取向量容量
static inline int covec_cap(covec_t *vec) { return vec->cap; }
// 设置向量大小
void covec_resize(covec_t *vec, int size);
// 增加向量容量
void covec_growcap(covec_t *vec, int cap);

// 压入子项，index可以为-1, -2..，表示从最后一个计算
bool covec_push_at(covec_t *vec, int index, void *data);
// 压入最前面
bool covec_push_first(covec_t *vec, void *data);
// 压入最后面
bool covec_push_last(covec_t *vec, void *data);

// 取子项，index可以为-1, -2..，表示从最后一个计算
bool covec_get_at(covec_t *vec, int index, void *data);
// 取第1个
bool covec_get_first(covec_t *vec, void *data);
// 取最后1个
bool covec_get_last(covec_t *vec, void *data);

// 设子项，index和上面一样
bool covec_set_at(covec_t *vec, int index, const void *data);
// 设第1个
bool covec_set_first(covec_t *vec, const void *data);
// 设最后1个
bool covec_set_last(covec_t *vec, const void *data);

// 删除子项，index和上面一样， data可以为NULL， 也可以有值，表示删除的同时取值
bool covec_del_at(covec_t *vec, int index, void *data);
// 删除第1个
bool covec_del_first(covec_t *vec, void *data);
// 删除最后1个
bool covec_del_last(covec_t *vec, void *data);

// 拷贝向量
void covec_copy(covec_t *vfrom, covec_t *vto);

#endif