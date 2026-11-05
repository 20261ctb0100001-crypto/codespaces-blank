#include <stdio.h>

int main(void) {
    int par[5], impar[5];
    int valor, i, qtdPar = 0, qtdImpar = 0;

    for (i = 0; i < 15; i++) {
        scanf("%d", &valor);

        if (valor % 2 == 0) {
            par[qtdPar] = valor;
            qtdPar++;

            if (qtdPar == 5) {
                for (int j = 0; j < 5; j++)
                    printf("par[%d] = %d\\n", j, par[j]);
                qtdPar = 0;
            }
        } else {
            impar[qtdImpar] = valor;
            qtdImpar++;

            if (qtdImpar == 5) {
                for (int j = 0; j < 5; j++)
                    printf("impar[%d] = %d\\n", j, impar[j]);
                qtdImpar = 0;
            }
        }
    }

    for (i = 0; i < qtdImpar; i++)
        printf("impar[%d] = %d\\n", i, impar[i]);

    for (i = 0; i < qtdPar; i++)
        printf("par[%d] = %d\\n", i, par[i]);

    return 0;
}
