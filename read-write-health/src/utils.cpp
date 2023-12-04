#include "utils.hpp"

const std::uint32_t utils::GetProcessId(const std::string& name)
{
	using raii_handle_t = std::unique_ptr<std::remove_pointer_t<HANDLE>, decltype(&CloseHandle)>;

	raii_handle_t snapshot(CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL), &CloseHandle);
	PROCESSENTRY32 entry{ sizeof(PROCESSENTRY32) };

	for (Process32First(snapshot.get(), &entry); Process32Next(snapshot.get(), &entry);)
		if (!name.compare(entry.szExeFile))
			return entry.th32ProcessID;

	return NULL;
}

const std::uint64_t utils::GetModuleBaseAddress(const std::string& name, const std::uint32_t& pid)
{
	using raii_handle_t = std::unique_ptr<std::remove_pointer_t<HANDLE>, decltype(&CloseHandle)>;

	raii_handle_t snapshot(CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid), &CloseHandle);
	MODULEENTRY32 entry{ sizeof(MODULEENTRY32) };

	for (Module32First(snapshot.get(), &entry); Module32Next(snapshot.get(), &entry);)
		if (!name.compare(entry.szModule))
			return reinterpret_cast<std::uint64_t>(entry.modBaseAddr);

	return NULL;
}