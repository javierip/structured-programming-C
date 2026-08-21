# C programming styles — classic vs. modern

Class material for Informática I (Electrical Engineering): a comparison between
a "classic" C style (the one typically used in an exam) and a "modern" C99
style (the one expected in real-world code), using a files + arrays + insertion
sort exercise as a case study.

> **Note:** the slides (`slides.tex`) and the code comments are written in
> **Spanish**, since that is the language used in class. Only this README is in
> English.

## Contents

- `slides.tex` — Beamer presentation (in Spanish) with the comparison.
- `codigo/clasico.c` — Full solution in classic style (C99).
- `codigo/moderno.c` — Same solution in modern style (C99).
- `codigo/c23.c` — The modern version, adding **C11** (`static_assert`) and
  **C23** features (`bool`/`true`/`false` and `nullptr` as keywords,
  `constexpr`, the `[[nodiscard]]` attribute).
- `build-slides.sh` — Build script for the slides (Linux and WSL).

## Requirements

A LaTeX distribution (TeX Live or similar) providing Beamer, `listings`,
`booktabs`, `tabularx`, `ragged2e`, `microtype` and the Spanish `babel` files,
plus a C compiler (GCC or Clang).

### Beamer theme (external repository)

The slides use the UTN-BHI theme, which lives in a separate repository and is
**not** part of this one. Clone it inside this directory (it is listed in
`.gitignore`, so it is never committed here):

```bash
git clone https://github.com/javierip/custom-beamer.git
```

That leaves the theme in `custom-beamer/`, which is where `build-slides.sh`
expects it — nothing needs to be copied into this directory. If you compile by
hand instead, point `TEXINPUTS` at it (see below).

### Linux (Debian/Ubuntu)

```bash
sudo apt update
sudo apt install build-essential \
                 texlive-latex-recommended \
                 texlive-latex-extra \
                 texlive-fonts-recommended \
                 texlive-pictures \
                 texlive-lang-spanish
```

On Fedora: `sudo dnf install gcc texlive-scheme-medium texlive-babel-spanish`.

### Windows (WSL)

Everything below is meant to run inside WSL, so the same commands work on
Windows and on Linux. Install a distribution once (from PowerShell):

```powershell
wsl --install -d Ubuntu
```

Then open the Ubuntu shell and run the `apt install` command from the Linux
section above.

The Windows filesystem is mounted under `/mnt/`, so this directory is reachable
from WSL as:

```bash
cd /mnt/c/Users/<your-user>/Documents/GitHub/structured-programming-C/class-extra-c-styles
```

## Building the slides

### With the build script (recommended)

`build-slides.sh` runs the two `pdflatex` passes for you. It is plain POSIX
`sh`, so it behaves the same on Linux and inside WSL, with either `sh` or
`bash`:

```bash
sh build-slides.sh          # build slides.pdf
sh build-slides.sh clean    # remove the PDF and the auxiliary files
```

Or, after `chmod +x build-slides.sh` (needed once, and often already lost when
the repository lives on a Windows drive), simply `./build-slides.sh`.

The script checks that the theme is in place (and tells you the `git clone`
command if it is not), points `TEXINPUTS` at `custom-beamer/` so the theme and
its logos are found, and hides the LaTeX output while things go well; if a pass
fails, it prints the last lines of `slides.log` and exits with an error.

From Windows you can also call it without opening a WSL shell first:

```powershell
wsl sh -c "cd /mnt/c/Users/<your-user>/Documents/GitHub/structured-programming-C/class-extra-c-styles && sh build-slides.sh"
```

### Manually

From the `class-extra-c-styles` directory (in a Linux shell or inside WSL).
`TEXINPUTS` is what makes `\usetheme{UTN-BHI}` and the theme images resolve
from the cloned repository; the trailing colon keeps the default search path:

```bash
export TEXINPUTS="./custom-beamer:"
pdflatex slides.tex
pdflatex slides.tex   # second pass, for references and the outline
```

This produces `slides.pdf`.

If `latexmk` is available, a single command does both passes and cleans up:

```bash
TEXINPUTS="./custom-beamer:" latexmk -pdf slides.tex
latexmk -c              # remove auxiliary files (keeps the PDF)
```

To open the resulting PDF from WSL with the default Windows viewer:

```bash
explorer.exe slides.pdf
```

On Linux, use `xdg-open slides.pdf`.

### Theme adjustments made in the preamble

The UTN-BHI theme is designed for 4:3 slides, while this deck is 16:9, so
`slides.tex` overrides a few things after `\usetheme{UTN-BHI}` (preamble only —
no slide content is affected):

- the background image is centred at page height instead of being stretched, so
  the logo keeps its proportions;
- an empty footline reserves ~0.9 cm at the bottom, so text never runs over the
  logo;
- a global `\lstset` applies the `myC++Style` listing style in C at
  `\scriptsize`, which is what makes the code fit in the two-column comparison
  slides;
- tables are set one size smaller and unjustified, to avoid stretched spacing
  and hyphenated words in narrow columns.

## Building and running the example code

```bash
cd codigo
gcc -std=c99 -Wall -Wextra -o clasico clasico.c
gcc -std=c99 -Wall -Wextra -o moderno moderno.c

# C23 (requires GCC 13+; use -std=c23 on GCC 15+ / Clang 18+)
gcc -std=c2x -Wall -Wextra -o c23 c23.c

./clasico
./moderno
./c23
```

The three programs do the same thing: they generate `archivo1.txt` with N
random integers in [1000, 2000], load them into an array, sort it by insertion
and print it. In addition, `c23.c` fails at **compile time** if the
`RANGO_MAX > RANGO_MIN` invariant is broken (via `static_assert`), and emits a
warning if the return value of a `[[nodiscard]]` function is ignored.

## Suggested activity

See the last slide of `slides.tex`: compare the `-Wall -Wextra` warnings
between both versions and rewrite `cargarArchivo` applying the principles of
the modern style.
