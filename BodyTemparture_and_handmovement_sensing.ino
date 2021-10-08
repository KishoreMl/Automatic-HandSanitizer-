#include<Servo.h>
#include<Wire.h>
#include<LiquidCrystal.h>
#include<Adafruit_MLX90614.h>




const int rs = 0, en = 2, d4 = 4, d5 = 5, d6 = 6, d7 = 7, rw = 1;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


Adafruit_MLX90614 mlx= Adafruit_MLX90614();

Servo mot;
int risignal = A0;
int output;
int led_green = 11;
int led_red = 12;
int deg=0;
float temp;

void setup() {
mlx.begin();
lcd.begin(16,2);
lcd.clear();
lcd.home();
mot.attach(8);
pinMode(risignal,INPUT);
pinMode(led_green,OUTPUT);
pinMode(led_red,OUTPUT);
lcd.setCursor(0,0);
}

void loop() {


output=analogRead(risignal);

if(output<50)
{
lcd.setCursor(0,0);
lcd.print("Temp:");
lcd.print(mlx.readObjectTempC());
lcd.print("C");
delay(1500);
lcd.clear();

delay(1000);

if(mlx.readObjectTempC()<37.8)
{
digitalWrite(led_green,HIGH);
lcd.setCursor(0,0);
lcd.print("Normal");

delay(2500);
lcd.clear();
}
else if(mlx.readObjectTempC()>37.8)
{
digitalWrite(led_red,HIGH);
lcd.setCursor(0,0);
lcd.print("High Temp");

delay(2500);
lcd.clear();
}
else{
digitalWrite(led_green,LOW);
digitalWrite(led_red,LOW);
}

for(deg=45;deg<=345;deg++)
{
mot.write(deg);
delay(1);

}

for(deg=345; deg>=45;deg--)
{
mot.write(deg);
delay(1);

}

delay(4000);
}
else
{
digitalWrite(led_green,LOW);
digitalWrite(led_red,LOW);

}

}
