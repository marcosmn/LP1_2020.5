#include "App.h"
#include <iostream>
#include <string>

App::App(const std::string& filename) : diario(filename)
{
}

int App::run(int argc, char* argv[])
{
    if (argc == 1)
    {
      return show_usage();
      }
}
