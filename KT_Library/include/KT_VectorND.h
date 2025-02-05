#pragma once
#include <exception>
#include <initializer_list>
#include <sstream>

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

        VectorND(std::initializer_list<type> list)
        {
            if (list.size() > size)
                throw std::runtime_error("Out of Range");

            std::copy(list.begin(), list.end(), m_data.data());
            std::fill((m_data.begin() + list.size()), m_data.end(), type());
        }
        VectorND()
        {
            std::fill(m_data.begin(), m_data.end(), type());
        }
        VectorND(const VectorND& tab)
        {
            if (tab.m_data.Size() != size)
                throw std::runtime_error("size must be equal");
            std::copy(tab.m_data.begin(), tab.m_data.end(), m_data.data());
        }
        VectorND& operator=(VectorND& tab)
        {
            if (m_data.Size() != tab.m_data.Size())
                throw std::out_of_range("size must be equal");
            if (this != &tab)
                std::copy(tab.m_data.begin(), tab.m_data.end(), m_data.data());
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