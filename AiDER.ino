/*
 * WRITING AID FOR DISABLED 
 * SOORAJ P S | AISWARYA R L | A S ATHIRA | ADITHYA T S | AMRUTHAPRIYA B S
 * COLLEGE OF ENGINEERING ATTINGAL
*/

//Initalizing libraries
#include <Arduino.h>
#include <ESP32_Servo.h>
#include "BasicStepperDriver.h"
#include "SyncDriver.h"
#include <WiFi.h>

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
// X motor
#define DIR_X 26
#define STEP_X 27
// Y motor
#define DIR_Y 25
#define STEP_Y 33
// If microstepping is set externally, make sure this matches the selected mode
// 1=full step, 2=half step etc.
#define MICROSTEPS 1

int liftPin = 12; //Lifting Servo pin

//WiFi connection SSID & Password
const char* ssid     = "YOYO";
const char* password = "haecceal1519";

Servo lift1; //Creating servo library object

// 2-wire basic config, microstepping is hardwired on the driver
// Other drivers can be mixed and matched but must be configured individually
BasicStepperDriver stepperX(MOTOR_STEPS, DIR_X, STEP_X);
BasicStepperDriver stepperY(MOTOR_STEPS, DIR_Y, STEP_Y);
SyncDriver controller(stepperX, stepperY);

WiFiServer server(80); //Creating WiFi server library object

void setup()
{
    Serial.begin(115200); //Begin serial communication 
    lift1.attach(liftPin); //Initialize servo
    stepperX.begin(120, MICROSTEPS); //Initialize stepper
    stepperY.begin(120, MICROSTEPS);
    delay(10);

    // We start by connecting to a WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.disconnect();
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    server.begin();

    lift1.write(170);
    delay(1000);
}

int value = 0;
void loop(){
 WiFiClient client = server.available();   // listen for incoming clients
  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 5 off.<br>");
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
        //Serial.println(currentLine);
        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /A")) 
        {
          wrA();
        }
        if (currentLine.endsWith("GET /B")) 
        {
          wrB();
        }
        if (currentLine.endsWith("GET /hello")) 
        {
          wrH();
          wrE();
          wrL();
          wrL();
          wrO();
        }
        if (currentLine.endsWith("GET /Google")) 
        {
          wrG();
          wrO();
          wrO();
          wrG();
          wrL();
          wrE();
        }
        if (currentLine.endsWith("GET /God")) 
        {
          wrG();
          wrO();
          wrD();
        }
        if (currentLine.endsWith("GET /above")) 
        {
          wrUP();
        }
        if (currentLine.endsWith("GET /down")) 
        {
          wrDOWN();
        }
        if (currentLine.endsWith("GET /left")) 
        {
          wrLEFT();
        }
        if (currentLine.endsWith("GET /right")) 
        {
          wrRIGHT();
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}

void wrA()
{
  lift1.write(120);
  delay(500);
  controller.rotate(0*15, 40*5);
  delay(10);
  controller.rotate(-5*15, 0*5);
  delay(10);
  controller.rotate(0*15, -20*5);
  delay(10);
  controller.rotate(5*15, 0*5);
  delay(10);
  controller.rotate(-5*15, 0*5);
  delay(10);
  controller.rotate(0*15, -20*5);
  delay(10);
  lift1.write(170);
  delay(500);
  controller.rotate(-3*15, 0*5);
  delay(10);
}

void wrB()
{
  lift1.write(120);
  delay(500);
  controller.rotate(0*15, 40*5);
  delay(10);
  controller.rotate(-4*15, 0*5);
  delay(10);
  controller.rotate(-1*15, -3*5);
  delay(10);
  controller.rotate(0*15, -18*5);
  delay(10);
  controller.rotate(1*15, -3*5);
  delay(10);
  controller.rotate(5*15, 0*5);
  delay(10);
  controller.rotate(-5*15, 0*5);
  delay(10);
  controller.rotate(-1*15, -3*5);
  delay(10);
  controller.rotate(0*15, -18*5);
  delay(10);
  controller.rotate(1*15, -3*5);
  delay(10);
  controller.rotate(4*15, 0*5);
  delay(10);
  lift1.write(170);
  delay(500);
  controller.rotate(-8*15, -0*5);
  delay(10);
}

void wrC()
{
  controller.rotate(0*15, 40*5);
  delay(10);
  controller.rotate(-5*15, 0*5);
  delay(10);
  lift1.write(120);
  delay(500);
  controller.rotate(5*15, 0*5);
  delay(10);
  controller.rotate(0*15, -40*5);
  delay(10);
  controller.rotate(-5*15, 0*5);
  delay(10);
  lift1.write(170);
  delay(500);
  controller.rotate(-3*15, -0*5);
  delay(10);
}

void wrD()
{
  lift1.write(120);
  delay(500);
  controller.rotate(0*15, 40*5);
  delay(10);
  controller.rotate(-4*15, 0*5);
  delay(10);
  controller.rotate(-1*15, -10*5);
  delay(10);
  controller.rotate(0*15, -20*5);
  delay(10);
  controller.rotate(1*15, -10*5);
  delay(10);
  controller.rotate(4*15, 0*5);
  delay(10);
  lift1.write(170);
  delay(500);
  controller.rotate(-8*15, -0*5);
  delay(10);
}

void wrE()
{  
  controller.rotate(-5*15, 0*5);
  delay(10);
  lift1.write(120);
  delay(500);
  controller.rotate(5*15, 0*5);
  delay(10);
  controller.rotate(0*15, 20*5);
  delay(10);
  controller.rotate(-5*15, 0*5);
  delay(10);
  controller.rotate(5*15, 0*5);
  delay(10); 
  controller.rotate(0*15, 20*5);
  delay(10);
  controller.rotate(-5*15, 0*5);
  delay(10);
  lift1.write(170);
  delay(500);  
  controller.rotate(0*15, -40*5);
  delay(10);
  controller.rotate(-3*15, -0*5);
  delay(10);  
}

void wrF()
{  
  controller.rotate(0*15, 40*5);
  delay(10);
  controller.rotate(-5*15, 0*5);
  delay(10);
  lift1.write(120);
  delay(500);
  controller.rotate(5*15, 0*5);
  delay(10);
  controller.rotate(0*15, -20*5);
  delay(10);
  controller.rotate(-5*15, 0*5);
  delay(10);
  controller.rotate(5*15, 0*5);
  delay(10); 
  controller.rotate(0*15, -20*5);
  delay(10);
  lift1.write(170);
  delay(500);  
  controller.rotate(-8*15, -0*5);
  delay(10);  
}

void wrG()
{  
  controller.rotate(0*15, 40*5);
  delay(10);
  controller.rotate(-5*15, 0*5);
  delay(10);
  lift1.write(120);
  delay(500);
  controller.rotate(5*15, 0*5);
  delay(10);
  controller.rotate(0*15, -40*5);
  delay(10);
  controller.rotate(-5*15, 0*5);
  delay(10);
  controller.rotate(0*15, 10*5);
  delay(10);
  controller.rotate(2*15, 0*5);
  delay(10);
  lift1.write(170);
  delay(500);
  controller.rotate(0*15, -10*5);
  delay(10);  
  controller.rotate(-5*15, -0*5);
  delay(10);  
}

void wrH()
{
  lift1.write(120);
  delay(500);
  controller.rotate(0*15, 40*5);
  delay(10);
  controller.rotate(0*15, -20*5);
  delay(10);
  controller.rotate(-5*15, 0*5);
  delay(10);
  controller.rotate(0*15, 20*5);
  delay(10);
  controller.rotate(0*15, -40*5);
  delay(10);
  lift1.write(170);
  delay(500);
  controller.rotate(-3*15, -0*5);
  delay(10);
}  

void wrI()
{
  controller.rotate(0*15, 40*5);
  delay(10);
  lift1.write(120);
  delay(500);
  controller.rotate(-5*15, 0*5);
  delay(10);
  controller.rotate(3*15, 0*5);
  delay(10);
  controller.rotate(0*15, -40*5);
  delay(10);
  controller.rotate(3*15, 0*5);
  delay(10);
  controller.rotate(-5*15, 0*5);
  delay(10);
  lift1.write(170);
  delay(500);
  controller.rotate(-3*15, -0*5);
  delay(10);
}

void wrJ()
{
  controller.rotate(0*15, 40*5);
  delay(10);
  lift1.write(120);
  delay(500);
  controller.rotate(-5*15, 0*5);
  delay(10);
  controller.rotate(3*15, 0*5);
  delay(10);
  controller.rotate(0*15, -40*5);
  delay(10);
  controller.rotate(2*15, 0*5);
  delay(10);
  lift1.write(170);
  delay(500);
  controller.rotate(-8*15, -0*5);
  delay(10);
}

void wrK()
{
  controller.rotate(0*15, 40*5);
  delay(10);
  lift1.write(120);
  delay(500);
  controller.rotate(-5*15, 0*5);
  delay(10);
  controller.rotate(3*15, 0*5);
  delay(10);
  controller.rotate(0*15, -40*5);
  delay(10);
  controller.rotate(2*15, 0*5);
  delay(10);
  lift1.write(170);
  delay(500);
  controller.rotate(-8*15, -0*5);
  delay(10);
}

void wrL()
{
  controller.rotate(0*15, 40*5);
  delay(10);
  lift1.write(120);
  delay(500);
  controller.rotate(0*15, -40*5);
  delay(10);
  controller.rotate(-5*15, 0*5);
  delay(10);
  lift1.write(170);
  delay(500);
  controller.rotate(-3*15, -0*5);
  delay(10);
}

void wrO()
{
  lift1.write(120);
  delay(500);
  controller.rotate(0*15, 40*5);
  delay(10);
  controller.rotate(-5*15, 0*5);
  delay(10);
  controller.rotate(0*15, -40*5);
  delay(10);
  controller.rotate(5*15, 0*5);
  delay(10);
  lift1.write(170);
  delay(500);
  controller.rotate(-8*15, -0*5);
  delay(10);
}

void wrDOWN()
{
  controller.rotate(0*15, -50*5);
  delay(10);
}
void wrUP()
{
  controller.rotate(0*15, 50*5);
  delay(10);
}

void wrRIGHT()
{
  controller.rotate(-15*15, 0*5);
  delay(10);
}

void wrLEFT()
{
  controller.rotate(15*15, 0*5);
  delay(10);
}

