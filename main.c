// https://github.com/YgoRosa/CalculadoraBinaria
// Ygor Rosa - 3ºA 
// Implementação da função de conversão de decimal para binário, octal, hexadecimal e BCD às 22:23 do dia 29/08/2024
// Correção da função Octal e Implementação da função complementado A2, 30/08/24 às 16:25
// Implementação das novas funções referentes a questão 3, as 21:55 - 30/08 também


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
    int bcd[16]; 
    int i = 0;

    printf("Conversao para BCD:\n");

    while (numero > 0) {
        int digito = numero % 10;
        printf("Digito: %d\n", digito);

        bcd[i++] = digito & 1;
        bcd[i++] = (digito & 2) >> 1;
        bcd[i++] = (digito & 4) >> 2;
        bcd[i++] = (digito & 8) >> 3;
        
        numero = numero / 10;
    }

    printf("Numero em BCD: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bcd[j]);
        if (j % 4 == 0) {
            printf(" "); 
        }
    }
    printf("\n\n");
}

void decimalParaComplemento2(int numero) {
    unsigned short complemento2[16];
    int i = 15;

    printf("Conversao para complemento a 2 com 16 bits:\n");

    if (numero < 0) {
        numero = (1 << 16) + numero; 
    }
    while (i >= 0) {
        complemento2[i] = numero % 2;
        numero = numero / 2;
        i--;
    }
    printf("Numero em complemento a 2 com 16 bits: ");
    for (int j = 0; j < 16; j++) {
        printf("%d", complemento2[j]);
    }
    printf("\n\n");
}

void mostrarBitsFloat(float num) {
    int bits;
    bits = *(int*)&num;

    int sinal = (bits >> 31) & 1;
    int expoente = (bits >> 23) & 0xFF;
    int expoenteComVies = expoente - 127;
    int mantissa = bits & 0x7FFFFF;

    printf("Sinal: %d\n", sinal);
    printf("Expoente (com vies): %d\n", expoente);
    printf("Expoente: %d\n", expoenteComVies);
    printf("Fracao: 0x%06X\n", mantissa);
}

void mostrarBitsDouble(double num) {
    long long int bits;
    bits = *(long long int*)&num; 

    int sinal = (bits >> 63) & 1;
    int expoente = (bits >> 52) & 0x7FF;
    int expoenteComVies = expoente - 1023;
    long long int mantissa = bits & 0xFFFFFFFFFFFFF;

    printf("Sinal: %d\n", sinal);
    printf("Expoente (com vies): %d\n", expoente);
    printf("Expoente: %d\n", expoenteComVies);
    printf("Fracao: 0x%013llX\n", mantissa);
}

int main() {
    int numero;
    float numeroFloat;
    double numeroDouble;

    printf("Digite um numero decimal: ");
    scanf("%d", &numero);

    decimalParaBinario(numero);
    decimalParaOctal(numero);
    decimalParaHexadecimal(numero);
    decimalParaBCD(numero);
    decimalParaComplemento2(numero);

    printf("Digite um numero real para converter em float e double: ");
    scanf("%f", &numeroFloat);
    numeroDouble = (double)numeroFloat;

    printf("\n--- Representacao em Float (32 bits) ---\n");
    mostrarBitsFloat(numeroFloat);

    printf("\n--- Representacao em Double (64 bits) ---\n");
    mostrarBitsDouble(numeroDouble);

    return 0;
}