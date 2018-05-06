#ifndef __SCRN_H
#define __SCRN_H

/* Hardware text mode color constants. */
enum vga_color {
        COLOR_BLACK = 0,
        COLOR_BLUE = 1,
        COLOR_GREEN = 2,
        COLOR_CYAN = 3,
        COLOR_RED = 4,
        COLOR_MAGENTA = 5,
        COLOR_BROWN = 6,
        COLOR_LIGHT_GREY = 7,
        COLOR_DARK_GREY = 8,
        COLOR_LIGHT_BLUE = 9,
        COLOR_LIGHT_GREEN = 10,
        COLOR_LIGHT_CYAN = 11,
        COLOR_LIGHT_RED = 12,
        COLOR_LIGHT_MAGENTA = 13,
        COLOR_LIGHT_BROWN = 14,
        COLOR_WHITE = 15,
};


/* SCRN.C */
extern void cls();
extern void putch(unsigned char c);
extern void puts(unsigned char* str);
extern void putp(addr pointer);
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video();

#endif
