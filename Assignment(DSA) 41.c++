Stack

1. Create a stack of int type, push 5 elements in it and print it on the console screen.
2. Create a stack of int type, and find the top most element in a stack.
3. Create a stack, and implement main operations like push(), pop(), peek(), empty()
and size().
4. Reverse the Words of a String using Stack.
Example:
Input: str = “I Love To Code”
Output: Code To Love I
5. Create stack1 of int type, and create another stack of the same type with name
stack2 and copy all the elements of stack1 into stack2 in the same order.
6. Reverse a string using a stack.
Example:
Input: str = "Reverse me"
Output: em esreveR
7. Create a stack of int type and sort it.
8. Create a stack of int type and sort it in descending order.
9. Create back button functionality using stack.
10. Given an array, print the Next Greater Element (NGE) for every element using stack.

Solution:-

1. #include <iostream>
#include <stack>

int main() {
    std::stack<int> stk;
    for (int i = 1; i <= 5; ++i) {
        stk.push(i);
    }

    std::stack<int> temp = stk;
    std::cout << "Stack elements: ";
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;

    return 0;
}

2. #include <iostream>
#include <stack>

int main() {
    std::stack<int> stk;
    for (int i = 1; i <= 5; ++i) {
        stk.push(i);
    }

    if (!stk.empty()) {
        std::cout << "Topmost element in the stack: " << stk.top() << std::endl;
    } else {
        std::cout << "Stack is empty" << std::endl;
    }

    return 0;
}

3. #include <iostream>
#include <stack>

class Stack {
public:
    void push(int value) {
        stk.push(value);
    }

    void pop() {
        if (!stk.empty()) {
            stk.pop();
        } else {
            std::cout << "Stack is empty" << std::endl;
        }
    }

    int peek() {
        if (!stk.empty()) {
            return stk.top();
        } else {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
    }

    bool empty() {
        return stk.empty();
    }

    size_t size() {
        return stk.size();
    }

private:
    std::stack<int> stk;
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << "Top element: " << s.peek() << std::endl;
    s.pop();
    std::cout << "Top element after pop: " << s.peek() << std::endl;
    std::cout << "Stack size: " << s.size() << std::endl;
    std::cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << std::endl;

    return 0;
}

4. #include <iostream>
#include <stack>
#include <sstream>

std::string reverseWords(const std::string& str) {
    std::stack<std::string> stk;
    std::stringstream ss(str);
    std::string word;

    while (ss >> word) {
        stk.push(word);
    }

    std::string reversed;
    while (!stk.empty()) {
        reversed += stk.top() + " ";
        stk.pop();
    }

    if (!reversed.empty()) {
        reversed.pop_back(); // remove the trailing space
    }

    return reversed;
}

int main() {
    std::string str = "I Love To Code";
    std::string reversed = reverseWords(str);
    std::cout << "Reversed words: " << reversed << std::endl;

    return 0;
}

5. #include <iostream>
#include <stack>

void copyStack(std::stack<int>& src, std::stack<int>& dest) {
    std::stack<int> temp;

    while (!src.empty()) {
        temp.push(src.top());
        src.pop();
    }

    while (!temp.empty()) {
        dest.push(temp.top());
        src.push(temp.top());
        temp.pop();
    }
}

int main() {
    std::stack<int> stack1;
    for (int i = 1; i <= 5; ++i) {
        stack1.push(i);
    }

    std::stack<int> stack2;
    copyStack(stack1, stack2);

    std::cout << "Stack1 elements: ";
    while (!stack1.empty()) {
        std::cout << stack1.top() << " ";
        stack1.pop();
    }
    std::cout << std::endl;

    std::cout << "Stack2 elements: ";
    while (!stack2.empty()) {
        std::cout << stack2.top() << " ";
        stack2.pop();
    }
    std::cout << std::endl;

    return 0;
}

6. #include <iostream>
#include <stack>

std::string reverseString(const std::string& str) {
    std::stack<char> stk;
    for (char ch : str) {
        stk.push(ch);
    }

    std::string reversed;
    while (!stk.empty()) {
        reversed += stk.top();
        stk.pop();
    }

    return reversed;
}

int main() {
    std::string str = "Reverse me";
    std::string reversed = reverseString(str);
    std::cout << "Reversed string: " << reversed << std::endl;

    return 0;
}

7. #include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

void sortStack(std::stack<int>& stk) {
    std::vector<int> temp;
    while (!stk.empty()) {
        temp.push_back(stk.top());
        stk.pop();
    }

    std::sort(temp.begin(), temp.end());

    for (int val : temp) {
        stk.push(val);
    }
}

int main() {
    std::stack<int> stk;
    stk.push(3);
    stk.push(1);
    stk.push(4);
    stk.push(2);
    stk.push(5);

    sortStack(stk);

    std::cout << "Sorted stack: ";
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << std::endl;

    return 0;
}

8. #include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

void sortStackDesc(std::stack<int>& stk) {
    std::vector<int> temp;
    while (!stk.empty()) {
        temp.push_back(stk.top());
        stk.pop();
    }

    std::sort(temp.rbegin(), temp.rend());

    for (int val : temp) {
        stk.push(val);
    }
}

int main() {
    std::stack<int> stk;
    stk.push(3);
    stk.push(1);
    stk.push(4);
    stk.push(2);
    stk.push(5);

    sortStackDesc(stk);

    std::cout << "Stack sorted in descending order: ";
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << std::endl;

    return 0;
}

9. #include <iostream>
#include <stack>
#include <string>

class Browser {
public:
    void visit(const std::string& url) {
        backStack.push(url);
        while (!forwardStack.empty()) {
            forwardStack.pop();
        }
    }

    void back() {
        if (!backStack.empty()) {
            forwardStack.push(backStack.top());
            backStack.pop();
        }
    }

    void forward() {
        if (!forwardStack.empty()) {
            backStack.push(forwardStack.top());
            forwardStack.pop();
        }
    }

    void current() const {
        if (!backStack.empty()) {
            std::cout << "Current page: " << backStack.top() << std::endl;
        } else {
            std::cout << "No pages visited yet." << std::endl;
        }
    }

private:
    std::stack<std::string> backStack;
    std::stack<std::string> forwardStack;
};

int main() {
    Browser browser;
    browser.visit("www.google.com");
    browser.visit("www.youtube.com");
    browser.visit("www.github.com");

    browser.current();

    browser.back();
    browser.current();

    browser.back();
    browser.current();

    browser.forward();
    browser.current();

    return 0;
}

10. #include <iostream>
#include <vector>

std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, 1);

    int leftProduct = 1;
    // Calculate left product for each position
    for (int i = 0; i < n; ++i) {
        result[i] = leftProduct;
        leftProduct *= nums[i];
    }

    int rightProduct = 1;
    // Calculate right product for each position and multiply with left product
    for (int i = n - 1; i >= 0; --i) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> result = productExceptSelf(nums);

    std::cout << "Product of array elements except self: ";
    for (int value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
