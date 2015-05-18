#include <iostream>
#include <time.h>
#include <stdio.h>
#include <raspicam/raspicam_cv.h>
#include "camera.h"

using namespace std;

int main(int argc,char **argv) 
{
	time_t start,end;
	
	raspicam::RaspiCam_Cv Camera;
	
	OpenPiCamera(Camera);
	
	cv::Mat rawMat;
	IplImage *frame;
	
	cvNamedWindow("Capture Frame",1);
	
	time(&start);
	int counter=0;
	
	while(1)
	{
		Camera.grab();
		Camera.retrieve(rawMat);
	
		frame=new IplImage(rawMat);
		
		time(&end);
		++counter;
		double sec=difftime(end,start);
		double fps=counter/sec;
		printf("FPS: %0.2f\n",fps);
		
		cvShowImage("Capture Frame",frame);

		if((cvWaitKey(1) & 255) == 27 ) break;  
	}

	ClosePiCamera(Camera);
}
