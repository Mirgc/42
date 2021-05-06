#include <unistd.h>
#include <stdio.h>
#include "ex00/ft_iterative_factorial.c"
#include "ex01/ft_recursive_factorial.c"
#include "ex02/ft_iterative_power.c"
#include "ex03/ft_recursive_power.c"
#include "ex04/ft_fibonacci.c"
//#include "ex05/ft_sqrt.c"
//#include "ex06/ft_is_prime.c"
#include "ex07/ft_find_next_prime.c"

int main()
{

//	printf("%i\n", ft_iterative_factorial(1));
//	printf("%i\n", ft_recursive_factorial(1));

//	printf("%i\n", ft_iterative_power(0, -1));
//	printf("%i\n", ft_recursive_power(119, -1));

//	printf("%i\n",ft_fibonacci(9));

//	printf("%i\n",ft_sqrt(2147395600));

//	printf("%i\n", ft_is_prime(11));
	printf("%i\n", ft_find_next_prime(2147483643));

	return 0;
}
