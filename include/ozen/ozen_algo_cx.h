//	algorithm C++14 constexpr version.
//
//	Copyright(c) 2018, YOSHIDA Masahiro
//	MIT License
#pragma once
#ifndef	OZEN_ALGO_CX_H
#define	OZEN_ALGO_CX_H

#include <algorithm>



#if	(__cplusplus <= 201703L)

// C++2x support constexpr.
namespace ozen
{

	///	@brief	C++2x std::equal substitute.
	template <class I1, class I2, class Op>
	static constexpr bool equal(I1 a0, I1 a1, I2 b0, I2 b1, Op op)
	{
		if ((a1 - a0) != (b1 - b0)) {
			return false;
		}
		while (a0 != a1) {
			if (!op(*a0, *b0)) {
				return false;
			}
			++a0, ++b0;
		}
		return true;
	}
}

#endif	// 	(__cplusplus <= 201703L).


#endif
