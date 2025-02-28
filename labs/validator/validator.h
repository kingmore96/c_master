/* validator.h - 通用校验模块 */
#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <stddef.h> // 用于offsetof宏

// 错误码定义
typedef enum {
    VALID_OK,
    ERR_NONZERO,     // 值必须非零
    ERR_RANGE,       // 超出允许范围
    ERR_MAX_LENGTH,  // 字符串超长
    ERR_MIN_LENGTH   // 字符串过短
} ValidatorError;

// 错误信息结构体
typedef struct {
    ValidatorError code;
    char message[128];
} ValidationResult;

// 校验策略函数类型
typedef ValidationResult (*ValidateFunc)(void* field, void* param);

// 校验规则配置结构体
typedef struct {
    size_t field_offset;   // 字段在结构体中的偏移量
    ValidateFunc validate; // 策略函数指针
    void *param;           // 校验参数（如范围值）
} ValidatorRule;

/* 公共校验入口函数 */
ValidationResult validate_entity(void *entity, 
                               const ValidatorRule *rules, 
                               int rule_count);

/* 常用策略函数声明 */
ValidationResult validate_nonzero(void *field, void *param);
ValidationResult validate_range(void *field, void *param);
ValidationResult validate_max_length(void *field, void *param);

#endif
