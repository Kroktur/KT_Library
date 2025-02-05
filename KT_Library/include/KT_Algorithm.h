#pragma once
/*****************************************************************//**
 * \file   KT_Algorithm.h
 * \brief  This file contains the sort and transform
 *
 * \author Kroktur
 * \date   February 2025
 *********************************************************************/
#include "KT_FusionSort.h"
#include "KT_BubbleSort.h"
#include "KT_InsertionSort.h"
namespace KT
{
	template<typename container, template<typename>class SortMethode>
	void Sort(container& data)
	{
		SortMethode<container>()(data);
	}

	template<typename input, typename output, typename fn>
	void transform(input* begin, input* end, output* dest, fn fn_)
	{
		for (auto it = begin; it != end; ++it, ++dest)
		{
			*dest = fn_(*it);
		}
	}
}
