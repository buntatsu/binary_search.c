#ifndef	_BINARY_SEARCH_H_
#define	_BINARY_SEARCH_H_

void *binary_search(
	const void *key, const void *base,
	size_t nmemb, size_t size,
	int (*compar)(const void *k, const void *v)
);
void *binary_search_lower_most(
	const void *key, const void *base,
	size_t nmemb, size_t size,
	int (*compar)(const void *k, const void *v)
);
void *binary_search_upper_most(
	const void *key, const void *base,
	size_t nmemb, size_t size,
	int (*compar)(const void *k, const void *v)
);
void *binary_search_lower_bound(
	const void *key, const void *base,
	size_t nmemb, size_t size,
	int (*compar)(const void *k, const void *v)
);
void *binary_search_upper_bound(
	const void *key, const void *base,
	size_t nmemb, size_t size,
	int (*compar)(const void *k, const void *v)
);

#endif
