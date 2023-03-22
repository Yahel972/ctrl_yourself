#include "ScreenCapture.h"

ScreenCapture::ScreenCapture() {}

// function will be used as a thread
// sending screenshots to the controlled PC
void ScreenCapture::recordScreen(SOCKET sock)
{
    // capture image
    HWND hwnd = GetDesktopWindow();
    int screenWidth = SCREEN_SIZE_TEMP; //GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = SCREEN_SIZE_TEMP; //GetSystemMetrics(SM_CYSCREEN);
    while (true)
    {
            

        // Create a device context for the screen
        HDC hdcScreen = CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);  
        HDC hdcMem = CreateCompatibleDC(hdcScreen);

        HBITMAP hbmScreen = CreateCompatibleBitmap(hdcScreen, screenWidth, screenHeight); // Current bitmap
        HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem, hbmScreen); // taking old bitmap

        // Copy the contents of the screen to the new bitmap
        BitBlt(hdcMem, 0, 0, screenWidth, screenHeight, hdcScreen, 0, 0, SRCCOPY);

        BITMAPINFOHEADER bi = createBitmapHeader(screenWidth, screenHeight);

        int size = screenWidth * screenHeight * 4;
        char* pixels = new char[size];
        GetDIBits(hdcScreen, hbmScreen, 0, screenHeight, pixels, (BITMAPINFO*)&bi, DIB_RGB_COLORS);

        
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        // Compress the captured frame


        // Send the compressed frame to the server

        // Wait for a short period of time before capturing the next frame
        send(sock, pixels, size, 0);

        //delete[] pixels;


        // Clean up
        SelectObject(hdcMem, hbmOld);
        DeleteObject(hbmScreen);
        DeleteDC(hdcMem);
        DeleteDC(hdcScreen);

        }
    }

void ScreenCapture::receiveCaptures(SOCKET sock)
{
    const int size = SCREEN_SIZE_TEMP * SCREEN_SIZE_TEMP * 4;
    //char buffer[size] = { 0 };
    char* buffer = new char[size];
    while (true)
    {
        recv(sock, buffer, size, 0);

        cv::Mat image(256, 256, CV_8UC4, buffer);

        cv::imshow("Screenshot", image);
        cv::waitKey(30);
    }
}

// function creates a bitmap header
BITMAPINFOHEADER ScreenCapture::createBitmapHeader(int width, int height)
{
    BITMAPINFOHEADER bi;

    // creating a bitmap
    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = width;
    bi.biHeight = -height;
    bi.biPlanes = 1;
    bi.biBitCount = 32;
    bi.biCompression = BI_RGB;
    bi.biSizeImage = 0;
    bi.biXPelsPerMeter = 0;
    bi.biYPelsPerMeter = 0;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;

    return bi;
}

// function __________ @Dean
cv::Mat ScreenCapture::captureScreenMat(HWND hwnd)
{
    cv::Mat src;

    // get handles to a device context (DC)
    HDC hwindowDC = GetDC(hwnd);
    HDC hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);
    SetStretchBltMode(hwindowCompatibleDC, COLORONCOLOR);

    // define scale, height and width
    int screenx = GetSystemMetrics(SM_XVIRTUALSCREEN);
    int screeny = GetSystemMetrics(SM_YVIRTUALSCREEN);
    int width = GetSystemMetrics(SM_CXVIRTUALSCREEN);
    int height = GetSystemMetrics(SM_CYVIRTUALSCREEN);

    // create mat object
    src.create(height, width, CV_8UC4);

    // create a bitmap
    HBITMAP hbwindow = CreateCompatibleBitmap(hwindowDC, width, height);
    BITMAPINFOHEADER bi = createBitmapHeader(width, height);

    // use the previously created device context with the bitmap
    SelectObject(hwindowCompatibleDC, hbwindow);

    // copy from the window device context to the bitmap device context
    StretchBlt(hwindowCompatibleDC, 0, 0, width, height, hwindowDC, screenx, screeny, width, height, SRCCOPY);  //change SRCCOPY to NOTSRCCOPY for wacky colors !
    GetDIBits(hwindowCompatibleDC, hbwindow, 0, height, src.data, (BITMAPINFO*)&bi, DIB_RGB_COLORS);            //copy from hwindowCompatibleDC to hbwindow

    // avoid memory leak
    DeleteObject(hbwindow);
    DeleteDC(hwindowCompatibleDC);
    ReleaseDC(hwnd, hwindowDC);

    return src;
}

std::string ScreenCapture::getSize(int size)
{
    int digits = ScreenCapture::count_digit(size);
    switch (digits)
    {
    case 6:
        return std::to_string(size);
    case 5:
        return std::to_string(size) + "0";
    case 4:
        return std::to_string(size) + "00";
    case 3:
        return std::to_string(size) + "000";
    case 2:
        return std::to_string(size) + "0000";
    case 1:
        return std::to_string(size) + "00000";
    default:
        std::cout << "something is wrong..." << std::endl;
        break;
    }
    return "000000";
}

// helper function - finds the amount of digits in a given number
int ScreenCapture::count_digit(int number) {
    int count = 0;
    while (number != 0) {
        number = number / 10;
        count++;
    }
    return count;
}