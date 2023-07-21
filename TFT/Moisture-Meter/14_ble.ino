
//Setup callbacks onConnect and onDisconnect
class MyServerCallbacks: public BLEServerCallbacks {
  void onConnect(NimBLEServer* pServer) {
    deviceConnected = true;
  };
  void onDisconnect(NimBLEServer* pServer) {
    deviceConnected = false;
  }
};

float rounded_02(float value_) {
    float rounded_value = 0.0;
    char array_float_value[7];
  
    sprintf(array_float_value, "%0.1f", value_);
    sscanf(array_float_value, "%f",  &rounded_value);
    return  rounded_value;
}

void NimBLE_setup(){
    // Create the BLE Device
  NimBLEDevice::init(bleServerName);
  NimBLEDevice::setPower(ESP_PWR_LVL_P9); /** +9db */
  NimBLEServer *pMeasurementServer = NimBLEDevice::createServer();
  NimBLEService *pMeasurementService = pMeasurementServer->createService(SERVICE_UUID);
  pMeasurementCharacteristic = pMeasurementService->createCharacteristic(
        CHARACTERISTIC_UUID,
        NIMBLE_PROPERTY::READ |
        NIMBLE_PROPERTY::WRITE |
        NIMBLE_PROPERTY::NOTIFY
    );

  pMeasurementService->start();
  NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);
  pAdvertising->setMinPreferred(0x12);
  NimBLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it on your phone!");
}
