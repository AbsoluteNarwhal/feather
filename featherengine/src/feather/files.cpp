#include "feather/files.h"
#include "feather/core.h"
#include "feather/log.h"
#include <sstream>
#include <fstream>
#include <iostream>

namespace ft {
    const std::string getFileStr(const char *path) {
        std::string text;
        std::ifstream vfile;
        vfile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

        try {
            vfile.open(path);
            std::stringstream vTextStream;
            vTextStream << vfile.rdbuf();
            vfile.close();
            text = vTextStream.str();	
        }
        catch(std::ifstream::failure e) {
            FT_CORE_LOG_WARN("Could not open file at path '{0}'\n{1}", path, e.what());
            return nullptr;
        }

        return text;
    }
}