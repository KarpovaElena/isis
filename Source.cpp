#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <stdio.h>
#include <ctime>
using namespace cv;
using namespace std;

string F_NAME = "C:/Users/Bear-/OneDrive/Документы/Институут 2019-2020/sobelvideo/Snowfall - 29314.mp4"; 


int main() {
	cv::Mat r;
	cv::VideoCapture a(F_NAME);
	if (!a.isOpened()) {
		cout<<"OSHIBKA, BLIN(("<< endl;
		return -1;
	}
	auto fps = a.get(CV_CAP_PROP_FPS);

	cout<<"FPS= "<< fps<<endl;

	auto delay = 1000 / fps; //задержка
	while (1) {
		auto cb = clock();
		a >> r;//считаем фрейм
		resize(r, r, r.size() / 2); 
		if (r.channels() != 1) cvtColor(r, r, CV_RGB2GRAY);
		Mat xe, ye;
		Sobel(r, xe, CV_16S, 1, 0); //собель по Х
		Sobel(r, ye, CV_16S, 0, 1);//собель по У
		convertScaleAbs(xe, xe);
		convertScaleAbs(ye, ye);
		addWeighted(xe, 0.5, ye, 0.5, 0, r);//совмещаем 
		cv::imshow("ddddd", r);
		double ce = (clock() - cb) * 1000 / CLOCKS_PER_SEC;
		if (ce > delay - 1) ce = 1;
		else ce = delay - ce;
		int a = cv::waitKey(ce);
		if (a == 27) break;
	}
	destroyAllWindows();
	return 0;

}
