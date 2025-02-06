#pragma once
/*****************************************************************//**
 * \file   KT_Array.h
 * \brief  This file contains the code for KT::Vector
 *
 * \author Kroktur
 * \date   February 2025
 *********************************************************************/

//include
 #include <exception>
#include <initializer_list>
#include <sstream>
//namespace
namespace KT
{
    template<typename type>
    class Vector
    {
    public:
        using value_type = type;
        struct iterator;
        struct reverse_iterator;
        struct const_iterator;
        struct const_reverse_iterator;
        using reverse_iterator = reverse_iterator;
        using const_reverse_iterator = const_reverse_iterator;
        using iterator = iterator;
        using const_iterator = const_iterator;
        using value_type = type;
        using pointer = type*;
        using const_pointer = const type*;
        using reference = type&;
        using const_reference = const type&;
        ~Vector() { delete[] m_data; }
        Vector() :capacity(0), size(0), m_data(nullptr) {}
        Vector(size_t newcapacity) :capacity(newcapacity), size(0), m_data(nullptr) { reserve(newcapacity); }
        Vector(const Vector& tab) :capacity(0), size(0), m_data(nullptr)
        {
            reserve(tab.Capacity());
            resize(tab.Size());
            std::copy(tab.begin(), tab.end(), m_data);
        }
        Vector(std::initializer_list<type> list):capacity(0), size(0), m_data(nullptr)
        {
            reserve(list.size() * 2);
            resize(list.size());
            std::copy(list.begin(), list.end(), m_data);
        }
        void reserve(const size_t& newcapacity)
        {
            if (capacity > newcapacity)
                throw std::runtime_error("New capacity too small");
            type* newdata = new type[newcapacity];
            std::copy(m_data, m_data + size, newdata);
            std::fill(newdata + size, newdata + newcapacity, type());
            delete[] m_data;
            m_data = newdata;
            capacity = newcapacity;
        }
        void pushBack(const_reference value)
        {
            resize(size + 1);
            m_data[size - 1] = value;
        }
        void popBack()
        {
            if (!Empty())
                resize(size - 1);
        }
        void resize(const size_t& newsize)
        {
            if (size == newsize)
                return;
            if (newsize > capacity)
                reserve(newsize * 2);
            size = newsize;
        }
        reference operator[](const size_t& idx)
        {
            return m_data[idx];
        }
        const_reference operator[](const size_t& idx) const
        {
            return m_data[idx];
        }
        reference at(const size_t& idx)
        {
            if (idx >= size)
                throw std::out_of_range("Out of Range");
            return m_data[idx];
        }
        const_reference at(const size_t& idx) const
        {
            if (idx >= size)
                throw std::out_of_range("Out of Range");
            return m_data[idx];
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
            return const_iterator(m_data);
        }
        const_iterator end() const
        {
            return const_iterator(m_data + size);
        }
        reverse_iterator rbegin()
        {
            return reverse_iterator(m_data + size - 1);
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(m_data + size - 1);
        }
        reverse_iterator rend()
        {
            return reverse_iterator(m_data - 1);
        }
        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(m_data - 1);
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
        bool Empty()
        {
            return size == 0;
        }
        bool Empty() const
        {
            return size == 0;
        }
        size_t Capacity()
        {
            return capacity;
        }
        size_t Capacity() const
        {
            return capacity;
        }
        size_t Size()
        {
            return size;
        }
        size_t Size() const
        {
            return size;
        }
        size_t max_size()
        {
            return std::numeric_limits<size_t>::max() / sizeof(type);
        }
        size_t max_size() const
        {
            return std::numeric_limits<size_t>::max() / sizeof(type);
        }
        pointer data()
        {
            return m_data;
        }
        const_pointer data() const
        {
            return m_data;
        }
        void clear()
        {
            resize(0);
            reserve(capacity);
        }
        void insert(iterator dest, const_reference value )
        {
            if (dest > m_data + size || dest < m_data)
                throw std::out_of_range("dest out of range");
            resize(size + 1);
            for (auto ptr = m_data + size - 1; ptr != dest.m_ptr; --ptr)
            {
                *ptr = *(ptr - 1);
            }
            *dest = value;
        }
        void erase(iterator supr)
        {
            if (find(supr) == end())
                throw std::out_of_range("supr out of range");
            for (auto ptr = supr; ptr != m_data + size - 1; ++ptr)
            {
                *ptr = *(ptr + 1);
            }
            resize(size - 1);
        }
        void assign(iterator begin, iterator end)
        {
            clear();
            size_t sizeofvec = end - begin;
            resize(sizeofvec);

            std::copy(begin, end, m_data);
        }
        void assign(size_t sizeofvec, value_type data)
        {
            clear();
            resize(sizeofvec);
            std::fill(m_data, m_data + sizeofvec, data);
        }
        void assign(std::initializer_list<type> list)
        {
            clear();
            resize(list.size());
            std::copy(list.begin(), list.end(), m_data);
        }
        Vector& operator=(const Vector& tab)
        {
            resize(tab.Size());
            std::copy(tab.begin(), tab.end(), m_data);
            return *this;
        }
        void swap(Vector<type>& NewVector)
        {
            Vector<type> tmp = *this;
            *this = NewVector;
            NewVector = tmp;
        }
        iterator find(const iterator& ptr)
        {
            for (auto it = begin(); it != end(); ++it)
            {
                if (it == ptr)
                    return it;
            }
            return end();
        }
        const_iterator find(const const_iterator& ptr) const
        {
            for (auto it = begin(); it != end(); ++it)
            {
                if (it == ptr)
                    return it;
            }
            return end();
        }

    private:
        struct iterator
        {
            //this iterator compatible with stl
            using iterator_category = std::random_access_iterator_tag;
            using value_type = type;
            using difference_type = std::ptrdiff_t;
            using pointer = type*;
            using reference = type&;
            friend Vector;
            iterator(pointer ptr) : m_ptr(ptr) {}
            reference operator*()
            {
                return *m_ptr;
            }
          const reference operator*()const
            {
                return *m_ptr;
            }
            pointer operator->()
            {
                return m_ptr;
            }
           const pointer operator->()const
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
        struct const_iterator
        {
            //this iterator compatible with stl
            using iterator_category = std::random_access_iterator_tag;
            using value_type = const type;
            using difference_type = std::ptrdiff_t;
            using pointer = const type*;
            using reference = const type&;
            friend Vector;
            const_iterator(pointer ptr) : m_ptr(ptr) {}
            reference operator*()
            {
                return *m_ptr;
            }
            const reference operator*() const
            {
                return *m_ptr;
            }
            pointer operator->()
            {
                return m_ptr;
            }
            const pointer operator->() const
            {
                return m_ptr;
            }
            const_iterator& operator++()
            {
                ++m_ptr;
                return *this;
            }
            const_iterator& operator--()
            {
                --m_ptr;
                return *this;
            }
            const_iterator operator+(difference_type n) const
            {
                return iterator(m_ptr + n);
            }
            const_iterator operator-(difference_type n) const
            {
                return const_iterator(m_ptr - n);
            }
            difference_type operator-(const const_iterator& other) const
            {
                return m_ptr - other.m_ptr;
            }
            difference_type operator+(const const_iterator& other) const
            {
                return m_ptr + other.m_ptr;
            }
            bool operator==(const const_iterator& other) const
            {
                return m_ptr == other.m_ptr;
            }
            bool operator!=(const const_iterator& other) const
            {
                return m_ptr != other.m_ptr;
            }
            bool operator<(const const_iterator& other) const
            {
                return m_ptr < other.m_ptr;
            }
            bool operator>(const const_iterator& other) const
            {
                return m_ptr > other.m_ptr;
            }
            bool operator<=(const const_iterator& other) const
            {
                return m_ptr <= other.m_ptr;
            }
            bool operator>=(const const_iterator& other) const
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
            friend Vector;
            reverse_iterator(pointer ptr) : m_ptr(ptr) {}
            reference operator*()
            {
                return *m_ptr;
            }
            const reference operator*() const
            {
                return *m_ptr;
            }
            pointer operator->()
            {
                return m_ptr;
            }
            const pointer operator->() const
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
        struct const_reverse_iterator {
            //this iterator compatible with stl
            using iterator_category = std::random_access_iterator_tag;
            using value_type = const type;
            using difference_type = std::ptrdiff_t;
            using pointer = const type*;
            using reference = const type&;
            friend Vector;
            const_reverse_iterator(pointer ptr) : m_ptr(ptr) {}
            reference operator*()
            {
                return *m_ptr;
            }
            const reference operator*() const 
            {
                return *m_ptr;
            }
            pointer operator->()
            {
                return m_ptr;
            }
            const pointer operator->() const 
            {
                return m_ptr;
            }
            const_reverse_iterator& operator++()
            {
                --m_ptr;
                return *this;
            }
            const_reverse_iterator& operator--()
            {
                ++m_ptr;
                return *this;
            }
            const_reverse_iterator operator+(difference_type n) const
            {
                return const_reverse_iterator(m_ptr - n);
            }
            const_reverse_iterator operator-(difference_type n) const
            {
                return const_reverse_iterator(m_ptr + n);
            }
            difference_type operator-(const const_reverse_iterator& other) const
            {
                return m_ptr + other.m_ptr;
            }
            difference_type operator+(const const_reverse_iterator& other) const
            {
                return m_ptr - other.m_ptr;
            }
            bool operator==(const const_reverse_iterator& other) const
            {
                return m_ptr == other.m_ptr;
            }
            bool operator!=(const const_reverse_iterator& other) const
            {
                return m_ptr != other.m_ptr;
            }
            bool operator<(const const_reverse_iterator& other) const
            {
                return m_ptr < other.m_ptr;
            }
            bool operator>(const const_reverse_iterator& other) const
            {
                return m_ptr > other.m_ptr;
            }
            bool operator<=(const const_reverse_iterator& other) const
            {
                return m_ptr <= other.m_ptr;
            }
            bool operator>=(const const_reverse_iterator& other) const
            {
                return m_ptr >= other.m_ptr;
            }
        private:
            pointer m_ptr;
        };
        size_t capacity;
        size_t size;
        type* m_data;
    };
}
template<typename type>
std::ostream& operator<<(std::ostream& os, const KT::Vector<type>& tab)
{
    if (tab.Size() == 0)
        return os;
    os << "(";
    for (auto i = 0; i < tab.Size() - 1; ++i)
        os << tab[i] << ", ";
    os << tab[tab.Size() - 1] << ")";
    return os;
}