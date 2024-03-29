/*
* First Start Menu
*/

/* Show welcome Screen for the first start procedure */
void welcomeScreen() {
	display.fillScr(127, 127, 127);
	display.setBackColor(127, 127, 127);
	display.setFont(bigFont);
	display.printC("Welcome to the", CENTER, 20);
	display.printC("DIY-Thermocam", CENTER, 60, VGA_YELLOW);
	display.setFont(smallFont);
	display.printC("This is the first time setup.", CENTER, 110);
	display.printC("It will guide you through", CENTER, 140);
	display.printC("the basic settings.", CENTER, 170);
	display.printC("Please touch screen", CENTER, 210, VGA_YELLOW);
	//Wait for touch press
	while (!touch.touched());
	//Touch release again
	while (touch.touched());
}

/* Shows an info screen during the first start procedure */
void infoScreen(String* text, bool Continue = true) {
	display.fillScr(127, 127, 127);
	display.setBackColor(127, 127, 127);
	display.setFont(bigFont);
	display.printC(text[0], CENTER, 20, VGA_YELLOW);
	display.setFont(smallFont);
	display.printC(text[1], CENTER, 55);
	display.printC(text[2], CENTER, 80);
	display.printC(text[3], CENTER, 105);
	display.printC(text[4], CENTER, 130);
	if (Continue) {
		display.printC(text[5], CENTER, 155);
		display.printC(text[6], CENTER, 180);
		display.printC("Please touch screen", CENTER, 212, VGA_YELLOW);
		//Wait for touch press
		while (!touch.touched());
		//Touch release again
		while (touch.touched());
	}
	else {
		display.printC(text[5], CENTER, 180);
		display.printC(text[6], CENTER, 205);
	}
}

/* Help screen for the first start of live mode */
void liveModeHelper() {
	//Array to store up to 7 lines of text
	String text[7];
	//Hint screen for the live mode #1 
	text[0] = "Live Mode Helper";
	text[1] = "To enter the live mode menu,";
	text[2] = "touch the screen. 'Exit' will";
	text[3] = "bring you to the main menu.";
	text[4] = "Pressing the pushbutton on";
	text[5] = "top of the device short takes";
	text[6] = "an image, long records a video.";
	infoScreen(text);
	//Set EEPROM marker to complete
	EEPROM.write(eeprom_firstStart, eeprom_setValue);
}

/* First start setup*/
void firstStart() {
	//Welcome screen
	welcomeScreen();
	//Array to store up to 7 lines of text
	String text[7];
	//Welcome screen
	text[0] = "First time setup";
	text[1] = "Welcome to the";
	text[2] = "DIY-Thermocam!";
	text[3] = "";
	text[4] = "This is the first time setup";
	text[5] = "that will guide you through";
	text[6] = "the basic settings for the cam.";
	//Hint screen for the time and date settings
	text[0] = "Set Time & Date";
	text[1] = "In the next screen, you have";
	text[2] = "to set the time and date so ";
	text[3] = "that it matches your current";
	text[4] = "time zone. This only has to be";
	text[5] = "done once, as the coin cell battery";
	text[6] = "powers the real-time-clock permanent.";
	infoScreen(text);
	//Adjust Time & Date settings
	timeAndDateMenu(true);
	timeAndDateMenuHandler(true);
	//Hint screen for temperature format setting
	text[0] = "Set Temp. Format";
	text[1] = "In the next screen, you have";
	text[2] = "to set the temperature format ";
	text[3] = "for the temperature display.";
	text[4] = "Choose either Celcius or";
	text[5] = "Fahrenheit, the conversion will";
	text[6] = "be done automatically.";
	infoScreen(text);
	//Temperature format
	tempFormatMenu(true);
	//Hint screen for the image storage settings
	text[0] = "Image Storage";
	text[1] = "In the next screen, you have";
	text[2] = "to set the format and the type";
	text[3] = "for the image save proccess.";
	text[4] = "";
	text[5] = "Storage options for videos";
	text[6] = "will be set in the next step.";
	infoScreen(text);;
	//Image storage
	imagesStorageMenu(true);
	imagesStorageMenuHandler(true);
	//Hint screen for the video storage settings
	text[0] = "Video Storage";
	text[1] = "In the next screen, you have";
	text[2] = "to set the format and the type";
	text[3] = "for the video save proccess.";
	text[4] = "Those will be applied for";
	text[5] = "every single frame that is";
	text[6] = "saved during the video record.";
	infoScreen(text);
	//Image storage
	videosStorageMenu(true);
	videosStorageMenuHandler(true);
	//Set Color Scheme to Rainbow
	EEPROM.write(eeprom_colorScheme, 0);
	//Hint screen for the video storage settings
	text[0] = "Setup completed !";
	text[1] = "The first-time setup is";
	text[2] = "now complete. Please reboot";
	text[3] = "the device by turning the";
	text[4] = "power switch off and on again.";
	text[5] = "Afterwards, you will be able";
	text[6] = "to use the Thermocam normally.";
	infoScreen(text, false);
	//Set EEPROM marker to show hint screen next time
	EEPROM.write(eeprom_firstStart, 100);
	while (true);
}