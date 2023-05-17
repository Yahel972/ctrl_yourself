#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <thread>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/core/core_c.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>


#define SCREEN_SIZE_TEMP 512 

class ScreenCapture
{
public:
	ScreenCapture();
	void recordScreen(SOCKET sock, std::string width, std::string height);
	void receiveCaptures(SOCKET sock, std::string width, std::string height);

private:
	BITMAPINFOHEADER createBitmapHeader(int width, int height);
	cv::Mat captureScreenMat(HWND hwnd);
};