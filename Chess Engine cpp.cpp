#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int boardsize = 100;

int main()
{
	cv::Mat board = cv::Mat::zeros(cv::Size(1000, 1000), CV_8UC3);
	cv::namedWindow("Mask", 0);


	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			cv::rectangle(board, cv::Point(boardsize, 100), cv::Point(200, 200), cv::Scalar(0, 255, 255), -1, cv::LINE_4);
		}
	}
	cv::imshow("Mask", board);
	cv::waitKey(0);

	return 0;
}