#include <stdio.h>

int main(void) {
    int T, N, soma, i, j;

    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        scanf("%d", &N);
        soma = 0;

        if (N > 1)
            soma = 1;

        for (j = 2; j <= N / j; j++) {
            if (N % j == 0) {
                soma += j;
                if (j != N / j)
                    soma += N / j;
            }
        }

        if (soma == N)
            printf("%d eh perfeito\n", N);
        else
            printf("%d nao eh perfeito\n", N);
    }

    return 0;
}
