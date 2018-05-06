#include <system.h>
#include <irq.h>
#include <kb.h>
#include <check.h>

/* Keyboard constants */
#define KB_SHIFT 0x11
#define KB_ALT 0x12
#define KB_CTRL 0x13
#define KBD_LAYOUT kbd_us

/* Include keyboard layouts here */
#include <kbd/us.h>

/* Global indicator as to the status of
 * various keyboard controls */
unsigned short keystatus = 0x0000;

/* global keyboard buffer */
char buffer[32] = {0};
int idx = 0;

/* Handles the keyboard interrupt */
void keyboard_handler(struct regs* r)
{
	unsigned char scancode;

	/* Read from the keyboard's data buffer */
	scancode = inportb(0x60);

	/* If the top bit of the byte we read from the keyboard is
	 * set, that means that a key has just been released */
	if (scancode & 0x80)
	{
		/* You can use this one to see if the user released
		 * shift, alt or control keys... */
		if (KBD_LAYOUT[scancode] == KB_SHIFT)
			keystatus &= ~0x0100;
		else if (KBD_LAYOUT[scancode] == KB_CTRL)
			keystatus &= ~0x0010;
		else if (KBD_LAYOUT[scancode] == KB_ALT)
			keystatus &= ~0x0001;
	}
	else
	{
		/* Here, a key was just pressed.  Please note that if
		 * you hold a key down, you will get repeated key press
		 * interrupts. */
		if (KBD_LAYOUT[scancode] == KB_SHIFT)
			keystatus |= 0x0100;
		else if (KBD_LAYOUT[scancode] == KB_CTRL)
			keystatus |= 0x0010;
		else if (KBD_LAYOUT[scancode] == KB_ALT)
			keystatus |= 0x0001;

		/* Example showing keyboard characters outputted to the
		 * screen */
		if ((keystatus & 0x0100) == 0x0100) {
			//Backspace
			if(KBD_LAYOUT[scancode+128] == 0x08) {
				if(idx > 0) {
					idx--;
					putch(KBD_LAYOUT[scancode+128]);
				}
			}
			//Tab
			else if (KBD_LAYOUT[scancode+128] == 0x09) {
				//putch(KBD_LAYOUT[scancode+128]);
			}
			//Enter
			else if (KBD_LAYOUT[scancode+128] == '\n' || KBD_LAYOUT[scancode+128] == '\r') {
				check(buffer);
				int i=0;
				for(i = 0 ; i < 32 ; i++)
					buffer[i] = 0;
				idx = 0;
				putch(KBD_LAYOUT[scancode+128]);
			} else{
				if(idx < 32) {
					buffer[idx] = KBD_LAYOUT[scancode+128];
					idx++;
					putch(KBD_LAYOUT[scancode+128]);
				}
			}
		}
		else {
			//Backspace
			if(KBD_LAYOUT[scancode] == 0x08) {
				if(idx > 0) {
					idx--;
					putch(KBD_LAYOUT[scancode]);
				}
			}
			//Tab
			else if (KBD_LAYOUT[scancode] == 0x09) {
				//putch(KBD_LAYOUT[scancode]);
			}
			//Enter
			else if (KBD_LAYOUT[scancode] == '\n' || KBD_LAYOUT[scancode] == '\r') {
				check(buffer);
				int i=0;
				for(i = 0 ; i < 32 ; i++)
					buffer[i] = 0;
				idx = 0;
				putch(KBD_LAYOUT[scancode]);
			} else {
				if(idx < 32) {
					buffer[idx] = KBD_LAYOUT[scancode];
					idx++;
					putch(KBD_LAYOUT[scancode]);
				}
			}
		}
	}
}

#undef KBD_LAYOUT

/* Sets up the keyboard by installing the handler
 * into IRQ1 */
void kb_install()
{
	/* Installs the IRQ handler */
	irq_install_handler(1, keyboard_handler);
}
