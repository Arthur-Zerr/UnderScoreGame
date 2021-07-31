#include "CoreHelpers.hpp"

namespace UnderScore::Engine::Core
{
    std::string Helper_GetCurrentDateAndTime()
    {
        std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm tm = *std::localtime(&time);
        constexpr int bufsize = 265;
        char buf[bufsize];
        std::strftime(buf, bufsize, "%d_%m_%y %H:%M:%S", &tm);

        return std::string(buf);
    }

    std::string Helper_GetCurrentDate()
    {
        std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm tm = *std::localtime(&time);
        constexpr int bufsize = 265;
        char buf[bufsize];
        std::strftime(buf, bufsize, "%d_%m_%y", &tm);

        return std::string(buf);
    }
}