#include <Wire.h>
#include <SparkFun_APDS9960.h>

// Global Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint8_t proximity_data = 0;

const int fanRelayPin = 8; // Define the fan relay pin
const int bulbRelayPin = 9; // Define the bulb relay pin

bool isFanOn = false;
bool isBulbOn = false;
String lastSwitched = "";

void setup() {
  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("------------------------------------"));
  Serial.println(F("SparkFun APDS-9960 - ProximitySensor"));
  Serial.println(F("------------------------------------"));
  
  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }

  // Adjust the Proximity sensor gain
  if ( !apds.setProximityGain(PGAIN_2X) ) {
    Serial.println(F("Something went wrong trying to set PGAIN"));
  }
  
  // Start running the APDS-9960 proximity sensor (no interrupts)
  if ( apds.enableProximitySensor(false) ) {
    Serial.println(F("Proximity sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during sensor init!"));
  }

  // Set relay pins as output
  pinMode(fanRelayPin, OUTPUT);
  pinMode(bulbRelayPin, OUTPUT);
  digitalWrite(fanRelayPin, LOW); // Ensure the fan relay is off initially
  digitalWrite(bulbRelayPin, LOW); // Ensure the bulb relay is off initially
}

void loop() {
  // Read the proximity value
  if ( !apds.readProximity(proximity_data) ) {
    Serial.println("Error reading proximity value");
  } else {
    // Print the proximity value
    Serial.print("Proximity: ");
    Serial.println(proximity_data);

    if (proximity_data > 100) {
      if (lastSwitched != "fan") {
        Serial.println("Switched to fan");
        lastSwitched = "fan";
      } else {
        Serial.println("Switched to bulb");
        lastSwitched = "bulb";
      }
    }

    if (proximity_data >= 10 && proximity_data <= 70) {
      if (lastSwitched == "fan") {
        if (!isFanOn) {
          digitalWrite(fanRelayPin, HIGH); // Turn fan relay on
          Serial.println("Fan turned on");
          isFanOn = true;
        } else {
          digitalWrite(fanRelayPin, LOW); // Turn fan relay off
          Serial.println("Fan turned off");
          isFanOn = false;
        }
      } else if (lastSwitched == "bulb") {
        if (!isBulbOn) {
          digitalWrite(bulbRelayPin, HIGH); // Turn bulb relay on
          Serial.println("Bulb turned on");
          isBulbOn = true;
        } else {
          digitalWrite(bulbRelayPin, LOW); // Turn bulb relay off
          Serial.println("Bulb turned off");
          isBulbOn = false;
        }
      }
    }
  }

  // Wait 250 ms before next reading
  delay(800);
}
