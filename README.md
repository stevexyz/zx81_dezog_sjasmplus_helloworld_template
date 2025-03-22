# ZX81 assembler projects template

This project to jumpstart ZX81 assemler developments with a modern integrated IDE/debugger.

Note that before debugging yuu need to compile the program with sjasmplus: sample script and executable are provided with all the options, but you can install the full sjasmplus and update the paths (DOS/Windows files untested for now).

Project is setup to use the internal DeZog emulator.

Required to be installed: Visual Studio Code with DeZog extension (https://github.com/maziac/DeZog). Recommended full sjasmplus (https://github.com/z00m128/sjasmplus).

Notes:
- To change the program name remember to change it also in the launch.json file in the .vscode directory.
- When starting debug be sure to select DeZog
- To be able to set breakpoints in the source file verify that it has beeen recognized as assembler file in the language mode (and not e.g. as a Plain Text) in the bottom right of the window

