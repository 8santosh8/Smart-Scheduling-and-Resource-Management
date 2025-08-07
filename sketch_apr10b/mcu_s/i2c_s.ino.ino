#include <Wire.h>
char t[]="c";
int pin1=2;
void setup() {
 pinMode(pin1,INPUT);
 Wire.begin(8);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent); /* register receive event */
 Wire.onRequest(requestEvent); /* register request event */
 Serial.begin(115200);
 /* start serial for debug */
}

void loop() {
 delay(100);
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
 while (0 <Wire.available()) {
    char c = Wire.read();      /* receive byte as a character */
    //Serial.print(c);           /* print the character */
  }
 Serial.println();             /* to newline */
}

// function that executes whenever data is requested from master
void requestEvent() {
  int x=digitalRead(pin1);
  Serial.print(x);  
  if(x==HIGH)
  {
   char c=Serial.read();
   c="1";
   Wire.write(c);  /*send string on request */
   
  }
}
