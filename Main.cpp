/* Include guard: */
#ifndef _GG_CALCULATOR_CPP_
#define _GG_CALCULATOR_CPP_

/* Importations: */
#define IMPORT_TERMINAL_COLORS
#define IMPORT_MATH_UTILS
#include <cutils.h>
#include <iostream>
#include <cmath>


/* Main code: */
int main()
{
	/* GG Calculator version variables: */
	#define GG_CALCULATOR_FULL_VERSION  101.0L /* GG Calculator full version variable (1.0.1). */
	#define GG_CALCULATOR_MAJOR_VERSION 1.0L   /* GG Calculator major version variable (1).    */
	#define GG_CALCULATOR_MINOR_VERSION 0.0L   /* GG Calculator minor version variable (0).    */
	#define GG_CALCULATOR_PATCH_VERSION 1.0L   /* GG Calculator patch version variable (1).    */

	/* Main variables: */
	#define MIN_PRECISION               0      /* Minimum precision variable.                  */
	#define MAX_PRECISION               18     /* Maximum precision variable.                  */
	signed char loop1 = 1;                     /* First Loop variable.                         */
	signed int precision = 18;                 /* Precision variable.                          */
	long double n1;                            /* First number variable.                       */
	long double n2;                            /* Second number variable.                      */
	long double result = 0.0L;                 /* Result variable.                             */
	std::string option1;                       /* First option variable.                       */
	std::string sn1;                           /* First string number variable.                */
	std::string sn2;                           /* Second string number variable.               */
	std::string sprecision;                    /* String precision variable.                   */

	/* Commands before main loop: */
	enable_vt_and_utf8();

	/* Main loop: */
	while(loop1 == 1)
	{
		CLEAR_TERMINAL();
		puts("====================================");
		printf("========= CALCULATOR %.0Lf.%.0Lf.%.0Lf =========\n", GG_CALCULATOR_MAJOR_VERSION, GG_CALCULATOR_MINOR_VERSION, GG_CALCULATOR_PATCH_VERSION);
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
		CLEAR_TERMINAL();

		if(option1 == "0")
		{
			loop1 = 2;

			/* Second main loop: */
			while(loop1 == 2)
			{
				puts("=======================================");
				puts("=============== OPTIONS ===============");
				puts("=======================================");
				puts("  [ 0 ] Return");
				printf("  %s[ 1 ] Exit...%s\n", RED_COLOR, BASE_TERMINAL);
				puts("  [ 2 ] Read \"READ-ME\"");
				printf("  [ 3 ] Change precision (actual: %d)\n", precision);
				fputs("\tYour answer: ", stdout);
				std::cin >> std::ws >> option1;

				if(option1 == "0")
				{
					--loop1;
				}

				else if(option1 == "1")
				{
					loop1 = 0, CLEAR_TERMINAL();
				}

				else if(option1 == "2")
				{
					CLEAR_TERMINAL();
					read_me();
				}

				else if(option1 == "3")
				{
					CLEAR_TERMINAL();
					fputs("Type the new value to the precision (base: 6, min: 0, max: 18): ", stdout);
					std::cin >> std::ws >> sprecision;

					precision = atoi(sprecision.c_str());

					if(precision < MIN_PRECISION)
					{
						precision = MIN_PRECISION;
					}

					else if(precision > MAX_PRECISION)
					{
						precision = MAX_PRECISION;
					}

					CLEAR_TERMINAL();
				}

				else if(option1 == "3.14" || option1 == "3.1415" || option1 == "3.14159" || option1 == "3,14" || option1 == "3,1415" || option1 == "3,14159")
				{
					CLEAR_TERMINAL();
					easter_egg_function();
					CLEAR_TERMINAL();
				}

				CLEAR_TERMINAL();
			}
		}

		else if(option1 == "1")
		{
			printf("Type two numbers, both with space to sum it (last account result, %.*Lf): ", precision, result);
			std::cin >> std::ws >> sn1 >> sn2;

			if(sn1 == "lr")
			{
				n1 = result;
			}

			else if(sn1 == "pi")
			{
				n1 = PI_S_L;
			}

			else if(sn1 == "pim")
			{
				n1 = PI_M_L;
			}

			else if(sn1 == "pil")
			{
				n1 = PI_L_L;
			}

			else
			{
				n1 = strtold(sn1.c_str(), NULL);
			}

			if(sn2 == "lr")
			{
				n2 = result;
			}

			else if(sn2 == "pi")
			{
				n2 = PI_S_L;
			}

			else if(sn2 == "pim")
			{
				n2 = PI_M_L;
			}

			else if(sn2 == "pil")
			{
				n2 = PI_L_L;
			}

			else
			{
				n2 = strtold(sn2.c_str(), NULL);
			}

			result = n1 + n2;
			printf("Result: %.*Lf + %.*Lf = %.*Lf\n", precision, n1, precision, n2, precision, result);
			petc();
		}

		else if(option1 == "2")
		{
			printf("Type two numbers, both with space to subtract it (last account result, %.*Lf): ", precision, result);
			std::cin >> std::ws >> sn1 >> sn2;

			if(sn1 == "lr")
			{
				n1 = result;
			}

			else if(sn1 == "pi")
			{
				n1 = PI_S_L;
			}

			else if(sn1 == "pim")
			{
				n1 = PI_M_L;
			}

			else if(sn1 == "pil")
			{
				n1 = PI_L_L;
			}

			else
			{
				n1 = strtold(sn1.c_str(), NULL);
			}

			if(sn2 == "lr")
			{
				n2 = result;
			}

			else if(sn2 == "pi")
			{
				n2 = PI_S_L;
			}

			else if(sn2 == "pim")
			{
				n2 = PI_M_L;
			}

			else if(sn2 == "pil")
			{
				n2 = PI_L_L;
			}

			else
			{
				n2 = strtold(sn2.c_str(), NULL);
			}

			result = n1 - n2;
			printf("Result: %.*Lf - %.*Lf = %.*Lf\n", precision, n1, precision, n2, precision, result);
			petc();
		}

		else if(option1 == "3")
		{
			printf("Type two numbers, both with space to multiply it (last account result, %.*Lf): ", precision, result);
			std::cin >> std::ws >> sn1 >> sn2;

			if(sn1 == "lr")
			{
				n1 = result;
			}

			else if(sn1 == "pi")
			{
				n1 = PI_S_L;
			}

			else if(sn1 == "pim")
			{
				n1 = PI_M_L;
			}

			else if(sn1 == "pil")
			{
				n1 = PI_L_L;
			}

			else
			{
				n1 = strtold(sn1.c_str(), NULL);
			}

			if(sn2 == "lr")
			{
				n2 = result;
			}

			else if(sn2 == "pi")
			{
				n2 = PI_S_L;
			}

			else if(sn2 == "pim")
			{
				n2 = PI_M_L;
			}

			else if(sn2 == "pil")
			{
				n2 = PI_L_L;
			}

			else
			{
				n2 = strtold(sn2.c_str(), NULL);
			}

			result = n1 * n2;
			printf("Result: %.*Lf x %.*Lf = %.*Lf\n", precision, n1, precision, n2, precision, result);
			petc();
		}

		else if(option1 == "4")
		{
			printf("Type two numbers, both with space to make a division (last account result, %.*Lf): ", precision, result);
			std::cin >> std::ws >> sn1 >> sn2;

			if(sn1 == "lr")
			{
				n1 = result;
			}

			else if(sn1 == "pi")
			{
				n1 = PI_S_L;
			}

			else if(sn1 == "pim")
			{
				n1 = PI_M_L;
			}

			else if(sn1 == "pil")
			{
				n1 = PI_L_L;
			}

			else
			{
				n1 = strtold(sn1.c_str(), NULL);
			}

			if(sn2 == "lr")
			{
				n2 = result;
			}

			else if(sn2 == "pi")
			{
				n2 = PI_S_L;
			}

			else if(sn2 == "pim")
			{
				n2 = PI_M_L;
			}

			else if(sn2 == "pil")
			{
				n2 = PI_L_L;
			}

			else
			{
				n2 = strtold(sn2.c_str(), NULL);
			}

			if(n2 == 0.0L)
			{
				printf("%sERROR... The second number can't be 0...%s\n", RED_COLOR, BASE_TERMINAL);
			}

			else
			{
				result = n1 / n2;
				printf("Result: %.*Lf ÷ %.*Lf = %.*Lf\n", precision, n1, precision, n2, precision, result);
			}

			petc();
		}

		else if(option1 == "5")
		{
			printf("Type two numbers, both with space to elevate the left number (last account result, %.*Lf): ", precision, result);
			std::cin >> std::ws >> sn1 >> sn2;

			if(sn1 == "lr")
			{
				n1 = result;
			}

			else if(sn1 == "pi")
			{
				n1 = PI_S_L;
			}

			else if(sn1 == "pim")
			{
				n1 = PI_M_L;
			}

			else if(sn1 == "pil")
			{
				n1 = PI_L_L;
			}

			else
			{
				n1 = strtold(sn1.c_str(), NULL);
			}

			if(sn2 == "lr")
			{
				n2 = result;
			}

			else if(sn2 == "pi")
			{
				n2 = PI_S_L;
			}

			else if(sn2 == "pim")
			{
				n2 = PI_M_L;
			}

			else if(sn2 == "pil")
			{
				n2 = PI_L_L;
			}

			else
			{
				n2 = strtold(sn2.c_str(), NULL);
			}

			result = powl(n1, n2);
			printf("Result: %.*Lf ^ %.*Lf = %.*Lf\n", precision, n1, precision, n2, precision, result);
			petc();
		}

		else if(option1 == "6")
		{
			printf("Type two numbers, both with space to root the left number (last account result, %.*Lf): ", precision, result);
			std::cin >> std::ws >> sn1 >> sn2;

			if(sn1 == "lr")
			{
				n1 = result;
			}

			else if(sn1 == "pi")
			{
				n1 = PI_S_L;
			}

			else if(sn1 == "pim")
			{
				n1 = PI_M_L;
			}

			else if(sn1 == "pil")
			{
				n1 = PI_L_L;
			}

			else
			{
				n1 = strtold(sn1.c_str(), NULL);
			}

			if(sn2 == "lr")
			{
				n2 = result;
			}

			else if(sn2 == "pi")
			{
				n2 = PI_S_L;
			}

			else if(sn2 == "pim")
			{
				n2 = PI_M_L;
			}

			else if(sn2 == "pil")
			{
				n2 = PI_L_L;
			}

			else
			{
				n2 = strtold(sn2.c_str(), NULL);
			}

			printf("Result: %.*Lf √ %.*Lf = ", precision, n1, precision, n2);

			if(n1 < 0.0L)
			{
				result = copysignl(powl(fabsl(n1), 1.0L / n2), n1);
				printf("%.*Lf\n", precision, result);
			}

			else
			{
				result = powl(n1, 1.0L / n2);
				printf("%.*Lf\n", precision, result);
			}

			petc();
		}
	}

	return 0;
}

#endif
