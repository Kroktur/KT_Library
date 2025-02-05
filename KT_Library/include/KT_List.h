#pragma once 
/*****************************************************************//**
 * \file   KT_Array.h
 * \brief  This file contains the code for KT::List
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
	class List
	{
	public:
	
		struct Node;
		struct iterator;
		struct const_iterator;
		struct reverse_iterator;
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
		~List() { clear(); }
		List() :size(0) { Head.Next = &Tail;  Tail.Previous = &Head; }
		List(const List& tab) :size(0)
		{
			Head.Next = &Tail;  
			Tail.Previous = &Head;
			for (auto it = tab.begin(); it != tab.end(); ++it)
			{
				pushBack(*it);
			}
		}
		List(const std::initializer_list<type>& list) :size(0)
		{
			Head.Next = &Tail;  Tail.Previous = &Head;
			for (const auto& element : list)
			{
				pushBack(element);
			}
		}
		void resize(const size_t& idx)
		{
			if (idx < size)
			{
				for (size_t i = size; i > idx; --i)
				{
					popBack();
				}

			}
			if (idx > size)
			{
				for (size_t i = size; i < idx; ++i)
				{
					pushBack(type{});
				}
			}

		}
		void swap(List<type>& Newlist)
		{
			List<type> tmp = *this;
			*this = Newlist;
			Newlist = tmp;
		}
		void pushBack(const type& val)
		{
			Node* NewVal = new Node(val);
			Tail.Previous->Next = NewVal;
			NewVal->Next = &Tail;
			NewVal->Previous = Tail.Previous;
			Tail.Previous = NewVal;
			++size;
		}
		void popBack()
		{
			if (Empty())
				throw std::out_of_range("List is Empty");
			auto todelete = Tail.Previous;
			Tail.Previous = todelete->Previous;
			todelete->Previous->Next = &Tail;

			todelete->Next = nullptr;
			todelete->Previous = nullptr;
			delete todelete;

			--size;
		}
		void pushFront(const type& val)
		{
			Node* NewVal = new Node(val);
			Head.Next->Previous = NewVal;
			NewVal->Previous = &Head;
			NewVal->Next = Head.Next;
			Head.Next = NewVal;
			++size;
		}
		void popFront()
		{
			if (Empty())
				throw std::out_of_range("List is Empty");
			auto todelete = Head.Next;
			Head.Next = todelete->Next;
			todelete->Next->Previous = &Head;

			todelete->Next = nullptr;
			todelete->Previous = nullptr;
			delete todelete;

			--size;
		}
		reference operator[](const size_t& idx)
		{
			auto it = begin();
			for (auto i = 0; i < idx; ++i)
			{
				++it;
			}
			return *it;

		}
		const_reference operator[](const size_t& idx) const
		{
			auto it = begin();
			for (auto i = 0; i < idx; ++i)
			{
				++it;
			}
			return *it;
		}
		reference at(const size_t& idx)
		{
			if (Empty())
				throw std::out_of_range("vector is empty");
			if (idx >= size)
				throw std::out_of_range("idx out of vector range");
			auto it = begin();
			for (auto i = 0; i < idx; ++i)
			{
				++it;
			}
			return *it;
		}
		const_reference at(const size_t& idx) const
		{
			if (Empty())
				throw std::out_of_range("vector is empty");
			if (idx >= size)
				throw std::out_of_range("idx out of vector range");
			auto it = begin();
			for (auto i = 0; i < idx; ++i)
			{
				++it;
			}
			return *it;
		}
		bool Empty()
		{
			return size == 0;
		}
		bool Empty() const
		{
			return size == 0;
		}
		size_t Size()
		{
			return size;
		}
		size_t Size() const
		{
			return size;
		}
		void erase(const iterator& it)
		{
			if (find(it) == end())
				throw std::out_of_range("out of range");
			auto supr = it.m_node;
			supr->Previous->Next = supr->Next;
			supr->Next->Previous = supr->Previous;

			delete supr;

			--size;
		}
		iterator begin()
		{
			return iterator(Head.Next);
		}
		const_iterator begin() const
		{
			return const_iterator(Head.Next);
		}
		iterator end()
		{
			return iterator(&Tail);
		}
		const_iterator end() const
		{
			return const_iterator(&Tail);
		}
		reference front()
		{
			return Head.Next->data;
		}
		const_reference front() const
		{
			return Head.Next->data;
		}
		reference back()
		{
			return Tail.Previous->data;
		}
		const_reference back() const
		{
			return Tail.Previous->data;
		}
		void clear()
		{
			while (!Empty())
				popFront();
			resize(0);
		}
		List& operator=(const List& tab)
		{
			clear();
			for (auto it = tab.begin(); it != tab.end(); ++it)
			{
				pushBack(*it);
			}
			return *this;
		}
		void assign(const iterator& begin, const iterator& end)
		{
			clear();
			for (auto it = begin; it != end; ++it)
			{
				pushBack(*it);
			}
		}
		void assign(const size_t& sizeofvec, const value_type& data)
		{
			clear();
			for (size_t i = 0; i < sizeofvec; ++i)
			{
				pushBack(data);
			}
		}
		void assign(const std::initializer_list<type>& list)
		{
			clear();
			for (const auto& element : list)
			{
				pushBack(element);
			}
		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(Tail.Previous);
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(Tail.Previous);
		}
		reverse_iterator rend()
		{
			return reverse_iterator(&Head);
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(&Head);
		}
		size_t max_size()
		{
			return std::numeric_limits<size_t>::max() / sizeof(type);
		}
		size_t max_size() const
		{
			return std::numeric_limits<size_t>::max() / sizeof(type);
		}
		void insert(const iterator&  newit, const value_type& value)
		{
			if (find(newit) == end())
				throw std::out_of_range("Out of range");
			auto oldnode = newit.m_node;
			Node* nodetoadd = new Node(value);
			nodetoadd->Next = oldnode;
			nodetoadd->Previous = oldnode->Previous;
			oldnode->Previous->Next = nodetoadd;
			oldnode->Previous = nodetoadd;
			++size;
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
		const_iterator find(const iterator& ptr) const
		{
			for (auto it = begin(); it != end(); ++it)
			{
				if (it == ptr)
					return it;
			}
			return end();
		}
	private:

		struct Node
		{
			Node() :Next(nullptr), Previous(nullptr)
			{
			}
			Node( type val) :data(val), Next(nullptr), Previous(nullptr)
			{
			}
			type data;
			Node* Next;
			Node* Previous;
		};

		struct iterator {
			//this iterator compatible with stl
			using iterator_category = std::random_access_iterator_tag;
			using value_type = type;
			using difference_type = std::ptrdiff_t;
			using pointer = type*;
			using reference = type&;
			friend List;
			iterator(Node* ptr) : m_node(ptr) {}
			reference operator*()
			{
				return m_node->data;
			}
			const reference  operator*() const
			{
				return m_node->data;
			}
			Node* operator->()
			{
				return m_node;
			}
			const Node* operator->() const
			{
				return m_node;
			}
			iterator& operator++()
			{
				m_node = m_node->Next;
				return *this;
			}
			iterator& operator--()
			{
				m_node = m_node->Previous;
				return *this;
			}
			iterator operator+(difference_type n) const
			{
				auto curentnode = m_node;
				for (size_t i = 0; i < n; ++i)
				{
					curentnode = curentnode->Next;
				}
				return iterator(curentnode);
			}
			iterator operator-(difference_type n) const
			{
				auto curentnode = m_node;
				for (size_t i = 0; i < n; ++i)
				{
					curentnode = curentnode->Previous;
				}
				return iterator(curentnode);
			}
			difference_type operator-(const iterator& other) const
			{
				difference_type diff = 0;
				for(auto it = *this; it != other ; --it)
				{
					++diff;
				}
				return diff;
			}
			difference_type operator+(const iterator& other) const
			{
				difference_type diff = 0;
				for (auto it = *this; it != other; ++it)
				{
					++diff;
				}
				return diff;
			}
			bool operator==(const iterator& other) const
			{
				return m_node == other.m_node;
			}
			bool operator!=(const iterator& other) const
			{
				return m_node != other.m_node;
			}
			bool operator<(const iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					curent = curent->Next;
					if (curent == other.m_node)
						return true;
					
				}
				return false;
			}
			bool operator>(const iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					curent = curent->Previous;
					if (curent == other.m_node)
						return true;

				}
				return false;
			}
			bool operator<=(const iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					if (curent == other.m_node)
						return true;
					curent = curent->Next;
				}
				return false;
			}
			bool operator>=(const iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					if (curent == other.m_node)
						return true;
					curent = curent->Previous;
				}
				return false;
			}
		private:
			Node* m_node;
		};
		struct const_iterator {
			//this iterator compatible with stl
			using iterator_category = std::random_access_iterator_tag;
			using value_type = const type;
			using difference_type = std::ptrdiff_t;
			using pointer = const type*;
			using reference = const type&;
			friend List;
			const_iterator(const Node* ptr) : m_node(ptr) {}
			reference operator*()
			{
				return m_node->data;
			}
			reference operator*() const
			{
				return m_node->data;
			}
			Node* operator->()
			{
				return m_node;
			}
			const Node* operator->() const
			{
				return m_node;
			}
			const_iterator& operator++()
			{
				m_node = m_node->Next;
				return *this;
			}
			const_iterator& operator--()
			{
				m_node = m_node->Previous;
				return *this;
			}
			const_iterator operator+(difference_type n) const
			{
				auto curentnode = m_node;
				for (size_t i = 0; i < n; ++i)
				{
					curentnode = curentnode->Next;
				}
				return const_iterator(curentnode);
			}
			const_iterator operator-(difference_type n) const
			{
				auto curentnode = m_node;
				for (size_t i = 0; i < n; ++i)
				{
					curentnode = curentnode->Previous;
				}
				return const_iterator(curentnode);
			}
			difference_type operator-(const const_iterator& other) const
			{
				difference_type diff = 0;
				for (auto it = *this; it != other; --it)
				{
					++diff;
				}
				return diff;
			}
			difference_type operator+(const const_iterator& other) const
			{
				difference_type diff = 0;
				for (auto it = *this; it != other; ++it)
				{
					++diff;
				}
				return diff;
			}
			bool operator==(const const_iterator& other) const
			{
				return m_node == other.m_node;
			}
			bool operator!=(const const_iterator& other) const
			{
				return m_node != other.m_node;
			}
			bool operator<(const const_iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					curent = curent->Next;
					if (curent == other.m_node)
						return true;

				}
				return false;
			}
			bool operator>(const const_iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					curent = curent->Previous;
					if (curent == other.m_node)
						return true;

				}
				return false;
			}
			bool operator<=(const const_iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					if (curent == other.m_node)
						return true;
					curent = curent->Next;
				}
				return false;
			}
			bool operator>=(const const_iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					if (curent == other.m_node)
						return true;
					curent = curent->Previous;
				}
				return false;
			}
		private:
			const Node* m_node;
		};
		struct reverse_iterator {
			//this iterator compatible with stl
			using iterator_category = std::random_access_iterator_tag;
			using value_type = type;
			using difference_type = std::ptrdiff_t;
			using pointer = type*;
			using reference = type&;
			friend List;
			reverse_iterator(Node* ptr) : m_node(ptr) {}
			reference operator*()
			{
				return m_node->data;
			}
			const reference operator*() const
			{
				return m_node->data;
			}
			const Node* operator->()
			{
				return m_node;
			}
			const Node* operator->() const
			{
				return m_node;
			}
			reverse_iterator& operator++()
			{
				m_node = m_node->Previous;
				return *this;
			}
			reverse_iterator& operator--()
			{
				m_node = m_node->Next;
				return *this;
			}
			reverse_iterator operator+(difference_type n) const
			{
				auto curentnode = m_node;
				for (size_t i = 0; i < n; ++i)
				{
					curentnode = curentnode->Previous;
				}
				return reverse_iterator(curentnode);
			}
			reverse_iterator operator-(difference_type n) const
			{
				auto curentnode = m_node;
				for (size_t i = 0; i < n; ++i)
				{
					curentnode = curentnode->Next;
				}
				return reverse_iterator(curentnode);
			}
			difference_type operator-(const reverse_iterator& other) const
			{
				difference_type diff = 0;
				for (auto it = *this; it != other; --it)
				{
					++diff;
				}
				return diff;
			}
			difference_type operator+(const reverse_iterator& other) const
			{
				difference_type diff = 0;
				for (auto it = *this; it != other; ++it)
				{
					++diff;
				}
				return diff;
			}
			bool operator==(const reverse_iterator& other) const
			{
				return m_node == other.m_node;
			}
			bool operator!=(const reverse_iterator& other) const
			{
				return m_node != other.m_node;
			}
			bool operator<(const reverse_iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					curent = curent->Next;
					if (curent == other.m_node)
						return true;

				}
				return false;
			}
			bool operator>(const reverse_iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					curent = curent->Previous;
					if (curent == other.m_node)
						return true;

				}
				return false;
			}
			bool operator<=(const reverse_iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					if (curent == other.m_node)
						return true;
					curent = curent->Next;
				}
				return false;
			}
			bool operator>=(const reverse_iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					if (curent == other.m_node)
						return true;
					curent = curent->Previous;
				}
				return false;
			}
		private:
			Node* m_node;
		};
		struct const_reverse_iterator {
			//this iterator compatible with stl
			using iterator_category = std::random_access_iterator_tag;
			using value_type = const type;
			using difference_type = std::ptrdiff_t;
			using pointer = const type*;
			using reference = const type&;
			friend List;
			const_reverse_iterator(const Node* ptr) : m_node(ptr) {}
			reference operator*()
			{
				return m_node->data;
			}
			const reference operator*() const
			{
				return m_node->data;
			}
			const Node* operator->()
			{
				return m_node;
			}
			const Node* operator->() const
			{
				return m_node;
			}
			const_reverse_iterator& operator++()
			{
				m_node = m_node->Previous;
				return *this;
			}
			const_reverse_iterator& operator--()
			{
				m_node = m_node->Next;
				return *this;
			}
			const_reverse_iterator operator+(difference_type n) const
			{
				auto curentnode = m_node;
				for (size_t i = 0; i < n; ++i)
				{
					curentnode = curentnode->Previous;
				}
				return const_reverse_iterator(curentnode);
			}
			const_reverse_iterator operator-(difference_type n) const
			{
				auto curentnode = m_node;
				for (size_t i = 0; i < n; ++i)
				{
					curentnode = curentnode->Next;
				}
				return const_reverse_iterator(curentnode);
			}
			difference_type operator-(const const_reverse_iterator& other) const
			{
				difference_type diff = 0;
				for (auto it = *this; it != other; --it)
				{
					++diff;
				}
				return diff;
			}
			difference_type operator+(const const_reverse_iterator& other) const
			{
				difference_type diff = 0;
				for (auto it = *this; it != other; ++it)
				{
					++diff;
				}
				return diff;
			}
			bool operator==(const const_reverse_iterator& other) const
			{
				return m_node == other.m_node;
			}
			bool operator!=(const const_reverse_iterator& other) const
			{
				return m_node != other.m_node;
			}
			bool operator<(const const_reverse_iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					curent = curent->Next;
					if (curent == other.m_node)
						return true;

				}
				return false;
			}
			bool operator>(const const_reverse_iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					curent = curent->Previous;
					if (curent == other.m_node)
						return true;

				}
				return false;
			}
			bool operator<=(const const_reverse_iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					if (curent == other.m_node)
						return true;
					curent = curent->Next;
				}
				return false;
			}
			bool operator>=(const const_reverse_iterator& other) const
			{
				auto curent = m_node;
				while (curent != nullptr)
				{
					if (curent == other.m_node)
						return true;
					curent = curent->Previous;
				}
				return false;
			}

		private:
			const Node* m_node;
		};
		Node Head;
		Node Tail;
		size_t size;
	};

}
template<typename type>
std::ostream& operator<<(std::ostream& os,  KT::List<type> tab)
{
	if (tab.Empty())
		return os;
	os << "(";
	for (auto i = 0; i < tab.Size() - 1; ++i)
		os << tab[i] << ", ";
	os << tab[tab.Size() - 1] << ")";
	return os;
}