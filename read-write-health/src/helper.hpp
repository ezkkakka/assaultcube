#pragma once
#include "includes.hpp"
#include "structs.hpp"

class Helper
{
private:
	HANDLE handle = nullptr;

public:
	std::uint32_t pid{};
	std::uint64_t module_base{};

	Helper() = default;
	Helper(const char* process_name);
	~Helper()
	{
		CloseHandle(handle);
	}

	/*
	BOOL ReadProcessMemory(
		[in]  HANDLE  hProcess,				// 대상 프로세스의 핸들
		[in]  LPCVOID lpBaseAddress,		// 읽어올 데이터가 있는 메모리 주소
		[out] LPVOID  lpBuffer,				// lpBaseAddress에 있는 데이터를 받기 위한 버퍼 주소
		[in]  SIZE_T  nSize,				// 받을 데이터의 크기
		[out] SIZE_T  *lpNumberOfBytesRead	// 받아온 데이터의 크기를 저장 (NULL = 무시)
	);
	*/

	template <typename T>
	T ReadMemory(const std::uint64_t target_addr)
	{
		if (!target_addr) return T();

		T buffer;
		ReadProcessMemory(this->handle, (LPCVOID)target_addr, &buffer, sizeof(T), nullptr);
		return buffer;
	}

	template <typename T>
	void WriteMemory(const std::uint64_t target_addr, T data)
	{
		if (!target_addr) return;

		WriteProcessMemory(this->handle, (LPVOID)target_addr, &data, sizeof(T), nullptr);
	}
};