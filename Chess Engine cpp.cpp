#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace std;

int boardsize = 100;
cv::Scalar color = cv::Scalar(255, 255, 0);


int main()
{
	cv::Mat board = cv::Mat::zeros(cv::Size(1000, 1000), CV_8UC3);
	cv::namedWindow("Mask", 0);


	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			cv::Point startpoint = cv::Point(100 + x * boardsize, 100 + y * boardsize);
			cv::Point endpoint = cv::Point(100 + (x + 1) * boardsize, 100 + (y+1) * boardsize);

			if ((x + y) % 2 == 0) 
			{
				color = cv::Scalar(62, 148,228);

			}
			else
			{
				color = cv::Scalar(16, 63,120);
			}

			cout << color << endl;

			cv::rectangle(board, startpoint, endpoint, color, -1, cv::LINE_4);
		}
	}
	cv::imshow("Mask", board);
	cv::waitKey(0);

	return 0;
}