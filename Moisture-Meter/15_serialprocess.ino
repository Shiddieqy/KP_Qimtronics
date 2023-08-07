void processSerialInput() {
  if (Serial.available()) { // Check if data is available to read
    char receivedChar = Serial.read(); // Read a character from the serial monitor
    
    if (receivedChar == 't') { // If 'm' is received
      sys_State = 1 ; // Set sys_State value to 1
    } else if (receivedChar == 'm') { // If 't' is received
      sys_State = 0; // Set sys_State value to 0
    } else if (receivedChar == 'c') { // If 't' is received
      sys_State = 2; // Set sys_State value to 0
    }
  }
}
