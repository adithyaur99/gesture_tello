
#include<Wire.h>

const int MPU_addr=0x68;
int16_t axis_X,axis_Y,axis_Z;

int minVal=265;
int maxVal=402;

double x;
double y;
double z;
 


void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);
  axis_X=Wire.read()<<8|Wire.read();
  axis_Y=Wire.read()<<8|Wire.read();
  axis_Z=Wire.read()<<8|Wire.read();
    int xAng = map(axis_X,minVal,maxVal,-90,90);
    int yAng = map(axis_Y,minVal,maxVal,-90,90);
    int zAng = map(axis_Z,minVal,maxVal,-90,90);

       x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
       y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
       z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);
char c;
      if((x>30)&&(x<100))
    c='L';
    else if((x<330)&&(x>250))
    c='R';
    else if((y>30)&&(y<100))
    c='F';
    
    else if((y<330)&&(y>250))
    c='B';
    else c='S';
    Serial.println(c);
    delay(200);
}
