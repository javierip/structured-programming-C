#!/bin/bash

# This script compiles the LaTeX presentation without user interaction
# It uses pdflatex and ensures all output files are placed in the 'output' directory.

set -e # Exit immediately if a command exits with a non-zero status

OUTPUT_DIR="output"
MAIN_FILE="main"

# Create output directory if it doesn't exist
mkdir -p "$OUTPUT_DIR"

echo "--- Starting LaTeX compilation ---"

# Clean previous files (suppress errors if files don't exist)
rm -f *.aux *.bbl *.blg *.dvi *.log *.nav *.out *.snm *.toc *.eps
rm -f "$OUTPUT_DIR"/*

# Copy bibliography file to output directory for bibtex
cp references.bib "$OUTPUT_DIR/"

# Use pdflatex with non-interactive mode to avoid prompts
echo "--- Compiling LaTeX (pass 1) ---"
pdflatex -interaction=nonstopmode -output-directory="$OUTPUT_DIR" "$MAIN_FILE.tex"

# Run bibtex (suppress output and errors)
echo "--- Running BibTeX ---"
cd "$OUTPUT_DIR"
bibtex "$MAIN_FILE" || true
cd ..

# Run pdflatex again to resolve citations
echo "--- Compiling LaTeX (pass 2) ---"
pdflatex -interaction=nonstopmode -output-directory="$OUTPUT_DIR" "$MAIN_FILE.tex"

# Final pass to ensure everything is resolved
echo "--- Compiling LaTeX (final pass) ---"
pdflatex -interaction=nonstopmode -output-directory="$OUTPUT_DIR" "$MAIN_FILE.tex"

echo "---"
echo "Compilation complete!"
echo "Output PDF: $OUTPUT_DIR/$MAIN_FILE.pdf"

# Check if PDF was created successfully
if [ -f "$OUTPUT_DIR/$MAIN_FILE.pdf" ]; then
    echo "✓ PDF generated successfully"
else
    echo "✗ PDF generation failed - check the log file: $OUTPUT_DIR/$MAIN_FILE.log"
    exit 1
fi