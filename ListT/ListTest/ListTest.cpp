#include "pch.h"
#include "CppUnitTest.h"
#include "../List/List.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListTest
{
	TEST_CLASS(ListTest)
	{
	public:

		TEST_METHOD(PushBackInt_ValidData_Success)
		{
			List<int> A;
			A.PushBack(4);
			Assert::IsTrue(A.ToString() == "4");
		}
		TEST_METHOD(PopFrontString_ValidData_Success)
		{
			List<std::string> A{"a", "b"};
			A.PopFront();
			Assert::IsTrue(A.ToString() == "b");
		}
		TEST_METHOD(PushFrontString_ValidData_Success)
		{
			List<std::string> A{"a", "b"};
			std::string x = "x";
			A.PushFront(x);
			Assert::IsTrue(A.ToString() == "xab");
		}
		TEST_METHOD(ToString_ValidData_Success)
		{
			List<std::string> A{"a", "b", "c"};
			List<std::string> B{"a", "b", "c"};
			Assert::AreEqual(A.ToString(), B.ToString());
		}
		TEST_METHOD(AssignmentOperator_ValidData_Success)
		{
			List<std::string> E{"a", "b", "c"};
			List<std::string> B;
			E = B;
			Assert::IsTrue(B.ToString() == E.ToString());
		}
		TEST_METHOD(IsEmpty_ValidData_Success)
		{
			List<std::string> E;
			Assert::IsTrue(E.IsEmpty());
		}
		TEST_METHOD(IsEmptyString_InvalidData_Success)
		{
			List<std::string> FF;
			FF.PushBack("a");
			Assert::IsFalse(FF.IsEmpty());
		}
		TEST_METHOD(PushFrontInt_InvalidData_Success)
		{
			List<int> D;
			D.PushFront(5);
			Assert::IsFalse(D.ToString() == "2");
		}
		TEST_METHOD(ListInt_NegativeSize_ExpectedException)
		{
			List<int> A;
			Assert::ExpectException<std::invalid_argument>([&]() { A.PopFront(); });
		}
	};
}

