#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

float getGrade(string rate) {
	if (rate == "A+") return 4.5;
	else if (rate == "A0") return 4.0;
	else if (rate == "B+") return 3.5;
	else if (rate == "B0") return 3.0;
	else if (rate == "C+") return 2.5;
	else if (rate == "C0") return 2.0;
	else if (rate == "D+") return 1.5;
	else if (rate == "D0") return 1.0;
	else if (rate == "F") return 0.0;
	else return -1;
}

int main() {
	double sum = 0, credits = 0;
	for (int i = 0; i < 20; ++i) {
		string subject, credit, grade;
		cin >> subject >> credit >> grade;
		
		float creditConv = stof(credit);
		float gradeConv = getGrade(grade);

		if (gradeConv < 0) continue;

		sum += creditConv * gradeConv;
		credits += creditConv;
	}

	cout << sum / credits;

	return 0;
}