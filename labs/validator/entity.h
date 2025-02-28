/* entity.h - 业务实体定义 */
#ifndef ENTITY_H
#define ENTITY_H

#include "validator.h"

// 学生实体
typedef struct {
    int id;         // 需校验：非零
    char *name;     // 需校验：最大长度20
    float score;
} Student;

// 学生校验规则配置
static const ValidatorRule student_rules[] = {
    {offsetof(Student, id), validate_nonzero, NULL},
    {offsetof(Student, name), validate_max_length, (void*)20}
};

// 图书实体
typedef struct {
    int book_id;    // 需校验：1-9999
    char *title;    // 需校验：最大长度50
    float price;
} Book;

// 图书校验规则配置
static int book_id_range[] = {1, 9999};
static const ValidatorRule book_rules[] = {
    {offsetof(Book, book_id), validate_range, book_id_range},
    {offsetof(Book, title), validate_max_length, (void*)50}
};

#endif
