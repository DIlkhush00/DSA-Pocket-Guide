#include <iostream>

// Printing the array
void print(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}



void one_Dimensional_Array()
{
    ////////////////////// Static Initialization //////////////////////
    int arr1[5] = {5, 4, 3, 2, 1};

    // Accessing the array
    std::cout << arr1[3] << std::endl;

    // Updation
    arr1[2] = 0;

    // Array size
    int arr1_size = sizeof(arr1) / sizeof(arr1[0]);

    // Traversal
    for (int i = 0; i < arr1_size; ++i)
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    // Passing to function
    print(arr1, arr1_size);



    ////////////////////// Dynamic Initialization ///////////////////////
    int arr2_size = 5;
    int* arr2 = new int[arr2_size]{10, 9, 8, 7, 6};

    // Accessing the array
    std::cout << arr2[2] << std::endl;

    // Updation
    arr2[1] = 11;

    // Traversal
    for (int i = 0; i < arr2_size; ++i)
    {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    // Passing to function
    print(arr2, arr2_size);

    // Deletion
    delete[] arr2;

}

int main()
{
    one_Dimensional_Array();
    
    return 0;
}