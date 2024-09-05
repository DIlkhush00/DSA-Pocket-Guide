#include <iostream>
#include <vector>

void print(std::vector<int> &v)
{
    for(int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Initialization
    int SIZE = 10;
    // std::vector<int> v(SIZE, VALUE);
    // std::vector<int> v(SIZE);
    // std::vector<int> v{1, 2, 3, 4, 5};
    // std::vector<int> v(arr, arr + SIZE);
    // std::vector<int> v(vec.begin(), vec.end());

    std::vector<int> v = {1, 2, 3, 4, 5};

    // v.assign(5, 1); will create {1, 1, 1, 1, 1}

    // Accessing values
    int val = v[2];
    val = v.at(3);
    val = v.front();
    val = v.back();
    std::cout << val << std::endl;

    // Insertion 
    v.push_back(6); // insert from back

    int index = 2;
    v.insert(v.begin() + index, 11);

    // Updation
    v[2] = 10;

    // Vector Size
    std::cout << v.size() << std::endl;

    // Passing to a function
    print(v);

    // Deletion 
    v.pop_back();  // removes from back
    v.erase(v.begin() + index); // erase a specific value
    v.clear();  // clears whole array (dynamic array or vector)

    return 0;
}