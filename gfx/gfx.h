/**
 * Simple GFX (graphics) library based on SDL3
 *
 * Author: Vinicius Schautz <vinicius.schautz@hotmail.com>
 * Based on the 2013 work of Fabricio Sergio de Paula <fabricio.paula@gmail.com>
 * Now ported to SDL3
 * 
 * Year: 2026
 *
 * Use: Before using this library, you must install SDL3 and SDL3_ttf libraries.
 * After that, make sure all GFX library files are at YOUR-PROGRAM-DIR/gfx directory.
 * Then, your program must include gfx.h (e.g. "gfx/gfx.h") and be linked against
 * -Lgfx -lgfx -lSDL3 -lSDL3_ttf flags.
 */
#ifndef _GFX_H_
#define _GFX_H_

#include <assert.h>
#include <stdbool.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>

#define FONT_NAME "gfx/FreeSans.ttf"

/**
 * Initialize the graphic window with given dimension and caption.
 * 
 * \param width width of the window.
 * \param height height of the window.
 * \param caption caption of the window (i.e. the name of your program).
 */ 
void gfx_init(int width, int height, const char *caption);

/**
 * Terminate the graphic window.
 */ 
void gfx_quit(void);

/**
 * Get any event (keyboard/mouse/window).
 * 
 * \param event pointer to a SDL_event structure, which will store an event.
 * 
 * \returns false if there's no event, or true otherwise.
 */ 
bool gfx_get_event(SDL_Event *event);

/**
 * Verify whether the window should stay opened or the user has requested to close it
 * by pressing the window's Close button.
 * 
 * Note that this function must be called as a condition in the loop that
 * updates the program's state, in order to prevent it from being considered
 * frozen by the operational system:
 * 
 * ```c
 * while (gfx_window_opened()) {
 *     
 *     // update game state, draw the current frame
 * 
 * }
 * gfx_quit(); // effectively close the window
 * ```
 * 
 * \returns false if the user has requested to close the window, or true otherwise.
 */ 
bool gfx_window_opened(void);

/**
 * Apply changes to the graphic window.
 * 
 * This function must be called to show graphic elements.
 */
void gfx_paint(void);

/**
 * Clear the graphic window with a solid color (black by default).
 */
void gfx_clear(void);

/**
 * Get the width dimension of the window.
 * 
 * \returns the window's width.
 */
int gfx_get_width(void);

/**
 * Get the height dimension of the window.
 * 
 * \returns the window's height.
 */
int gfx_get_height(void);

/**
 * Get the current text/object draw color.
 * 
 * \param r pointer to a variable to store the RED color value.
 * \param g pointer to a variable to store the GREEN color value.
 * \param b pointer to a variable to store the BLUE color value.
 */
void gfx_get_color(Uint8 *r, Uint8 *g, Uint8 *b);

/**
 * Set the text/object draw color.
 * 
 * \param r the new RED color value (0-255).
 * \param g the new GREEN color value (0-255).
 * \param b the new BLUE color value (0-255).
 */
void gfx_set_color(Uint8 r, Uint8 g, Uint8 b);

/**
 * Get the current text's font size.
 * 
 * \returns the text's font size.
 */
float gfx_get_font_size(void);

/**
 * Set the text's font size.
 * 
 * \param size the text's new font size.
 */
void gfx_set_font_size(float size);

/**
 * Get the width and the height of the text to be printed on the screen.
 * 
 * \param text the text to be printed.
 * \param width pointer to a variable to store the text width.
 * \param height pointer to a variable to store the text height.
 */
void gfx_get_text_size(const char *text, int *width, int *height);

/**
 * Print text starting at (`x`,`y`) point on the screen.
 * 
 * Note that the coordinate refers to the top-left corner of the text.
 * 
 * \param x the x (horizontal) coordinate.
 * \param y the y (vertical) coordinate.
 * \param text the text to be printed.
 */
void gfx_text(float x, float y, const char *text);

/**
 * Draw a line from (`x1`,`y1`) to (`x2`,`y2`) on the screen.
 * 
 * \param x1 the starting x (horizontal) coordinate.
 * \param y1 the starting y (vertical) coordinate.
 * \param x2 the ending x (horizontal) coordinate.
 * \param y2 the ending y (vertical) coordinate.
 */
void gfx_line(float x1, float y1, float x2, float y2);

/**
 * Draw a rectangle (outline) of top-left corner at (`x1`,`y1`) and bottom-right corner at (`x2`,`y2`) on the screen.
 * 
 * \param x1 the starting x (horizontal) coordinate.
 * \param y1 the starting y (vertical) coordinate.
 * \param x2 the ending x (horizontal) coordinate.
 * \param y2 the ending y (vertical) coordinate.
 */
void gfx_rectangle(float x1, float y1, float x2, float y2);

/**
 * Draw a filled rectangle of top-left corner at (`x1`,`y1`) and bottom-right corner at (`x2`,`y2`) on the screen.
 * 
 * \param x1 the starting x (horizontal) coordinate.
 * \param y1 the starting y (vertical) coordinate.
 * \param x2 the ending x (horizontal) coordinate.
 * \param y2 the ending y (vertical) coordinate.
 */
void gfx_filled_rectangle(float x1, float y1, float x2, float y2);

/**
 * Draw an ellipse (outline) of center (`x`,`y`) with x radius `rx` and y radius `ry`.
 * 
 * \param x the x (horizontal) coordinate.
 * \param y the y (vertical) coordinate.
 * \param rx the x radius value.
 * \param ry the y radius value.
 */
void gfx_ellipse(float x, float y, float rx, float ry);

/**
 * Draw a filled ellipse of center (`x`,`y`) with x radius `rx` and y radius `ry`.
 * 
 * \param x the x (horizontal) coordinate.
 * \param y the y (vertical) coordinate.
 * \param rx the x radius value.
 * \param ry the y radius value.
 */
void gfx_filled_ellipse(float x, float y, float rx, float ry);

#endif