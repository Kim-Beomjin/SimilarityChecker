#include <vector>
#include <string>
#include <set>
#include <stdexcept>

using namespace std;

class LengthChecker {
public:
	LengthChecker(void) = default;
	LengthChecker(string input1, string input2) {
		input.push_back(input1);
		input.push_back(input2);
	}

	int GetResult(void) {
		for (auto each : input) {
			if (each.length() == 0) throw length_error("At least one letter");
		}

		int maxLength = max(input[0].length(), input[1].length());
		int minLength = min(input[0].length(), input[1].length());

		if (maxLength == minLength) return 60;
		if (minLength * 2 <= maxLength) return 0;

		int diff = maxLength - minLength;
		return 60 - 60 * diff / minLength;
	}

	void AddInputStrings(vector<string>& input) {
		this->input = input;
	}

private:
	vector<string> input;
};

class AlphaChecker {
public:
	AlphaChecker(void) = default;
	AlphaChecker(string input1, string input2) {
		input.push_back(input1);
		input.push_back(input2);
	}

	int GetResult(void) {
		for (auto each : input) {
			if (each >= "A" && each <= "Z") continue;
			throw invalid_argument("Allow CAPITAL only");
		}

		set<char> set1(input[0].begin(), input[0].end());
		set<char> set2(input[1].begin(), input[1].end());

		if (set1 == set2) return 40;
	}

	void AddInputStrings(vector<string>& input) {
		this->input = input;
	}

private:
	vector<string> input;
};