#include "pch.h"
#include "CppUnitTest.h"
#include "..\BinaryTree\BinaryTree.h"
#include "..\BinaryTree\BinaryTree.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryTreeTests
{
	TEST_CLASS(BinaryTreeTests)
	{
	public:
		BinaryTree tr=15;
		Iterator* TestIterator;
		
		//////INSERT//////
		
		TEST_METHOD(insert_first)
		{
			tr.insert(10);//15, 10
			TestIterator = tr.create_bft_iterator();
			Assert::AreEqual(TestIterator->next(), 15);
		}
		TEST_METHOD(insert_four)
		{
			tr.insert(10);
			tr.insert(2);
			tr.insert(20);
			tr.insert(23);
			tr.insert(30);
			tr.insert(9);
			tr.insert(12);
			TestIterator = tr.create_bft_iterator();
			Assert::AreEqual(TestIterator->next(), 15);
			Assert::AreEqual(TestIterator->next(), 10);
			Assert::AreEqual(TestIterator->next(), 20);
			Assert::AreEqual(TestIterator->next(), 2);
		}
		TEST_METHOD(insert_end)
		{
			tr.insert(10);
			tr.insert(2);
			tr.insert(20);
			tr.insert(23);
			tr.insert(30);
			TestIterator = tr.create_bft_iterator();
			Assert::AreEqual(TestIterator->next(), 15);
			Assert::AreEqual(TestIterator->next(), 10);
			Assert::AreEqual(TestIterator->next(), 20);
			Assert::AreEqual(TestIterator->next(), 2);
			Assert::AreEqual(TestIterator->next(), 23);
			Assert::AreEqual(TestIterator->next(), 30);
		}
		//////CONTAINS//////
		TEST_METHOD(contains_true)
		{
			tr.insert(10);
			tr.insert(2);// 15 10 2
			Assert::AreEqual(tr.contains(10), true);
		}
		TEST_METHOD(contains_false)
		{
			tr.insert(10);
			tr.insert(2);// 15 10 2
			Assert::AreEqual(tr.contains(1), false);
		}
		//////REMOVE//////
		TEST_METHOD(remove_error)
		{
			tr.insert(10);
			try
			{
				tr.remove(20);
			}
			catch (std::out_of_range error)
			{
				Assert::AreEqual("has next is false", error.what());
			}
		}
		TEST_METHOD(remove_first)
		{
			tr.insert(10);
			tr.insert(2);
			tr.insert(20);
			tr.insert(23);
			tr.insert(30);
			tr.remove(15);
			TestIterator = tr.create_bft_iterator();
			Assert::AreEqual(TestIterator->next(), 20);
			Assert::AreEqual(TestIterator->next(), 10);
			Assert::AreEqual(TestIterator->next(), 23);
			Assert::AreEqual(TestIterator->next(), 2);
			Assert::AreEqual(TestIterator->next(), 30);
		}
		TEST_METHOD(remove_end)
		{
			tr.insert(10);
			tr.insert(2);
			tr.insert(20);
			tr.insert(23);
			tr.insert(30);
			tr.remove(30);
			TestIterator = tr.create_bft_iterator();
			Assert::AreEqual(TestIterator->next(), 15);
			Assert::AreEqual(TestIterator->next(), 10);
			Assert::AreEqual(TestIterator->next(), 20);
			Assert::AreEqual(TestIterator->next(), 2);
			Assert::AreEqual(TestIterator->next(), 23);
		}
		TEST_METHOD(remove_mid)
		{
			tr.insert(10);
			tr.insert(2);
			tr.insert(20);
			tr.insert(23);
			tr.insert(30);
			tr.remove(20);
			TestIterator = tr.create_bft_iterator();
			Assert::AreEqual(TestIterator->next(), 15);
			Assert::AreEqual(TestIterator->next(), 10);
			Assert::AreEqual(TestIterator->next(), 23);
			Assert::AreEqual(TestIterator->next(), 2);
			Assert::AreEqual(TestIterator->next(), 30);
		}
	//////DFT//ITERATOR//////
		TEST_METHOD(dft_iterator)
		{
			tr.insert(10);
			tr.insert(2);
			tr.insert(20);
			tr.insert(23);
			tr.insert(30);
			TestIterator = tr.create_dft_iterator();
			Assert::AreEqual(TestIterator->next(), 15);
			Assert::AreEqual(TestIterator->next(), 10);
			Assert::AreEqual(TestIterator->next(), 2);
			Assert::AreEqual(TestIterator->next(), 20);
			Assert::AreEqual(TestIterator->next(), 23);
			Assert::AreEqual(TestIterator->next(), 30);
		}
		TEST_METHOD(dft_iterator_error)
		{
			tr.insert(10);
			TestIterator = tr.create_dft_iterator();
			try
			{
				TestIterator->next();
				TestIterator->next();
				TestIterator->next();
			}
			catch (std::out_of_range error)
			{
				Assert::AreEqual("has next is false", error.what());
			}
		}
		//////BFT//ITERATOR//////
		TEST_METHOD(bft_iterator)
		{
			tr.insert(10);
			tr.insert(2);
			tr.insert(20);
			tr.insert(23);
			tr.insert(30);
			TestIterator = tr.create_bft_iterator();
			Assert::AreEqual(TestIterator->next(), 15);
			Assert::AreEqual(TestIterator->next(), 10);
			Assert::AreEqual(TestIterator->next(), 20);
			Assert::AreEqual(TestIterator->next(), 2);
			Assert::AreEqual(TestIterator->next(), 23);
			Assert::AreEqual(TestIterator->next(), 30);
		}
		TEST_METHOD(bft_iterator_error)
		{
			tr.insert(10);
			TestIterator = tr.create_bft_iterator();
			try
			{
				TestIterator->next();
				TestIterator->next();
				TestIterator->next();
			}
			catch (std::out_of_range error)
			{
				Assert::AreEqual("has next is false", error.what());
			}
		}
	};
	
}
