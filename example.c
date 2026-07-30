#include "gfx/gfx.h"
#include <stdio.h>

int main()
{
	printf("Testing GFX library...\n");

	gfx_init(480, 360, "Test!"); // Initializes the graphic window

	while (gfx_window_opened()) { // This should be used to update program state, called every frame
		// Setting red color for a rectangle
		gfx_set_color(255, 0, 0);
		gfx_rectangle(80, 80, 400, 280);
		// Setting blue color for an ellipse
		gfx_set_color(0, 0, 255);
		gfx_filled_ellipse(120, 120, 80, 60);
		// Setting green color for some text
		gfx_set_color(0, 255, 0);
		gfx_set_font_size(18.f);
		gfx_text(120, 120, "Text");
		
		gfx_paint(); // Draw everything on the screen
	}
	gfx_quit(); // Close the window

	return 0;
}
