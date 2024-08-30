// https://github.com/YgoRosa/CalculadoraBinaria
// Ygor Rosa - 3ºA 
// Implementação da função de conversão de decimal para binário, octal, hexadecimal e BCD às 22:23 do dia 29/08/2024
//

#include <stdio.h>
#include <stdlib.h>

void decimalParaBinario(int numero) {
    int binario[32];
    int i = 0;
    
    printf("Conversao para binario:\n");
    while (numero > 0) {
        binario[i] = numero % 2;
        printf("%d / 2 = %d, resto = %d\n", numero, numero / 2, numero % 2);
        numero = numero / 2;
        i++;
    }

    printf("Numero em binario: ");
    for (int j = i - 1; j >= 0; j--){
        printf("%d", binario[j]);
    }
    printf("\n\n");
}

void decimalParaOctal(int numero) {
    int octal[32];
    int i = 0;

    printf("Conversao para octal:\n");
    while (numero > 0) {
        octal[i] = numero % 8;
        printf("%d / 8 = %d, resto = %d\n", numero, numero / 8, numero % 8);
        numero = numero / 8;
        i++;
    }

    printf("Numero em octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n\n");
}

void decimalParaHexadecimal(int numero) {
    char hexa[32];
    int i = 0;

    printf("Conversao para hexadecimal:\n");
    while (numero > 0) {
        int temp = numero % 16;
        printf("%d / 16 = %d, resto = %d\n", numero, numero / 16, numero % 16);
        
        if (temp < 10) {
            hexa[i] = temp + 48; 
        } else {
            hexa[i] = temp + 55;  
        }
        numero = numero / 16;
        i++;
    }

    printf("Numero em hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexa[j]);
    }
    printf("\n\n");
}

void decimalParaBCD(int numero) {
    int bcd[32];
    int i = 0;

    printf("Conversao para BCD:\n");
    while (numero > 0) {
        bcd[i] = numero % 10;
        printf("Dígito: %d\n", bcd[i]);
        numero = numero / 10;
        i++;
    }

    printf("Numero em BCD: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%04d ", bcd[j]);
    }
    printf("\n\n");
}

int main() {
    int numero;

    printf("Digite um numero decimal: ");
    scanf("%d", &numero);

    decimalParaBinario(numero);
    decimalParaOctal(numero);
    decimalParaHexadecimal(numero);
    decimalParaBCD(numero);

    return 0;
}