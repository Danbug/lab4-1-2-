#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	printf("It's a*x^2 + b*x + c = 0 Calculcator\n");
	printf("-----------------------------------------\n");
	if(argc != 4){
		printf("Wrong amount of arguments! \nYou should run program like this './test a b c'\n");
		printf("where a b c is a integer value of desired expresion");
		return -1;
	}
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int c = atoi(argv[3]);
	printf("%d*x^2 + %d*x + %d = 0\n", a , b , c);
	
	double discriminant = b * b - 4 * a * c;
	
	if(2 * a == 0){
		printf("You can't divide by zero!\n i'm ded");
		return -1;
	}
	
	if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("First Root = %.2lf, Second Root = %.2lf", root1, root2);
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        printf("Root = %.2lf;", root);
    } else {
    	printf("Roots are not real\n");
	}
		
	return 0;
}