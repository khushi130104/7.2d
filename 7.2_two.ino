#include <VirtualWire.h>
#include <VirtualWire_Config.h>

char t;
char *data;
// int speed;

void setup ()
{
  pinMode (4, OUTPUT); 
  pinMode (5, OUTPUT); 
  pinMode (6, OUTPUT); 
  pinMode (7, OUTPUT); 
  Serial.begin(9600);

  vw_set_tx_pin (3);
  vw_setup (2000);

}

void loop()
{

  if(Serial.available())
  {
    t = Serial.read();
    // Serial.println(t);

    if(t == 'F')
    {
      data="f";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      forward();
      Serial.println(data);
      
    }
    else if (t =='G')
    {
      data="g";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      backward();
      Serial.println(data);
    }
    else if(t == 'L') 
    {
      data="l";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      left();
      Serial.println(data);
    }
    else if(t == 'R') 
    {
      data="r";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      right();
      Serial.println(data);
    }
    else if(t == 'S') 
    {
      data="s";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      stop();
      Serial.println(data);
    }
  }
}
void forward() {
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
}
void backward() {
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
}
void right() {
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
}
void left() {
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
}
void stop() {
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
}
