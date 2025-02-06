#pragma once
/*****************************************************************//**
 * \file   KT_Matrix.h
 * \brief  This file contains the code for KT::Matrix
 *
 * \author Kroktur
 * \date   February 2025
 *********************************************************************/
#include <exception>
#include <initializer_list>
#include <sstream>

#include "KT_Array.h"
namespace KT
{
    template<typename type, size_t height , size_t width>
    class Matrix
    {
    public:
        using value_type = type;
        using pointer = type*;
        using const_pointer = const type*;
        using reference = type&;
        using const_reference = const type&;
        using reverse_iterator = KT::Array<type, width * height>::reverse_iterator;
        using const_reverse_iterator = KT::Array<type, width * height >::const_reverse_iterator;
        using iterator = KT::Array<type, width* height>::iterator;
        using const_iterator = KT::Array<type, width* height>::const_iterator;
        Matrix(std::initializer_list<type> list)
        {
            if (list.size() > size)
                throw std::runtime_error("Out of Range");

            std::copy(list.begin(), list.end(), m_data.data());
            std::fill((m_data.begin() + list.size()), m_data.end(), type());
        }
        Matrix()
        {
            std::fill(m_data.begin(), m_data.end(), type());
        }
        Matrix(const Matrix& tab)
        {
            if (tab.m_data.Size() != size)
                throw std::runtime_error("size must be equal");
            std::copy(tab.m_data.begin(), tab.m_data.end(), m_data.data());
        }
        Matrix& operator=(const Matrix& tab)
        {
            if (m_data.Size() != tab.m_data.Size())
                throw std::out_of_range("size must be equal");
            if (this != &tab)
                std::copy(tab.m_data.begin(), tab.m_data.end(), m_data.data());
            return *this;
        }
        reference getCell(size_t row, size_t col)
        {
            return m_data.at(row * width + col);
        }
        const_reference getCell(size_t row, size_t col) const
        {
            return m_data.at(row * width + col);
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
        KT::Matrix<type, height, width > operator+(const KT::Matrix<type, height, width >& data)
        {
            KT::Matrix<type, height, width > result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] = data[i] + m_data[i];
            }
            return result;
        }
        KT::Matrix<type, height, width > operator-(const KT::Matrix<type, height, width >& data)
        {
            KT::Matrix<type, height, width > result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] = data[i] - m_data[i];
            }
            return result;
        }
        KT::Matrix<type, height, width > operator*(const int& idx)
        {
            KT::Matrix<type, height, width > result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] = m_data[i] * idx;
            }
            return result;
        }
        KT::Matrix<type,height,width > operator/(const int& idx)
        {
            if (idx == 0)
                throw std::runtime_error("cannot divide by 0");
            KT::Matrix<type, height, width > result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] = m_data[i] / idx;
            }
            return result;
        }
        bool operator ==(const KT::Matrix<type, height, width >& data)
        {
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                if (data[i] != m_data[i])
                    return false;
            }
            return true;
        }
        bool operator !=(const KT::Matrix<type, height, width >& data)
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
        KT::Matrix<type, height, width > operator+(const KT::Matrix<type, height, width >& data) const
        {
            KT::Matrix<type, height, width > result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] = data[i] + m_data[i];
            }
            return result;
        }
        KT::Matrix<type, height, width > operator-(const KT::Matrix<type, height, width >& data) const
        {
            KT::Matrix<type, height, width> result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] = data[i] - m_data[i];
            }
            return result;
        }
        KT::Matrix<type, height, width > operator*(const int& idx) const
        {
            KT::Matrix<type, height, width > result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] = m_data[i] * idx;
            }
            return result;
        }
        KT::Matrix<type, height, width > operator/(const int& idx) const
        {
            if (idx == 0)
                throw std::runtime_error("cannot divide by 0");
            KT::Matrix<type, height, width > result;
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                result[i] = m_data[i] / idx;
            }
            return result;
        }
        bool operator ==(const KT::Matrix<type, height, width >& data) const
        {
            for (size_t i = 0; i < m_data.Size(); ++i)
            {
                if (data[i] != m_data[i])
                    return false;
            }
            return true;
        }
        bool operator !=(const KT::Matrix<type, height, width >& data) const
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
        size_t size = width * height;
        KT::Array<type, height* width > m_data;
    };
}
template<typename type, size_t height, size_t width>
std::ostream& operator<<(std::ostream& os, const KT::Matrix<type, height, width >& tab)
{
    if (tab.Size() == 0)
        return os;
    for (auto i = 0; i < height; ++i)
    {
        os << "(";
        for (auto j = 0; j < width; ++j)
        {
            os << tab.getCell(i ,j) ;
            if (j != width - 1)
                os << ",";
        }
        os << ")" << std::endl;
    }
       
    return os;
}