#include <stdlib.h>

int dub(int x)
{
	return x * 2;
}

int addndub(int x, int y)
{
	int add = x + y;
	return dub(add);
}

int main() {
	int x = 1;
	int y = 2;
	int z = addndub(x, y);

	return z;
}
