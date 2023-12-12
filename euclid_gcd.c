#include <stdio.h>

int euclid(int m, int n)
{
	if (n == 0)
		return 0;
	else if (m == n)
		return m;
	else
	{
		if (m < n)
		{
			m += n;
			n = m - n;
			m -= n;
		}

		m -= n;

		if (m > n)
			return euclid(m, n);
		else
			return euclid(n, m);
	}
}

int main()
{
	int n, m, gcd = 0;

	printf("Enter two positive number M and N: ");
	scanf("%d %d", &m, &n);

	gcd = euclid(m, n);
	if (gcd)
		printf("GCD of %d and %d: %d\n", m, n, gcd);
	else
		printf("They have no GCM.\n");

	return 0;
}
