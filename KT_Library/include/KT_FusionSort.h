#pragma once
namespace KT
{
	template<typename container>
	struct FusionSort
	{
		using Iterator = container::iterator;
		using difference_type = container::iterator::difference_type;
		void operator()(container& data)
		{
			internalfusion(data, data.begin(), data.end());

		}
	private:
		void merge_fusion(container& val, Iterator startidx, Iterator middleidx, Iterator endrightidx)
		{
			auto leftendidx = middleidx;
			auto rightstartidx = leftendidx + 1;

			auto curentleftidx = startidx;
			auto curentrightidx = rightstartidx;

			auto tabidx = 0;

			auto tabsize = endrightidx - startidx + 1;
			auto tmptab = val;

			while (curentleftidx != leftendidx + 1 || curentrightidx != endrightidx + 1)
			{
				if (curentleftidx == leftendidx + 1)
				{
					tmptab[tabidx] = *curentrightidx;
					++tabidx;
					++curentrightidx;
				}
				else if (curentrightidx == endrightidx + 1)
				{
					tmptab[tabidx] = *curentleftidx;
					++tabidx;
					++curentleftidx;
				}
				else
				{
					if (*curentleftidx <= *curentrightidx)
					{
						tmptab[tabidx] = *curentleftidx;
						++tabidx;
						++curentleftidx;
					}
					else
					{
						tmptab[tabidx] = *curentrightidx;
						++tabidx;
						++curentrightidx;
					}
				}
			}
			/*for (auto i = 0; i < tabsize; ++i)
			{
				val[i + startidx] = tmptab[i];
			}*/

		}
		void internalfusion(container& val,  Iterator startidx, Iterator endidx)
		{
			if (startidx == endidx)
				return;

			auto middleidx = startidx +(/*(endidx + startidx) /*/ 2);

			internalfusion(val, startidx, middleidx);
			internalfusion(val, middleidx + 1, endidx);

			merge_fusion(val, startidx, middleidx, endidx);
		}
		
	};
}
