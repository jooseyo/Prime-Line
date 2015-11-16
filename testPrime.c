#include <assert.h>
#include "prime.h"

void test_isPrime() {
	unsigned long long primes[] = {2, 3, 5, 7, 11};
	int i;
	for (i = 0; i < 5; i++)
		assert(isPrime(primes[i]) == 1);

	unsigned long long nonPrimes[] = {4, 6, 8, 9, 10};
	for (i = 0; i < 5; i++)
		assert(isPrime(nonPrimes[i]) == 0);

	assert(isPrime(295) == 0);
	assert(isPrime(195) == 0);
	assert(isPrime(27) == 0);

	printf("test_isPrime passed\n");
}

void test_getNextPrime() {
	assert(getNextPrime((unsigned long long) 2) == (unsigned long long) 3);
	assert(getNextPrime((unsigned long long) 3) == (unsigned long long) 5);
	assert(getNextPrime((unsigned long long) 4) == (unsigned long long) 5);
	assert(getNextPrime((unsigned long long) 5) == (unsigned long long) 7);
	assert(getNextPrime((unsigned long long) 6) == (unsigned long long) 7);
	assert(getNextPrime((unsigned long long) 7) == (unsigned long long) 11);
	assert(getNextPrime((unsigned long long) 8) == (unsigned long long) 11);
	assert(getNextPrime((unsigned long long) 9) == (unsigned long long) 11);

	printf("test_getNextPrime passed\n");
}

void test_countPrime() {
	assert(countPrime((unsigned long long) 5, (unsigned long long) 7) == (unsigned long long) 1);
	assert(countPrime((unsigned long long) 7, (unsigned long long) 11) == (unsigned long long) 1);
	assert(countPrime((unsigned long long) 1, (unsigned long long) 11) == (unsigned long long) 5);
	assert(countPrime((unsigned long long) 2, (unsigned long long) 11) == (unsigned long long) 4);

	printf("test_countPrime passed\n");
}

int main() {
	test_isPrime();
	test_getNextPrime();
	test_countPrime();
}
