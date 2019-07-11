/*
	any
		https://en.cppreference.com/w/cpp/utility/any
		http://occamsrazr.net/tt/322

		+ operator=
			: assigns an any object

		+ type_info

		+ emplace
		+ reset
		+ swap

		# std::any_cast
		# std::make_any
		# std::swap
*/

#include <any>
#include <iostream>
#include <string>


int main()
{
    std::cout << std::boolalpha;


	std::any aVal = 1;

	{	// any type
		std::cout << aVal.type().name() << ": " << std::any_cast<int>(aVal) << std::endl;

		aVal = 3.14;
		std::cout << aVal.type().name() << ": " << std::any_cast<double>(aVal) << std::endl;

		aVal = true;
		std::cout << aVal.type().name() << ": " << std::any_cast<bool>(aVal) << std::endl;
	} 

	{	// emplace
		aVal.emplace<std::string>("hello world");
		std::cout << aVal.type().name() << ": " << std::any_cast<std::string>(aVal) << std::endl;
	}
    
	{	// bad_any_cast
		try
		{
			aVal = 1;
			std::cout << std::any_cast<float>(aVal) << std::endl;
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}

		float* aRet = std::any_cast<float>(&aVal);		// noexcept
		if (aRet != nullptr)
		{
			std::cout << "noexcept : casted : " << (*aRet) << std::endl;
		}
		else
		{
			std::cout << "noexcept : bad cast" << std::endl;
		}
	}
	
	{	// has value
		aVal = 1;
		if (aVal.has_value())
		{
			std::cout << aVal.type().name() << std::endl;
		}
	}

	{	// reset
		aVal.reset();
		if (!aVal.has_value())
		{
			std::cout << "no value" << std::endl;
		}
	}

	{	// pointer to contained data
		aVal = 1;
		int* aPtr = std::any_cast<int>(&aVal);
		std::cout << *aPtr << std::endl;
	}
    
	return 0;
}
