#include "gfx/gfx.h"
#include <stdio.h>

int main()
{
	printf("Testing GFX library...\n");

	gfx_init(480, 360, "Test!");

	while (gfx_window_opened()) {
		gfx_set_color(255, 0, 0);
		gfx_rectangle(80, 80, 400, 280);

		gfx_set_color(0, 0, 255);
		gfx_filled_ellipse(120, 120, 80, 60);

		gfx_set_color(0, 255, 0);
		gfx_set_font_size(18.f);
		gfx_text(120, 120, "Texto");
		
		gfx_paint();
	}
	gfx_quit();

	return 0;
}
