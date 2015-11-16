#include "prime.h"

int main(int argc, char ** argv) {
	if (argc < 2) {					// if the argument integer is not given,
		printf("No parameter\n");	// It is an error
		exit(1);
	}

/* Start: get start, end, prime */
	FILE * startFd = fopen("startData", "r");

	unsigned long long start, end, prime;

	char temp[20];
	fgets(temp, 19, startFd);
	start = strtoull(temp, NULL, 0);

	fgets(temp, 19, startFd);
	prime = strtoull(temp, NULL, 0);

	end = start + prime;

	fclose(startFd);
/* End: get start, end, prime */

/* Start: count and append to Data */
	FILE * dataFd = fopen("Data", "a");

	int i;
	int bound = atoi(argv[1]);
	for (i = 0; i < bound; i++) {
		fprintf(dataFd, "%llu\n", countPrime(start, end));

		prime = getNextPrime(prime);
		start = end;
		end = start + prime;
	}
/* End: count and append to Data */

/* Start: save the current start value and prime value */
	startFd = fopen("startData", "w");

	fprintf(startFd, "%llu\n", start);
	fprintf(startFd, "%llu\n", prime);
/* End: save the current start value and prime value */
}
