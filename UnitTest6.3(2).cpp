#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest632
{
	TEST_CLASS(UnitTest632)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 10;
			int a[n] = { -1, 0, -4, 5, 6, 2, 10,7, 9, -10 };

			int SortedA[n] = { -10,-4, -1, 0, 2, 5, 6, 7, 9, 10 };

			QuickSort(a, 0, n - 1);

			for (int i = 0; i < n; i++)
				Assert::AreEqual(SortedA[i], a[i]);

			double b[n] = { -0.1, 0.3, -2.0, -0.002, 0, 0.9, 1.4, 1., 40.3, -100. };
			double SortedB[n] = { -100., -2, -0.1, -0.002, 0, 0.3, 0.9, 1., 1.4, 40.3 };

			QuickSort(b, 0, n - 1);

			for (int i = 0; i < n; i++)
				Assert::AreEqual(SortedB[i], b[i]);
		}
	};
}
