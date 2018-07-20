// Including User Defined Header file which contains all Macros, Preprocessor Directive and Function Declarations
#include "sorting.h"

/*
 This function will perform below activities:
 1. Takes input from User for size of array and choice of sorting algorithm
 2. Generate array of random numbers according to the specified conditions
 3. Calling respective sorting functions and print the original & sorted arrays
*/
int main() {

    printf(BLU"\n--------------- SORTING PROGRAM __ NITESH MISHRA --------------- \n\n"RST);

    // Variable Declaration and Initialization
    int array_size = 0;
    int sorting_choice = 0;
    char is_retry = 'n';
    bool is_error = false;
    bool is_sorting_done = false;
    int i, j, k;

    printf(GRN"Enter Number of Input Data ('Size Limit = [1, 1000]') --> "RST);
    scanf("%d", &array_size);

    // General information about Sorting Algorithms supported by this program
    PRINT_SORTING_INFORMATION;

    printf(GRN"Enter Choice for Sorting Algorithm ('Choices = [1, 2, 3, 4]') --> "RST);
    scanf("%d", &sorting_choice);

    // Display error when array size is not in specified limit
    if (array_size < 1 || array_size > 1000) {
        printf(RED"\n\nERROR ::::: Number of Input Data is not Valid ::: "YLW"'Size Limit = [1, 1000]' ... !!! \n"RST);
        is_error = true;
    }

    // Display error when choice of sorting algorithm is not valid
    if (sorting_choice != 1 && sorting_choice != 2 && sorting_choice != 3 && sorting_choice != 4) {
        printf(RED"\nERROR ::::: Choice for Sorting Algorithm is not Valid ::: "YLW"'Choices = [1, 2, 3, 4]' ... !!! \n"RST);
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
        srand(time(NULL));

        // Generating array of random integers in the specified limit according to respective conditions
        if (array_size <= ARRAY_SIZE_CONST) {
            for (i = 0; i < array_size; i++) {
                array_elements[i] = (1 + (rand() % LIMIT_CONST_MAX));
            }
        } else {
            for (i = 0; i < array_size; i++) {
                array_elements[i] = (1 + (rand() % SHRT_MAX));
            }
        }

        //
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
        case EXCHANGE_SORT_CHOICE:
            printf(MAG"\n\n**********---------- EXCHANGE SORTING ----------********** \n\n"RST);
            printf(CYN"Original Array Elements --> \t"RST);
            print_array_elements(array_elements, array_size);
            // Callling Exchange Sort Function
            exchange_sort(array_elements, array_size);
            is_sorting_done = true;
            break;
        case INSERTION_SORT_CHOICE:
            printf(MAG"\n\n**********---------- INSERTION SORTING ----------********** \n\n"RST);
            printf(CYN"Original Array Elements --> \t"RST);
            print_array_elements(array_elements, array_size);
            // Callling Insertion Sort Function
            insertion_sort(array_elements, array_size);
            is_sorting_done = true;
            break;
        case MERGE_SORT_CHOICE:
            printf(MAG"\n\n**********---------- MERGE SORTING ----------********** \n\n"RST);
            printf(CYN"Original Array Elements --> \t"RST);
            print_array_elements(array_elements, array_size);
            // Callling Merge Sort Function
            merge_sort(array_elements, array_size);
            if (array_size == 1) {
                // Calling function to print visualization pattern for sorting process
                print_visualization_pattern(array_elements, array_size);
            }
            is_sorting_done = true;
            break;
        case RANDOMIZED_QUICK_SORT_CHOICE:
            printf(MAG"\n\n**********----------  RANDOMIZED QUICK SORTING ----------********** \n\n"RST);
            printf(CYN"Original Array Elements --> \t"RST);
            print_array_elements(array_elements, array_size);
            // Callling Randomized Quick Sort Function
            randomized_quick_sort(array_elements, array_size);
            // Calling function to print visualization pattern for sorting process
            print_visualization_pattern(array_elements, array_size);
            is_sorting_done = true;
            break;
        default:
            break;
    }

    return is_sorting_done;
}

/*
 Function to perform sorting using Exchange Sort Algorithm
*/
int exchange_sort(int array_elements[], int array_size) {

    // Variable Declaration and Initialization
    int i, j;

    for (i = 0; i < array_size; i++) {
        // Calling function to print visualization pattern for sorting process
        print_visualization_pattern(array_elements, array_size);
        for (j = i + 1; j < array_size; j++) {
            if (array_elements[i] > array_elements[j]) {
                // Macro to swap two input numbers
                SWAP(array_elements[i], array_elements[j]);
            }
        }
    }

    return 0;
}

/*
  Function to perform sorting using Insertion Sort Algorithm
*/
int insertion_sort(int array_elements[], int array_size) {

    // Variable Declaration and Initialization
    int i, j;

    for (i = 1; i < array_size; i++) {
        // Calling function to print visualization pattern for sorting process
        print_visualization_pattern(array_elements, array_size);
        for (j = i; j > 0 && array_elements[j] < array_elements[j - 1]; j--) {
            // Macro to swap two input numbers
            SWAP(array_elements[j], array_elements[j - 1]);
        }
    }

    // Calling function to print visualization pattern for sorting process
    print_visualization_pattern(array_elements, array_size);

    return 0;
}

/*
  Function to perform sorting using Merge Sort Algorithm
*/
int merge_sort(int array_elements[], int array_size) {

    // Variable Declaration and Initialization
    int i, j;
    int first_size = floor(array_size / 2);
    int second_size = array_size - first_size;
    int first_array[first_size];
    int second_array[second_size];

    // Base Condition for Merge Sort Recursion
    if (array_size > 1) {
        // Putting elements in First Array and Second Array from Original Array
        for (i = 0; i < first_size; i++) {
            first_array[i] = array_elements[i];
        }
        for (j = 0; j < second_size; j++) {
            second_array[j] = array_elements[first_size + j];
        }

        // Recursive call for Merge Sort with First and Second arrays respectively
        merge_sort(first_array, first_size);
        merge_sort(second_array, second_size);
        // Combining First and Second arrays and putting them in Original Array after sorting
        merge_sort_combine(first_array, second_array, array_elements, first_size, second_size);

        // Calling function to print visualization pattern for sorting process
        print_visualization_pattern(array_elements, array_size);
    }

    return 0;
}

/*
 This function combines two input arrays and provides sorted original array
*/
int merge_sort_combine(int first_array[], int second_array[], int array_elements[], int first_size, int second_size) {

    // Variable Declaration and Initialization
    int i = 0, j = 0, k = 0;

    // Logic to combine two arrays in sorting manner
    while (i < first_size && j < second_size) {
        if (first_array[i] < second_array[j]) {
            array_elements[k] = first_array[i];
            i++;
        } else {
            array_elements[k] = second_array[j];
            j++;
        }
        k++;
    }

    // Logic to merge remaining elements of First and Second arrays acccording to conditions
    if (i >= first_size) {
        while (j < second_size) {
            array_elements[k] = second_array[j];
            j++;
            k++;
        }
    }
    if (j >= second_size) {
        while (i < first_size) {
            array_elements[k] = first_array[i];
            i++;
            k++;
        }
    }

    return 0;
}

/*
  Function to perform sorting using Randomized Quick Sort Algorithm
*/
int randomized_quick_sort(int array_elements[], int array_size) {

    // Variable Declaration and Initialization
    int i, j = 0, k = 0;
    int first_limit, second_limit;
    int pivot_item, random_index;

    // Base Condition for Randomized Quick Sort
    if (array_size > 1) {
        // Logic to generate Random Pivot item using random index of the input array and swap with first position of array
        srand(time(NULL));
        random_index = (rand() % array_size);
        if (random_index > 0 && random_index < array_size) {
            SWAP(array_elements[0], array_elements[random_index]);
        }

        // Swaping first two elements of the array acording to the specified condition
        if (array_elements[0] > array_elements[1]) {
            // Macro to swap two input numbers
            SWAP(array_elements[0], array_elements[1]);
        }

        // Pivot Item --> First Element of the array
        pivot_item = array_elements[k];

        // Logic to compare array elements with Pivot Item and partitioning the elements accordingly
        for (i = 0; i < array_size; i++) {
            if (i > 1 && array_elements[i] < pivot_item) {
                j++;
                // Macro to swap two input numbers
                SWAP(array_elements[i], array_elements[j]);
            }
        }
        // Swapping pivot item to make sure that every less array elements are on the left of pivot item
        if (i == array_size && j > 0) {
            // Macro to swap two input numbers
            SWAP(array_elements[k], array_elements[j]);
        }

        // Initializing the limits for partition arrays
        first_limit = j;
        second_limit = array_size - (j + 1);
        int first_array[first_limit], second_array[second_limit], third_array[THIRD_ARRAY_SIZE];

        // Partitioning the three arrays, First, Second and Third array
        third_array[k] = array_elements[j];
        for (i = 0; i < first_limit; i++) {
            first_array[i] = array_elements[i];
        }
        for (i = 0; i < second_limit; i++) {
            second_array[i] = array_elements[j + 1 + i];
        }

        // Sorting the elements of First Array and Second Array according to the conditions
        if (first_limit == ARRAY_LIMIT_MIN) {
            if (first_array[k] > first_array[k + 1]) {
                // Macro to swap two input numbers
                SWAP(first_array[k], first_array[k + 1]);
            }
        }
        if (second_limit == ARRAY_LIMIT_MIN) {
            if (second_array[k] > second_array[k + 1]) {
                // Macro to swap two input numbers
                SWAP(second_array[k], second_array[k + 1]);
            }
        }

        // Calling function to print visualization pattern for sorting process
        print_visualization_pattern(array_elements, array_size);

        // Recursively calling Randomized Quick Sort for First and Second Arrays
        randomized_quick_sort(first_array, first_limit);
        randomized_quick_sort(second_array, second_limit);
        // Quick Sort Concatenation for First, Second and Third Array
        quick_sort_concatenation(first_array, second_array, third_array, first_limit, second_limit, array_elements);
    }

    return 0;
}

/*
 This function is used to concatenate three input arrays in specified order with respective conditions
*/
int quick_sort_concatenation(int first_array[], int second_array[], int third_array[], int first_limit, int second_limit, int array_elements[]) {

    // Variable Declaration and Initialization
    int i, k = 0;

    // Logic to concatenate elements of First, Third and Second arrays as per the specified conditions
    for (i = 0; i < first_limit; i++, k++) {
        array_elements[k] = first_array[i];
    }
    array_elements[k] = third_array[0];
    k++;
    for (i = 0; i < second_limit; i++) {
        array_elements[k] = second_array[i];
        k++;
    }

    return 0;
}

/*
 This function prints all the elements of the array passed as parameter, on the console output
*/
int print_array_elements(int array_elements[], int array_size) {

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
