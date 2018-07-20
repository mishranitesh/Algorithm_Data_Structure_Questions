#ifndef PROGRAM_HPP
#define PROGRAM_HPP

// Predefined Libraries used in program
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

// Constants to print, outputs in color format to the Console
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YLW "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define RST "\x1B[0m"

// Constants in the program for calculations and conditions
#define ARRAY_SIZE_CONST 20
#define LIMIT_CONST_MAX_999 999
#define LIMIT_CONST_MAX_15 15
#define HEAP_SORT_CHOICE 1
#define RADIX_SORT_CHOICE 2
#define MSD_MAX_LIMIT_9 9
#define OTHER_MAX_LIMIT_10 10

// Macro to swap two numbers using Bit_Wise operator (^ XOR)
#define SWAP(first_num, second_num)             \
        first_num = first_num ^ second_num;     \
        second_num = second_num ^ first_num;    \
        first_num = first_num ^ second_num;

// Macro to print information regarding supported sorting algorithm by the program
#define PRINT_SORTING_INFORMATION                       \
    printf(GRN"\n\nList of Sorting Algorithms::: \n"    \
                "\t 1. Heap Sort \n"                    \
                "\t 2. Radix Sort \n\n"RST);

// Macro to limit maximum random integer
#define MAX_RANDOM_INTEGER(x) (sqrt(INT_MAX / x))

// Global Variable  Declarations
int original_array_size;
bool is_visualization_required = false;
int max_random_num;
int original_matrix_size;
int rec_matrix_size;
int display_matrix_size;
int mul_matrix_size;
int add_matrix_size;
int sub_matrix_size;
int result_num_of_digits;

// Function Declaration
bool sort_array_elements(int array_elements[], int array_size, int sorting_choice);

int heap_sort(int array_elements[], int array_size);

int build_max_heap(int array_elements[], int array_size);

int max_heapify(int array_elements[], int array_size, int node_order);

int radix_sort(int array_elements[], int array_size);

int get_maximum_element(int array_elements[], int array_size);

int counting_sort(int array_elements[], int array_size, int digit_counter);

int print_array_elements(int array_elements[], int array_size);

int print_visualization_pattern(int array_elements[], int array_size);

int strassen_matrix_multiplication(int **first_matrix, int **second_matrix, int **result_matrix, int rec_size);

int standard_matrix_multiplication(int **first_matrix, int **second_matrix, int **result_matrix, int mul_size);

int standard_matrix_addition(int **first_matrix, int **second_matrix, int **add_result_matrix, int add_size);

int standard_matrix_subtraction(int **first_matrix, int **second_matrix, int **sub_result_matrix, int sub_size);

int display_matrix_elements(int **matrix, int display_size);

int large_integer_multiplication_divide_into_two(int first_large_num[], int second_large_num[], int result_large_num_divide_into_two[], int digit_count);

int large_integer_multiplication_divide_into_three(int first_large_num[], int second_large_num[], int result_large_num_divide_into_three[], int digit_count);

int standard_array_product_with_ten(int input_large_num[], int output_large_num[], int input_size, int num_raise_to_ten);

int standard_array_multiplication(int first_large_num[], int second_large_num[], int result_large_num[], int digit_count);

int standard_array_addition(int first_large_num[], int second_large_num[], int result_large_num[], int digit_count);

int display_large_number(int large_num[], int digit_count);


// Macros to Print Useful Information on Console Output (regarding Strassen's Algorithm)
#define PRINT_DIVIDED_FIRST_SECOND_ARRAYS \
    display_matrix_size = divided_size; \
    printf("\n\nFirst_11 --> \n\t\t\t\t"); \
    display_matrix_size = divided_size; \
    display_matrix_elements(f_matrix_11, display_matrix_size); \
    printf("\n\nFirst_12 --> \n\t\t\t\t"); \
    display_matrix_size = divided_size; \
    display_matrix_elements(f_matrix_12, display_matrix_size); \
    printf("\n\nFirst_21 --> \n\t\t\t\t"); \
    display_matrix_size = divided_size; \
    display_matrix_elements(f_matrix_21, display_matrix_size); \
    printf("\n\nFirst_22 --> \n\t\t\t\t"); \
    display_matrix_size = divided_size; \
    display_matrix_elements(f_matrix_22, display_matrix_size); \
    printf("\n\nSecond_11 --> \n\t\t\t\t"); \
    display_matrix_size = divided_size; \
    display_matrix_elements(s_matrix_11, display_matrix_size); \
    printf("\n\nSecond_12 --> \n\t\t\t\t"); \
    display_matrix_size = divided_size; \
    display_matrix_elements(s_matrix_12, display_matrix_size); \
    printf("\n\nSecond_21 --> \n\t\t\t\t"); \
    display_matrix_size = divided_size; \
    display_matrix_elements(s_matrix_21, display_matrix_size); \
    printf("\n\nSecond_22 --> \n\t\t\t\t"); \
    display_matrix_size = divided_size; \
    display_matrix_elements(s_matrix_22, display_matrix_size);

#define PRINT_M1_M2_M3_M4_M5_M6_M7_ARRAYS \
    printf("\n\nM1 --> \n\t\t\t\t"); \
    display_matrix_elements(m1, display_matrix_size); \
    printf("\n\nM2 --> \n\t\t\t\t"); \
    display_matrix_elements(m2, display_matrix_size); \
    printf("\n\nM3 --> \n\t\t\t\t"); \
    display_matrix_elements(m3, display_matrix_size); \
    printf("\n\nM4 --> \n\t\t\t\t"); \
    display_matrix_elements(m4, display_matrix_size); \
    printf("\n\nM5 --> \n\t\t\t\t"); \
    display_matrix_elements(m5, display_matrix_size); \
    printf("\n\nM6 --> \n\t\t\t\t"); \
    display_matrix_elements(m6, display_matrix_size); \
    printf("\n\nM7 --> \n\t\t\t\t"); \
    display_matrix_elements(m7, display_matrix_size);

#define PRINT_C11_C12_C21_C22_ARRAYS \
    printf("\n\nC11 --> \n\t\t\t\t"); \
    display_matrix_elements(c11, display_matrix_size); \
    printf("\n\nC12 --> \n\t\t\t\t"); \
    display_matrix_elements(c12, display_matrix_size); \
    printf("\n\nC21 --> \n\t\t\t\t"); \
    display_matrix_elements(c21, display_matrix_size); \
    printf("\n\nC22 --> \n\t\t\t\t"); \
    display_matrix_elements(c22, display_matrix_size);

#define PRINT_X_Y_W_Z \
    printf("\n\nDisplay x --> "); \
    display_large_number(large_num_x, mid_digit); \
    printf("\n\nDisplay y --> "); \
    display_large_number(large_num_y, mid_digit); \
    printf("\n\nDisplay w --> "); \
    display_large_number(large_num_w, mid_digit); \
    printf("\n\nDisplay z --> "); \
    display_large_number(large_num_z, mid_digit);

#endif