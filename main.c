#include <Wire.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
char inchar; //Will hold the incoming character from the Serial Port.
int count = 0;
int relay1 = 2;
int relay2 = 3;
int relay3 = 5;
int relay4 = 4;
float tariff;
float units;
SoftwareSerial mySerial(7, 8);
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);
void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.print("WELCOME TO GSM");
    delay(200);
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT);
    pinMode(relay4, OUTPUT);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    Serial.print("pin state low\n");
    delay(3000);                 // give time for GSM module to register on network.
    Serial.println("AT+CMGF=1"); // set SMS mode to text
    delay(200);
    Serial.println("AT+CNMI=2,2,0,0,0"); // set module to send SMS data to serial out upon receipt
    delay(200);
}
void loop()
{
    int sensor = analogRead(A0);
    if (sensor < 1000)
    {
        count++;
        delay(500);
        Serial.print("count=");
        Serial.println(count);
        units = count / 3.2;
        Serial.print("units=");
        Serial.println(units);
    }
    if (units <= 50000)
    {
        tariff = units * 1.45;
    }
    else if (units > 50000 && units <= 100000)
    {
        tariff = units * 2.6;
    }
    else if (units > 100000 && units <= 200000)
    {
        tariff = units * 3.6;
    }
    else if (units > 200000 && units <= 250000)
    {
        tariff = units * 6.7;
    }
    else if (units > 250000 && units <= 300000)
    {
        tariff = units * 7.22;
    }
    else if (units > 301000 && units <= 400000)
    {
        tariff = units * 7.75;
    }
    else if (units > 400000 && units <= 500000)
    {
        tariff = units * 8.27;
    }
    else if (units > 500000)
    {
        tariff = units * 8.8;
    }
    //If @a1b1c1d1 comes as sms, all led's should light up.
    if (Serial.available() > 0)
    {
        inchar = Serial.read();
        if (inchar == '@')
        {
            delay(10);
            inchar = Serial.read();
            //first led
            if (inchar == 'a') //closed
            {
                delay(10);
                inchar = Serial.read();
                if (inchar == '0') //closed
                {
                    //digitalWrite(led1, LOW);
                    //delay(1000);
                    digitalWrite(relay1, HIGH);
                    Serial.print("Relay 1 LOW\n");
                    delay(1000);
                    Serial.print("Power OFF"); //the message you want to send
                    lcd.setCursor(1, 1);
                    lcd.print("L1 OFF");
                    delay(500);
                }
                else if (inchar == '1')
                {
                    //digitalWrite(led1, HIGH);
                    //delay(1000);
                    digitalWrite(relay1, LOW);
                    Serial.print("Relay 1 HIGH\n");
                    delay(1000);
                    Serial.print("Power ON");
                    lcd.setCursor(1, 1);
                    lcd.print("L1 ON");
                    delay(500);
                }
                delay(10);
                inchar = Serial.read();
                //Second led
                if (inchar == 'b') //closed
                {
                    delay(10);
                    inchar = Serial.read();
                    if (inchar == '0') //closed
                    {
                        //digitalWrite(led2, LOW);
                        //delay(1000);
                        digitalWrite(relay2, HIGH);
                        Serial.print("Relay 2 LOW\n");
                        delay(1000);
                        Serial.print("Power OFF"); //the message you want to send
                        lcd.setCursor(7, 1);
                        lcd.print("L2 OFF");
                        delay(500);
                    }
                    else if (inchar == '1')
                    {
                        //digitalWrite(led2, HIGH);
                        //delay(1000);
                        digitalWrite(relay2, LOW);
                        Serial.print("Relay 2 HIGH\n");
                        delay(1000);
                        Serial.print("Power ON");
                        lcd.setCursor(7, 1);
                        lcd.print("L2 ON");
                        delay(500);
                    }
                    delay(10);
                    inchar = Serial.read();
                    //third led
                    if (inchar == 'c') //closed
                    {
                        delay(10);
                        inchar = Serial.read();
                        if (inchar == '0') //closed
                        {
                            //digitalWrite(led3, LOW);
                            // delay(1000);
                            digitalWrite(relay3, HIGH);
                            Serial.print("Relay 3 LOW\n");
                            delay(1000);
                            Serial.print("Power OFF"); //the message you want to send
                            lcd.setCursor(1, 1);
                            lcd.print("L3 OFF");
                            delay(500);
                        }
                        else if (inchar == '1')
                        {
                            //digitalWrite(led3, HIGH);
                            //delay(1000);
                            digitalWrite(relay3, LOW);
                            Serial.print("Relay 3 HIGH\n");
                            delay(1000);
                            Serial.print("Power ON");
                            lcd.setCursor(1, 1);
                            lcd.print("L3 ON");
                            delay(500);
                        }
                        delay(10);
                        inchar = Serial.read();
                        //fourth led
                        if (inchar == 'd') //closed
                        {
                            delay(10);
                            inchar = Serial.read();
                            if (inchar == '0') //closed
                            {
                                //digitalWrite(led4, LOW);
                                //delay(1000);
                                digitalWrite(relay4, HIGH);
                                Serial.print("Relay 4 LOW\n");
                                delay(1000);
                                Serial.print("Power OFF"); //the message you want to send
                                lcd.setCursor(1, 1);
                                lcd.print("L4 OFF");
                                delay(500);
                            }
                            else if (inchar == '1')
                            {
                                //digitalWrite(led4, HIGH);
                                //delay(1000);
                                digitalWrite(relay4, LOW);
                                Serial.print("Relay 4 HIGH\n");
                                delay(1000);
                                Serial.print("Power ON");
                                lcd.setCursor(1, 1);
                                lcd.print("L4 ON");
                                delay(500);
                            }
                            delay(10);
                            inchar = Serial.read();
                            //fourth led
                            if (inchar == 'e') //closed
                            {
                                delay(10);
                                inchar = Serial.read();
                                if (inchar == '0') //closed
                                {
                                    if (mySerial.available())
                                        Serial.write(mySerial.read());
                                    mySerial.print("AT+CMGF=1\r"); //Because we want to send the SMS in text mode
                                    delay(100);
                                    mySerial.println("AT+CNMI=2,2,0,0,0\r");
                                    mySerial.println("AT + CMGS = \"+919515306454\""); //send sms message, be careful need to
                                    //add a country code before the cell phone number
                                    delay(100);
                                    mySerial.print("units:");
                                    mySerial.println(units); //the content of the message
                                    mySerial.print("The current reading is:");
                                    mySerial.println(tariff); //the content of the message
                                    delay(100);
                                    mySerial.println((char)26); //the ASCII code of the ctrl+z is 26
                                    delay(100);
                                    mySerial.println();
                                    delay(1000);
                                    Serial.print("The current reading is:");
                                    Serial.print(tariff);
                                    Serial.println("Rs/-");
                                    lcd.setCursor(1, 0);
                                    lcd.print("units=");
                                    lcd.print(units);
                                    lcd.setCursor(9, 0);
                                    lcd.print("tariff=");
                                    lcd.print("Rs=");
                                    lcd.print(tariff);
                                }
                            }
                        }
                    }
                }
            }

            Serial.println("AT+CMGD=1,4"); //Delete all message
        }
    }
}
