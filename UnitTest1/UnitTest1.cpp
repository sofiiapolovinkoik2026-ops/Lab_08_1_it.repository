#include "pch.h"
#include "CppUnitTest.h"

#define main main_app
#include "../Lab_08_1it/Lab_08_1it.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestIterative)
        {
            char s1[50] = "Hello!!! World!!!!";
            Assert::IsTrue(HasTripleExclamation(s1));

            char* res = ReplaceTripleExclamation(s1);
            Assert::AreEqual("Hello** World**!", s1);
            Assert::AreEqual("Hello** World**!", res);
            delete[] res;

            char s2[50] = "Hello!! World!";
            Assert::IsFalse(HasTripleExclamation(s2));
        }
    };
}