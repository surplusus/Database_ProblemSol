#include <stdio.h>

void update(int *a, int *b) {
	int tmp = *a;
	*a = *a + *b;
	if (*a > tmp)
		*b = tmp - *b;
	else
		*b = tmp + *b;
	if (*b < 0) *b = -(*b);
}

int main() {
	int a, b;
	int *pa = &a, *pb = &b;

	scanf("%d %d", &a, &b);
	update(pa, pb);
	printf("%d\n%d", a, b);

	return 0;
}

