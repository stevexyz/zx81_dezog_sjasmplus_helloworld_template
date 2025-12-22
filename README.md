# ZX81 assembler projects template

This repository is a starter template for developing ZX81 assembler programs using VS Code and the [DeZog extension](https://github.com/maziac/DeZog).

Quick start:
- Start VS Code (with "code ." inside this repo directory, or with a new codespace)
- Install the DeZog extension if not already done
- Open "zx81_hello_world.asm" and start debugging (select DeZog as the debugger if prompted)

Notes:
- To change the program name remember to change it also in the launch.json and tasks.json files in the .vscode directory for compilation and debugging to work
- To be able to set breakpoints in the source file verify that it has been recognized as assembler file in the language mode (and not e.g. as a Plain Text) in the bottom right of the window
- The project is already set up to use the new internal ZX81 DeZog emulator (see the project page for full configuration)
- The provided [sjasmplus](https://github.com/z00m128/sjasmplus) executable is enough to get started; see the linked project page for updates and documentation
- This repository is compatible with [GitHub Codespaces](https://docs.github.com/en/codespaces/quickstart), allowing development directly in the browser instead of a local installation. Click the green "<> Code" button above, select the “Codespaces” tab, and create a new codespace.

Further reading:
- [A nice guide on how to create a game](https://sinclairzxworld.com/viewtopic.php?t=4045), and [39 pages to get every byte out of the 1K ZX81!](https://www.sinclairzxworld.com/download/file.php?id=12563) from the unbeatable Dr Beep!
- [A handy reference of everything](https://problemkaputt.de/zxdocs.htm#zx80zx81) by Martin Korth

Advanced topics:
- [Details about the video systems](https://quix.us/timex/rigter/ZX@20Video@20Tutorial.html) by Wilf Ritger
- The "user code" (e.g. the example program) is normally executed in the slow mode of ZX81 (the one that is showing the screen) during the top and bottom borders video generation, so in a proper emulator the actual screen of the example program will be visualized after many iterations of the infinite loop execution (until border section ends). Please refer to a proper guide on how the ZX81 generates the TV output (many available on the internet, e.g. a deep [video series of DrMattRegan](https://www.youtube.com/watch?v=pVQJxV9JCSE))
