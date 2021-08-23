# SFND 2D Feature Tracking

<img src="images/keypoints.png" width="820" height="248" />

The idea of the camera course is to build a collision detection system - that's the overall goal for the Final Project. As a preparation for this, you will now build the feature tracking part and test various detector / descriptor combinations to see which ones perform best. This mid-term project consists of four parts:

* First, you will focus on loading images, setting up data structures and putting everything into a ring buffer to optimize memory load. 
* Then, you will integrate several keypoint detectors such as HARRIS, FAST, BRISK and SIFT and compare them with regard to number of keypoints and speed. 
* In the next part, you will then focus on descriptor extraction and matching using brute force and also the FLANN approach we discussed in the previous lesson. 
* In the last part, once the code framework is complete, you will test the various algorithms in different combinations and compare them with regard to some performance measures. 

See the classroom instruction and code comments for more details on each of these parts. Once you are finished with this project, the keypoint matching part will be set up and you can proceed to the next lesson, where the focus is on integrating Lidar points and on object detection using deep-learning. 

## Assignment Write Up
MP.1 Data Buffer Optimization: 
* When the vector gets larger than size 2, we erase the oldest image in the ring buffer. 

MP.2 Keypoint Detection: 
* The Haris implementation is recycled from the exercises. The remaining detectors are implemented by a call to a function in matching2D_Student.cpp with the option to select by a string. The function performs the simple 1 line implementation in openCV.

MP.3 Keypoint Removal:
* Here we check vehicleKeypoints to see if they are inside the defined rectangle which contains the preceding vehicle. If they are inside, we add them to keypoints. 

MP.4 Keypoint Descriptors:
* The openCV documentation was used to implement the keypoint descriptors which are also selectable via a string. 

MP.5 Descriptor Matching:
* Again, the documentation was used to implement KNN and FLANN. For FLANN, we have to convert to CV_32F for compatability. KNN is implemented with k=2. When using SIFT, we have to use DES_HOG for the descriptor catagory, and a check is added accordingly. 

MP.6 Descriptor Distance Ratio:
* The descriptor distance ratio test was implemented using KNN with k=2. 

MP.7 Performance Evaluation 1:
* The total number of keypoints is counted with numOfKpts which is an int that sums the keypoints of all 10 images. The distrobution of the keypoints is centered around areas of high contrast such as around shaddows. 

MP.8 Performance Evaluation 2:
* The number of matched kepoints is is logged with MAT_BF used. 

MP.9 Performance Evaluation 3:
* For tis part, two vectos called detectorTimes and descriptorTimes are created. After the times are calulated for each image, they are added to their respective vector. The vector is then returned and later appended again for the next image unil the loop ends. At the end, the times are averaged and displayed. All combinations of descriptors and detectors were then put into the included spreadsheet to compare. The average of a given descriptor and detector are taken and then the list was sorted. The fastest Orb-Fast with a time of 0.9622ms. Second ands third were Brief-Fast and Brisk-Fast respectivly. These were very quick to compute on a 12C/24T Ryzen CPU, but I would like to consider my other use case: a low power arm computer for a mobile robot such as an NVIDIA jetson. For this, speed is paramount for real time aplications, so I would go with the Orb-Fast combination. 

Improvments:
The main thing I would do differently is instead of returning the descriptorTimes and detectorTimes, I would pass the vector by reference to modify it like I did with the numOfKpts variable.


## Dependencies for Running Locally
1. cmake >= 2.8
 * All OSes: [click here for installation instructions](https://cmake.org/install/)

2. make >= 4.1 (Linux, Mac), 3.81 (Windows)
 * Linux: make is installed by default on most Linux distros
 * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
 * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)

3. OpenCV >= 4.1
 * All OSes: refer to the [official instructions](https://docs.opencv.org/master/df/d65/tutorial_table_of_content_introduction.html)
 * This must be compiled from source using the `-D OPENCV_ENABLE_NONFREE=ON` cmake flag for testing the SIFT and SURF detectors. If using [homebrew](https://brew.sh/): `$> brew install --build-from-source opencv` will install required dependencies and compile opencv with the `opencv_contrib` module by default (no need to set `-DOPENCV_ENABLE_NONFREE=ON` manually). 
 * The OpenCV 4.1.0 source code can be found [here](https://github.com/opencv/opencv/tree/4.1.0)

4. gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using either [MinGW-w64](http://mingw-w64.org/doku.php/start) or [Microsoft's VCPKG, a C++ package manager](https://docs.microsoft.com/en-us/cpp/build/install-vcpkg?view=msvc-160&tabs=windows). VCPKG maintains its own binary distributions of OpenCV and many other packages. To see what packages are available, type `vcpkg search` at the command prompt. For example, once you've _VCPKG_ installed, you can install _OpenCV 4.1_ with the command:
```bash
c:\vcpkg> vcpkg install opencv4[nonfree,contrib]:x64-windows
```
Then, add *C:\vcpkg\installed\x64-windows\bin* and *C:\vcpkg\installed\x64-windows\debug\bin* to your user's _PATH_ variable. Also, set the _CMake Toolchain File_ to *c:\vcpkg\scripts\buildsystems\vcpkg.cmake*.


## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./2D_feature_tracking`.
