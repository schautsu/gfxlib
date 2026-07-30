## Introduction

The gfxlib library provides basic drawing and writing functions on SDL3 graphical programs.

As it is a very limited library, it is intended to be used for learning/academic purposes only.

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
<img width="610" height="518" alt="Screenshot_20260730_193202" src="https://github.com/user-attachments/assets/9178b006-7102-42a1-8326-37886942a145" />

## Disclaimer

This library is based on the 2013 work of Fabricio Sergio de Paula <fabricio.paula@gmail.com>.

His GFX library was used for some college works (graphical representation of recursion, memory management, linked lists etc.) and relied on SDL version 1.2, and after some time it became obsolete.

As I wanted to see my works alive again (sort of "surviving over the time"), this library was born.

## Contact and License
E-mail  Vinicius "schautsu" Schautz at <vinicius.schautz@hotmail.com> to contact the author.

This library is licensed under the zlib License, see the file LICENSE for details.
