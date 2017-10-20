#pragma once

std::vector<char> end_operators = { '=', '+', '-', '*', '/' ,'(',')','^' };
std::string operations = "+-*/^";
std::map<std::string, float> variablesMap;

bool DEBUG = false;
bool DEBUG2 = false;
bool DEBUG3 = false;


bool GotToExit = false;