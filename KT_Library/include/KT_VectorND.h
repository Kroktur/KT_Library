#pragma once
/*****************************************************************//**
 * \file   KT_VectorND.h
 * \brief  This file contains the code for KT::VectorND
 *
 * \author Kroktur
 * \date   February 2025
 *********************************************************************/
#include <exception>
#include <initializer_list>
#include <sstream>
#include "KT_Math.h"
#include "KT_Array.h"
namespace KT
{
	template<typename type , size_t size>
	class VectorND
	{
	public:
        using value_type = type;
        using pointer = type*;
        using const_pointer = const type*;
        using reference = type&;
        using const_reference = const type&;
        using reverse_iterator = KT::Array<type,size>::reverse_iterator;
        using const_reverse_iterator = KT::Array<type, size>::const_reverse_iterator;
        using iterator = KT::Array<type, size>::iterator;
        using const_iterator = KT::Array<type, size>::const_iterator;
        VectorND(std::initializer_list<type> list)
        {
            if (list.size() > size)
                throw std::runtime_error("Out of Range");

           KT::Math::Copy(list.begin(), list.end(), m_data.data());
            KT::Math::Fill((m_data.begin() + list.size()), m_data.end(), type());
        }
        VectorND()
        {
           KT::Math::Fill(m_data.begin(), m_data.end(), type());
        }
        VectorND(const VectorND& tab)
        {
            if (tab.m_data.Size() != size)
                throw std::runtime_error("size must be equal");
            KT::Math::Copy(tab.m_data.begin(), tab.m_data.end(), m_data.data());
        }
        VectorND& operator=(const VectorND& tab)
        {
            if (m_data.Size() != tab.m_data.Size())
                throw std::out_of_range("size must be equal");
            if (this != &tab)
               KT::Math::Copy(tab.m_data.begin(), tab.m_data.end(), m_data.data());
            return *this;
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
        size_t Size()
        {
            return m_data.Size();
        }
        const size_t Size() const
        {
            return m_data.Size();
        }
        bool Empty()
        {
            return m_data.Empty();
        }
        bool Empty() const
        {
            return  m_data.Empty();
        }
        pointer data()
        {
            return m_data.data();
        }
        const_pointer data() const
        {
            return m_data.data();
        }
        iterator begin()
        {
            if (Empty())
                throw std::out_of_range("Array is empty");
            return iterator(data());
        }
        iterator end()
        {
            if (Empty())
                throw std::out_of_range("Array is empty");
            return iterator(data() + size);
        }
        const_iterator begin() const
        {
            if (Empty())
                throw std::out_of_range("Array is empty");
            return const_iterator(data());
        }
        const_iterator end() const
        {
            if (Empty())
                throw std::out_of_range("Array is empty");
            return const_iterator(data() + size);
        }
        reverse_iterator rbegin()
        {
            if (Empty())
                throw std::out_of_range("Array is empty");
            return reverse_iterator(data() + size - 1);
        }
        reverse_iterator rend()
        {
            if (Empty())
                throw std::out_of_range("Array is empty");
            return reverse_iterator(data() - 1);
        }
        const_reverse_iterator rbegin() const
        {
            if (Empty())
                throw std::out_of_range("Array is empty");
            return const_reverse_iterator(data() + size - 1);
        }
        const_reverse_iterator rend() const
        {
            if (Empty())
                throw std::out_of_range("Array is empty");
            return const_reverse_iterator(data() - 1);
        }
        KT::VectorND<type, size> operator+(const KT::VectorND<type,size>& data)
        {
            KT::VectorND<type, size> result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] = data[i] + m_data[i];
            }
            return result;
        }
        KT::VectorND<type, size> operator-(const KT::VectorND<type,size>& data)
        {
            KT::VectorND<type, size> result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] = data[i] - m_data[i];
            }
            return result;
        }
        KT::VectorND<type, size> operator*(const int& idx)
        {
            KT::VectorND<type, size> result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] =  m_data[i] * idx;
            }
            return result;
        }
        KT::VectorND<type, size> operator/(const int& idx)
        {
            if (idx == 0)
                throw std::runtime_error("cannot divide by 0");
            KT::VectorND<type, size> result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] =  m_data[i] / idx;
            }
            return result;
        }
        bool operator ==(const KT::VectorND<type, size>& data)
        {
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                if (data[i] != m_data[i])
                    return false;
            }
            return true;
        }
        bool operator !=(const KT::VectorND<type, size>& data)
        {
            bool result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                if (data[i] == m_data[i])
                    result = false;
                else
                    result = true;
            }
            return result;
        }
        KT::VectorND<type, size> operator+(const KT::VectorND<type, size>& data) const 
        {
            KT::VectorND<type, size> result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] = data[i] + m_data[i];
            }
            return result;
        }
        KT::VectorND<type, size> operator-(const KT::VectorND<type, size>& data) const
        {
            KT::VectorND<type, size> result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] = data[i] - m_data[i];
            }
            return result;
        }
        KT::VectorND<type, size> operator*(const int& idx) const
        {
            KT::VectorND<type, size> result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] = m_data[i] * idx;
            }
            return result;
        }
        KT::VectorND<type, size> operator/(const int& idx) const
        {
            if (idx == 0)
                throw std::runtime_error("cannot divide by 0");
            KT::VectorND<type, size> result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] = m_data[i] / idx;
            }
            return result;
        }
        bool operator ==(const KT::VectorND<type, size>& data) const
        {
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                if (data[i] != m_data[i])
                    return false;
            }
            return true;
        }
        bool operator !=(const KT::VectorND<type, size>& data) const
        {
            bool result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                if (data[i] == m_data[i])
                    result = false;
                else
                    result = true;
            }
            return result;
        }
	private:
        KT::Array<type, size> m_data;
	};
}
template<typename type , size_t size>
std::ostream& operator<<(std::ostream& os, const KT::VectorND<type, size>& tab)
{
    if (tab.Size() == 0)
        return os;
    for (auto i = 0; i < tab.Size(); ++i)
        os << "(" << tab[i] << ")" << std::endl;
    return os;
}