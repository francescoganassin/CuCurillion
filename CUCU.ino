// ***************************************
//
// A small lazy cucu for teensy 4.0 and audio shield
//
// Celesta's sounds come from Felt Instruments Helenka VST
//
// small tunes are short improvisations by Francesco Ganassin
// played on a foggy evening of November
// at home, in Rovigo, Veneto, Italy
//
// ***************************************
 
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

AudioPlaySdWav           playSdWav1;     //xy=308,204
AudioOutputI2S           i2s1;           //xy=495,204
AudioConnection          patchCord1(playSdWav1, 0, i2s1, 0);
AudioConnection          patchCord2(playSdWav1, 1, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=629,310

#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

void setup() {
  Serial.begin(9600);

  AudioMemory(8);

  sgtl5000_1.enable();
  sgtl5000_1.volume(0.85);

  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
}

void playFile(const char *filename)
{
  Serial.print("Playing file: ");
  Serial.println(filename);
  playSdWav1.play(filename);
  delay(5);

  while (playSdWav1.isPlaying()) {
  }
}

void loop() {
playFile("001.WAV");  
 delay(random(60000));
playFile("002.WAV");
 delay(random(60000));
playFile("003.WAV");
 delay(random(60000));
playFile("004.WAV");
 delay(random(60000));
playFile("005.WAV");
 delay(random(60000));
playFile("006.WAV");
 delay(random(60000));
playFile("007.WAV");
 delay(random(60000));
playFile("008.WAV");
 delay(random(60000));
playFile("009.WAV");
 delay(random(60000));
}
