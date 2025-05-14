#include <stdio.h>
#include <string.h>

// Função para calcular o fatorial
unsigned long long fatorial(int n) {
    unsigned long long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Função para verificar se é palíndromo
int ehPalindromo(char palavra[]) {
    int i = 0;
    int j = strlen(palavra) - 1;
    while (i < j) {
        if (palavra[i] != palavra[j]) {
            return 0; // Falso
        }
        i++;
        j--;
    }
    return 1; // Verdadeiro
}

int main() {
    int opcao;

    printf("MENU DE EXERCICIOS\n");
    printf("1 - Sequência de Fibonacci\n");
    printf("2 - Fatoriais\n");
    printf("3 - Verificar Palindromo\n");
    printf("4 - Verificar Substring\n");
    printf("Escolha uma opção (1 a 4): ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        int N;
        printf("Digite a quantidade de termos da sequência de Fibonacci (1 a 50): ");
        scanf("%d", &N);
        if (N < 1 || N > 50) {
            printf("Número inválido.\n");
            return 1;
        }
        int fib[N];
        fib[0] = 0;
        if (N > 1) fib[1] = 1;
        for (int i = 2; i < N; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        printf("Sequência de Fibonacci: ");
        for (int i = 0; i < N; i++) {
            printf("%d", fib[i]);
            if (i < N - 1) printf(", ");
        }
        printf("\n");

    } else if (opcao == 2) {
        int N;
        printf("Digite um número inteiro (1 a 20): ");
        scanf("%d", &N);
        if (N < 1 || N > 20) {
            printf("Número inválido.\n");
            return 1;
        }
        printf("Fatoriais:\n");
        for (int i = 1; i <= N; i++) {
            printf("%d!=%llu\n", i, fatorial(i));
        }

    } else if (opcao == 3) {
        char palavra[101];
        printf("Digite uma palavra: ");
        scanf("%s", palavra);
        if (ehPalindromo(palavra)) {
            printf("A palavra é um palindromo.\n");
        } else {
            printf("A palavra NÃO é um palindromo.\n");
        }

    } else if (opcao == 4) {
        char str1[101], str2[101];
        printf("Digite a primeira string: ");
        scanf("%s", str1);
        printf("Digite a segunda string: ");
        scanf("%s", str2);
        if (strstr(str1, str2)) {
            printf("A segunda string está contida na primeira.\n");
        } else {
            printf("A segunda string NÃO está contida na primeira.\n");
        }

    } else {
        printf("Opção inválida.\n");
    }

    return 0;
}