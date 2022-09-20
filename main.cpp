#include <iostream>
#include<cstdlib> //rand 위한 c standard library
using namespace std;

/* 문제1  n != 1 * 2 * 3 * ..n을 구하는 프로그램 */
// 함수는 항상 Main 바깥쪽에


	//아이디어 : N_Total을 입력 -> for문으로 N_Total만큼 돌린다 -> 돌릴때마다 N에 +1한 값을 곱한다. 
	//오류 : N_Total이 For문 반복때마다 커져 무한루프됨. -> 파이썬에선 안보이던 현상 -> 변수를 따로 추가함
	//오류2 : 자료형 크기가 자동변환되지 않으므로, N = 11 이후에서 부호 바뀌면서 오류 -> 추후 자료형을 큰것으로 변경할 것
int N_Factorial()
{
	cout << "팩토리얼 N값을 입력하세요" << endl;

	int N_Input = 1; // 0을 곱하면 안되므로 
	cin >> N_Input;
	int N_Total = N_Input;
	for (int N = 1; N <= N_Input; N = N + 1)
	{
		N_Total = N_Total * N;
		cout << "N은 : ";
		cout << N << endl;
		cout << "N_Total은 : ";
		cout << N_Total << endl;
	}
	cout << "최종 숫자는 : ";
	cout << N_Total << endl;

	return N_Total;
}

/* n을 받아서 구구단 n단 출력 */
	// 아이디어 : N을 입력 -> 이중for문 i,j 돌림 
int Times_Table()
{
	cout << "단수를 입력하세요" << endl;

	int N = 1;
	cin >> N;
	for (int i = 1; i <= N; i = i + 1) // 단수
	{
		cout << i << "단" << endl;

		for (int j = 1; j <= 9; j = j + 1)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}
	return 0;
}

//// 중복 검사 
//int overlap_check(int Numbers[])
//{
//	for (int i = 0; i < 100; i++)
//	{
//		for (int j = i + 1; j < i; j++)
//		{
//			if (Numbers[i] == Numbers[j])
//			{
//				cout << "중복 발생" << endl;
//				cout << Numbers[i] << ", ";
//				cout << Numbers[j+1] << endl;
//
//				Numbers[i] = rand() % 100; // 난수 다시 생성
//			}
//		}
//	}
//	return 0;
//}

int Random_Number_Generate()
{
	/* 문제3 1 ~ 100까지 숫자를, 랜덤하면서 겹치지 않게 출력하셈 (rand, srand 이용) */
// rand : 난수표에서 뽑아옴. 0~32767. 항상 일정. srand : 현시간값 곱해서 난수표 변형시킴
// rand에 N%100 해주면, 항상 100까지 두자리 나옴. 
// 아이디어 : srand 사용 -> for 100번 돌림 -> 배열[1~100]조회, 중복x시 -> 배열 [100]에 입력

// srand 사용 예시 
	srand((unsigned int)time(NULL));  //rand값에 (int로_형변환된)time 넣어주기 
	for (int i = 0; i < 5; i++) {
		cout << rand() % 100 << endl;
	}

	// 문제풀이
	//int Numbers[100] = { 0, }; //0으로 초기화. 0일시 미입력된 자리
	//srand((unsigned int)time(NULL));

	////중복검사 안하고 기입하는 버전
	//srand((unsigned int)time(NULL));  //rand값에 (int로_형변환된)time 넣어주기 
	//for (int i = 0; i < 100; i++) 
	//{
	//	Numbers[i] = rand() % 100;
	//	cout << i + 1 << "번째는 : " << Numbers[i] << endl;
	//}

	//생성 -> 중복검사 간단 버전 // 중복되면 i--해서 다시 생성 // 파이썬에선 안될텐데
	int Numbers[100] = { 0, };

	srand((unsigned int)time(NULL)); //매번 실행시 시간 오래걸림
	cout << "중복검사 버전 " << endl;
	for (int i = 0; i < 100; i++) {
		Numbers[i] = (rand() % 100) + 1;	//i++ -> i보다 작은 배열과 비교 / 0부터 시작하므로 + 1
		for (int j = 0; j < i; j++) {
			if (Numbers[i] == Numbers[j]) i--;
			//cout << i + 1 << "번째는 : " << Numbers[i] << endl;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		cout << i + 1 << "번째는 : " << Numbers[i] << endl;

	}


	/* 난수 발생시마다 중복검사하는 버전. 복잡해서 폐기 */
	//for (int i = 1; i <= 100; i++) //배열 넣을땐 -1 해주자. i-1 = 배열번호, 
	//{
	//	// 아이디어_중복검사 : rand로 숫자 생성 -> 기입된 i-1까지(for), 기존 배열과 비교(if), 통과하면 기입(else) / 통과못하면 rand 다시돌림 
	//	
	//	int Number = rand() % 100;



	//	if (i >= 2) // i가 2이상일때부터, 중복 체크
	//	{
	//		for (int j = 2; j <= i; j++) {
	//			if (Numbers[j - 1] == Number)
	//			{
	//				cout << "중복 발생" << endl;
	//				// 다시 돌리기 

	//			}
	//			else
	//				Numbers[i - 1] = Number;
	//		}
	//	}

	//	
	//	
	//	cout << i << "번째 번호는 : " << Numbers[i - 1] << endl;

	//}

	return 0;
}

int Trump_Random4()
{
	// 문제 4
	//트럼프 카드 겹치지 않게 4장 뽑기
	// Heart A Spade 2 Diamond K Clover J
	// 아이디어 : 
		// 1. 변수 설정 :  H, C, S, D, 1 ~ 13, 10넘으면 J Q K로 변환, 1 A로 변환
		// 2. 배열에 하나씩 집어넣기 (113, 204 -> Heart King, Clover 4)
		// 3. 랜덤하게 뽑고, 중복 제외 알고리즘 쓰기  

	int H = 100;
	int C = 200;
	int S = 300;
	int D = 400;

	// 카드 갯수 4 x 13 = 52개 + 1 (조커)
	int Trumps[53] = { 0, };
	int Trump_p = 0;

	for (int i = 100; i < 401; i = i + 100)
	{
		for (int j = 1; j <= 13; j++)
		{
			Trumps[Trump_p] = i + j;
			Trump_p++;
		}
	}

	for (int i = 0; i < 53; i++)
	{
		cout << i << "번째 숫자는 : " << Trumps[i] << endl; // 0은 조커 
	}

	int Trumps_My[4] = { 0, };

	// 랜덤하게 뽑기 
	srand((unsigned int)time(NULL)); //매번 실행시 시간 오래걸림
	cout << "중복검사 버전 " << endl;
	for (int i = 0; i < 4; i++) {
		Trumps_My[i] = (rand() % 53) + 1;	//i++ -> i보다 작은 배열과 비교 
		for (int j = 0; j < i; j++) {
			if (Trumps_My[i] == Trumps_My[j]) i--;
			//cout << i + 1 << "번째는 : " << Numbers[i] << endl;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		cout << "몇번째 카드? : " << Trumps_My[i] << endl;
		cout << "무슨 카드? : " << Trumps[Trumps_My[i] - 1] << endl;
		//cout << "무슨 카드? : " << (Trumps[Trumps_My[i]] / 100) << endl;

		//아이디어
			//(Trumps[Trumps_My[i]] / 100) -> HCSD
			//(Trumps[Trumps_My[i]] % 100) -> if 1->a, if 11~13->J Q K


			// HCSD
		int Flag = (Trumps[Trumps_My[i] - 1] / 100);
		int Flag2 = (Trumps[Trumps_My[i] -1] % 100);
		if (Flag == 1)
		{
			cout << "H ";

		}
		else if (Flag == 2)
		{
			cout << "C ";
		}
		else if (Flag == 3)
		{
			cout << "S ";
		}
		else if (Flag == 4)
		{
			cout << "D ";
		}
		else
		{
			cout << "The ";

		}
		// 숫자
		if (Flag2 == 1)
		{
			cout << "A ";
		}
		else if (Flag2 == 11)
		{
			cout << "J ";
		}
		else if (Flag2 == 12)
		{
			cout << "Q ";
		}
		else if (Flag2 == 13)
		{
			cout << "K ";
		}
		else if (Flag2 == 0)
		{
			cout << "JOKER ";
		}
		else
		{
			cout << Flag2;
		}

		cout << endl;
	}


	//srand((unsigned int)time(NULL)); //매번 실행시 시간 오래걸림
	//cout << "중복검사 버전 " << endl;
	//for (int i = 0; i < 53; i++) {
	//	Numbers[i] = (rand() % 100) + 1;	//i++ -> i보다 작은 배열과 비교 
	//	for (int j = 0; j < i; j++) {
	//		if (Numbers[i] == Numbers[j]) i--;
	//		//cout << i + 1 << "번째는 : " << Numbers[i] << endl;
	//	}
	//}

	return 0;
}


int main()
{
	//문제 4
	Trump_Random4();

	//문제 1
	N_Factorial();

	//문제 2
	Times_Table();

	//문제 3
	Random_Number_Generate();



	return 0;
}