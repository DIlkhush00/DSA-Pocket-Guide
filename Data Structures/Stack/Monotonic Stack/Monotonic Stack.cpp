#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
    Function Name: nextGreaterElements(...)
    Time Complexity: O(N)
    Space Compelexity: O(N)

    note: The code can be deceiving but remember each element is pushed and popped at most once, 
    so the number of stack operations (pushes and pops) across the entire execution of the algorithm is proportional to n
*/
vector<int> nextGreaterElements(vector<int>& nums)
{
	vector<int> result(nums.size(), -1); // Default value is -1 which indicates that the next greater element doesn't exist for that index in input array.
	stack<int> decMonoStack; // Mono-Decreasing Stack

	for(int i = nums.size() - 1; i >= 0; i--)
	{
        int currentElement = nums[i];

        // Remove elements from the stack till the top of the stack is less than or equal to the current element
        while(!decMonoStack.empty() && decMonoStack.top() <= currentElement)
        {
            decMonoStack.pop();
        }

        // Check if stack is empty or not
        // If no, then top element of the stack will be the next greater element for the current element.
        // If yes, then default value (-1) is already stored in result. 
        if(!decMonoStack.empty())
            result[i] = decMonoStack.top();
        
        // Finally push the current element to the stack. Thus the stack will maintain it's decreasing order.
		decMonoStack.push(currentElement);
	}

	return result;
}

/*
    Function Name: prevSmallerElements(...)
    Time Complexity: O(N)
    Space Compelexity: O(N)

    note: The code can be deceiving but remember each element is pushed and popped at most once, 
    so the number of stack operations (pushes and pops) across the entire execution of the algorithm is proportional to n
*/
vector<int> prevSmallerElements(vector<int>& nums)
{
	vector<int> result(nums.size(), -1); // Default value is -1 which indicates that the next greater element doesn't exist for that index in input array.
	stack<int> incMonoStack; // Mono-Increasing Stack

	for(int i = 0; i < nums.size(); i++)
	{
        int currentElement = nums[i];

        // Remove elements from the stack till the top of the stack is greater than or equal to the current element
        while(!incMonoStack.empty() && incMonoStack.top() >= currentElement)
        {
            incMonoStack.pop();
        }

        // Check if stack is empty or not
        // If no, then top element of the stack will be the previous smaller element for the current element.
        // If yes, then default value (-1) is already stored in result. 
        if(!incMonoStack.empty())
            result[i] = incMonoStack.top();
        
        // Finally push the current element to the stack. Thus the stack will maintain it's increasing order.
		incMonoStack.push(currentElement);
	}

	return result;
}

void print(const vector<int>& nums)
{
	for(int x: nums)
	{
		cout << x << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> nums = {1, 2, 3, 4, 5, 6}; // where: nums[i] >= 0
    cout << "Original array: ";
    print(nums);

    cout << "Next greater elements to the corresponding indexes: ";
	print(nextGreaterElements(nums));
    cout << "Previous smaller elements to the corresponding indexes: ";
    print(prevSmallerElements(nums));
	
	return 0;
}