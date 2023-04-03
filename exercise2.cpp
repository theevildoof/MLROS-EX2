#include <lua.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <string>" << std::endl;
    return 1;
  }
  
  std::string input_string = argv[1];

  lua_State *L;
  L = luaL_newstate();
  luaL_openlibs(L);
  // Push a value of input_string to the stack
  lua_pushstring(L, input_string.c_str());
  // Pop the value from the stack and set it as a global variable
  lua_setglobal(L, "name");
  // Execute the lua script
  luaL_dostring(L, "print(name,'says hi')");

  // Send a int variable to the lua script
  lua_pushinteger(L, 10);
  lua_setglobal(L, "number");
  // Print the value from the lua script
  luaL_dostring(L, "print(number)");

  // Change the value of the variable in the lua script - Change the number here
  luaL_dostring(L, "number = 20");
  // Print the value from the lua script
  luaL_dostring(L, "print(number)");

  lua_close(L);
  return 0;
}
