#include <iostream>

#define SIZE 3

void print(int arr[][SIZE], int rows, int cols)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void print(int **arr, int rows, int cols)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void two_Dimensional_Array()
{
    ////////////////////// Static Initialization //////////////////////
    int arr1[3][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Accessing the array
    std::cout << arr1[1][2] << std::endl;

    // Updation
    arr1[1][2] = 10;

    // Array size
    int arr1_rows = sizeof(arr1) / sizeof(*arr1);
    int arr1_cols = sizeof(*arr1) / sizeof(**arr1);

    // Traversal
    for (int i = 0; i < arr1_rows; ++i)
    {
        for(int j = 0; j < arr1_cols; ++j)
        {
            std::cout << arr1[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    // Passing to function
    print(arr1, arr1_rows, arr1_cols);


    ////////////////////// Dynamic Initialization ///////////////////////
    int arr2_rows = 3;
    int arr2_cols = SIZE;

    int** arr2 = new int*[3];

    int num = 1;
    for(int i = 0; i < 3; ++i)
    {
        arr2[i] = new int[SIZE];

        for(int j = 0; j < arr2_cols; ++j)
        {
            arr2[i][j] = num;
            num++;
        }
    }

    // Accessing the array
    std::cout << arr2[1][1] << std::endl;

    // Updation
    arr2[1][1] = 11;

    // Traversal
    for (int i = 0; i < arr2_rows; ++i)
    {
        for(int j = 0; j < arr2_cols; ++j)
        {
            std::cout << arr2[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Passing to function
    print(arr2, arr2_rows, arr2_cols);

    // Deletion (deallocating the memory)
    for (int i = 0; i < SIZE; i++)
        delete[] arr2[i];
    delete[] arr2;
}

int main()
{
    two_Dimensional_Array();

    return 0;
}