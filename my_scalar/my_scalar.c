#include <stdio.h>

#define MAX_SIZE 100

/* Declaring functions before calling them */
int scalar_product(int u_vector[], int v_vector[], int vector_size);

void print_vector_to_screen(int vec[], int vector_size, char vec_name);

int *get_vectors_values(int vector[], char vector_name, int vector_length);

int main() {
    /* The main function that calls all of the other functions, gets the size of the vectors
       and 2 vectors's values from the user's input and than calculates
     * the inner product for both of the vectors and prints the result to the screen*/

    /* Declaring vectors length, `inner_product` result value, 2 vectors, and vector's names */
    int vector_size, inner_product = 0, u_vector[MAX_SIZE], v_vector[MAX_SIZE];
    char Uvector = 'U', Vvector = 'V';
    printf("\nStarting the program in order to find the inner product of 2 vectors\n");
    
    /*Receiving the length of the vectors*/
    printf("\nPlease insert the size (length) of the vector");
    scanf("%d", &vector_size);
    if (vector_size < 0 || vector_size > MAX_SIZE){
        vector_size = MAX_SIZE;
    }
    printf("\nThe vectors's length will be %d\n", vector_size);

    /* Receiving values from the user and fill them to the vectors */
    printf("\nInsert 2 vector's values - insert a number and click enter,\n"
           "each enter will save the last value you entered in the vector's values, till you reach the limit of values in a vector\n");

    get_vectors_values(u_vector, Uvector, vector_size);
    get_vectors_values(v_vector, Vvector, vector_size);

    printf("\nCalculating the inner product for U and V vectors\n");
    inner_product = scalar_product(u_vector, v_vector, vector_size);
    printf("\nThe inner product for U and V vectors is: %d\n", inner_product);
    printf("\nEnd of program run\n");
    return 0;
}

int scalar_product(int u_vector[], int v_vector[], int vector_size) {
    /* A function that gets 2 vectors and the max_size (length) of them both,
     * and goes over their values to calculate the inner product and returns it*/
    int i, result = 0;
    for (i = 0; i < vector_size; ++i) {
        result += u_vector[i] * v_vector[i];
    }
    return result;
}

void print_vector_to_screen(int vec[], int vector_size, char vec_name) {
    /* A function that goes over the vector's values and print them to the screen*/
    int i;
    printf("\nThe values of the %c vector are:\n", vec_name);
    for (i = 0; i < vector_size; i++) {
        printf("%d ", vec[i]);
    }
}

int *get_vectors_values(int vector[], char vector_name, int vector_length) {
    /* A function that lets the user insert the vector's values*/
    int i;
    printf("\nPlease enter the %c vector's values\n", vector_name);
    for (i = 0; i < vector_length; ++i) {
        scanf("%d", &vector[i]);
    }
    /*Printing the vector that the user just entered*/
    print_vector_to_screen(vector, vector_length, vector_name);
    return vector;
}