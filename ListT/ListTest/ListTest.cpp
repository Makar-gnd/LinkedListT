#include "pch.h"
#include "CppUnitTest.h"
#include "../List/List.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListTest
{
	TEST_CLASS(ListTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			List<int> A;
			A.PushBack(4);
			Assert::IsTrue(A.ToString() == "4");
		}
		TEST_METHOD(TestMethod2)
		{
			List<std::string> A{"a", "b"};
			A.PopFront();
			Assert::IsTrue(A.ToString() == "b");
		}
		TEST_METHOD(TestMethod3)
		{
			List<std::string> A{"a", "b"};
			std::string x = "x";
			A.PushFront(x);
			Assert::IsTrue(A.ToString() == "xab");
		}
		TEST_METHOD(TestMethod4)
		{
			List<std::string> A{"a", "b", "c"};
			A.PopBack();
			Assert::IsTrue(A.ToString() == "ab");
		}
		TEST_METHOD(TestMethod5)
		{
			List<std::string> A{"a", "b", "c"};
			List<std::string> B{"a", "b", "c"};
			Assert::AreEqual(A.ToString(), B.ToString());
		}
		TEST_METHOD(TestMethod6)
		{
			List<std::string> E{"a", "b", "c"};
			List<std::string> B;
			E = B;
			Assert::IsTrue(B.ToString() == E.ToString());
		}
		TEST_METHOD(TestMethod7)
		{
			List<std::string> E;
			Assert::IsTrue(E.IsEmpty());
		}
		TEST_METHOD(TestMethod8)
		{
			List<std::string> FF;
			FF.PushBack("a");
			Assert::IsFalse(FF.IsEmpty());
		}
		TEST_METHOD(TestMethod9)
		{
			List<int> D;
			D.PushFront(5);
			Assert::IsFalse(D.ToString() == "2");
		}
	};
}

