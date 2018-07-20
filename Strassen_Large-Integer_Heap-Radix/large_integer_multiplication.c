// Including User Defined Header file which contains all Macros, Preprocessor Directive and Function Declarations
#include "program_header.h"

/*
 This function will perform below activities:
 1. Take input from user as Number of Digits (n = 6k where k is positive integer)
 2. Print error message if input is not in the required range
 3. Randomly generate two numbers with n digits with Most Significant Number as 1 to 9 (not 0)
 3. Call function to perform Large Integer Multiplication (Algorithm to Divide numbers in Two and Three parts)
*/
int main() {

    printf(MAG"\n----------------------------------- Large Integer Multiplication __ NITESH MISHRA ----------------------------------- \n\n"RST);

    // Variable Declaration and Initialization
    char is_retry = 'n';
    bool is_error = false;
    int num_of_digits;

    printf(GRN"Enter Number of Digits (n = 6*k __ k is positive integer) --> "RST);
    scanf("%d", &num_of_digits);

    // Set error flag if matrix size is not in specified limit
    if (num_of_digits <= 0 || num_of_digits % 6 != 0) {
        is_error = true;
    }

    // Display error if error flag is set as true
    if (is_error) {
        printf(RED"\n\nERROR ::::: Invalid Number of Digits ::: 'Digits should be in the form of (6*k) where k is positive integer' ... !!! \n"RST);
        // Restart the program execution when Error occurs & user wants to retry
        printf(CYN"\n\nDo you want to retry (Y/N) ? --> "RST);
        scanf("%s", &is_retry);
        if (is_retry == 'y' || is_retry == 'Y') {
            main();
        } else {
            printf(YLW"\nTHANK YOU for using my Large Integer Multiplication Program !!\n"
                           "                                       ----- Nitesh Mishra !! \n\n"RST);
        }
    } else {

        int i, result_array_digit_count = 2 * num_of_digits;;
        int first_large_num[num_of_digits], second_large_num[num_of_digits];
        int result_large_num_divide_into_two[result_array_digit_count], result_large_num_divide_into_three[result_array_digit_count];

        // Initialize Result Array with 0
        for (i = 0; i < result_array_digit_count; i++) {
            result_large_num_divide_into_two[i] = 0;
            result_large_num_divide_into_three[i] = 0;
        }
        result_num_of_digits = result_array_digit_count;

        // Logic to initialize Random Number Generator as per timestamp so that rand() generates different random numbers
        srand((unsigned int) time(NULL));

        // Logic to generate random numbers of 'n' digits (MSD is between 1 and 9)
        for (i = 0; i < num_of_digits; i++) {
            if (i == num_of_digits - 1) {
                first_large_num[i] = (1 + (rand() % MSD_MAX_LIMIT_9));
                second_large_num[i] = (1 + (rand() % MSD_MAX_LIMIT_9));
            } else {
                first_large_num[i] = rand() % OTHER_MAX_LIMIT_10;
                second_large_num[i] = rand() % OTHER_MAX_LIMIT_10;
            }
        }

        // Printing Number of Digits
        printf(GRN"\n\n------------------------------------------------------------------------------------------------------------------------------------------\n"RST);
        printf("Number of Digits ---> \t%d", num_of_digits);
        printf(GRN"\n--------------------------------------------------------------------------------------------------------------------------------------------\n"RST);

        // Printing First Large Integer Number
        printf(GRN"\n--------------------------------------------------------------------------------------------------------------------------------------------\n"RST);
        printf("First Large Integer Number ---> \t");
        display_large_number(first_large_num, num_of_digits);
        printf(GRN"\n--------------------------------------------------------------------------------------------------------------------------------------------\n"RST);

        // Printing Second Large Integer Number
        printf(GRN"\n--------------------------------------------------------------------------------------------------------------------------------------------\n"RST);
        printf("Second Large Integer Number ---> \t");
        display_large_number(second_large_num, num_of_digits);
        printf(GRN"\n--------------------------------------------------------------------------------------------------------------------------------------------\n"RST);

        // Large Integer Multiplication Algorithm (Divide into two parts)
        large_integer_multiplication_divide_into_two(first_large_num, second_large_num, result_large_num_divide_into_two, num_of_digits);
        // Printing Result Large Integer Number
        printf(CYN"\n---------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("LARGE INTEGER MULTIPLICATION (Numbers are Divided into Two Parts)");
        printf("\n------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("Multiplication Result Large Integer Number ---> \t");
        display_large_number(result_large_num_divide_into_two, result_array_digit_count);
        printf("\n------------------------------------------------------------------------------------------------------------------------------------------------\n"RST);

        // Large Integer Multiplication Algorithm (Divide into three parts)
        large_integer_multiplication_divide_into_three(first_large_num, second_large_num, result_large_num_divide_into_three, num_of_digits);
        // Printing Result Large Integer Number
        printf(YLW"\n----------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("LARGE INTEGER MULTIPLICATION (Numbers are Divided into Three Parts)");
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("Multiplication Result Large Integer Number ---> \t");
        display_large_number(result_large_num_divide_into_three, result_array_digit_count);
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------\n"RST);

        printf(MAG"\n\n------------------------------------------------------------------------------------------------------------------------------------------\n\n"RST);
    }

    return 0;
}

/*
 Implementation of Large Integer Multiplication Algorithm by dividing each numbers into two equal parts
*/
int large_integer_multiplication_divide_into_two(int first_large_num[], int second_large_num[], int result_large_num_divide_into_two[], int digit_count) {

    // Base Condition - if digit count can not split into two parts then perform Standard Array Multiplication operation
    if (digit_count % 2 != 0) {
        standard_array_multiplication(first_large_num, second_large_num, result_large_num_divide_into_two, digit_count);
    } else {
        // Variable Declaration and Initialization
        int i;
        int mid_digit = (int) floor(digit_count / 2);
        int large_num_x[mid_digit], large_num_y[mid_digit], large_num_w[mid_digit], large_num_z[mid_digit];
        int addition_result[result_num_of_digits];
        int equation_part_xw[result_num_of_digits], equation_part_xz[result_num_of_digits], equation_part_wy[result_num_of_digits], equation_part_yz[result_num_of_digits];
        int equation_part_1[result_num_of_digits], equation_part_2[result_num_of_digits];

        // Initialization of all the arrays to 0 in order to prevent calculation over garbage values
        for (i = 0; i < result_num_of_digits; i++) {
            equation_part_xw[i] = 0;
            equation_part_xz[i] = 0;
            equation_part_wy[i] = 0;
            equation_part_yz[i] = 0;
            equation_part_1[i] = 0;
            equation_part_2[i] = 0;
            addition_result[i] = 0;
        }

        // Dividing each input numbers First_Large_Num and Second_Large_Num into two parts
        for (i = 0; i < mid_digit; i++) {
            large_num_x[i] = first_large_num[i];
            large_num_y[i] = first_large_num[i + mid_digit];
            large_num_w[i] = second_large_num[i];
            large_num_z[i] = second_large_num[i + mid_digit];
        }

        // Calculation of [(x*w)]*10^2m
        large_integer_multiplication_divide_into_two(large_num_x, large_num_w, equation_part_xw, mid_digit);
        standard_array_product_with_ten(equation_part_xw, equation_part_1, result_num_of_digits, (2 * mid_digit));

        // Calculation of [(x*z)+(w*y)]*10^m
        large_integer_multiplication_divide_into_two(large_num_x, large_num_z, equation_part_xz, mid_digit);
        large_integer_multiplication_divide_into_two(large_num_w, large_num_y, equation_part_wy, mid_digit);
        standard_array_addition(equation_part_xz, equation_part_wy, addition_result, result_num_of_digits);
        standard_array_product_with_ten(addition_result, equation_part_2, result_num_of_digits, mid_digit);

        // Calculation of [(y*z)]
        large_integer_multiplication_divide_into_two(large_num_y, large_num_z, equation_part_yz, mid_digit);

        // Calculation of [(x*w)]*10^2m + [(x*z)+(w*y)]*10^m
        standard_array_addition(equation_part_1, equation_part_2, addition_result, result_num_of_digits);

        // Result = [(x*w)]*10^2m + [(x*z)+(w*y)]*10^m + [(y*z)]
        standard_array_addition(addition_result, equation_part_yz, result_large_num_divide_into_two, result_num_of_digits);
    }

    return 0;
}

/*
 Implementation of Large Integer Multiplication Algorithm by dividing each numbers into three equal parts
*/
int large_integer_multiplication_divide_into_three(int first_large_num[], int second_large_num[], int result_large_num_divide_into_three[], int digit_count) {

    // Base Condition - if digit count can not split into three parts then perform Standard Array Multiplication operation
    if (digit_count % 3 != 0) {
        standard_array_multiplication(first_large_num, second_large_num, result_large_num_divide_into_three, digit_count);
    } else {
        // Variable Declaration and Initialization
        int i;
        int fraction_digit = (int) floor(digit_count / 3);
        int large_num_x[fraction_digit], large_num_y[fraction_digit], large_num_z[fraction_digit];
        int large_num_a[fraction_digit], large_num_b[fraction_digit], large_num_c[fraction_digit];
        int addition_result_1[result_num_of_digits], addition_result_2[result_num_of_digits], addition_result_3[result_num_of_digits];
        int equation_part_xa[result_num_of_digits], equation_part_xb[result_num_of_digits], equation_part_xc[result_num_of_digits];
        int equation_part_ya[result_num_of_digits], equation_part_yb[result_num_of_digits], equation_part_yc[result_num_of_digits];
        int equation_part_za[result_num_of_digits], equation_part_zb[result_num_of_digits], equation_part_zc[result_num_of_digits];
        int equation_part_1[result_num_of_digits], equation_part_2[result_num_of_digits], equation_part_3[result_num_of_digits], equation_part_4[result_num_of_digits];

        // Initialization of all the arrays to 0 in order to prevent calculation over garbage values
        for (i = 0; i < result_num_of_digits; i++) {
            equation_part_xa[i] = 0;
            equation_part_xb[i] = 0;
            equation_part_xc[i] = 0;
            equation_part_ya[i] = 0;
            equation_part_yb[i] = 0;
            equation_part_yc[i] = 0;
            equation_part_za[i] = 0;
            equation_part_zb[i] = 0;
            equation_part_zc[i] = 0;
            equation_part_1[i] = 0;
            equation_part_2[i] = 0;
            equation_part_3[i] = 0;
            equation_part_4[i] = 0;
            addition_result_1[i] = 0;
            addition_result_2[i] = 0;
            addition_result_3[i] = 0;
        }

        // Dividing each input numbers First_Large_Num and Second_Large_Num into three parts
        for (i = 0; i < fraction_digit; i++) {
            large_num_x[i] = first_large_num[i];
            large_num_y[i] = first_large_num[i + fraction_digit];
            large_num_z[i] = first_large_num[i + fraction_digit + fraction_digit];
            large_num_a[i] = second_large_num[i];
            large_num_b[i] = second_large_num[i + fraction_digit];
            large_num_c[i] = second_large_num[i + fraction_digit + fraction_digit];
        }

        // Calculation of [(x*a)]*10^4m
        large_integer_multiplication_divide_into_three(large_num_x, large_num_a, equation_part_xa, fraction_digit);
        standard_array_product_with_ten(equation_part_xa, equation_part_1, result_num_of_digits, (4 * fraction_digit));

        // Calculation of [(x*b)+(y*a)]*10^3m
        large_integer_multiplication_divide_into_three(large_num_x, large_num_b, equation_part_xb, fraction_digit);
        large_integer_multiplication_divide_into_three(large_num_y, large_num_a, equation_part_ya, fraction_digit);
        standard_array_addition(equation_part_xb, equation_part_ya, addition_result_1, result_num_of_digits);
        standard_array_product_with_ten(addition_result_1, equation_part_2, result_num_of_digits, (3 * fraction_digit));

        // Calculation of [(x*c)+(y*b)+(z*a)]*10^2m
        large_integer_multiplication_divide_into_three(large_num_x, large_num_c, equation_part_xc, fraction_digit);
        large_integer_multiplication_divide_into_three(large_num_y, large_num_b, equation_part_yb, fraction_digit);
        large_integer_multiplication_divide_into_three(large_num_z, large_num_a, equation_part_za, fraction_digit);
        standard_array_addition(equation_part_xc, equation_part_yb, addition_result_1, result_num_of_digits);
        standard_array_addition(addition_result_1, equation_part_za, addition_result_2, result_num_of_digits);
        standard_array_product_with_ten(addition_result_2, equation_part_3, result_num_of_digits, (2 * fraction_digit));

        // Calculation of [(y*c)+(z*b)]*10^m
        large_integer_multiplication_divide_into_three(large_num_y, large_num_c, equation_part_yc, fraction_digit);
        large_integer_multiplication_divide_into_three(large_num_z, large_num_b, equation_part_zb, fraction_digit);
        standard_array_addition(equation_part_yc, equation_part_zb, addition_result_1, result_num_of_digits);
        standard_array_product_with_ten(addition_result_1, equation_part_4, result_num_of_digits, (fraction_digit));

        // Calculation of [(z*c)]
        large_integer_multiplication_divide_into_three(large_num_z, large_num_c, equation_part_zc, fraction_digit);

        // Calculation of [(x*a)]*10^4m + [(x*b)+(y*a)]*10^3m
        standard_array_addition(equation_part_1, equation_part_2, addition_result_1, result_num_of_digits);
        // Calculation of [(x*c)+(y*b)+(z*a)]*10^2m + [(y*c)+(z*b)]*10^m
        standard_array_addition(equation_part_3, equation_part_4, addition_result_2, result_num_of_digits);
        // Calculation of [(x*a)]*10^4m + [(x*b)+(y*a)]*10^3m + [(x*c)+(y*b)+(z*a)]*10^2m + [(y*c)+(z*b)]*10^m
        standard_array_addition(addition_result_1, addition_result_2, addition_result_3, result_num_of_digits);

        // Result = [(x*a)]*10^4m + [(x*b)+(y*a)]*10^3m + [(x*c)+(y*b)+(z*a)]*10^2m + [(y*c)+(z*b)]*10^m + [(z*c)]
        standard_array_addition(addition_result_3, equation_part_zc, result_large_num_divide_into_three, result_num_of_digits);
    }

    return 0;
}

/*
 This function will perform product of input_large_num and 10^num_raise_to_ten and stores output in output_large_num
*/
int standard_array_product_with_ten(int input_large_num[], int output_large_num[], int input_size, int num_raise_to_ten) {

    // Logic to perform multiplication with 10^num_raise_to_ten
    for (int p = num_raise_to_ten; p < input_size; p++) {
        output_large_num[p - num_raise_to_ten] = input_large_num[p];
    }

    return 0;
}

/*
 This function will perform multiplication of two large number array using Standard Algorithm
*/
int standard_array_multiplication(int first_large_num[], int second_large_num[], int result_large_num[], int digit_count) {

    // Variable Declaration and Initialization
    int p, q, temp_num;
    int result_array_digit_count = result_num_of_digits;
    int iter_1, iter_2 = result_array_digit_count;

    // Logic to perform straight multiplication for each array elements
    for (p = digit_count - 1; p >= 0; --p) {
        iter_1 = iter_2 - 1;
        for (q = digit_count - 1; q >= 0; --q) {
            result_large_num[iter_1] = result_large_num[iter_1] + (first_large_num[p] * second_large_num[q]);
            iter_1--;
        }
        iter_2--;
    }

    // Logic to alter result_large_num with manipulation of addition
    for (p = result_array_digit_count - 1; p >= 0; --p) {
        temp_num = result_large_num[p] / 10;
        result_large_num[p] = result_large_num[p] % 10;
        if (temp_num > 0) {
            result_large_num[p - 1] += temp_num;
        }
    }

    return 0;
}

/*
 This function will perform addition of two large number array using Standard Algorithm
*/
int standard_array_addition(int first_large_num[], int second_large_num[], int result_large_num[], int digit_count) {

    int p, temp_num;
    int result_array_digit_count = result_num_of_digits;

    for (p = digit_count - 1; p >= 0; --p) {
        result_large_num[p] = first_large_num[p] + second_large_num[p];
    }

    for (p = result_array_digit_count - 1; p >= 0; --p) {
        temp_num = result_large_num[p] / 10;
        result_large_num[p] = result_large_num[p] % 10;
        if (temp_num > 0) {
            result_large_num[p - 1] += temp_num;
        }
    }

    return 0;
}

/*
 This function will display content of large numbers on the console output
*/
int display_large_number(int large_num[], int digit_count) {

    int is_first_zero = 0;

    for (int p = 0; p < digit_count; p++) {
        if (large_num[p] != 0) {
            is_first_zero = 1;
        }
        if (is_first_zero != 0) {
            printf("%d", large_num[p]);
        }
    }

    return 0;
}
