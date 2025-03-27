#include <stdio.h>
#include <math.h>

int main(void)
{
	float toosmall = -3.4E38 * 100;
	printf("-3.4E38 * 100 = %f\n",toosmall);

	union{
		unsigned int a;
		float b;
	}cv_p;

	cv_p.a = 0x7F800000;	
	printf("sqrt(+inf) = %f\n",sqrt(cv_p.b));

	printf("log(0.0) = %f\n",log(0.0));
	
	printf("inf + 1.2 = %f\n",cv_p.b + 1.2);
	printf("inf - 1.2 = %f\n",cv_p.b - 1.2);

	printf("inf * 1.2 = %f\n",cv_p.b * 1.2);
	printf("inf / 1.2 = %f\n",cv_p.b / 1.2);
	printf("inf * -1.2 = %f\n",cv_p.b * (-1.2));
	printf("inf / -1.2 = %f\n",cv_p.b / (-1.2));		

	union{
		unsigned int a;
		float b;
	}cv_n;

	cv_n.a = 0xFF800000;
	printf("-inf + 1.2 = %f\n",cv_n.b + 1.2);
	printf("-inf - 1.2 = %f\n",cv_n.b - 1.2);

	printf("-inf * 1.2 = %f\n",cv_n.b * 1.2);
	printf("-inf / 1.2 = %f\n",cv_n.b / 1.2);
	printf("-inf * -1.2 = %f\n",cv_n.b * (-1.2));
	printf("-inf / -1.2 = %f\n",cv_n.b / (-1.2));		

	printf("inf + inf = %f\n",cv_p.b + cv_p.b);
	printf("-inf + -inf = %f\n",cv_n.b + cv_n.b);
	
	printf("inf - inf = %f\n",cv_p.b - cv_p.b);
	printf("-inf + inf = %f\n",cv_n.b + cv_p.b);

	printf("inf * inf = %f\n",cv_p.b * cv_p.b);
	printf("inf * -inf = %f\n",cv_p.b * cv_n.b);

	printf("inf / inf = %f\n",cv_p.b / cv_p.b);
	printf("inf / -inf = %f\n",cv_p.b / cv_n.b);

	printf("0.0 * inf = %f\n",0.0 * cv_p.b);
	printf("0.0 * -inf = %f\n",0.0 * cv_n.b);


	printf("-0.0 * inf = %f\n",-0.0 * cv_p.b);
	printf("-0.0 * -inf = %f\n",-0.0 * cv_n.b);

	

	printf("0.0 / inf = %f\n",0.0 / cv_p.b);
	printf("0.0 / -inf = %f\n",0.0 / cv_n.b);


	printf("-0.0 / inf = %f\n",-0.0 / cv_p.b);
	printf("-0.0 / -inf = %f\n",-0.0 / cv_n.b);

	printf("fmax(3.0,nan) = %f\n",fmax(3.0,nan("")));
	printf("fmax(nan,-5,0) = %f\n",fmax(nan(""),-5.0));
	printf("fmax(nan,nan) = %f\n",fmax(nan(""),nan("")));



}
