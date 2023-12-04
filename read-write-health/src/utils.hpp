#pragma once
#include "includes.hpp"

namespace utils
{
	const std::uint32_t GetProcessId(const std::string& name);
	const std::uint64_t GetModuleBaseAddress(const std::string& name, const std::uint32_t& pid);
}