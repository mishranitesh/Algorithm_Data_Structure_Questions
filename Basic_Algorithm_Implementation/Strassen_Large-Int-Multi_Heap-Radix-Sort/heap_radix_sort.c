// Including User Defined Header file which contains all Macros, Preprocessor Directive and Function Declarations
#include "program_header.h"

/*
 This function will perform below activities:
 1. Takes input from User for size of array and choice of sorting algorithm
 2. Generate array of random numbers according to the specified conditions
 3. Calling respective sorting functions and print the original & sorted arrays
*/
int main() {

    printf(MAG"\n-------------------------------------- PROGRAMMING ASSIGNMENT - 2 - PART : 3 - (Heap and Radix Sort) __ NITESH MISHRA -------------------------------------- \n\n"RST);

    // Variable Declaration and Initialization
    int array_size = 0;
    int sorting_choice = 0;
    char is_retry = 'n';
    bool is_error = false;
    bool is_sorting_done;
    int i;

    printf(GRN"Enter Number of Input Data ('Size Limit = [1, 1000]') --> "RST);
    scanf("%d", &array_size);

    // General information about Sorting Algorithms supported by this program
    PRINT_SORTING_INFORMATION;

    printf(GRN"Enter Choice for Sorting Algorithm ('Choices = [1, 2]') --> "RST);
    scanf("%d", &sorting_choice);

    // Display error when array size is not in specified limit
    if (array_size < 1 || array_size > 1000) {
        printf(RED"\n\nERROR ::::: Number of Input Data is not Valid ::: 'Size Limit = [1, 1000]' ... !!! \n"RST);
        is_error = true;
    }

    // Display error when choice of sorting algorithm is not valid
    if (sorting_choice != 1 && sorting_choice != 2) {
        printf(RED"\nERROR ::::: Choice for Sorting Algorithm is not Valid ::: 'Choices = [1, 2]' ... !!! \n"RST);
        is_error = true;
    }

    if (is_error) {
        // Restart the program execution when Error occurs & user wants to retry
        printf(CYN"\n\nDo you want to retry (Y/N) ? --> "RST);
        scanf("%s", &is_retry);
        if (is_retry == 'y' || is_retry == 'Y') {
            main();
        } else {
            printf(YLW"\nTHANK YOU for using my Sorting Program !!\n"
                           "                       ----- Nitesh Mishra !! \n\n"RST);
        }
    } else {
        int array_elements[array_size];

        // Logic to initialize Random Number Generator as per timestamp so that rand() generates different random numbers
        srand((unsigned int) time(NULL));

        // Generating array of random integers in the specified limit according to respective conditions
        if (array_size <= ARRAY_SIZE_CONST) {
            for (i = 0; i < array_size; i++) {
                array_elements[i] = (1 + (rand() % LIMIT_CONST_MAX_15));
            }
        } else {
            if (sorting_choice == 2) {
                // Generate Random Number [0, 999] for Radix Sort
                for (i = 0; i < array_size; i++) {
                    array_elements[i] = (1 + (rand() % LIMIT_CONST_MAX_999));
                }
            } else {
                // Generate Random Number [0, SHORT MAX] for Heap Sort
                for (i = 0; i < array_size; i++) {
                    array_elements[i] = (1 + (rand() % SHRT_MAX));
                }
            }
        }

        // Set flag is array size is <= 20
        if (array_size <= ARRAY_SIZE_CONST) {
            is_visualization_required = true;
        }

        // Calling respective sorting algorithm functions according to user's choice
        is_sorting_done = sort_array_elements(array_elements, array_size, sorting_choice);

        // Printing the sorted array if sorting has been completed
        if (is_sorting_done) {
            printf(CYN"\nSorted Array Elements --> \t"RST);
            print_array_elements(array_elements, array_size);
        }

        printf("\n\n");
    }

    return 0;
}

/*
 This function takes sorting choice as one of the parameter and accordingly calls the respective Sorting Functions
*/
bool sort_array_elements(int array_elements[], int array_size, int sorting_choice) {

    // Variable Declaration and Initialization
    bool is_sorting_done = false;

    // Selection of respective Sorting Algorithms as per User's choice
    switch (sorting_choice) {
        case HEAP_SORT_CHOICE:
            printf(MAG"\n\n*************************--------------- HEAP SORTING ---------------************************* \n\n"RST);
            printf(CYN"Original Array Elements --> \t"RST);
            print_array_elements(array_elements, array_size);
            original_array_size = array_size;
            // Calling Heap Sort Function
            heap_sort(array_elements, array_size);
            is_sorting_done = true;
            break;
        case RADIX_SORT_CHOICE:
            printf(MAG"\n\n*************************--------------- RADIX SORTING ---------------************************* \n\n"RST);
            printf(CYN"Original Array Elements --> \t"RST);
            print_array_elements(array_elements, array_size);
            // Calling Radix Sort Function
            radix_sort(array_elements, array_size);
            is_sorting_done = true;
            break;
        default:
            break;
    }

    return is_sorting_done;
}

/*
 Function to perform sorting using Heap Sort Algorithm
*/
int heap_sort(int array_elements[], int array_size) {

    int i;

    // Calling function to print visualization pattern for sorting process
    print_visualization_pattern(array_elements, array_size);

    // Build Max-Heap for essential binary tree
    build_max_heap(array_elements, array_size);

    for (i = array_size - 1; i > 0; --i) {
        // Calling function to print visualization pattern for sorting process
        print_visualization_pattern(array_elements, array_size);
        SWAP(array_elements[i], array_elements[0]);
        max_heapify(array_elements, i - 1, 0);
    }

    if (array_size != 1) {
        // Calling function to print visualization pattern for sorting process
        print_visualization_pattern(array_elements, array_size);
    }

    return 0;
}

/*
 This function will build Max-Heap from any essential complete binary tree
*/
int build_max_heap(int array_elements[], int array_size) {

    int i, node_order_num;

    // Calculating node from where Build Max Heap will start
    node_order_num = (int) (floor(array_size / 2) - 1);

    for (i = node_order_num; i >= 0; --i) {
        max_heapify(array_elements, array_size, i);
    }

    return 0;
}

/*
 Function to max heapify the array elements
*/
int max_heapify(int array_elements[], int array_size, int node_order) {

    int left_child_order, right_child_order, large_node_order;

    // Logic to find left and right child node of parent node in tree
    left_child_order = (2 * node_order) + 1;
    right_child_order = ((2 * node_order) + 1) + 1;

    // Logic to find largest value among Parent, Left Child and Right Child nodes
    if (left_child_order <= array_size
        && array_elements[left_child_order] > array_elements[node_order]) {
        large_node_order = left_child_order;
    } else {
        large_node_order = node_order;
    }
    if (right_child_order < original_array_size && right_child_order <= array_size
        && array_elements[right_child_order] > array_elements[large_node_order]) {
        large_node_order = right_child_order;
    }

    // Logic to recursively perform max-heapify algorithm
    if (large_node_order != node_order) {
        SWAP(array_elements[large_node_order], array_elements[node_order]);
        max_heapify(array_elements, array_size, large_node_order);
    }

    return 0;
}

/*
 Function to perform sorting using Radix Sort Algorithm
*/
int radix_sort(int array_elements[], int array_size) {

    int digit_counter, maximum_element;

    // Finding maximum element among all the array elements
    maximum_element = get_maximum_element(array_elements, array_size);

    for (digit_counter = 1; (maximum_element / digit_counter) > 0; digit_counter *= 10) {
        // Calling function to print visualization pattern for sorting process
        print_visualization_pattern(array_elements, array_size);
        counting_sort(array_elements, array_size, digit_counter);
    }

    if (array_size != 1) {
        // Calling function to print visualization pattern for sorting process
        print_visualization_pattern(array_elements, array_size);
    }

    return 0;
}

/*
 Function to get Largest Element in an array
*/
int get_maximum_element(int array_elements[], int array_size) {

    int i, max_num = 0;

    // Logic to get largest element from an array
    for (i = 0; i < array_size; i++) {
        if (array_elements[i] > max_num) {
            max_num = array_elements[i];
        }
    }

    return max_num;
}

/*
 Function to perform Counting Sort on the provided digit count
*/
int counting_sort(int array_elements[], int array_size, int digit_counter) {

    int i;
    int sorted_array_elements[array_size];

    // Initialization of Auziliary Counting Array with 0
    int aux_counting_array[10] = {0};

    // Setting count of items in Auxiliary Counting Array
    for (i = 0; i < array_size; i++) {
        aux_counting_array[(array_elements[i] / digit_counter) % 10] += 1;
    }

    // Setting offset values in Auxiliary Counting Array
    for (i = 1; i <= 9; i++) {
        aux_counting_array[i] = aux_counting_array[i] + aux_counting_array[i - 1];
    }

    // Putting elements in sorted array according to offset counting values
    for (i = array_size - 1; i >= 0; --i) {
        sorted_array_elements[aux_counting_array[(array_elements[i] / digit_counter) % 10] - 1] = array_elements[i];
        aux_counting_array[(array_elements[i] / digit_counter) % 10] -= 1;
    }

    // Coping sorted array elements in Original Array
    for (i = 0; i < array_size; i++) {
        array_elements[i] = sorted_array_elements[i];
    }

    return 0;
}

/*
 This function prints all the elements of the array passed as parameter, on the console output
*/
int print_array_elements(int array_elements[], int array_size) {

    // Logic to print array elements on the console output
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array_elements[i]);
    }

    printf("\n");
    return 0;
}

/*
 This function prints the visualization pattern of array elements in the form of '*' as per the specified condition
*/
int print_visualization_pattern(int array_elements[], int array_size) {

    // Logic to print visulization "*" according to specified conditions on the console output
    if (is_visualization_required && array_size <= ARRAY_SIZE_CONST) {
        printf("\n\n");
        for (int i = 0; i < array_size; i++) {
            for (int j = 0; j < array_elements[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
