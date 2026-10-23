#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_1_rec/Lab_06_1_rec.cpp" // Перевірте назву вашої папки з проектом

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab61Rec
{
	TEST_CLASS(UnitTestLab61Rec)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int a[5] = { 4, -3, 10, 5, 6 };

			// Від'ємні або непарні елементи: -3 та 5 (всього 2 елементи, сума = 2)
			int count = Count(a, 5, 0);
			int sum = Sum(a, 5, 0);

			Assert::AreEqual(2, count);
			Assert::AreEqual(2, sum);

			ZeroElements(a, 5, 0);
			Assert::AreEqual(0, a[1]);
			Assert::AreEqual(0, a[3]);
		}
	};
}