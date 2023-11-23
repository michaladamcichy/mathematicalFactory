/*
* Simple console calculator app.
* Type in two argument mathematical operations: (+, -, * or /), press ENTER, and see result.
* If any of numbers isn't an integer, both numbers will be treated as double.
* Else both will be treated as long.
* 
* There's a log of operations and results written to "output.csv" file.
* You should exit the app by typing 'exit' to have the file saved.
*/

#include "pch.h"
#include "MathematicalParser.h"
#include "Logger.h"

static constexpr auto initialMessage{ 
R"(To exit type 'exit'.
Available binary operators: '+', '-', '*', '/'.
Make your calculations below:)" };

int main()
{
	Logger logger;
	logger.Log(initialMessage);

	while (true)
	{
		std::string input;
		std::getline(std::cin, input);
		
		if (input == "")
			continue;

		if (input == "exit")
			break;

		try
		{
			MathematicalParser mathematicalParser;
			const auto [operationName, result] = mathematicalParser.Parse(input);
			logger.Log("=", result);
			logger.LogOperationToFile(operationName, result);
		}
		catch (...)
		{
			logger.Log("invalid input");
		}
	}
}
