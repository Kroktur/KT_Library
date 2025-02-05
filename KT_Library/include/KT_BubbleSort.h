#pragma once
namespace KT
{
	template<typename container>
	struct BubbleSort
	{
		void operator()(container& data)
		{
			for (auto it = data.begin(); it != data.end(); ++it)
			{
				for (auto it2 = data.begin(); it2!= data.end() - 1; ++it2)
				{
					if (*it2 > *(it2 + 1))
					{
						std::swap(*it2, *(it2 + 1));
					}
				}
			}
		}

	};
}
