////#include <DHT.h>
////#include <DHT_U.h>

float tempDRY;
float tempHUM;
float Press;
float U;

int tempPinSECO = 2;
int tempPinUMIDO = 3;


////#define DHTPIN 7     // Digital pin connected to the DHT sensor

// Uncomment whatever type you're using!
////#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
////DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
 //// Serial.println(F("DHT22 test!"));

 //// dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
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
  Press = 935; //hPa

  U = 100*(exp(1.8096 + (17.2694*tempHUM/(237.3 + tempHUM))) - 7.866E-4*Press*(tempDRY - tempHUM)*(1+tempDRY/610));
  U = U/exp(1.8096 + (17.2694*tempDRY/(237.3+tempDRY)));
  Serial.print("UMIDADE ESTIMADA: ");
  Serial.println(U);
  Serial.println("-----------------------");
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  ////float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  ////float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  ////float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  ////if (isnan(h) || isnan(t) || isnan(f)) {
  ////  Serial.println(F("Failed to read from DHT sensor!"));
  ////  return;
  ////}

  // Compute heat index in Fahrenheit (the default)
  ////float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  ////float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
////  Serial.print(h);
  Serial.print(F("%  Temperature: "));
////  Serial.print(t);
  Serial.print(F("°C "));
 //// Serial.print(f);
  Serial.print(F("°F  Heat index: "));
 //// Serial.print(hic);
  Serial.print(F("°C "));
 //// Serial.print(hif);
  Serial.println(F("°F"));
}
