#include <stdio.h>

int main(void) {
    int T, N, soma, i, j;
    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        scanf("%d", &N);
        soma = 0;

        for (j = 1; j <= N / 2; j++) {
            if (N % j == 0)
                soma += j;
        }

        if (soma == N)
            printf("%d eh perfeito\n", N);
        else
            printf("%d nao eh perfeito\n", N);
    }

    return 0;
}
