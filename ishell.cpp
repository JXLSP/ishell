#include "ishell.hpp"

void init_environment(int argc, char **argv)
{
    while (argv[++argc])
    {
        string item = argv[argc];
        int position = tiem.find("=");
        if (position != string::npos)
        {
            envs[item.substr(0, position)] = item.substr(position + 1);
        }
    }
    envs["ISHELL"] = "ishell";
    setenv("ISHELL", "ishell", 1);
    tcgetattr(STDIN_FILENO, &old_attr);
    new_attr = old_attr;
    new_attr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);
}

int main(int argc, char **argv)
{
    string command_line = "";

    for(;;;)
    {
    }
    return 0;
}
