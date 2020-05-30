//
// Created by twome on 30/05/2020.
//

#ifndef CRYSTALUI_LOGGER_H
#define CRYSTALUI_LOGGER_H

#ifndef CRYSTALUI_DEBUGLOG
#define CRYSTALUI_DEBUGLOG true
#endif

#include <string>

namespace crystal {
    class Logger {
    private:
        static void print(const std::string &prefix, const std::string &message);

    public:
        static void error(const std::string &message);

        static void warn(const std::string &message);

        static void info(const std::string &message);
    };
};

#endif //CRYSTALUI_LOGGER_H
