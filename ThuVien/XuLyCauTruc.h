#pragma one
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<fstream>
#include<time.h>
#include <sstream>
#include <cstring>
#include<Math.h>
#include "Data.h"
#include <ctime>

using namespace std;

// ====================== Doc Gia ==========================//
int CountNode(Tree t);
int HeightTree(Tree t);
int TaoMaThe(Tree t, int arr1[], int arr2[], int &nt, int &np);
void AddNodeOnTree(Tree &t, DocGia *a);
void NodeThayThe(Tree &t, Tree &x);
void XoaNodeDocGia(Tree &t, int maDocGia);
DocGia *findDocGia(Tree t, int maThe);
void ThemDSDocGia(DocGia *dS[], DocGia *newDocGia, int &n);
void ChuyenDoiDuLieuDocGia(Tree t, DocGia *ds[], int &n);
void ThemDSDocGiaCauI(DocGia *dS, DocGia newDocGia, int &n, int *dSQuaHan);
void ChuyenDoiDuLieuDocGiaCauI(Tree t, DocGia *dS, int &n, int *dSQuaHan);
int partitionDocGiaTen(DocGia *dS[], int l, int r);
int partitionDocGiaID(DocGia *dS[], int l, int r);
void quickSortDocGiaTenHienThi(DocGia *dS[], int l, int r);
void quickSortDocGiaIDHienThi(DocGia *dS[], int l, int r);
void capNhatKhoaThe(Tree &t);

// ========================== Muon Tra ======================//

bool checkThemMuonTraBa(DanhSachMuonTra *dS);
int checkMaSachThemMuon(DanhSachDauSach dS, int maSach);
bool checkNgayMuon(Ngay dateMuon, Ngay dateTra);
void chuanHoaNgay(Ngay &ngay, char s[]);
int checkNgayDauVao(Ngay dateMuon);
void themVaoCuoiMuonTra(DanhSachMuonTra *dS, MuonTra *p);
void themVaoCuoiDanhSachMuonTra(DanhSachMuonTra &dS, MuonTra *p);
MuonTra *findMuonTra(DanhSachMuonTra dS, int maSach);
int soNgayTrongNam(Ngay ngay);
int soNgayQuaHan(Ngay ngay);
bool kiemTraMuonBayNgay(DanhSachMuonTra *dS);
int soLuongMuon(DanhMucSach *dS, DanhSachMuonTra dSMT);
int partitionSoLuongMuonDauSach(DauSach *dS[], int l, int r, DanhSachMuonTra dSMT);
bool kiemTraMuonTraCoTonTai(int maSach, char ngay[11], DanhSachMuonTra *dS);
int demSoMuonTraDangMuon(DanhSachMuonTra *dSMT);
DauSach *findDauSachTheoMaSach(DanhSachDauSach dS, int maSach);
bool kiemTraISBN(DanhSachDauSach dS, char ISBN[10]);
void capNhatMuon(DanhMucSach &dMS, DanhSachDauSach &dSDS, DanhSachMuonTra &dSMT, DanhSachMuonTra *dS, MuonTra *p, MuonTra *q);
void capNhatTra(DanhMucSach &dMS, DanhSachDauSach &dSDS, DanhSachMuonTra &dSMT, DanhSachMuonTra *dS, int maSach, char ngayMuon[10], int capNhat);
bool checkHaiSachChungDauSach(int maSach, DanhSachMuonTra dSMT, DanhSachDauSach dSDS);

// ========================= Dau Sach =========================//

void themSach(DanhSachDauSach &dS, DauSach *dauSach);
DauSach *findDauSach(DanhSachDauSach dS, char ISBN[10]);
int timKiemNhiPhan(int l, int r, DanhSachDauSach dS, char ten[100]);
int tongSoSachCoTheChoMuon(DanhSachDauSach dS);
int kiemTraXoaDauSach(DanhMucSach *dMS, DanhSachMuonTra dSMT);
void xoaDauSach(DanhSachDauSach &dS, char ISBN[10], DanhMucSach &dMS);
int partition(DauSach *dS[], int l, int r);
int partitionTenSach(DauSach *dS[], int l, int r);
void quickSortDauSachHienThi(DauSach *dS[], int l, int r);
void quickSortTenSach(DauSach *dS[], int l, int r);
void quickSortMuonTraDauSach(DauSach *dS[], int l, int r, DanhSachMuonTra dSMT);

//========================= Muc Sach =========================//

void themVaoCuoi(DanhMucSach *dMS, MucSach *newMucSach);
void themVaoCuoiDMS(DanhMucSach &dMS, MucSach *newMucSach);
MucSach *findMucSachByID(int maSach, DanhMucSach dMS);
bool kiemTraMucSachXoa(int maSach, DanhSachMuonTra dSMT);
void xoaMucSach(int maSach, DanhSachDauSach &dSDS, DanhMucSach &dMS);
void capNhatDauSachMucSach(MucSach *p, DanhSachDauSach &dSDS);
void xoaMucSachTheoDauSach(DanhMucSach *dMSDS, DanhMucSach &dMS);

//////////////// Doc File ///////////////////////////////
void docFileDauSach(DanhSachDauSach &dSDS, DanhMucSach &dMS, int &idDMSMax);
void docFileDocGia(DanhSachDocGia &dSDG, DanhSachMuonTra &dSMT);

//======================== Ghi file ==============================//
void ghiFileDauSach(DanhSachDauSach dSDS, int idDMSMax);
void ghiDanhSachDocGia(DanhSachDocGia dSDG);

// Linh Tinh
// chuyen doi du lieu

int charToInt(char c)
{
   int arr[]={0,1,2,3,4,5,6,7,8,9};
   return arr[c-'0'];
}

char Inttochar(int n)
{
	switch (n)
    {
	    case 0:
	        return '0';
	    case 1:
	        return '1';
	    case 2:
	        return '2';
	    case 3:
	        return '3';
	    case 4:
	        return '4';
	    case 5:
	        return '5';
	    case 6:
	        return '6';
	    case 7:
	        return '7';
	    case 8:
	        return '8';
	    case 9:
	        return '9';
	    default:
	        return '0';
    }
}

int Convert(char s[]){
	int result = 0;
	for(int i = 0; i < strlen(s); i++)
	{
		if(s[i] == '\0')
			break;
		result = result*10 + charToInt(s[i]);
	}
	return result;
}

int lengCuaMotSo(int x)
{
	int kq = 0;
	while(x > 0)
	{
		kq++;
		x = x/10;
	}
	return kq;
}

void ConvertIntToChar(char s[], int x){
	int daoNguoc = 0;
	int leng = lengCuaMotSo(x);
	for(int i = leng - 1; i >= 0; i--)
	{
		s[i] = Inttochar(x % 10);
		x /= 10;
	}
	s[leng] = '\0';
}

// Set ID

void TaoMangRd (int arr[], int min, int max)
{
	for(int i = min; i <= max ; i++)
	{
		if(min == 1 )
		{

			arr[i-1] = i;	
		}
		else if (min == 501)
		{
			arr[i-500-1] = i;
		}
	}
}

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int Random(int minN, int maxN)
{
	srand((int)time(0));
    return minN + rand() % (maxN + 1 - minN);
}

void RandomMang(int arr[])
{
	for(int i = 0; i < 250; i++)
	{
		int x = Random(0, 499-i);
		swap(arr[x], arr[499-i]);
	}
}

int RDMang (int arr[], int sch)
{
	int x = Random(0,499-sch);
	swap(arr[x],arr[499-sch]);
	return arr[499-sch];
}

int CountNode(Tree t)
{
	Tree Stack[1000];
	Tree p = t;
	int i = 0;
	int sp = -1;	// Khoi tao Stack rong
	do
	{
		while (p != NULL)
		{
			sp++;
			Stack[sp] = p;
			p = p->pLeft;
		}
		if (sp != -1)
		{
			p = Stack[sp];
			sp--;
			++i;
			p = p->pRight;
		}
		else	
			break;		
	} 
	while (1);
	return i;
}

//tra ve gia tri lon nhat trong hai so a va b
int Max(int a, int b) {
   if(a>b)
      return a;
   else
      return b;
}

int HeightTree(Tree t) {
   if( t == NULL)
      return 0;
   else
      return Max(HeightTree(t->pLeft),HeightTree(t->pRight)) + 1;
}

// Muon tra

////////////////////////////////////////////////////////////////////////////////////

bool checkThemMuonTraBa(DanhSachMuonTra *dS)
{
	int i = 0;
	MuonTra *p = dS->pHead;
	while(p != NULL)
	{
		if(p->trangThai == 0)
		{
			i++;
			if(i == 3)
				return false;
		}
		p = p->pNext;
	}
	return true;
}

// check xem ma sach co ton tai khong
// 0 ko ton tai
// 1 da thanh ly
// 2 co thang muon
// 3 muon dc 
int checkMaSachThemMuon(DanhSachDauSach dS, int maSach)
{
	if(dS.SLDauSach == 0)
		return 0;
	for(int i = 0; i < dS.SLDauSach; i++)
	{
		MucSach *p = dS.danhSachDauSach[i]->dMS->pHead;
		while(p !=NULL)
		{
			if(p->maSach == maSach)
			{
				if(p->TrangThai == 1)
					return 2;
				else if(p->TrangThai == 2)
					return 1;
				else
					return 3;
			}
			p = p->pNext;
		}
	}
	return 0;
}

// true la cho nhap
// fales la cut
bool checkNgayMuon(Ngay dateMuon, Ngay dateTra){
	if(dateMuon.nam <= dateTra.nam)
	{
		if(dateMuon.nam == dateTra.nam)
		{
			if(dateMuon.thang <= dateTra.thang)
			{
				if(dateMuon.thang == dateTra.thang)
				{
					if(dateMuon.ngay < dateTra.ngay)
						return true;
					else
						return false;
				}
				else
					return true;
			}
			else
				return false;	
		}
		else
			return true;
	}
	else
		return false;
}

void chuanHoaNgay(Ngay &ngay, char s[])
{
	char tmp[5];
	int index = 0;
	// dem xem do la ngay hay thang hay nam
	int count = 0;
	memset(tmp, 0, 5);
	for(int i = 0; i < strlen(s); i++)
	{
		if(s[i] == '\0')
			break;
		if(s[i] == '-')
		{
			if(count == 0)
			{
				ngay.ngay = Convert(tmp);
			}
			else if(count == 1)
			{
				ngay.thang = Convert(tmp);
			}
			memset(tmp, 0, 5);
			index = 0;
			count++;
		}
		else
		{
			tmp[index] = s[i];
			index++;
		}
	}
	ngay.nam = Convert(tmp);
}



int checkNgayDauVao(Ngay dateMuon){
	if(dateMuon.ngay > 31 || dateMuon.ngay < 0)
		return 1;
	if(dateMuon.thang > 12 || dateMuon.thang < 0)
		return 2;
	if(dateMuon.nam < 0)
		return 3;
	if(dateMuon.thang == 4 || dateMuon.thang == 6 || dateMuon.thang == 9 || dateMuon.thang == 11)
		if(dateMuon.ngay > 30)
			return 4;
	if(dateMuon.thang == 2)
		if(dateMuon.nam % 4 == 0 && dateMuon.nam % 100 != 0)
		{
			if(dateMuon.ngay > 29)
			return 5;
		}
		else
		{
			if(dateMuon.ngay > 28)
			return 6;
		}
	return 0;
}

void themVaoCuoiMuonTra(DanhSachMuonTra *dS, MuonTra *p){
	if(dS->pHead == NULL)
	{
		dS->pHead = dS->pTail = p;
	}
	else
	{
		dS->pTail->pNext = p;
		p->prev = dS->pTail;
		dS->pTail = p;
	}
}

void themVaoCuoiDanhSachMuonTra(DanhSachMuonTra &dS, MuonTra *p){
	if(dS.pHead == NULL)
	{
		dS.pHead = dS.pTail = p;
	}
	else
	{
		dS.pTail->pNext = p;
		p->prev = dS.pTail;
		dS.pTail = p;
	}
}

MuonTra *findMuonTra(DanhSachMuonTra dS, int maSach){
	MuonTra *p = dS.pHead;
	while(p != NULL)
	{
		if(p->maSach == maSach)
			return p;
		p = p->pNext;
	}
	return NULL;
}


int soNgayTrongNam(Ngay ngay){
	int soNgayDaQua = 0;
	if(ngay.nam % 4 == 0 && ngay.nam % 100 != 0)
	{
		if(ngay.thang == 1)
			soNgayDaQua = ngay.ngay;
		else if(ngay.thang == 2)
			soNgayDaQua = 31 + ngay.ngay;
		else if(ngay.thang == 3)
			soNgayDaQua = 31 + 29 + ngay.ngay;
		else if(ngay.thang == 4)
			soNgayDaQua = 31*2 + 29 + ngay.ngay;
		else if(ngay.thang == 5)
			soNgayDaQua = 31*2 + 29 + 30 + ngay.ngay;
		else if(ngay.thang == 6)
			soNgayDaQua = 31*3 + 29 + 30 + ngay.ngay;
		else if(ngay.thang == 7)
			soNgayDaQua = 31*3 + 29 + 30*2 + ngay.ngay;
		else if(ngay.thang == 8)
			soNgayDaQua = 31*4 + 29 + 30*2 + ngay.ngay;
		else if(ngay.thang == 9)
			soNgayDaQua = 31*5 + 29 + 30*2 + ngay.ngay;
		else if(ngay.thang == 10)
			soNgayDaQua = 31*5 + 29 + 30*3 + ngay.ngay;
		else if(ngay.thang == 11)			
			soNgayDaQua = 31*6 + 29 + 30*3 + ngay.ngay;
		else
			soNgayDaQua = 366 - 31 + ngay.ngay;
		}
	else
	{
		if(ngay.thang == 1)
			soNgayDaQua = ngay.ngay;
		else if(ngay.thang == 2)
			soNgayDaQua = 31 + ngay.ngay;
		else if(ngay.thang == 3)
			soNgayDaQua = 31 + 28 + ngay.ngay;
		else if(ngay.thang == 4)
			soNgayDaQua = 31*2 + 28 + ngay.ngay;
		else if(ngay.thang == 5)
			soNgayDaQua = 31*2 + 28 + 30 + ngay.ngay;
		else if(ngay.thang == 6)
			soNgayDaQua = 31*3 + 28 + 30 + ngay.ngay;
		else if(ngay.thang == 7)
			soNgayDaQua = 31*3 + 28 + 30*2 + ngay.ngay;
		else if(ngay.thang == 8)
			soNgayDaQua = 31*4 + 28 + 30*2 + ngay.ngay;
		else if(ngay.thang == 9)
			soNgayDaQua = 31*5 + 28 + 30*2 + ngay.ngay;
		else if(ngay.thang == 10)
			soNgayDaQua = 31*5 + 28 + 30*3 + ngay.ngay;
		else if(ngay.thang == 11)
			soNgayDaQua = 31*6 + 28 + 30*3 + ngay.ngay;
		else
			soNgayDaQua = 365 - 31 + ngay.ngay;
	}
	return soNgayDaQua;
}

int soNgayQuaHan(Ngay ngay)
{
	Ngay ngayHienTai;
	std::time_t now = std::time(0);
    std::tm* currentTime = std::localtime(&now);
    ngayHienTai.ngay = currentTime->tm_mday;
    ngayHienTai.thang = currentTime->tm_mon+1;
    ngayHienTai.nam = currentTime->tm_year + 1900;
    int result = 0;
    if(ngay.nam <= ngayHienTai.nam)
    {
    	if(ngay.nam == ngayHienTai.nam)
    	{
    		if(soNgayTrongNam(ngay) >= soNgayTrongNam(ngayHienTai))
    			return 0;
    		else
    			return soNgayTrongNam(ngayHienTai) - soNgayTrongNam(ngay);
		}
		else
		{
			if(ngay.nam % 4 == 0 && ngay.nam % 100 != 0)
				result = 366 - soNgayTrongNam(ngay);
			else
				result = 365 - soNgayTrongNam(ngay);
			for(int i = ngay.nam + 1; i < ngayHienTai.nam; i++)
			{
				if(i % 4 ==0 && i % 100 != 0)
					result += 366;
				else
					result += 365;
			}
			return result + soNgayTrongNam(ngayHienTai);
		}
	}
	else
		return result;
}

bool kiemTraMuonBayNgay(DanhSachMuonTra *dS){
	MuonTra *p = dS->pHead;
	while(p != NULL)
	{
		if(p->trangThai == 0)
		{
			Ngay ngayTra;
			ngayTra.ngay = 0;
			ngayTra.thang = 0;
			ngayTra.nam = 0;
			chuanHoaNgay(ngayTra, p->NgayTra);
			//std::cout << ngayTra.nam << " ";
			if(soNgayQuaHan(ngayTra) > 7)
				return false;
		}
		p = p->pNext;
	}
	return true;
}

// ==================== THEM 1 Doc Gia ==========================
int TaoMaThe(Tree t, int arr1[], int arr2[], int &nt, int &np)
{	
	int Maxid = 1000;
	int x;
	if (t == NULL)
	{
		x = Maxid/2;
		return x;
	}
	else
	{
		// khi = false thi tiep tuc random 1 so cho toi khi khac tat ca id trong dsch
		
		if (HeightTree(t->pLeft) < HeightTree(t->pRight))
		{
			x = arr1[498 - nt];
			nt++;			
		}
		else 
		{
			x = arr2[498 - np];
			np++;
		}
		return x;
	}
}

// Thêm

void AddNodeOnTree(Tree &t, DocGia *a){
	if(t == NULL)
		t = a;
	else
		if(a->MaThe < t->MaThe)
			AddNodeOnTree(t->pLeft, a);
		else
			AddNodeOnTree(t->pRight, a);
}

void NodeThayThe(Tree &t, Tree &x)
{
	if(t->pLeft != NULL)	
		NodeThayThe(t->pLeft, x);
	else
	{
		x->MaThe = t->MaThe;
		memcpy(x->ho, t->ho, sizeof(t->ho));
		memcpy(x->ten, t->ten, sizeof(t->ten));
		memcpy(x->phai, t->phai, sizeof(t->phai));
		x->dSMuonTra = t->dSMuonTra;
		x->trangThaiThe = t->trangThaiThe;
		x = t;
		t = t->pRight;
	}
}

void XoaNodeDocGia(Tree &t, int maDocGia){
	if(t == NULL)
		return;
	else
	{
		if(t->MaThe > maDocGia)
			XoaNodeDocGia(t->pLeft, maDocGia);
		else if(t->MaThe < maDocGia)
			XoaNodeDocGia(t->pRight, maDocGia);
		else{
			Tree x = t;
			if(t->pLeft == NULL)
			{
				t = t->pRight;
			}
			else if(t->pRight == NULL)
			{
				t = t->pLeft;
			}
			else
			{
				NodeThayThe(t->pRight,x);
			}
			delete x;
		}
	}
}

DocGia *findDocGia(Tree t, int maThe){
	if(t == NULL)	
		return NULL;
	else
	{
		if(maThe < t->MaThe)	
			findDocGia(t->pLeft, maThe);
		else if(maThe > t->MaThe) 
			findDocGia(t->pRight, maThe);
		else return t;
	}
}

void ThemDSDocGia(DocGia *dS[], DocGia *newDocGia, int &n)
{
	if(n == 0)
	{
		dS[0] = newDocGia;
		n++;
		return;
	}
	if(strcmp(dS[n - 1]->ten, newDocGia->ten) <= 0)
	{
		if(strcmp(dS[n - 1]->ten, newDocGia->ten) == 0)
		{
			if(strcmp(dS[n - 1]->ho, newDocGia->ho) <= 0)
			{
				dS[n] = newDocGia;
				n++;
				return;
			}
		}
		dS[n] = newDocGia;
		n++;
		return;
	}
	int index = 0;
	for(int i = 0; i < n; i++)
	{
		if(strcmp(dS[i]->ten, newDocGia->ten) >= 0)
		{
			if(strcmp(dS[i]->ten, newDocGia->ten) == 0)
			{
				if(strcmp(dS[i]->ho, newDocGia->ho) >= 0)
				{
					index = i;
					for(int j = n; j > index; j--)
					{
						dS[j] = dS[j - 1];
					}
					dS[index] = newDocGia;
					n++;
					return;
				}
				else
				{
					index = i + 1;
					for(int j = n; j > index; j--)
					{
						dS[j] = dS[j - 1];
					}
					dS[index] = newDocGia;
					n++;
					return;
				}
			}
			index = i;
			for(int j = n; j > index; j--)
			{
				dS[j] = dS[j - 1];
			}
			dS[index] = newDocGia;
			n++;
			return;
		}
	}
}

// Duyet cay LNR
void ChuyenDoiDuLieuDocGia(Tree t, DocGia *ds[], int &n)
{
	if(t == NULL)
		return;
	else
	{
		ChuyenDoiDuLieuDocGia(t->pLeft, ds, n);
		ThemDSDocGia(ds, t, n);
		ChuyenDoiDuLieuDocGia(t->pRight, ds, n);
	}
	
}

// Tao danh sach doc gia cau I 

void ThemDSDocGiaCauI(DocGia dS[], DocGia newDocGia, int &n, int dSQuaHan[])
{
	Ngay ngayThem;
	chuanHoaNgay(ngayThem, newDocGia.dSMuonTra->pHead->NgayTra);
	int songayQuaHanThem = soNgayQuaHan(ngayThem);
	if(n == 0)
	{
		dS[0] = newDocGia;
		dSQuaHan[0] = songayQuaHanThem;
		n++;
		return;
	}
	Ngay ngayTrongDS;
	chuanHoaNgay(ngayTrongDS, dS[n-1].dSMuonTra->pHead->NgayTra);
	if(soNgayQuaHan(ngayTrongDS) > songayQuaHanThem)
	{
		dS[n] = newDocGia;
		dSQuaHan[n] = songayQuaHanThem;
		n++;
		return;
	}
	int index = 0;
	for(int i = 0; i < n; i++)
	{
		chuanHoaNgay(ngayTrongDS, dS[i].dSMuonTra->pHead->NgayTra);
		if(soNgayQuaHan(ngayTrongDS) < soNgayQuaHan(ngayThem))
		{
			index = i;
			for(int j = n; j > index; j--)
			{
				dS[j] = dS[j - 1];
				dSQuaHan[j] = dSQuaHan[j-1];
			}
			dS[index] = newDocGia;
			dSQuaHan[index] = songayQuaHanThem;
			n++;
			return;
		}
	}
}

void ChuyenDoiDuLieuDocGiaCauI(Tree t, DocGia dS[], int &n, int dSQuaHan[])
{
	if(t == NULL)
		return;
	else
	{
		ChuyenDoiDuLieuDocGiaCauI(t->pLeft, dS, n, dSQuaHan);
		for(int i =0; i < t->dSMuonTra->SLDS; i++)
		{
			DocGia docGia; 
			docGia.MaThe = t->MaThe;
			memcpy(docGia.ho, t->ho, sizeof(t->ho));
			memcpy(docGia.ten, t->ten, sizeof(t->ten));
			memcpy(docGia.phai, t->phai, sizeof(t->phai));
			MuonTra *p = t->dSMuonTra->pHead;
			for(int j = 0; j < i; j++)
				p = p->pNext;
			Ngay ngayTra;
			chuanHoaNgay(ngayTra, p->NgayTra);
			if(p->trangThai == 0 && soNgayQuaHan(ngayTra) > 0)
			{
				MuonTra *q = new MuonTra;
				q->maSach = p->maSach;
				memcpy(q->NgayMuon, p->NgayMuon, sizeof(p->NgayMuon));
				memcpy(q->NgayTra, p->NgayTra, sizeof(p->NgayMuon));
				q->trangThai = p->trangThai;
				q->pNext = NULL;
				q->prev = NULL;
				docGia.dSMuonTra = new DanhSachMuonTra;
				themVaoCuoiMuonTra(docGia.dSMuonTra, q);
				docGia.trangThaiThe = t->trangThaiThe;
				ThemDSDocGiaCauI(dS, docGia, n, dSQuaHan);
			}
		}
		ChuyenDoiDuLieuDocGiaCauI(t->pRight, dS, n, dSQuaHan);
	}
}

// sap xep


void swapDocGia(DocGia *&p, DocGia *&q){
	DocGia *tmp = q;
	q = p;
	p = tmp;
}

// Xap xep theo the loai
int partitionDocGiaTen(DocGia *dS[], int l, int r){
	DocGia *pivot = dS[r];
	int i = l - 1;
	for(int j = l; j < r; j++)
	{
		if(strcmp(dS[j]->ten, pivot->ten) <= 0)
		{
			if(strcmp(dS[j]->ten, pivot->ten) == 0)
			{
				if(strcmp(dS[j]->ho, pivot->ho) <= 0)
				{
					++i;
					swapDocGia(dS[i], dS[j]);
				}
			}
			else
			{
				++i;
				swapDocGia(dS[i], dS[j]);
			}
		}
	}
	// Dua chot ve giua
	++i;
	swapDocGia(dS[i], dS[r]);
	return i; 
} 

int partitionDocGiaID(DocGia *dS[], int l, int r){
	DocGia *pivot = dS[r];
	int i = l - 1;
	for(int j = l; j < r; j++)
	{
		if(dS[j]->MaThe <= pivot->MaThe)
		{
			++i;
			swapDocGia(dS[i], dS[j]);
		}
	}
	// Dua chot ve giua
	++i;
	swapDocGia(dS[i], dS[r]);
	return i; 
} 


// sap xep 
void quickSortDocGiaTenHienThi(DocGia *dS[], int l, int r){
	if(l >= r) return;
	int p = partitionDocGiaTen(dS, l, r);
	quickSortDocGiaTenHienThi(dS, l, p-1);
	quickSortDocGiaTenHienThi(dS, p+1, r);
}

void quickSortDocGiaIDHienThi(DocGia *dS[], int l, int r){
	if(l >= r) return;
	int p = partitionDocGiaID(dS, l, r);
	quickSortDocGiaIDHienThi(dS, l, p-1);
	quickSortDocGiaIDHienThi(dS, p+1, r);
}


// ===================================================================================================================//
// Danh Sach Dau sach

// Them sach
void themSach(DanhSachDauSach &dS, DauSach *dauSach){
	if(dS.SLDauSach == 0)
	{
		dS.danhSachDauSach[dS.SLDauSach] = dauSach;
		dS.SLDauSach++;
	}
	else
	{
		if(strcmp(dS.danhSachDauSach[dS.SLDauSach - 1]->TenSach, dauSach->TenSach) <= 0)
		{
			dS.danhSachDauSach[dS.SLDauSach] = dauSach;
			dS.SLDauSach++;
		}
		else
		{
			int index = 0;
			for(int i = 0; i < dS.SLDauSach; i++)
			{
				if(strcmp(dS.danhSachDauSach[i]->TenSach, dauSach->TenSach) >= 0)
				{
					index = i;
					break;
				}
			}
			for(int i = dS.SLDauSach; i > index; i--)
			{
				dS.danhSachDauSach[i] = dS.danhSachDauSach[i-1];
			}
			dS.danhSachDauSach[index] = dauSach;
			dS.SLDauSach++;
		}
	}	
}

// Tim kiem dau sach
DauSach *findDauSach(DanhSachDauSach dS, char ISBN[10]){
	for(int i = 0; i < dS.SLDauSach; i++)
		if(strcmp(dS.danhSachDauSach[i]->ISBN, ISBN) == 0)
			return dS.danhSachDauSach[i];
	return NULL;
}

int timKiemNhiPhan(int l, int r, DanhSachDauSach dS, char ten[100]){
	if(r >= l)
    {
        int mid = l + (r - l)/2;
        if(strcmp(dS.danhSachDauSach[mid]->TenSach, ten) == 0)
        	return mid;
        if(strcmp(dS.danhSachDauSach[mid]->TenSach, ten) > 0)
        	return timKiemNhiPhan(l, mid - 1, dS,ten);
        return timKiemNhiPhan(mid + 1, r, dS, ten);
    }
    return -1;
}

int tongSoSachCoTheChoMuon(DanhSachDauSach dS)
{
	int count = 0;
	for(int i = 0; i < dS.SLDauSach; i++)
	{
		MucSach *p = dS.danhSachDauSach[i]->dMS->pHead;
		while(p != NULL)
		{
			if(p->TrangThai == 0)
				count++;
			p = p->pNext;
		}
	}
	return count;
}

// 0 la cho phep xoa 1 la da ton tai
// LNR
int kiemTraXoaDauSach(DanhMucSach *dMS, DanhSachMuonTra dSMT)
{
	MuonTra *p = dSMT.pHead;
	MucSach *q = dMS->pHead;
	while(q != NULL)
	{
		while(p != NULL)
		{
			if(p->maSach == q->maSach)
				return 1;
			p = p->pNext;
		}
		q = q->pNext;
	}
	return 0;
}
// Xoa dau sach 
void xoaDauSach(DanhSachDauSach &dS, char ISBN[10], DanhMucSach &dMS)
{
	int index = 0;
	for(int i = 0; i < dS.SLDauSach; i++)
	{
		if(strcmp(dS.danhSachDauSach[i]->ISBN, ISBN) == 0)
		{
			index = i;
			DauSach *dauSachTmp = dS.danhSachDauSach[index];
			for(int j = index; j < dS.SLDauSach; j++)
				dS.danhSachDauSach[j] = dS.danhSachDauSach[j + 1];
			dS.danhSachDauSach[dS.SLDauSach - 1] = NULL;
			xoaMucSachTheoDauSach(dauSachTmp->dMS, dMS);
			delete dauSachTmp;
			dS.SLDauSach--;
			return;
		}
	}			
}

void swapDauSach(DauSach *&p, DauSach *&q){
	DauSach *tmp = q;
	q = p;
	p = tmp;
}

// Xap xep theo the loai
int partition(DauSach *dS[], int l, int r){
	DauSach *pivot = dS[r];
	int i = l - 1;
	for(int j = l; j < r; j++)
	{
		if(strcmp(dS[j]->TheLoai, pivot->TheLoai) <= 0)
		{
			if(strcmp(dS[j]->TheLoai, pivot->TheLoai) == 0)
			{
				if(strcmp(dS[j]->TenSach, pivot->TenSach) <= 0)
				{
					++i;
					swapDauSach(dS[i], dS[j]);
				}
			}
			else
			{
				++i;
				swapDauSach(dS[i], dS[j]);
			}
		}
	}
	// Dua chot ve giua
	++i;
	swapDauSach(dS[i], dS[r]);
	return i; 
} 

// Sap xep theo ten sach
int partitionTenSach(DauSach *dS[], int l, int r){
	DauSach *pivot = dS[r];
	int i = l - 1;
	for(int j = l; j < r; j++)
	{
		if(strcmp(dS[j]->TenSach, pivot->TenSach) <= 0)
		{
			++i;
			swapDauSach(dS[i], dS[j]);
		}
	}
	// Dua chot ve giua
	++i;
	swapDauSach(dS[i], dS[r]);
	return i; 
} 

int soLuongMuon(DanhMucSach *dS, DanhSachMuonTra dSMT)
{
	cout << endl << "tong so muon tra " << dSMT.SLDS  << endl;
	int count = 0;
	MucSach *p = dS->pHead;
	while(p != NULL)
	{
		MuonTra *q = dSMT.pHead;
		while(q != NULL)
		{
			cout << q->maSach << " ";
			if(q->maSach == p->maSach)
				count++;
			q = q->pNext;
		}
		cout << endl;
		p = p->pNext;
	}
	return count;
}

// Xap xep theo sl muon tra
int partitionSoLuongMuonDauSach(DauSach *dS[], int l, int r, DanhSachMuonTra dSMT){
	DauSach *pivot = dS[r];
	int i = l - 1;
	for(int j = l; j < r; j++)
	{
		cout << soLuongMuon(dS[j]->dMS, dSMT);
		if(soLuongMuon(dS[j]->dMS, dSMT) > soLuongMuon(pivot->dMS, dSMT))
		{
			++i;
			swapDauSach(dS[i], dS[j]);
		}
	}
	// Dua chot ve giua
	++i;
	swapDauSach(dS[i], dS[r]);
	return i; 
} 

// sap xep 
void quickSortDauSachHienThi(DauSach *dS[], int l, int r){
	if(l >= r) return;
	int p = partition(dS, l, r);
	quickSortDauSachHienThi(dS, l, p-1);
	quickSortDauSachHienThi(dS, p+1, r);
}

// sap xep TenSach
void quickSortTenSach(DauSach *dS[], int l, int r){
	if(l >= r) return;
	int p = partitionTenSach(dS, l, r);
	quickSortTenSach(dS, l, p-1);
	quickSortTenSach(dS, p+1, r);
}

// sap xep Theo luot muon
void quickSortMuonTraDauSach(DauSach *dS[], int l, int r, DanhSachMuonTra dSMT){
	if(l >= r) return;
	int p = partitionSoLuongMuonDauSach(dS, l, r, dSMT);
	quickSortMuonTraDauSach(dS, l, p-1, dSMT);
	quickSortMuonTraDauSach(dS, p+1, r, dSMT);
}

// Muc Sach
void themVaoCuoi(DanhMucSach *dMS, MucSach *newMucSach)
{
	if(dMS->pHead == NULL)
	{
		//std::cout << "Vao";
		dMS->pHead = newMucSach;
		dMS->pLast = newMucSach;
	}
	else
	{
		dMS->pLast->pNext = newMucSach;
		dMS->pLast = newMucSach;
	}
	dMS->SLDms++;
}

void themVaoCuoiDMS(DanhMucSach &dMS, MucSach *newMucSach)
{
	if(dMS.pHead == NULL)
	{
		dMS.pHead = newMucSach;
		dMS.pLast = newMucSach;
	}
	else
	{
		dMS.pLast->pNext = newMucSach;
		dMS.pLast = newMucSach;
	}
	dMS.SLDms++;
}


//================================================= Muon Tra ==========================//
void capNhatMuon(DanhMucSach &dMS, DanhSachDauSach &dSDS, DanhSachMuonTra &dSMT, DanhSachMuonTra *dS, MuonTra *p, MuonTra *q)
{
	themVaoCuoiMuonTra(dS, p);
	dS->SLDS++;
	themVaoCuoiDanhSachMuonTra(dSMT, q);
	dSMT.SLDS++;
	int kiemTra = false;
	for(int i = 0; i < dSDS.SLDauSach; i++)
	{
		MucSach *h = dSDS.danhSachDauSach[i]->dMS->pHead;
		while(h != NULL)
		{
			if(h->maSach == p->maSach)
			{
				h->TrangThai = 1;
				kiemTra = true;
				break;
			}
			h = h->pNext;
		}
		if(kiemTra == true)
			break;
	}
	MucSach *h = dMS.pHead;
	while(h != NULL)
	{
		if(h->maSach == p->maSach)
		{
			h->TrangThai = 1;
			//kiemTra = true;
			break;
		}
		h = h->pNext;
	}
}

void capNhatTra(DanhMucSach &dMS, DanhSachDauSach &dSDS, DanhSachMuonTra &dSMT, DanhSachMuonTra *dS, int maSach, char ngayMuon[10], int capNhat)
{
	// 0 la tra 1 la den
	int kiemTra = false;
	for(int i = 0; i < dSDS.SLDauSach; i++)
	{
		MucSach *h = dSDS.danhSachDauSach[i]->dMS->pHead;
		while(h != NULL)
		{
			if(h->maSach == maSach)
			{
				if(capNhat == 0)
					h->TrangThai = 0;
				else
					h->TrangThai = 2;
				kiemTra = true;
				break;
			}
			h = h->pNext;
		}
		if(kiemTra == true)
			break;
	}
	MucSach *h = dMS.pHead;
	while(h != NULL)
	{
		if(h->maSach == maSach)
		{
			if(capNhat ==0)
				h->TrangThai = 0;
			else
				h->TrangThai = 2;
			//kiemTra = true;
			break;
		}
		h = h->pNext;
	}
	MuonTra *p = dS->pHead;
	while(p != NULL)
	{
		if(p->maSach == maSach && strcmp(p->NgayMuon, ngayMuon) == 0)
		{
			if(capNhat ==0)
				p->trangThai = 1;
			else
				p->trangThai = 2;
			break;
		}
		p = p->pNext;
	}
	MuonTra *q = dSMT.pHead;
	while(q != NULL)
	{
		if(q->maSach == maSach && strcmp(q->NgayMuon, ngayMuon) == 0)
		{
			if(capNhat ==0)
				q->trangThai = 1;
			else
				q->trangThai = 2;
			break;
		}
		q = q->pNext;
	}
}

bool kiemTraMuonTraCoTonTai(int maSach, char ngay[11], DanhSachMuonTra *dS)
{
	if(dS->SLDS == 0)
		return false;
	else
	{
		MuonTra *p = dS->pHead;
		while(p != NULL)
		{
			if(p->maSach == maSach && strcmp(ngay, p->NgayMuon) == 0){
				return true;
			}
			p = p->pNext;
		}
		return false;
	}
}

/// Câu h ///
int demSoMuonTraDangMuon(DanhSachMuonTra *dSMT)
{
	MuonTra *p = dSMT->pHead;
	int count = 0;
	while(p != NULL)
	{
		if(p->trangThai == 0)
		{
			count++;
		}
		p = p->pNext;
	}
	return count;
}

DauSach *findDauSachTheoMaSach(DanhSachDauSach dS, int maSach)
{
	for(int i = 0; i < dS.SLDauSach; i++)
	{
		MucSach *p = dS.danhSachDauSach[i]->dMS->pHead;
		while(p != NULL)
		{
			if(p->maSach == maSach)
				return dS.danhSachDauSach[i];
			p = p->pNext;
		}
	}
	return NULL;
}

bool kiemTraISBN(DanhSachDauSach dS, char ISBN[10])
{
	for(int i = 0; i < dS.SLDauSach; i++)
	{
		if(strcmp(dS.danhSachDauSach[i]->ISBN, ISBN) == 0)
		{
			return true;
		}
	}
	return false;
}

void docFileDauSach(DanhSachDauSach &dSDS, DanhMucSach &dMS, int &idDMSMax)
{
	ifstream f;
	f.open("DauSach.txt", ios::in);
	
	if(f.fail())
	{
		cout << "Mo FILE THAT BAI";
	}
	else
	{
		f >> idDMSMax;
		f.ignore();
		f >> dSDS.SLDauSach;
		f.ignore();
		
		string line = "";
		for(int i = 0; i< dSDS.SLDauSach; i++)
		{
			
			DauSach *dauSach = new DauSach;
			getline(f, line);
			strcpy(dauSach->ISBN, line.c_str());
			getline(f, line);
			strcpy(dauSach->TenSach, line.c_str());
			getline(f, line);
			strcpy(dauSach->TacGia, line.c_str());
			getline(f, line);
			strcpy(dauSach->TheLoai, line.c_str());
			f >> dauSach->SoTrang;
			f.ignore();
			f >> dauSach->NamXB;
			f.ignore();
			dauSach->dMS = new DanhMucSach;
			int lap = 0;
			f >> lap;
			f.ignore();
			//cout << dauSach->dMS->SLDms;
			for(int j = 0; j < lap; j++)
			{
				int tmp = 0;
				MucSach *p = new MucSach;
				MucSach *q = new MucSach;
				p->pNext = NULL;
				q->pNext = NULL;
				f >> tmp;
				f.ignore();
				q->maSach = tmp;
				p->maSach = tmp;
				getline(f, line);
				strcpy(p->ViTri, line.c_str());
				strcpy(q->ViTri, p->ViTri);
				f >> tmp;
				f.ignore();
				q->TrangThai = tmp;
				p->TrangThai = tmp;
				themVaoCuoi(dauSach->dMS, p);
				themVaoCuoiDMS(dMS, q);
			}
		//	dauSach->dMS->SLDms = lap;
			dSDS.danhSachDauSach[i] = dauSach;
		}
	}
	f.close();
	int set = 0;
	for(int i = 0; i < dSDS.SLDauSach; i++)
		set += dSDS.danhSachDauSach[i]->dMS->SLDms;
	dMS.SLDms = set;
	quickSortTenSach(dSDS.danhSachDauSach, 0, dSDS.SLDauSach-1);
}

void ghiFileDauSach(DanhSachDauSach dSDS, int idDMSMax)
{
	ofstream f;
	f.open("DauSach.txt", ios::out);
	f << idDMSMax << endl;
	f << dSDS.SLDauSach << endl;
	for(int i = 0; i < dSDS.SLDauSach; i++)
	{
		f << dSDS.danhSachDauSach[i]->ISBN << endl;
		f << dSDS.danhSachDauSach[i]->TenSach << endl;
		f << dSDS.danhSachDauSach[i]->TacGia << endl;
		f << dSDS.danhSachDauSach[i]->TheLoai << endl;
		f << dSDS.danhSachDauSach[i]->SoTrang << endl;
		f << dSDS.danhSachDauSach[i]->NamXB << endl;
		f << dSDS.danhSachDauSach[i]->dMS->SLDms << endl;
		MucSach *p = dSDS.danhSachDauSach[i]->dMS->pHead;
		while(p != NULL)
		{
			f << p->maSach << endl;
			f << p->ViTri << endl;
			f << p->TrangThai << endl;
			p = p->pNext;
		}
	}
}

void swapINT(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void docFileDocGia(DanhSachDocGia &dSDG, DanhSachMuonTra &dSMT, int arr1[], int arr2[])
{
	ifstream f;
	f.open("DocGia.txt", ios::in);
	
	if(f.fail())
	{
		cout << "Mo FILE THAT BAI";
	}
	f >> dSDG.SLDocGia;
	f.ignore();
	string line = "";
	int tongMuonTra = 0;
	int nt = 0;
	int np = 0;
	for(int j = 0; j < dSDG.SLDocGia; j++)
	{
		DocGia *newDocGia = new DocGia;
		f >> newDocGia->MaThe;
		f.ignore();
		getline(f, line);
		strcpy(newDocGia->ho, line.c_str());
		getline(f, line);
		strcpy(newDocGia->ten, line.c_str());
		getline(f, line);
		strcpy(newDocGia->phai, line.c_str());
		f >> newDocGia->trangThaiThe;
		f.ignore();
		int lap = 0;
		f >> lap;
		f.ignore();
		newDocGia->dSMuonTra = new DanhSachMuonTra;
		for(int i = 0; i < lap; i++)
		{
			MuonTra *p = new MuonTra;
			MuonTra *q = new MuonTra;
			p->pNext = NULL;
			p->prev = NULL;
			q->pNext = NULL;
			q->prev = NULL;
			int tmp = 0;
			
			f >> tmp;
			f.ignore();
			p->maSach = tmp;
			q->maSach = tmp;
			
			getline(f, line);
			strcpy(p->NgayMuon, line.c_str());
			strcpy(q->NgayMuon, line.c_str());
			
			getline(f, line);
			strcpy(p->NgayTra, line.c_str());
			strcpy(q->NgayTra, line.c_str());
			
			f >> tmp;
			f.ignore();
			p->trangThai = tmp;
			q->trangThai = tmp;
			themVaoCuoiMuonTra(newDocGia->dSMuonTra, p);
			newDocGia->dSMuonTra->SLDS++;
			themVaoCuoiDanhSachMuonTra(dSMT, q);
		}
		tongMuonTra += newDocGia->dSMuonTra->SLDS;
		AddNodeOnTree(dSDG.dsDocGia, newDocGia);
	}
	f.close();
	dSMT.SLDS = tongMuonTra;
}

void ghiDanhSachDocGia(DanhSachDocGia dSDG)
{
	ofstream f;
	f.open("DocGia.txt", ios::out);
	if(dSDG.SLDocGia == 0)
	{
		cout << "Danh Sach rong!!!";
		return;
	}
	f << dSDG.SLDocGia << endl;
	Tree Stack[dSDG.SLDocGia];
	int sp = -1;
	Tree p = dSDG.dsDocGia;
	while(p != NULL)
	{
		f << p->MaThe << endl;
		f << p->ho << endl;
		f << p->ten << endl;
		f << p->phai << endl;
		f << p->trangThaiThe << endl;
		f << p->dSMuonTra->SLDS << endl;
		for(int i = 0; i < p->dSMuonTra->SLDS; i++)
		{
			MuonTra *muonTra = p->dSMuonTra->pHead;
			f << muonTra->maSach << endl;
			f << muonTra->NgayMuon << endl;
			f << muonTra->NgayTra << endl;
			f << muonTra->trangThai << endl;
			muonTra = muonTra->pNext;
		}
		if(p->pRight != NULL)
		{
			sp++;
			Stack[sp] = p->pRight;
		}
		if (p->pLeft != NULL)
		{
			p = p->pLeft;
		}
		else if (sp == -1)	break;
		else
		{
			p = Stack[sp];
			sp--;
		}	
	}
	f.close();
	return;
}

void giaiPhongVungNhoDSDG(Tree &t)
{
	if(t == NULL)	return;
	else
	{
		giaiPhongVungNhoDSDG(t->pLeft);
		giaiPhongVungNhoDSDG(t->pRight);
		while(t->dSMuonTra->pHead != NULL)
		{
			MuonTra *p = t->dSMuonTra->pHead;
			t->dSMuonTra->pHead = p->pNext;
			t->dSMuonTra->pHead->prev = NULL;
			delete p;
		}
		delete t->dSMuonTra;
		delete t;
	}
}

void giaiPhongVungNho(DanhMucSach &dMS, DanhSachMuonTra &dSMT, DanhSachDauSach &dSDS)
{
	for(int i = dSDS.SLDauSach - 1; i >= 0; i--)
	{
		
		while(dSDS.danhSachDauSach[i]->dMS->pHead != NULL)
		{
			MucSach *p = dSDS.danhSachDauSach[i]->dMS->pHead;
			dSDS.danhSachDauSach[i]->dMS->pHead = p->pNext;
			delete p;
		}
		delete dSDS.danhSachDauSach[i]->dMS;
		delete dSDS.danhSachDauSach[i];
	}
	while(dMS.pHead != NULL)
	{
		MucSach *p = dMS.pHead;
		dMS.pHead = p->pNext;
		delete p;
	}
	while(dSMT.pHead != NULL)
	{
		MuonTra *p = dSMT.pHead;
		dSMT.pHead = p->pNext;
		dSMT.pHead->prev = NULL;
		delete p;
	}
}

bool checkHaiSachChungDauSach(int maSach, DanhSachMuonTra *dSMT, DanhSachDauSach dSDS)
{
	MuonTra *p = dSMT->pHead;
	while(p != NULL)
	{
		if(p->trangThai == 0)
		{
			DauSach *dauSach = findDauSachTheoMaSach(dSDS, p->maSach);
			DauSach *dauSachHai = findDauSachTheoMaSach(dSDS, maSach);
			if(dauSach == dauSachHai)
				return true;
		}
		p = p->pNext;
	}
	return false;
}

MucSach *findMucSachByID(int maSach, DanhMucSach dMS)
{
	MucSach *p = dMS.pHead;
	while(p != NULL)
	{
		if(p->maSach == maSach)
			return p;
		p = p->pNext;
	}
	return NULL;
}

bool kiemTraMucSachXoa(int maSach, DanhSachMuonTra dSMT)
{
	MuonTra *p = dSMT.pHead;
	while(p != NULL)
	{
		if(p->maSach == maSach)
			return false;
		p = p->pNext;
	}
	return true;
}

void xoaMucSach(int maSach, DanhSachDauSach &dSDS, DanhMucSach &dMS)
{
	int kt = 0;
	for(int i = 0; i < dSDS.SLDauSach; i++)
	{
		MucSach *p = dSDS.danhSachDauSach[i]->dMS->pHead;
		if(p->maSach == maSach)
		{
			dSDS.danhSachDauSach[i]->dMS->pHead = p->pNext;
			delete p;
			dSDS.danhSachDauSach[i]->dMS->SLDms--;
			break;
		}
		else 
		{
			//MucSach *p = dSDS.danhSachDauSach[i]->dMS->pHead;
			while(p->pNext != NULL)
			{
				if(p->pNext->maSach == maSach)
				{
					if(p->pNext == dSDS.danhSachDauSach[i]->dMS->pLast)
					{
						MucSach *q = p->pNext;
						p->pNext = q->pNext;
						dSDS.danhSachDauSach[i]->dMS->pLast = p;
						delete q;
						dSDS.danhSachDauSach[i]->dMS->SLDms--;
						kt = 1;
						break;
					}
					else
					{
						MucSach *q = p->pNext;
						p->pNext = q->pNext;
						delete q;
						dSDS.danhSachDauSach[i]->dMS->SLDms--;
						kt = 1;
						break;
					}
					
				}
				p = p->pNext;
			}	
		}
		if(kt == 1)
			break;
	}
	
	MucSach *h = dMS.pHead;
	if(h->maSach == maSach)
	{
		dMS.pHead = h->pNext;
		delete h;
		dMS.SLDms--;
	}
	else
		while(h->pNext != NULL)
		{
			if(h->pNext->maSach == maSach)
			{
				if(h->pNext == dMS.pLast)
				{
					MucSach *m = h->pNext;
					h->pNext = m->pNext;
					dMS.pLast = h;
					delete m;
					dMS.SLDms--;
					break;
				}
				else
				{
					MucSach *m = h->pNext;
					h->pNext = m->pNext;
					delete m;
					dMS.SLDms--;
					break;
				}
			}
			h = h->pNext;
		}		
	
}

void xoaMucSachTheoDauSach(DanhMucSach *dMSDS, DanhMucSach &dMS)
{
	MucSach *p = dMSDS->pHead;
	cout << "qua";
	while(p != NULL)
	{
		MucSach *h = dMS.pHead;
		if(h->maSach == p->maSach)
		{
			dMS.pHead = h->pNext;
			delete h;
			dMS.SLDms--;
		}
		else
			while(h->pNext != NULL)
			{
				if(h->pNext->maSach == p->maSach)
				{
					if(h->pNext == dMS.pLast)
					{
						MucSach *m = h->pNext;
						h->pNext = m->pNext;
						dMS.pLast = h;
						delete m;
						dMS.SLDms--;
						break;
					}
					else
					{
						MucSach *m = h->pNext;
						h->pNext = m->pNext;
						delete m;
						dMS.SLDms--;
						break;
					}
				}
				h = h->pNext;
			}
		p = p->pNext;
		
	}
	while(dMSDS->pHead != NULL)
	{
		MucSach *q  = dMSDS->pHead;
		dMSDS->pHead = q->pNext;
		delete q;
	}
	dMSDS->SLDms = 0;
}

void capNhatDauSachMucSach(MucSach *p, DanhSachDauSach &dSDS)
{
	for(int i = 0; i < dSDS.SLDauSach; i++)
	{
		MucSach *q = dSDS.danhSachDauSach[i]->dMS->pHead;
		while(q != NULL)
		{
			if(q->maSach == p->maSach)
			{
				memset(q->ViTri, 0, 100);
				memcpy(q->ViTri, p->ViTri, sizeof(p->ViTri));
				return;
			}
			q = q->pNext;	
		}
	}
}

void capNhatKhoaThe(Tree &t)
{
	if(t == NULL)
		return;
	else
	{
		capNhatKhoaThe(t->pLeft);
		if(!kiemTraMuonBayNgay(t->dSMuonTra))
			t->trangThaiThe = 0;
		capNhatKhoaThe(t->pRight);
	}
}

void docFileMangRD(int arr[], int file)
{
	ifstream f;
	int i = 0;
	if(file == 1)
		f.open("MangRDMot.txt", ios::in);
	else
		f.open("MangRDHai.txt", ios::in);
	if(f.fail())
	{
		cout << "Mo FILE THAT BAI";
	}
	while(!f.eof())
	{
		f >> arr[i];
		f.ignore();
		i++;
	}
	f.close();
}

void ghiFileRD(int arr[], int file)
{
	ofstream f;
	if(file == 1)
		f.open("MangRDMot.txt", ios::out);
	else
		f.open("MangRDHai.txt", ios::out);
	for(int i = 0; i < 499; i++)
	{
		f << arr[i] << endl;
	}
	f.close();
}
