
unsigned long _last_time = 0;
unsigned long _timer = 0;

int led_fading_index = 0;
int led_fading_color_1[3] = {0, 0, 0};
int led_fading_color_2[3] = {0, 0, 0};

boolean led_fading_running = false;

void led_fading_update()
{
    int speed = 1;
    int timeout = 150;

    unsigned long now = millis();
    unsigned long delta = now - _last_time;
    _last_time = now;

    _timer += delta;
    if (_timer > timeout)
    {
        _timer = _timer - timeout;
        if (led_fading_running)
        {
            led_fading_update_internal(speed);
        }
    }
}

void led_fading_update_internal(int speed)
{
    int red = led_red();
    int red2 = led_fading_color_index(0);
    int red3 = led_fading_lerp(red, red2, speed);

    int green = led_green();
    int green2 = led_fading_color_index(1);
    int green3 = led_fading_lerp(green, green2, speed);

    int blue = led_blue();
    int blue2 = led_fading_color_index(2);
    int blue3 = led_fading_lerp(blue, blue2, speed);

    led_set(red3, green3, blue3);

    if (led_fading_close(red2, red3) && led_fading_close(green2, green3) && led_fading_close(blue2, blue3))
    {
        led_fading_index = (led_fading_index + 1) % 2;
    }
}

int led_fading_color_index(int index)
{
    if (led_fading_index < 1)
    {
        return led_fading_color_1[index];
    }
    return led_fading_color_2[index];
}

boolean led_fading_close(int x, int x2)
{
    return abs(x - x2) < 1;
}

void led_fading_set_color_1(int red, int green, int blue)
{
    led_fading_color_1[0] = red;
    led_fading_color_1[1] = green;
    led_fading_color_1[2] = blue;
}

void led_fading_set_color_2(int red, int green, int blue)
{
    led_fading_color_2[0] = red;
    led_fading_color_2[1] = green;
    led_fading_color_2[2] = blue;
}

void led_fading_set_running(boolean running)
{
    led_fading_running = running;
}

int led_fading_lerp(int x, int x2, int speed)
{

    int d = x2 - x;
    if (d == 0)
    {
        return x;
    }

    int step = (d / abs(d)) * speed;
    int x3 = x + step;

    if (d > 0 && x3 > x2)
    {
        x3 = x2;
    }
    else if (d < 0 && x3 < x2)
    {
        x3 = x2;
    }
    return x3;
}