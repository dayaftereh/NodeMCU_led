#include <ArduinoJson.h>

void _server_api_get() {
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  // --- Color ---

  JsonArray& color = root.createNestedObject("color");

  color["red"] = led_red();
  color["green"] = led_green();
  color["blue"] = led_blue();

  // --- Output ---

  String content;
  root.printTo(content);
  server.send(200, HTTP_APPLICATION_JSON, content);
}

void _server_api_post() {
  String body = server_get_request_body();
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(body);

  if(!root.success()){
    server_send_error(500, F("Fail to parse json content"));
    return;
  }

  // JsonObject::containsKey()

  // --- Color ---
  if(root.containsKey("color")){
    JsonObject& color = root["color"];
    int red = color["red"];
    int green = color["green"];
    int blue = color["blue"];

    led_set(red, green, blue);
  }

  server_send_ok();
}

void server_api_handle() {
  HTTPMethod method = server.method();
  if(method == HTTP_GET){
    _server_api_get();
  } else if(metho == HTTP_POST){
    _server_api_post();
  }
}
