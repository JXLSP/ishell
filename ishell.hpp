#ifndef __ISHELL_H_

#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef history_command // 命令行历史
{
    size_t index; // 索引
    string start_time; // 执行时间
    string line; // 命令行内容
} history_command;

size_t history_command_pos = 0;

vector<history_command> history_command_line;

unordered_map<string, string> envs;

enum status
{
    INIT = 1,
    PIPE = 2,
    WORD = 3,
};

struct termios old_attr, new_attr;

void init_environment(int argc, char **argv);

string get_env(string name);

string get_path();

void updated_pwd(string pass);

void env();

void cd_command(vector<string> &command);

void print_command_line_prefix();

#endif
