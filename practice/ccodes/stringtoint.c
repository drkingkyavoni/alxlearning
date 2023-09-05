#include <stdio.h>

int stringToInt(const char* s) {
    int res = 0;
    int sign = 1;

    if (*s == '-') {
        sign = -1;
        s++;
    }

	while (*s)
	{
        if (*s >= '0' && *s <= '9') {
            res = (10 * res) + (*s - '0');
        } else {
            break;
        }
        s++;
    }

    return res * sign;
}

int main() {
    const char* str = "12345";
    int result = stringToInt(str);
    printf("Converted integer: %d\n", result);
    return 0;
}
