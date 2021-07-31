#include "Logger.hpp"
#include "LoggerTypes.hpp"
#include "../Core/CoreHelpers.hpp"

namespace UnderScore::Engine::Logger
{
	Logger& Logger::GetInstance()
	{
		static Logger logger;
		return logger;
	}

	void Logger::logError(const char* errorTxt)
	{
		this->logText(errorTxt, LoggerTypes::Error);
	}

	void Logger::logInfo(const char* infoTxt)
	{
		this->logText(infoTxt, LoggerTypes::Info);

	}
	void Logger::logWarning(const char* warningTxt)
	{
		this->logText(warningTxt, LoggerTypes::Warning);

	}
	void Logger::logDebug(const char* warningTxt)
	{
		this->logText(warningTxt, LoggerTypes::Debug);
	}

	void write(std::string txt)
	{
		auto path = std::filesystem::current_path().string() + "\\logs\\";
		if (!std::filesystem::is_directory(path) || !std::filesystem::exists(path)) { // Check if src folder exists
			std::filesystem::create_directory(path); // create src folder
		}

		auto pathLog = path + "log_" + UnderScore::Engine::Core::Helper_GetCurrentDate() + ".txt";
		const char* logPath = pathLog.c_str();
		std::fstream logFile = std::fstream(logPath, std::ios::app);
		logFile << txt;
		logFile.close();
	}

	void Logger::logText(const char* txt, LoggerTypes type)
	{
		std::string logFile;
		switch (type)
		{
		case LoggerTypes::Info:
			logFile += UnderScore::Engine::Core::Helper_GetCurrentDateAndTime() +" Info: " + txt + "\n";
			break;
		case LoggerTypes::Warning:
			logFile += UnderScore::Engine::Core::Helper_GetCurrentDateAndTime() + " Warning: " + txt + "\n";
			break;
		case LoggerTypes::Error:
			logFile += UnderScore::Engine::Core::Helper_GetCurrentDateAndTime() + " Error: " + txt + "\n";
			break;
		case LoggerTypes::Debug:
			logFile += UnderScore::Engine::Core::Helper_GetCurrentDateAndTime() + " Debug: " + txt + "\n";
			break;
		default:
			break;
		}

		std::thread logThread = std::thread(&write, logFile);
		logThread.detach();
	}
}
