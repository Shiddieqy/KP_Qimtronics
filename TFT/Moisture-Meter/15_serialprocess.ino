void processSerialInput() {
  if (Serial.available()) { // Check if data is available to read
    char receivedChar = Serial.read(); // Read a character from the serial monitor
    
    if (receivedChar == 't') { // If 'm' is received
      taree = 1 ; // Set taree value to 1
    } else if (receivedChar == 'm') { // If 't' is received
      taree = 0; // Set taree value to 0
    } else if (receivedChar == 'c') { // If 't' is received
      taree = 2; // Set taree value to 0
    }
  }
}
