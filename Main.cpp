// Run once time:
#ifndef _GG_CALC_CPP_
#define _GG_CALC_CPP_

// Importations:
#define IMPORT_TERMINAL_COLORS
#include <cutils.h>
#include <iostream>
#include <string>
#include <cmath>


// Main code:
int main(void)
{
	// Variables:
	#define GG_CALCULATOR_VERSION "1.0.0" // Calculator version variable.
	#define MIN_PRECISION 0               // Minimum precision variable.
	#define MAX_PRECISION 18              // Maximum precision variable.
	signed char loop1 = 1;                // First Loop variable.
	signed int precision = 2;             // Precision variable.
	long double n1;                       // First number variable.
	long double n2;                       // Second number variable.
	long double result;                   // Result variable.
	std::string option1;                  // First option variable.

	// Commands before main loop:
	enable_vt_and_utf8();

	// Main loop:
	while(loop1 == 1)
	{
		clear_terminal();
		puts("====================================");
		printf("========= CALCULATOR %s =========\n", GG_CALCULATOR_VERSION);
		puts("====================================");
		printf("  %s[ 0 ] Options...%s\n", RED_COLOR, BASE_TERMINAL);
		puts("  [ 1 ] Addition accounts +");
		puts("  [ 2 ] Subtraction accounts -");
		puts("  [ 3 ] Multiplication accounts x");
		puts("  [ 4 ] Division accounts ÷");
		puts("  [ 5 ] Elevation accounts ^");
		puts("  [ 6 ] Rooted accounts √");
		fputs("\t Your answer: ", stdout);
		std::cin >> std::ws >> option1;
		clear_terminal();

		if(option1 == "0")
		{
			loop1 = 2;

			// Second main loop:
			while(loop1 == 2)
			{
				puts("========================================");
				puts("============= OPTIONS MENU =============");
				puts("========================================");
				puts("   [ 0 ] Return");
				printf("   %s[ 1 ] Exit...%s\n", RED_COLOR, BASE_TERMINAL);
				puts("   [ 2 ] Read \"READ-ME\"");
				printf("   [ 3 ] Change precision (actual: %d)\n", precision);
				fputs("\t Your answer: ", stdout);
				std::cin >> std::ws >> option1;

				if(option1 == "0")
				{
					--loop1;
				}

				else if(option1 == "1")
				{
					loop1 = 0, clear_terminal();
				}

				else if(option1 == "2")
				{
					clear_terminal();
					rrmf();
				}

				else if(option1 == "3")
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

				else if(option1 == "3.14" || option1 == "3.1415" || option1 == "3.14159" || option1 == "3,14" || option1 == "3,1415" || option1 == "3,14159")
				{
					clear_terminal();
					easter_egg_function();
					clear_terminal();
				}

				clear_terminal();
			}
		}

		else if(option1 == "1")
		{
			fputs("Type two numbers, both with space to sum it (lr = last account result): ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
			printf("Result: %.*Lf\n", precision, n1 + n2);
			petc();
		}

		else if(option1 == "2")
		{
			fputs("Type two numbers, both with space to subtract it (lr = last account result): ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
			printf("Result: %.*Lf\n", precision, n1 - n2);
			petc();
		}

		else if(option1 == "3")
		{
			fputs("Type two numbers, both with space to multiply it (lr = last account result): ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
			printf("Result: %.*Lf\n", precision, n1 * n2);
			petc();
		}

		else if(option1 == "4")
		{
			fputs("Type two numbers, both with space to make a division (lr = last account result): ", stdout);
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

		else if(option1 == "5")
		{
			fputs("Type two numbers, both with space to elevate the left number (lr = last account result): ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
			printf("Result: %.*Lf\n", precision, powl(n1, n2));
			petc();
		}

		else if(option1 == "6")
		{
			fputs("Type two numbers, both with space to root the left number (lr = last account result): ", stdout);
			scanf("%Lf %Lf", &n1, &n2);
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
