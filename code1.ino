#define BLYNK_PRINT Serial

#include <Stepper.h>

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>



char auth[] = "Blynk Auth Token";

char ssid[] = "your ssid";

char pass[] = "wifi password";



// change this to fit the number of steps per revolution

const int stepsPerRevolution = 200; 


Stepper myStepper(stepsPerRevolution, 14, 12, 13, 15);


int xVal=512;

void setup() {

   
   Serial.begin(9600);

   Blynk.begin(auth, ssid, pass);

}

void loop() {

  

 Blynk.run();



  if( (xVal < 500)  ){

     myStepper.step(1);

     delayMicroseconds(3000);

  }else if( xVal > 550){

     myStepper.step(-1);

     delayMicroseconds(3000);

  }



  

}

BLYNK_WRITE(V1)

{

  xVal = param[0].asInt();

 // int y = param[1].asInt();    

}

BLYNK_WRITE(V2)

{

   if( param.asInt() == 1){

        xVal = 0;

   }else{

        xVal = 512;

   }

}

BLYNK_WRITE(V3)

{

   if( param.asInt() == 1){

        xVal = 1000;

   }else{

        xVal = 512;

   }

}
