#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class SimilarChecker {
public:
	SimilarChecker(string input1, string input2) {
		input.push_back(input1);
		input.push_back(input2);
	}

	void GetResult(void) {
		for (auto each : input) {
			if (each.length() == 0) throw length_error("At least one letter");
		}
	}

private:
	vector<string> input;
};