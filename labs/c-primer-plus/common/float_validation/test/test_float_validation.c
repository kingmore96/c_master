#include "float_validation.h"
#include "unity.h"
#include <stdint.h>

#define MAX_NORMAL_NUMBER 	0x7F7FFFFF
#define MIN_NORMAL_NUMBER 	0x00800000
#define MAX_DENORMAL_NUMBER 	0x007FFFFF
#define MIN_DENORMAL_NUMBER	0x00000001
#define P_INF			0x7F800000
#define N_INF			0xFF800000
#define P_QNAN			0x7FC00000
#define N_QNAN			0xFFC00000
#define P_SNAN			0x7FA00000
#define N_SNAN			0xFFA00000
#define FLOAT_RULE_ALLOW_TEST	(1<<31)

float make_special(uint32_t bits)
{
	union{
		float f;
		uint32_t b;
	}converter;

	converter.b = bits;
	return converter.f;
}

void test_one_rule_allow_normal(void)
{
	TEST_ASSERT_EQUAL(0,valid_float(1.5f,FLOAT_RULE_ALLOW_NORMAL));
	TEST_ASSERT_EQUAL(0,valid_float(-3.14f,FLOAT_RULE_ALLOW_NORMAL));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(MAX_NORMAL_NUMBER),FLOAT_RULE_ALLOW_NORMAL));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(MIN_NORMAL_NUMBER),FLOAT_RULE_ALLOW_NORMAL));
}

void test_one_rule_not_allow_normal(void)
{
	TEST_ASSERT_EQUAL(-1,valid_float(1.5f,FLOAT_RULE_ALLOW_TEST));
	TEST_ASSERT_EQUAL(-1,valid_float(-3.14f,FLOAT_RULE_ALLOW_TEST));
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(MAX_NORMAL_NUMBER),FLOAT_RULE_ALLOW_TEST));
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(MIN_NORMAL_NUMBER),FLOAT_RULE_ALLOW_TEST));
}

void test_one_rule_allow_zero(void)
{
	TEST_ASSERT_EQUAL(0,valid_float(0.0f,FLOAT_RULE_ALLOW_ZERO));
	TEST_ASSERT_EQUAL(0,valid_float(-0.0f,FLOAT_RULE_ALLOW_ZERO));	
}


void test_one_rule_not_allow_zero(void)
{
	TEST_ASSERT_EQUAL(-1,valid_float(0.0f,FLOAT_RULE_ALLOW_TEST));
	TEST_ASSERT_EQUAL(-1,valid_float(-0.0f,FLOAT_RULE_ALLOW_TEST));
}


void test_one_rule_allow_denormal(void)
{
	TEST_ASSERT_EQUAL(0,valid_float(make_special(MIN_DENORMAL_NUMBER),FLOAT_RULE_ALLOW_DENORMAL));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(MAX_DENORMAL_NUMBER),FLOAT_RULE_ALLOW_DENORMAL));
}

void test_one_rule_not_allow_denormal(void)
{
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(MIN_DENORMAL_NUMBER),FLOAT_RULE_ALLOW_TEST));
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(MAX_DENORMAL_NUMBER),FLOAT_RULE_ALLOW_TEST));
}

void test_one_rule_allow_inf(void)
{
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_INF),FLOAT_RULE_ALLOW_INF));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_INF),FLOAT_RULE_ALLOW_INF));
}

void test_one_rule_not_allow_inf(void) 
{
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(N_INF),FLOAT_RULE_ALLOW_TEST));
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(P_INF),FLOAT_RULE_ALLOW_TEST));
}

void test_one_rule_allow_nan(void)
{
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_QNAN),FLOAT_RULE_ALLOW_NAN));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_QNAN),FLOAT_RULE_ALLOW_NAN));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_SNAN),FLOAT_RULE_ALLOW_NAN));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_SNAN),FLOAT_RULE_ALLOW_NAN));
}


void test_one_rule_not_allow_nan(void)
{
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(N_QNAN),FLOAT_RULE_ALLOW_TEST));
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(P_QNAN),FLOAT_RULE_ALLOW_TEST));
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(N_SNAN),FLOAT_RULE_ALLOW_TEST));
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(P_SNAN),FLOAT_RULE_ALLOW_TEST));
}


void test_one_rule_allow_pzero(void)
{
	TEST_ASSERT_EQUAL(-1,valid_float(-0.0f,FLOAT_RULE_ALLOW_PZERO));
	TEST_ASSERT_EQUAL(0,valid_float(0.0f,FLOAT_RULE_ALLOW_PZERO));
}



void test_one_rule_allow_nzero(void)
{
	TEST_ASSERT_EQUAL(0,valid_float(-0.0f,FLOAT_RULE_ALLOW_NZERO));
	TEST_ASSERT_EQUAL(-1,valid_float(0.0f,FLOAT_RULE_ALLOW_NZERO));
}


void test_one_rule_allow_pinf(void)
{
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_INF),FLOAT_RULE_ALLOW_PINF));
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(N_INF),FLOAT_RULE_ALLOW_PINF));
}

void test_one_rule_allow_ninf(void)
{
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_INF),FLOAT_RULE_ALLOW_NINF));
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(P_INF),FLOAT_RULE_ALLOW_NINF));
}

void test_one_rule_allow_qnan(void)
{
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_QNAN),FLOAT_RULE_ALLOW_QNAN));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_QNAN),FLOAT_RULE_ALLOW_QNAN));
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(P_SNAN),FLOAT_RULE_ALLOW_QNAN));
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(N_SNAN),FLOAT_RULE_ALLOW_QNAN));
}

void test_one_rule_allow_snan(void)
{
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_SNAN),FLOAT_RULE_ALLOW_SNAN));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_SNAN),FLOAT_RULE_ALLOW_SNAN));
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(P_QNAN),FLOAT_RULE_ALLOW_SNAN));
	TEST_ASSERT_EQUAL(-1,valid_float(make_special(N_QNAN),FLOAT_RULE_ALLOW_SNAN));

}

void test_combines_zero_all(void)
{
	uint32_t rules = FLOAT_RULE_ALLOW_ZERO|FLOAT_RULE_ALLOW_PZERO|FLOAT_RULE_ALLOW_NZERO; 
	TEST_ASSERT_EQUAL(0,valid_float(0.0f,rules));
	TEST_ASSERT_EQUAL(0,valid_float(-0.0f,rules));
}

void test_combines_zero_pzero(void)
{
        uint32_t rules = FLOAT_RULE_ALLOW_ZERO|FLOAT_RULE_ALLOW_PZERO; 
        TEST_ASSERT_EQUAL(0,valid_float(0.0f,rules));
        TEST_ASSERT_EQUAL(0,valid_float(-0.0f,rules));
}


void test_combines_zero_nzero(void)
{
        uint32_t rules = FLOAT_RULE_ALLOW_ZERO|FLOAT_RULE_ALLOW_NZERO; 
        TEST_ASSERT_EQUAL(0,valid_float(0.0f,rules));
        TEST_ASSERT_EQUAL(0,valid_float(-0.0f,rules));
}


void test_combines_pzero_nzero(void)
{
        uint32_t rules = FLOAT_RULE_ALLOW_PZERO|FLOAT_RULE_ALLOW_NZERO; 
        TEST_ASSERT_EQUAL(0,valid_float(0.0f,rules));
        TEST_ASSERT_EQUAL(0,valid_float(-0.0f,rules));
}

void test_combines_inf_all(void)
{
	uint32_t rules = FLOAT_RULE_ALLOW_INF|FLOAT_RULE_ALLOW_PINF|FLOAT_RULE_ALLOW_NINF; 
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_INF),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_INF),rules));
}


void test_combines_inf_pinf(void)
{
	uint32_t rules = FLOAT_RULE_ALLOW_INF|FLOAT_RULE_ALLOW_PINF;
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_INF),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_INF),rules));
}

void test_combines_inf_ninf(void)
{
	uint32_t rules = FLOAT_RULE_ALLOW_INF|FLOAT_RULE_ALLOW_NINF; 
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_INF),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_INF),rules));
}

void test_combines_pinf_ninf(void)
{
	uint32_t rules = FLOAT_RULE_ALLOW_PINF|FLOAT_RULE_ALLOW_NINF; 
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_INF),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_INF),rules));
}


void test_combines_nan_all(void)
{
	uint32_t rules = FLOAT_RULE_ALLOW_NAN|FLOAT_RULE_ALLOW_QNAN|FLOAT_RULE_ALLOW_SNAN; 
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_QNAN),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_QNAN),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_SNAN),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_SNAN),rules));
}


void test_combines_nan_qnan(void)
{
	uint32_t rules = FLOAT_RULE_ALLOW_NAN|FLOAT_RULE_ALLOW_QNAN; 
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_QNAN),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_QNAN),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_SNAN),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_SNAN),rules));
}
void test_combines_nan_snan(void)
{
	uint32_t rules = FLOAT_RULE_ALLOW_NAN|FLOAT_RULE_ALLOW_SNAN; 
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_QNAN),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_QNAN),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_SNAN),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_SNAN),rules));
}
void test_combines_qnan_snan(void)
{
	uint32_t rules = FLOAT_RULE_ALLOW_QNAN|FLOAT_RULE_ALLOW_SNAN; 
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_QNAN),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_QNAN),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(P_SNAN),rules));
	TEST_ASSERT_EQUAL(0,valid_float(make_special(N_SNAN),rules));
}
void setUp(void)
{
}

void tearDown(void)
{
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_one_rule_allow_normal);
	RUN_TEST(test_one_rule_not_allow_normal);
	RUN_TEST(test_one_rule_allow_zero);
	RUN_TEST(test_one_rule_not_allow_zero);
	RUN_TEST(test_one_rule_allow_denormal);
	RUN_TEST(test_one_rule_not_allow_denormal);
	RUN_TEST(test_one_rule_allow_inf);
	RUN_TEST(test_one_rule_not_allow_inf);
	RUN_TEST(test_one_rule_allow_nan);
	RUN_TEST(test_one_rule_not_allow_nan);

	RUN_TEST(test_one_rule_allow_pzero);
	RUN_TEST(test_one_rule_allow_nzero);

	RUN_TEST(test_one_rule_allow_pinf);
	RUN_TEST(test_one_rule_allow_ninf);

	RUN_TEST(test_one_rule_allow_qnan);
	RUN_TEST(test_one_rule_allow_snan);
	
	RUN_TEST(test_combines_zero_all);
	RUN_TEST(test_combines_zero_pzero);
	RUN_TEST(test_combines_zero_nzero);
	RUN_TEST(test_combines_pzero_nzero);

	RUN_TEST(test_combines_inf_all);
	RUN_TEST(test_combines_inf_pinf);
	RUN_TEST(test_combines_inf_ninf);
	RUN_TEST(test_combines_pinf_ninf);

		
	RUN_TEST(test_combines_nan_all);
	RUN_TEST(test_combines_nan_qnan);
	RUN_TEST(test_combines_nan_snan);
	RUN_TEST(test_combines_qnan_snan);
	return UNITY_END(); 
}
