#ifndef _CAPTURE_H
#define _CAPTURE_H

void OpenPiCamera(raspicam::RaspiCam_Cv &Camera);
void ClosePiCamera(raspicam::RaspiCam_Cv &Camera);
void SetPiCameraProperty(raspicam::RaspiCam_Cv &Camera);

#endif
