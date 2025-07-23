#include <vector>
#include <string>
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