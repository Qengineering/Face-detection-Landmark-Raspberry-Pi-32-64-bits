# Face-detection-Landmark-Raspberry-Pi-32-64-bits
![output image]( https://qengineering.eu/images/Face_Land_9.jpg )
## A fast face detection with landmarks running on a bare Raspberry Pi 4.
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)<br/>

This C ++ application detects faces in a scene. At the same time, the characteristic landmarks are located so that you can use them as input for a face recognition algorithm.  (see: [Face recognition](https://github.com/Qengineering/Face-Recognition-Raspberry-Pi-64-bits)).

------------

## Benchmark.
| RPi 4 64-OS 1950 MHz | RPi 4 64-OS 1500 MHz | Jetson Nano 2015 MHz | Jetson Nano 1479 MHz |
|  :------------: | :-------------: | :-------------:  | :-------------: |
| 20 mS | 23 mS  |  11 mS | 14 mS  |

------------

## Dependencies.
To run the application on a 64 OS, you have to:<br/>
- A raspberry Pi 4 with a 64-bit operating system. It can be the Raspberry 64-bit OS, or Ubuntu 18.04 / 20.04. (https://qengineering.eu/install-raspberry-64-os.html) <br/>
- The Tencent ncnn framework installed. (https://qengineering.eu/install-ncnn-on-raspberry-pi-4.html) <br/>
- OpenCV 64 bit installed. (https://qengineering.eu/install-opencv-4.3-on-raspberry-64-os.html) <br/>
- Code::Blocks installed.<br/>

To run the application on a 32 OS, you need:<br/>
- The Tencent ncnn framework installed. (https://qengineering.eu/install-ncnn-on-raspberry-pi-4.html) <br/>
- OpenCV 32 bit installed. (https://qengineering.eu/install-opencv-4.3-on-raspberry-pi-4.html) <br/>
- Code::Blocks installed.

------------

## Running the app.
To extract and run the network in Code::Blocks <br/>
$ mkdir *MyDir* <br/>
$ cd *MyDir* <br/>
$ wget https://github.com/Qengineering/Face-detection-Landmark-Raspberry-Pi-32-64-bits/archive/refs/heads/master.zip <br/>
$ unzip -j master.zip <br/>
Remove master.zip, LICENSE and README.md as they are no longer needed. <br/> 
$ rm master.zip <br/>
$ rm README.md <br/> <br/>
Your *MyDir/ncnn* folder must now look like this: <br/> 
9.jpg<br/>
11.jpg<br/>
Walk2.mp4 (demo video)<br/>
FaceLandmark.cpb (code::blocks project file)<br/>
main.cpp (main example file)<br/>
FaceDetector.cpp (Ultra face class)<br/>
FaceDetector.hpp (Ultra face class)<br/>
face.bin (ncnn model)<br/>
face.param (ncnn topology file)<br/>

------------

## WebCam.
If you want to use a camera please alter line 22 in main.cpp to<br/>
`cv::VideoCapture cap(0);                          //WebCam`<br/>
If you want to run a movie please alter line 22 in main.cpp to<br/>
`cv::VideoCapture cap("Walks2.mp4");   //Movie`<br/>

------------

### Thanks.
https://github.com/Tencent/ncnn<br/>
https://github.com/nihui<br/>
https://github.com/Linzaer/Ultra-Light-Fast-Generic-Face-Detector-1MB<br/>
https://github.com/biubug6/Face-Detector-1MB-with-landmark/tree/master/Face_Detector_ncnn<br/><br/>

![output image]( https://qengineering.eu/images/Face_Land_11.jpg )

