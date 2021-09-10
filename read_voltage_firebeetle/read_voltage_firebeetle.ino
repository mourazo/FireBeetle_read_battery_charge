void setup() {
 
    Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

    int vref = 1100; //voltage reference
    uint16_t v = analogRead(A0); //a0 is the gpio for the battery, you need to solder the 0 resistance near the TP4056 chip
    Serial.print("Reading: ");
    Serial.println(v);
    float battery_voltage = ((float)v /4095.0) * 2.0 * 3.3 * (vref/1000.0); //to calculate the voltage
    String voltage = "Voltage: " + String(battery_voltage) + "V"; //output of the voltage
    Serial.println(voltage);
    int charge = map(v, 1770, 2423, 0, 100); //function to calculate the percentage
    

    String result = "La carga de la batería es del " + String(charge) +"%"; //percentage output
    Serial.println();
    Serial.println(result);
    Serial.println();
    delay(2000);
}
