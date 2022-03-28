#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" { // call functions 

	#include "Header.h"
}

// Step to set up your environment

	//	Step 1: Go to the
	//		- Configuration Properties > Linker > Input
	//		- Select Additional Dependencies
	//		- Use the dropdown arrow on the right to select Edit
	//		- Add new line
	//		- Copy this into that box correctly
	//			File.obj
	//			Main.obj
	//			UI.obj
	//			MathToGuess.obj
	//			WordToGuess.obj
	//		- Select Apply

	//	Step 2: Go to the
	//		- Configuration Properties > Linker > General
	//		- Select Additional Library Directories
	//		- Use the dropdown arrow on the right to select Edit
	//		- Add new line
	//		- Input to it the path to choose your Debug folder inside the Hangman - Teambasedsofdev Group7
	//		Example on my computer is: C:\Users\Minh\Desktop\Study\Semester II - 2022\ASSIGNMENT\Project - Github - Big\HangMan - Teambasedsoftdev Group7\Debug
	//		- Select Apply

	//	Step 3: Go to the
	//		- Configuration Properties > VC++
	//		- Select Include Directories
	//		- Use the dropdown arrow on the right to select Edit
	//		- Add new line
	//		- Input to it the path to store the Header.h file inside the HangMan - Teambasedsofdev Group7
	//			Example on my computer is: C:\Users\Minh\Desktop\Study\Semester II - 2022\ASSIGNMENT\Project - Github - Big\HangMan - Teambasedsoftdev Group
	//		- Select Apply


namespace HangmanTestCasesGroup7
{
	TEST_CLASS(HangmanTestCasesGroup7)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//	Arrange
			int a = 2;
			int b = 3;

			//	Act
			int result = a * b;

			//	Assert
			Assert::AreEqual(6, result);

		}
		TEST_METHOD(TestMethod2)
		{
			int a = 7;
			int b = 3;

			int result = a * b;

			Assert::AreEqual(21, result);

		}
	};

}
