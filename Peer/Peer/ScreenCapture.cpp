#include "ScreenCapture.h"

ScreenCapture::ScreenCapture() {}

// function will be used as a thread
// sending screenshots to the controlled PC
void ScreenCapture::recordScreen(SOCKET sock)
{
    // capture image
    HWND hwnd = GetDesktopWindow();
    //while (true)
    //{ 
        cv::Mat src = captureScreenMat(hwnd);
        std::vector<uchar> buffer;

        cv::imencode(".png", src, buffer);
        //char* naktar = (char*)malloc(sizeof(char) * buffer.size());
        char naktar[965535] = { 0 };
        std::string size = getSize(buffer.size());
        std::cout << "len: " << size << std::endl;
        for (int i = 0; i < 6; i++)
        {
            naktar[i] = size[i];
        }
        for (int i = 0; i < buffer.size(); i++)
        {
            naktar[i + 6] = buffer[i];
        }


        cv::waitKey(1); // to dean - why 100?
        std::vector<uchar> restek;
        for (int i = 6; i < stoi(size) + 6; i++)
        {
            restek.push_back(naktar[i]);
        }
        
        cv::Mat image = cv::imdecode(restek, cv::IMREAD_COLOR);

        if (image.empty())
        {
            std::cerr << "Failed to decode image" << std::endl;
        }
        else
        {
            cv::imshow("Received Image", image);
            cv::waitKey(1);
        }
        cv::imshow("Received Image", image);

        send(sock, naktar, buffer.size(), 0);
    //}
}

void ScreenCapture::receiveCaptures(SOCKET sock)
{
    char buffer[965535] = { 0 };
    char size[6] = { 0 };
    //while (true)
    //{
        int bytes;
        recv(sock, size, 6, 0);
        int imgSize = stoi(std::to_string(size[0] - '0') + std::to_string(size[1] - '0') + std::to_string(size[2] - '0') + std::to_string(size[3] - '0') + std::to_string(size[4] - '0') + std::to_string(size[5] - '0'));
        for (int i = 0; i < imgSize; i += bytes) {
            if ((bytes = recv(sock, buffer + i, imgSize - i, 0)) == -1) {
                std::cout << "recv failed" << std::endl;
                exit(1);
            }
            else {
                std::cout << "benbenben" << std::endl;
            }   
        }

        std::vector<uchar> image_data;
        for (int i = 6; i < imgSize + 6; i++)
        {
            image_data.push_back(buffer[i]);
        }

        cv::Mat image = cv::imdecode(image_data, cv::IMREAD_COLOR);

        // Check if the decoding was successful
        if (image.empty())
        {
            std::cerr << "Failed to decode image" << std::endl;
        }
        else
        {
            cv::imshow("Received Image", image);
            Sleep(10000);
        }

    //}
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