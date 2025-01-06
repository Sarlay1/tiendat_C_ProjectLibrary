#include <stdio.h>
#include <stdlib.h>
#include"function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	int currentLength;
	Book Books[50];
	char search[50];
    loadBooksFromFile(&currentLength, Books );

	do{
		system("cls");
		char check;	
		printMenu();
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				system("cls");
				printf("			****NHAP SO LUONG VA THONG TIN SACH****\n");
				inputBook(&currentLength, Books);
				saveOfFile(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
			    break;
			case 2:
				system("cls");
				printf("\n			****TAT CA THONG TIN SACH****\n");
				printf("======================================================\n");
			    loadBooksFromFile(&currentLength, Books );
			//	printBook(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
				break;
			case 3:
				system("cls");
				printf("			****THEM SACH****\n");
				addBook(&currentLength, Books);
				saveOfFile(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
				break;
			case 4:
				 system("cls");
				printf("			****CAP NHAT DANH SACH SACH****\n");
				updateBook(currentLength, Books);
				saveOfFile(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
				break;
			case 5:
				 system("cls");
				printf("			****XOA SACH****\n");
				deleteBook(&currentLength, Books);
				saveOfFile(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
				break;
			case 6:
				system("cls");
				printf("			****TIM KIEM SACH THEO TEN****\n");
				searchBook(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
				break;
			case 7:
				 system("cls");
				printf("			****SAP XEP SACH THEO GIA****\n");
				arrangeBooks(currentLength, Books);
				saveOfFile(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
				break;
			case 8: 
			    system("cls");
			    printf("			****LUU FILE SACH****\n");
				
				saveOfFile(currentLength, Books);
				printf("\nGo back(b)? or Exit(0)?: ");
                scanf(" %c", &check);
                if(check == '0'){
                    return 0;
                }
			    system("pause");
			    break;
			case 9:
				 system("cls");
				printf("        ======= THANK YOU FOR USING! ======\n");
				printf("        =======   AND SEE YOU SOON!  ======\n");
				printf("-----------------------------------------\n");
				break;
			default:
				printf("Lua chon khong hop le vui long nhap lai!");
				break;
		}
	}while(choice!=9);
	return 0;
}
