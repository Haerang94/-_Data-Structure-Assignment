
/*
�а�: ��ǻ���������к�
�й�:201521514
�̸�:���ض�
����: visual studio 2015



*/



#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#define SUB_NUM 2 //���ð��� ��
#define TT_NUM 10 //���� ������ ��
typedef struct _subject_score {//���� ���� ����ü
	char cname[SUB_NUM][20];//�����
	int jumsu[SUB_NUM]; //���� ���� ����
} subj_score;
typedef struct _testTaker {//���� ������ ����ü
	char *name; //������ �̸�
	subj_score score; //���ð��� �� ����(���� ���� ����ü)
}testTaker;



void create_testTaker(testTaker ** tt) {//������ ����, ���� ���� �Է�, ������ �̸� �Է�, ���� ���� ���� ����
	
	for (int i = 0; i < TT_NUM; i++) {//������ ����, ����ü �����͹迭�� �����Ҵ��Ѵ� 
		tt[i] = (testTaker*)malloc(sizeof(testTaker));
	}

	char temp[20];//�ӽ÷� ���ڿ� �Է¹��� ���� ���� 
	int len = sizeof(temp) + 1;//�ӽ� ���ڿ� ������ ũ�� ���� +1�� �ΰ��̴�
	for (int k = 0; k < SUB_NUM; k++) {//���� ���� �Է�, �����ڼ��� �ٸ��ٴ� �Ϳ� ���� 
		printf("���ð���%d �̸� �Է�: ",k+1);
		gets_s(tt[k]->score.cname[k]);//�����̸� �Է� 
	}

	for (int j = 0; j < TT_NUM; j++) {//������ �̸� �Է�
		printf("������%d �̸� �Է�: ",j+1);
		gets_s(temp);// �ӽ� ���幮�ڿ������� ���ڿ� �Է� 
		tt[j]->name = (char*)malloc(sizeof(char) * len);//temp���ڿ��� �Է��� ũ�⸸ŭ �Ҵ� 
		strcpy(tt[j]->name, temp);// ���ڿ� ���� 
	}

	for (int i = 0; i < TT_NUM; i++) {//���� ���� ���� ���� 
		for (int j = 0; j < SUB_NUM; j++) {
			tt[i]->score.jumsu[j] = rand() % 71 + 30;//30~100 �� ���ڵ��� �������� ���� 
		}

	}



}

void print_testTaker(testTaker ** tt) {//���� ������ ��� ���(�̸�, �����, ����, ���, PASS or FAIL)

	double avg;// ���� ������� ������ ���� 

	for (int i = 0; i < TT_NUM; i++) {
		printf("%s: ", tt[i]->name);// ������ �̸� ��� 

		for (int j = 0; j < SUB_NUM; j++) {
			printf("%s(%d), ", tt[j]->score.cname[j],tt[i]->score.jumsu[j]);// ���� ���� �� ����� �ش� ���� ��� 
		}
		avg = (double)(tt[i]->score.jumsu[0] + tt[i]->score.jumsu[1] )/ 2;// ��� ���� (�Ǽ�)
		if (tt[i]->score.jumsu[0] >= 40 && tt[i]->score.jumsu[1] >= 40 && avg >= 60)//�� ������ ���� ��� 40�� �̻��̿��� �ϰ� ����� 60�� �̻� 
			printf("���(%.2f)=> PASS", avg);//���� ������ ��� ������ �Բ� PASS��� 
		else
			printf("���(%.2f)=> FAIL", avg);//���� ���� ���� ���ҽ� ��� ������ �Բ� FAIL��� 
		printf("\n");
	}
	



}


void delete_testTaker(testTaker ** tt)// �޸� �Ҵ� ���� �Լ� 
{
	for (int i = 0; i < TT_NUM; i++) {
		free(tt[i]->name);//����ü�� name���� �޸��Ҵ� ���� 
		free(tt[i]);// ���� ���� �Ҵ��� tt������ �迭 �޸� �Ҵ� ���� 
	}

}

void main()
{
	testTaker *tt[TT_NUM];
	srand((unsigned int)time(NULL));
	create_testTaker(tt);
	printf("***���� ���***\n");
	print_testTaker(tt);
	printf("��� �Ϸ�\n");
	delete_testTaker(tt);
	printf("�޸� �Ҹ� �Ϸ�\n");
}