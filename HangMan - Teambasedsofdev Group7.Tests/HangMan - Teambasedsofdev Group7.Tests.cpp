
#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
	#include "Header.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HangManTeambasedsofdevGroup7Tests
{
	TEST_CLASS(HangManTeambasedsofdevGroup7Tests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//Arrange
			int lang = 1;
			int result = 0;
			int result_FileDe = 0;
			int result_FileEn = 0;
			char *word;
			int result_1 = 0;
			int result_2 = 0;
			//Act
			result = menu(lang);
			result_FileEn = FileEncrypt(lang);
			result_FileDe = FileDecrypt(lang);
			word = FileGetWord(lang);
			result_1 = MathtoGuess(lang);
			result_2 = Dash(word,lang);

			//Assert
			Assert::AreEqual(1, result);
			Assert::AreEqual(1, result_FileEn);
			Assert::AreEqual(1, result_FileDe);
			Assert::AreEqual(word, FileGetWord(lang));
			Assert::AreEqual(1, result_1);
			Assert::AreEqual(1, result_2);

		}
	};
}


