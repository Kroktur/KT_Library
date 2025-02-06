#pragma once
/*****************************************************************//**
 * \file   KT_Math_Algorithm.h
 * \brief  This file contains the Algorithm for KT::VectorND and KT::Matrix
 *
 * \author Kroktur
 * \date   February 2025
 *********************************************************************/
#include "KT_VectorND.h"
#include <cmath>
namespace KT
{
	template <typename type >
	KT::VectorND<type, 3>  VectorProduct(const KT::VectorND<type, 3>& lhs, const KT::VectorND<type, 3>& rhs)
	{
		KT::VectorND<type, 3> result;
		result[0] = lhs[1] * rhs[2] - lhs[2] * rhs[1];
		result[1] = lhs[2] * rhs[0] - lhs[0] * rhs[2];
		result[2] = lhs[0] * rhs[1] - lhs[1] * rhs[0];
		return result;
	}
	template<typename type, size_t size>
	type Norme(const KT::VectorND<type, size>& data)
	{
		type result = type{};
		for (auto it = data.begin(); it != data.end(); ++it)
		{
			result += (*it * *it);
		}
		return std::sqrt(result);
	};
	template<typename type,size_t size>
	KT::VectorND<type, size> VectorNormalization( const KT::VectorND<type,size>& data)
	{
		KT::VectorND<type, size> result;
		type norme = Norme<type, size>(data);
		auto itresult = result.begin();
		for (auto it = data.begin(); it != data.end(); ++it)
		{
			*itresult = (*it / norme);
			++itresult;
		}
		return result;
	};
	template <typename type ,size_t size>
	type VectorScalarProduct(const KT::VectorND<type, size>& lhs, const KT::VectorND<type, size>& rhs)
	{
		type result = type{};
		auto it2 = rhs.begin();
		for (auto it = lhs.begin(); it != lhs.end(); ++it)
		{
			result += (*it * *it2);
			++it2;
		}
		return result;
	}

}
