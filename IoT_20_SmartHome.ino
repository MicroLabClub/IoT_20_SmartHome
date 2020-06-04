#include "Arduino.h"
//The setup function is called once at startup of the sketch

#include "src/actuator/srv_actuator_demo/srv_actuator_demo.h"

void setup()
{
// Add your initialization code here
	srv_actuator_demo_setup();
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	srv_actuator_demo_loop();
}
