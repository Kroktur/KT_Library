#pragma once 
/*****************************************************************//**
 * \file   KT_Array.h
 * \brief  This file contains the code for KT::IntrusiveList
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
	template <typename type>
	struct Node
	{
		Node() :Next(nullptr), Previous(nullptr)
		{
		}
		Node( const type& val) :data(val), Next(nullptr), Previous(nullptr)
		{
		}
		type data;
		Node* Next;
		Node* Previous;
	};
	template <typename type>
	std::ostream& operator<<(std::ostream& os, const Node<type>& node)
	{
		return os << node.data;
	}
	template<typename type>
	class IntrusiveList
	{
	public:
		struct iterator;
		struct reverse_iterator;
		struct const_iterator;
		struct const_reverse_iterator;
		using reverse_iterator = reverse_iterator;
		using const_reverse_iterator = const_reverse_iterator;
		using iterator = iterator;
		using const_iterator = const_iterator;
		using value_type = Node<type>;
		using pointer = Node<type>*;
		using const_pointer = const Node<type>*;
		using reference = Node<type>&;
		using const_reference = const Node<type>&;
		~IntrusiveList() { clear(); }
		IntrusiveList() :size(0) { anchor.Next = &anchor; anchor.Previous = &anchor; }
		IntrusiveList(const IntrusiveList& tab) :size(0)
		{
			anchor.Next = &anchor; anchor.Previous = &anchor;
			for (auto it = tab.begin(); it != tab.end(); ++it)
			{
				pushBack(*it);
			}
		}
		IntrusiveList(const std::initializer_list<Node<type>>& list):size(0)
		{
			anchor.Next = &anchor; anchor.Previous = &anchor;
			for (const auto& element : list)
			{
				pushBack(element);
			}
		}
		void resize(size_t idx)
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
					pushBack(Node<type>{});
				}
			}

		}
		IntrusiveList& operator=(const IntrusiveList& tab)
		{
			clear();
			for (auto it = tab.begin(); it != tab.end(); ++it)
			{
				pushBack(*it);
			}
			return *this;
		}
		void swap( IntrusiveList& Newlist)
		{
			IntrusiveList<type> tmp = *this;
			*this = Newlist;
			Newlist = tmp;
		}
		void pushBack(const Node<type>& val)
		{
			Node<type>* newval = new Node<type>(val.data);
			anchor.Previous->Next = newval;
			newval->Previous = anchor.Previous;
			newval->Next = &anchor;
			anchor.Previous = newval;
			++size;
		}
		void popBack()
		{
			if (Empty())
				throw std::out_of_range("List is Empty");
			auto todelete = anchor.Previous;
			anchor.Previous = todelete->Previous;
			todelete->Previous->Next = &anchor;

			todelete->Next = nullptr;
			todelete->Previous = nullptr;
			delete todelete;

			--size;
		}
		void pushFront(const Node<type>& val)
		{
			Node<type>* newval = new Node<type>(val.data);
			anchor.Next->Previous = newval;
			newval->Next = anchor.Next;
			newval->Previous = &anchor;
			anchor.Next = newval;

			++size;
		}
		void popFront()
		{
			if (Empty())
				throw std::out_of_range("List is Empty");
			auto todelete = anchor.Next;
			anchor.Next = todelete->Next;
			todelete->Next->Previous = &anchor;

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
			return iterator(anchor.Next);
		}
		const_iterator begin() const
		{
			return const_iterator(anchor.Next);
		}
		iterator end()
		{
			return iterator(&anchor);
		}
		const_iterator end() const
		{
			return const_iterator(&anchor);
		}
		reference front()
		{
			return *anchor.Next;
		}
		const_reference front() const
		{
			return *anchor.Next;
		}
		reference back()
		{
			return *anchor.Previous;
		}
		const_reference back() const
		{
			return *anchor.Previous;
		}
		void clear()
		{
			while (!Empty())
				popFront();

		}
		void assign(iterator begin, iterator end)
		{
			clear();
			for (auto it = begin; it != end; ++it)
			{
				pushBack(*it);
			}
		}
		void assign(size_t sizeofvec,  const Node<type>& data)
		{
			clear();
			for (size_t i = 0; i < sizeofvec; ++i)
			{
				pushBack(data);
			}
		}
		void assign(std::initializer_list<Node<type>> list)
		{
			clear();
			for (const auto& element : list)
			{
				pushBack(element);
			}
		}
		void static advanceptr(iterator& dest, int distance)
		{
			if (distance < 0)
			{
				for (int i = 0; i < -distance; ++i)
					--dest;
			}
			else
			{
				for (int i = 0; i < distance; ++i)
					++dest;
			}

		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(anchor.Previous);
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(anchor.Previous);
		}
		reverse_iterator rend()
		{
			return reverse_iterator(&anchor);
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(&anchor);
		}
		size_t maxsize()
		{
			return std::numeric_limits<size_t>::max() / sizeof(type);
		}
		size_t maxsize() const
		{
			return std::numeric_limits<size_t>::max() / sizeof(type);
		}
		void insert(const iterator& newit, const Node<type>& value)
		{
			if (find(newit) == end())
				throw std::out_of_range("Out of range");
			auto oldnode = newit.m_node;
			Node<type>* nodetoadd = new Node<type>(value.data);
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
		struct iterator {
			//this iterator compatible with stl
			using iterator_category = std::random_access_iterator_tag;
			using value_type = Node<type>;
			using difference_type = std::ptrdiff_t;
			using pointer = Node<type>*;
			using reference = Node<type>&;
			friend IntrusiveList;
			iterator(Node<type>* ptr) : m_node(ptr) {}
			reference operator*()
			{
				return *m_node;
			}
			pointer operator->()
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
				for (auto i = m_node; i != other; --i)
				{
					++diff;
				}
				return diff;
			}
			difference_type operator+(const iterator& other) const
			{
				difference_type diff = 0;
				for (auto i = m_node; i != other; ++i)
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
		private:
			Node<type>* m_node;
		};

		struct reverse_iterator {
			//this iterator compatible with stl
			using iterator_category = std::random_access_iterator_tag;
			using value_type = Node<type>;
			using difference_type = std::ptrdiff_t;
			using pointer = Node<type>*;
			using reference = Node<type>&;
			friend IntrusiveList;
			reverse_iterator(Node<type>* ptr) : m_node(ptr) {}
			reference operator*()
			{
				return *m_node;
			}
			pointer operator->()
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
				for (auto i = m_node; i != other; --i)
				{
					++diff;
				}
				return diff;
			}
			difference_type operator+(const reverse_iterator& other) const
			{
				difference_type diff = 0;
				for (auto i = m_node; i != other; ++i)
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
		private:
			Node<type>* m_node;
		};
		struct const_iterator {
			//this iterator compatible with stl
			using iterator_category = std::random_access_iterator_tag;
			using value_type = const Node<type>;
			using difference_type = std::ptrdiff_t;
			using pointer = const Node<type>*;
			using reference = const Node<type>&;
			friend IntrusiveList;
			const_iterator(const Node<type>* ptr) : m_node(ptr) {}
			reference operator*()
			{
				return *m_node;
			}
			pointer operator->()
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
				for (auto i = m_node; i != other; --i)
				{
					++diff;
				}
				return diff;
			}
			difference_type operator+(const const_iterator& other) const
			{
				difference_type diff = 0;
				for (auto i = m_node; i != other; ++i)
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
		private:
			const Node<type>* m_node;
		};
		
		struct const_reverse_iterator {
			//this iterator compatible with stl
			using iterator_category = std::random_access_iterator_tag;
			using value_type = const Node<type>;
			using difference_type = std::ptrdiff_t;
			using pointer = const Node<type>*;
			using reference = const Node<type>&;
			friend IntrusiveList;
			const_reverse_iterator(const Node<type>* ptr) : m_node(ptr) {}
			reference operator*()
			{
				return *m_node;
			}
			pointer operator->()
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
				for (auto i = m_node; i != other; --i)
				{
					++diff;
				}
				return diff;
			}
			difference_type operator+(const const_reverse_iterator& other) const
			{
				difference_type diff = 0;
				for (auto i = m_node; i != other; ++i)
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
		private:
			const Node<type>* m_node;
		};
		Node<type> anchor;
		size_t size;
	};
}
template< typename type>
std::ostream& operator<<(std::ostream& os, const KT::IntrusiveList<type>& tab)
{
	if (tab.Empty())
		return os;
	os << "(";
	for (auto i = 0; i < tab.Size() - 1; ++i)
		os << tab[i] << ", ";
	os << tab[tab.Size() - 1] << ")";
	return os;
}