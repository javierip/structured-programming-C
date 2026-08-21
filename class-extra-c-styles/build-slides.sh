#!/bin/sh
#
# Compila slides.tex (Beamer) a slides.pdf.
# POSIX sh: funciona igual en Linux y dentro de WSL, con sh o con bash.
#
#   ./build-slides.sh          compila
#   ./build-slides.sh clean    borra el PDF y los archivos auxiliares
#
set -eu

cd "$(dirname "$0")"

THEME_DIR=custom-beamer

if [ "${1:-}" = "clean" ]; then
    rm -f slides.pdf slides.aux slides.log slides.nav slides.out slides.snm \
          slides.toc slides.vrb slides.synctex.gz slides.fls slides.fdb_latexmk
    echo "Limpieza completa."
    exit 0
fi

if ! command -v pdflatex >/dev/null 2>&1; then
    echo "Error: no se encontró pdflatex. En Debian/Ubuntu (también en WSL):" >&2
    echo "  sudo apt install texlive-latex-recommended texlive-latex-extra \\" >&2
    echo "                   texlive-fonts-recommended texlive-pictures texlive-lang-spanish" >&2
    exit 1
fi

if [ ! -f "$THEME_DIR/beamerthemeUTN-BHI.sty" ]; then
    echo "Error: falta el tema UTN-BHI en $THEME_DIR/. Clonarlo con:" >&2
    echo "  git clone https://github.com/javierip/custom-beamer.git" >&2
    exit 1
fi

# El tema y sus imágenes se leen desde $THEME_DIR (repositorio aparte): no hace
# falta copiar nada dentro de este proyecto.
TEXINPUTS="./$THEME_DIR:${TEXINPUTS:-}"
export TEXINPUTS

# Dos pasadas: la segunda resuelve referencias e índice.
for pass in 1 2; do
    echo "Compilando (pasada $pass/2)..."
    pdflatex -interaction=nonstopmode -halt-on-error slides.tex >/dev/null || {
        echo "Error de compilación (últimas líneas de slides.log):" >&2
        tail -n 20 slides.log >&2
        exit 1
    }
done

echo "Listo: $(pwd)/slides.pdf"
