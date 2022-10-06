#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

int main() {

    double x1, x2, delta;
    int number = 0;

    printf("Enter following data x1: ");
    scanf("%lf", &x1);
    printf("Enter following data x2: ");
    scanf("%lf", &x2);
    printf("Enter delta: ");
    scanf("%lf", &delta);

    printf("        +===============================================+\n");
    printf("        | X1: %-5.0f |  X2: %-5.0f | STEP: %-15.0f| \n", x1, x2, delta);
    printf("        +===============================================+\n");
    printf("\t| N \t    | X     \t | f(x) \t\t|\n");
    printf("        +===============================================+\n");

    if (x1 < x2 && delta <= x2 - x1) {

        for (; x1 <= x2; x1 = x1 + delta) {
            double result = (2.00 * (pow((x1 - 1000.00), 3.00)) - (3.00 * pow((x1 - 500.00), 2.00)) +
                             (4.00 * x1 - 5.00));
            ++number;

            printf("\t| %9.0d |  %9.0f | %21.5e|\n", number, x1, result);
            printf("        +===============================================+\n");

            if (number % 9 == 1) {
                getchar();
            }

        }

    }
        else if (x1 > x2) {
        printf("X1 is bigger than X2, restart program");
    }
        else if (delta >= x2 - x1) {
        printf("Delta is bigger than X2-X1, restart program");
    }
   return 0;
}
