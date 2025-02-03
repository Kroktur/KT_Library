#pragma once 
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
		~List() { clear(); }
		List() :size(0) { anchor.Next = &anchor; anchor.Previous = &anchor; }
		List(const List& tab) :size(0)
		{
			anchor.Next = &anchor; anchor.Previous = &anchor;
			for (auto it = tab.begin(); it != tab.end(); ++it)
			{
				pushBack(*it);
			}
		}
		List(std::initializer_list<type> list)
		{
			anchor.Next = &anchor; anchor.Previous = &anchor;
			for (size_t idx = 0; idx < list.size(); ++idx)
			{
				pushBack(list[idx]);
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
			anchor.Previous->Next = NewVal;
			NewVal->Previous = anchor.Previous;
			NewVal->Next = &anchor;
			anchor.Previous = NewVal;
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
		void pushFront(const type& val)
		{
			Node* NewVal = new Node(val);
			anchor.Next->Previous = NewVal;
			NewVal->Next = anchor.Next;
			NewVal->Previous = &anchor;
			anchor.Next = NewVal;
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
			return iterator(anchor.Next);
		}
		iterator end()
		{
			return iterator(&anchor);
		}
		const_iterator end() const
		{
			return iterator(&anchor);
		}
		reference front()
		{
			return anchor.Next->data;
		}
		const_reference front() const
		{
			return anchor.Next->data;
		}
		reference back()
		{
			return anchor.Previous->data;
		}
		const_reference back() const
		{
			return anchor.Previous->data;
		}
		void clear()
		{
			while (!Empty())
				popFront();

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
		void assign(iterator begin, iterator end)
		{
			clear();
			for (auto it = begin; it != end; ++it)
			{
				pushBack(*it);
			}
		}
		void assign(size_t sizeofvec, type data)
		{
			clear();
			for (size_t i = 0; i < sizeofvec; ++i)
			{
				pushBack(data);
			}
		}
		void assign(std::initializer_list<type> list)
		{
			clear();
			for (size_t i = 0; i < list.size(); ++i)
			{
				pushBack(list[i]);
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
			return reverse_iterator(anchor.Previous);
		}
		reverse_iterator rend()
		{
			return reverse_iterator(&anchor);
		}
		const_reverse_iterator rend() const
		{
			return reverse_iterator(&anchor);
		}
		size_t maxsize()
		{
			return std::numeric_limits<size_t>::max() / sizeof(type);
		}
		size_t maxsize() const
		{
			return std::numeric_limits<size_t>::max() / sizeof(type);
		}
		void insert(iterator newit, const type& value)
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
			Node(const  type& val) :data(val), Next(nullptr), Previous(nullptr)
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
			Node* operator->()
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
			Node* m_node;
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
			Node* operator->()
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
			Node* m_node;
		};
		Node anchor;
		size_t size;
	};
}
template<typename type>
std::ostream& operator<<(std::ostream& os, const KT::List<type>& tab)
{
	if (tab.Empty())
		return os;
	os << "(";
	for (auto i = 0; i < tab.Size() - 1; ++i)
		os << tab[i] << ", ";
	os << tab[tab.Size() - 1] << ")";
	return os;
}