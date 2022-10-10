#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void calculation(double x1, double x2, double delta);

int main() {

    unsigned int var, N;
    double x1, x2, delta;

    printf("Enter variant (1 or 2): ");
    scanf("%d", &var);

    while (var != 1 && var != 2) {
        printf("Error. Incorrect variant. Enter variant again (1 or 2): ");
        scanf("%d", &var);
    }

    if (var == 1) {
        printf("Enter following data x1: ");
        scanf("%lf", &x1);
        printf("Enter following data x2: ");
        scanf("%lf", &x2);
        printf("Enter N: ");
        scanf("%u", &N);

        while(x1 > x2) {
            printf("Error, enter data again\n");
            printf("Enter following data x1: ");
            scanf("%lf", &x1);
            printf("Enter following data x2: ");
            scanf("%lf", &x2);
            printf("Enter N: ");
            scanf("%u", &N);
        }

        delta = (x2 - x1) / (N - 1);
        printf("        +===============================================+\n");
        printf("        | X1: %-5.0f |  X2: %-5.0f | STEP: %-15.0f| \n", x1,x2,  delta);
        printf("        +===============================================+\n");

        calculation(x1, x2, delta);

        return 0;
    }

    if (var == 2) {
        printf("Enter following data x1: ");
        scanf("%lf", &x1);
        printf("Enter following data x2: ");
        scanf("%lf", &x2);
        printf("Enter delta: ");
        scanf("%lf", &delta);

        while((x1 > x2) || (delta >= x2-x1)) {
            printf("Error, enter data again\n");
            printf("Enter following data x1: ");
            scanf("%lf", &x1);
            printf("Enter following data x2: ");
            scanf("%lf", &x2);
            printf("Enter delta: ");
            scanf("%lf", &delta);
        }

        printf("        +===============================================+\n");
        printf("        | X1: %-5.0f |  X2: %-5.0f | STEP: %-15.0f| \n", x1, x2, delta);
        printf("        +===============================================+\n");
        printf("\t| N \t    | X     \t | f(x) \t\t|\n");
        printf("        +===============================================+\n");

        calculation(x1, x2, delta);

        return 0;
    }
}

void calculation(double x1, double x2, double delta) {
    if (x1 < x2 && delta <= x2 - x1) {
        for (int number = 0; x1 <= x2; x1 = x1 + delta) {
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
}

