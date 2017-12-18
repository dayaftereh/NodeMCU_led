
int _red_value = 0;
int _green_value = 0;
int _blue_value = 0;

void led_init() {
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);

  led_print_gpios();
}

void led_print_gpios(){
  Serial.print("led gpio: [ red: ");
  Serial.print(LED_RED_PIN);
  Serial.print(", green: ");
  Serial.print(LED_GREEN_PIN);
  Serial.print(", blue: ");
  Serial.print(LED_BLUE_PIN);
  Serial.println(" ]");
}

int led_value_to_pwm(int value){
  float x = value / ((float)LED_RANGE);
  int pwm_value = (int)(x * PWMRANGE);
  return pwm_value;
}

void led_set(int red, int green, int blue){
  _red_value = red;
  _green_value = green;
  _blue_value = blue;
}

int led_red(){
  return _red_value;
}

int led_green(){
  return _green_value;
}

int led_blue(){
  return _blue_value;
}

void led_write_values(){
  int red_pwm = led_value_to_pwm(_red_value);
  analogWrite(LED_RED_PIN, red_pwm);

  int green_pwm = led_value_to_pwm(_green_value);
  analogWrite(LED_GREEN_PIN, green_pwm);

  int blue_pwm = led_value_to_pwm(_blue_value);
  analogWrite(LED_BLUE_PIN, blue_pwm);
}
