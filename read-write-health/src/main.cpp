#include "includes.hpp"

/*
		로컬 플레이어 체력 구하기
		008FF2AC = value = 100
		ac_client.exe + 0x17e0a8 = 008FF1C0 + 0xEC = 008FF2AC
		
		1. 치트엔진을 통해 현재 체력 100을 검색 후, 실시간으로 변동되는 체력을 통해 결괏값를 줄여나감 (e.g. 100 -> 65 -> 30)
		2. 예시와 같은 0x008FF2AC 동적 주소를 찾았으면 해당 주소에 어떤 값이 접근하는지 조회해보면 mov ecx, [ebx + 0xEC]와 같이 offset(0xEC)을 찾을 수 있음
		3. ebx(008FF1C0)에 든 값을 스캔하면 static address를 찾을 수 있는데 해당 주소가 base + offset임
*/

int main()
{
	auto helper = std::make_unique<Helper>(PROCESS_NAME);

	const auto local_player = helper->ReadMemory<std::uint64_t>(helper->module_base + offsets::base_address);
	printf("[>] local_player address -> [ 0x%08llX ]\n", local_player);

	while (!GetAsyncKeyState(VK_END))
	{
		int new_health = 1337;
		helper->WriteMemory<std::uint32_t>(local_player + offsets::health, new_health);
		auto health = helper->ReadMemory<std::uint32_t>(local_player + offsets::health);
		printf("[>] health -> [ %d ]\n", health);
		Sleep(1000);
	}

	return 0;
}