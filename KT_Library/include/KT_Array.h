#pragma once
//include
#include <exception>
#include <initializer_list>
#include <sstream>
//namespace
namespace KT
{
    template<typename type, size_t size>
    class Array
    {
    public:
        using value_type = type;
        struct iterator;
        struct reverse_iterator;
        using reverse_iterator = reverse_iterator;
        using const_reverse_iterator = reverse_iterator;
        using iterator = iterator;
        using const_iterator = const iterator;
        using value_type = type;
        using pointer = type*;
        using const_pointer = const type*;
        using reference = type&;
        using const_reference = const type&;
        Array(std::initializer_list<type> list)
        {
            if (list.size() != size)
                throw std::runtime_error("Out of Range");
            std::copy(list.begin(), list.end(), m_data);
        }

        Array()
        {
            std::fill(m_data, m_data + size, type());
        }
        Array& operator=(Array<type, size>& tab)
        {
            if (this != &tab)
                std::copy(tab.begin(), tab.end(), m_data);
            return *this;
        }
        Array(const Array& tab)
        {
            std::copy(tab.begin(), tab.end(), m_data);
        }
        reference operator[](size_t Idx)
        {
            return m_data[Idx];
        }
        const_reference operator[](size_t Idx) const
        {
            return m_data[Idx];
        }
        reference at(size_t Idx)
        {
            if (Idx >= size)
                throw std::runtime_error("Out of Range");
            return m_data[Idx];
        }
        const_reference at(size_t Idx) const
        {
            if (Idx >= size)
                throw std::runtime_error("Out of Range");
            return m_data[Idx];
        }
        reference front()
        {
            return m_data[0];
        }
        const_reference front() const
        {
            return m_data[0];
        }
        reference back()
        {
            return m_data[size - 1];
        }
        const_reference back() const
        {
            return m_data[size - 1];
        }
        pointer data()
        {
            return m_data;
        }
        const_pointer data() const
        {
            return m_data;
        }
        bool Empty()
        {
            return size == 0;
        }
        bool Empty() const
        {
            return size == 0;
        }
        size_t max_size()
        {
            return size;
        }
        size_t max_size() const
        {
            return size;
        }
        size_t Size()
        {
            return size;
        }
        size_t Size() const
        {
            return size;
        }
        iterator begin()
        {
            return iterator(m_data);
        }
        iterator end()
        {
            return iterator(m_data + size);
        }
        const_iterator begin() const
        {
            return iterator(m_data);
        }
        const_iterator end() const
        {
            return iterator(m_data + size);
        }
        reverse_iterator rbegin()
        {
            return reverse_iterator(m_data + size - 1);
        }
        reverse_iterator rend()
        {
            return reverse_iterator(m_data - 1);
        }
        const_reverse_iterator rbegin() const
        {
            return reverse_iterator(m_data + size - 1);
        }
        const_reverse_iterator rend() const
        {
            return reverse_iterator(m_data - 1);
        }
        void swap(Array<type, size>& NewArray)
        {
            Array<type, size> tmp = *this;
            *this = NewArray;
            NewArray = tmp;
        }
    private:
        struct iterator {
            //this iterator compatible with stl
            using iterator_category = std::random_access_iterator_tag;
            using value_type = type;
            using difference_type = std::ptrdiff_t;
            using pointer = type*;
            using reference = type&;
            friend Array;
            iterator(pointer ptr) : m_ptr(ptr) {}
            reference operator*()
            {
                return *m_ptr;
            }
            pointer operator->()
            {
                return m_ptr;
            }
            iterator& operator++()
            {
                ++m_ptr;
                return *this;
            }
            iterator& operator--()
            {
                --m_ptr;
                return *this;
            }
            iterator operator+(difference_type n) const
            {
                return iterator(m_ptr + n);
            }
            iterator operator-(difference_type n) const
            {
                return iterator(m_ptr - n);
            }
            difference_type operator-(const iterator& other) const
            {
                return m_ptr - other.m_ptr;
            }
            difference_type operator+(const iterator& other) const
            {
                return m_ptr + other.m_ptr;
            }
            bool operator==(const iterator& other) const
            {
                return m_ptr == other.m_ptr;
            }
            bool operator!=(const iterator& other) const
            {
                return m_ptr != other.m_ptr;
            }
            bool operator<(const iterator& other) const
            {
                return m_ptr < other.m_ptr;
            }
            bool operator>(const iterator& other) const
            {
                return m_ptr > other.m_ptr;
            }
            bool operator<=(const iterator& other) const
            {
                return m_ptr <= other.m_ptr;
            }
            bool operator>=(const iterator& other) const
            {
                return m_ptr >= other.m_ptr;
            }
        private:
            pointer m_ptr;
        };

        struct reverse_iterator {
            //this iterator compatible with stl
            using iterator_category = std::random_access_iterator_tag;
            using value_type = type;
            using difference_type = std::ptrdiff_t;
            using pointer = type*;
            using reference = type&;
            friend Array;
            reverse_iterator(pointer ptr) : m_ptr(ptr) {}
            reference operator*()
            {
                return *m_ptr;
            }
            pointer operator->()
            {
                return m_ptr;
            }
            reverse_iterator& operator++()
            {
                --m_ptr;
                return *this;
            }
            reverse_iterator& operator--()
            {
                ++m_ptr;
                return *this;
            }
            reverse_iterator operator+(difference_type n) const
            {
                return reverse_iterator(m_ptr - n);
            }
            reverse_iterator operator-(difference_type n) const
            {
                return reverse_iterator(m_ptr + n);
            }
            difference_type operator-(const reverse_iterator& other) const
            {
                return m_ptr + other.m_ptr;
            }
            difference_type operator+(const reverse_iterator& other) const
            {
                return m_ptr - other.m_ptr;
            }
            bool operator==(const reverse_iterator& other) const
            {
                return m_ptr == other.m_ptr;
            }
            bool operator!=(const reverse_iterator& other) const
            {
                return m_ptr != other.m_ptr;
            }
            bool operator<(const reverse_iterator& other) const
            {
                return m_ptr < other.m_ptr;
            }
            bool operator>(const reverse_iterator& other) const
            {
                return m_ptr > other.m_ptr;
            }
            bool operator<=(const reverse_iterator& other) const
            {
                return m_ptr <= other.m_ptr;
            }
            bool operator>=(const reverse_iterator& other) const
            {
                return m_ptr >= other.m_ptr;
            }
        private:
            pointer m_ptr;
        };
        type m_data[size];
    };
}
template<typename type, size_t size>
std::ostream& operator<<(std::ostream& os, const KT::Array<type, size>& tab)
{
    if (tab.Size() == 0)
        return os;
    os << "(";
    for (auto i = 0; i < tab.Size() - 1; ++i)
        os << tab[i] << ", ";
    os << tab[tab.Size() - 1] << ")";
    return os;
}