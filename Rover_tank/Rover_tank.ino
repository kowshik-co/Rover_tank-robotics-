//191-35-2774
#include <SoftwareSerial.h>// for bluetooth at any digital pin
SoftwareSerial bluetooth (10, 12);//RX, TX

const int MLa=6;//initiating left motor to pwm pin 6
const int MLb=3;//initiating left motor to pwm pin 3
const int MRa=9;//initiating right motor to pwm pin 9
const int MRb=7;//initiating right motor to pin 7

const int Lf = 5;//initiating front light to pin 5
const int Lb = 8;//initiating back light to pin 8

char data='S';// initiating a value for "STOP" (from app setting)

void forward(){
digitalWrite(MLa, HIGH);
digitalWrite(MLb, LOW);
digitalWrite(MRa, HIGH);
digitalWrite(MRb, LOW);
}
void backward(){
digitalWrite(MLa, LOW);
digitalWrite(MLb, HIGH);
digitalWrite(MRa, LOW);
digitalWrite(MRb, HIGH);
}
void carstop(){
digitalWrite(MLa, LOW);
digitalWrite(MLb, LOW);
digitalWrite(MRa, LOW);
digitalWrite(MRb, LOW);
}
void left(){
digitalWrite(MLa, LOW);
digitalWrite(MLb, LOW);
digitalWrite(MRa, HIGH);
digitalWrite(MRb, LOW);
}
void right(){
digitalWrite(MLa, HIGH);
digitalWrite(MLb, LOW);
digitalWrite(MRa, LOW);
digitalWrite(MRb, LOW);
}
void forwardLeft(){
analogWrite(MLa, 128);//using pwm decreasing rpm 50%
digitalWrite(MLb, LOW);
digitalWrite(MRa, HIGH);
digitalWrite(MRb, LOW);
}
void forwardRight(){
digitalWrite(MLa, HIGH);
digitalWrite(MLb, LOW);
analogWrite(MRa, 128);//using pwm decreasing rpm 50%
digitalWrite(MRb, LOW);
}
void backwardLeft(){
digitalWrite(MLa, LOW);
analogWrite(MLb, 128);//using pwm decreasing rpm 50%
digitalWrite(MRa, LOW);
digitalWrite(MRb, HIGH);
}
void backwardRight(){
digitalWrite(MLa, LOW);
digitalWrite(MLb, HIGH);
digitalWrite(MRa, LOW);
analogWrite(MRb, HIGH);
}
void frontLight(){
digitalWrite(Lf, HIGH);
digitalWrite(Lb, LOW);
}
void bottomLight(){
digitalWrite(Lf, LOW);
digitalWrite(Lb, HIGH);
}
void setup() {
bluetooth.begin(9600);// starting bluetooth communication
pinMode(MLa, OUTPUT); //setup all pin mode here
pinMode(MLb, OUTPUT);
pinMode(MRa, OUTPUT);
pinMode(MRb, OUTPUT);
pinMode(Lf, OUTPUT);
pinMode(Lb, OUTPUT);

digitalWrite(Lf, LOW); //led front default turn off
digitalWrite(Lb, LOW);//led back default turn off

carstop(); //car stop default

}
void loop() {
if(bluetooth.available()) // checking if there any command available
{
  data=bluetooth.read();//reading the data sent over bluetooth module
if (data == 'A')
{
  forward();//calling forward function
}
else if(data == 'B')
{
  backward(); //calling backward function
}
else if(data == 'C')
{
  left(); //calling left function
}
else if(data == 'D')
{
  right(); //calling right function
}
else if(data == 'E')
{
  carstop(); //calling stop function
}
else if(data == 'F')
{
  forwardLeft(); //calling forward left function
}
else if(data == 'G')
{
  forwardRight(); //calling forwardright function
}
else if(data == 'H')
{
  backwardLeft(); //calling backward left function
}
else if(data == 'I')
{
  backwardRight(); //calling backwardright function
}
else if(data == 'J')
{
  frontLight(); //calling front light on function
}
else if(data == 'K')
{
  bottomLight(); //calling backlighton function
}
else
{
  carstop();// calling function for stop
}
}
}
