#ifndef SORTING_HPP
#define SORTING_HPP

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
#define LIMIT_CONST_MAX 15
#define EXCHANGE_SORT_CHOICE 1
#define INSERTION_SORT_CHOICE 2
#define MERGE_SORT_CHOICE 3
#define RANDOMIZED_QUICK_SORT_CHOICE 4
#define ARRAY_LIMIT_MIN 2
#define THIRD_ARRAY_SIZE 1

// Macro to swap two numbers using Bit_Wise operator (^ XOR)
#define SWAP(first_num, second_num)                 \
        (first_num) = (first_num) ^ (second_num);   \
        (second_num) = (second_num) ^ (first_num);  \
        (first_num) = (first_num) ^ (second_num);

// Macro to print information regarding supported sorting algorithm by the program
#define PRINT_SORTING_INFORMATION                       \
    printf(GRN"\n\nList of Sorting Algorithms::: \n"    \
                "\t 1. Exchange Sort \n"                \
                "\t 2. Insertion Sort \n"               \
                "\t 3. Merge Sort \n"                   \
                "\t 4. Randomized Quick Sort \n\n"RST);

// Function and Global Variable  Declarations
bool sort_array_elements(int array_elements[], int array_size, int sorting_choice);

int exchange_sort(int array_elements[], int array_size);

int insertion_sort(int array_elements[], int array_size);

int merge_sort(int array_elements[], int array_size);

int merge_sort_combine(int first_array[], int second_array[], int array_elements[], int first_size, int second_size);

int randomized_quick_sort(int array_elements[], int array_size);

int quick_sort_concatenation(int first_array[], int second_array[], int third_array[], int first_limit, int second_limit, int array_elements[]);

int print_array_elements(int array_elements[], int array_size);

int print_visualization_pattern(int array_elements[], int array_size);

bool is_visualization_required = false;

#endif
