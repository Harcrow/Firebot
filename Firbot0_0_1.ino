/*
Beta code for checking IR Sensors and basic servo interaction

Motor code will have to  be altered after the switch away from Servos
Test now is using 

 */


#include <Servo.h>

//Creating servo objects
Servo servo_Left;
Servo servo_Right;

//Setting IR Input pins
const int IR_Sensor_Left = A8;
const int IR_Sensor_Right = A9;
const int IR_Sensor_Front = A10;
const int IR_Sensor_Rear = A11;

//IR Values
int IR_Sensor_Right_Value = 0;
int IR_Sensor_Left_Value = 0;
int IR_Sensor_Rear_Value = 0;        
int IR_Sensor_Front_Value = 0;        

//Servo position values
//for servos, the angle normally indicates position
//for continuous rotation, you only need the 3 integers indicated.
int stopped = 90;
int forward = 0;
int reverse = 180;


void setup()
{
  //attaching servos to specific PWM pins
  servo_Left.attach(8);
  servo_Right.attach(9);
  
  
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  
}

void loop() 

{
  // read the analog in value:
  IR_Sensor_Right_Value = analogRead(IR_Sensor_Right);
  IR_Sensor_Rear_Value = analogRead(IR_Sensor_Rear);
  IR_Sensor_Front_Value = analogRead(IR_Sensor_Front);
  IR_Sensor_Left_Value = analogRead(IR_Sensor_Left);  // print the results to the serial monitor:
  
  //Should detect if something is immediately in front of the Bot and there
  //is cleareance to the left, initiating a pivoted left hand turn
  if(IR_Sensor_Front_Value >= 650 &&  IR_Sensor_Left_Value >=500)
    {
      servo_Left.write(reverse);
      servo_Right.write(stopped);
      delay (1000);
    }
      

  
  
  //Serial checks for values
  Serial.print("Rear Sensor Value = " );
  Serial.println(IR_Sensor_Rear_Value);
  Serial.print("Front Sensor Value = ");
  Serial.println(IR_Sensor_Front_Value);
  Serial.print("Left Sensor Value = ");
  Serial.println(IR_Sensor_Left_Value);
  Serial.print("Right Sensor Value = ");
  Serial.println(IR_Sensor_Right_Value);
  

 //Wait for 500 ms
  delay(500);
  
  //It's really starting to snow...
}
