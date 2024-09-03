## System(S/W) Life Cycle

- 요구사항(Requirements) 분석 단계
    - 문제와 결과 정보를 규정
- 분석(Analysis) 단계
    - 상향식 설계
        - 초기부터 세부 구현을 함
        - 결과 프로그램 = 세부 기능들의 조합
        - 단점 : 주어진 문제의 고유 특성, 프로젝트에 대한 기본 계획이 없는 설계가 될 위험이 있음
    - 하향식 설계
        - 최종 결과 프로그램을 설계 후 우리가 다룰 수 있을 정도의 세그먼트로 분할함
        - 단점 : 도미노 효과 발생 가능
- 설계(Design) 단계
    - 데이터 적인 관점에서 : 추상적 데이터 타입
    - 연산의 관점에서 : 알고리즘의 명세와 설계 기법을 고려
    - 추상 데이터 타입과 알고리즘은 프로그래밍 언어와 별개이기 때문에 구체적인 구현은 미루어둔다.
- 정제와 코딩(Refinement and Coding)
    - 구현(Implementation) 단계라고도 한다.
    - 데이터의 구현 방법을 선택하고
    - 데이터에 대한 연산들의 구현 알고리즘을 선택한다.
    - 이는 시스템의 성능을 좌우할 수 있다.
- 검증(Verification) 단계
    - 정확성 증명(Correctness Proof)
        - 수학적 기법을 사용할 수 있으나 시간이 많이 소요되어 경우에 따라 불가능
        - 수학적으로 정확성이 증명된 알고리즘 사용
    - 검사(Testing)
        - 테스트 데이터와 실행 가능한 코드를 요함
        - 훌륭한 테스트 데이터는 실행 코드의 모든 부분을 검사할 수 있어야 함
        - 프로그램의 실행 시간 역시 중요함
    - 오류 제거(Error Removal)
        - 문서화가 되어있지 않으며 설명이 들어있지 않은 코드에서 오류를 제거하는 것은 프로그래머의 악몽과 같다.
        - 좋은 프로그램은 설명이 잘 기술되어 있고 매개변수를 통해 독립적인 단위로 구성되어 : 문서화, 모듈화가 잘 되어있는 프로그램이다.

## 포인터, 동적 메모리 할당

[CH. 11 포인터](https://www.notion.so/CH-11-9bf9445c63164c7ba14a107211ed434e?pvs=21)

[CH. 25 메모리 관리와 동적 할당](https://www.notion.so/CH-25-cbb0cc9efab2430197c24a948ef5b539?pvs=21)

`malloc()`은 프로그램의 여러 곳에서 호출 되기 때문에 `malloc()`을 호출하고, `malloc()`이 정상적으로 작동했는지(`NULL`을 반환하지는 않았는지)를 확인하기 위해 매크로를 정의하는 것이 편할 때가 있다.

```c
#define MALLOC(p, s) \
	if(!( (p) = malloc(s) ) ) { \
		fprintf(stderr, "Insufficient Memory");\ // 표준 에러 장치에 문자열 출력
		exit(EXIT_FAILURE); // 프로그램 종료를 뜻함
	}
```

+) 유용한 MACRO 함수들

```c
#define SWAP(x, y, t) ((t) = (x)) ((x) = (y)) ((y) = (t))
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1) 
// x > y 1, x == y 0, x < y -1 return
```

## 알고리즘 명세

알고리즘이란 어떤 일을 수행하기 위한 유한 개의 명령어들의 나열이다. 모든 알고리즘은 다음의 조건을 만족한다 : 

- 입력(Input) : 0 혹은 그 이상의 입력 존재
- 출력(Output) : 적어도 하나 이상의 결과물 출력
- 명확성(Definiteness) : 명령어들의 의미는 명확해야 하며, 애매모호해서는 안된다.
- 유한성(Finiteness) : 유한 개의 명령어들을 수행한 후 종료해야 한다.
- 실행가능성(Effectiveness) : 모든 명령어들은 실행 가능해야 한다.

알고리즘은 의사코드, 흐름도 등으로 표현한다. 이는 자연어와 프로그래밍 언어를 혼용하여 알고리즘을 짜고 구현은 가장 마지막에 한다.

## 알고리즘의 예 1 : 선택 정렬, 이진 탐색

## 선택 정렬

n ≥ 1 개의 서로 다른 정수를 정렬하는 프로그램을 작성한다고 하자. 간단한 방법은 

**“정렬되지 않은 정수들 중에서 가장 작은 값을 찾아서 정렬된 리스트 다음에 놓는다.”**

이다. 정수들이 크기가 `n`인 배열 `list` 에 저장된다고 가정하면, 

```c
for(i = 0; i < n; i++) {
	//list[i]에서 list[n-1]까지의 정수 값을 검사한 결과
	//list[min]이 가장 작은 정수 값이라 하자;

	//list[i]와 list[min]을 서로 교환;
}
```

- 0부터 끝까지 탐색 후 최솟값을 0번 인덱스에 교환 → 1부터 끝까지 탐색 후 최솟값을 1번 인덱스와 교환을 배열의 끝까지 반복함.

## 이진 탐색

- 이진탐색이란 “정렬되어있는 배열”에서 하한, 상한, 중간값을 기준으로 찾으려는 값을 중간값과 비교하여 탐색의 범위를 반씩 줄여가는 탐색이다.
- `n ≥ 1`개의 서로 다른 정수가 이미 정렬되어 배열 `list` 에 저장되어 있다고 가정하자. 정수 `searchnum` 이 배열 `list`에 있는지를 검사하려고 한다.
- 만약 존재한다면 `list[i] = searchnum` 인 인덱스 `i`를 반환하고, 그렇지 않다면 `-1`을 반환한다.
- `left`, `right`는 탐색하고자 하는 배열의 왼쪽, 오른쪽 끝 지점을 가리킨다.
- 초기값은 `left = 0, right = n-1`로 주고, `list`의 중간 지점 `middle = (right+left)/2` 로 설정하여 `list[middle]` 과 `searchnum` 을 비교한다.
- 찾으려는 값`searchnum` 이 배열의 중간값`list[middle]` 보다 큰 경우 우리는 배열의 중간값에서`left = middle + 1` 부터 가장 오른쪽까지를 새로운 범위로 잡아 같은 작업을 반복한다. `middle = (right+left)/2`
- 찾으려는 값`searchnum`이 배열의 중간값`list[middle]`보다 작은 경우 왼쪽 끝`left`부터 배열의 중간값`list[middle]` 까지를 새로운 범위로 잡아 같은 작업을 반복한다.
- 이러한 과정을 반복하여서 `list[middle] = searchnum`이 되는 순간 `middle` 을 반환하는 함수를 작성하자.

구현)

- `left` 초기값  = `0`
- `right` 초기값 = `n-1`
- `middle` 초기값 = `( right + left ) / 2`
- `searchnum`이 `middle` 과 다르다면 다시 반복
    - 반복의 종료 조건 : `searchnum`과 같은 값을 찾았거나 모든 범위를 검사했을 때(찾지 못한다는 것을 깨달았을 때)
    - 모든 범위를 검사했다는 것을 어떻게 찾아낼 것인가?
    - 한 번 반복이 진행될 때마다 `left` `right` 값이 shifting 되는데 이 때 점점 범위가 줄다가 `left == right`가 되는 순간에는 `middle == left == right` 가 되어 값을 찾아야 함 근데 이때도 값을 못찾는다면 `middle` 값과 `searchnum` 값에 따라 `left` 가 오른쪽으로 가거나, `right`가 왼쪽으로 가게 된다.
    - 이 때가 바로 이제 `searchNum`이 배열에 존재하지 않는 경우임. 따라서 반복의 종료 조건 즉, `while`문의 조건식은 `left ≤ right` 여야 함
- `middle` 값은 매 반복마다 `left` `right` 값이 바뀜에 따라 바뀌게됨

[LAB. 1 선택 정렬과 이진 탐색](https://www.notion.so/LAB-1-250024cfc384400897787557ca2cfdf1?pvs=21)

## 알고리즘의 예 2 : 순환(Recursion) 알고리즘

재귀(순환) 알고리즘은 어떤 함수에서, 함수가 종료되기 전에 함수 자기 자신을 다시 호출하여 반복 작업이 필요한 문제를 해결할 때에 사용한다. 또한, 함수 자기 자신만을 다시 호출하는 방법 외에도 다른 호출 함수를 다시 호출하게 되어있는 다른함수를 호출(간접 순환)하여 알고리즘을 짤 수도 있다. 

재귀 알고리즘은 factorial, fibonacci 등 자체적으로 재귀적인 알고리즘에 매우 적합하지만, 우리가 `if-else`, `while` 으로 작성하는 어떤 프로그램이라도 순환으로 작성할 수 있다.

재귀 알고리즘의 핵심은 순환의 종료 조건이다. `while`, `for` 등의 반복문과 유사하게 생각할 수 있는데, 호출을 종료하는 경계 조건을 설정해놓고 각 단계마다 경계 조건에 접근하여 호출이 반드시 종료될 수 있도록 해야한다. 

### 1. 이진 탐색의 순환 알고리즘

이진 탐색에서의 반복의 종료조건은 찾고자하는 숫자를 배열에서 찾았을 때`list[middle] == searchnum` 와 탐색에 실패하여서 `left`와 `right` 인덱스 값이 엇갈렸을 때`while(left<=right)` 이다. 탐색이 종료되는 순간이 아니라면 새롭게 바뀐 범위에서 다시 탐색을 하도록 범위를 조정하여 함수를 다시 호출하도록 한다.

```c
int binsearch(int list[], int searchnum, int left, int right){
	int middle;
	if(left <= right) {
		middle = (left + right) / 2;
		switch(COMPARE(list[middle], searchnum){
			case -1: return binsearch(list, searchnum, middle+1, right);
			case 0 : return middle;
			case 1 : return binsearch(list, searchnum, left, middle-1);
		}
	}
	return -1;
}
```

### 2. 순열의 순환 알고리즘

n≥1 개의 원소를 갖는 집합에 대해 집합의 모든 원소들에 대한 순열을 출력하라 : 총 순열의 개수는 n!

```c
void perm(char* list, int i, int n){
	// list[i] ~ list[n] 까지의 원소로 구성된 순열 출력
	int j, temp;
	if(i == n){ // 표현할 수 있는 순열의 개수가 하나
		// 더 이상 이어지는 재귀 호출 없음.
		// 현재 배열의 상태 그대로 출력.
		for(j = 0; j<= n; j++)
			printf("%c", list[j]);
		printf("  ");
	} else {
		for(j = i; j <= n; j++){
			SWAP(list[i], list[j], temp); // 위치 변경
			perm(list, i + 1, n);
			SWAP(list[i], list[j], temp); // 제자리로
		}
	}
}
```

## 데이터 추상화

**데이터 타입이란 무엇인가?**

C언어에서의 데이터 타입에는 `char, int, float, double` 등이 있다. 이러한 데이터 타입은 `short, long, unsigned` 의 키워드로 확장될 수 있고, `array, struct, union`을 통해 그룹화 할 수 있다. 

모든 프로그래밍 언어는 최소한의 사전 정의 **데이터 타입**들과 새로운 **데이터 타입**을 만들 수 있도록 사용자 정의 **데이터 타입**을 제공한다. 

**데이터 타입**은 객체와 그 객체위에 작동하는 연산의 집합이다. 

데이터 타입에 대한 객체 표현을 이해하는 것은 유용하면서도 위험하다. 연산에 대한 새로운 구현을 하게 된다면 그에 따른 모든 흐름을 새로 짜야하기 때문이다.

**명세**란 프로그램의 기능과 구조를 최대한 상세하게 기술한 문서이다. 

**추상 데이터 타입`Abstract Data Type, ADT`**은 객체의 명세와 그 연산의 명세가 객체의 표현과 연산의 구현으로부터 분리된 데이터 타입이다. 멤버함수의 선언부와 구현부를 분리하여 작성하는 C++의 클래스가 대표적인 예이다. 

ADT 연산에서 명세는 함수의 이름, 매개변수 타입, 리턴 타입으로 구성된다. 또한 함수가 어떠한 기능을 하는지에 대한 설명을 포함해야 한다. 그러나 함수 내부의 구체적인 구현에 대한 자세한 설명은 필요없다. 

데이터 타입 명세에서 함수들의 종류는 다음과 같다.

1. 생성자/구성자 : 데이터 타입에 맞는 새로운 인스턴스를 생성한다
2. 변환자 : 기존 인스턴스를 이용하여 새로운 인스턴스 생성
3. 관찰자 : 인스턴스에 대한 정보 출력, 인스턴스 변경 않음
- ADT의 예 : Natural Number
    
    자연수의 기본적인 덧셈/뺄셈, 비교연산을 포함하는 ADT를 작성해보자.
    
    기본적으로 ADT의 정의는 크게 세 가지를 포함한다 : 이름, 객체, 함수
    
    자연수를 다룰 것이므로 ADT의 이름을 `NaturalNumber` 로 작성해준다.
    
    객체는 0부터 시작하여 컴퓨터 내에서의 최대 정수값까지의 정수의 부분 범위이다.
    
    ```c
    ADT NaturalNumber
    	objects : 정수
    	funcs : 
    		NaturalNumber의 원소 x, y
    		Boolean의 원소 TRUE, FALSE에 대하여
    		+,-,<,==는 일반적인 정수 연산자이다.
    		NaturalNumber Zero() { return 0 } // 생성자
    		Boolean IsZero(x) { if(x) return FALSE
    												else return TRUE } // 관찰자
    		Boolean Equal(x, y) { if(x == y) return TRUE
    													else return FALSE } // 관찰자
    		NaturalNumber Successor(x) { if(x == INT_MAX) return x
    																 else return x+1 }
    		NaturalNumber Add(x, y) { if((x+y) <= INT_MAX) return x+y
    															else return INT_MAX }
    		NaturalNumber Substract(x, y) { if(x<y) return 0
    																		else return x-y }
    end NaturalNumber
    			
    ```
    
- 연습문제1
    
    Natural Number ADT에 Predecessor, IsGreater, Multiply, Divide 연산자를 추가하라
    
    ```c
    ADT NaturalNumber
    	objects : 정수
    	funcs : 
    		NaturalNumber의 원소 x, y
    		Boolean의 원소 TRUE, FALSE에 대하여
    		+,-,<,==는 일반적인 정수 연산자이다.
    		NaturalNumber Zero() { return 0 } // 생성자
    		Boolean IsZero(x) { if(x) return FALSE
    												else return TRUE } // 관찰자
    		Boolean Equal(x, y) { if(x == y) return TRUE
    													else return FALSE // 관찰자
    		NaturalNumber Successor(x)   if(x == INT_MAX) return x
    																 else return x+1 // 변환자
    		// 리턴타입이 NatNum인 것부터 새로운 인스턴스를 만든다고 볼 수 있음
    		NaturalNumber Add(x, y)   if((x+y) <= INT_MAX) return x+y
    															else return INT_MAX // 변환자
    		NaturalNumber Substract(x, y)   if(x<y) return 0
    																		else return x-y 
    		//
    		NaturalNumber Predecessor(x) if x==0 return 0
    																 else return x-1
    		Boolean IsGreater(x,y)   if(x>y) return TRUE
    														 else return FALSE
    		NaturalNumber Multiply(x,y) if((x*y) >= INT_MAX) return INT_MAX
    																else return x*y
    		NaturalNumber Divide(x,y) if(y) return x/y
    															else return 0 // 예외													 
    
    end NaturalNumber
    			
    ```
    

## 성능 분석

프로그램을 평가하는 데에 어떠한 기준을 세울 것인가?

1. 주어진 문제를 해결하였는가?
2. 정확하게 작동하는가?
3. 문서화
4. 모듈화
5. 가독성
6. 프로그램이 메인 메모리와 보조기억장치를 효율적으로 사용하는가? // 공간 효율성
7. 프로그램의 실행 시간은 허용할 만한가? // 시간 효율성

1,2는 프로그램을 작성하는 데에 있어 필수적인 요소이고, 3~5는 개발자 개인의 프로그래밍 스타일과 밀접한 연관이 있으며 경험과 훈련이 필요하다. 6~7이 프로그램의 성능 평가에 있어 직접적인 연관을 가진다. 

6~7의 성능 평가는 크게 두 가지 분야로 나눌 수 있다 : **성능 분석** vs **성능 측정**

1. 성능 분석 : 컴퓨터와 상관없이 시공간의 추산에 초점을 둔다. 이는 컴퓨터 공학의 주요 분야인 **복잡도 이론**의 핵심이다.
2. 성능 측정 : 컴퓨터에 의존적인 실행 시간을 얻어내는 것으로, 비효율적인 코드 세그먼트(가장 작은 코드의 구성 단위)를 분별하는데 활용된다.

<aside>
💡 프로그램의 **공간 복잡도**는 프로그램을 실행시켜 완료하는 데 필요로 하는 공간의 양이다. **시간 복잡도**는 프로그램을 실행시켜 완료하는 데 필요한 컴퓨터 시간의 양을 의미한다.

</aside>

### **시간 복잡도**

프로그램P에 의해 소요되는 시간 $T(P)$는 컴파일 시간과 실행 시간을 합한 것이다.

컴파일 시간은 인스턴스 특성에 의존적이지 않으며, 한 번 컴파일 하면 여러 번 실행할 수 있기에 실행시간 $T_P$만 염두에 두면 된다.

$T_P$는 컴파일러와 하드웨어 사양에 따라 변하기 때문에, **Program Step**이라는 단위로 나누어 계산한다. 

**프로그램 단계(Program Step)**이란 실행 시간이 프로그램의 특성과는 무관한 프로그램의 문법적인 혹은 논리적인 단위이다.

즉, 프로그램의 명령문을 일정한 세그먼트로 나누어 그 세그먼트가 몇 번 실행되는지를 검사한다.

이 때 명령문은 프로그램 특성(컴파일러, 하드웨어 특성 등)과 무관해야 하며 초기 값이 0인 전역변수 count를 정의하여 매 실행 명령문마다 count를 증가시키는 명령문을 삽입한다. **실행문은 기본연산, 함수 호출 반환 등이 될 것이다.**

count++ 식의 위치는 프로그램의 실행 흐름과 연관이 있다. count++는 코드의 특정 부분이 실행되었음을 추적하거나 확인하고자 할 때 사용된다.

```c
/* 예제 1.9 리스트에 있는 수의 반복적 합산 */
int count = 0; // step 계산을 위한 전역변수 count 선언
float sum(float list[], int n){
	float tempsum = 0; count++; // tempsum 지정문을 위한
	int i;
	for(int i = 0; i < n; i++){
		count++; // for 루프를 위한 연산, n회 반복
		tempsum += list[i]; count++; // tempsum 지정문을 위한 연산, n회 반복
	}
	count++; // for 루프 마지막 실행, i = n 일 때가 반복의 종료이므로
	count++; return tempsum; // 반환을 위한
}
```

```c
/* 예제 1.10 리스트에 있는 수의 순환적 합산 */
int count = 0;
float rsum(float list[], int n){
	count++; // if문 을 위한
	if (n) {
		count++; // return 문과 함수 호출을 위한
		return rsum(list, n-1) + list[n-1];
	}
	count++; // return을 위한
	return list[0];
}
```

위 `rsum`함수의 단계는 매개변수 `n`에 따라 달라진다. `n`이 커질수록 재귀호출은 깊어지며, 이에 따른 실행 시간은 커질 것이다. 이를 계산하기 위해 우리는 `count`변수를 함수 호출시와 조건문 검사시에 증가시킨다. 전체 함수 호출 횟수와 조건문 검사 횟수를 프로그램의 세그먼트로 정한 것이다. `if(n)`이 입력 크기에 직접적으로 의존하며, 재귀 호출의 종료조건을 다루는 기본 연산(조건 연산)이므로 이를 count했고, return과 동시에 함수가 호출되는 문장 역시 함수 프로그램에서 중요한 부분이므로 이를 count 했다.

```c
/* 예제 1.11 행렬의 덧셈 */
int count = 0;
void add(int a[][MAX_SIZE], int b[][MAX_SIZE], 
	int c[][MAX_SIZE], int rows, int cols)
{
	int i, j;
	for(i = 0; i < rows; i++){
		count++; // i 반복을 위한
		for(j = 0; j < cols; j++){
			count++; // j 반복을 위한
			c[i][j] = a[i][j] + b[i][j];
			count++; // 지정문을 위한
		}
		count++; // for 루프의 마지막 j
	}
	count++; // for 루프의 마지막 i
}
```

위 함수에서 프로그램 종료 시에 `count`는 `2rows*cols+2rows+1`이 됨을 알 수 있다. 이는 행의 수가 열의 수보다 현저히 크다면 행렬을 교환해야 함을 암시한다.

**Step/Execution Count Table**

함수 내에 count문을 물리적으로 위치시켜 함수를 실행한 후 단계 수를 구하였다. 단계 수를 구하는 또 다른 방법은 Step/Execution Count Table이다. 먼저 명령문에 대한 단계수를 구해야 한다. 이를 s/e 라고 하며, 이에 따른 빈도수를 곱하면 각 명령문에 대한 총 빈도수를 구할 수 있다.

- 리스트에 있는 수의 반복적 합산

| 문장 | s/e | 빈도수 | 총 단계 수 |
| --- | --- | --- | --- |
| `float sum(float list[], int n)` | 0 | 0 | 0 |
| `{` | 0 | 0 | 0 |
|   `float tempsum = 0;` | 1 | 1 | 1 |
|   `int i;` | 0 | 0 | 0 |
|   `for(i = 0; i < n; i++)` | 1 | n+1 | n+1 |
|     `tempsum += list[i];` | 1 | n | n |
|   `return tempsum;` | 1 | 1 | 1 |
| `}` | 0 | 0 | 0 |
| 합계 |  |  | 2n+3 |
- 리스트에 있는 수의 순환적 합산

| 문장 | s/e | 빈도수 | 총 단계 수 |
| --- | --- | --- | --- |
| `float rsum(float list[], int n)` | 0 | 0 | 0 |
| `{` | 0 | 0 | 0 |
|   `if(n)` | 1 | n+1 | 1 |
|     `return rsum(list,n-1)+list[n-1]` | 1 | n | 1 |
|   `return list[0];` | 1 | 1 | 1 |
| `}` | 0 | 0 | 0 |
| 합계 |  |  | 2n+2 |
- 행렬의 합산

| 문장 | s/e | 빈도 수 | 총 단계 수 |
| --- | --- | --- | --- |
| `void add(int a[][MAX_SIZE], … )` | 0 | 0 | 0 |
| `{` | 0 | 0 | 0 |
|   `int i, j;` | 0 | 0 | 0 |
|   `for(i = 0; i < rows; i++)` | 1 | rows+1 | rows+1 |
|     `for(j = 0; j < cols; j++)` | 1 | (cols+1)*rows | rows*cols+rows |
|       `c[i][j]=a[i][j]+b[i][j];` | 1 | cols*rows | rows*cols |
| `}` | 0 | 0 | 0 |
| 합계 |  |  | 2rows*cols+2rows+1 |

### **공간 복잡도**

프로그램이 요구하는 공간은 다음과 같은 요소의 합이 된다.

- 고정 공간 요구 $c$
    - 프로그램의 입출력 횟수나 크기에 무관한 공간 요구
    - ex. 명령어 공간(코드의 저장을 위한 공간), 단순 변수, 고정 크기의 구조화 변수, 상수 …
- 가변 공간 요구 $S_p(I)$
    - 함수가 순환호출을 할 경우 요구되는 추가 공간을 포함한 프로그램의 작업 인스턴스 I에 의존하는 크기
    - 동적으로 필요한 공간

```c
/* 예제 1.6 단순 산술 함수 */
float abc(float a, float b, float c){
	return a+b+b*c+(a+b-c)/(a+b)+4.00;
}
```

이 함수는 오직 고정공간 요구만을 가지고 있다. 따라서 $S_{abc}(I) = 0$ 이다.

```c
/* 예제 1.7 리스트에 있는 수 합산 */
float sum(float list[], int n){
	float tempsum = 0;
	for(int i = 0; i < n; i++)
		tempsum += list[i];
	return tempsum;
}
```

배열을 포함하는 입력이다. 만약 배열의 값 전체를 함수의 인자로 전달한다면 배열 전체를 임시 저장소에 복사해두어야 한다. 이에 따른 가변 공간 요구는 배열의 크기 n이다. 다만 C 언어는 배열을 호출할 때에 배열의 시작 주소값을 인자로 전달하고 배열을 복사하지 않으므로 $S_{sum}(n) = 0$이다.

```c
/* 예제 1.8 리스트에 있는 수 순환 합산 */
float rsum(float list[], int n){
	if(n) return list[n-1]+rsum(n-1);
	return list[0];
}
```

순환함수는 컴파일러가 매개변수, 지역변수, 복귀 주소를 순환 호출을 할 때마다 저장해야 한다. 이 예제에서 하나의 순환호출을 위해 요구되는 공간은 2개의 매개변수`float*,int`와 복귀 주소이다.

이 함수는 n번 재귀호출 되므로 $S_{rsum}(I) = (n+1)(float+int)$ 이다.

### 점근 표기법

프로그램의 정확한 단계수를 계산하는 것은 매우 어려우며, Program Step의 정의 자체가 정확하지 않다. 

시간 복잡도는 입력 n에 따라 달라지는 함수로 표현할 수 있다. 예를 들어, 시간 복잡도가 $c_1n^2+c_2n$, $c_3n$인 두 프로그램에 대하여 c1, c2, c3의 값에 따라 시간 복잡도가 결정되겠지만, n이 값이 충분히 큰 값이라면 전자의 시간 복잡도가 훨씬 크다는 것을 알 수 있다. c1,c2,c3의 값에 상관 없이 복잡도가 $c_3n$인 프로그램이 $c_1n^2+c_2n$인 프로그램보다 빠른 n이 반드시 존재할 것이다. 이 n을 균형 분기점이라 한다.

정확한 균형 분기점을 결정하는 것은 매우 어렵다. 따라서 우리는 시간과 공간 복잡도에 대한 의미있는 대략적인 값을 알 수 있는 방법에 대해 알아볼 것이다.

**빅오 : 모든 $n$, $n≥n_0$ 에 대해 $f(n)≤cg(n)$인 조건을 만족하는 두 양의 정수 $c$와 $n_0$가 존재하기만 하면 $f(n) = O(g(n))$이다. (O는 빅-오 라읽음)**

임의의 양의 상수 $c$를 곱한 $cg(n)$에 대해 $n$의 값을 충분히 증가시켰을 때 항상 $f(n) ≤ cg(n)$인 구간이 나온다면 $f(n) = O(g(n))$이다. 

$g(n)$은 $f(n)$의 상계이며, $f(n)$이 $g(n)$에 비례하거나 그보다 작음을 의미한다.

$3n+2≠O(1)$ 이며 $10n^2+4n ≠ O(n)$이다.

$n≥4$일 때 $6*2^n+n^2$ ≤ $7*2^n$ 이므로 $6*2^n+n^2$ $= O(2^n)$ 이며 

$n≥2$일 때 $10n^2+4n ≤ 10n^4$ 이므로 $10n^2+4n = O(n^4)$ 이다.

$O(1)$을 상수 시간 복잡도라 하며, $O(n)$을 선형, $O(n^2)$를 평방형, $O(n^3)$을 입방형, $O(2^n)$을 지수형, $O(log n)$을 로그형이라 한다.

식 $f(n) = O(g(n))$은 $n ≥ n_0$인 모든 $n$에 대하여 $g(n)$ 값이 $f(n)$의 **상한**임을 의미하다. 따라서 $f(n) = O(g(n))$이 의미상으로 유익하기 위해서는 $g(n)$은 가능한 한 작아야 한다. 예를 들어, $O(n)$은 입력 크기 $n$에 선형적으로 비례하는 최대 연산 수를 가짐을 의미한다.

정리) 만약 $f(n) = a_mn^m + … + a_1n+a_0$ 이면 $f(n) = O(n^m)$ 이다.

증명) $f(n) ≤ \sum_{i=0}^m\left\vert a_i \right\vert n^i$

   $≤ n^m \sum_0^m\left\vert a_i \right\vert n^{i-m}$

   $≤ n^m \sum_0^m\left\vert a_i \right\vert$

따라서 $f(n) = O(n^m)$ 이다.

**오메가 : 모든 $n$, $n≥n_0$에 대해 $f(n)≥cg(n)$인 조건을 만족하는 두 양의 상수 $c$와 $n_0$이 존재하기만 하면 $f(n) = \Omega(g(n))$ 이다.**

임의의 양의 상수 $c$를 곱한 $cg(n)$에 대해 $n$의 값을 충분히 증가시켰을 때 항상 $f(n) ≥ cg(n)$인 구간이 나온다면 $f(n) = \Omega(g(n))$이다.

g(n)은 f(n)의 하계이며, f(n)이 g(n)에 비례하거나 그보다 큼을 의미한다.

**세타 : 모든 $n$, $n≥n_0$에 대해 $c_1g(n)≤f(n)≤c_2g(n)$을 만족하는 세 양의 상수 c1, c2, $n_0$이 존재하기만 하면 $f(n) = \Theta(g(n))$이다.**

$g(n)$이 $f(n)$에 대해 상한 값과 하한 값을 가지기만 하면 $f(n) = \Theta(g(n))$이다.
