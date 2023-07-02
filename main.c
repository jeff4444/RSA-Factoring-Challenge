#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long long find_factor(long long num) {
    if (num <= 3) {
        if (num >= 0) {
            return num;
        }
    }
    if (num % 2 == 0) {
        return 2;
    }
    if (num % 3 == 0) {
        return 3;
    }
    long long end = (long long)sqrt(num);
    for (long long i = 5; i <= end; i += 6) {
        if (num % i == 0) {
            return i;
        }
        if (num % (i + 2) == 0) {
            return i + 2;
        }
    }
    return -1;
}

void print_fact(long long num) {
    long long fact = find_factor(num);
    if (fact == -1) {
        printf("%lld=1*%lld\n", num, num);
    }
    else {
        long long fact2 = num / fact;
        printf("%lld=%lld*%lld\n", num, fact2, fact);
    }
}

int main(int argc, char* argv[]) {
    clock_t start_time = clock();
    char* file_path = argv[1];
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("File not found: %s\n", file_path);
        return 1;
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        long long num = atoll(line);
        print_fact(num);
    }
    fclose(file);
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the elapsed time
    printf("Elapsed time: %f seconds\n", elapsed_time);

    return 0;
}

