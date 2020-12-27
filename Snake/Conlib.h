#pragma once
//extern "C" {

/*////////////////////////////////////////////////////////////////////////////
// Output functions
////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////
// 6 functions below
// If the function succeeds, the return value is nonzero.
// If the function fails, the return value is zero.
// To get extended error information, call GetLastError()
////////////////////////////////////////////////////////////////////////////*/

int	GotoXY(int x, int y);		/* moves cursor to given position (x,y) */
int	GetXY(int *px, int *py);	/* retrieves current cursor position */
int	MaxXY(int *px, int *py);	/* retrieves current maximal window coordinates */
int	ClearConsole();					/* clears console window */

/* controls the cursor visibility (depends on bVisible value) */
int	ConShowCursor(int bVisible);

/* prints formatted string at current cursor position */
int	OutTxt(const char *, ...);
void frame(int maxX, int maxY, int foregroung);
/*////////////////////////////////////////////////////////////////////////////
// Input functions
////////////////////////////////////////////////////////////////////////////*/

int KeyPressed();	/* non zero if key was pressed */
int GetKey();		/* returns key code, positive means regular character,
					   negative means extended character */

/*////////////////////////////////////////////////////////////////////////////
// Special characters codes
////////////////////////////////////////////////////////////////////////////*/

#define KEY_ESC		27
#define KEY_ENTER	13

/*////////////////////////////////////////////////////////////////////////////
// Extended characters codes
////////////////////////////////////////////////////////////////////////////*/

#define KEY_UP		-72		/* Up arrow */
#define KEY_LEFT	-75		/* Left arrow */
#define KEY_RIGHT	-77		/* Right arrow */
#define KEY_DOWN	-80		/* Down arrow */

/*////////////////////////////////////////////////////////////////////////////
// Text atrributes
////////////////////////////////////////////////////////////////////////////*/

#ifndef FOREGROUND_BLUE

#define FOREGROUND_BLUE      0x0001 /* text color contains blue. */
#define FOREGROUND_GREEN     0x0002 /* text color contains green. */
#define FOREGROUND_RED       0x0004 /* text color contains red. */
#define FOREGROUND_INTENSITY 0x0008 /* text color is intensified. */
#define BACKGROUND_BLACK	 0x0000 /* background color contains black. */
#define BACKGROUND_BLUE      0x0010 /* background color contains blue. */
#define BACKGROUND_GREEN     0x0020 /* background color contains green. */
#define BACKGROUND_RED       0x0040 /* background color contains red. */
#define BACKGROUND_INTENSITY 0x0080 /* background color is intensified. */

#endif /* FOREGROUND_BLUE */

/* sets current text (foreground&background) attribute */
int SetColor(short color);

/* retrievess current text (foreground&background) attribute */
short GetColor();

/*////////////////////////////////////////////////////////////////////////////
// Block output
////////////////////////////////////////////////////////////////////////////*/

/* rectangular image descriptor */
typedef struct _IMG IMG;

/* allocates image of the given size */
IMG *	ImgAlloc(int width, int height);

/* deletes the given image */
void	ImgFree(IMG * pImg);

/* fills all image with given char and attribute */
int	ImgFill(IMG * pImg, char ch, short attr);

/* puts char into image to given position */
int	ImgPutChar(IMG * pImg, int x, int y, char ch, short attr);

/* writes image to console. left & top - window coords of upper-left cell of image */
int	ImgPut(const IMG * pImg, int left, int top);

//}
