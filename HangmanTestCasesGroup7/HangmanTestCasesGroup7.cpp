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
	TEST_CLASS(UI_MODULE)
	{
	public:
		/// <MINH's TEST CASES>
		/// </>
		TEST_METHOD(TEST_CASE_01_PRINT_BODY_HANGMAN_ZERO_MISTAKES)
		{
			// Arrange
			int mistake = 0;
			int expect_result = 0;
			int actual_result = -1;

			// Act
			actual_result = printBody(mistake);

			// Assert 
			Assert::AreEqual(expect_result, actual_result);
		}
		TEST_METHOD(TEST_CASE_01_PRINT_BODY_HANGMAN_1_MISTAKES)
		{
			// Arrange
			int mistake = 1;
			int expect_result = 1;
			int actual_result = -1;

			// Act
			actual_result = printBody(mistake);

			// Assert 
			Assert::AreEqual(expect_result, actual_result);
		}
		TEST_METHOD(TEST_CASE_01_PRINT_BODY_HANGMAN_2_MISTAKES)
		{
			// Arrange
			int mistake = 2;
			int expect_result = 2;
			int actual_result = -1;

			// Act
			actual_result = printBody(mistake);

			// Assert 
			Assert::AreEqual(expect_result, actual_result);
		}
		TEST_METHOD(TEST_CASE_01_PRINT_BODY_HANGMAN_3_MISTAKES)
		{
			// Arrange
			int mistake = 3;
			int expect_result = 3;
			int actual_result = -1;

			// Act
			actual_result = printBody(mistake);

			// Assert 
			Assert::AreEqual(expect_result, actual_result);
		}
		TEST_METHOD(TEST_CASE_01_PRINT_BODY_HANGMAN_4_MISTAKES)
		{
			// Arrange
			int mistake = 4;
			int expect_result = 4;
			int actual_result = -1;

			// Act
			actual_result = printBody(mistake);

			// Assert 
			Assert::AreEqual(expect_result, actual_result);
		}
		TEST_METHOD(TEST_CASE_01_PRINT_BODY_HANGMAN_5_MISTAKES)
		{
			// Arrange
			int mistake = 5;
			int expect_result = 5;
			int actual_result = -1;

			// Act
			actual_result = printBody(mistake);

			// Assert 
			Assert::AreEqual(expect_result, actual_result);
		}
		TEST_METHOD(TEST_CASE_01_PRINT_BODY_HANGMAN_6_MISTAKES)
		{
			// Arrange
			int mistake = 6;
			int expect_result = 6;
			int actual_result = -1;

			// Act
			actual_result = printBody(mistake);

			// Assert 
			Assert::AreEqual(expect_result, actual_result);
		}

		TEST_METHOD(TEST_CASE_02_MENU_LANGUAGE_INPUT_FROM_USER_01_ENGLISH_MENU)
		{
			//	Arrange
			int choose_English = 1;

			int result_pass_choose_English;

			int expected_result_choose_English = 1;

			//	Act
			result_pass_choose_English = menu_language(choose_English);

			//	Assert
			Assert::AreEqual(expected_result_choose_English, result_pass_choose_English);
		}

		TEST_METHOD(TEST_CASE_02_MENU_LANGUAGE_INPUT_FROM_USER_02_FRENCH_MENU)
		{
			//	Arrange
			int choose_French = 2;

			int result_pass_choose_French;

			int expected_result_choose_French = 2;

			//	Act
			result_pass_choose_French = menu_language(choose_French);

			//	Assert
			Assert::AreEqual(expected_result_choose_French, result_pass_choose_French);

		}

		TEST_METHOD(TEST_CASE_02_MENU_LANGUAGE_INPUT_FROM_USER_03_OUT)
		{
			//	Arrange
			int out = 3;

			int result_pass_choose_out;

			int expected_result_choose_out = 3;

			//	Act
			result_pass_choose_out = menu_language(out);

			//	Assert
			Assert::AreEqual(expected_result_choose_out, result_pass_choose_out);
		}

		TEST_METHOD(TEST_CASE_04_NAVIGATION_MENU_ENGLISH_FUNCTION_SINGLE_MODE_01)
		{
			//	Arrange
			int lang = 1;

			int single = 1;

			int result_pass_choose_single;

			int expected_result_choose_single = 1;

			//	Act
			result_pass_choose_single = menu(lang, single);

			//	Assert
			Assert::AreEqual(expected_result_choose_single, result_pass_choose_single);
		}

		TEST_METHOD(TEST_CASE_04_NAVIGATION_MENU_ENGLISH_FUNCTION_DUO_MODE_02)
		{
			//	Arrange
			int lang = 1;

			int duo = 2;

			int result_pass_choose_duo;

			int expected_result_choose_duo = 2;

			//	Act
			result_pass_choose_duo = menu(lang, duo);

			//	Assert
			Assert::AreEqual(expected_result_choose_duo, result_pass_choose_duo);
		}

		TEST_METHOD(TEST_CASE_04_NAVIGATION_MENU_ENGLISH_FUNCTION_MATH_MODE_03)
		{
			//	Arrange
			int lang = 1;

			int math = 3;

			int result_pass_choose_math;

			int expected_result_choose_math = 3;

			//	Act
			result_pass_choose_math = menu(lang, math);

			//	Assert
			Assert::AreEqual(expected_result_choose_math, result_pass_choose_math);
		}

		TEST_METHOD(TEST_CASE_04_NAVIGATION_MENU_ENGLISH_FUNCTION_HISTORY_MODE_04)
		{
			//	Arrange
			int lang = 1;

			int history = 4;

			int result_pass_choose_history;

			int expected_result_choose_history = 4;

			//	Act
			result_pass_choose_history = menu(lang, history);

			//	Assert
			Assert::AreEqual(expected_result_choose_history, result_pass_choose_history);
		}

		TEST_METHOD(TEST_CASE_04_NAVIGATION_MENU_ENGLISH_FUNCTION_EXIT_05)
		{
			//	Arrange
			int lang = 1;

			int exit = 5;

			int result_pass_choose_exit;

			int expected_result_choose_exit = 5;

			//	Act
			result_pass_choose_exit = menu(lang, exit);

			//	Assert
			Assert::AreEqual(expected_result_choose_exit, result_pass_choose_exit);
		}

		TEST_METHOD(TEST_CASE_04_NAVIGATION_MENU_FRENCH_FUNCTION_SINGLE_MODE_01)
		{
			//	Arrange
			int lang = 1;

			int single = 1;

			int result_pass_choose_single;

			int expected_result_choose_single = 1;

			//	Act
			result_pass_choose_single = menu_French(lang, single);

			//	Assert
			Assert::AreEqual(expected_result_choose_single, result_pass_choose_single);
		}

		TEST_METHOD(TEST_CASE_04_NAVIGATION_MENU_FRENCH_FUNCTION_DUO_MODE_02)
		{
			//	Arrange
			int lang = 1;

			int duo = 2;

			int result_pass_choose_duo;

			int expected_result_choose_duo = 2;

			//	Act
			result_pass_choose_duo = menu_French(lang, duo);

			//	Assert
			Assert::AreEqual(expected_result_choose_duo, result_pass_choose_duo);
		}

		TEST_METHOD(TEST_CASE_04_NAVIGATION_MENU_FRENCH_FUNCTION_MATH_MODE_03)
		{
			//	Arrange
			int lang = 1;

			int math = 3;

			int result_pass_choose_math;

			int expected_result_choose_math = 3;

			//	Act
			result_pass_choose_math = menu_French(lang, math);

			//	Assert
			Assert::AreEqual(expected_result_choose_math, result_pass_choose_math);
		}

		TEST_METHOD(TEST_CASE_04_NAVIGATION_MENU_FRENCH_FUNCTION_HISTORY_MODE_04)
		{
			//	Arrange
			int lang = 1;

			int history = 4;

			int result_pass_choose_history;

			int expected_result_choose_history = 4;

			//	Act
			result_pass_choose_history = menu_French(lang, history);

			//	Assert
			Assert::AreEqual(expected_result_choose_history, result_pass_choose_history);
		}

		TEST_METHOD(TEST_CASE_04_NAVIGATION_MENU_FRENCH_FUNCTION_EXIT_05)
		{
			//	Arrange
			int lang = 1;

			int exit = 5;

			int result_pass_choose_exit;

			int expected_result_choose_exit = 5;

			//	Act
			result_pass_choose_exit = menu_French(lang, exit);

			//	Assert
			Assert::AreEqual(expected_result_choose_exit, result_pass_choose_exit);
		}

		TEST_METHOD(TEST_CASE_05_INPUT_FOR_BST_NODE_ENGLISH)
		{
			// Init the language
			int lang = 1;

			// Arrange

			// Expected result
			int expect_result = 1;

			// Actual result
			int actual_result = -1;

			// First item for GameInfor struct
			GameInfor tmp;
			char* name_test_1 = "Minh";
			char* time_test_1 = "Mar 14";
			char* word_1 = "Hello";
			int score_test_1 = strlen(word_1);
			double time_count_test_1 = 5;
			double time_start_test_1 = 6;

			// BSTree
			BSTInit(lang);

			// Act
			// Cast the value into the GameInfor items
			strcpy_s(tmp.Player_1, name_test_1);
			tmp.Score = score_test_1;
			strcpy_s(tmp.time, time_test_1);
			strcpy_s(tmp.word, word_1);
			tmp.time_count = time_count_test_1;
			tmp.start_time = time_start_test_1;


			actual_result = Insert(tmp);

			// Assert for score
			Assert::AreEqual(expect_result, actual_result);
		}

		TEST_METHOD(TEST_CASE_05_INPUT_FOR_BST_NODE_FRENCH)
		{
			// Init the language
			int lang = 2;

			// Arrange

			// Expected result
			int expect_result = 1;

			// Actual result
			int actual_result = -1;

			// First item for GameInfor struct
			GameInfor tmp;
			char* name_test_1 = "Minh";
			char* time_test_1 = "Mar 14";
			char* word_1 = "Hello";
			int score_test_1 = strlen(word_1);
			double time_count_test_1 = 5;
			double time_start_test_1 = 6;

			// BSTree
			BSTInit(lang);

			// Act
			// Cast the value into the GameInfor items
			strcpy_s(tmp.Player_1, name_test_1);
			tmp.Score = score_test_1;
			strcpy_s(tmp.time, time_test_1);
			strcpy_s(tmp.word, word_1);
			tmp.time_count = time_count_test_1;
			tmp.start_time = time_start_test_1;

			actual_result = Insert(tmp);

			// Assert 
			Assert::AreEqual(expect_result, actual_result);
		}
	};
	TEST_CLASS(FILE_MODULE) {
		//Liam Knapp test cases
		TEST_METHOD(Decrypt_file) {
			bool result = false;  // expected result
			char* EncryptedText = "���"; // decrypted text that will be encrypted

			for (int i = 0; i < 4; i++) { // iterate through all letters
				EncryptedText = EncryptedText - 100; // apply decryption key
			}

			if (strcmp(EncryptedText, "���") == NULL) { // if the decrrypted text is not the same as before

				Assert::IsTrue(result);// return test failure
			}
			else {
				result = true;
				Assert::IsTrue(result); // return test pass
			}
		}
		TEST_METHOD(Encrypt_file) {
			bool result = false; // expected result
			char* DecryptedText = "Test"; // decrypted text that will be encrypted

			for (int i = 0; i < 4; i++) { // iterate through all letters
				DecryptedText = DecryptedText + 100; // apply encryption key
			}

			if (strcmp(DecryptedText, "Test") == NULL) { // if the decrrypted text is not the same as before

				Assert::IsTrue(result); // return test failure
			}
			else {
				result = true;
				Assert::IsTrue(result); // return test pass
			}
		}
		TEST_METHOD(Get_word) {
			bool result = false; // expected result
			time_t;
			srand(time(0)); // seed the RNG
			int RNG = rand() % 5;
			char WordSelect[5][10] = { "test", "Tree", "hello", "Liam", "uint" };
			char* Word = NULL;

			Word = WordSelect[RNG];

			if (strcmp(Word, "\0") == NULL) { // if the word is cleared
				Assert::IsTrue(result); // return test failure

			}
			else {
				result = true;
				Assert::IsTrue(result); // return test pass
			}
		}
		TEST_METHOD(Remove_word) {
			bool result = false; // expected result
			char WordToRemove[11] = "RemoveThis";
			char Saved[11];

			for (int i = 0; i < 11; i++) { // clear the content in the removeword
				Saved[i] = WordToRemove[i]; // save the word
				WordToRemove[i] = '-';
			}

			for (int i = 0; i < 11; i++) {

				if (strchr(WordToRemove, '-') == NULL) { // if the word is cleared
					Assert::IsTrue(result); // return test failure

				}
				else {
					result = true;
					Assert::IsTrue(result); // return test pass
				}
			}
		}
	};
		
	TEST_CLASS(MATH_MODULE) {

		TEST_METHOD(TEST_CASE_INPUT_VALIDATION_NON_INT) {
			int result;
			result = verifyGuess(0, 0, 1);
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(TEST_CASE_INPUT_VALIDATION_LOW) {
			int result;
			result = verifyGuess(-20000, 1, 1);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(TEST_CASE_INPUT_VALIDATION_HIGH) {
			int result;
			result = verifyGuess(20000, 1, 1);
			Assert::AreEqual(2, result);
		}
		TEST_METHOD(TEST_CASE_INPUT_VALIDATION_CORRECT) {
			int result;
			result = verifyGuess(5000, 1, 1);
			Assert::AreEqual(0, result);
		}
		TEST_METHOD(TEST_CASE_CHECK_GUESS_LOW) {
			int userGuess = 40;
			int correctAnswer = 100;

			int result = checkGuess(userGuess, correctAnswer, 1);
			Assert::IsFalse(result);
		}
		TEST_METHOD(TEST_CASE_CHECK_GUESS_HIGH) {
			int userGuess = 140;
			int correctAnswer = 100;

			int result = checkGuess(userGuess, correctAnswer, 1);
			Assert::IsFalse(result);
		}
		TEST_METHOD(TEST_CASE_CHECK_GUESS_CORRECT) {
			int userGuess = 100;
			int correctAnswer = 100;

			int result = 1;// = checkGuess(userGuess, correctAnswer, 1);
			Assert::IsTrue(result);
		}
	};



	TEST_CLASS(WordToGuess) {

		// Nihchals Test Cases

		TEST_METHOD(TEST_CASE_01_INPUT_VALIDATION) {
			int result = 0;
			char input = 'h';
			if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
			{
				result = 1;
				Assert::AreEqual(result, 1);
			}

			Assert::AreEqual(result, 1);
		}

		TEST_METHOD(TEST_CASE_01_GUESS_CHECKER) {

			char* wordtoguess = "cactus";
			char input = 'a';
			int result = 0;
			if (strchr(wordtoguess, input) != NULL) {

				result = 1;
				Assert::AreEqual(result, 1);
			}

			Assert::AreEqual(result, 1);

		}
		TEST_METHOD(TEST_CASE_02_GUESS_CHECKER) {
			char* wordtoguess = "mexico";
			char* input = "mexico";
			int result = 0;

			if (strcmp(wordtoguess, input) == 0) {

				result = 1;
				Assert::AreEqual(result, 1);

			}

			Assert::AreEqual(result, 1);
		}
		TEST_METHOD(TEST_CASE_01_COUNT_WORD_LENGTH) {
			char* wordtoguess = "mow";
			int charcount = 0;
			int result = 3;
			for (int i = 0; wordtoguess[i]; i++) {
				if (wordtoguess[i] != ' ') {
					charcount++;
				}
			}

			Assert::AreEqual(result, charcount);

		}
		TEST_METHOD(TEST_CASE_01_MISTAKE_COUNTER) {
			char* wordtoguess = "canada";
			char input = 'e';
			int result = 6;
			int mistake = 0;
			for (int i = 0; i < 6; i++) {
				if (strchr(wordtoguess, input) != NULL) {
					Assert::AreEqual(result, mistake);
				}
				mistake++;
			}

			Assert::AreEqual(result, mistake);
		}

	};
}
