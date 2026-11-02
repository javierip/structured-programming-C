# Classes 26 and 27 - Files

Examples of sequential access (class 26) and direct access (class 27) files in C.

## Files

- **[text-example.c](./text-example.c)**: Sequential access to a text file. Creates `myfile.txt` with `fprintf`, reads it line by line with `fgets` and word by word with `fscanf`, and gets its size with `fseek`/`ftell`.
- **[structures-example.c](./structures-example.c)**: Direct access to a binary file of structures. Saves an array of `Student` to `data.bin` with `fwrite` and reads it back with `fread`. Then uses `fseek` to read and update a single record in place (mode `"r+b"`).

## Build

```sh
gcc text-example.c -o text-example.exe
gcc structures-example.c -o structures-example.exe
```

## Run

```sh
./text-example.exe
./structures-example.exe
```
