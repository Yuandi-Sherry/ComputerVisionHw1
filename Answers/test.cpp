#include "Solution.hpp"
#include "CImg.h"
using namespace cimg_library;
#include <iostream>
//using namespace std;
void testInfo(int heightBegin, int widthBegin, int heightEnd, int widthEnd, Solution orginalImg, Solution testImg);
int main(int argc, char **argv) {
	
	// test1
	Solution answer1_1;
	answer1_1.question3();
	Solution answer1_2;
	answer1_2.question3Manual();
	cout << "Test1: To figure out the number of different pixels \nafter calling CImg function and drawing the circle manually \nin Step3." << endl;
	int heightBegin = 19, widthBegin = 19, heightEnd = 81, widthEnd = 81;
	testInfo(heightBegin, heightBegin, heightEnd, heightEnd, answer1_1,answer1_2);
	
	// test2
	Solution answer2_1;
	answer2_1.question4();
	Solution answer2_2;
	answer2_2.question4Manual();
	cout << "Test2: To figure out the number of different pixels \nafter calling CImg function and drawing the circle manually \nin Step4." << endl;
	testInfo(46, 46, 54, 54, answer2_1,answer2_2);


	// test3
	Solution answer3_1;
	answer3_1.question5();
	Solution answer3_2;
	answer3_2.question5Manual();
	cout << "Test3: To figure out the number of different pixels \nafter calling CImg function and drawing the line manually \nin Step5." << endl;
	testInfo(0, 0, 100, 100, answer3_1,answer3_2);

	return 0;
}

void testInfo(int heightBegin, int widthBegin, int heightEnd, int widthEnd, Solution orginalImg, Solution testImg) {
	int count = 0;
	for(int i = heightBegin; i < heightEnd; i++) {
		for(int j = widthBegin; j < widthEnd; j++) {
			//cout << w++ << endl;
			if(orginalImg.getColor(i,j,0,0) != testImg.getColor(i,j,0,0)
			|| orginalImg.getColor(i,j,0,1) != testImg.getColor(i,j,0,1)
			|| orginalImg.getColor(i,j,0,2) != testImg.getColor(i,j,0,2)) {
				count++;
			}
		}
	}
	cout << "The answer is " << count << endl;
}
