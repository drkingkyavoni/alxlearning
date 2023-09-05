#include <stdio.h>

int count_elements(const char **arr) {
    int count = 0;
    while (arr[count] != NULL) {
        count++;
    }

	if (arr[count] == NULL)
    	count++;
    return count;
}

int main() {
    const char *strArray[] = {"apple", "orange", "banana", "grape", NULL};

    int numElements = count_elements(strArray);

    printf("Number of elements in the string array: %d\n", numElements);

    return 0;
}
