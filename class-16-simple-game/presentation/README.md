# Simple Pong — Presentation

A LaTeX/Beamer presentation that explains the **Simple Pong** example of
`class-16-simple-game`: how a minimal Pong game integrates the concepts seen
from week 9 to 13, and how the same logic is written in two versions (console
and SDL3).

The slides use the **UTN-BHI** custom Beamer theme from
<https://github.com/javierip/custom-beamer>.

## Building

You need a TeX distribution with `pdflatex` and `bibtex` (e.g. TeX Live), plus
`git` (to fetch the theme automatically).

```bash
sh run.sh
```

`run.sh` will:

1. Download the custom theme (`beamerthemeUTN-BHI.sty` + `theme/`) from
   `custom-beamer` if it is not already present.
2. Compile the presentation with the passes needed to resolve citations.

The final PDF is written to `output/main.pdf`.

### Building on Windows with WSL

If you are on Windows, the easiest way to get `pdflatex` and `bibtex` is through
WSL (Windows Subsystem for Linux). From a PowerShell prompt:

```powershell
wsl --install -d Ubuntu   # only the first time; then reboot if asked
```

Open the **Ubuntu** terminal and install a TeX distribution plus git (one time):

```bash
sudo apt update
sudo apt install -y texlive-latex-recommended texlive-latex-extra \
                    texlive-fonts-recommended texlive-lang-spanish git
```

Then go to this folder through the mounted Windows drive and build:

```bash
# Replace <path-to-repo> with wherever you cloned the repository.
cd /mnt/c/<path-to-repo>/class-16-simple-game/presentation
sh run.sh
```

WSL mounts your Windows drives under `/mnt`, so e.g. `C:\Users\you\repos` becomes
`/mnt/c/Users/you/repos`.

The PDF appears at `output/main.pdf`, which you can open from Windows at
`...\class-16-simple-game\presentation\output\main.pdf`.

> Tip: `run.sh` uses LF line endings. If you edited it on Windows and WSL
> complains about `\r`, run `sed -i 's/\r$//' run.sh` once.

### Getting the theme manually

If you prefer to add the theme by hand:

```bash
git clone https://github.com/javierip/custom-beamer.git
```

Then copy `beamerthemeUTN-BHI.sty` and the `theme/` directory into this folder.

## Files

```text
presentation/
├── main.tex         # the slides
├── references.bib   # bibliography
├── run.sh           # build script (fetches the theme, compiles)
└── README.md        # this file
```

The theme files (`beamerthemeUTN-BHI.sty`, `theme/`) and the `output/` folder
are not tracked in git — they are produced/fetched at build time.
