#include <Servo.h>

//Threshold for servo motor control with muscle sensor. 
//You can set a threshold according to the maximum and minimum values of the muscle sensor.
#define THRESHOLD 900

//Pin number where the sensor is connected. (Analog 0)
#define EMG_PIN A0

//Pin number where the servo motor is connected. (Digital PWM 3)
#define PNR 3
//#define Middle 5
//#define Index 6
//#define Thumb 9

//Define Servo motor
Servo Servo_1;
//Servo Servo_2;
//Servo Servo_3;
//Servo Servo_4;

/*-------------------------------- void setup ------------------------------------------------*/

void setup(){
  //BAUDRATE set to 115200, remember it to set monitor serial properly. 
  //Used this Baud Rate and "NL&CR" option to visualize the values correctly.
  Serial.begin(115200);
    pinMode(A0, INPUT);
      pinMode(3, OUTPUT);


  //Set servo motor to digital pin 3
  Servo_1.attach(PNR);
  //Servo_2.attach(Middle);
  //Servo_3.attach(Index);
  //Servo_4.attach(Thumb);
}

/*--------------------------------  void loop  ------------------------------------------------*/

void loop(){

  //The "Value" variable reads the value from the analog pin to which the sensor is connected.
  int value = analogRead(EMG_PIN);

  //If the sensor value is GREATER than the THRESHOLD, the servo motor will turn to 170 degrees.
  if(value > THRESHOLD){
    Servo_1.write(170);
    //Servo_2.write(170);
    //Servo_3.write(170);
    //Servo_4.write(170);
  }

  //If the sensor is LESS than the THRESHOLD, the servo motor will turn to 10 degrees.
  else{
    Servo_1.write(10);
    //Servo_2.write(10);
    //Servo_3.write(10);
    //Servo_4.write(10);
  }

  //You can use serial monitor to set THRESHOLD properly, comparing the values shown when you open and close your hand.
  delay(500);
  Serial.println(value);
  
}
  
