// Including User Defined Header file which contains all Macros, Preprocessor Directive and Function Declarations
#include "program_header.h"

/*
 This function will perform below activities:
 1. Take input from user as Size of the Matrices (n = 2^k format where k = 0, 1, 2, .... 10)
 2. Print error message if input is not in the required range [1, 1024]
 3. Randomly generate Matrix elements using rand() function
 3. Call functions to perform Matrix Multiplication using Standard Algorithm and Strassen's Algorithm
*/
int main() {

    printf(MAG"\n------------------------- Strassen's Matrix Multiplication __ NITESH MISHRA ------------------------- \n\n"RST);

    // Variable Declaration and Initialization
    char is_retry = 'n';
    bool is_error = false;

    printf(GRN"Enter size of Matrix (n = 2^k __ n should be in range [1, 1024]) --> "RST);
    scanf("%d", &original_matrix_size);

    // Set error flag if matrix size is not in specified limit
    if (original_matrix_size == 1 || original_matrix_size == 2) {
        is_error = false;
    } else {
        if (original_matrix_size < 1 || original_matrix_size > 1024) {
            is_error = true;
        } else {
            int temp_size = original_matrix_size;
            if (temp_size % 2 != 0) {
                is_error = true;
            } else {
                while ((temp_size % 2 == 0) && temp_size > 1) {
                    temp_size = temp_size / 2;
                }
                if (temp_size != 1) {
                    is_error = true;
                }
            }
        }
    }

    // Display error if error flag is set as true
    if (is_error) {
        printf(RED"\n\nERROR ::::: Invalid Matrix Size ::: 'Matrix Size Limit = [1, 1024] and it should be in the form of 2^k (k = 0, 1, 2, .... 10)' ... !!! \n"RST);
        // Restart the program execution when Error occurs & user wants to retry
        printf(CYN"\n\nDo you want to retry (Y/N) ? --> "RST);
        scanf("%s", &is_retry);
        if (is_retry == 'y' || is_retry == 'Y') {
            main();
        } else {
            printf(YLW"\nTHANK YOU for using my Matrix Multiplication Program !!\n"
                           "                                     ----- Nitesh Mishra !! \n\n"RST);
        }
    } else {
        int i, j;

        // Logic to initialize Random Number Generator as per timestamp so that rand() generates different random numbers
        srand((unsigned int) time(NULL));

        // Logic to generate maximum random integer number to prevent integer overflow
        max_random_num = (int) floor(MAX_RANDOM_INTEGER(original_matrix_size));

        // Matrix Variable Declaration and Memory Allocation
        int **first_matrix = malloc(original_matrix_size * sizeof(*first_matrix));
        int **second_matrix = malloc(original_matrix_size * sizeof(*first_matrix));
        int **result_matrix_standard = malloc(original_matrix_size * sizeof(*result_matrix_standard));
        int **result_matrix_strassen = malloc(original_matrix_size * sizeof(*result_matrix_strassen));
        for (i = 0; i < original_matrix_size; i++) {
            first_matrix[i] = malloc(original_matrix_size * sizeof(*(first_matrix[i])));
            second_matrix[i] = malloc(original_matrix_size * sizeof(*(second_matrix[i])));
            result_matrix_standard[i] = malloc(original_matrix_size * sizeof(*(result_matrix_standard[i])));
            result_matrix_strassen[i] = malloc(original_matrix_size * sizeof(*(result_matrix_strassen[i])));
        }

        // Initialization of First and Second Matrix with randomly generated integers
        for (i = 0; i < original_matrix_size; i++) {
            for (j = 0; j < original_matrix_size; j++) {
                first_matrix[i][j] = (1 + (rand() % max_random_num));
                second_matrix[i][j] = (1 + (rand() % max_random_num));
            }
        }

        // Printing elements of First Matrix
        printf(GRN"\n\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t First Matrix Elements \n");
        printf("----------------------------------------------------------------------------------------------------------------------------------------\n\t"RST);
        display_matrix_size = original_matrix_size;
        display_matrix_elements(first_matrix, display_matrix_size);

        // Printing elements of Second Matrix
        printf(GRN"\n\n-----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t Second Matrix Elements \n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------------\n\t"RST);
        display_matrix_size = original_matrix_size;
        display_matrix_elements(second_matrix, display_matrix_size);

        // Calculating Matrix Multiplication using Strassen's Algorithm
        rec_matrix_size = original_matrix_size;
        strassen_matrix_multiplication(first_matrix, second_matrix, result_matrix_strassen, rec_matrix_size);
        // Printing elements of Matrix Result using Strassen's algorithm
        printf(CYN"\n\n-------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t STRASSEN'S MATRIX MULTIPLICATION ALGORITHM \n");
        printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t Result Matrix Strassen Elements \n");
        printf("-------------------------------------------------------------------------------------------------------------------------------------------\n\t"RST);
        display_matrix_size = original_matrix_size;
        display_matrix_elements(result_matrix_strassen, display_matrix_size);

        // Calculating Matrix Multiplication using Standard Algorithm
        mul_matrix_size = original_matrix_size;
        standard_matrix_multiplication(first_matrix, second_matrix, result_matrix_standard, mul_matrix_size);
        // Printing elements of Matrix Result using Standard algorithm
        printf(YLW"\n\n-----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t STANDARD MATRIX MULTIPLICATION ALGORITHM \n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t Result Matrix Standard Elements \n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------------\n\t"RST);
        display_matrix_size = original_matrix_size;
        display_matrix_elements(result_matrix_standard, display_matrix_size);

        // Free Memory Allocation for Matrices
        for (i = 0; i < original_matrix_size; i++) {
            free(first_matrix[i]);
            free(second_matrix[i]);
            free(result_matrix_standard[i]);
            free(result_matrix_strassen[i]);
        }
        free(first_matrix);
        free(second_matrix);
        free(result_matrix_standard);
        free(result_matrix_strassen);

        printf(MAG"\n\n----------------------------------------------------------------------------------------------------------------------------------------\n\n"RST);
    }

    return 0;
}

/*
 Function to perform Matrix Multiplication using Strassen's Algorithm
*/
int strassen_matrix_multiplication(int **first_matrix, int **second_matrix, int **result_matrix, int rec_size) {

    // Perform Matrix Multiplication for (2 X 2) matrices -- Base Condition
    if (rec_size <= 2) {
        mul_matrix_size = rec_size;
        standard_matrix_multiplication(first_matrix, second_matrix, result_matrix, mul_matrix_size);
    } else {
        int i, j;
        int divided_size = rec_size / 2;

        // Declaration and Memory Allocation of First and Second Partition Matrices
        int **f_matrix_11 = malloc(rec_size * sizeof(*f_matrix_11));
        int **f_matrix_12 = malloc(rec_size * sizeof(*f_matrix_12));
        int **f_matrix_21 = malloc(rec_size * sizeof(*f_matrix_21));
        int **f_matrix_22 = malloc(rec_size * sizeof(*f_matrix_22));
        int **s_matrix_11 = malloc(rec_size * sizeof(*s_matrix_11));
        int **s_matrix_12 = malloc(rec_size * sizeof(*s_matrix_12));
        int **s_matrix_21 = malloc(rec_size * sizeof(*s_matrix_21));
        int **s_matrix_22 = malloc(rec_size * sizeof(*s_matrix_22));;

        // Declaration and Memory Allocation of M1, M2, M3, M4, M5, M6, M7 Matrices
        int **m1 = malloc(rec_size * sizeof(*m1));
        int **m2 = malloc(rec_size * sizeof(*m2));
        int **m3 = malloc(rec_size * sizeof(*m3));
        int **m4 = malloc(rec_size * sizeof(*m4));
        int **m5 = malloc(rec_size * sizeof(*m5));
        int **m6 = malloc(rec_size * sizeof(*m6));
        int **m7 = malloc(rec_size * sizeof(*m7));

        // Declaration and Memory Allocation of C11, C12, C21, C22 Matrices
        int **c11 = malloc(rec_size * sizeof(*c11));
        int **c12 = malloc(rec_size * sizeof(*c12));
        int **c21 = malloc(rec_size * sizeof(*c21));
        int **c22 = malloc(rec_size * sizeof(*c22));

        // Declaration and Memory Allocation of General Matrices used for calculations
        int **add_matrix_1 = malloc(rec_size * sizeof(*add_matrix_1));
        int **add_matrix_2 = malloc(rec_size * sizeof(*add_matrix_2));
        int **sub_matrix = malloc(rec_size * sizeof(*sub_matrix));

        // Memory Allocation for Matrices
        for (i = 0; i < divided_size; i++) {
            f_matrix_11[i] = malloc(rec_size * sizeof(*f_matrix_11[i]));
            f_matrix_12[i] = malloc(rec_size * sizeof(*f_matrix_12[i]));
            f_matrix_21[i] = malloc(rec_size * sizeof(*f_matrix_21[i]));
            f_matrix_22[i] = malloc(rec_size * sizeof(*f_matrix_22[i]));

            s_matrix_11[i] = malloc(rec_size * sizeof(*s_matrix_11[i]));
            s_matrix_12[i] = malloc(rec_size * sizeof(*s_matrix_12[i]));
            s_matrix_21[i] = malloc(rec_size * sizeof(*s_matrix_21[i]));
            s_matrix_22[i] = malloc(rec_size * sizeof(*s_matrix_22[i]));

            m1[i] = malloc(rec_size * sizeof(*m1[i]));
            m2[i] = malloc(rec_size * sizeof(*m2[i]));
            m3[i] = malloc(rec_size * sizeof(*m3[i]));
            m4[i] = malloc(rec_size * sizeof(*m4[i]));
            m5[i] = malloc(rec_size * sizeof(*m5[i]));
            m6[i] = malloc(rec_size * sizeof(*m6[i]));
            m7[i] = malloc(rec_size * sizeof(*m7[i]));

            c11[i] = malloc(rec_size * sizeof(*c11[i]));
            c12[i] = malloc(rec_size * sizeof(*c12[i]));
            c21[i] = malloc(rec_size * sizeof(*c21[i]));
            c22[i] = malloc(rec_size * sizeof(*c22[i]));

            add_matrix_1[i] = malloc(rec_size * sizeof(*add_matrix_1[i]));
            add_matrix_2[i] = malloc(rec_size * sizeof(*add_matrix_2[i]));
            sub_matrix[i] = malloc(rec_size * sizeof(*sub_matrix[i]));
        }

        // Partition for First Matrix in 4 parts (A11, A12, A21, A22, B11, B12, B21, B22)
        for (i = 0; i < divided_size; i++) {
            for (j = 0; j < divided_size; j++) {
                f_matrix_11[i][j] = first_matrix[i][j];
                f_matrix_12[i][j] = first_matrix[i][j + divided_size];
                f_matrix_21[i][j] = first_matrix[i + divided_size][j];
                f_matrix_22[i][j] = first_matrix[i + divided_size][j + divided_size];

                s_matrix_11[i][j] = second_matrix[i][j];
                s_matrix_12[i][j] = second_matrix[i][j + divided_size];
                s_matrix_21[i][j] = second_matrix[i + divided_size][j];
                s_matrix_22[i][j] = second_matrix[i + divided_size][j + divided_size];
            }
        }

        // Initialization of M1, M2, M3, M4, M5, M6, M7 and other matrices
        for (i = 0; i < divided_size; i++) {
            for (j = 0; j < divided_size; j++) {
                m1[i][j] = 0;
                m2[i][j] = 0;
                m3[i][j] = 0;
                m4[i][j] = 0;
                m5[i][j] = 0;
                m6[i][j] = 0;
                m7[i][j] = 0;
                add_matrix_1[i][j] = 0;
                add_matrix_2[i][j] = 0;
                sub_matrix[i][j] = 0;
            }
        }

        // Calculation for M1
        add_matrix_size = divided_size;
        standard_matrix_addition(f_matrix_11, f_matrix_22, add_matrix_1, add_matrix_size);
        add_matrix_size = divided_size;
        standard_matrix_addition(s_matrix_11, s_matrix_22, add_matrix_2, add_matrix_size);
        rec_matrix_size = divided_size;
        strassen_matrix_multiplication(add_matrix_1, add_matrix_2, m1, rec_matrix_size);

        // Calculation for M2
        add_matrix_size = divided_size;
        standard_matrix_addition(f_matrix_21, f_matrix_22, add_matrix_1, add_matrix_size);
        rec_matrix_size = divided_size;
        strassen_matrix_multiplication(add_matrix_1, s_matrix_11, m2, rec_matrix_size);

        // Calculation for M3
        sub_matrix_size = divided_size;
        standard_matrix_subtraction(s_matrix_12, s_matrix_22, sub_matrix, sub_matrix_size);
        rec_matrix_size = divided_size;
        strassen_matrix_multiplication(f_matrix_11, sub_matrix, m3, rec_matrix_size);

        // Calculation for M4
        sub_matrix_size = divided_size;
        standard_matrix_subtraction(s_matrix_21, s_matrix_11, sub_matrix, sub_matrix_size);
        rec_matrix_size = divided_size;
        strassen_matrix_multiplication(f_matrix_22, sub_matrix, m4, rec_matrix_size);

        // Calculation for M5
        add_matrix_size = divided_size;
        standard_matrix_addition(f_matrix_11, f_matrix_12, add_matrix_1, add_matrix_size);
        rec_matrix_size = divided_size;
        strassen_matrix_multiplication(add_matrix_1, s_matrix_22, m5, rec_matrix_size);

        // Calculation for M6
        sub_matrix_size = divided_size;
        standard_matrix_subtraction(f_matrix_21, f_matrix_11, sub_matrix, sub_matrix_size);
        add_matrix_size = divided_size;
        standard_matrix_addition(s_matrix_11, s_matrix_12, add_matrix_1, add_matrix_size);
        rec_matrix_size = divided_size;
        strassen_matrix_multiplication(sub_matrix, add_matrix_1, m6, rec_matrix_size);

        // Calculation for M7
        sub_matrix_size = divided_size;
        standard_matrix_subtraction(f_matrix_12, f_matrix_22, sub_matrix, sub_matrix_size);
        add_matrix_size = divided_size;
        standard_matrix_addition(s_matrix_21, s_matrix_22, add_matrix_1, add_matrix_size);
        rec_matrix_size = divided_size;
        strassen_matrix_multiplication(sub_matrix, add_matrix_1, m7, rec_matrix_size);

        // Calculation for C11
        add_matrix_size = divided_size;
        standard_matrix_addition(m1, m4, add_matrix_1, add_matrix_size);
        sub_matrix_size = divided_size;
        standard_matrix_subtraction(add_matrix_1, m5, sub_matrix, sub_matrix_size);
        standard_matrix_addition(sub_matrix, m7, c11, divided_size);

        // Calculation for C12
        add_matrix_size = divided_size;
        standard_matrix_addition(m3, m5, c12, add_matrix_size);

        // Calculation for C21
        add_matrix_size = divided_size;
        standard_matrix_addition(m2, m4, c21, add_matrix_size);

        // Calculation for C22
        add_matrix_size = divided_size;
        standard_matrix_addition(m1, m3, add_matrix_1, add_matrix_size);
        sub_matrix_size = divided_size;
        standard_matrix_subtraction(add_matrix_1, m2, sub_matrix, sub_matrix_size);
        standard_matrix_addition(sub_matrix, m6, c22, divided_size);

        // Logic to combine C11, C12, C21 and C22 in Result Matrix
        for (i = 0; i < divided_size; i++) {
            for (j = 0; j < divided_size; j++) {
                result_matrix[i][j] = c11[i][j];
                result_matrix[i][j + divided_size] = c12[i][j];
                result_matrix[i + divided_size][j] = c21[i][j];
                result_matrix[i + divided_size][j + divided_size] = c22[i][j];
            }
        }

        // Free Memory allocation for arrays
        for (i = 0; i < divided_size; i++) {
            free(f_matrix_11[i]);
            free(f_matrix_12[i]);
            free(f_matrix_21[i]);
            free(f_matrix_22[i]);

            free(s_matrix_11[i]);
            free(s_matrix_12[i]);
            free(s_matrix_21[i]);
            free(s_matrix_22[i]);

            free(m1[i]);
            free(m2[i]);
            free(m3[i]);
            free(m4[i]);
            free(m5[i]);
            free(m6[i]);
            free(m7[i]);

            free(c11[i]);
            free(c12[i]);
            free(c21[i]);
            free(c22[i]);

            free(add_matrix_1[i]);
            free(add_matrix_2[i]);
            free(sub_matrix[i]);
        }

        free(f_matrix_11);
        free(f_matrix_12);
        free(f_matrix_21);
        free(f_matrix_22);

        free(s_matrix_11);
        free(s_matrix_12);
        free(s_matrix_21);
        free(s_matrix_22);

        free(m1);
        free(m2);
        free(m3);
        free(m4);
        free(m5);
        free(m6);
        free(m7);

        free(c11);
        free(c12);
        free(c21);
        free(c22);

        free(add_matrix_1);
        free(add_matrix_2);
        free(sub_matrix);
    }

    return 0;
}

/*
 Function to perform Matrix Multiplication using Standard Algorithm
*/
int standard_matrix_multiplication(int **first_matrix, int **second_matrix, int **result_matrix, int mul_size) {

    // Logic to perform Matrix Multiplication using standard algorithm
    for (int p = 0; p < mul_size; p++) {
        for (int q = 0; q < mul_size; q++) {
            result_matrix[p][q] = 0;
            for (int r = 0; r < mul_size; r++) {
                result_matrix[p][q] += first_matrix[p][r] * second_matrix[r][q];
            }
        }
    }

    return 0;
}

/*
 Function to perform Matrix Addition using Standard Algorithm
*/
int standard_matrix_addition(int **first_matrix, int **second_matrix, int **add_result_matrix, int add_size) {

    // Logic to perform Matrix Addition using standard algorithm
    for (int p = 0; p < add_size; p++) {
        for (int q = 0; q < add_size; q++) {
            add_result_matrix[p][q] = first_matrix[p][q] + second_matrix[p][q];
        }
    }

    return 0;
}

/*
 Function to perform Matrix Subtraction using Standard Algorithm
*/
int standard_matrix_subtraction(int **first_matrix, int **second_matrix, int **sub_result_matrix, int sub_size) {

    // Logic to perform Matrix Subtraction using standard algorithm
    for (int p = 0; p < sub_size; p++) {
        for (int q = 0; q < sub_size; q++) {
            sub_result_matrix[p][q] = first_matrix[p][q] - second_matrix[p][q];
        }
    }

    return 0;
}

/*
 Function to display Matrix elements on the console output
*/
int display_matrix_elements(int **input_matrix, int display_size) {

    for (int p = 0; p < display_size; p++) {
        for (int q = 0; q < display_size; q++) {
            printf("\t%d", input_matrix[p][q]);
        }
        printf("\n\t");
    }

    return 0;
}
