#include "KT_Algorithm.h"
#include "Test.h"
#include"KT_Container.h"


int main()
{
	{
		Test_Units Test("Test_Array_Constructor");
		KT::Array<int, 3> DefaultConstructor;
		Test.testresult(DefaultConstructor[0], 0, "Test_Default value");
		KT::Array<int, 3>InitialiszeListConstructor{1,2,3};
		Test.testresult(InitialiszeListConstructor[0], 1, "Test_First value");
		KT::Array<int, 3>CopyConstructor = InitialiszeListConstructor;
		Test.testresult(CopyConstructor[2], InitialiszeListConstructor[2], "test_Copy value");
	}
	{
		Test_Units Test("Test_Operator");
		KT::Array<int, 3> array{ 1,2,3 };
		KT::Array<int, 3> ArrayCopy{ 5,5,5 };
		Test.testresult(array[2], 3,  "Test_Operator[]");
		Test.testresult(array.at(0), 1, "Test_at()");
		array = ArrayCopy;
		Test.testresult(array[0], ArrayCopy[0], "test_Operator =");
		array = { 1,2,3 };
		ArrayCopy.swap(array);
		Test.testresult(ArrayCopy[0], 1, "test swap");
		ArrayCopy[0] = 100;
		Test.testresult(ArrayCopy[0], 100, "test assignation");
	}
	{
		Test_Units Test("test_Array_Iterator");
		KT::Array<int, 3> IteratorTest{5, 1, 3};
		Test.testresult(*IteratorTest.begin(), 5, "Test_Iterator_begin");
		Test.testresult(*IteratorTest.begin(), *(IteratorTest.rend() - 1), "test_Iterator and reverse Iterator");
		KT::Array<int, 3>::reverse_iterator ri = IteratorTest.rbegin();
		++ri;
		Test.testresult(*ri, IteratorTest[1], "test_++Operator");
		KT::Array<int, 3>::iterator ni = IteratorTest.end();
		--ni;
		Test.testresult(*ni, IteratorTest[2], "test_--Operator");
	}
	{
		Test_Units Test("Test_Array_function");
		KT::Array<int, 3 > array;
		Test.testresult(array.front(), array[0], "test_front");
		Test.testresult(array.back(), array[2],"test_back");
		Test.testresult(array.Size(), 3, "test_size");
		Test.testresult(array.max_size(), 3, "test max_size");
		Test.testresult(*array.data(), 0, "test data");
	}
	{
		Test_Units Test(" Const Test_Array_Constructor");
		const KT::Array<int, 3> DefaultConstructor;
		Test.testresult(DefaultConstructor[0], 0, "Test_Default value");
		const KT::Array<int, 3>InitialiszeListConstructor{ 1,2,3 };
		Test.testresult(InitialiszeListConstructor[0], 1, "Test_First value");
		const KT::Array<int, 3>CopyConstructor = InitialiszeListConstructor;
		Test.testresult(CopyConstructor[2], InitialiszeListConstructor[2], "test_Copy value");
	}
	{
		Test_Units Test(" const Test_Operator");
		const KT::Array<int, 3> array{ 1,2,3 };
		const KT::Array<int, 3> ArrayCopy{ 5,5,5 };
		Test.testresult(array[2], 3, "Test_Operator[]");
		Test.testresult(array.at(0), 1, "Test_at()");
	}
	{
		Test_Units Test(" const test_Array_Iterator");
		const KT::Array<int, 3> IteratorTest{ 5, 1, 3 };
		Test.testresult(*IteratorTest.begin(), 5, "Test_Iterator_begin");
		Test.testresult(*IteratorTest.begin(), *(IteratorTest.rend() - 1), "test_Iterator and reverse Iterator");
		KT::Array<int, 3>::const_reverse_iterator ri = IteratorTest.rbegin();
		++ri;
		Test.testresult(*ri, IteratorTest[1], "test_++Operator");
		KT::Array<int, 3>::const_iterator ni = IteratorTest.end();
		--ni;
		Test.testresult(*ni, IteratorTest[2], "test_--Operator");
	}
	{
		Test_Units Test("const Test_Array_function");
		const KT::Array<int, 3 > array;
		Test.testresult(array.front(), array[0], "test_front");
		Test.testresult(array.back(), array[2], "test_back");
		Test.testresult(array.Size(), 3, "test_size");
		Test.testresult(array.max_size(), 3, "test max_size");
		Test.testresult(*array.data(), 0, "test data");
	}
	{
		Test_Units Test("Algorithme on Array");
		KT::Array<int, 3> array;
		KT::Math::Fill(array.begin(), array.end(), 5);
		Test.testresult(array[0], 5, "test KT::Fill");
		std::fill(array.begin(), array.end(), 10);
		Test.testresult(array[0], 10, "test std::fill");
		KT::Array<int, 3> arraycopy;
		KT::Math::Copy(array.begin(), array.end(), arraycopy.data());
		Test.testresult(arraycopy[0], 10, "test KT::copy");
		array = { 0,0,0 };
		std::copy(array.begin(), array.end(), arraycopy.data());
		Test.testresult(arraycopy[0], 0, "test std::copy");

	}
	return 0;
}
