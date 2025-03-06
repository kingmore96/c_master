#include "float_validation.h"
#include <stdint.h>
#include <string.h>

int valid_float(float num,uint32_t rules)
{	
	if(rules == 0) return -1;
	
	uint32_t bits;
	memcpy(&bits,&num,sizeof(num));
	const uint32_t sign = bits >> 31;
	const uint32_t exp = (bits & 0x7F800000) >> 23;
	const uint32_t mantissa = bits & 0x007FFFFF;

	if (exp > 0 && exp < 0xFF){
		if(rules & FLOAT_RULE_ALLOW_NORMAL) return 0;
		return -1;
	}


	if (exp == 0){
		if(mantissa == 0){
			if(rules & FLOAT_RULE_ALLOW_ZERO) return 0;
			const uint32_t sign_rule = sign ? FLOAT_RULE_ALLOW_NZERO:FLOAT_RULE_ALLOW_PZERO;
			return rules & sign_rule ? 0 : -1;
		}
		return rules & FLOAT_RULE_ALLOW_DENORMAL ? 0 : -1;
	}

	if (mantissa == 0){
		if(rules & FLOAT_RULE_ALLOW_INF) return 0;
		const uint32_t sign_rule = sign ? FLOAT_RULE_ALLOW_NINF : FLOAT_RULE_ALLOW_PINF;
		return rules & sign_rule ? 0 : -1;
	}

	if(rules & FLOAT_RULE_ALLOW_NAN) return 0;
	const uint32_t nan_type_rule = (mantissa & 0x00400000) ? FLOAT_RULE_ALLOW_QNAN : FLOAT_RULE_ALLOW_SNAN;
	return rules & nan_type_rule ? 0 : -1;

}




