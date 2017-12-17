#include <ESP8266WebServer.h>

#define HTTP_PLAIN_TEXT "text/plain"
#define HTTP_APPLICATION_JSON "application/json"

ESP8266WebServer server(SERVER_PORT);

void server_init(){
  Serial.print("started http server on port:");
  Serial.println(SERVER_PORT);
  
  server.on("/api", server_api_handle);
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



