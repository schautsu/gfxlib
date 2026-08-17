## Introduction

The gfxlib library provides basic drawing and writing functions on SDL3 graphical programs.

It is originally made to be used for learning/academic purposes.

## Installation

### Unix/Linux

Before using this library, you must install the following libraries:
- `make`
- `SDL3`
- `SDL3_ttf`

When done, within the `gfx` directory, type on your terminal:
```
make
```
This runs the commands inside a `Makefile` that create `gfx.o` and `libgfx.a` files as a result.

## Usage

All the files you need are the ones within the `gfx` directory of this project.

First, make sure all GFX library files are at YOUR-PROGRAM-DIR/gfx directory.

Then, your program must include gfx.h (i.e., `#include "gfx/gfx.h"`) and be linked against `-Lgfx -lgfx -lSDL3 -lSDL3_ttf` flags.

## Example

For an example, check the `example.c` file and compile it with the `Makefile` which contains the compile command, both within this project root directory.

The graphic window should display something like this:

<img width="610" height="518" alt="Program example.c screenshot" src="https://github.com/user-attachments/assets/c9fd65de-0e16-4374-add1-0063a90dd7a7" />

## Disclaimer

This library is a 2013 work by Fabricio Sergio de Paula <fabricio.paula@gmail.com> using SDL version 1.2.

Ported to SDL3 by Vinicius "schautsu" Schautz <vinicius.schautz@hotmail.com> in 2026.

This library is being updated to keep past works functional over time and to be used for new ones.

## Contact and License
E-mail Fabricio Sergio de Paula at <fabricio.paula@gmail.com> to contact the author.

This library is licensed under the zlib License, see the file LICENSE for details.
