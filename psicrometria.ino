float tempDRY;
float tempHUM;
float Press;
float U;

int tempPinSECO = A2;
int tempPinUMIDO = A3;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(2000);

  // LM35 - SECO
  tempDRY = analogRead(tempPinSECO);
  tempDRY = tempDRY * 0.48828125;
  Serial.print("SECO CELSIUS: ");
  Serial.println(tempDRY);

  // LM35 - ÚMIDO
  tempHUM = analogRead(tempPinUMIDO);
  tempHUM = tempHUM * 0.48828125;
  Serial.print("ÚMIDO CELSIUS: ");
  Serial.println(tempHUM);

  // UMIDADE ESTIMADA COM LM35
  P = 935; //Pressão em hPa

  U = 100*(exp(1.8096 + (17.2694*tempHUM/(237.3 + tempHUM))) - 7.866E-4*P*(tempDRY - tempHUM)*(1+tempDRY/610));
  U = U/exp(1.8096 + (17.2694*tempDRY/(237.3+tempDRY)));
  
  Serial.print("UMIDADE ESTIMADA: ");
  Serial.println(U);
  Serial.println("-----------------------");
}
