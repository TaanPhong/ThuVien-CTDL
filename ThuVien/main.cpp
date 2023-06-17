#include<winbgim.h>
#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
#include<string.h>
#include<stdio.h>
#include <unistd.h>
#include "DoHoa.h"

using namespace std;
int mapID[width][hight];
//const int hight = 770;


int main(int argc, char *argv[]){
	initwindow(width, hight);
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	SetmapID(mapID);
	SetIDMenu(mapID);
	DanhSachDocGia dSDG;
	DanhSachDauSach dSDS;
	DanhSachMuonTra dSMT;
	DanhMucSach dMS;
	int x = 0;
	int idDMSMax = 0;
	int arr1[499];
	int arr2[499];
	int nt = 0;
	int np = 0;
	docFileDauSach(dSDS, dMS, idDMSMax);
	docFileDocGia(dSDG, dSMT, arr1, arr2);
	capNhatKhoaThe(dSDG.dsDocGia);
	bool ghiFile = false;
	if(dSDG.SLDocGia != 0)
	{
		ghiFile = false;
		docFileMangRD(arr1, 1);
		docFileMangRD(arr2, 2);
	}
	else
	{
		ghiFile = true;
		TaoMangRd(arr1,1,499);
		TaoMangRd(arr2,501,999);
		RandomMang(arr1);
		RandomMang(arr2);
	}
	if(dSDG.SLDocGia != 0)
	{
		nt = CountNode(dSDG.dsDocGia->pLeft);
		np = CountNode(dSDG.dsDocGia->pRight);
	}
	Menu(mapID, dSDG, dSDS, dSMT, dMS, idDMSMax, arr1, arr2, nt, np);
	ghiFileDauSach(dSDS, idDMSMax);
	ghiDanhSachDocGia(dSDG);
	if(ghiFile == true)
	{
		ghiFileRD(arr1, 1);
		ghiFileRD(arr2, 2);
	}
	giaiPhongVungNho(dMS, dSMT, dSDS);
	giaiPhongVungNhoDSDG(dSDG.dsDocGia);
	return 0;	
}
