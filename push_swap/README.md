## 📌 Push Swap
  
이 프로젝트은 주어진 스택에 대하여 제한된 명령어 집합을 가능한 한 적게 사용하여 정렬을 하는 것입니다.   
성공적으로 프로젝트를 끝내기 위해서는 다양한 유형의 알고리즘을 조작하고 최적화 된 데이터 정렬에 가장 적합한 솔루션을 선택해야 합니다.

### Instruction set

Code	| Instruction			| Action
--------|-----------------------|----------------------------------------------
`sa`	| swap a				| 스택 `a`의 가장 위에 있는 두 원소(혹은 첫 번쨰 원소와 두 번째 원소)의 위치를 서로 바꾼다.
`sb`	| swap b				| 스택 `b`의 가장 위에 있는 두 원소(혹은 첫 번쨰 원소와 두 번째 원소)의 위치를 서로 바꾼다.
`ss`	| swap a + swap b		| `sa`와 `sb`를 동시에 실행한다.
`pa`	| push a				| 스택 `b`에서 가장 위(탑)에 있는 원소를 가져와서, 스택 `a`의 맨 위(탑)에 넣는다. 스택 `b`가 비어 있으면 아무 것도 하지 않는다.
`pb`	| push b				| 스택 `a`에서 가장 위(탑)에 있는 원소를 가져와서, 스택 `b`의 맨 위(탑)에 넣는다. 스택 `a`가 비어있으면 아무 것도 하지 않는다.
`ra`	| rotate a				| shifts all elements of stack a from bottom to top
`rb`	| rotate b				| shifts all elements of stack b from bottom to top
`rr`	| rotate a + rotate b	| `ra`와 `rb`를 동시에 실행한다.
`rra`	| reverse rotate a		|  스택 `a`의 모든 원소들을 아래로 1 인덱스 만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
`rrb`	| reverse rotate b		| 스택 `b`의 모든 원소들을 아래로 1 인덱스 만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
`rrr`	| reverse rotate a + reverse rotate b	|  `rra`와 `rrb`를 동시에 실행한다.

### Compiling
Run `make`.

### Running
```
./push_swap 4 3 2 1
```
