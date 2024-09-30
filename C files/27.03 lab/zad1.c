#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int size = 10;
    int non_zero_counter = size;

    // scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int)); // create array

    // fill with random numbers
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 5;
        printf("%d%s", arr[i], i < (size - 1) ? ", " : "\n");
    }

    {
        // count zeros
        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] == 0)
            {
                non_zero_counter--;
            }
        }

        // allocate storage for reduced array
        int *temp = (int *)malloc(non_zero_counter * sizeof(int));

        // copy reduced information to reduced array
        int temp_i = 0;

        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] != 0)
            {
                temp[temp_i] = arr[i];
                temp_i++;
            }
        }

        free(arr); // free the old storage

        arr = temp; // assign the new location to the old pointer
    }

    // print
    for (size_t i = 0; i < non_zero_counter; i++)
    {
        printf("%d%s", arr[i], i < (non_zero_counter - 1) ? ", " : "\n");
    }

    free(arr); // free storage

    return 0;
}
