#include <iostream>
#include <opencv2/opencv.hpp>
#include "FaceDetector.h"

using namespace std;

int main(int argc, char **argv)
{
    float f;
    float FPS[16];
    int i, Fcnt=0;
    cv::Mat frame;
    const int max_side = 320;

    //some timing
    chrono::steady_clock::time_point Tbegin, Tend;

    for(i=0;i<16;i++) FPS[i]=0.0;

    Detector detector("face.param","face.bin");

    cv::VideoCapture cap("Walks2.mp4");
    if (!cap.isOpened()) {
        cerr << "ERROR: Unable to open the camera" << endl;
        return 0;
    }
    cout << "Start grabbing, press ESC on Live window to terminate" << endl;

    while(1){
        //get frame
//        frame=cv::imread("11.jpg");  //if you want to run just one picture need to refresh frame before class detection
        cap >> frame;
        if (frame.empty()) {
            cerr << "ERROR: Unable to grab from the camera" << endl;
            break;
        }

        // scale
        float long_side = std::max(frame.cols, frame.rows);
        float scale = max_side/long_side;
        cv::Mat img_scale;

        cv::resize(frame, img_scale, cv::Size(frame.cols*scale, frame.rows*scale));

        std::vector<bbox> boxes;

        Tbegin = chrono::steady_clock::now();

        detector.Detect(img_scale, boxes);

        Tend = chrono::steady_clock::now();

        // draw image
        for (size_t j = 0; j < boxes.size(); ++j) {
            cv::Rect rect(boxes[j].x1/scale, boxes[j].y1/scale, boxes[j].x2/scale - boxes[j].x1/scale, boxes[j].y2/scale - boxes[j].y1/scale);
            cv::rectangle(frame, rect, cv::Scalar(0, 0, 255), 1, 8, 0);
//            cv::putText(frame, cv::format("%f", boxes[j].s), cv::Size((boxes[j].x1/scale), boxes[j].y1/scale), cv::FONT_HERSHEY_COMPLEX, 0.5, cv::Scalar(0, 255, 255));
            cv::circle(frame, cv::Point(boxes[j].point[0]._x / scale, boxes[j].point[0]._y / scale), 1, cv::Scalar(0, 0, 225), 3);
            cv::circle(frame, cv::Point(boxes[j].point[1]._x / scale, boxes[j].point[1]._y / scale), 1, cv::Scalar(0, 255, 225), 3);
            cv::circle(frame, cv::Point(boxes[j].point[2]._x / scale, boxes[j].point[2]._y / scale), 1, cv::Scalar(255, 0, 225), 3);
            cv::circle(frame, cv::Point(boxes[j].point[3]._x / scale, boxes[j].point[3]._y / scale), 1, cv::Scalar(0, 255, 0), 3);
            cv::circle(frame, cv::Point(boxes[j].point[4]._x / scale, boxes[j].point[4]._y / scale), 1, cv::Scalar(255, 0, 0), 3);
        }

        //calculate frame rate
        f = chrono::duration_cast <chrono::milliseconds> (Tend - Tbegin).count();
        if(f>0.0) FPS[((Fcnt++)&0x0F)]=1000.0/f;
        for(f=0.0, i=0;i<16;i++){ f+=FPS[i]; }
        cv::putText(frame, cv::format("FPS %0.2f", f/16),cv::Point(10,20),cv::FONT_HERSHEY_SIMPLEX,0.6, cv::Scalar(0, 0, 255));

        //show output
//        cv::imwrite("Result_11.jpg",frame); //in case you run only a jpg picture
        cv::imshow("RPi 64 OS - 1,95 GHz - 2 Mb RAM", frame);
        char esc = cv::waitKey(50);
        if(esc == 27) break;
    }

    cv::destroyAllWindows();
    return 0;
}
