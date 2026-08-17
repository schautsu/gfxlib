#include "gfx.h"

static int g_gfx_window_width = 0;
static int g_gfx_window_height = 0;
static float g_gfx_font_size = 14.f;
static SDL_Color g_gfx_color = { 255, 255, 255, SDL_ALPHA_OPAQUE };
static SDL_Renderer *g_gfx_renderer = NULL;
static SDL_Window *g_gfx_window = NULL;
static TTF_Font *g_gfx_font = NULL;

void gfx_init(int width, int height, const char *caption)
{
    g_gfx_window_width = width;
    g_gfx_window_height = height;

    assert(SDL_Init(SDL_INIT_VIDEO));
    assert(SDL_CreateWindowAndRenderer(caption, width, height, 0, &g_gfx_window, &g_gfx_renderer));

    assert(TTF_Init());
    assert((g_gfx_font = TTF_OpenFont(FONT_NAME, g_gfx_font_size)) != NULL);
}

void gfx_quit()
{
    SDL_DestroyRenderer(g_gfx_renderer);
    SDL_DestroyWindow(g_gfx_window);
    TTF_CloseFont(g_gfx_font);
    TTF_Quit();
    SDL_Quit();
}

bool gfx_get_event(SDL_Event *event)
{
    return SDL_PollEvent(event);
}

bool gfx_window_opened()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            return false;
        }
    }

    return true;
}

void gfx_paint()
{
    SDL_RenderPresent(g_gfx_renderer);
}

void gfx_clear()
{
    SDL_SetRenderDrawColor(g_gfx_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(g_gfx_renderer);
}

int gfx_get_width()
{
    return g_gfx_window_width;
}

int gfx_get_height()
{
    return g_gfx_window_height;
}

void gfx_get_color(Uint8 *r, Uint8 *g, Uint8 *b)
{
    *r = g_gfx_color.r;
    *g = g_gfx_color.g;
    *b = g_gfx_color.b;
}

void gfx_set_color(Uint8 r, Uint8 g, Uint8 b)
{
    g_gfx_color.r = r;
    g_gfx_color.g = g;
    g_gfx_color.b = b;
}

float gfx_get_font_size()
{
    return g_gfx_font_size;
}

void gfx_set_font_size(float size)
{
    g_gfx_font_size = size;

    if (g_gfx_font != NULL) {
        TTF_CloseFont(g_gfx_font);
        assert((g_gfx_font = TTF_OpenFont(FONT_NAME, g_gfx_font_size)) != NULL);
    }
}

void gfx_get_text_size(const char *text, int *width, int *height)
{
    TTF_GetStringSize(g_gfx_font, text, 0, width, height);
}

void gfx_text(float x, float y, const char *text)
{
    SDL_FRect position;
    SDL_Surface *surface;
    SDL_Texture *texture;

    assert((surface = TTF_RenderText_Blended(g_gfx_font, text, 0, g_gfx_color)) != NULL);
    assert((texture = SDL_CreateTextureFromSurface(g_gfx_renderer, surface)) != NULL);

    position.x = x;
    position.y = y;
    position.w = (float)surface->w;
    position.h = (float)surface->h;

    SDL_RenderTexture(g_gfx_renderer, texture, NULL, &position);

    SDL_DestroyTexture(texture);
    SDL_DestroySurface(surface);
}

void gfx_line(float x1, float y1, float x2, float y2)
{
    SDL_SetRenderDrawColor(g_gfx_renderer, g_gfx_color.r, g_gfx_color.g, g_gfx_color.b, g_gfx_color.a);
    SDL_RenderLine(g_gfx_renderer, x1, y1, x2, y2);
}

void gfx_rectangle(float x1, float y1, float x2, float y2)
{
    float tmp;
    SDL_FRect rect;

    SDL_SetRenderDrawColor(g_gfx_renderer, g_gfx_color.r, g_gfx_color.g, g_gfx_color.b, g_gfx_color.a);

    if (x1 == x2) {
        if (y1 == y2) {
            SDL_RenderPoint(g_gfx_renderer, x1, y1);
        } else {
            SDL_RenderLine(g_gfx_renderer, x1, y1, x1, y2);
        }
        return;
    } else if (y1 == y2) {
        SDL_RenderLine(g_gfx_renderer, x1, y1, x2, y1);
        return;
    }

    if (x1 > x2) {
        tmp = x1;
        x1 = x2;
        x2 = tmp;
    }
    if (y1 > y2) {
        tmp = y1;
        y1 = y2;
        y2 = tmp;
    }

    rect.x = x1;
    rect.y = y1;
    rect.w = x2 - x1;
    rect.h = y2 - y1;

    SDL_RenderRect(g_gfx_renderer, &rect);
}

void gfx_filled_rectangle(float x1, float y1, float x2, float y2)
{
    float tmp;
    SDL_FRect rect;

    SDL_SetRenderDrawColor(g_gfx_renderer, g_gfx_color.r, g_gfx_color.g, g_gfx_color.b, g_gfx_color.a);

    if (x1 == x2) {
        if (y1 == y2) {
            SDL_RenderPoint(g_gfx_renderer, x1, y1);
        } else {
            SDL_RenderLine(g_gfx_renderer, x1, y1, x1, y2);
        }
        return;
    } else if (y1 == y2) {
        SDL_RenderLine(g_gfx_renderer, x1, y1, x2, y1);
        return;
    }

    if (x1 > x2) {
        tmp = x1;
        x1 = x2;
        x2 = tmp;
    }
    if (y1 > y2) {
        tmp = y1;
        y1 = y2;
        y2 = tmp;
    }

    rect.x = x1;
    rect.y = y1;
    rect.w = x2 - x1;
    rect.h = y2 - y1;

    SDL_RenderFillRect(g_gfx_renderer, &rect);
}

void gfx_ellipse(float x, float y, float rx, float ry)
{
    float curr_x, curr_y;
    float d1, d2;
    float dx, dy;
    float rx_sq, ry_sq;

    SDL_SetRenderDrawColor(g_gfx_renderer, g_gfx_color.r, g_gfx_color.g, g_gfx_color.b, g_gfx_color.a);

    curr_x = 0;
    curr_y = ry;

    rx_sq = rx * rx;
    ry_sq = ry * ry;

    dx = 2 * ry_sq * curr_x;
    dy = 2 * rx_sq * curr_y;

    d1 = ry_sq - (rx_sq * ry) + (0.25f * rx_sq);

    while (dx < dy) {
        SDL_RenderPoint(g_gfx_renderer, x + curr_x, y + curr_y);
        SDL_RenderPoint(g_gfx_renderer, x - curr_x, y + curr_y);
        SDL_RenderPoint(g_gfx_renderer, x + curr_x, y - curr_y);
        SDL_RenderPoint(g_gfx_renderer, x - curr_x, y - curr_y);

        if (d1 < 0) {
            curr_x++;
            dx += (2 * ry_sq);
            d1 += dx + ry_sq;
        } else {
            curr_x++;
            curr_y--;
            dx += (2 * ry_sq);
            dy -= (2 * rx_sq);
            d1 += dx - dy + ry_sq;
        }
    }

    d2 = (ry_sq * ((curr_x + 0.5f) * (curr_x + 0.5f))) +
         (rx_sq * ((curr_y - 1.0f) * (curr_y - 1.0f))) -
         (rx_sq * ry_sq);

    while (curr_y >= 0) {
        SDL_RenderPoint(g_gfx_renderer, x + curr_x, y + curr_y);
        SDL_RenderPoint(g_gfx_renderer, x - curr_x, y + curr_y);
        SDL_RenderPoint(g_gfx_renderer, x + curr_x, y - curr_y);
        SDL_RenderPoint(g_gfx_renderer, x - curr_x, y - curr_y);

        if (d2 > 0) {
            curr_y--;
            dy -= (2 * rx_sq);
            d2 += rx_sq - dy;
        } else {
            curr_y--;
            curr_x++;
            dx += (2 * ry_sq);
            dy -= (2 * rx_sq);
            d2 += dx - dy + rx_sq;
        }
    }
}

void gfx_filled_ellipse(float x, float y, float rx, float ry)
{
    int curr_x, curr_y;
    int d1, d2;
    int dx, dy;
    int irx, iry;
    int ix, iy;
    int rx_sq, ry_sq;

    SDL_SetRenderDrawColor(g_gfx_renderer, g_gfx_color.r, g_gfx_color.g, g_gfx_color.b, g_gfx_color.a);

    ix = (int)x;
    iy = (int)y;
    irx = (int)rx;
    iry = (int)ry;

    curr_x = 0;
    curr_y = iry;

    rx_sq = irx * irx;
    ry_sq = iry * iry;

    dx = 2 * ry_sq * curr_x;
    dy = 2 * rx_sq * curr_y;

    d1 = ry_sq - (rx_sq * iry) + (rx_sq / 4);

    while (dx < dy) {
        SDL_RenderLine(g_gfx_renderer, (float)(ix - curr_x), (float)(iy + curr_y), (float)(ix + curr_x), (float)(iy + curr_y));
        SDL_RenderLine(g_gfx_renderer, (float)(ix - curr_x), (float)(iy - curr_y), (float)(ix + curr_x), (float)(iy - curr_y));

        if (d1 < 0) {
            curr_x++;
            dx += (2 * ry_sq);
            d1 += dx + ry_sq;
        } else {
            curr_x++;
            curr_y--;
            dx += (2 * ry_sq);
            dy -= (2 * rx_sq);
            d1 += dx - dy + ry_sq;
        }
    }

    d2 = (ry_sq * (curr_x + 1) * (curr_x + 1)) +
         (rx_sq * (curr_y - 1) * (curr_y - 1)) -
         (rx_sq * ry_sq);

    while (curr_y >= 0) {
        SDL_RenderLine(g_gfx_renderer, (float)(ix - curr_x), (float)(iy + curr_y), (float)(ix + curr_x), (float)(iy + curr_y));
        SDL_RenderLine(g_gfx_renderer, (float)(ix - curr_x), (float)(iy - curr_y), (float)(ix + curr_x), (float)(iy - curr_y));

        if (d2 > 0) {
            curr_y--;
            dy -= (2 * rx_sq);
            d2 += rx_sq - dy;
        } else {
            curr_y--;
            curr_x++;
            dx += (2 * ry_sq);
            dy -= (2 * rx_sq);
            d2 += dx - dy + rx_sq;
        }
    }
}