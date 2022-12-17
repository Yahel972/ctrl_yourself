#pragma once

#define CV_IGNORE_DEBUG_BUILD_GUARD


#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <thread>
#include "Server.h"
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/core/core_c.h>

class ScreenCapture
{
public:
	ScreenCapture();
	~ScreenCapture();
	cv::Mat captureScreenMat(HWND hwnd);
private:
	BITMAPINFOHEADER createBitmapHeader(int width, int height);
};
