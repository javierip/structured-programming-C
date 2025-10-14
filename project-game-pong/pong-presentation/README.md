# Pong Project Evolution Presentation

This repository contains the source code for a LaTeX Beamer presentation that documents the evolution of a Pong game project through three distinct implementations.

## Presentation Overview

The presentation covers three stages of development:
1.  **Console Pong**: A simple, cross-platform version written in C that runs in the terminal.
2.  **Visual Studio Project**: The same console game structured within a professional Visual Studio solution.
3.  **Graphical SDL3 Version**: A modern implementation using C++ and the SDL3 library for graphics and event handling.

## How to Build

To compile the presentation and generate the PDF, you need a working TeX distribution (like TeX Live) that includes `pdflatex` and `bibtex`.

This project also requires a custom Beamer theme. You can download it from the following repository:
```bash
git clone https://github.com/javierip/custom-beamer.git
```
After cloning, copy the `beamerthemeUTN-BHI.sty` file and the `theme/` directory into this project's root directory.

Once the theme is in place, simply run the build script from the root directory:
```bash
sh run.sh
```

The final PDF will be available at `output/main.pdf`.

## Project Structure

-   `main.tex`: The main LaTeX source file for the presentation.
-   `references.bib`: The bibliography file containing all citations.
-   `beamerthemeUTN-BHI.sty`: The custom Beamer theme for the presentation.
-   `run.sh`: The compilation script.
-   `figures/`: Contains images used in the presentation slides.
-   `theme/`: Contains assets for the Beamer theme.
-   `output/`: The directory where all compiled files, including the final PDF, are placed.
