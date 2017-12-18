
void setup() {
  wifi_init();
  wifi_print_info();

  led_init();
  file_system_init();
  server_init();
}

void loop() {
  server_loop();
  led_write_values();
}
