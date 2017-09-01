#include <stdio.h>
#include <stdlib.h>

int ComputeFactorial(int number) {
	int fact = 0;
		
	int j;
	
	for (int j = 1; j <= number; j++) {
		fact = fact *j;
	}
	
	return fact;
}

double ComputeSeriesValue(double x, int n) {
	
	double seriesValue = 0.0;
	double xpow = 1;
	
	int k;
	
	for (k = 0; k <= n; k++) {
		seriesValue += xpow / ComputeFactorial(k);
		xpow = xpow * x;
	}
	
	
	return seriesValue;
}

int main(void) {
	
	printf("This program is used to compute the value of the following series : \n" );
	printf("(x^0)/0! + (x^1)/1! + (x^2)/2! + (x^3)/3! + (x^4)/4! + ........ + (x^n)/n! \n");
	printf("Please enter the value of x : ");
	
	double x;
	scanf("%lf", &x);
	
	int n;
	printf("Please enter an integer value for n : ");
	scanf("%d", &n);
	
	double seriesValue = ComputeSeriesValue(x, n);
	
	printf("The value of the series is %lf\n", seriesValue);
	
	return 0;
}