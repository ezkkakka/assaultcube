## read-write-health
1. get process id (Process32First, Process32Next)  
2. get module base address (Module32First, Module32Next)  
3. get handle of target process (OpenProcess)  
4. read, write to health address (ReadProcessMemory, WriteProcessMemory)
---
external의 특성상 위와 같은 작업이 1순위로 필요함 (말그대로 외부에서 특정 프로세스에 대한 권한을 얻고 해당 프로세스에 대한 메모리를 읽고, 쓰는 작업을 하기 때문)  

위와 같은 과정을 통해 체력 값을 100 -> 1337로 변경하는 간단한 코드입니다.  

### example
![1337](https://github.com/ezkkakka/echo-poc/assets/118009522/cc7b84dd-0d4c-4d93-8f32-0cc727c4b897)