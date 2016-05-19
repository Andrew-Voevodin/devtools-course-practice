// Copyright 2016 Voevodin Andrew

#ifndef MODULES_VOEVODIN_ANDREW_SQCONVERTER_INCLUDE_COMPLEX_CALCULATOR_H_
#define MODULES_VOEVODIN_ANDREW_SQCONVERTER_INCLUDE_COMPLEX_CALCULATOR_H_

#include <string>
#include "include/converterarea.h"

class SQConverter {
public:
    SQConverter();
    std::string operator()(int argc, const char** argv);

private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double value;
        std::string from;
        std::string to;
    } Arguments;
};

#endif  // MODULES_VOEVODIN_ANDREW_SQCONVERTER_INCLUDE_COMPLEX_CALCULATOR_H_
