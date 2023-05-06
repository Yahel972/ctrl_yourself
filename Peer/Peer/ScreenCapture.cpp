#include "ScreenCapture.h"

ScreenCapture::ScreenCapture() {}

// function will be used as a thread
// sending screenshots to the controlled PC
void ScreenCapture::recordScreen(SOCKET sock, std::string width, std::string height)
{
    // capture image
    HWND hwnd = GetDesktopWindow();
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    while (true)
    {
        // Create a device context for the screen
        HDC hdcScreen = GetDC(NULL);
        HDC hdcMem = CreateCompatibleDC(hdcScreen);

        HBITMAP hbmScreen = CreateCompatibleBitmap(hdcScreen, screenWidth, screenHeight); // Current bitmap
        HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem, hbmScreen); // taking old bitmap

        // Copy the contents of the screen to the new bitmap
        BitBlt(hdcMem, 0, 0, screenWidth, screenHeight, hdcScreen, 0, 0, SRCCOPY);

        BITMAPINFOHEADER bi = createBitmapHeader(screenWidth, screenHeight);

        int size = screenWidth * screenHeight * 4;
        char* pixels = new char[size];
        GetDIBits(hdcScreen, hbmScreen, 0, screenHeight, pixels, (BITMAPINFO*)&bi, DIB_RGB_COLORS);

        cv::Mat image(screenHeight, screenWidth, CV_8UC4, pixels);

        cv::Mat resizedImage;
        cv::resize(image, resizedImage, cv::Size(stoi(width), stoi(height)));

        // Convert the resized image back to raw pixel data
        size = screenWidth * screenHeight * 4;
        char* resizedPixels = new char[size];
        memcpy(resizedPixels, resizedImage.data, size);


        // Wait for a short period of time before capturing the next frame
        
        send(sock, resizedPixels, size, 0);
        delete[] pixels;
        delete[] resizedPixels;

        // Clean up
        SelectObject(hdcMem, hbmOld);
        DeleteObject(hbmScreen);
        DeleteDC(hdcMem);
        DeleteDC(hdcScreen);
    }
}

void ScreenCapture::receiveCaptures(SOCKET sock, std::string width, std::string height)
{
    int screenWidth = stoi(width);//GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = stoi(height); // GetSystemMetrics(SM_CYSCREEN);
    const int size = screenWidth * screenHeight * 4;
    //char buffer[size] = { 0 };
    //cv::namedWindow("Screen", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Screen", cv::WINDOW_AUTOSIZE);
    while (true)
    {
        char* buffer = new char[size];
        int totalReceived = 0; // total bytes received so far
        while (totalReceived < size) {
            int bytesReceived = recv(sock, buffer + totalReceived, size - totalReceived, 0);
            if (bytesReceived == SOCKET_ERROR) {
                // handle error
                std::cout << "error" << std::endl;
                break;
            }
            if (bytesReceived == 0) {
                std::cout << "connection closed" << std::endl;
                break;
            }
            totalReceived += bytesReceived;
        }
        if (totalReceived == size) {
            // message received successfully
            // process the message in the buffer
            cv::Mat image(screenHeight, screenWidth, CV_8UC4, buffer);
            cv::imshow("Screen", image);
            cv::waitKey(5);
            delete[] buffer;
        }
        //cv::destroyAllWindows();
    }
            //
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