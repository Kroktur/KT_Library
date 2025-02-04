#include <iostream>
#include "KT_Array.h"
#include "KT_List.h"
#include "KT_Vector.h"
#include "KT_IntrusiveList.h"
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

	std::cout << "*Begin && *data = 1 : ";
	std::cout << *testArrayconst.begin() << "," << *testArrayconst.data() << std::endl;

	std::cout << "front && end = 1 et 5 :";
	std::cout << testArrayconst.front() << "," << testArrayconst.back() << std::endl;


	// test Vector
	
	//KT::Vector<int> testVector;

	//KT::Vector<int> testVector2{ 1,2,3,4,5 };

	//KT::Vector<int> testVector3(testVector2);

	//KT::Vector<int>testVector4{ 1,2,3 };

	//testVector = testVector3;

	//std::cout << "Size  && max size = 5 :";
	//std::cout << testVector.Size() << "," << testVector.max_size() << std::endl;

	//std::cout << "vector == 1,2,3,4,5 : ";
	//std::cout << testVector << std::endl;

	//std::cout << "vector2 == 1,2,3,4,5 : ";
	//std::cout << testVector2 << std::endl;

	//std::cout << "vector3 == 1,2,3,4,5 : ";
	//std::cout << testVector3 << std::endl;

	//std::cout << "vector4 == 1,2,3,0,0 : ";
	//std::cout << testVector4 << std::endl;

	//std::cout << "vector[0] == 1 :";
	//std::cout << testVector[0] << std::endl;

	//std::cout << "vector.at(0) == 1 :";
	//std::cout << testVector.at(0) << std::endl;

	//std::cout << "*Begin && *data = 1 : ";
	//std::cout << *testVector.begin() << "," << *testVector.data() << std::endl;

	//std::cout << "front && end = 1 et 5 :";
	//std::cout << testVector.front() << "," << testVector.back() << std::endl;

	//std::fill(testVector.begin(), testVector.end(), 5);
	//std::cout << "vector == 5,5,5,5,5 : ";
	//std::cout << testVector << std::endl;

	//std::fill(testVector.rbegin(), testVector.rend(), 10);
	//std::cout << "vector == 10,10,10,10,10 : ";
	//std::cout << testVector << std::endl;


	//testVector.swap(testVector2);
	//std::cout << "vector == 1,2,3,4,5 : ";
	//std::cout << testVector << std::endl;
	//testVector2 = { 1,2,3,4,5 };
	//testVector.pushBack(100);
	//std::cout << "vector == 1,2,3,4,5,100 && size = 6 : ";
	//std::cout << testVector << "," << testVector.Size() << std::endl;

	//testVector.popBack();
	//std::cout << "vector == 1,2,3,4,5 && size = 5 : ";
	//std::cout << testVector << "," << testVector.Size() << std::endl;

	//testVector.erase(testVector.begin());
	//std::cout << "vector == 2,3,4,5 : ";
	//std::cout << testVector << std::endl;

	//testVector.insert(testVector.begin(),100);
	//std::cout << "vector == 100,2,3,4,5 : ";
	//std::cout << testVector << std::endl;

	//testVector.assign({ 1,2,3 });
	//std::cout << "vector == 1,2,3 : ";
	//std::cout << testVector << std::endl;

	//testVector.assign(3,3);
	//std::cout << "vector == 3,3,3 : ";
	//std::cout << testVector << std::endl;

	//testVector.assign(testVector2.begin(), testVector2.end());
	//std::cout << "vector == 1,2,3,4,5 : ";
	//std::cout << testVector << std::endl;
	//// test const Vector
	//const KT::Vector<int> testVectorconst{ 1,2,3,4,5 };

	//const KT::Vector<int> testVector2const{ 1,2,3,4,5 };

	//const KT::Vector<int> testVector3const(testVector2const);

	//const KT::Vector<int>testVector4const{ 1,2,3 };

	////testArrayconst;

	//std::cout << "Size  && max size = 5 :";
	//std::cout << testVectorconst.Size() << "," << testVectorconst.max_size() << std::endl;

	//std::cout << "array == 1,2,3,4,5 : ";
	//std::cout << testVectorconst << std::endl;


	//std::cout << "array4 == 1,2,3,0,0 : ";
	//std::cout << testVector4const << std::endl;

	//std::cout << "array[0] == 1 :";
	//std::cout << testVectorconst[0] << std::endl;

	//std::cout << "array.at(0) == 1 :";
	//std::cout << testVectorconst.at(0) << std::endl;

	//std::cout << "*Begin && *data = 1 : ";
	//std::cout << *testVectorconst.begin() << "," << *testVectorconst.data() << std::endl;

	//std::cout << "front && end = 1 et 5 :";
	//std::cout << testVectorconst.front() << "," << testVectorconst.back() << std::endl;

	//test List
KT::List<int> testList{ 1,2,3,4,5 };

KT::List<int> testList2{ 1,2,3,4,5 };

KT::List<int> testList3(testList2);

KT::List<int>testList4{ 1,2,3 };

testList = testList2;

std::cout << "Size  && max size = 5 :";
std::cout << testList.Size() << "," << testList.max_size() << std::endl;

std::cout << "vector == 1,2,3,4,5 : ";
std::cout << testList << std::endl;

std::cout << "vector2 == 1,2,3,4,5 : ";
std::cout << testList2 << std::endl;

std::cout << "vector3 == 1,2,3,4,5 : ";
std::cout << testList3 << std::endl;

std::cout << "vector4 == 1,2,3,0,0 : ";
std::cout << testList4 << std::endl;

std::cout << "vector[0] == 1 :";
std::cout << testList[0] << std::endl;

std::cout << "vector.at(0) == 1 :";
std::cout << testList.at(0) << std::endl;

std::cout << "*Begin  1 : ";
std::cout << *testList.begin() << ","<<std::endl;

std::cout << "front && end = 1 et 5 :";
std::cout << testList.front() << "," << testList.back() << std::endl;

std::fill(testList.begin(), testList.end(), 5);
std::cout << "vector == 5,5,5,5,5 : ";
std::cout << testList << std::endl;

std::fill(testList.rbegin(), testList.rend(), 10);
std::cout << "vector == 10,10,10,10,10 : ";
std::cout << testList << std::endl;


testList.swap(testList2);
std::cout << "vector == 1,2,3,4,5 : ";
std::cout << testList << std::endl;
testList2 = { 1,2,3,4,5 };
testList.pushBack(100);
std::cout << "vector == 1,2,3,4,5,100 && size = 6 : ";
std::cout << testList << "," << testList.Size() << std::endl;

testList.popBack();
std::cout << "vector == 1,2,3,4,5 && size = 5 : ";
std::cout << testList << "," << testList.Size() << std::endl;

testList.erase(testList.begin());
std::cout << "vector == 2,3,4,5 : ";
std::cout << testList << std::endl;

testList.insert(testList.begin(), 100);
std::cout << "vector == 100,2,3,4,5 : ";
std::cout << testList << std::endl;

testList.assign({ 1,2,3 });
std::cout << "vector == 1,2,3 : ";
std::cout << testList << std::endl;

testList.assign(3, 3);
std::cout << "vector == 3,3,3 : ";
std::cout << testList << std::endl;

testList.assign(testList2.begin(), testList2.end());
std::cout << "vector == 1,2,3,4,5 : ";
std::cout << testList << std::endl;
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

}