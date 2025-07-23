#include "gmock/gmock.h"
#include "similarity-checker.cpp"
#include <string>

using namespace std;
using namespace testing;

class SimilarCheckFixture : public Test {
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

TEST_F(SimilarCheckFixture, ThrowExceptionInputBlank) {
	assertInvalidLength("", "");
	assertInvalidLength("", "A");
	assertInvalidLength("A", "");
}

TEST_F(SimilarCheckFixture, SameLength) {
	checkLengthResult(60, "ABC", "DEF");
	checkLengthResult(60, "AAAAA", "BBBBB");
}

TEST_F(SimilarCheckFixture, OverLength) {
	checkLengthResult(0, "A", "BC");
	checkLengthResult(0, "A", "BCD");
	checkLengthResult(0, "BC", "A");
	checkLengthResult(0, "BCD", "A");
}

TEST_F(SimilarCheckFixture, NormalLength) {
	checkLengthResult(0, "A", "AB");
	checkLengthResult(30, "AAA", "BB");
	checkLengthResult(12, "AAAAAAAAAAAAAAAAAA", "BBBBBBBBBB");
}
