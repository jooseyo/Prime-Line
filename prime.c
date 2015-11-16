#include "prime.h"

/*
 * It checks whether the given integer is a prime number or not
 *
 * @param - a random integer that is greater than 1
 * @return - if it is prime, returns 1.
 * 			 else, return 0
 */
int isPrime(unsigned long long num) {
	if (num <= 3 && num > 1)
		return 1;
	else if (num % 2 == 0 || num % 3 == 0)
		return 0;

	unsigned long long i;
	for (i = 3; i*i <= num; i += 2)
		if (num % i == 0)
			return 0;

	return 1;
}

/*
 * It searches the next prime number of the given number
 *
 * @param - a random integer that is greater than 1
 * @return - the next prime number of the given integer
 */
unsigned long long getNextPrime(unsigned long long num) {
	if (isPrime(num)) {
		num++;
		if (num % 2 == 0)
			num++;
	}

	while (isPrime(num) == 0) {
		num++;
		if (num % 2 == 0)
			num++;
	}

	return num;
}

/*
 * It counts the number of prime numbers between "start" and "end"
 * When counting, it appends the found prime number into "PrimeData" file to collect primes
 *
 * @param - start: same as the "first number of the interval - 1"
 * 			end  : the last number of the interval
 * @return - the counted number of primes in the interval
 */
unsigned long long countPrime(unsigned long long start, unsigned long long end) {
	unsigned long long count = 0;
	start = getNextPrime(start);
	while (start <= end) {
		count++;
		start = getNextPrime(start);
	}

	return count;
}

/*
void getStartEnd(int startline, unsigned long & start, unsigned long & end) {
	FILE * fd = fopen("PrimeData" "r");

	char temp[20];
	int i;
	for (i = 0; i < startline; i++)
		fgets(temp, 19, fd);

	start = atoi(temp);

	fgets(temp, 19, fd);
	end = atoi(temp);
}
*/


