#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>


using namespace std;
using namespace cv;
#define PI 3.14159265
int main(){

	char name[20];
	char nameHough[10];
	Mat imgMedian;
	Mat imgMedianBez;
	Mat imgGaussian;
	Mat imgThresholded1;
	Mat imgThresholded2;
	Mat imgThresholded;
	Mat binary_edges;
	Mat imgHSV;
	Mat binary_edges2;
	Mat img_hough2;
	
	/* odkomentowac dla wideo + out_capture.write(img_hough); w 182 linii
	VideoCapture cap;
	VideoWriter out_capture("video.avi", CV_FOURCC('M', 'J', 'P', 'G'), 12, Size(1920, 1080));


	 
	for (int n = 1; n < 156; n++){
		sprintf(name, "seq4/image.%04d.jpg", n);

		Mat img = imread(name, 1); // 1 - w formacie BGR
		*/ 

	Mat img = imread("zielone1.jpg", 1);
		Mat img_hough = img.clone();

		cvtColor(img, imgHSV, CV_BGR2HSV);
		cvtColor(img, img, CV_BGR2GRAY);
	
			Canny(img, binary_edges2, 100, 200);
		vector<Vec3f> circles;


		//	inRange(imgHSV, Scalar(165, 60, 110), Scalar(180, 255, 255), imgThresholded); //Threshold the image czerwone
		//	inRange(imgHSV, Scalar(0, 60, 110), Scalar(20, 255, 255), imgThresholded2); //Threshold the image czerwone2
			inRange(imgHSV, Scalar(40, 60, 110), Scalar(90, 255, 255), imgThresholded); //Threshold the image zielone
			Mat imgThresholdedOnly = imgThresholded.clone();
			Canny(imgThresholdedOnly, binary_edges2, 100, 200);

		medianBlur(imgThresholded, imgMedianBez, 7);

		/*
		//111111111111111111111111111111111111
		inRange(imgHSV, Scalar(165, 150, 150), Scalar(180, 255, 255), imgThresholded); //Threshold the image czerwone
		// CZERWONE1

		//morphological opening (removes small objects from the foreground)
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//	imshow("Threshold otwarcie", imgThresholded);

		//morphological closing (removes small holes from the foreground)
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		//	Mat imgFinal;
		//	cvtColor(imgThresholded, imgFinal, CV_HSV2BGR);

		//	imshow("Threshold domkniecie", imgThresholded);

		//![reduce_noise]
		medianBlur(imgThresholded, imgMedian, 7);
		//![reduce_noise]

		Canny(imgMedian, binary_edges, 100, 200);




		//	vector<Vec3f> circles;
		HoughCircles(binary_edges, circles, CV_HOUGH_GRADIENT, 2, 20, 100, 20, 5, 30);

		for (size_t i = 0; i < circles.size(); i++){
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		// draw the circle center
		circle(img_hough, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		// draw the circle outline
		circle(img_hough, center, radius, Scalar(0, 0, 255), 2, 8, 0);
		}
		//	imshow("Hough image1", img_hough);

		// 22222222222222222222222222222222222222222222222
		// CZERWONE2

		inRange(imgHSV, Scalar(0, 150, 150), Scalar(20, 255, 255), imgThresholded);

		//morphological opening (removes small objects from the foreground)
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//	imshow("Threshold otwarcie", imgThresholded);

		//morphological closing (removes small holes from the foreground)
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		//	Mat imgFinal;
		//	cvtColor(imgThresholded, imgFinal, CV_HSV2BGR);

		//	imshow("Threshold domkniecie", imgThresholded);

		//![reduce_noise]
		medianBlur(imgThresholded, imgMedian, 7);
		//![reduce_noise]

		Canny(imgMedian, binary_edges, 100, 200);




		//	vector<Vec3f> circles;
		HoughCircles(binary_edges, circles, CV_HOUGH_GRADIENT, 2, 20, 100, 20, 5, 30);

		for (size_t i = 0; i < circles.size(); i++){
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		// draw the circle center
		circle(img_hough, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		// draw the circle outline
		circle(img_hough, center, radius, Scalar(0, 0, 255), 2, 8, 0);
		}
		//	imshow("Hough image2", img_hough);

		*/
		
		// 33333333333333333333333333333333333333333333
		// ZIELONE

		
	//	inRange(imgHSV, Scalar(40, 60, 110), Scalar(90, 255, 255), imgThresholded);

		//morphological opening (removes small objects from the foreground)
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//	imshow("Threshold otwarcie", imgThresholded);

		//morphological closing (removes small holes from the foreground)
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//	imshow("Threshold domkniecie", imgThresholded);

		//![reduce_noise]
		medianBlur(imgThresholded, imgMedian, 9);
		//![reduce_noise]

		Canny(imgMedian, binary_edges, 100, 200);




		//	vector<Vec3f> circles;
		HoughCircles(binary_edges, circles, CV_HOUGH_GRADIENT, 2, 20, 100, 20, 5, 30);

		for (size_t i = 0; i < circles.size(); i++){
			Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
			int radius = cvRound(circles[i][2]);
			// draw the circle center
			circle(img_hough, center, 3, Scalar(0, 255, 0), -1, 8, 0);
			// draw the circle outline
			circle(img_hough, center, radius, Scalar(0, 0, 255), 2, 8, 0);
		}
			imshow("Hough", img_hough);



				//vector<Vec3f> circles2;
				//HoughCircles(binary_edges2, circles2, CV_HOUGH_GRADIENT, 2, 20, 100, 20, 5, 30);

				//for (size_t i = 0; i < circles.size(); i++){
				//	Point center(cvRound(circles2[i][0]), cvRound(circles2[i][1]));
				//	int radius = cvRound(circles2[i][2]);
				//	// draw the circle center
				//	circle(img_hough2, center, 3, Scalar(0, 255, 0), -1, 8, 0);
				//	// draw the circle outline
				//	circle(img_hough2, center, radius, Scalar(0, 0, 255), 2, 8, 0);
				//}
				//imshow("Hough bez filtrow", img_hough2);


//		sprintf(nameHough, "Hough %d", n);

//		cap.grab();

//		out_capture.write(img_hough); // ODKONEMNTOWAC DLA WIDEO

//		imshow(nameHough, img_hough);

	//} // ODKOMENTOWAC DLA WIDEO
	// wszystkie po drodze operacje
			imshow("HSV", imgHSV);

	imshow("Threshold", imgThresholded);

	imshow("Median", imgMedian);

	imshow("Threshold bez operacji", imgThresholdedOnly);

//	imshow("Image", img);

	imshow("Canny", binary_edges);

	imshow("Median bez operacji", imgMedian);

	imshow("Canny bez operacji", binary_edges2);

	waitKey(0);
	return 0;
}
