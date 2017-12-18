#include <ESP8266WebServer.h>

#define HTTP_PLAIN_TEXT "text/plain"
#define HTTP_APPLICATION_JSON "application/json"

ESP8266WebServer server(SERVER_PORT);

void server_not_found(){
  server_send_error(404, F("Not Found"));
}

void server_init(){  
  server.on("/api", server_api_handle);
  server.onNotFound(server_not_found);
  server.serveStatic("/", SPIFFS, "/index.html");

  server.begin();
  Serial.print("started http server on port:");
  Serial.println(SERVER_PORT);
}

void server_loop(){
  server.handleClient();
}

String server_get_request_body(){
  if(server.hasArg("plain")){
    String plain = server.arg("plain");
    return plain;
  }
  return ""
}

void server_send_error(int code, String message){
  server.send(code, HTTP_PLAIN_TEXT, message);
}

void server_send_ok(){
  server.send(code, HTTP_PLAIN_TEXT, "Ok");
}
