#include <iostream>
#include "KT_Array.h"
#include "KT_List.h"
#include "KT_Vector.h"
int main()
{
	//KT::List<int*>tst;
	//tst.pushBack(new int(5));
	//delete tst[0];
	//tst.erase(tst.begin());

	//KT::List<int>a;
	//a.pushBack(1);
	//a.pushBack(2);
	//std::cout << a.at(0) << std::endl;
	//std::cout << a.Empty() << std::endl;
	//a.pushBack(3);
	//a.pushBack(4);
	//a.pushBack(8);
	//a.pushBack(8);
	//a.pushBack(8);
	//a.pushBack(8);
	//a.pushBack(8);
	//a.pushBack(8);
	//a.pushBack(8);
	//KT::List<int>b;
	//std::cout << a.Size() << std::endl;
	//b.assign(a.begin(), a.end());
	//auto rr = a.begin();
	//++rr;
	//std::cout << *rr << std::endl;
	//std::cout << b.Size() << std::endl;
	//auto it = b.begin();
	////List<int>::advanceptr(it, 12);
	//b.erase(it);
	//std::cout << b[0] << std::endl;
	KT::Vector<int> a;
	KT::Vector<int> b{ 1,4,3,2 };
	KT::Vector<int> c(b);
	std::cout << c << std::endl;
	c.resize(3);
	c.pushBack(13);
	std::cout << c.back() << std::endl;
	std::cout << c.front() << std::endl;
	std::cout << c << std::endl;
	c.erase(c.begin());
	std::cout << c << std::endl;
	c.clear();
	c.resize(2);
	std::cout << c[0] << std::endl;
	c.pushBack(19);
	std::cout << c << std::endl;
	c.popBack();
	std::cout << c << std::endl;
	c.pushBack(19);
	c.pushBack(19);
	c.pushBack(19);
	c.pushBack(19);
	c.pushBack(19);
	c.assign(3, 22);
	std::cout << c << std::endl;
	c.assign({1,2,3});
	std::cout << c << std::endl;
	c.assign(b.begin(),b.end());
	std::cout << c << std::endl;
	c.insert(c.begin(), 100);
	std::cout << c << std::endl;
	std::cout << c.at(0) << std::endl;
	KT::Vector<int> t = c;
	t.clear();
	std::cout << c << std::endl;
	std::cout << t << std::endl;
	c.pushBack(1313);
	std::cout << t << std::endl;
}