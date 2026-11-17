# 🖼️ Script-Driven Image Editor (C++)

![C++](https://img.shields.io/badge/C%2B%2B-00599C?logo=cplusplus&logoColor=white) ![Grade](https://img.shields.io/badge/Grade-18%2F20-green)

My **first programming project**: a C++ program that reads **command scripts ("scrims")** and runs them as an image-processing pipeline to create and edit PNG images.

> Project for **Programming (PROG)** — BSc in Informatics and Computing Engineering (L.EIC), FEUP, 2024/2025. **Grade: 18/20.**

## ✨ Commands
| Command | Description |
|---|---|
| `blank` | Create a new image with a given size and background color |
| `open` / `save` | Read and write PNG files |
| `invert` | Invert all colors (negative) |
| `to_gray_scale` | Convert to grayscale |
| `replace` | Replace one color with another |
| `fill` | Fill a rectangle with a color |
| `h_mirror` / `v_mirror` | Mirror horizontally or vertically |
| `add` | Overlay another image, treating one "neutral" color as transparent |
| `move` | Shift the image, filling the gap with the background color |
| `slide` | Cyclic shift: what leaves one side comes back on the other |

## 🧩 Design
- **`Image`** and **`Color`**: an image is a grid of RGB pixels
- **`Command`**: an abstract class with a virtual `apply(Image*)` method, and one subclass per operation (**Command pattern**)
- **`ScrimParser`**: turns a script file into a list of `Command` objects
- **`Scrim`**: runs the commands in order
- **`PNG`**, **`Logger`**, **`Utils`**: file I/O, error reporting and helpers

To add a new operation, you only write a new `Command` subclass and register it in the parser.

## 📝 Example script
```
blank 200 100 255 255 255
fill 20 20 50 50 255 0 0
h_mirror
save output/example.png
```

## 👥 Authors
André Rocha (up202407636) · Gustavo Monteiro (up202456754)
