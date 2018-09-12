#include "CImg.h"
#define cimg_OS 2
using namespace cimg_library;

class Solution {
	// attributes
	CImg<unsigned char> img;

	// methods
public:
	Solution() {
		CImg<unsigned char> img("../Questions/1.bmp");
		this.img = img;
	}

	CImg<unsigned char> displayImage() {
		img.Display();
	}

	CImg<unsigned char> white2redBlack2green() {

	}

	CImg<unsigned char> white2redBlack2green() {

	}
};