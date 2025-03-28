#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    int binary[32], i = 0;
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }
    printf("Binary: ");
    for (i = i - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to convert binary to decimal
int binaryToDecimal(char binary[]) {
    int decimal = 0, base = 1, length = strlen(binary);
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int n) {
    printf("Hexadecimal: %X\n", n);
}

// Function to convert octal to binary
void octalToBinary(int n) {
    int decimal = 0, i = 0, rem;
    char binary[32];
    while (n != 0) {
        rem = n % 10;
        decimal += rem * (1 << (i * 3)); // Convert octal to decimal
        i++;
        n = n / 10;
    }
    decimalToBinary(decimal); // Convert decimal to binary
}

// Function to convert octal to decimal
int octalToDecimal(int n) {
    int decimal = 0, base = 1, rem;
    while (n > 0) {
        rem = n % 10;
        decimal += rem * base;
        n = n / 10;
        base = base * 8;
    }
    return decimal;
}

int main() {
    int choice, num;
    char binary[32];

    do {
        printf("\nNumber System Converter\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Octal to Binary\n");
        printf("5. Octal to Decimal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Decimal to Binary
                printf("Enter a decimal number: ");
                scanf("%d", &num);
                decimalToBinary(num);
                break;

            case 2:
                // Binary to Decimal
                printf("Enter a binary number: ");
                scanf("%s", binary);
                printf("Decimal: %d\n", binaryToDecimal(binary));
                break;

            case 3:
                // Decimal to Hexadecimal
                printf("Enter a decimal number: ");
                scanf("%d", &num);
                decimalToHexadecimal(num);
                break;

            case 4:
                // Octal to Binary
                printf("Enter an octal number: ");
                scanf("%d", &num);
                octalToBinary(num);
                break;

            case 5:
                // Octal to Decimal
                printf("Enter an octal number: ");
                scanf("%d", &num);
                printf("Decimal: %d\n", octalToDecimal(num));
                break;

            case 6:
                // Exit
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
