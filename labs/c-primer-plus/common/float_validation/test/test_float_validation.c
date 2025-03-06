#include "float_validation.h"
#include "unity.h"
#include <stdint.h>


float make_special(uint32_t bits)
{
	union{
		float f;
		uint32_t b;
	}converter;

	converter.b = bits;
	return converter.f;
}

void test_allow_normal(void)
{
	TEST_ASSERT_EQUAL(valid_float(1.5f,FLOAT_RULE_ALLOW_NORMAL),0);
	TEST_ASSERT_EQUAL(valid_float(-3.14f,FLOAT_RULE_ALLOW_NORMAL),0);
	TEST_ASSERT_EQUAL(valid_float(make_special(0x7F7FFFFF),FLOAT_RULE_ALLOW_NORMAL),0);
	TEST_ASSERT_EQUAL(valid_float(make_special(0x00800000),FLOAT_RULE_ALLOW_NORMAL),0);
}


void setUp(void)
{
       // 初始化代码
}

void tearDown(void)
{
       // 清理代码
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_allow_normal);
	return UNITY_END();
}
