#include <stdio.h>

void itoa(int, char*, int);
int len(char*);
void reverse(char*);

int main() {
    int i = 987654321;
    char result[32];
    itoa(i, result, 10);

    printf("2024(base 10): %s\n", result);

    itoa(i, result, 30);
    printf("2024(base 30): %s\n", result);

    itoa(i, result, 2);
    printf("2024(base 2): %s\n", result);
    return 0;
}

/**
 *
 * @param buffer
 * @return
 */
int len(char * buffer) {
    int i = 0;
    while (buffer[i] != '\0') {
        i++;
    }
    return i;
}

/**
 *
 * @param buffer
 */
void reverse(char * buffer) {
    int i, j;
    char tmp;
    for (i=0, j=len(buffer) - 1; i<j; i++, j--) {
        tmp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = tmp;
    }
}

/**
 *
 * @param number
 * @param buffer
 * @param radix
 */
void itoa(int number, char * buffer, int radix) {
    char * alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int i = 0;
    int rem;
    do {
        buffer[i++] =
                    (rem = number % radix) < 10
                        ? rem + '0'
                        : alphabet[rem - 10]
        ;
    } while ((number /= radix) > 0);
    buffer[i++] = '\0';
    reverse(buffer);
}