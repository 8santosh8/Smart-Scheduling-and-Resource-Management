const int MIC = 0; //the microphone amplifier output is connected to pin A0
int adc;
int dB, PdB; //the variable that will hold the value read from the microphone each time
int a[25];

unsigned long previousMillis = 0;

const long interval = 100;

int threshold=500;

void setup() {
Serial.begin(115200); //sets the baud rate at 9600 so we can check the values the microphone is obtaining on the Serial Monitor
pinMode(3, OUTPUT);
  
}

void loop(){

 //Store the previous of dB here
  
//adc= analogRead(MIC); //Read the ADC value from amplifer 
//Serial.println(adc);
//Serial.println (adc);//Print ADC for initial calculation 
//dB = (adc+83.2073) / 11.003; //Convert ADC value to dB using Regression values

/*if(dB>90.29)
{
  Serial.println (dB);
}*/

//int adc=analogRead(MIC);
//Serial.println(adc);

int i=0;


while(i<25)
{
  adc=analogRead(MIC);
  a[i]=adc;
  i++;
  }

int   avg=0;
for(int j=0;j<25;j++)
{
  avg=avg+a[j];
  }


 avg=avg/25;




 i=0;


while(i<25)
{
  adc=analogRead(MIC);
  a[i]=adc;
  i++;
  }

int   avg2=0;
for(int j=0;j<25;j++)
{
  avg2=avg2+a[j];
  }


 avg2=avg2/25;



    i=0;


    while(i<25)
    {
      adc=analogRead(MIC);
      a[i]=adc;
      i++;
    }

    int   avg3=0;
    for(int j=0;j<25;j++)
    {
        avg3=avg3+a[j];
     }


      avg3=avg3/25;
  int   avg4=(avg+avg2+avg3)/3;
 

//int adc=analogRead(MIC);
if(avg4>550)
{
    unsigned long pmillis=millis();
    while(avg4>threshold) 
    {
      Serial.println("Loud Sound");
         i=0;


        while(i<25)
        {
            adc=analogRead(MIC);
            a[i]=adc;
            i++;
         }

          avg=0;
        for(int j=0;j<25;j++)
        {
            avg=avg+a[j];
        }

           avg=avg/25;

          i=0;

         while(i<25)
          {
                adc=analogRead(MIC);
                a[i]=adc;
                i++;
           }

             avg2=0;
          for(int j=0;j<25;j++)
          {
            avg2=avg2+a[j];
          }
          
            avg2=avg2/25;

          i=0;


            while(i<25)
            {
              adc=analogRead(MIC);
              a[i]=adc;
              i++;
            }

              avg3=0;
            for(int j=0;j<25;j++)
            {
              avg3=avg3+a[j];
            }


            avg3=avg3/25;
            
            avg4=(avg+avg2+avg3)/3;

            Serial.println(avg4);
 
    }
    unsigned long cmillis=millis();

    if(cmillis-pmillis<interval)
    {
      Serial.println("Gunshot detected");
      }
    

}

}
