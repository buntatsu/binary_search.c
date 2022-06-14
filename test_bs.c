#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "binary_search.h"

#define ASSERT(cond) assert((cond))

int compar(const void *k, const void *v)
{
	return *(int *)k - *(int *)v;
}

void do_test(void)
{
	int arr[] = {
	//   0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15
		 4,  4,  5,  6,  6,  6, 10, 10, 12, 18, 18, 20, 20, 20, 20, 20,
		};
	int nr_of_arr = sizeof(arr) / sizeof(arr[0]);

	printf("## arr[] ##\n");
	printf("index:");
	for (int i = 0; i < nr_of_arr; i++) {
		printf(" %3d", i);
	}
	printf("\n");
	printf("value:");
	for (int i = 0; i < nr_of_arr; i++) {
		printf(" %3d", arr[i]);
	}
	printf("\n");

	#define PRINT_RES(func, key, res) \
		do { \
			printf("%-30s(key=%2d) => ", #func, key); \
			if (res == NULL) \
				printf("NULL\n"); \
			else if ((res - arr) < nr_of_arr) \
				printf("*res=%2d, index=%2zd\n", *res, res - arr); \
			else \
				printf("*res=--, index=%2zd\n", res - arr); \
		} while(0)

	int *res;
	size_t index;

	{
		printf("--------\n");
		int key = 1;

		res = binary_search(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res == NULL);
		PRINT_RES(binary_search, key, res);

		res = binary_search_lower_most(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res == NULL);
		PRINT_RES(binary_search_lower_most, key, res);

		res = binary_search_upper_most(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res == NULL);
		PRINT_RES(binary_search_upper_most, key, res);

		res = binary_search_lower_bound(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search_lower_bound, key, res);
		ASSERT(*res == 4 && (res - arr) == 0);

		res = binary_search_upper_bound(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search_upper_bound, key, res);
		ASSERT(*res == 4 && (res - arr) == 0);
	}

	{
		printf("--------\n");
		int key = 4;

		res = binary_search(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search, key, res);
		index = res - arr;
		ASSERT(*res == 4 && (0 <= index && index <= 1));

		res = binary_search_lower_most(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search_lower_most, key, res);
		ASSERT(*res == 4 && (res - arr) == 0);

		res = binary_search_upper_most(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search_upper_most, key, res);
		ASSERT(*res == 4 && (res - arr) == 1);

		res = binary_search_lower_bound(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search_lower_bound, key, res);
		ASSERT(*res == 4 && (res - arr) == 0);

		res = binary_search_upper_bound(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search_upper_bound, key, res);
		ASSERT(*res == 5 && (res - arr) == 2);
	}

	{
		printf("--------\n");
		int key = 8;

		res = binary_search(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res == NULL);
		PRINT_RES(binary_search, key, res);

		res = binary_search_lower_most(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res == NULL);
		PRINT_RES(binary_search_lower_most, key, res);

		res = binary_search_upper_most(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res == NULL);
		PRINT_RES(binary_search_upper_most, key, res);

		res = binary_search_lower_bound(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search_lower_bound, key, res);
		ASSERT(*res == 10 && (res - arr) == 6);

		res = binary_search_upper_bound(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search_upper_bound, key, res);
		ASSERT(*res == 10 && (res - arr) == 6);
	}

	{
		printf("--------\n");
		int key = 20;

		res = binary_search(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search, key, res);
		index = res - arr;
		ASSERT(*res == 20 && (11 <= index && index <= 15));

		res = binary_search_lower_most(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search_lower_most, key, res);
		ASSERT(*res == 20 && (res - arr) == 11);

		res = binary_search_upper_most(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search_upper_most, key, res);
		ASSERT(*res == 20 && (res - arr) == 15);

		res = binary_search_lower_bound(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search_lower_bound, key, res);
		ASSERT(*res == 20 && (res - arr) == 11);

		res = binary_search_upper_bound(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search_upper_bound, key, res);
		ASSERT((res - arr) == 16);
	}

	{
		printf("--------\n");
		int key = 99;

		res = binary_search(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res == NULL);
		PRINT_RES(binary_search, key, res);

		res = binary_search_lower_most(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res == NULL);
		PRINT_RES(binary_search_lower_most, key, res);

		res = binary_search_upper_most(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res == NULL);
		PRINT_RES(binary_search_upper_most, key, res);

		res = binary_search_lower_bound(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search_lower_bound, key, res);
		ASSERT((res - arr) == 16);

		res = binary_search_upper_bound(&key, arr, nr_of_arr, sizeof(int), compar);
		ASSERT(res != NULL);
		PRINT_RES(binary_search_upper_bound, key, res);
		ASSERT((res - arr) == 16);
	}
}

int main(void)
{
	do_test();
	return 0;
}
