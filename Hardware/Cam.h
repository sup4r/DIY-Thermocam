/*
* Methods to access the VC0706 camera module
*/

/* Init the camera module */
void initCamera() {
	if (!cam.begin(115200)) {
		drawMessage((char*) "Error connecting to visual camera!");
		while (1);
	}
	cam.setImageSize(VC0706_640x480);
}

/* Send the capture command to the camera*/
void captureVisualImage() {
	cam.takePicture();
}

/* Receive the visual image from the camera and save it on the SD card */
void saveVisualImage() {
	uint16_t jpglen = cam.frameLength();
	//Start alternative clockline
	startAltClockline();
	//Buffer to store the data
	uint8_t *buffer;
	while (jpglen > 0) {
		uint8_t bytesToRead = min(jpglen, 64);
		buffer = cam.readPicture(bytesToRead);
		sdFile.write(buffer, bytesToRead);
		jpglen -= bytesToRead;
	}
	sdFile.close();
	//End SD Transmission
	endAltClockline();
	cam.end();
	return;
}