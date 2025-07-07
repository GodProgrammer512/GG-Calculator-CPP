// Importations:
#include <cutils.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Main code:
int main(void)
{
	// Variables:
	unsigned char loop1 = 1u, loop2 = 0u;
	signed int precision = 6; /* Precision of the numbers. */
	long double n1, n2, option1, option2;
	#define CALC_VERSION 5.0L

	// Main loop:
	while(loop1)
	{
		clear_terminal();
		puts("=====================================");
		printf("======== CALCULATOR %Lf ========\n", CALC_VERSION);
		puts("=====================================");
		printf("  %s[ 0 ] Options...%s\n", RED_COLOR, BASE_TERMINAL);
		puts("  [ 1 ] Addition accounts");
		puts("  [ 2 ] Subtraction accounts");
		puts("  [ 3 ] Multiplication accounts");
		puts("  [ 4 ] Division accounts");
		puts("  [ 5 ] Elevation accounts");
		puts("  [ 6 ] Rooted accounts");
		fputs("\t Your answer: ", stdout);
		scanf("%Lf", &option1);
		clear_terminal();

		if(option1 == 0.0L)
		{
			--loop1, ++loop2;

			// Second main loop:
			while(loop2)
			{
				puts("=============================");
				puts("========== OPTIONS ==========");
				puts("=============================");
				puts("  [ 0 ] Return");
				printf("  %s[ 1 ] Exit...%s\n", RED_COLOR, BASE_TERMINAL);
				puts("  [ 2 ] Read \"READ-ME\"");
				puts("  [ 3 ] Change precision");
				fputs("\tYour answer: ", stdout);
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
					clear_terminal();
				}

				else if(option2 == 3.0L)
				{
					clear_terminal();
					printf("Type the new value to the precision (base: 6, actual: %d, min: 0, max: 30): ", precision);
					scanf("%d", &precision);

					if(precision < 0)
					{
						precision = 0;
					}

					else if(precision > 30)
					{
						precision = 30;
					}

					printf("New value: %d\n", precision);
					petc();
					clear_terminal();
				}

				else if(option2 == 3.14L || option2 == 3.1415L)
				{
					clear_terminal();
					easter_egg_function();
					clear_terminal();
				}
			}
		}

		else if(option1 == 1.0L)
		{
			fputs("Type two numbers, both with space to sum it: ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
			printf("Result: %.*Lf\n", precision, n1 + n2);
			petc();
		}

		else if(option1 == 2.0L)
		{
			fputs("Type two numbers, both with space to subtract it: ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
			printf("Result: %.*Lf\n", precision, n1 - n2);
			petc();
		}

		else if(option1 == 3.0L)
		{
			fputs("Type two numbers, both with space to multiply it: ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
			printf("Result: %.*Lf\n", precision, n1 * n2);
			petc();
		}

		else if(option1 == 4.0L)
		{
			fputs("Type two numbers, both with space to make a division: ", stdout);
			scanf("%Lf %Lf", &n1, &n2);

			if(n2 == 0.0L)
			{
				printf("%sERROR...%s\n", RED_COLOR, BASE_TERMINAL);
			}

			else
			{
				printf("Result: %.*Lf\n", precision, n1 / n2);
			}

			petc();
		}

		else if(option1 == 5.0L)
		{
			fputs("Type two numbers, both with space to elevate the left number: ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
			printf("Result: %.*Lf\n", precision, powl(n1, n2));
			petc();
		}

		else if(option1 == 6.0L)
		{
			fputs("Type two numbers, both with space to root the left number: ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
			fputs("Result: ", stdout);

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
