/*
    9: Բալանսավորված փակագծեր
    Մուտքում տրվում է ‘(‘, ‘)’, ‘{‘, ‘}’, ‘[‘ և ‘]’ սիմվոներից բաղկացած հաջորդականություն, 
    պահանջվում է արտածել YES, եթե այն փակագծերի ճիշտ արտահայտություն է և NO՝ հակառակ դեպքում։ 
*/

#include <iostream>
#include <cassert>

class Stack
{
public:
    Stack(int c);
    Stack(Stack &st);
    ~Stack();
    bool empty();
    int top();
    void push(int obj);
    void pop();

private:
    int stack_size;
    int array_capacity;
    int *array;
};

//  should be greater than 0
Stack::Stack(int c) : stack_size(0),
                      array_capacity(c),
                      array(new int[array_capacity]) {}

// copy constructor
Stack::Stack(Stack &st) : stack_size(st.stack_size),
                          array_capacity(st.array_capacity),
                          array(new int[array_capacity])
{
    for (int i = 0; i < stack_size; i++)
    {
        array[i] = st.array[i];
    }
}

Stack::~Stack()
{
    delete[] array;
}

bool Stack::empty()
{
    return stack_size == 0;
}

int Stack::top()
{
    assert(!empty());
    return array[stack_size - 1];
}

void Stack::push(int obj)
{
    if (stack_size == array_capacity)
    {
        return;
    }
    array[stack_size] = obj;
    ++stack_size;
}

void Stack::pop()
{
    if (empty())
    {
        return;
    }
    --stack_size;
}

// Main function
int main()
{
    int n = 40;
    Stack st(n);
    std::string str;
    std::cin >> str;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        int input = str[i];
        if (input == '(' || input == '{' || input == '[')
        {
            st.push(input);
        }
        else if (st.empty())
        {
            st.push(input);
            break;
        }
        else if ((input == ')' && st.top() == '(') || (input == '}' && st.top() == '{') || (input == ']' && st.top() == '['))
        {
            st.pop();
        }
    }
    if (st.empty())
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }
}