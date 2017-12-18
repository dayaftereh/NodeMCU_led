
void setup() {
  Serial.begin(115200);
  
  wifi_init();
  wifi_print_info();

  led_init();
  file_system_init();
  server_init();

  Serial.println("Done");
}

void loop() {
  server_loop();
  led_write_values();
}
