#ifndef SOLUTION_HPP
#define SOLUTION_HPP
#include "CImg.h"
#include <iostream>
#include <string>
#define cimg_OS 2
#define pi 3.14159265
using namespace cimg_library;
using namespace std;
const unsigned char red[3]={255,0,0}, 
	green[3]={0,255,0}, 
	blue[3]={0,0,255},
	yellow[3] = {255, 255, 0};
class Solution {
	CImg<unsigned char> img;

public:
	Solution() {
		img.load_bmp("../Questions/1.bmp"); 
	}

	void question1() {
		img.display();
	}

	void question2() {
		cimg_forXY(img,i,j) {
		// check white
			if(img(i,j,0,0) == 255 && img(i,j,0,1) == 255 && img(i,j,0,2) == 255) {
				img(i,j,0,1) = 0;
				img(i,j,0,2) = 0;
			}
			// check black
			if(img(i,j,0,0) == 0 && img(i,j,0,1) == 0 && img(i,j,0,2) == 0) {
				img(i,j,0,1) = 255;
			}
		}

	}

	void question3Manual() {
		cimg_forXY(img,i,j) {
		// define the range of pixels in the circle
			if((i-50)*(i-50)+(j-50)*(j-50) <= 900) {
				img(i,j,0,0) = 0;
				img(i,j,0,1) = 0;
				img(i,j,0,2) = 255;
			}
		}
		//MPCircle(50,50,30);
	}

	void MPCircle(int x, int y, int r) {
		int xp = x, yp = y-r;
		while(xp-x <= y-yp) {
			if(delta(xp,yp,x,y,r)) {
				xp++;
			}
			else {
				xp++;
				yp++;
			}
			for(int i = y; i >= yp; i--) {
				img(xp,i,0,0) = 0;
				img(xp,i,0,1) = 0;
				img(xp,i,0,2) = 255;
			}
		}
		cimg_forXY(img,i,j) {
		// define the range of pixels in the circle
			if(img(i,j,0,0) == 0 && img(i,j,0,1) == 0 && img(i,j,0,2) == 255) {
				img(2*x-i,2*y-j,0,0) = 0;
				img(2*x-i,2*y-j,0,1) = 0;
				img(2*x-i,2*y-j,0,2) = 255;

				img(2*x-i,j,0,0) = 0;
				img(2*x-i,j,0,1) = 0;
				img(2*x-i,j,0,2) = 255;

				img(i,2*y-j,0,0) = 0;
				img(i,2*y-j,0,1) = 0;
				img(i,2*y-j,0,2) = 255;

				img(j+y-x,i+x-y,0,0) = 0;
				img(j+y-x,i+x-y,0,1) = 0;
				img(j+y-x,i+x-y,0,2) = 255;
			}
		}
	}

	bool delta(int xp, int yp, int x, int y, int r) {
		int result = (xp+1-x)*(xp+1-x)+(yp-0.5-y)*(yp-0.5-y)-r*r;
		return result <= 0;
	}

	void question3() {
		img.draw_circle(50,50,30,blue);
	}


	void question4Manual() {
		//MPCircle(50,50,3);
		cimg_forXY(img,i,j) {
			if((i-50)*(i-50)+(j-50)*(j-50) <= 9) {
				// change color to yellow
				img(i,j,0,0) = 255;
				img(i,j,0,1) = 255;
				img(i,j,0,2) = 0;
			}
		}
	}

	void question4() {
		MPCircle(50,50,3);
		img.draw_circle(50,50,3,yellow);
	}

	void question5Manual() {
		cimg_forXY(img,i,j) {
			if((double)j/i < tan(35.0/180.0*pi)+0.5/i
				&& (double)j/i > tan(35.0/180.0*pi)-0.5/i && i*i+j*j <= 10000) {
				img(i,j,0,0) = 0;
				img(i,j,0,1) = 0;
				img(i,j,0,2) = 255;
			}
		}
		img.save_bmp("Manual5.bmp");
	}
	void question5() {
		double x1=100*cos(35.0/180.0*pi);
		double y1=100*sin(35.0/180.0*pi);
		img.draw_line(0,0,x1,y1,blue);
		img.save_bmp("Library5.bmp");
	}

	void question6() {
		question2();
		question3();
		question4();
		question5();
		//save("2.bmp");
	}

	void save(string filename) {
		img.save_bmp(filename.c_str());
	}

	int getHeight() {
		return img.height();
	}

	int getWidth() {
		return img.width();
	}

	CImg<unsigned char> getImg() {
		return img;
	}

	int getColor(int i, int j, int z, int w) {
		return img(i,j,z,w);
	}
};
#endif
