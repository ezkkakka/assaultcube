#include "includes.hpp"

/*
		���� �÷��̾� ü�� ���ϱ�
		008FF2AC = value = 100
		ac_client.exe + 0x17e0a8 = 008FF1C0 + 0xEC = 008FF2AC
		
		1. ġƮ������ ���� ���� ü�� 100�� �˻� ��, �ǽð����� �����Ǵ� ü���� ���� �ᱣ���� �ٿ����� (e.g. 100 -> 65 -> 30)
		2. ���ÿ� ���� 0x008FF2AC ���� �ּҸ� ã������ �ش� �ּҿ� � ���� �����ϴ��� ��ȸ�غ��� mov ecx, [ebx + 0xEC]�� ���� offset(0xEC)�� ã�� �� ����
		3. ebx(008FF1C0)�� �� ���� ��ĵ�ϸ� static address�� ã�� �� �ִµ� �ش� �ּҰ� base + offset��
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