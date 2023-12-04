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
		[in]  HANDLE  hProcess,				// ��� ���μ����� �ڵ�
		[in]  LPCVOID lpBaseAddress,		// �о�� �����Ͱ� �ִ� �޸� �ּ�
		[out] LPVOID  lpBuffer,				// lpBaseAddress�� �ִ� �����͸� �ޱ� ���� ���� �ּ�
		[in]  SIZE_T  nSize,				// ���� �������� ũ��
		[out] SIZE_T  *lpNumberOfBytesRead	// �޾ƿ� �������� ũ�⸦ ���� (NULL = ����)
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