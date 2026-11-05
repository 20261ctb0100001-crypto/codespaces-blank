#include <stdio.h>

int main(void) {
    int T, N, i, j, primo;
    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        scanf("%d", &N);
        primo = (N >= 2);

        for (j = 2; primo && j * j <= N; j++) {
            if (N % j == 0)
                primo = 0;
        }

        if (primo)
            printf("%d eh primo\n", N);
        else
            printf("%d nao eh primo\n", N);
    }

    return 0;
}
