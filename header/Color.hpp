#pragma once

struct color_t {
    short int r, g, b, a;
};

struct Color {
private:
    color_t color;

public:
    Color(short int r = 225, short int g = 225, short int b = 225, short int a = 1.0);

    Color(color_t color);

    bool check();
    static void fix(Color c);

    color_t& get();

    void set(color_t color);

    void set(short int r, short int g, short int b, short int a);
};