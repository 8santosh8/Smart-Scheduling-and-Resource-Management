const int MIC = A0; //the microphone amplifier output is connected to pin A0
const int MIC1=A1;
const int MIC2=A2;

int adc,adc1,adc2;
int dB, PdB; //the variable that will hold the value read from the microphone each time
int a[25];
int b[25];
int c[25];

unsigned long previousMillis = 0;

const long interval = 100;

int threshold=500;



#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 3; 
// Create a servo object 
Servo Servo1; 
int opt=0;


void setup() {
Serial.begin(115200); //sets the baud rate at 9600 so we can check the values the microphone is obtaining on the Serial Monitor
pinMode(3, OUTPUT);
Servo1.attach(servoPin); 
}

void loop(){


int i=0;


while(i<25)
{
  adc=analogRead(MIC);
  a[i]=adc;
  
  adc1=analogRead(MIC1);
  b[i]=adc1;

  adc2=analogRead(MIC2);
  c[i]=adc2;
  
  i++;
  }

int   avg=0,avgb=0,avgc=0;

for(int j=0;j<25;j++)
{
  avg=avg+a[j];
  avgb=avgb+b[j];
  avgc=avgc+c[j];
  }


 avg=avg/25;
 avgb=avgb/25;
 avgc=avgc/25;




 i=0;


while(i<25)
{
  adc=analogRead(MIC);
  a[i]=adc;
  
  adc1=analogRead(MIC1);
  b[i]=adc1;

  adc1=analogRead(MIC2);
  c[i]=adc1;
  
  i++;
  }


int   avg2=0,avgb2=0,avgc2=0;

for(int j=0;j<25;j++)
{
  avg2=avg2+a[j];
  avgb2=avgb2+b[j];
  avgc2=avgc2+c[j];
  }


 avg2=avg2/25;
 avgb2=avgb2/25;
 avgc2=avgc2/25;



    i=0;

while(i<25)
{
  adc=analogRead(MIC);
  a[i]=adc;
  
  adc1=analogRead(MIC1);
  b[i]=adc1;

  adc2=analogRead(MIC2);
  c[i]=adc2;
  
  i++;
  }


int   avg3=0,avgb3=0,avgc3=0;

for(int j=0;j<25;j++)
{
  avg3=avg3+a[j];
  avgb3=avgb3+b[j];
  avgc3=avgc3+c[j];
  }


 avg3=avg3/25;
 avgb3=avgb3/25;
 avgc3=avgc3/25;



    
      i=0;

while(i<25)
{
  adc=analogRead(MIC);
  a[i]=adc;
  
  adc1=analogRead(MIC1);
  b[i]=adc1;

  adc2=analogRead(MIC2);
  c[i]=adc2;
  
  i++;
  }


int   avg4=0,avgb4=0,avgc4=0;

for(int j=0;j<25;j++)
{
  avg4=avg4+a[j];
  avgb4=avgb4+b[j];
  avgc4=avgc4+c[j];
  }


 avg4=avg4/25;
 avgb4=avgb4/25;
 avgc4=avgc4/25;


           i=0;


while(i<25)
{
  adc=analogRead(MIC);
  a[i]=adc;
  
  adc1=analogRead(MIC1);
  b[i]=adc1;

  adc2=analogRead(MIC2);
  c[i]=adc2;
  
  i++;
  }


int   avg5=0,avgb5=0,avgc5=0;

for(int j=0;j<25;j++)
{
  avg5=avg5+a[j];
  avgb5=avgb5+b[j];
  avgc5=avgc5+c[j];
  }


 avg5=avg5/25;
 avgb5=avgb5/25;
 avgc5=avgc5/25;
      
  int   avg6=(avg+avg2+avg3+avg4+avg5)/5;

  int   avgb6=(avgb+avgb2+avgb3+avgb4+avgb5)/5;

  int   avgc6=(avgc+avgc2+avgc3+avgc4+avgc5)/5;
 

//int adc=analogRead(MIC);
if(avg6>500||avgb6>500||avgc6>500)
{
    Serial.println("Loudsound");

    Serial.println(avg6);
    Serial.println(avgb6);
    Serial.println(avgc6);

    if(avgb6>avg6 && avgb6>avgc6 )
      {
      Serial.println("right");
      opt=3;
      }
    if(avg6>avgb6 && avg6>avgc6 )
      {
      Serial.println("middle");
      opt=2;
      }
     
    if(avgc6>avg6 && avgc6>avgb6 )
      {
      Serial.println("left");
      opt=1;
      }
      

}
if(opt!=0)
  {
    if(opt==1)
      Servo1.write(180);
    else if(opt==2)
      Servo1.write(90);
    else
      Servo1.write(0);
    delay(500);
    }
opt=0;

}
