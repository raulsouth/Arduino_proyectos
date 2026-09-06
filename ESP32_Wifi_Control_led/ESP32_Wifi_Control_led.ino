#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);
String estadoSalida = "off";
int salida = 25; //Pin GPIO de led
String header; // Variable para guardar el HTTP request

//--------------SETUP---------
void setup() {
  Serial.begin(115200);
  const char* ssid     = "MEGA FIBRA2.4G-DjB4";
  const char* password = "7UssZtww";
  Serial.println("Desconectamos antes de conectar el WiFi");
  WiFi.disconnect();
  Serial.print("Conectando a  ");
  Serial.println(ssid);

  //Configuramos salida para led
  pinMode(salida, OUTPUT);
  digitalWrite(salida, LOW);


  //Conectamos el esp a la red wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  //Intentamos conectarnos a la red
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //Si logramos conectarnos mostramos la ip a la que nos conectamos
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  //Si entramos a la raiz mostramos las opciones
  server.on("/", []() {
    String content="";
    /*content += "<html>";
    content += "<div><a href=\"encender\">Encender</a></div>";
    content += "<div><a href=\"apagar\">Apagar</a></div>";
    content += "</html>";*/

content += "<html>";
content += "<head>";
content += "<meta charset='utf-8' />";
content += "<title>Servidor Web ESP32</title>";
content += "</head>";
content += "<body>";
content += "<center>";
content += "<h1>Servidor Web ESP32</h1>";
content += "<p><a href='/on'><button style='height:50px;width:100px'>ON</button></a></p>";
content += "<p><a href='/off'><button style='height:50px;width:100px'>OFF</button></a></p>";
content += "</center>";
content += "</body>";
content += "</html>";


    server.send(200, "text/html", content);
  });
  server.begin();
}

void loop() {
  //
  server.handleClient();
  delay(100);
  

}