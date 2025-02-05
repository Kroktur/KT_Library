#include <iostream>
#include "KT_Array.h"
#include "KT_List.h"
#include "KT_Vector.h"
#include "KT_IntrusiveList.h"
#include "KT_Algorithm.h"
#include "KT_BubbleSort.h"
#include <algorithm>
int main()
{
	//// Test Array
	KT::Array<int , 5> testArray;

	KT::Array<int, 5> testArray2{ 1,2,3,4,5 };

	KT::Array<int, 5> testArray3(testArray2);

	KT::Array<int, 5 >testArray4{ 1,2,3 };

	testArray = testArray3;

	std::cout << "Size  && max size = 5 :" ;
	std::cout << testArray.Size() << "," << testArray.max_size() << std::endl;

	std::cout << "array == 1,2,3,4,5 : ";
	std::cout << testArray << std::endl;

	std::cout << "array2 == 1,2,3,4,5 : ";
	std::cout << testArray2 << std::endl;

	std::cout << "array3 == 1,2,3,4,5 : ";
	std::cout << testArray3 << std::endl;

	std::cout << "array4 == 1,2,3,0,0 : ";
	std::cout << testArray4 << std::endl;

	std::cout << "array[0] == 1 :";
	std::cout << testArray[0] << std::endl;

	std::cout << "array.at(0) == 1 :";
	std::cout << testArray.at(0) << std::endl;

	std::cout << "*Begin && *data = 1 : ";
	std::cout << *testArray.begin() << "," << *testArray.data() << std::endl;

	std::cout << "front && end = 1 et 5 :";
	std::cout << testArray.front() << "," << testArray.back() << std::endl;

	std::fill(testArray.begin(), testArray.end(), 5);
	std::cout << "array == 5,5,5,5,5 : ";
	std::cout << testArray << std::endl;

	std::fill(testArray.rbegin(), testArray.rend(), 10);
	std::cout << "array == 10,10,10,10,10 : ";
	std::cout << testArray << std::endl;

	testArray.swap(testArray2);
	std::cout << "array == 1,2,3,4,5 : ";
	std::cout << testArray << std::endl;

	// test const Array
	const KT::Array<int, 5> testArrayconst{ 1,2,3,4,5 };

	const KT::Array<int, 5> testArray2const{ 1,2,3,4,5 };

	const KT::Array<int, 5> testArray3const(testArray2const);

	const KT::Array<int, 5 >testArray4const{ 1,2,3 };

	

	std::cout << "Size  && max size = 5 :";
	std::cout << testArrayconst.Size() << "," << testArrayconst.max_size() << std::endl;

	std::cout << "array == 1,2,3,4,5 : ";
	std::cout << testArrayconst << std::endl;


	std::cout << "array4 == 1,2,3,0,0 : ";
	std::cout << testArray4const << std::endl;

	std::cout << "array[0] == 1 :";
	std::cout << testArrayconst[0] << std::endl;

	std::cout << "array.at(0) == 1 :";
	std::cout << testArrayconst.at(0) << std::endl;

	std::cout << "*Begin && *data && rbegin = 1,1,5 : ";
	std::cout << *testArrayconst.begin() << "," << *testArrayconst.data() << "," << *testArrayconst.rbegin() << std::endl;

	std::cout << "front && end = 1 et 5 :";
	std::cout << testArrayconst.front() << "," << testArrayconst.back() << std::endl;


	// test Vector
	
	KT::Vector<int> testVector;

	KT::Vector<int> testVector2{ 1,2,3,4,5 };

	KT::Vector<int> testVector3(testVector2);

	KT::Vector<int>testVector4{ 1,2,3 };

	testVector = testVector3;

	std::cout << "Size  && max size = 5 :";
	std::cout << testVector.Size() << "," << testVector.max_size() << std::endl;

	std::cout << "vector == 1,2,3,4,5 : ";
	std::cout << testVector << std::endl;

	std::cout << "vector2 == 1,2,3,4,5 : ";
	std::cout << testVector2 << std::endl;

	std::cout << "vector3 == 1,2,3,4,5 : ";
	std::cout << testVector3 << std::endl;

	std::cout << "vector4 == 1,2,3,0,0 : ";
	std::cout << testVector4 << std::endl;

	std::cout << "vector[0] == 1 :";
	std::cout << testVector[0] << std::endl;

	std::cout << "vector.at(0) == 1 :";
	std::cout << testVector.at(0) << std::endl;

	std::cout << "*Begin && *data && rbegin = 1,1,5 : ";
	std::cout << *testVector.begin() << "," << *testVector.data() <<"," <<*testVector.rbegin() << std::endl;

	std::cout << "front && end = 1 et 5 :";
	std::cout << testVector.front() << "," << testVector.back() << std::endl;

	std::fill(testVector.begin(), testVector.end(), 5);
	std::cout << "vector == 5,5,5,5,5 : ";
	std::cout << testVector << std::endl;

	std::fill(testVector.rbegin(), testVector.rend(), 10);
	std::cout << "vector == 10,10,10,10,10 : ";
	std::cout << testVector << std::endl;


	testVector.swap(testVector2);
	std::cout << "vector == 1,2,3,4,5 : ";
	std::cout << testVector << std::endl;
	testVector2 = { 1,2,3,4,5 };
	testVector.pushBack(100);
	std::cout << "vector == 1,2,3,4,5,100 && size = 6 : ";
	std::cout << testVector << "," << testVector.Size() << std::endl;

	testVector.popBack();
	std::cout << "vector == 1,2,3,4,5 && size = 5 : ";
	std::cout << testVector << "," << testVector.Size() << std::endl;

	testVector.erase(testVector.begin());
	std::cout << "vector == 2,3,4,5 : ";
	std::cout << testVector << std::endl;

	testVector.insert(testVector.begin(),100);
	std::cout << "vector == 100,2,3,4,5 : ";
	std::cout << testVector << std::endl;

	testVector.assign({ 1,2,3 });
	std::cout << "vector == 1,2,3 : ";
	std::cout << testVector << std::endl;

	testVector.assign(3,3);
	std::cout << "vector == 3,3,3 : ";
	std::cout << testVector << std::endl;

	testVector.assign(testVector2.begin(), testVector2.end());
	std::cout << "vector == 1,2,3,4,5 : ";
	std::cout << testVector << std::endl;
	// test const Vector
	const KT::Vector<int> testVectorconst{ 1,2,3,4,5 };

	const KT::Vector<int> testVector2const{ 1,2,3,4,5 };

	const KT::Vector<int> testVector3const(testVector2const);

	const KT::Vector<int>testVector4const{ 1,2,3 };

	//testArrayconst;

	std::cout << "Size  && max size = 5 :";
	std::cout << testVectorconst.Size() << "," << testVectorconst.max_size() << std::endl;

	std::cout << "array == 1,2,3,4,5 : ";
	std::cout << testVectorconst << std::endl;


	std::cout << "array4 == 1,2,3,0,0 : ";
	std::cout << testVector4const << std::endl;

	std::cout << "array[0] == 1 :";
	std::cout << testVectorconst[0] << std::endl;

	std::cout << "array.at(0) == 1 :";
	std::cout << testVectorconst.at(0) << std::endl;

	std::cout << "*Begin && *data = 1 : ";
	std::cout << *testVectorconst.begin() << "," << *testVectorconst.data() << std::endl;

	std::cout << "front && end = 1 et 5 :";
	std::cout << testVectorconst.front() << "," << testVectorconst.back() << std::endl;

	//test List
KT::List<int> testList{ 1,2,3,4,5 };

KT::List<int> testList2{ 1,2,3,4,5 };

KT::List<int> testList3(testList2);

KT::List<int>testList4{ 1,2,3 };

testList = testList2;

std::cout << "Size  && max size = 5 :";
std::cout << testList.Size() << "," << testList.max_size() << std::endl;

std::cout << "List == 1,2,3,4,5 : ";
std::cout << testList << std::endl;

std::cout << "List2 == 1,2,3,4,5 : ";
std::cout << testList2 << std::endl;

std::cout << "List3 == 1,2,3,4,5 : ";
std::cout << testList3 << std::endl;

std::cout << "List4 == 1,2,3,0,0 : ";
std::cout << testList4 << std::endl;

std::cout << "List[0] == 1 :";
std::cout << testList[0] << std::endl;

std::cout << "List.at(0) == 1 :";
std::cout << testList.at(0) << std::endl;

std::cout << "*Begin && rbegin  1 , 5 : ";
std::cout << *testList.begin() << "," << *testList.rbegin()<<std::endl;

std::cout << "front && end = 1 et 5 :";
std::cout << testList.front() << "," << testList.back() << std::endl;

std::fill(testList.begin(), testList.end(), 5);
std::cout << "List == 5,5,5,5,5 : ";
std::cout << testList << std::endl;

std::fill(testList.rbegin(), testList.rend(), 10);
std::cout << "List == 10,10,10,10,10 : ";
std::cout << testList << std::endl;


testList.swap(testList2);
std::cout << "List == 1,2,3,4,5 : ";
std::cout << testList << std::endl;
testList2 = { 1,2,3,4,5 };
testList.pushBack(100);
std::cout << "List == 1,2,3,4,5,100 && size = 6 : ";
std::cout << testList << "," << testList.Size() << std::endl;

testList.popBack();
std::cout << "List == 1,2,3,4,5 && size = 5 : ";
std::cout << testList << "," << testList.Size() << std::endl;

testList.erase(testList.begin());
std::cout << "List == 2,3,4,5 : ";
std::cout << testList << std::endl;

testList.insert(testList.begin(), 100);
std::cout << "vector == 100,2,3,4,5 : ";
std::cout << testList << std::endl;

testList.assign({ 1,2,3 });
std::cout << "List == 1,2,3 : ";
std::cout << testList << std::endl;

testList.assign(3, 3);
std::cout << "List == 3,3,3 : ";
std::cout << testList << std::endl;

testList.assign(testList2.begin(), testList2.end());
std::cout << "List == 1,2,3,4,5 : ";
std::cout << testList << std::endl;
// test const List
const KT::List<int> testListconst{ 1,2,3,4,5 };

const KT::List<int> testList2const{ 1,2,3,4,5 };

const KT::List<int> testList3const(testList2const);

const KT::List<int>testList4const{ 1,2,3 };


std::cout << "Size  && max size = 5 :";
std::cout << testListconst.Size() << "," << testListconst.max_size() << std::endl;

std::cout << "List == 1,2,3,4,5 : ";
std::cout << testListconst << std::endl;


std::cout << "List == 1,2,3,0,0 : ";
std::cout << testList4const << std::endl;

std::cout << "List[0] == 1 :";
std::cout << testListconst[0] << std::endl;

std::cout << "List.at(0) == 1 :";
std::cout << testListconst.at(0) << std::endl;

std::cout << "*Begin = 1 rbegin = 5 : ";
std::cout << *testListconst.begin() << ","  << *testListconst.rbegin()<<std::endl;

std::cout << "front && end = 1 et 5 :";
std::cout << testListconst.front() << "," << testListconst.back() << std::endl;

// test Intrusive List

KT::IntrusiveList<KT::Node<int>> testIntrusiveList{ KT::Node<int>(1), KT::Node<int>(2), KT::Node<int>(3), KT::Node<int>(4), KT::Node<int>(5)};

KT::IntrusiveList<KT::Node<int>> testIntrusiveList2{ KT::Node<int>(1), KT::Node<int>(2), KT::Node<int>(3), KT::Node<int>(4), KT::Node<int>(5) };

KT::IntrusiveList<KT::Node<int>> testIntrusiveList3(testIntrusiveList2);

KT::IntrusiveList<KT::Node<int>>testIntrusiveList4{ KT::Node<int>(1), KT::Node<int>(2), KT::Node<int>(3)};

testIntrusiveList = testIntrusiveList2;

std::cout << "Size  && max size = 5 :";
std::cout << testIntrusiveList.Size() << "," << std::endl;

std::cout << "IntrusiveList == 1,2,3,4,5 : ";
std::cout << testIntrusiveList << std::endl;

std::cout << "IntrusiveList2 == 1,2,3,4,5 : ";
std::cout << testIntrusiveList2 << std::endl;

std::cout << "IntrusiveList3 == 1,2,3,4,5 : ";
std::cout << testIntrusiveList3 << std::endl;

std::cout << "IntrusiveList4 == 1,2,3,0,0 : ";
std::cout << testIntrusiveList4 << std::endl;

std::cout << "IntrusiveList[0] == 1 :";
std::cout << testIntrusiveList[0] << std::endl;

std::cout << "IntrusiveList.at(0) == 1 :";
std::cout << testIntrusiveList.at(0) << std::endl;

std::cout << "*Begin && rbegin  1 , 5 : ";
std::cout << *testIntrusiveList.begin() << "," << *testIntrusiveList.rbegin() << std::endl;

std::cout << "front && end = 1 et 5 :";
std::cout << testIntrusiveList.front() << "," << testIntrusiveList.back() << std::endl;
//
//std::fill(testIntrusiveList.begin(), testIntrusiveList.end(), KT::Node<int>(5) );
//std::cout << "IntrusiveList == 5,5,5,5,5 : ";
//std::cout << testIntrusiveList << std::endl;

//std::fill(testIntrusiveList.rbegin(), testIntrusiveList.rend(), 10);
//std::cout << "IntrusiveList == 10,10,10,10,10 : ";
//std::cout << testIntrusiveList << std::endl;


testIntrusiveList.swap(testIntrusiveList2);
std::cout << "IntrusiveList == 1,2,3,4,5 : ";
std::cout << testIntrusiveList << std::endl;
testIntrusiveList2 = { KT::Node<int>(1), KT::Node<int>(2), KT::Node<int>(3), KT::Node<int>(4), KT::Node<int>(5) };
testIntrusiveList.pushBack(KT::Node<int>(100));
std::cout << "IntrusiveList == 1,2,3,4,5,100 && size = 6 : ";
std::cout << testIntrusiveList << "," << testIntrusiveList.Size() << std::endl;

testIntrusiveList.popBack();
std::cout << "v == 1,2,3,4,5 && size = 5 : ";
std::cout << testIntrusiveList << "," << testIntrusiveList.Size() << std::endl;

testIntrusiveList.erase(testIntrusiveList.begin());
std::cout << "IntrusiveList == 2,3,4,5 : ";
std::cout << testIntrusiveList << std::endl;

testIntrusiveList.insert(testIntrusiveList.begin(), KT::Node<int>(100));
std::cout << "IntrusiveList == 100,2,3,4,5 : ";
std::cout << testIntrusiveList << std::endl;

testIntrusiveList.assign({ KT::Node<int>(1), KT::Node<int>(2), KT::Node<int>(3) });
std::cout << "IntrusiveList == 1,2,3 : ";
std::cout << testIntrusiveList << std::endl;

testIntrusiveList.assign({ KT::Node<int>(3), KT::Node<int>(3) });
std::cout << "IntrusiveList == 3,3,3 : ";
std::cout << testIntrusiveList << std::endl;

testIntrusiveList.assign(testIntrusiveList2.begin(), testIntrusiveList2.end());
std::cout << "IntrusiveList == 1,2,3,4,5 : ";
std::cout << testIntrusiveList << std::endl;

const KT::IntrusiveList<const KT::Node<int>> testIntrusiveListcont{ KT::Node<int>(1), KT::Node<int>(2), KT::Node<int>(3), KT::Node<int>(4), KT::Node<int>(5) };

const KT::IntrusiveList<const KT::Node<int>> testIntrusiveList2cont{ KT::Node<int>(1), KT::Node<int>(2), KT::Node<int>(3), KT::Node<int>(4), KT::Node<int>(5) };

const KT::IntrusiveList<const KT::Node<int>> testIntrusiveList3cont(testIntrusiveList2cont);

const KT::IntrusiveList<const KT::Node<int>>testIntrusiveList4cont{ KT::Node<int>(1), KT::Node<int>(2), KT::Node<int>(3) };


std::cout << "Size  && max size = 5 :";
std::cout << testIntrusiveListcont.Size() << "," << std::endl;

std::cout << "List == 1,2,3,4,5 : ";
std::cout << testIntrusiveListcont << std::endl;


std::cout << "IntrusiveList == 1,2,3,0,0 : ";
std::cout << testIntrusiveList4cont << std::endl;

std::cout << "IntrusiveList[0] == 1 :";
std::cout << testIntrusiveListcont[0] << std::endl;

std::cout << "IntrusiveList.at(0) == 1 :";
std::cout << testIntrusiveListcont.at(0).data << std::endl;

std::cout << "*Begin = 1 rbegin = 5 : ";
std::cout << *testIntrusiveListcont.begin() << "," << *testIntrusiveListcont.rbegin() << std::endl;

std::cout << "front && end = 1 et 5 :";
std::cout << testIntrusiveListcont.front().data << "," << testIntrusiveListcont.back().data << std::endl;

KT::Array<int, 5> testArraysort{ 5,4,3,2,1 };
KT::Sort<KT::Array<int, 5>, KT::FusionSort>(testArraysort);
std::cout << testArraysort;

KT::Vector<int> testVectorsort{ 5,4,3,2,1 };
KT::Sort<KT::Vector<int>, KT::FusionSort>(testVectorsort);
std::cout << testVectorsort;


KT::List<int> testListsort{ 5,4,3,2,1 };
KT::Sort<KT::List<int>, KT::FusionSort>(testListsort);
std::cout << testListsort;


}