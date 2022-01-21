#include <ArduinoJson.h>

void _server_api_get() {
  DynamicJsonDocument root(1024);

  // --- Color ---

  JsonObject color = root.createNestedObject("color");

  color["red"] = led_red();
  color["green"] = led_green();
  color["blue"] = led_blue();

  // --- fading ---

  JsonObject fading = root.createNestedObject("fading");

  fading["running"] = led_fading_running;
  
  JsonObject color1 = fading.createNestedObject("color1");
  color1["red"] = led_fading_color_1[0];
  color1["green"] = led_fading_color_1[1];
  color1["blue"] = led_fading_color_1[2];

  JsonObject color2 = fading.createNestedObject("color2");
  color2["red"] = led_fading_color_2[0];
  color2["green"] = led_fading_color_2[1];
  color2["blue"] = led_fading_color_2[2];

  // --- Output ---

  String content;
  serializeJson(root, content);

  // --- send ---
  
  server_send(200, HTTP_APPLICATION_JSON, content);
}

void _server_api_post() {
  String body = server_get_request_body();
  
  DynamicJsonDocument root(1024);
  DeserializationError error = deserializeJson(root, body);

  if(error){
    server_send_error(500, F("Fail to parse json content"));
    return;
  }

  // --- Color ---
  if(root.containsKey("color")){
    JsonObject color = root["color"];
    int red = color["red"];
    int green = color["green"];
    int blue = color["blue"];

    led_set(red, green, blue);
  }

  // --- fading ---
  if(root.containsKey("fading")){
    JsonObject fading = root["fading"];
    boolean running = fading["running"];
    led_fading_set_running(running);

    // --- color1 ---
    if(fading.containsKey("color1")){
      JsonObject color1 = fading["color1"];

      int red = color1["red"];
      int green = color1["green"];
      int blue = color1["blue"];

      led_fading_set_color_1(red, green, blue);
    }

    // --- color2 ---
    if(fading.containsKey("color2")){
      JsonObject color2 = fading["color2"];

      int red = color2["red"];
      int green = color2["green"];
      int blue = color2["blue"];

      led_fading_set_color_2(red, green, blue);
    }
  }

  server_send_ok();
}

void server_api_handle() {
  led_status_on();
  HTTPMethod method = server.method();
  if(method == HTTP_GET){
    _server_api_get();
  } else if(method == HTTP_POST){
    _server_api_post();
  }
}
