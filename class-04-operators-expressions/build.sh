#!/bin/bash

OUTPUT_DIR="output"
OUTPUT_BIN="$OUTPUT_DIR/main"

mkdir -p "$OUTPUT_DIR"

gcc main.c -o "$OUTPUT_BIN" -lm

if [ $? -eq 0 ]; then
    echo "Build successful. Running: $OUTPUT_BIN"
    ./"$OUTPUT_BIN"
else
    echo "Build failed."
    exit 1
fi
