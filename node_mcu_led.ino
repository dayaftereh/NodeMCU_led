

void setup() {
  wifi_init();
  wifi_print_info();
  server_init();
}

void loop() {
  server_loop();
}
