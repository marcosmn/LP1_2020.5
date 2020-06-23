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
    
    std::string action = argv[1];
    if (action == "add")
    {
        if (argc == 2)
        {
            add();
        }
        else
        {
            add(argv[2]);
        }
    }
    else if (action == "list")
    {
        list_messages();
    }
    else if (action == "search")
    {
    }
    else
    {
        return show_usage();
    }
    
    return 0;
}
