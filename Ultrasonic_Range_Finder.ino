#include <LiquidCrystal.h>
#include <Ultrasonic.h> //https://github.com/ErickSimoes/Ultrasonic

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int in = 10;
const int out = 13;

Ultrasonic ultrasonic(10,13);// ultrasonic(IN,OUT);

void setup() {
  // put your setup code here, to run once:
  
  //Code for LCD
  lcd.begin(16,2);
  lcd.print("Range Finder");

  //Code for Ultrasonic Sensor
    //Starts up reading in the output and input from the serial tab
 /* Serial.begin(9600);
  pinMode(out,OUTPUT);
  pinMode(in,INPUT);
  */
}

////////////////////////////////
//Displays results on the LCD //
//module.                      //
////////////////////////////////

void loop() {
  // put your main code here, to run repeatedly:
  long distance;
  //Code for LCD
  lcd.setCursor(0,1);//sets cursor to second half of LCD
  //lcd.print(millis()/1000);

  //Code for Ultrasonic Sensor
  //Programming the Sensor to run:
  /*
  long dur;
  long dis;
  
  digitalWrite(out,LOW);
  delayMicroseconds(2);

  digitalWrite(out,HIGH);
  delayMicroseconds(10);
  digitalWrite(out,LOW);
  
  //Prints out results in the serial tab
  //Recieves pulse and converts to a value that is then...
  dur = pulseIn(in,HIGH);

  //...readable from the serial tab
  //Serial.println(String(dur));
  */
  
  //Test code for printing Ultrasonic sensor results
  //Using <Ultrasonic.h>: 
  distance = ultrasonic.read(INC);// reads output from sensor-in INCHES/ default is Centimeters
  lcd.print(distance);//prints out distance onto LCD
  //delay(100);
  ultrasonic.setTimeout(40000UL); //30 microseconds (40ms/6.8m range)
  /*waittime before allowing library to lockup
  if the return pulse takes too long.*/


}
