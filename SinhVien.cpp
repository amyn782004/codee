#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct SinhVien {
	char MSSV[50];
	char hoten[50];
	float DTB;
	SinhVien* next;
} SV;

typedef SV* LIST;

SV* TaoNode(SV x) {
	SV* p = new SV;
	if (p == NULL) {
		printf("Het bo nho");
		exit(0);
	}
	strcpy(p->MSSV, x.MSSV);
	strcpy(p->hoten, x.hoten);
	p->DTB = x.DTB;
	p->next = NULL;
	return p;
}

void KhoiDongDS(LIST* l) {
	*l = NULL;
}

SV* themvaocuoi(SV* l, SV* p) {
	if (l == NULL) {
		return p;
	}
	SV*  i;
	for (i = l; i->next != NULL; i = i->next);
	i->next = p;
	return i;
}

void nhapsv(SV &x);

void Nhapds(LIST &l, int n) {
	SV x;
	SV* p;
	KhoiDongDS(&l);
	for(int i=0; i<n; i++) {
		printf("\n\tsinh vien thu %d",i+1);
		nhapsv(x);
		p = TaoNode(x);
		l = themvaocuoi(l,p);
	}
}

void nhapsv(SV &x) {
	printf("\n1.Nhap MSSV: ");
	fflush (stdin);
	gets(x.MSSV);
	printf("Nhap ten Sinh Vien: ");
	gets(x.hoten);
	printf("Nhap Diem trung binh: ");
	scanf("%f",&x.DTB);
}

void xuatds(LIST l,int n) {
	SV* x = l;
	printf("\n\tDanh sach da nhap: \n");
	for(int i=0; i<n; i++) {
		printf("sinh vien thu %d",i+1);

		printf("MSSV: %s\n", x->MSSV);
		printf("Ten Sinh Vien: %s\n", x->hoten);
		printf("Diem Trung Binh: %.2f\n\n", x->DTB);
	}
}

void ThemPsauQ(SV& p, SV* q) {

}

void menu() {

}
int main() {
	int n;
	SV x, head;
	LIST l;
	printf("Nhap so sinh vien: ");
	scanf("%d", &n);
	Nhapds(l,n);
	xuatds(l,n);
	return 0;
}