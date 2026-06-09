#include <Render.h>
#include <Hardware.h>
#include <string.h>

void PrintDisp(int page, const char* text, bool invert){
    ssd1306_display_text(&display, page, text, strlen(text), invert);
}