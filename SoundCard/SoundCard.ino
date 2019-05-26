#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputUSB            usb1;           //xy=127,300
AudioInputI2S            i2s1;           //xy=162,215
AudioMixer4              mixer2;         //xy=356,467
AudioMixer4              mixer1;         //xy=357,374
AudioOutputUSB           usb2;           //xy=492,321
AudioOutputI2S           i2s2;           //xy=529,494
AudioConnection          patchCord1(usb1, 0, mixer1, 1);
AudioConnection          patchCord2(usb1, 1, mixer2, 1);
AudioConnection          patchCord3(i2s1, 0, usb2, 0);
AudioConnection          patchCord4(i2s1, 0, mixer1, 0);
AudioConnection          patchCord5(i2s1, 1, usb2, 1);
AudioConnection          patchCord6(i2s1, 1, mixer2, 0);
AudioConnection          patchCord7(mixer2, 0, i2s2, 1);
AudioConnection          patchCord8(mixer1, 0, i2s2, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=377,220
// GUItool: end automatically generated code


const int myInput = AUDIO_INPUT_LINEIN;

void setup() {
  AudioMemory(12);
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(myInput);
  sgtl5000_1.volume(0.5); // Adjust Headphone Jack Volume, overwritten via poti if avialable
  sgtl5000_1.adcHighPassFilterDisable(); // this helps reducing noise quite a bit (no pun intended)
}

elapsedMillis volmsec=0;

void loop() {
  // every 50 ms, adjust the volume
  if (volmsec > 50) {
    float vol = analogRead(15);
    vol = vol / 1023.0;
    sgtl5000_1.volume(vol); // <-- comment out if you dont have the optional
    volmsec = 0;               //     volume pot on your audio shield
  }
}
