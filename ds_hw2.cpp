
/*
학과: 컴퓨터정보공학부
학번:201521514
이름:최해랑
버전: visual studio 2015



*/



#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#define SUB_NUM 2 //응시과목 수
#define TT_NUM 10 //시험 응시자 수
typedef struct _subject_score {//과목 점수 구조체
	char cname[SUB_NUM][20];//과목명
	int jumsu[SUB_NUM]; //과목에 대한 점수
} subj_score;
typedef struct _testTaker {//시험 응시자 구조체
	char *name; //응시자 이름
	subj_score score; //응시과목 및 점수(과목 점수 구조체)
}testTaker;



void create_testTaker(testTaker ** tt) {//응시자 생성, 응시 과목 입력, 응시자 이름 입력, 과목 점수 랜덤 결정
	
	for (int i = 0; i < TT_NUM; i++) {//응시자 생성, 구조체 포인터배열을 동적할당한다 
		tt[i] = (testTaker*)malloc(sizeof(testTaker));
	}

	char temp[20];//임시로 문자열 입력받을 변수 생성 
	int len = sizeof(temp) + 1;//임시 문자열 변수의 크기 저장 +1은 널값이다
	for (int k = 0; k < SUB_NUM; k++) {//응시 과목 입력, 응시자수와 다르다는 것에 주의 
		printf("응시과목%d 이름 입력: ",k+1);
		gets_s(tt[k]->score.cname[k]);//과목이름 입력 
	}

	for (int j = 0; j < TT_NUM; j++) {//응시자 이름 입력
		printf("응시자%d 이름 입력: ",j+1);
		gets_s(temp);// 임시 저장문자열변수에 문자열 입력 
		tt[j]->name = (char*)malloc(sizeof(char) * len);//temp문자열에 입력한 크기만큼 할당 
		strcpy(tt[j]->name, temp);// 문자열 복사 
	}

	for (int i = 0; i < TT_NUM; i++) {//과목 점수 랜덤 결정 
		for (int j = 0; j < SUB_NUM; j++) {
			tt[i]->score.jumsu[j] = rand() % 71 + 30;//30~100 의 숫자들을 랜덤으로 배정 
		}

	}



}

void print_testTaker(testTaker ** tt) {//시험 응시자 결과 출력(이름, 과목명, 점수, 평균, PASS or FAIL)

	double avg;// 과목 평균점수 저장할 변수 

	for (int i = 0; i < TT_NUM; i++) {
		printf("%s: ", tt[i]->name);// 응시자 이름 출력 

		for (int j = 0; j < SUB_NUM; j++) {
			printf("%s(%d), ", tt[j]->score.cname[j],tt[i]->score.jumsu[j]);// 응시 과목 및 과목당 해당 점수 출력 
		}
		avg = (double)(tt[i]->score.jumsu[0] + tt[i]->score.jumsu[1] )/ 2;// 평균 구함 (실수)
		if (tt[i]->score.jumsu[0] >= 40 && tt[i]->score.jumsu[1] >= 40 && avg >= 60)//두 과목의 점수 모두 40점 이상이여야 하고 평균은 60점 이상 
			printf("평균(%.2f)=> PASS", avg);//조건 만족시 평균 점수와 함께 PASS출력 
		else
			printf("평균(%.2f)=> FAIL", avg);//위의 조건 만족 못할시 평균 점수와 함께 FAIL출력 
		printf("\n");
	}
	



}


void delete_testTaker(testTaker ** tt)// 메모리 할당 해제 함수 
{
	for (int i = 0; i < TT_NUM; i++) {
		free(tt[i]->name);//구조체의 name변수 메모리할당 해제 
		free(tt[i]);// 가장 먼저 할당한 tt포인터 배열 메모리 할당 해제 
	}

}

void main()
{
	testTaker *tt[TT_NUM];
	srand((unsigned int)time(NULL));
	create_testTaker(tt);
	printf("***응시 결과***\n");
	print_testTaker(tt);
	printf("출력 완료\n");
	delete_testTaker(tt);
	printf("메모리 소멸 완료\n");
}