/*
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;
int main(){

	char name[20]; // nazwa pliku wejsciowego
	char nameHough[10]; // nazwa obrazu po transformacji hougha
	Mat imgMedianBez; // filtr medianowy przed filtrami morfologicznymi
	Mat imgThresholded; // obraz po filtrach morfologicznych - otwarcie, nastepnie domkniecie
	Mat imgMedian; // filtr medianowy po filtrach morfologicznych
	Mat binaryEdges; // wykryte krawêdzie algorytmem Canny
	Mat imgHSV; // obraz w przestrzeni HSV, bez zastosowanych zadnych operacji
	VideoCapture cap;
	VideoWriter out_capture("video.avi", CV_FOURCC('M', 'J', 'P', 'G'), 12, Size(1920, 1080));

	for (int n = 1; n < 156; n++){
		sprintf(name, "seq4/image.%04d.jpg", n);
		Mat img = imread(name, 1); // >0 jako drugi argument oznacza odczytanie w formacie BGR
		Mat imgHough = img.clone();
		vector<Vec3f> circles;

		cvtColor(img, imgHSV, CV_BGR2HSV);

		// filtr medianowy przed filtrami morfologicznymi
		medianBlur(imgThresholded, imgMedianBez, 7);
	
		// pozostawienie tylko barw zielonych
		inRange(imgHSV, Scalar(40, 150, 150), Scalar(90, 255, 255), imgThresholded);

		// otwarcie
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		// imshow("Threshold otwarcie", imgThresholded);
		// domkniêcie
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		// imshow("Threshold domkniecie", imgThresholded);

		// usuwanie szumu
		medianBlur(imgThresholded, imgMedian, 9);

		Canny(imgMedian, binaryEdges, 100, 200);

		HoughCircles(binaryEdges, circles, CV_HOUGH_GRADIENT, 2, 20, 100, 20, 5, 30);

		for (size_t i = 0; i < circles.size(); i++){
			Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
			int radius = cvRound(circles[i][2]);
			// draw the circle center
			circle(imgHough, center, 3, Scalar(0, 255, 0), -1, 8, 0);
			// draw the circle outline
			circle(imgHough, center, radius, Scalar(0, 0, 255), 2, 8, 0);
		}
			sprintf(nameHough, "Hough %d", n);
			imshow(nameHough, imgHough);
			out_capture.write(imgHough);
	}
		imshow("Threshold", imgThresholded);
		imshow("Median", imgMedian);
		imshow("Canny", binaryEdges);
		imshow("Median bez operacji", imgMedian);

	waitKey(0);
	return 0;
}
*/