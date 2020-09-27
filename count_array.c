#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int most_common_element(int nums[], size_t length)
{
    int const MAX_SIZE = 100;
    int element_tracker_count[MAX_SIZE];

    int array_len = length / (sizeof(int));

    printf("\n\n\n************** \n\n\nLength of array is %d\n\n", array_len);

    //Initialize all count to zero
    for (int i=0; i < MAX_SIZE; i++)
    {
        element_tracker_count[i] = 0;
    }



    // Initialize the Count of number occuring most, at least one number exists
    int most_number_count = 0;

    int current_number = 0;
    int current_element_count = 0;

       // Initialize the counter for Minimum number that repeats
    int min_number_with_max_count = 0;

    printf("Input Array is: { ");
    // Iterate through the array
    for (int i=0; i < array_len; i++)
    {

        current_number = nums[i];

        if (i != array_len -1)
            printf("%d, ", current_number);
        else
            printf("%d", current_number);  // no comma before final element when printing

        // Increment the corresponding count for the number
        current_element_count = ++element_tracker_count[current_number];

        //printf("Current number is %d with a count of: %d\n", current_number, current_element_count);
    }
    printf (" }\n\n");

    // Iterate through the element_tracker array to find the minimum with max count
    for (int i = MAX_SIZE -1; i >= 0; i--)
    {
        if (element_tracker_count[i] >= most_number_count)
        {
           min_number_with_max_count = i;
           most_number_count = element_tracker_count[i];
        }
    }

    printf("The Minimum number most count is: %d\n\n", most_number_count);
    return min_number_with_max_count;

}

int main(int argc, char *argv[])
{

   int ARRAY_MAX_SIZE = 20;

   time_t t;

   /* Intializes random number generator */
   srand((unsigned) time(&t));

    if (argv[1] == NULL)
    {
        printf("Enter a number less than %d for array size\n", ARRAY_MAX_SIZE);
        return 0;
    }


    int n = atoi(argv[1]);

    if (n > ARRAY_MAX_SIZE)
    {
         printf("Enter a number less than %d for array size\n", ARRAY_MAX_SIZE);
        return 0;
    }

    int random_test_array[n];
    int random_number = 0;

    for (int i = 0; i < n; i++)
    {
        random_number = (int) rand() % 100;
        //printf("%d, ", random_number);

        random_test_array[i] = random_number;
    }


    int test_array1[] = {0, 1, 2, 3, 4, 4, 99};
    int test_array2[] = {1, 4, 9, 9, 4};
    int test_array3[] = {9, 8, 7, 6, 10};
    int test_array4[] = {5};
    int test_array5[] = {15, 50, 10, 20, 10, 20, 20};
    int test_array6[] = {6, 50, 10, 20, 10, 20, 20, 6, 6};
    int test_array7[] = {5, 4, 3, 2, 1, 0};

    int test_array8[] = {5, 4, 3, 2, 2, 2, 1, 0, 0, 0, 0, 24, 99, 45, 0, 2, 2, 2, 2, 23, 9};
    int test_array9[] = { 16, 89, 46, 70, 8, 57, 84, 80, 97, 27 };

    int min_common_element = most_common_element(random_test_array, sizeof(random_test_array));

    printf("Most Common Minimum Number Element in Array is: %d\n", min_common_element);

    return 0;
}