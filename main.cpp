#include <iostream>
#include<cstdlib> //rand ���� c standard library
using namespace std;

/* ����1  n != 1 * 2 * 3 * ..n�� ���ϴ� ���α׷� */
// �Լ��� �׻� Main �ٱ��ʿ�


	//���̵�� : N_Total�� �Է� -> for������ N_Total��ŭ ������ -> ���������� N�� +1�� ���� ���Ѵ�. 
	//���� : N_Total�� For�� �ݺ������� Ŀ�� ���ѷ�����. -> ���̽㿡�� �Ⱥ��̴� ���� -> ������ ���� �߰���
	//����2 : �ڷ��� ũ�Ⱑ �ڵ���ȯ���� �����Ƿ�, N = 11 ���Ŀ��� ��ȣ �ٲ�鼭 ���� -> ���� �ڷ����� ū������ ������ ��
int N_Factorial()
{
	cout << "���丮�� N���� �Է��ϼ���" << endl;

	int N_Input = 1; // 0�� ���ϸ� �ȵǹǷ� 
	cin >> N_Input;
	int N_Total = N_Input;
	for (int N = 1; N <= N_Input; N = N + 1)
	{
		N_Total = N_Total * N;
		cout << "N�� : ";
		cout << N << endl;
		cout << "N_Total�� : ";
		cout << N_Total << endl;
	}
	cout << "���� ���ڴ� : ";
	cout << N_Total << endl;

	return N_Total;
}

/* n�� �޾Ƽ� ������ n�� ��� */
	// ���̵�� : N�� �Է� -> ����for�� i,j ���� 
int Times_Table()
{
	cout << "�ܼ��� �Է��ϼ���" << endl;

	int N = 1;
	cin >> N;
	for (int i = 1; i <= N; i = i + 1) // �ܼ�
	{
		cout << i << "��" << endl;

		for (int j = 1; j <= 9; j = j + 1)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}
	return 0;
}

//// �ߺ� �˻� 
//int overlap_check(int Numbers[])
//{
//	for (int i = 0; i < 100; i++)
//	{
//		for (int j = i + 1; j < i; j++)
//		{
//			if (Numbers[i] == Numbers[j])
//			{
//				cout << "�ߺ� �߻�" << endl;
//				cout << Numbers[i] << ", ";
//				cout << Numbers[j+1] << endl;
//
//				Numbers[i] = rand() % 100; // ���� �ٽ� ����
//			}
//		}
//	}
//	return 0;
//}

int Random_Number_Generate()
{
	/* ����3 1 ~ 100���� ���ڸ�, �����ϸ鼭 ��ġ�� �ʰ� ����ϼ� (rand, srand �̿�) */
// rand : ����ǥ���� �̾ƿ�. 0~32767. �׻� ����. srand : ���ð��� ���ؼ� ����ǥ ������Ŵ
// rand�� N%100 ���ָ�, �׻� 100���� ���ڸ� ����. 
// ���̵�� : srand ��� -> for 100�� ���� -> �迭[1~100]��ȸ, �ߺ�x�� -> �迭 [100]�� �Է�

// srand ��� ���� 
	srand((unsigned int)time(NULL));  //rand���� (int��_����ȯ��)time �־��ֱ� 
	for (int i = 0; i < 5; i++) {
		cout << rand() % 100 << endl;
	}

	// ����Ǯ��
	//int Numbers[100] = { 0, }; //0���� �ʱ�ȭ. 0�Ͻ� ���Էµ� �ڸ�
	//srand((unsigned int)time(NULL));

	////�ߺ��˻� ���ϰ� �����ϴ� ����
	//srand((unsigned int)time(NULL));  //rand���� (int��_����ȯ��)time �־��ֱ� 
	//for (int i = 0; i < 100; i++) 
	//{
	//	Numbers[i] = rand() % 100;
	//	cout << i + 1 << "��°�� : " << Numbers[i] << endl;
	//}

	//���� -> �ߺ��˻� ���� ���� // �ߺ��Ǹ� i--�ؼ� �ٽ� ���� // ���̽㿡�� �ȵ��ٵ�
	int Numbers[100] = { 0, };

	srand((unsigned int)time(NULL)); //�Ź� ����� �ð� �����ɸ�
	cout << "�ߺ��˻� ���� " << endl;
	for (int i = 0; i < 100; i++) {
		Numbers[i] = (rand() % 100) + 1;	//i++ -> i���� ���� �迭�� �� / 0���� �����ϹǷ� + 1
		for (int j = 0; j < i; j++) {
			if (Numbers[i] == Numbers[j]) i--;
			//cout << i + 1 << "��°�� : " << Numbers[i] << endl;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		cout << i + 1 << "��°�� : " << Numbers[i] << endl;

	}


	/* ���� �߻��ø��� �ߺ��˻��ϴ� ����. �����ؼ� ��� */
	//for (int i = 1; i <= 100; i++) //�迭 ������ -1 ������. i-1 = �迭��ȣ, 
	//{
	//	// ���̵��_�ߺ��˻� : rand�� ���� ���� -> ���Ե� i-1����(for), ���� �迭�� ��(if), ����ϸ� ����(else) / ������ϸ� rand �ٽõ��� 
	//	
	//	int Number = rand() % 100;



	//	if (i >= 2) // i�� 2�̻��϶�����, �ߺ� üũ
	//	{
	//		for (int j = 2; j <= i; j++) {
	//			if (Numbers[j - 1] == Number)
	//			{
	//				cout << "�ߺ� �߻�" << endl;
	//				// �ٽ� ������ 

	//			}
	//			else
	//				Numbers[i - 1] = Number;
	//		}
	//	}

	//	
	//	
	//	cout << i << "��° ��ȣ�� : " << Numbers[i - 1] << endl;

	//}

	return 0;
}

int Trump_Random4()
{
	// ���� 4
	//Ʈ���� ī�� ��ġ�� �ʰ� 4�� �̱�
	// Heart A Spade 2 Diamond K Clover J
	// ���̵�� : 
		// 1. ���� ���� :  H, C, S, D, 1 ~ 13, 10������ J Q K�� ��ȯ, 1 A�� ��ȯ
		// 2. �迭�� �ϳ��� ����ֱ� (113, 204 -> Heart King, Clover 4)
		// 3. �����ϰ� �̰�, �ߺ� ���� �˰��� ����  

	int H = 100;
	int C = 200;
	int S = 300;
	int D = 400;

	// ī�� ���� 4 x 13 = 52�� + 1 (��Ŀ)
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
		cout << i << "��° ���ڴ� : " << Trumps[i] << endl; // 0�� ��Ŀ 
	}

	int Trumps_My[4] = { 0, };

	// �����ϰ� �̱� 
	srand((unsigned int)time(NULL)); //�Ź� ����� �ð� �����ɸ�
	cout << "�ߺ��˻� ���� " << endl;
	for (int i = 0; i < 4; i++) {
		Trumps_My[i] = (rand() % 53) + 1;	//i++ -> i���� ���� �迭�� �� 
		for (int j = 0; j < i; j++) {
			if (Trumps_My[i] == Trumps_My[j]) i--;
			//cout << i + 1 << "��°�� : " << Numbers[i] << endl;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		cout << "���° ī��? : " << Trumps_My[i] << endl;
		cout << "���� ī��? : " << Trumps[Trumps_My[i] - 1] << endl;
		//cout << "���� ī��? : " << (Trumps[Trumps_My[i]] / 100) << endl;

		//���̵��
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
		// ����
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


	//srand((unsigned int)time(NULL)); //�Ź� ����� �ð� �����ɸ�
	//cout << "�ߺ��˻� ���� " << endl;
	//for (int i = 0; i < 53; i++) {
	//	Numbers[i] = (rand() % 100) + 1;	//i++ -> i���� ���� �迭�� �� 
	//	for (int j = 0; j < i; j++) {
	//		if (Numbers[i] == Numbers[j]) i--;
	//		//cout << i + 1 << "��°�� : " << Numbers[i] << endl;
	//	}
	//}

	return 0;
}


int main()
{
	//���� 4
	Trump_Random4();

	//���� 1
	N_Factorial();

	//���� 2
	Times_Table();

	//���� 3
	Random_Number_Generate();



	return 0;
}