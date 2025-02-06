#pragma once
/*****************************************************************//**
 * \file   KT_Math.h
 * \brief  This file contains all the function stl like
 *
 * \author Kroktur
 * \date   February 2025
 *********************************************************************/
namespace KT
{
	namespace Math
	{
		template<typename input, typename oupout, typename value>
		void Fill(input begin, oupout end, const value& val)
		{
			if (begin == end)
				return;
			for (auto it = begin; it != end; ++it)
			{
				*it = val;
			}
		}
		template<typename input, typename output, typename dest>
		void Copy(input begin, output end, dest val)
		{
			if (begin == end)
				return;
			size_t i = 0;
			for (auto it = begin; it != end; ++it)
			{
				val[i] = *it;
				++i;
			}
		}
		template<typename type>
		void Swap(type& lhs, type& rhs)
		{
			auto type = lhs;
			lhs = rhs;
			rhs = lhs;
		}
	}
	
}