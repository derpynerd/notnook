# notnook
**_notnook_** is a notebook for note-taking written in C using -
- [Raylib](https://github.com/raysan5/raylib) as the rendering engine
- [Clay](https://github.com/nicbarker/clay) as the UI Layout library
- [Sqlite](https://www.sqlite.org/index.html) as the database

Info - 
- A simple & super-fast note-taking app 

![Screenshot of notenook UI](screenshots/notnook-v5.png)
_Screenshot of notnook UI (WIP)_

Development Setup (WIP) - # I do realize this is terribly cumbersome
- Git clone this repository - `git clone https://github.com/derpynerd/notnook.git`
- `w64devkit 2.0.0` -
    - Download from [here](https://github.com/skeeto/w64devkit/releases/download/v2.0.0/w64devkit-x64-2.0.0.exe)
    - Extract to `C:/`
- `Raylib v5.5` - 
    - Download files from [here](https://github.com/raysan5/raylib/releases/download/5.5/raylib-5.5_win64_mingw-w64.zip)
    - [Optional] Copy all header files from `raylib-5.5_win64_mingw-w64/include` folder to `notnook/includes/renderer`
    - Copy `.dll` & `.a` files from `raylib-5.5_win64_mingw-w64/lib` to `C:\w64devkit\x86_64-w64-mingw32\lib` 
- `Clay v0.12` - 
    - Download `clay.h` from [here](https://github.com/nicbarker/clay/releases/download/v0.12/clay.h) to `notnook/includes` 
    - Copy all files from [here](https://github.com/nicbarker/clay/tree/main/renderers/raylib) to `notnook/includes/renderer`
- `Sqlite v3.47.2` -
    - Download `.dll` from [here](https://www.sqlite.org/2024/sqlite-dll-win-x64-3470200.zip) to `C:\w64devkit\x86_64-w64-mingw32\lib`
    - Download header files from [here](https://www.sqlite.org/2024/sqlite-amalgamation-3470200.zip)
    - Copy `sqlite3.h` to `notnook/includes`

TODO - 
- ~~Fix file structure~~
- ~~Common file for constants, reused components~~
- ~~Retrieve & store notes from database~~
- ~~Display all notes in left panel dynamically~~
- Fix note hover pointer update logic 
- Implement GetNote by NoteId query
- ~~Fix text getting cut-off (Clay render bug?)~~
- ~~Footer to display created timestamp (stored in db)~~
- ~~Footer to show "Save" button~~ (disabled when no text in text editor)
- Basic Text Editor implementation
- Fix scrollbar logic 
- ~~Local cache impl (redis?) to store cached notes~~ OR just store local state until update - Work out when to update
- Quick start guide (Setup + run code locally) - CMake(?)