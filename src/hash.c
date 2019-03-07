
#include "lem-in"

/*
**	http://www.amsoftware.narod.ru/algo2.html
*/

unsigned int	mafast_hash(char *str, unsigned int len)
{
	unsigned int hash = len, i = 0, k;
	long rem = len;
	unsigned char trail;
	const unsigned char * data = (const unsigned char *)str;

	while (rem >= 4) {
		k = *(unsigned int*)data;
		k += i++;
		hash ^= k;
		hash *= 171717;
		data += 4;
		rem -= 4;
	}
	while (rem >= 0) {
		trail = *(unsigned char*)data;
		trail += i++;
		hash ^= trail;
		hash *= 171717;
		data++;
		rem--;
	}
	return hash;
}
