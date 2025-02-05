#pragma once
#include <concepts>
namespace SKC::concepts {
	//typing concepts.
	template <typename T> concept isNumber = std::is_integral_v<T> || std::is_floating_point_v<T>;
	template <typename T> concept isString = std::is_convertible_v<T, std::string> || std::is_convertible_v<T,std::wstring>;
	// above is std::string, [cv qualifided] char or any array of it;

	template <typename T> concept isAlNum  = isNumber<T> || isString<T>; 

	//interface for the printable 
	template <typename T> concept parsable_cimple = requires(T t) { { t.ToString() } -> isString; };
	template <typename T> concept parsable_imple  = requires(T t) { { t.toString() } -> isString; };
	template <typename T> concept parsable        = parsable_cimple<T> || parsable_imple<T>;
	//this is saying if T has a ToString or toString method publically avalible then it is ok to print.. 
	template <typename T> concept printable       = parsable<T> || isAlNum<T>;

}