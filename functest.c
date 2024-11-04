/* functest */

#include <stdio.h>

double add(double a, double b);
double subt(double a, double b);
double multip(double a, double b);
double divide(double a, double b);

int main() {
	double a = 25.0, b= 5.0;

	printf("=== calc test \n ===");
	printf("a = %.1f, b = %.1f\n", a, b);
	printf("덧셈: %.1f\n", add(a, b));
    	printf("뺄셈: %.1f\n", subt(a, b));
    	printf("곱셈: %.1f\n", multip(a, b));
    	printf("나눗셈: %.1f\n", divide(a, b));
    
    	return 0;
}
