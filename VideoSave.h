#include <iostream>
#include <sstream>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

class VideoSave
{
public:
	bool isRecording; // 0;
	cv::Mat currentFrame;	// frame will be saved into the video
	void Save(Mat _frame);	// function to save the image stream to video
	void Save(Mat _frame1, Mat _fram2);
	void createFileFolder();

	String currentTimeString();

	VideoSave();
	~VideoSave();
};