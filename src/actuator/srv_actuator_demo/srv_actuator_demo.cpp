/*
 * srv_actuator_demo.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: User
 */

#include "srv_actuator_demo.h"

#include "Arduino.h"

#include "../srv_actuator/srv_actuator.h"
#include "../dd_realy/dd_relay.h"
#include "../dd_servo/dd_servo.h"
#include "../dd_dcmotor/dd_dcmotor.h"


extern actType actList[ACT_NR_OF];

#define DELTA_ANGLE 5
#define DELTA_POWER 10
void srv_actuator_demo_setup() {
  Serial.begin(9600);
  RelaySetup();
  ServoSetup();
  MotorSetup();

}

void srv_actuator_demo_loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    int myAngle;
    int myPower;
    //    switch (cmd) {
    //      case 'q':
    //        RelaySetValue(RELAY_ON) ;
    //        Serial.println("Relay turns on");
    //        break;
    //      case 'a':
    //        RelaySetValue(RELAY_OFF) ;
    //        Serial.println("Relay turns off");
    //        break;
    //      case 'w':
    //
    //        myAngle = ServoGetAngle();
    //        myAngle += DELTA_ANGLE;
    //        ServoSetAngle(myAngle) ;
    //        Serial.println("Servo Motor step up");
    //        delay(200);
    //        break;
    //      case 's':
    //        myAngle = ServoGetAngle() ;
    //        myAngle -= DELTA_ANGLE;
    //        ServoSetAngle(myAngle);
    //        Serial.println("Servo Motor step down");
    //        break;
    //       case 'e':
    //
    //        myPower = MotorGetPower();
    //        myPower+=DELTA_POWER;
    //        MotorSetPower(myPower) ;
    //        Serial.print("Motor step up ");
    //        Serial.println(myPower);
    //        break;
    //      case 'd':
    //        myPower = MotorGetPower() ;
    //        myPower-=DELTA_POWER;
    //        MotorSetPower(myPower);
    //        Serial.print("Motor step down ");
    //        Serial.println(myPower);
    //        break;
    //
    //    }
    switch (cmd) {
      case 'q':
        ActSetValue(ACT_RELAY, RELAY_ON) ;
        Serial.println("Relay turns on");
        break;
      case 'a':
        ActSetValue(ACT_RELAY, RELAY_OFF) ;
        Serial.println("Relay turns off");
        break;
      case 'w':

        myAngle = ServoGetAngle();
        myAngle += DELTA_ANGLE;
        ServoSetAngle(myAngle) ;
        Serial.println("Servo Motor step up");
        break;
      case 's':
        myAngle = ServoGetAngle() ;
        myAngle -= DELTA_ANGLE;
        ServoSetAngle(myAngle);
        Serial.println("Servo Motor step down");
        break;
      case 'e':

        myPower = MotorGetPower();
        myPower += DELTA_POWER;
        MotorSetPower(myPower) ;
        Serial.print("Motor step up ");
        Serial.println(myPower);
        break;
      case 'd':
        myPower = MotorGetPower() ;
        myPower -= DELTA_POWER;
        MotorSetPower(myPower);
        Serial.print("Motor step down ");
        Serial.println(myPower);
        break;

    }
    for (int i = 0; i < ACT_NR_OF; i++) {
      char * paramName = ActGetParamName(i);
      Serial.print(paramName);
      Serial.print(": ");

      float value = ActGetValue(i);
      Serial.print(value);

      char * unit = ActGetUnit(i);
      Serial.print(" ");
      Serial.print(unit);
      Serial.print(" , ");
    }

  }

}
