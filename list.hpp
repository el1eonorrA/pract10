#pragma once

#include <cstdint>
#include <cstdlib>

namespace blgt {

/**
 * @brief List data structure.
 *
 * @details
 * Implements general list data structure concept.
 * Holds pointer to firtst node or nullptr (if list is empty).
 *
 * Attept to visualize data structure:
 *
 * o--->[node1]--->[node2]--->[node3]
 *         |          |          |
 *         |          |          |
 *        \/         \/         \/
 *       data1      data2      data3
 *
 * Each arrow represents pointer.
 * Intial "o" means pointer to head (first node).
 *
 * @details
 * Also responsible for memory managment of additional and user data.
 */
class list
{
private:
    /**
     * @brief Internal structure do describe list node.
     */
    struct node
    {
        /**
         * @brief Pointer to next node in list. nullptr value indicates end of list.
         */
        node* _next;

        /**
         * @brief Pointer to data.
         */
        std::int32_t* _data;
    };

public:
    /**
     * @brief Public structure to provide list iteration functionality.
     */
    struct iterator
    {
        /**
         * @brief Prefix increment.
         *
         * @details
         * Update iterator to point next node in list.
         * If points to last node (next is null ptr) do nothing.
         *
         * @return Return unchanged iterator.
         */
        iterator operator++(); // prefix

        /**
         * @brief Postfix increment.
         *
         * @see iterator operator++();
         *
         * @return Return updated iterator.
         */
        iterator operator++(int); // postfix

        /**
         * @brief Dereference operator.
         *
         * @return Return data which pointed by current node.
         */
        std::int32_t& operator*();

        /**
         * @brief Pointer to current node.
         */
        node* _data;
    };

    /**
     * @brief List constructor.
     *
     * @details
     * Explicitly sets head to nullptr
     * to prevent unexpected usage of empty list.
     */
    list();

    /**
     * @brief List destructor.
     *
     * @details
     * Remove all data in list.
     */
    ~list();

    // ACCESSORS
    /**
     * @brief Accessor to first item iterator.
     *
     * @return Return iterator which points to first node in list. Return end() if
     * list is empty.
     */
    iterator begin();

    /**
     * @brief Accessor to last + 1 item iterator.
     *
     * @return Return iterator which points to after the last node in list.
     * (Points to invalid node)
     */
    iterator end();

    // MODIFIERS
    /**
     * @brief Add element to the beginning of the list.
     *
     * @par value - This value will be inserted.
     */
    void insert_front(std::int32_t value);

    /**
     * @brief Add element to the ending of the list.
     *
     * @par value - This value will be inserted.
     */
    void insert_back(std::int32_t value);

    /**
     * @brief Remove element from the beginning of the list.
     */
    void erase_front();

    /**
     * @brief Remove element from the ending of the list.
     */
    void erase_back();

    // PROPERTIES
    /**
     * @brief Indicates that list doesn't store any items.
     *
     * @return Return true if list doesn't store items, false otherwise.
     */
    bool empty();

    /**
     * @brief Calculates amount of stored items.
     *
     * @details
     * Iterates over each element in list until end will be found and counts it.
     *
     * @return Return count of stored items.
     */
    std::size_t size();

private:
    /**
     * @brief Pointer to first node. nullptr if list is empty.
     */
    node* _head;
};

/**
 * @brief Free function to compare list iterators equality.
 */
bool operator==(const list::iterator& lhs, const list::iterator& rhs);

/**
 * @brief Free function to compare list iterators inequality.
 */
bool operator!=(const list::iterator& lhs, const list::iterator& rhs);

} // namespace blgt