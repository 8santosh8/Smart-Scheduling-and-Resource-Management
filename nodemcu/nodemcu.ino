#include <ESP8266WiFi.h>
//#include "DHT.h"

//#define DHTPIN D1
//#define DHTTYPE DHT11 
int led1=5;
int led2=4;

int p1=1;
int p2=2;

const char* ssid = "LucKy";
const char* password = "really!o";

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);
//DHT dht(DHTPIN, DHTTYPE);

const char* host="vineets17.000webhostapp.com";

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  
  Serial.begin(115200);
  delay(10);
  //dht.begin();
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  Serial.println("Ip address");

  // Print the IP address
  Serial.println(WiFi.localIP());

  Serial.println("subnet mask");

  // Print the IP address
  Serial.println(WiFi.subnetMask());

  
  Serial.println("GateWay");

  // Print the IP address
  Serial.println(WiFi.gatewayIP());
  
}

void loop() {

  float la=0;

  float lo=0;

    la=13.54282;

    lo=80.0002;
  

  if (la==0 || lo==0) {
    Serial.println("Failed to read from gps sensor!");
    return;
  }

  char a;

  a=Serial.read();

  if(a!='a')
    return;

  Serial.print("connecting to");
  Serial.print("host");
  
  // Check if a client has connected
  WiFiClient client ;
  const int httpPort=80;
  if (!client.connect(host,httpPort)) {
    Serial.println("connection failed");
    return;
  }

  String url="/api/insert.php?lat="+ String(la) +"&lng="+String(lo);
  Serial.print("Requesting url  ");
  Serial.println(url);
  client.print(String("GET ")+ url + " HTTP/1.1\r\n"+
                "Host: " + host+"\r\n" +
                 "Connection: close\r\n\r\n");
  delay(500);

  while(client.available()){
    String line=client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");
  delay(10000);

  
  // Read the first line of the request
  //float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  //float t = dht.readTemperature();
 
 
  // Check if any reads failed and exit early (to try again).
  

 
}
