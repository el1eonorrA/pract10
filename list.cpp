#include "list.hpp"
#include <iostream> 

namespace blgt {


list::iterator list::iterator::operator++()
{
    if (_data) {
        _data = _data->_next;
    }
    return *this;
}

list::iterator list::iterator::operator++(int) 
{
    iterator temp = *this;
    ++(*this);
    return temp;
}

std::int32_t& list::iterator::operator*()
{
    
    return *_data->_data;
}


list::list() : _head(nullptr) {}

list::~list()
{
    node* current = _head;
    while (current != nullptr) {
        node* next = current->_next;
        delete current->_data; 
        delete current;       
        current = next;
    }
    _head = nullptr; 
}

list::iterator list::begin()
{
    iterator it;
    it._data = _head;
    return it;
}

list::iterator list::end()
{
    iterator it;
    it._data = nullptr; 
    return it;
}

void list::insert_front(std::int32_t value)
{
    node* new_node = new node();
    new_node->_data = new std::int32_t(value);
    new_node->_next = _head;
    _head = new_node;
}

void list::insert_back(std::int32_t value)
{
    node* new_node = new node();
    new_node->_data = new std::int32_t(value);
    new_node->_next = nullptr;

    if (_head == nullptr) {
        _head = new_node;
    } else {
        node* current = _head;
        while (current->_next != nullptr) {
            current = current->_next;
        }
        current->_next = new_node;
    }
}

void list::erase_front()
{
    if (_head == nullptr) {
        return; 
    }
    node* old_head = _head;
    _head = _head->_next;
    delete old_head->_data;
    delete old_head;
}

void list::erase_back()
{
    if (_head == nullptr) {
        return; 
    }
    if (_head->_next == nullptr) { 
        delete _head->_data;
        delete _head;
        _head = nullptr;
        return;
    }

    node* current = _head;
    while (current->_next && current->_next->_next != nullptr) {
        current = current->_next;
    }
    delete current->_next->_data;
    delete current->_next;
    current->_next = nullptr;
}

bool list::empty()
{
    return _head == nullptr;
}

std::size_t list::size()
{
    std::size_t count = 0;
    node* current = _head;
    while (current != nullptr) {
        count++;
        current = current->_next;
    }
    return count;
}


bool operator==(const list::iterator& lhs, const list::iterator& rhs)
{
    return lhs._data == rhs._data;
}

bool operator!=(const list::iterator& lhs, const list::iterator& rhs)
{
    return !(lhs == rhs);
}

} 