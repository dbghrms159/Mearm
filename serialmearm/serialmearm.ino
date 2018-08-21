#include <Servo.h>                 //Servo include
Servo landr;
Servo fandb;
Servo cat;
Servo uandd;
int x= 90, y = 90 , up = 90;           //angle default
bool x_y[4]= {false,false,false,false};  
bool u_d[2]= {false,false};
bool cats = false;

void setup() {
  // put your setup code here, to run once:

  cat.attach(2);                    //Servo pin D2
  landr.attach(3);                  //Servo pin D3
  uandd.attach(4);                 //Servo pin D4
  fandb.attach(5);                 //Servo pin D5
  Serial.begin(9600);              //Serial 9600
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available()>0){
      int a = Serial.read();
      if(a == 7)  cats = !cats;
      if(a == 0){
        //x -= 5;
        x_y[0] = true;
        x_y[1] = false;
        x_y[2] = false;
        x_y[3] = false;
      }else if(a == 4){
        //x += 5;
        x_y[0] = false;
        x_y[1] = true;
        x_y[2] = false;
        x_y[3] = false;                
      }else if(a == 2){
        //y -= 5;
        x_y[0] = false;
        x_y[1] = false;
        x_y[2] = true;
        x_y[3] = false;  
      }else if(a == 6){
        //y += 5;
        x_y[0] = false;
        x_y[1] = false;
        x_y[2] = false;
        x_y[3] = true; 
      }else
      {
        x_y[0] = false;
        x_y[1] = false;
        x_y[2] = false;
        x_y[3] = false; 
      }

      

      if(a == 9){
        u_d[0] = true;
        u_d[1] = false;
      }else if(a == 10){
        u_d[0] = false;
        u_d[1] = false;
      }else if(a == 11){
        u_d[0] = false;
        u_d[1] = true;
      }
  }

  if(x_y[0] && x > 0)  x -= 1;
  if(x_y[1] && x < 180) x += 1;
  if(x_y[2] && y <= 180) y -= 1;
  if(x_y[3] && y >= 0) y += 1;
  
  if(cats){
    cat.write(120);
  
  }
  else if(!cats){
    cat.write(75);
  }

  if(u_d[1] && up > 0 ) up -= 1;
  if(u_d[0] && up < 180) up += 1;

  landr.write(x);
  fandb.write(y);
  uandd.write(up);
  delay(50);
}

