#include"function.h"
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_LENGTH 50
//Logic ham

void printMenu(){
	printf("\n*******LIBRARY MANAGEMENT*******\n");
	printf("\n=========== MENU ===========\n");
    printf("[1]. Nhap so luong va thong tin sach\n");
    printf("[2]. Hien thi thong tin sach\n");
    printf("[3]. Them sach vao vi tri\n");
    printf("[4]. Cap nhat thong tin theo id sach\n");
    printf("[5]. Xoa sach theo ma sach\n");
    printf("[6]. Tim kiem sach theo ten\n");
    printf("[7]. Sap xep sach theo gia tien\n");
    printf("[8]. Luu file\n");
    printf("[9]. Thoat chuong trinh\n");
    printf("============================\n");
}

int checkDuplicateIdAndTitle(Book books[], int n, int id, const char* title) {
	int i;
    for ( i = 0; i < n; i++) {
        if (books[i].id == id) {
            printf("ID sach da ton tai. Vui long nhap ID khac.\n");
            return 1;  
        }
         if (strcmp(books[i].title, title) == 0) {
            printf("Ten sach da ton tai. Vui long nhap ten sach khac.\n");
            return 1;  
        }
    }
    return 0;  
}

void inputBook(int *n, Book books[]) {
    int i;
    printf("Nhap vao so luong sach: ");
    scanf("%d", n);
    getchar();  
    for (i = 0; i < *n; i++) {
        printf("Quyen sach thu %d: \n", i + 1);
        do {
            printf("Nhap ID sach: ");
            scanf("%d", &books[i].id);
            getchar(); 
            if (checkDuplicateIdAndTitle(books, i, books[i].id, "")) {
                printf("Vui long nhap lai ID sach.\n");
            } else {
                break;
            }
        } while (1);

        do {
            printf("Nhap ten sach (max %d ky tu): ", MAX_LENGTH - 1);
            fgets(books[i].title, 100, stdin);
            books[i].title[strcspn(books[i].title, "\n")] = '\0'; 
            if (strlen(books[i].title) == 0) {
                printf("Ten sach khong duoc de trong. Vui long nhap lai.\n");
            } else if (strlen(books[i].title) >= MAX_LENGTH) {
                printf("Ten sach qua dai. Vui long nhap lai.\n");
            } else {
                break;
            }
        } while (1);

        do {
            printf("Nhap ten tac gia (max %d ky tu): ", MAX_LENGTH - 1);
            fgets(books[i].author, 100, stdin);
            books[i].author[strcspn(books[i].author, "\n")] = '\0'; 	
            if (strlen(books[i].author) == 0) {
                printf("Ten tac gia khong duoc de trong. Vui long nhap lai.\n");
            } else if (strlen(books[i].author) >= MAX_LENGTH) {
                printf("Ten tac gia qua dai. Vui long nhap lai.\n");
            } else {
                break;
            }
        } while (1);
        
        do {
            printf("Nhap gia sach: ");

            if (scanf("%d", &books[i].price) != 1) {
                printf("Gia sach khong hop le. Vui long nhap lai.\n");
                while(getchar() != '\n'); 
            } else if (books[i].price < 0) {
                printf("Gia sach khong the la so am. Vui long nhap lai.\n");
            } else {
                break;
            }
        } while (1);
    }
}

void printBook(int n, Book books[]){
	int i;
    printf("==================================================================\n");
    printf("|ID||    Ten sach        ||    Tac gia         ||  Gia tien     |\n");
    printf("==================================================================\n");
    for(i=0 ;i<n;i++){
        printf("| %d ||%-20s||%-20s||%-15d|\n", books[i].id, books[i].title, books[i].author, books[i].price);
        printf("------------------------------------------------------------------\n");
                
    }
    printf("=====================================================\n");
    printf("\n");
}


int isDuplicate(Book books[], int n, Book newBook) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(books[i].title, newBook.title) == 0 && strcmp(books[i].author, newBook.author) == 0) {
            return 1; 
        }
    }
    return 0; 
}
		

void addBook(int *n, Book books[]){
	Book newBook;

	getchar();
	newBook.id=*n+1;
	printf("Moi ban nhap ID moi: \n");
	scanf("%d", &newBook.price);
	getchar();
	printf("Moi ban nhap ten sach moi: \n");
	fgets(newBook.title, 100, stdin);
	newBook.title[strcspn(newBook.title, "\n")] = '\0';
	printf("Moi ban nhap ten tac gia: \n");
	fgets(newBook.author, 100, stdin);
	newBook.author[strcspn(newBook.author, "\n")] = '\0';
	printf("Moi ban nhap gia tien moi: \n");
	scanf("%d", &newBook.price);
	getchar();
	if (!isDuplicate(books, *n, newBook)) {
	 books[*n] = newBook; 
	  (*n)++; 
	   saveOfFile(*n, books);
	  printf("Them sach thanh cong!\n");
	   } else {
	    printf("Sach da ton tai trong thu vien.\n");
		 }
}

void deleteBook(int *n, Book books[]) {
    int position, findIndex = -1;
    int i;
    printf("Nhap ID muon xoa: ");
    scanf("%d", &position);
    for (i = 0; i < *n; i++) {
        if (books[i].id == position) {
            findIndex = i;
            break;
        }
    }
    if (findIndex == -1) {
        printf("Khong tim thay sach de xoa.\n");
    } else {
        int val;
		printf("==================================================================\n");
		printf("| ID |        Ten sach       |        Tac gia        |  Gia tien   |\n");
		printf("==================================================================\n");
		printf("| %-3d | %-20s | %-20s | %-15d |\n", books[findIndex].id, books[findIndex].title, books[findIndex].author, books[findIndex].price);
		printf("==================================================================\n");
		printf("Ban co chac muon xoa sach nay khong? [1](Co) [2](Khong): ");
		scanf("%d", &val);
        if (val == 1) {
            for ( i = findIndex; i < *n; i++) {
                books[i] = books[i + 1]; 
            }
            (*n)--;
            printf("XOA THANH CONG!\n");
        } else if (val == 2) {
            printf("DA HUY QUA TRINH XOA!\n");
        } else if((val !=1)&&(val!=2)){
            printf("Khong co lua chon nay!\n");
        }
    }
    system("pause");
}



void saveOfFile(int n, Book books[]){
	// Mo file 
	FILE *ptr=fopen("studentsData.dat","wb");
	// Thao tac file
	if(ptr==NULL){
		printf("Khong mo duoc file.\n");
	
	}
    fwrite(&n, sizeof(int), 1, ptr); 
	fwrite(books,sizeof(Book),n,ptr);
	printf("Luu thong tin thanh cong");
	// Dong file 
	fclose(ptr);
}

void loadBooksFromFile(int *n, Book books[]) {
	// Mo file 
	FILE *ptr = fopen("studentsData.dat", "rb");
	// Thao tac file
	if(ptr==NULL){
		printf("Khong mo duoc file");
	    return;
	}
	 fread(n, sizeof(int), 1, ptr);
     if (*n > 0) {
        fread(books, sizeof(Book), *n, ptr); 
    }
	int i;
	printf("==================================================================\n");
    printf("|ID||    Ten sach        ||    Tac gia         ||  Gia tien     |\n");
    printf("==================================================================\n");
    for(i=0 ;i<*n;i++){
        printf("| %d ||%-20s||%-20s||%-15d|\n", books[i].id, books[i].title, books[i].author, books[i].price);
        printf("------------------------------------------------------------------\n");
                
    }
    printf("=====================================================\n");
    printf("\n");

    
	printf("Lay Du Lieu Thanh Cong\n");
	// Dong file 
	fclose(ptr);

	}


void searchBook(int n, Book books[]){
	char searchTitle[100];
	char searchLower[100];
	void toLowerCase(char *str){
		int i;
    	for(i = 0; str[i]; i++){
        	str[i] = tolower(str[i]);
    	}
	}
    int found=0;
    printf("Moi ban nhap vao ten sach can tim: ");
    getchar();
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';
    strcpy(searchLower, searchTitle);
    toLowerCase(searchLower);
    printf("Ket qua tim kiem:\n");
    int i;
    for(i = 0; i<n; i++){
        char titleLower[100];
        strcpy(titleLower, books[i].title);
        toLowerCase(titleLower);
        if (strstr(titleLower, searchLower) != NULL) {
		printf("==================================================================\n");
		printf("|ID ||     Ten sach       ||      Tac gia       ||    Gia tien   |\n");
		printf("==================================================================\n");
		printf("| %d ||%-20s||%-20s||%-15d|\n", books[i].id, books[i].title, books[i].author, books[i].price);
		printf("------------------------------------------------------------------\n");
		printf("==================================================================\n");
		printf("\n");          
		  found = 1;
        }
    }
    if (!found) {
        printf("KHONG TIM THAY SACH!\n");
    }
}


void updateBook(int n, Book books[]){
	int position;
	int i;
	printf("Moi ban nhap vao ID sach muon update:");
	scanf("%d", &position);
	int findIndex=-1;
	for( i=0;i<n;i++){
		if(books[i].id==position){
			findIndex =i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("KHONG TIM THAY SACH DE UPDATE! ");
	}else{
		printf("| %d ||%-20s||%-20s||%-15d|\n", books[i].id, books[i].title, books[i].author, books[i].price);
		getchar();
		printf("CAP NHAT THONG TIN CHO SACH\n");
		printf("Moi ban nhap vao ten sach: \n");
		fgets(books[findIndex].title, 100, stdin);
		books[findIndex].title[strcspn(books[findIndex].title, "\n")] = '\0';
		printf("Moi ban nhap vao ten tac gia: \n");
		fgets(books[findIndex].author, 100, stdin);
		books[findIndex].author[strcspn(books[findIndex].author, "\n")] = '\0';
		printf("Moi ban nhap vao gia tien: \n");
		scanf("%d", &books[findIndex].price);
		getchar();
		printf("UPDATE SACH THANH CONG!");
	}
}


void arrangeBooks(int n, Book books[]){
	int arrange;
	printf("1.Sap xep giam dan\n");
	printf("2.Sap xep tang dan\n");
	printf("Nhap lua chon cua ban: ");
    scanf("%d", &arrange);
    if (arrange == 1){
    	int i;
        for(i=0; i<n-1; i++){
		int j;
            for(j=i+1; j<n; j++) {
                if(books[i].price < books[j].price){
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
        printf("SAP XEP GIAM DAN THEO GIA TIEN THANH CONG!\n");
		printf("==================================================================\n");
		printf("|ID ||     Ten sach       ||      Tac gia       ||    Gia tien   |\n");
		printf("==================================================================\n");
		for(i=0 ;i<n;i++){
			printf("| %d ||%-20s||%-20s||%-15d|\n", books[i].id, books[i].title, books[i].author, books[i].price);
			printf("------------------------------------------------------------------\n");
		}
		printf("==================================================================\n");
		printf("\n");
    }else if(arrange == 2){
		int i; 
        for(i=0; i<n-1; i++){
			int j;
            for(j=i+1; j<n; j++) {
                if (books[i].price > books[j].price){
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
        printf("SAP XEP TANG DAN THEO GIA TIEN THANH CONG!\n");
		printf("==================================================================\n");
		printf("|ID ||     Ten sach       ||      Tac gia       ||    Gia tien   |\n");
		printf("==================================================================\n");
		for(i=0 ;i<n;i++){
			printf("| %d ||%-20s||%-20s||%-15d|\n", books[i].id, books[i].title, books[i].author, books[i].price);
			printf("------------------------------------------------------------------\n");
		}
		printf("==================================================================\n");
		printf("\n");
    }else{
        printf("LUA CHON KHONG HOP LE!\n");
        return;
    }
}



