# 운영체제의 개념과 구조

프로세스 = 실행중인 프로그램

**복습**
컴퓨터의 구조

cpu <- Memory에서 명령어를 FETCH, 실행

일반적인 구조
```
CPU <-> Memory <-> Hard Disk
[실행]  [프로세스]    [ex) a.out]
```
메모리의 계층...
- Text section
    - 실행가능한 코드
- Data section
    - 전역 변수
- Heap section
    - 프로그램이 진행 중에 동적으로 할당된 메모리

```
MAX STACK
    .
    .
    .
    HEAP
    DATA
    TEXT(CODE)
0
```
C언어를 예시로 확인해보자
```c
#include<stdio.h>
#include<stdlib.h>

int x;
int y=15;
int main(int argc, char *argv[]){
    int *values;
    int i;
    values = (int *)malloc(sizeof(int)*5);
    for(int i=0;i<5;i++)
        values[i] = i;
    return 0;
}
```
```
argc, argv
stack : main, values
~
heap : malloc(5개)
uninitialized data
initialized data
text : for 문
```
> size 명령어로 a.out을 확인해보자
>> text data bss dec hex filename 이 나타난다.

프로세스의 상태
1. New : 프로세스가 생성
2. Running : 명령어가 실행
3. Waiting : 프로세스가 이벤트 발생 전까지 기다림
    - I/O 작업이 끝날 때 까지 기다리기 등등
4. Ready : 프로세스가 프로세서에 할당되기 기다림
5. Terminated : 프로세스가 종료됨

![img](./asset/lesson3/processConcept.png)



