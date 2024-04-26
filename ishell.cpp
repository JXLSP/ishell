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

string get_env(string name)
{
    if (envs.find(name) != envs.end())
    {
        return envs[name];
    }
    return "";
}

string get_path()
{
    char path[2048]{0}
    getcwd(path, 2048);
    return path;
}

void env()
{
    for (const auto &item : envs)
    {
        cout << item.first << "==" << item.second << endl;
    }
}

void updated_pwd(string pass)
{
    envs["OLDPWD"] = envs["PWD"];
    envs["PWD"] = pass;
}

void cd_command(vector<string> &command)
{
    string path = "";
    if (command.size() == 1)
    {
        path = get_env("HOME");
    }
    else 
    {
        path = command[1];
    }

    if (path == ".")
    {
        return;
    }

    if (path == "~")
    {
        path = get_env("HOME");
    }
    else if (path == "-")
    {
        path = get_env("OLDPWD");
        count << path << endl;
    }

    int ret = chdir(path.c_str());
    if (ret)
    {
        cout << "ishell : cd : " << path << ":" << strerror(errno) << endl;
        return;
    }
    updated_pwd(path);
}

int main(int argc, char **argv)
{
    string command_line = "";

    for(;;;)
    {
    }
    return 0;
}
