#pragma one
#include<string.h>
#include<stdio.h>
#define MAXDAUSACH 1000

struct MucSach{
	int maSach;
	int TrangThai;
	char ViTri[100];
	MucSach *pNext;
};

struct DanhMucSach{
	int SLDms = 0;
	MucSach *pHead = NULL;
	MucSach *pLast = NULL;
};
typedef struct DanhMucSach listDMS;

struct DauSach{
	char ISBN[10];
	char TenSach[100];
	int SoTrang;
	char TacGia[100];
	char TheLoai[100];
	int NamXB;
	DanhMucSach *dMS;
};

struct DanhSachDauSach{
	int SLDauSach = 0;
	DauSach *danhSachDauSach[MAXDAUSACH];
};
typedef struct DanhSachDauSach listDS;


struct MuonTra{
	int maSach;
	char NgayMuon[11];
	char NgayTra[11];
	int trangThai;
	MuonTra *pNext;
	MuonTra *prev;
};

struct DanhSachMuonTra{
	int SLDS = 0;
	MuonTra *pHead = NULL;
	MuonTra *pTail = NULL;
};
typedef struct DanhSachMuonTra listMT;

struct DocGia{
	int MaThe;
	char ho[50];
	char ten[20];
	char phai[4];
	int trangThaiThe;
	DanhSachMuonTra *dSMuonTra;
	DocGia *pLeft;
	DocGia *pRight;
};
typedef struct DocGia* Tree;

struct DanhSachDocGia{
	int SLDocGia = 0;
	Tree dsDocGia = NULL;
};
typedef struct DanhSachDocGia listDG;

struct Ngay{
	int ngay;
	int thang;
	int nam;
};
