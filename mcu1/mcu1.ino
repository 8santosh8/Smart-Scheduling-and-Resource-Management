#include <ESP8266WiFi.h>
#include <Wire.h>
const char* ssid     = "BW9b-c2FudG9zaA";
const char* password = "santosh56";
const char* host = "noisedetection.000webhostapp.com";

void setup() {
 Serial.begin(115200);
  delay(100);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid); /* begin serial for debug */
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */
}

void loop() {

  float la=0;
  float lo=0;
  la=13.54282;
  lo=80.0002;
  
  int d=0; 
 
 Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("Hello Arduino");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */

 Wire.requestFrom(8, 1); /* request & read data of size 13 from slave */
 while(Wire.available()){
    d = Wire.read();
    Serial.println(d);
    delay(1000);
}
//Serial.println(d);
if(d==39)
{
  
 Serial.println(d);
Serial.print("connecting to ");
  Serial.println(host);
 
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  String url = "/api/insert.php?latitude="+ String(la) +"&longitude="+String(lo);
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
  
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  
  Serial.println("closing connection");
  delay(5000);
}
}
