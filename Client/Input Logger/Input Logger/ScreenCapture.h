#pragma once

#define CV_IGNORE_DEBUG_BUILD_GUARD
#include <opencv2/imgcodecs/imgcodecs_c.h>

#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <thread>
#include "Client.h"
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/core/core_c.h>

class ScreenCapture
{
public:
	ScreenCapture();
	~ScreenCapture();
private:
	cv::Mat captureScreenMat(HWND hwnd);
};
