#include "list.hpp"
#include <iostream>
#include <vector>
#include <string>


void print_test_result(const std::string& test_name, bool passed) {
    std::cout << "Test " << test_name << ": [" << (passed ? "OK" : "FAILED") << "]" << std::endl;
}


void test_list_construction() {
    blgt::list my_list;
    bool passed = my_list.empty() && (my_list.size() == 0) && (my_list.begin() == my_list.end());
    print_test_result("construction and basic properties", passed);
}


void test_insert_front_single_element() {
    blgt::list my_list;
    my_list.insert_front(10);
    bool passed = !my_list.empty() && (my_list.size() == 1) && (*my_list.begin() == 10);
    print_test_result("insert_front single element", passed);
}


void test_insert_front_multiple_elements() {
    blgt::list my_list;
    my_list.insert_front(10);
    my_list.insert_front(20);
    my_list.insert_front(30);

    bool passed = (my_list.size() == 3);
    auto it = my_list.begin();
    if (passed) passed = (*it == 30);
    if (passed) { ++it; passed = (*it == 20); }
    if (passed) { ++it; passed = (*it == 10); }
    if (passed) { ++it; passed = (it == my_list.end()); }
    print_test_result("insert_front multiple elements", passed);
}


void test_insert_back_two_elements() {
    blgt::list my_list;
    my_list.insert_back(10);
    my_list.insert_back(20);

    bool passed = (my_list.size() == 2);
    auto it = my_list.begin();
    if (passed) passed = (*it == 10);
    if (passed) { ++it; passed = (*it == 20); }
    if (passed) { ++it; passed = (it == my_list.end()); }
    print_test_result("insert_back two elements", passed);
}


void test_insert_back_multiple_elements() {
    blgt::list my_list;
    my_list.insert_back(10);
    my_list.insert_back(20);
    my_list.insert_back(30);

    bool passed = (my_list.size() == 3);
    auto it = my_list.begin();
    if (passed) passed = (*it == 10);
    if (passed) { ++it; passed = (*it == 20); }
    if (passed) { ++it; passed = (*it == 30); }
    if (passed) { ++it; passed = (it == my_list.end()); }
    print_test_result("insert_back multiple elements", passed);
}


void test_erase_front_on_empty_list() {
    blgt::list my_list;
    my_list.erase_front(); 
    bool passed = my_list.empty() && (my_list.size() == 0);
    print_test_result("erase_front on empty list", passed);
}


void test_erase_front() {
    blgt::list my_list;
    my_list.insert_front(10);
    my_list.insert_front(20); 
    my_list.erase_front(); 
    bool passed = (my_list.size() == 1) && (*my_list.begin() == 10);
    print_test_result("erase_front", passed);
}

void test_erase_back() {
    blgt::list my_list;
    my_list.insert_back(10);
    my_list.insert_back(20); 
    my_list.erase_back(); 
    bool passed = (my_list.size() == 1) && (*my_list.begin() == 10);
    print_test_result("erase_back", passed);
}

void test_erase_back_two_elements() {
    blgt::list my_list;
    my_list.insert_back(10);
    my_list.insert_back(20);
    my_list.insert_back(30); 
    my_list.erase_back(); 
    my_list.erase_back(); 
    bool passed = (my_list.size() == 1) && (*my_list.begin() == 10);
    print_test_result("erase_back two elements", passed);
}

void test_size() {
    blgt::list my_list;
    bool passed = (my_list.size() == 0);
    my_list.insert_front(1);
    if (passed) passed = (my_list.size() == 1);
    my_list.insert_back(2);
    if (passed) passed = (my_list.size() == 2);
    my_list.erase_front();
    if (passed) passed = (my_list.size() == 1);
    my_list.erase_back();
    if (passed) passed = (my_list.size() == 0);
    print_test_result("size", passed);
}


void test_iterator() {
    blgt::list my_list;
    my_list.insert_back(1);
    my_list.insert_back(2);
    my_list.insert_back(3);

    bool passed = true;
    auto it = my_list.begin();
    if (*it != 1) passed = false;
    if (passed) { ++it; if (*it != 2) passed = false; }
    if (passed) { ++it; if (*it != 3) passed = false; }
    if (passed) { ++it; if (it != my_list.end()) passed = false; }

    print_test_result("iterator", passed);
}


void test_empty() {
    blgt::list my_list;
    bool passed = my_list.empty();
    my_list.insert_front(1);
    if (passed) passed = !my_list.empty();
    my_list.erase_front();
    if (passed) passed = my_list.empty();
    print_test_result("empty", passed);
}


int main() {
    std::cout << "Is the list now empty? No" << std::endl; 
    
    test_insert_front_multiple_elements();
    test_insert_back_multiple_elements();
    test_erase_front_on_empty_list();
    test_erase_back();
    test_size();
    test_iterator();
    test_insert_front_single_element();
    test_insert_back_two_elements();
    test_erase_front();
    test_erase_back_two_elements();
    test_empty();

    return 0;
}