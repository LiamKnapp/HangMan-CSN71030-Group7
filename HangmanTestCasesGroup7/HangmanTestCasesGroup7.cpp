#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" { // call functions 

	// Liams Functions
	int FileEncrypt(int);
	int FileDecrypt(int);
	char* FileGetWord(int);
	int FileRemoveWord(char[], int);
	int FileReuseWords(int);

	
}

namespace HangmanTestCasesGroup7
{
	TEST_CLASS(HangmanTestCasesGroup7)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}
	};
}
