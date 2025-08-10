#ifndef _GG_CALCULATOR_C_
#define _GG_CALCULATOR_C_

// Importations:
#include <cutils.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Main code:
int main(void)
{
	// Variables:
	#define GG_CALC_VERSION  1.00L // Calculator version variable.
	#define MIN_PRECISION 0        // Minimum precision variable.
	#define MAX_PRECISION 18       // Maximum precision variable.
	unsigned char loop1 = 1u;      // First loop variable.
	unsigned char loop2 = 0u;      // Second loop variable.
	signed int precision = 2;      // Precision variable.
	long double n1;                // First number variable.
	long double n2;                // Second number variable.
	long double option1;           // First option variable.
	long double option2;           // Second option variable.

	// Main loop:
	while(loop1)
	{
		clear_terminal();
		puts("===================================");
		printf("========= CALCULATOR %.2Lf =========\n", GG_CALC_VERSION);
		puts("===================================");
		printf("  %s[ 0 ] Options...%s\n", RED_COLOR, BASE_TERMINAL);
		puts("  [ 1 ] Addition accounts +");
		puts("  [ 2 ] Subtraction accounts -");
		puts("  [ 3 ] Multiplication accounts x");
		puts("  [ 4 ] Division accounts ÷");
		puts("  [ 5 ] Elevation accounts ^");
		puts("  [ 6 ] Rooted accounts √");
		fputs("\t Your answer: ", stdout);
		scanf("%Lf", &option1);
		clear_terminal();

		if(option1 == 0.0L)
		{
			--loop1, ++loop2;

			// Second main loop:
			while(loop2)
			{
				puts("========================================");
				puts("============= OPTIONS MENU =============");
				puts("========================================");
				puts("   [ 0 ] Return");
				printf("   %s[ 1 ] Exit...%s\n", RED_COLOR, BASE_TERMINAL);
				puts("   [ 2 ] Read \"READ-ME\"");
				printf("   [ 3 ] Change precision (actual: %d)\n", precision);
				fputs("\t Your answer: ", stdout);
				scanf("%Lf", &option2);

				if(option2 == 0.0L)
				{
					++loop1, --loop2;
				}

				else if(option2 == 1.0L)
				{
					--loop2, clear_terminal();
				}

				else if(option2 == 2.0L)
				{
					clear_terminal();
					rrmf();
				}

				else if(option2 == 3.0L)
				{
					clear_terminal();
					fputs("Type the new value to the precision (base: 2, min: 0, max: 18): ", stdout);
					scanf("%d", &precision);

					if(precision < MIN_PRECISION)
					{
						precision = MIN_PRECISION;
					}

					else if(precision > MAX_PRECISION)
					{
						precision = MAX_PRECISION;
					}

					clear_terminal();
				}

				else if(option2 == 3.14L || option2 == 3.1415L)
				{
					clear_terminal();
					easter_egg_function();
					clear_terminal();
				}

				clear_terminal();
			}
		}

		else if(option1 == 1.0L)
		{
			fputs("Type two numbers, both with space to sum it: ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
			clear_terminal();
			printf("Result: %.*Lf + %.*Lf = %.*Lf\n", precision, n1, precision, n2, precision, n1 + n2);
			petc();
		}

		else if(option1 == 2.0L)
		{
			fputs("Type two numbers, both with space to subtract it: ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
			clear_terminal();
			printf("Result: %.*Lf - %.*Lf = %.*Lf\n", precision, n1, precision, n2, precision, n1 - n2);
			petc();
		}

		else if(option1 == 3.0L)
		{
			fputs("Type two numbers, both with space to multiply it: ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
			clear_terminal();
			printf("Result: %.*Lf x %.*Lf = %.*Lf\n", precision, n1, precision, n2, precision, n1 * n2);
			petc();
		}

		else if(option1 == 4.0L)
		{
			fputs("Type two numbers, both with space to make a division: ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
			clear_terminal();

			if(n2 == 0.0L)
			{
				printf("%sERROR...%s\n", RED_COLOR, BASE_TERMINAL);
			}

			else
			{
				printf("Result: %.*Lf ÷ %.*Lf = %.*Lf\n", precision, n1, precision, n2, precision, n1 / n2);
			}

			petc();
		}

		else if(option1 == 5.0L)
		{
			fputs("Type two numbers, both with space to elevate the left number: ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
			clear_terminal();
			printf("Result: %.*Lf ^ %.*Lf = %.*Lf\n", precision, n1, precision, n2, precision, powl(n1, n2));
			petc();
		}

		else if(option1 == 6.0L)
		{
			fputs("Type two numbers, both with space to root the left number: ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
			clear_terminal();
			printf("Result: %.*Lf √ %.*Lf = ", precision, n1, precision, n2);

			if(n1 < 0.0L)
			{
				printf("%.*Lf\n", precision, copysignl(powl(fabsl(n1), 1.0L / n2), n1));
			}

			else
			{
				printf("%.*Lf\n", precision, powl(n1, 1.0L / n2));
			}

			petc();
		}
	}

	return 0;
}

#endif
