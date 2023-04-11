// Chage These Credentials with your Blynk Template credentials
#define BLYNK_TEMPLATE_ID "TMPLwzjfqUb0"
#define BLYNK_TEMPLATE_NAME "Fire Detection"
#define BLYNK_AUTH_TOKEN "Kr6yTRGD7J_jcDEVzwCKx-5bolFg43Dz"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "DarkSoul"; // Change your Wifi/ Hotspot Name
char pass[] = "5698713245"; // Change your Wifi/ Hotspot Password

BlynkTimer timer;

#define fire 23
#define buzzer  14
int fire_Val = 1;

WidgetLED led(V1);

void setup() //Setup function - only function that is run in deep sleep mode
{
  Serial.begin(9600); //Start the serial output at 9600 baud
  pinMode(fire, INPUT);
  pinMode(buzzer, OUTPUT);
  
  Blynk.begin(auth, ssid, pass);//Splash screen delay
  delay(2000);
  timer.setInterval(500L, mySensor);
}

void loop() //Loop function
{
  Blynk.run();
  timer.run();
}

void mySensor()
{
  fire_Val = digitalRead(fire);
   
  if (fire_Val == LOW)
  {
    Blynk.logEvent("fire_alert");
   
    digitalWrite(buzzer, HIGH);
    Blynk.virtualWrite(V0, 1);
    Serial.print("fIRE Level: ");
    Serial.println(fire_Val);
    led.on();
  }

  else
  {
    
    digitalWrite(buzzer, LOW);
    Blynk.virtualWrite(V0, 0);
    Serial.print("fIRE Level: ");
    Serial.println(fire_Val);
    led.off();
  }  

  
}
