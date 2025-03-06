#include <stdint.h>

/*Header Identifier:ensure that the header file will only be expanded once.*/
#ifndef __CPP_COMMON_FLOAT_VALIDATION_H__
#define __CPP_COMMON_FLOAT_VALIDATION_H__

#define FLOAT_RULE_ALLOW_ZERO		(1<<0)
#define FLOAT_RULE_ALLOW_NORMAL		(1<<1)
#define FLOAT_RULE_ALLOW_DENORMAL	(1<<2)
#define FLOAT_RULE_ALLOW_INF		(1<<3)
#define FLOAT_RULE_ALLOW_NAN		(1<<4)

#define FLOAT_RULE_ALLOW_PZERO		(1<<5)
#define FLOAT_RULE_ALLOW_NZERO		(1<<6)

#define FLOAT_RULE_ALLOW_PINF		(1<<7)
#define FLOAT_RULE_ALLOW_NINF		(1<<8)

#define FLOAT_RULE_ALLOW_QNAN		(1<<9)
#define FLOAT_RULE_ALLOW_SNAN		(1<<10)

/*
typedef enum{
	VALID_OK = 0,
	ERR_TYPE_NOT_ALLOWED = -1
}valid_result_t;
*/

int valid_float(float num,uint32_t rules);



#endif
