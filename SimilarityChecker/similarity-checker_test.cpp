#include "gmock/gmock.h"
#include "similarity-checker.cpp"
#include <string>

using namespace std;
using namespace testing;

class LengthCheckFixture : public Test {
public:
	LengthChecker lengthChecker;

	void assertInvalidLength(string input1, string input2) {
		vector<string> input;
		input.push_back(input1);
		input.push_back(input2);
		lengthChecker.AddInputStrings(input);

		EXPECT_THROW(lengthChecker.GetResult(), length_error);
	}

	void checkLengthResult(int expected, string input1, string input2) {
		vector<string> input;
		input.push_back(input1);
		input.push_back(input2);
		lengthChecker.AddInputStrings(input);

		EXPECT_EQ(expected, lengthChecker.GetResult());
	}
};

class AlphaCheckFixture : public Test {
public:
	AlphaChecker alphaChecker;

	void assertInvalidArgument(string input1, string input2) {
		vector<string> input;
		input.push_back(input1);
		input.push_back(input2);
		alphaChecker.AddInputStrings(input);

		EXPECT_THROW(alphaChecker.GetResult(), invalid_argument);
	}

	void checkAlphaResult(int expected, string input1, string input2) {
		vector<string> input;
		input.push_back(input1);
		input.push_back(input2);
		alphaChecker.AddInputStrings(input);

		EXPECT_EQ(expected, alphaChecker.GetResult());
	}
};

TEST_F(LengthCheckFixture, ThrowExceptionInputBlank) {
	assertInvalidLength("", "");
	assertInvalidLength("", "A");
	assertInvalidLength("A", "");
}

TEST_F(LengthCheckFixture, SameLength) {
	checkLengthResult(60, "ABC", "DEF");
	checkLengthResult(60, "AAAAA", "BBBBB");
}

TEST_F(LengthCheckFixture, OverLength) {
	checkLengthResult(0, "A", "BC");
	checkLengthResult(0, "A", "BCD");
	checkLengthResult(0, "BC", "A");
	checkLengthResult(0, "BCD", "A");
}

TEST_F(LengthCheckFixture, NormalLength) {
	checkLengthResult(0, "A", "AB");
	checkLengthResult(30, "AAA", "BB");
	checkLengthResult(12, "AAAAAAAAAAAAAAAAAA", "BBBBBBBBBB");
}

TEST_F(AlphaCheckFixture, ThrowExceptionInvalidInput) {
	assertInvalidArgument("", "");
	assertInvalidArgument("", "A");
	assertInvalidArgument("A", "");
	assertInvalidArgument("123", "123");
	assertInvalidArgument("abc", "ABC");
}

TEST_F(AlphaCheckFixture, SameAlpha) {
	checkAlphaResult(40, "AAA", "AAA");
	checkAlphaResult(40, "ABC", "ABC");
	checkAlphaResult(40, "ABC", "BCA");
	checkAlphaResult(40, "ABC", "ABCBCACBA");
	checkAlphaResult(40, "ABC", "ABCAAAAAA");
}
