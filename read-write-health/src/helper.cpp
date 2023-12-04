#include "helper.hpp"

Helper::Helper(const char* process_name)
{
	pid = utils::GetProcessId(process_name);
	printf("[>] process id -> [ %d ]\n", pid);

	module_base = utils::GetModuleBaseAddress(process_name, pid);
	printf("[>] module base -> [ 0x%08llX ]\n", module_base);

	handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	printf("[>] process handle -> [ %d ]\n\n", (std::uint32_t)handle);
}