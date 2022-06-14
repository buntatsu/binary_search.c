#include <stddef.h>
#include "binary_search.h"

// same as C stdlib::bsearch()
void *binary_search(
	const void *key, const void *base,
	size_t nmemb, size_t size,
	int (*compar)(const void *k, const void *v)
)
{
	size_t mid = nmemb;
	const char *leftp = base;
	const char *midp;
	int cmp;

	while (mid > 0) {
		midp = leftp + (mid / 2) * size;
		cmp = (*compar)(key, midp);
		if (cmp == 0) {
			return (void *)midp;
		}
		if (cmp > 0) {
			leftp = midp + size;
			mid--;
		}
		mid = mid / 2;
	}

	return NULL;
}

void *binary_search_lower_most(
	const void *key, const void *base,
	size_t nmemb, size_t size,
	int (*compar)(const void *k, const void *v)
)
{
	size_t mid = nmemb;
	const char *leftp = base;
	const char *midp;
	int cmp;

	while (mid > 0) {
		midp = leftp + (mid / 2) * size;
		cmp = (*compar)(key, midp);
		if (cmp > 0) {
			leftp = midp + size;
			mid--;
		}
		mid = mid / 2;
	}

	if (leftp >= ((char *)base + nmemb * size)
		|| (*compar)(key, leftp) != 0) {
		return NULL;
	}

	return (void *)leftp;
}

void *binary_search_upper_most(
	const void *key, const void *base,
	size_t nmemb, size_t size,
	int (*compar)(const void *k, const void *v)
)
{
	size_t mid = nmemb;
	const char *leftp = base;
	const char *rightp = (char *)base + (nmemb - 1) * size;
	const char *midp;
	int cmp;

	while (mid > 0) {
		midp = leftp + (mid / 2) * size;
		cmp = (*compar)(key, midp);
		if (cmp >= 0) {
			leftp = midp + size;
			mid--;
		} else {
			rightp = midp - size;
		}
		mid = mid / 2;
	}

	if (rightp < (char *)base
		|| (*compar)(key, rightp) != 0) {
		return NULL;
	}

	return (void *)rightp;
}

// same as C++ std::lower_bound().
void *binary_search_lower_bound(
	const void *key, const void *base,
	size_t nmemb, size_t size,
	int (*compar)(const void *k, const void *v)
)
{
	size_t mid = nmemb;
	const char *leftp = base;
	const char *midp;
	int cmp;

	while (mid > 0) {
		midp = leftp + (mid / 2) * size;
		cmp = (*compar)(key, midp);
		if (cmp > 0) {
			leftp = midp + size;
			mid--;
		}
		mid = mid / 2;
	}

	return (void *)leftp;
}

// same as C++ std::upper_bound().
void *binary_search_upper_bound(
	const void *key, const void *base,
	size_t nmemb, size_t size,
	int (*compar)(const void *k, const void *v)
)
{
	size_t mid = nmemb;
	const char *leftp = base;
	const char *midp;
	int cmp;

	while (mid > 0) {
		midp = leftp + (mid / 2) * size;
		cmp = (*compar)(key, midp);
		if (cmp >= 0) {
			leftp = midp + size;
			mid--;
		}
		mid = mid / 2;
	}

	return (void *)leftp;
}
