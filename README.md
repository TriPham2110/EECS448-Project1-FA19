Repository for EECS448 Project 1: Battleship
how we got this to compile on windows:

download msys2 

in mingw64 shell or msys2 shell run these commands:

pacman -Syu

then

pacman -Su

then

pacman -S mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-gtkmm3
pacman -S pkg-config
pacman -S mingw-w64-x86_64-libffi
pacman -S mingw-w64-x86_64-make
pacman -Sy git
pacman -Sy make
pacman -Sy cmake

then

export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/mingw64/lib/pkgconfig

then

open mingw64
cd /path/to/battleship

then

add /path/to/msys2/mingw64/bin to $path (my msys2/mingw64/bin was in C:\)

make

and it will take a while and have lots of warnings but will (hopefully) compile

For mac:

a similar yet slightly simpler process using homebrew instead of mingw64
but similar pkg_config_path commands
