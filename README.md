# project-align
Game engine in the C++ language that uses tildearrow/furnace.

## Dependencies 

Lua source code
[`https://www.lua.org/download.html`](https://www.lua.org/download.html)

You must have Lua libray installed on your system

`${LUA_INCLUDE_DIR}`
`${LUA_LIBRARY_DIR}`

### On linux
Linux should already have a cmake module installed of the system and can be added by call `find_package(Lua REQUIRED)

Static path:
`/usr/lib/liblua.so`
`/usr/local/lib/liblua.a`

### Windows 

Static path:
`C:/lua/include` `C:/lua/lib/lua54.lib`