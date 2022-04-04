#include <stdio.h>

/*Declaring on the function in the exercise before calling them in main function*/
unsigned long get_num(char val_name);

long unsigned addition_bitwise_operation(unsigned long x, unsigned long y);

int count_similar_turned_on_bits(unsigned long val);

void printBinary(unsigned long val);

int main() {
    /*The main function gets 2 unsigned long numbers from the user, prints the values in decimal and binary to the screen,
     * checks how many turned on bits there are in the same spots of the two numbers and prints the counted number*/
    /*Declaring 2 unsigned longs to be set with values by the user, and also 2 char values for the naming and an int for the result*/
    unsigned long x, y, added_result;
    char x_name = 'x', y_name = 'y';
    int counted_similar_bits;
    printf("\nHello user, please enter a value for 2 unsigned long values in the next rows.\n");
    printf("This program will calculate the similarity of the turned on bits\nbetween the two values and will "
           "return to you the number of turned on bits in similar spots in those 2 values \n");
    x = get_num(x_name);
    y = get_num(y_name);
    /*finds the similar turned on bits between the 2 values and creates a new binary with only those bits turned on*/
    added_result = addition_bitwise_operation(x, y);
    printf("\n\nStarting to count similar turned-on bits...");
    counted_similar_bits = count_similar_turned_on_bits(added_result);
    printf("\nThere are %d similar turned on bits between x and y binary values!\n", counted_similar_bits);
    return 0;
}

unsigned long get_num(char val_name) {
    /*This function gets a decimal value from the user and prints it in decimal and binary to the screen*/
    unsigned long val;
    printf("\nPlease enter a number for %c: ", val_name);
    scanf("%lu", &val);
    printf("The number you just entered is: %lu\n", val);
    printBinary(val);
    return val;
}

int count_similar_turned_on_bits(unsigned long val) {
    /*This function gets 1 unsigned long values and finds the number of turned on bits */
    unsigned mask = 1;
    int counted_bits = 0;
    while (val) {
        if (val & mask) {
            counted_bits += 1;
        }
        /*moving unsigned long int, x and y 1 bit to the right*/
        val >>= mask;
    }
    return counted_bits;
}

void printBinary(unsigned long val) {
    /*This function gets an unsigned long value and prints it's binary value to the screen*/
    unsigned long mask = 1;
    printf("This number in binary is: ");
    mask <<= 63;
    while (mask) {
        if ((val & mask) == 0) {
            printf("0");
        } else {
            printf("1");
        }
        mask >>= 1;
    }

}

long unsigned addition_bitwise_operation(unsigned long x, unsigned long y) {
    /* This function does a bitwise ADD between the 2 unsigned long values */
    return x & y;
}