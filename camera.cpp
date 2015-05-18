#include <iostream>
#include <raspicam/raspicam_cv.h>
#include "camera.h"

using namespace std;

	/**Sets a property in the VideoCapture. 
 * 
 * 
 * Implemented properties:
 * CV_CAP_PROP_FRAME_WIDTH,CV_CAP_PROP_FRAME_HEIGHT,
 * CV_CAP_PROP_FORMAT: CV_8UC1 or CV_8UC3
 * CV_CAP_PROP_BRIGHTNESS: [0,100]
 * CV_CAP_PROP_CONTRAST: [0,100]
 * CV_CAP_PROP_SATURATION: [0,100]
 * CV_CAP_PROP_GAIN: (iso): [0,100]
 * CV_CAP_PROP_EXPOSURE: -1 auto. [1,100] shutter speed from 0 to 33ms
 * CV_CAP_PROP_WHITE_BALANCE_RED_V : [1,100] -1 auto whitebalance
 * CV_CAP_PROP_WHITE_BALANCE_BLUE_U : [1,100] -1 auto whitebalance
 *
	 */
void SetPiCameraProperty(raspicam::RaspiCam_Cv &Camera)
{
	Camera.set(CV_CAP_PROP_FRAME_WIDTH,320);
	Camera.set(CV_CAP_PROP_FRAME_HEIGHT,240);
	Camera.set(CV_CAP_PROP_BRIGHTNESS,50);
	Camera.set(CV_CAP_PROP_CONTRAST,50);
	Camera.set(CV_CAP_PROP_SATURATION,50);
	Camera.set(CV_CAP_PROP_GAIN,50);
	Camera.set(CV_CAP_PROP_FORMAT,CV_8UC3);
	Camera.set(CV_CAP_PROP_EXPOSURE,-1);
	Camera.set(CV_CAP_PROP_WHITE_BALANCE_RED_V,-1);
	Camera.set(CV_CAP_PROP_WHITE_BALANCE_BLUE_U,-1);
}

void OpenPiCamera(raspicam::RaspiCam_Cv &Camera) 
{
	SetPiCameraProperty(Camera);
	
	if(!Camera.open()) 
	{
		cerr<<"Error opening camera"<<endl;
	}
    
	cout<<"Connected to camera ="<<Camera.getId()<<endl;	
}

void ClosePiCamera(raspicam::RaspiCam_Cv &Camera)
{
	Camera.release();
}	

