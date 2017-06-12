#include <stdio.h>

void itoa(int, char *, int);

int atoi(char *, int);

int len(char *);

void reverse(char *);

int main() {
    int i = 987654321;
    char result[32];
    itoa(i, result, 10);

    printf("2024(base 10): %s\n", result);

    itoa(i, result, 30);
    printf("2024(base 30): %s\n", result);

    itoa(i, result, 2);
    printf("2024(base 2): %s\n", result);

    atoi("2024", 10);
    return 0;
}

/**
 *
 * @param buffer
 * @return
 */
int len(char *buffer) {
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
void reverse(char *buffer) {
    int i, j;
    char tmp;
    for (i = 0, j = len(buffer) - 1; i < j; i++, j--) {
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
void itoa(int number, char *buffer, int radix) {
    char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int rem, i = 0;
    short sign = number > 0;
    do {
        buffer[i++] = (rem = number % radix) < 10
                      ? rem + '0'
                      : alphabet[rem - 10];
    } while ((number /= radix) > 0);
    if (!sign) {
        buffer[i++] = '-';
    }
    buffer[i++] = '\0';
    reverse(buffer);
}

int pow(int number, int n) {
    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        return -1;
    }

    int result = number;

    for (int i=1; i < n; i++) {
        result*=number;
    }

    //printf("pow(%d, %d)=%d\n", number, n, result);

    return result;
}

int atoi(char *buffer, int radix) {
    int result=0, length = len(buffer), tmp;
    for (int i = length - 1; i >= 0; i--) {
        tmp = buffer[i] - '0';
        if (tmp >= 0 && tmp < radix) {
            result += tmp * pow(radix, length - i - 1);
        } else if (i==0 && buffer[i] == '-') {
            result *= -1;
        } else {
            return -1;
        }
    }

    printf("%d\n", result);
    return result;
}