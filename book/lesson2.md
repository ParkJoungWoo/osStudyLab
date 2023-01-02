# 운영체제의 개념과 구조

**복습**

운영체제의 역할 : 애플리케이션 프로그램을 제공하고 H/W와 S/W사이에서 매개 역할을 한다.

간단한 운영체제 계층
```
[사용자 1] [사용자 2] ...
↕️           ↕️
[시스템, 애플리케이션]
    ↕️
[운영체제]
    ↕️
[하드웨어]
```
>Common Definition of OS
>> 컴퓨터에서 항상 돌아가는 프로그램(대게 `kernel`로 불린다.)

커널에서 시스템 프로그램과 애플리케이션 프로그램이 작동한다.

Modern Computer System - 신경망 컴푸터, 네트웍 컴퓨터, 양자 컴퓨터 등 `폰노이만 구조를 따르지 않는` 컴퓨터를 말한다.

Classical Computer System - CPU와 `bus`를 통해 연결된 여러 장치 관리자가 존재

`bootstrap program`이란? -> 전원을 킬때 가장 먼저 시작하는 프로그램 == `운영체제를 로딩`하는 역할

Interrupts란?

CPU에게 I/O 장비를 통한 입력 결과를 알려주는 작업.(CPU와 프로세스와 I/O Device가 통신하는 방법 중 하나.)

**하드웨어는 어느 때에도 interrupt를 수행할 수 있다**

폰노이만 구조 복습 : 
- FETCH, EXECUTE의 구조 (저장소에서 가져오고 필요한 명령어를 실행)
- 명령어를 저장하는 공간`instruction register`을 기억하자

## 메모리 계층 구조

(높을 수록 처리 속도가 빠르고 저장 용량이 낮다)
```
[register]
    ↕️
[cache]
    ↕️
[main memory]
    ↕️
[solid-state disk]
    ↕️
[hard disk]
    ↕️
[optical disk]
    ↕️
[magnetic tapes]
```
DMA (Direct Memory Access)
- ex) 유튜브 영상 시청에 CPU가 많이 관여하지 않는다.
- 네트워크와 화면 출력이 주가 된다.
- 그렇다면 `굳이 CPU를 거치지 않고` 네트워크와 화면 출력끼리 `직접 데이터를 교환해서 성능을 높히기`

## Computer System Component

컴퓨터를 구성하는 요소들 :
1. CPU - 명령어를 수행하는 H/W
2. Processor - CPU를 집적하는 물리 칩
3. Core - CPU의 연산 유닛
4. Multi Core - 동일한 CPU에 많은 계산 코어를 포함하는 것
    - Multi-core design : 프로세서 칩에 여러 코어가 장착되어 있다.
5. Multi Processor - 다수의 프로세서를 포함하는 것.
    - SMP(Symmetric MultiProcessing) :
        메모리에 연결된 CPU들이 **모두 register와 cache**를 가지고 있다.

## Multiprogramming

여러개의 프로그램을 동시에 실행시키기.

Multitasking(=Multiprocessing) : 
- 1개의 CPU로 여러 프로그램을 실행시키기.
- 여러개의 job을 빠르고 자주 `switch`하기 (=시분할)

```
⭐concurrency와 parallelism의 차이 이해할 것
```

멀티태스킹을 진행하기 위해서는 CPU scheduling을 진행해야 한다. + 이 행위의 효율성이 중요

## 운영체제의 두가지 모드
Operations의 두가지 방법(**user mode**, **kernel mode**)

잘못된 프로그램 작동을 방지(kernel mode가 아니면 직접 H/W를 제어 할 수 없다.)

## Virtualization

가상화 : 
멀티 프로세싱 (1개의 컴퓨터에서 여러개의 프로세스를 실행할 수 있다는 점을 알 고 있다.) 

➡️ 운영체제도 여러개를 돌릴 수 있지 않을까?

> H/W 하나에 여러개의 OS를 실행시키기(CPU 스케줄링 처럼 OS 스케줄링을 진행)

```
VM 구조
[프로세스들1] [프로세스들2] [프로세스들3] ...
    ↕️             ↕️           ↕️
[커널1]      [커널2]      [커널3]
 ↕️             ↕️           ↕️
[VM1]       [VM2]       [VM3]
 ↕️             ↕️           ↕️
[virtual machine manager]
 ↕️
[H/W]
```

1. 이제는 대부분 Mobile Computing을 한다(스마트폰)
2. Client-Server Computing을 한다.(web의 구조)
3. Peer-to-Peer Computing을 한다.(개인간의 통신)
    - Block Chain...
4. Cloud Computing. 서버를 직접 구성하지 않는다.
    - 자신의 하드웨어 자원은 네트워크의 UI에 불과함
    - 실제 네트워크 장비는 Cloud에 존재(**Edge Computing**)
    - "`Cloud` 처럼 수많은 장비들이 가려저 있다"의 의미
5. Real-Time Embedded System 직접 하드웨어를 관리하는 시스템(라즈베리 등등)

## OS에서 알아야 하는 핵심 주제⭐⭐⭐

이 아래의 것들은 완벽하게 설명할 줄 알아야 한다.
1. User Interface
2. Program Execution
3. I/O Operation
4. File-System manipulation
5. Communications
6. Error Detection
7. Resource Allocation
8. Logging
9. Protection and Security

## System Call

- 사용자가 OS에 명령을 내리는 방법
    -   CLI, GUI, Touch Screen

OS가 H/W에 명령을 내리는 방법은? 

-> `System Call`

OS API를 호출하기 == 시스템 콜
```c
#include <unistd.h>
ssize_t read (int fd, void *buf, size_t count)
```
```
ssize_t : return value
read : function name
(int fd, void *buf, size_t count) : parameters
```
```
[코드]
#include <stdio.h>
int main(){ printf("yo"); return 0;} 
                ↕️(user mode)
[stdio.h == Standard C Library]
    (kernel mode)↕️
        ⬇️(write)          ⬆️(read)
                [H/W]
```
중요한 시스템 콜 

```
1. fork, exit, wait
2. open, read, write, close
```





