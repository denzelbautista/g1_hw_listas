#include <iostream>
#include "forward_list.cpp" 
// testeando xdd
void test_push_front() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    if (list.front() != 3) {
        std::cout << "PushFrontTest failed - Expected 3, got " << list.front() << "\n";
    } else {
        std::cout << "PushFrontTest passed - Expected 3, got " << list.front() << "\n";
    }
}

void test_pop_front() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.pop_front();
    if (list.front() != 2) {
        std::cout << "PopFrontTest failed - Expected 2, got " << list.front() << "\n";
    } else {
        std::cout << "PopFrontTest passed - Expected 2, got " << list.front() << "\n";
    }
}

void test_push_back() {
    ForwardList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    if (list.back() != 3) {
        std::cout << "PushBackTest failed - Expected 3, got " << list.back() << "\n";
    } else {
        std::cout << "PushBackTest passed - Expected 3, got " << list.back() << "\n";
    }
}

void test_pop_back() {
    ForwardList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    if (list.back() != 2) {
        std::cout << "PopBackTest failed - Expected 2, got " << list.back() << "\n";
    } else {
        std::cout << "PopBackTest passed - Expected 2, got " << list.back() << "\n";
    }
}

void test_operator_square_brackets() {
    ForwardList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    if (list[0] != 1 || list[1] != 2 || list[2] != 3) {
        std::cout << "OperatorSquareBracketsTest failed - Expected 1, 2, 3, got " << list[0] << ", " << list[1] << ", " << list[2] << "\n";
    } else {
        std::cout << "OperatorSquareBracketsTest passed\n";
    }
}

void test_size() {
    ForwardList<int> list;
    if (list.size() != 0) {
        std::cout << "SizeTest failed - Expected 0, got " << list.size() << "\n";
    }
    list.push_back(1);
    if (list.size() != 1) {
        std::cout << "SizeTest failed - Expected 1, got " << list.size() << "\n";
    }
    list.push_back(2);
    if (list.size() != 2) {
        std::cout << "SizeTest failed - Expected 2, got " << list.size() << "\n";
    }
    list.pop_front();
    if (list.size() != 1) {
        std::cout << "SizeTest failed - Expected 1, got " << list.size() << "\n";
    }
    list.clear();
    if (list.size() != 0) {
        std::cout << "SizeTest failed - Expected 0, got " << list.size() << "\n";
    } else {
        std::cout << "SizeTest passed\n";
    }
}

void test_clear() {
    ForwardList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
    if (!list.empty()) {
        std::cout << "ClearTest failed - Expected list to be empty after clear\n";
    } else {
        std::cout << "ClearTest passed\n";
    }
}

void test_empty() {
    ForwardList<int> list;

    // lista recien creada
    if (!list.empty()) {
        std::cout << "EmptyTest failed - Expected newly created list to be empty\n";
    }
    // luego de agregar un elemento
    list.push_back(1);
    if (list.empty()) {
        std::cout << "EmptyTest failed - Expected list to not be empty after push_back\n";
    }
    // after deleting the element
    list.pop_front();
    if (!list.empty()) {
        std::cout << "EmptyTest failed - Expected list to be empty after pop_front\n";
    }
    // luego multiples elementos
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    if (list.empty()) {
        std::cout << "EmptyTest failed - Expected list to not be empty after multiple push_back\n";
    }
    // testear si list is empty after clearing it
    list.clear();
    if (!list.empty()) {
        std::cout << "EmptyTest failed - Expected list to be empty after clear\n";
    } else {
        std::cout << "EmptyTest passed\n";
    }
}





void test_reverse() {
    ForwardList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.reverse();
    if (list[0] != 3 || list[1] != 2 || list[2] != 1) {
        std::cout << "ReverseTest failed - Expected 3, 2, 1, got " << list[0] << ", " << list[1] << ", " << list[2] << "\n";
    } else {
        std::cout << "ReverseTest passed\n";
    }
}

void test_sort() {
    ForwardList<int> list;
    list.push_back(30);
    list.push_back(-12);
    list.push_back(21);
    list.push_back(2);
    list.push_back(-1);
    list.sort();
    if (list[0] != -12 || list[1] != -1 || list[2] != 2 || list[3] != 21 || list[4] != 30) {
        std::cout << "SortTest failed - Expected -12, -1, 2, 21, 30, got " << list[0] << ", " << list[1] << ", " << list[2] << ", " << list[3] << ", " << list[4] << "\n";
    } else {
        std::cout << "SortTest passed\n";
    }
}

// sort empty list 
void test_sort_2() {
    ForwardList<int> list;
    list.sort();
// Should throw an exception
}

void test_print() {
    ForwardList<int> list;
    list.push_back(2);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(54);
    std::cout << "PrintTest - Expected 2, 2, 3, 4, 54, tenemos "<< std::endl;
    list.print();
}

int main() {
    test_push_front();
    test_pop_front();
    test_push_back();
    test_pop_back();
    test_operator_square_brackets();
    test_size();
    test_clear();
    test_empty();
    test_reverse();
    test_sort();
    test_print();
    test_sort_2();
    return 0;
}