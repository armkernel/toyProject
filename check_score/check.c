#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<wchar.h>

int pidx = 0; // person index
int sidx = 0; // sticker index
int bidx = 0; // diff index 

char gname[50][50] = {"조용원","홍종호","강환웅","이호중","정윤송","박다현","성진우","김선두","김상엽","이범혁","김수빈","이재환","김하성","이원재","이윤진","김동현","박하늘","최준혁","김현욱","임충호","민예슬","전강배","조수호","김지환","최현우","정원경","이태희"};

typedef struct _person {
	unsigned char name[50];
	int id;	 
	int counter;
} person;


typedef struct _color {
	int id;
	unsigned char colorName[50];
} color;

void print(person *,color *);

void init_lge (person *C, color *sticker){
	FILE *fp,*fp_sticker;
	char *str,*token;
	char s1[] = "\t\n";
	int buffer_size = 1024;


	fp = fopen("./data/C.data","rw");
	fp_sticker = fopen("./data/sticker.data","rw");

	str = malloc(buffer_size);


	while(fgets(str,buffer_size,fp)){

		token = strtok(str,s1);
		C[pidx].id = atoi(token);
		strcpy(C[pidx].name,gname[pidx]);
		/*
		while(token != NULL) {
			
			token = strtok(NULL,str);
			
			///if(token != NULL) {
				//strcpy(C[pidx].name,token);
			//	C[pidx].name[strlen(token)-1] = '\0';
			//	printf("%s",C[pidx].name);
			//}
		}*/
		C[pidx].counter = 0;
		pidx++;
	}

	token = NULL;

	while(fgets(str,buffer_size,fp_sticker)) { 
	
		token = strtok(str,s1);
		sticker[sidx].id = atoi(token);

		while(token != NULL) {
			
			token = strtok(NULL,str);
			if(token != NULL) {
				strcpy (sticker[sidx].colorName,token);
				sticker[sidx].colorName[strlen(token)-1] = '\0';
			}
		}
		sidx++;
	}
	free(str);
	str = NULL;
	fclose(fp_sticker);
	fclose(fp);
}


void print (person *C, color *sticker) {
	
	int i;
	int totalSticker[10] = {0}; 
	for( i = 0; i<pidx;i++) {
		if(C[i].counter) {
		printf("%d조  %s \t스티커 : %s\t%d 개\n",C[i].id,C[i].name,sticker[C[i].id - 1].colorName,C[i].counter);
		
		totalSticker[C[i].id] += C[i].counter;
		}
	}
	printf("============================================================\n");
	for(i = 0; i<sidx;i++) {
		printf("%d 조	총  %s \t%d 개\n",sticker[i].id,sticker[i].colorName,totalSticker[i+1]);  
	}

	printf("============================================================\n\n\n");

}

void input(person *C,color *sticker) {

	int i;
	char tmp_str[50];
	char buffer[50];
	char *token;
	while(1) {
		//printf("질문 학생의 이름을 입력하세요 : ");
		//scanf("%s",tmp_str);
		int num = 0;

		
		fgets(buffer,50,stdin); 

		token= strtok(buffer," ");
		strcpy(tmp_str,token);

		

		while(token != NULL) {
			
			token = strtok(NULL,buffer);
			if(token != NULL) {
				num = atoi(token);		
				//break;
			}
		}

		if(num == 0) {
			tmp_str[strlen(tmp_str)-1] = '\0';
			num = 1;
		}


		if(!strcmp(tmp_str,"end")) break;
		
		for(i = 0; i<pidx;i++) {
			if(!strcmp(C[i].name,tmp_str)) {
				C[i].counter+=num;				
				print(C,sticker);
				fflush(stdout);
				break;
			}
		}		
	}

}


//vs code
int main(int argc, char *argv[]) {
	
	person C[30];
	color sticker[10];
	char name[50][50]; 

	init_lge(C,sticker);
	input(C,sticker);
	print(C,sticker);
	
	return 0;
}
