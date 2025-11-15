#include <stdio.h>  

#include <string.h>  

#include <ctype.h>  

   

int ehPrimo(int n) {  

    int i;  

    if (n < 2) return 0;  

    for (i = 2; i * i <= n; i++) {  

        if (n % i == 0)  

            return 0;  

    }  

    return 1;  

}  

char deslocar(char c, int desloc) {  

    if (isupper(c)) {  

        return 'A' + (c - 'A' + desloc) % 26;  

    } else if (islower(c)) {  

        return 'a' + (c - 'a' + desloc) % 26;  

    }  

    return c;  

}  

int main() {  

    char texto[100];  

    int opcao;  

    int i;  

    printf(" MENU DE CRIPTOGRAFIA \n");  

    printf("1 - Cifra de Cesar\n");  

    printf("2 - Progressao Aritmetica (PA)\n");  

    printf("3 - Progressao Geometrica (PG)\n");  

    printf("4 - Sequencia de Fibonacci\n");  

    printf("5 - Numeros Primos\n");  

    printf("6 - Incrementos\n");  

    printf("\n");  

    printf("Escolha uma opcao: ");  

    scanf("%d", &opcao);  

    getchar();  

    printf("\nDigite o texto: ");  

    fgets(texto, sizeof(texto), stdin);  

    texto[strcspn(texto, "\n")] = '\0';  

    // Variáveis auxiliares  

    int desloc, a1, r, q, termo, f1, f2, prox, num;  

    switch (opcao) {  

        // vai deslocar Vetor escolhido pelo o usuario //  

        case 1:  

            printf("Digite o deslocamento: ");  

            scanf("%d", &desloc);  

            for (i = 0; i < strlen(texto); i++) {  

                texto[i] = deslocar(texto[i], desloc);  

            }  

            break;  

// vai fazer uma soma dos numeros escolhido pelo usuario //  

        case 2:  

            printf("Digite o primeiro termo (a1): ");  

            scanf("%d", &a1);  

            printf("Digite a razao (r): ");  

            scanf("%d", &r);  

            for (i = 0; i < strlen(texto); i++) {  

                termo = a1 + i * r;  

                texto[i] = deslocar(texto[i], termo);  

            }  

            break;  

//Progressão Geométrica //  

// vai fazer a multiplicacao do numero escolhido pelo usuario //  

   

        case 3:  

            printf("Digite o primeiro termo (a1): ");  

            scanf("%d", &a1);  

            printf("Digite a razao (q): ");  

            scanf("%d", &q);  

            termo = a1;  

            for (i = 0; i < strlen(texto); i++) {  

                texto[i] = deslocar(texto[i], termo);  

                termo *= q;  

            }  

            break;  

//Série de Fibonacci é a soma dos numeros anteriores//  

        case 4:  

            f1 = 1;  

            f2 = 1;  

            for (i = 0; i < strlen(texto); i++) {  

                desloc = f1;  

                texto[i] = deslocar(texto[i], desloc);  

                prox = f1 + f2;  

                f1 = f2;  

                f2 = prox;  

            }  

            break;  

// Números Primos  

// vai mostrar os numeros que sao dividido por eles mesmo ou por 1//  

        case 5:  

            num = 2;  

            for (i = 0; i < strlen(texto); i++) {  

                while (!ehPrimo(num)) num++;  

                texto[i] = deslocar(texto[i], num);  

                num++;  

            }  

            break;  

//incrementos//  

        case 6:  

            for (i = 0; i < strlen(texto); i++) {  

                desloc = i + 1;  

                texto[i] = deslocar(texto[i], desloc);  

            }  

            break;  

        default:  

            printf("Opcao invalida!\n");  

            return 0;  

    }  

    printf("\nTexto criptografado: %s\n", texto);  

    return 0;  

} 