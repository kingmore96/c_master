#include "validator.h"
#include <string.h>

// 策略1：校验整数字段非零
ValidationResult validate_nonzero(void *field, void *param) {
    int value = *(int*)field;
    ValidationResult result = {VALID_OK, ""};
    
    if (value == 0) {
        result.code = ERR_NONZERO;
        strcpy(result.message, "值不能为零");
    }
    return result;
}

// 策略2：校验整数字段在指定范围内
ValidationResult validate_range(void *field, void *param) {
    int value = *(int*)field;
    int *range = (int*)param;
    ValidationResult result = {VALID_OK, ""};
    
    if (value < range[0] || value > range[1]) {
        result.code = ERR_RANGE;
        snprintf(result.message, sizeof(result.message), 
                "值需在%d-%d之间", range[0], range[1]);
    }
    return result;
}

// 策略3：校验字符串最大长度
ValidationResult validate_max_length(void *field, void *param) {
    char *str = *(char**)field;
    int max_len = *(int*)param;
    ValidationResult result = {VALID_OK, ""};
    
    if (strlen(str) > max_len) {
        result.code = ERR_MAX_LENGTH;
        snprintf(result.message, sizeof(result.message), 
                "长度不能超过%d字符", max_len);
    }
    return result;
}

/* 核心校验逻辑 */
ValidationResult validate_entity(void *entity, 
                               const ValidatorRule *rules,
                               int rule_count) {
    ValidationResult final_result = {VALID_OK, "所有校验通过"};
    
    for (int i = 0; i < rule_count; i++) {
        // 计算字段地址：entity + 字段偏移量
        void *field = (char*)entity + rules[i].field_offset;
        
        // 执行校验策略
        ValidationResult ret = rules[i].validate(field, rules[i].param);
        
        if (ret.code != VALID_OK) {
            return ret; // 遇到首个错误立即返回
        }
    }
    return final_result;
}

