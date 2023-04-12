#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <thread>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/core/core_c.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#define SCREEN_SIZE_TEMP 1024

class ScreenCapture
{
public:
	ScreenCapture();
	void recordScreen(SOCKET sock);
	void receiveCaptures(SOCKET sock);
private:
	BITMAPINFOHEADER createBitmapHeader(int width, int height);
	cv::Mat captureScreenMat(HWND hwnd);
	std::string getSize(int size);
	static int count_digit(int number);
};