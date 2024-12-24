#include <iostream>
#include "lua.hpp"

int main() {
    lua_State* L = luaL_newstate(); // Create a new Lua state
    luaL_openlibs(L);              // Load Lua standard libraries

    // Execute a Lua script
    if (luaL_dostring(L, "print('Hello from Lua!')")) {
        std::cerr << "Error: " << lua_tostring(L, -1) << std::endl;
        lua_pop(L, 1); // Remove error message from the stack
    }

    // Clean up and close the Lua state
    lua_close(L);
    return 0;
}
