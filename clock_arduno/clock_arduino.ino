#include <Servo.h>
extern volatile unsigned long timer0_overflow_count;    
int mOnes=2;
int mD=4;
int hOnes=9;
int hD=1;
unsigned long loopstart=0;
unsigned long nextEvent=loopstart+60000;
Servo minutesOnes;
Servo minutesDec;
Servo hourOnes;
Servo hourDec;
void setup() {
  // put your setup code here, to run once:
  minutesOnes.attach(5);
  minutesDec.attach(6);
  hourOnes.attach(9);
  hourDec.attach(10);
  minutesOnes.write(20*mOnes);
  minutesDec.write(20*mD);  
  hourOnes.write(20*hOnes);
  hourDec.write(20*hD);  
  Serial.begin(9600);

  }
void loop() {

  timer0_overflow_count=0;
  if(loopstart==0) 
  {
    loopstart=millis();
    Serial.print("Waiting for 60 seconds...");
    Serial.println(loopstart);
    nextEvent=loopstart+60000;
  }

  if(millis()>=nextEvent)
  {
    mOnes++;
    if(mOnes>9)
    {
      mD++;
      mOnes=0;
    }
    if(mD>5)
    {
      mD=0;
      hOnes++;
    }
    if(hOnes>9)
    {
      hD++;
      hOnes=0;
    }
    if(hD>=2 && hOnes==4)
    {
      hD=0;
      hOnes=0;
    }
    update();
    loopstart=0;
  }
  if (Serial.available() > 0) 
  {
      Serial.print("Waiting for serial...");
      // Read the incoming dat
      hD = Serial.parseInt();
      hOnes = Serial.parseInt();
      mD = Serial.parseInt();
      mOnes = Serial.parseInt();
      update();
      loopstart=0;
  }
}
void update()
{
 Serial.print("Updated mOnes: ");
      Serial.println(mOnes);
      Serial.print("Updated mD: ");
      Serial.println(mD);
      Serial.print("Updated hOnes: ");
      Serial.println(hOnes);
      Serial.print("Updated hD: ");
      Serial.println(hD);
      minutesOnes.write(20*mOnes);
      delay(100);
      minutesDec.write(20*mD);
      delay(100);
      hourOnes.write(20*hOnes);
      delay(100);
      hourDec.write(20*hD);
      Serial.println("End of loop.");
}
