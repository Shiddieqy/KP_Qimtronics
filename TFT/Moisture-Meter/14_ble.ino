
//Setup callbacks onConnect and onDisconnect
class MyServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
  };
  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
  }
};

void BLE_setup(){
    // Create the BLE Device
  BLEDevice::init(bleServerName);

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *QohuaService = pServer->createService(SERVICE_UUID);

  // Create BLE Characteristics and Create a BLE Descriptor

  // Moisture
  QohuaService->addCharacteristic(&MoistureCharacteristics);
  MoistureDescriptor.setValue("Moisture");
  MoistureCharacteristics.addDescriptor(new BLE2902());

  // Temperature
  QohuaService->addCharacteristic(&TemperatureCharacteristics);
  TemperatureDescriptor.setValue("Temperature");
  TemperatureCharacteristics.addDescriptor(new BLE2902());

  // Density
  QohuaService->addCharacteristic(&DensityCharacteristics);
  DensityDescriptor.setValue("Density");
  DensityCharacteristics.addDescriptor(new BLE2902());
  
  // Start the service
  QohuaService->start();

  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pServer->getAdvertising()->start();
  Serial.println("Waiting a client connection to notify...");
}
