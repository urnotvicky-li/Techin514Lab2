#include <Arduino.h>

const int VOUT1_PIN = 1;  // A0 (GPIO1)
const int VOUT2_PIN = 2;  // A1 (GPIO2)

void setup() {
    Serial.begin(115200);
    adcAttachPin(VOUT1_PIN);  // make sure ADC is attached to the pins
    adcAttachPin(VOUT2_PIN);
    analogSetAttenuation(ADC_11db); // set attenuation to 11dB to allow measurement range of 0-3.3V
}

void loop() {
    int adc1 = analogRead(VOUT1_PIN); 
    int adc2 = analogRead(VOUT2_PIN);
    // read raw ADC value from the pins

    //convert raw ADC values to voltages (0-3.3V range and 12-bit resolution)
    float voltage1 = (adc1 / 4095.0) * 3.3;
    float voltage2 = (adc2 / 4095.0) * 3.3;

    //print voltage reading on the serial monitor
    Serial.print("VOUT1: "); Serial.print(voltage1); Serial.println(" V");
    Serial.print("VOUT2: "); Serial.print(voltage2); Serial.println(" V");
    Serial.println("----------------------");

    delay(1000);
}