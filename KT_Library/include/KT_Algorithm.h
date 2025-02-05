#pragma once
#include "KT_Vector.h"
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
}
