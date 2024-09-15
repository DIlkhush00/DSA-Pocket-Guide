#include <iostream>

using namespace std;

template <typename T>
class Stack {
private:
    T* container; // The container to store the data (elements)
    int maxSize; // Maximum size of the container
    int topIndex; // Top element index
    
public:
    Stack(int size); // Constructor
    ~Stack(); // Destructor

    void push(T element); // Push the element on top of the stack
    T pop(); // Delete top element
    T top(); // Top element
    bool isEmpty() const; // Check emptiness of the stack
    bool isFull() const; // Check fullness of the stack
    void print(); // Print the stack
};

template <typename T>
Stack<T>::Stack(int size)
{
    container = new T(size);
    maxSize = size;
    topIndex = -1;
}

template <typename T>
Stack<T>::~Stack()
{
    delete [] container;
}

template <typename T>
void Stack<T>::push(T element)
{
    if(isFull())
    {
        cout << "Stack is already full!" << endl;
        return;
    }
    container[++topIndex] = element;
}

template <typename T>
T Stack<T>::pop()
{
    if(isEmpty())
    {
        cout << "Stack is already empty!" << endl;
        return T();
    }
    else
    {
        return container[topIndex--];
    }
}

template <typename T>
T Stack<T>::top()
{
    return container[topIndex];
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return topIndex < 0;
}

template <typename T>
bool Stack<T>::isFull() const
{
    return topIndex == maxSize - 1;
}

template <typename T>
void Stack<T>::print()
{
    for(int i = topIndex; i >= 0; i--)
    {
        cout << "|\t" << container[i] << "\t|" << endl;
    }
}


int main(int argc, char const *argv[])
{
    int size = 5;

    Stack<int> st(size);

    st.push(10);
    st.push(11);
    st.push(12);
    st.push(13);
    st.push(14);

    if(st.isFull()) cout << "The stack is full!\n\n";

    st.print();

    st.pop();

    cout << "\nStack after removing the top most element: \n";
    st.print();

    cout << "\nTop Element: " << st.top() << endl;

    st.pop();
    st.pop();
    st.pop();
    st.pop();

    cout << "\nAfter removing all of the elements - \n" << endl;
    
    if(st.isEmpty()) cout << "The stack is empty!\n";

    return 0;
}
