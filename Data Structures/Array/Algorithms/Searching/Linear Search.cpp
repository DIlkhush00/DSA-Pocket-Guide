/* 
    Algorithm Name: Linear Search
    Time Complexity:
        Best Case: O(1)
        Worst Case: O(n)
    Space Complexity: O(1)
*/

#include <iostream>

int linearSearch(int arr[], int size, int target)
{
    for(int i = 0; i < size; ++i)
    {
        if(arr[i] == target)
            return i;
    }

    return -1;
}

int main()
{
    int size = 10;
    // Initializing
    int arr[size];

    // Filling up the array
    for(int i = 0; i < size; ++i)
    {
        arr[i] = i + 1;
    }

    // Target Element
    int target = 5;

    int pos = linearSearch(arr, size, target);

    if(pos != -1)
    {
        std::cout << "Found at " << pos << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}