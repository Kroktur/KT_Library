#pragma once
namespace KT
{
	template<typename container>
	struct FusionSort
	{
		using Iterator = container::iterator;
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
			/*auto leftendidx = middleidx;
			auto rightstartidx = middleidx + 1;
			int curentleftidx = startidx;
			int curentrightidx = rightstartidx;
			int tabidx = 0;

			int tabsize = (leftendidx - startidx + 1) + (endrightidx - rightstartidx + 1);
			int* tmptab = new int[tabsize];*/

			auto tabsize = endrightidx - startidx + 1;
			//int tabsize = (leftendidx - startidx + 1) + (endrightidx - rightstartidx + 1);
			auto tmptab = val;

			while (curentleftidx != leftendidx + 1 || curentrightidx != endrightidx + 1)
			{
				if (curentleftidx == leftendidx + 1)
				{
					tmptab[tabidx] = val[curentrightidx];
					++tabidx;
					++curentrightidx;
				}
				else if (curentrightidx == endrightidx + 1)
				{
					tmptab[tabidx] = val[curentleftidx];
					++tabidx;
					++curentleftidx;
				}
				else
				{
					if (val[curentleftidx] <= val[curentrightidx])
					{
						tmptab[tabidx] = val[curentleftidx];
						++tabidx;
						++curentleftidx;
					}
					else
					{
						tmptab[tabidx] = val[curentrightidx];
						++tabidx;
						++curentrightidx;
					}
				}
			}
			for (auto i = 0; i < tabsize; ++i)
			{
				val[i + startidx] = tmptab[i];
			}
			delete[] tmptab;
			tmptab = nullptr;
		}
		void internalfusion(container& val, const Iterator& startidx, const Iterator& endidx)
		{
			if (startidx == endidx)
				return;

			auto middleidx = (endidx + startidx) / 2;

			internalfusion(val, startidx, middleidx);
			internalfusion(val, middleidx + 1, endidx);

			merge_fusion(val, startidx, middleidx, endidx);
		}
		
	};
}
