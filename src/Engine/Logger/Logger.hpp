#include <fstream>
#include <filesystem>
#include <thread>
#include <string>

#include "LoggerTypes.hpp"

#ifndef __LOGGER_H__
#define __LOGGER_H__

namespace UnderScore::Engine::Logger 
{
    class Logger 
    {
        public:
            static Logger& GetInstance();

            void logError(const char* errorTxt);
            void logInfo(const char* infoTxt);
            void logWarning(const char* warningTxt);
            void logDebug(const char* warningTxt);

        private:
            void logText(const char* txt, LoggerTypes type);
    };
}

#endif // __LOGGER_H__