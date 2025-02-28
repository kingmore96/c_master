#include <stdio.h>
#include "entity.h"

void print_validation_result(const ValidationResult *result) {
    const char* code_names[] = {
        [VALID_OK] = "VALID_OK",
        [ERR_NONZERO] = "ERR_NONZERO",
        [ERR_RANGE] = "ERR_RANGE",
        [ERR_MAX_LENGTH] = "ERR_MAX_LENGTH"
    };
    printf("[%s] %s\n", code_names[result->code], result->message);
}

int main() {
    // 测试学生校验
    Student bad_student = {
        .id = 0, 
        .name = "This name is way too long for validation"
    };
    ValidationResult ret = validate_entity(&bad_student, 
                                        student_rules, 
                                        sizeof(student_rules)/sizeof(ValidatorRule));
    print_validation_result(&ret); // 预期输出两个错误中的第一个
    
    // 测试图书校验
    Book valid_book = {
        .book_id = 100,
        .title = "C Programming Language"
    };
    ret = validate_entity(&valid_book, 
                         book_rules, 
                         sizeof(book_rules)/sizeof(ValidatorRule));
    print_validation_result(&ret); // 预期输出VALID_OK
    
    return 0;
}

