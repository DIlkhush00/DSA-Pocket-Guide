/* 
    Algorithm Name: Binary Search
    Time Complexity:
        Best Case: O(1)
        Worst Case: O(logn)
    Space Complexity: O(1)
*/

#include <iostream>

int binarySearch(int arr[], int size, int targetElement)
{
    int left = 0, right = size - 1;

    while(left <= right)
    {
        // int mid = (left + right) / 2;  <-- left + right can lead to overflow if their sum gets greater than 2^31 - 1 (maximum positive number for int)
        // Possible solutions: 
        // int mid = left + ((right - left) / 2);  <-- works for positive integers but might still overflow if left is a negative integer
        // int mid = (left + right) >>> 1;  <-- faster
        // C++20 offers a solution:
        // int mid = std::midpoint(left, right);
        // To keep it simple I would like to go ahead with:
        int mid = (left + right) / 2;
        int midElement = arr[mid];

        if(midElement < targetElement)
        {
            left = mid + 1;
        }
        else if(midElement > targetElement)
        {
            right = mid - 1;
        }
        else
        {
            return mid; // Found
        }
    }

    return -1; // Not found
}

int main()
{
    int SIZE = 10;
    int arr[SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        arr[i] = i + 1;
    }

    int element;
    std::cin >> element;

    int pos = binarySearch(arr, SIZE, element);

    if(pos != -1)
    {
        std::cout << "Element " << element << " found at " << pos + 1 << " position"<< std::endl;
    }
    else
    {
        std::cout << "Element " << element << " is not in the array\n";
    }

    return 0;
}