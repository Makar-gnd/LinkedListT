#include "pch.h"
#include "CppUnitTest.h"
#include "../List/List.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListTest
{
	TEST_CLASS(ListTest)
	{
	public:

		TEST_METHOD(PushBackTestInt)
		{
			List<int> A;
			A.PushBack(4);
			Assert::IsTrue(A.ToString() == "4");
		}
		TEST_METHOD(PopFrontTest)
		{
			List<std::string> A{"a", "b"};
			A.PopFront();
			Assert::IsTrue(A.ToString() == "b");
		}
		TEST_METHOD(PushFrontTestString)
		{
			List<std::string> A{"a", "b"};
			std::string x = "x";
			A.PushFront(x);
			Assert::IsTrue(A.ToString() == "xab");
		}
		TEST_METHOD(ToStringTest)
		{
			List<std::string> A{"a", "b", "c"};
			List<std::string> B{"a", "b", "c"};
			Assert::AreEqual(A.ToString(), B.ToString());
		}
		TEST_METHOD(AssignmentOperatorTest)
		{
			List<std::string> E{"a", "b", "c"};
			List<std::string> B;
			E = B;
			Assert::IsTrue(B.ToString() == E.ToString());
		}
		TEST_METHOD(IsEmptyTest)
		{
			List<std::string> E;
			Assert::IsTrue(E.IsEmpty());
		}
		TEST_METHOD(IsEmptyTest2)
		{
			List<std::string> FF;
			FF.PushBack("a");
			Assert::IsFalse(FF.IsEmpty());
		}
		TEST_METHOD(PushFrontTestInt)
		{
			List<int> D;
			D.PushFront(5);
			Assert::IsFalse(D.ToString() == "2");
		}
		TEST_METHOD(PopBackTestString)
		{
			List<std::string> D{"q","w","e","r","t","y"};
			D.PopBack();
			Assert::IsTrue(D.ToString() == "qwert");
		}
	};
}

