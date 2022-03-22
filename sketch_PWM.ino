#include<Servo.h>

int Ch01 = 3;
int Ch06 = 4;
int servoPin = 9;

Servo servoObj;

long duration;
long MAX = 1500,MIN = 1500;

void setup() {
  // put your setup code here, to run once:
  pinMode(Ch01,INPUT);
  pinMode(Ch06,INPUT);
  Serial.begin(9600);
  
  servoObj.attach(servoPin);

  duration = pulseIn(Ch06,HIGH);

  while(duration > 1500) // calibration
  {
    duration = pulseIn(Ch01,HIGH);
    MAX = MAX>duration?MAX:duration;
    MIN = MIN<duration?MIN:duration;
    duration = pulseIn(Ch06,HIGH);
  }
}

void loop() {
  
  // put your main code here, to run repeatedly:
  duration = pulseIn(Ch01,HIGH);
  Serial.println(duration);
  Serial.print("MAX= ");
  Serial.print(MAX);
  Serial.print(" MIN= ");
  Serial.println(MIN);
  ControlServo(MAX,MIN,duration);

}

void ControlServo(long max, long min,long dutycycle)
{
  int pos = map(dutycycle,min,max,0,180);
  servoObj.write(pos);
}
