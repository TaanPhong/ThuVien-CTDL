#pragma one
#include<winbgim.h>
#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
#include<string.h>
#include <cstring>
#include<stdio.h>
#include <unistd.h>
#include "XuLyCauTruc.h"
const int width = 1500;
const int hight = 770;

using namespace std;

void VeBang(int cot);
void VeThemXoaSua(int mapID[][hight]);
void DrawMenu();
void inDanhSachDocGia(int mapID[][hight], DanhSachDocGia ds);
void HienThiDanhSachDocGia(int pageCurent, int totalPage, char hienThiTrang[], DocGia *DSDG[], int sl, int y1, int h, int hienThi);
void xoaHienThiDanhSachDocGia(int pageCurent, int totalPage, char hienThiTrang[], DocGia *DSDG[], int sl, int y1, int h, int hienThi);
void xoaDanhSachDauSach(int pageCurent, int totalPage, char hienThiTrang[], DanhSachDauSach dS, int sl, int y1, int h, int hienThi);
void HienThiDanhSachDauSach(int pageCurent, int totalPage, char hienThiTrang[], DanhSachDauSach dS, int sl, int y1, int h, int hienThi);

void SetmapID(int mapID[][hight])
{
	for(int i = 0; i < hight; i++)
		for(int j = 0; j < width; j++)
			mapID[i][j] = 0;
}

void SetID(int x1, int y1, int x2, int y2, int id, int mapID[][hight])
{
	for(int i = x1 + 1; i <= x2 - 1; i++)
		for(int j = y1 + 1; j <= y2 - 1; j++)
			mapID[i][j] = id;
}

void SetIDMenu(int mapID[][hight])
{
	int h = 0;
	int id = 1;
	for(int i = 0; i < 10; i++){
		SetID(30, 130 + h, 230, h + 160, id, mapID);
		h += 60;
		id++;
	}
	SetID(30, 20, 230, 80, 99, mapID);
}

// Dung chung

void DrawMenu(){
	line(0, 100, 1500, 100);
	settextstyle(3,0,4);
	outtextxy(1500/2 - textwidth("Quan Ly Thu Vien")/2, 20, "Quan Ly Thu Vien");
	line(300, 100, 300, 770);
	int h = 0;
	settextstyle(8,0,1);
	setfillstyle(1, 3);
	setusercharsize(1,2,1,2);
	for(int i = 0; i < 10; i++){
		//setcolor(7);
		bar(30, 130 + h, 230, h + 160);
		//setcolor(0);
		h += 60;
	}
	setfillstyle(1, 3);
	bar(30, 20, 230, 80);
	setbkcolor(3);
	setcolor(0);
	outtextxy(130 - textwidth("Thoat")/2, 40, "Thoat");
	setbkcolor(3);
	setcolor(0);
	h = 0;
	outtextxy(130 - textwidth("The doc gia")/2, 135 + h, "The doc gia");
	h += 60;
	outtextxy(130 - textwidth("In danh sach doc gia")/2, 135 + h, "In danh sach doc gia");
	h += 60;
	outtextxy(130 - textwidth("Quan ly dau sach")/2, 135 + h, "Quan ly dau sach");
	h += 60;
	outtextxy(130 - textwidth("In danh sach dau sach")/2, 135 + h, "In danh sach dau sach");
	h += 60;
	outtextxy(130 - textwidth("Tim thong tin sach")/2, 135 + h, "Tim thong tin sach");
	h += 60;
	outtextxy(130 - textwidth("Quan ly muon sach")/2, 135 + h, "Quan ly muon sach");
	h += 60;
	outtextxy(130 - textwidth("Quan ly tra sach")/2, 135 + h, "Quan ly tra sach");
	h += 60;
	outtextxy(130 - textwidth("Thong ke sach")/2, 135 + h, "Thong ke sach");
	h += 60;
	outtextxy(130 - textwidth("In danh sach doc gia")/2, 135 + h, "In danh sach doc gia");
	h += 60;
	outtextxy(130 - textwidth("Top 10 dau sach")/2, 135 + h, "Top 10 dau sach");
	h += 60;
	setbkcolor(15);
	setcolor(0);
}

void ThayDoiThemXoaSua(int id){
	if(id == 11)
	{
		setfillstyle(1, 4);
		int w = 0;
		bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
		setbkcolor(4);
		setcolor(0);
		outtextxy(400 + w + 25, 220, "Them");
		
		setfillstyle(1, 3);
		setbkcolor(3);
		w += (textwidth("Them") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua");
		
		w += (textwidth("Sua") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa");
		
		w += (textwidth("Xoa") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Thoat");
	}
	else if(id == 12)
	{
		setfillstyle(1, 3);
		int w = 0;
		bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
		setbkcolor(3);
		setcolor(0);
		outtextxy(400 + w + 25, 220, "Them");
		
		setfillstyle(1, 4);
		setbkcolor(4);
		w += (textwidth("Them") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua");
		
		setfillstyle(1, 3);
		setbkcolor(3);
		w += (textwidth("Sua") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa");
		
		w += (textwidth("Xoa") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Thoat");
	}
	else if(id == 13)
	{
		setfillstyle(1, 3);
		int w = 0;
		bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
		setbkcolor(3);
		setcolor(0);
		outtextxy(400 + w + 25, 220, "Them");
		
		
		w += (textwidth("Them") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua");
		
		setfillstyle(1, 4);
		setbkcolor(4);
		
		w += (textwidth("Sua") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa");
		
		setfillstyle(1, 3);
		setbkcolor(3);
		w += (textwidth("Xoa") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Thoat");
	}
	else if(id == 14)
	{
		setfillstyle(1, 3);
		int w = 0;
		bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
		setbkcolor(3);
		setcolor(0);
		outtextxy(400 + w + 25, 220, "Them");
		
		
		w += (textwidth("Them") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua");
		
		
		
		w += (textwidth("Sua") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa");
		
		setfillstyle(1, 4);
		setbkcolor(4);
		w += (textwidth("Xoa") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Thoat");
		
	}
	else
	{
		setfillstyle(1, 3);
		int w = 0;
		bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
		setbkcolor(3);
		setcolor(0);
		outtextxy(400 + w + 25, 220, "Them");
		
		
		w += (textwidth("Them") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua");
		
		
		
		w += (textwidth("Sua") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa");
		
		w += (textwidth("Xoa") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Thoat");
	}
}

void ThayDoiThemXoaSuaDauSach(int id){
	if(id == 11)
	{
		setfillstyle(1, 4);
		int w = 0;
		bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
		setbkcolor(4);
		setcolor(0);
		outtextxy(400 + w + 25, 220, "Them");
		
		setfillstyle(1, 3);
		setbkcolor(3);
		w += (textwidth("Them") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua");
		
		w += (textwidth("Sua") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa");
		
		w += (textwidth("Xoa") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua muc sach") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua muc sach");
		
		w += (textwidth("Sua muc sach") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa muc sach") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa muc sach");
		
		w += (textwidth("Xoa muc sach") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Thoat");
	}
	else if(id == 12)
	{
		setfillstyle(1, 3);
		int w = 0;
		bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
		setbkcolor(3);
		setcolor(0);
		outtextxy(400 + w + 25, 220, "Them");
		
		setfillstyle(1, 4);
		setbkcolor(4);
		w += (textwidth("Them") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua");
		
		setfillstyle(1, 3);
		setbkcolor(3);
		w += (textwidth("Sua") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa");
		
		w += (textwidth("Xoa") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua muc sach") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua muc sach");
		
		w += (textwidth("Sua muc sach") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa muc sach") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa muc sach");
		
		w += (textwidth("Xoa muc sach") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Thoat");
	}
	else if(id == 13)
	{
		setfillstyle(1, 3);
		int w = 0;
		bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
		setbkcolor(3);
		setcolor(0);
		outtextxy(400 + w + 25, 220, "Them");
		
		w += (textwidth("Them") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua");
		
		setfillstyle(1, 4);
		setbkcolor(4);
		w += (textwidth("Sua") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa");
		
		setfillstyle(1, 3);
		setbkcolor(3);
		w += (textwidth("Xoa") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua muc sach") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua muc sach");
		
		w += (textwidth("Sua muc sach") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa muc sach") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa muc sach");
		
		w += (textwidth("Xoa muc sach") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Thoat");
	}
	else if(id == 14)
	{
			setfillstyle(1, 3);
		int w = 0;
		bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
		setbkcolor(3);
		setcolor(0);
		outtextxy(400 + w + 25, 220, "Them");
		
		w += (textwidth("Them") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua");
		
		w += (textwidth("Sua") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa");
		
		
		w += (textwidth("Xoa") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua muc sach") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua muc sach");
		
		w += (textwidth("Sua muc sach") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa muc sach") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa muc sach");
		
		setfillstyle(1, 4);
		setbkcolor(4);
		w += (textwidth("Xoa muc sach") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Thoat");
		
	}
	else if(id == 34)
	{
		setfillstyle(1, 3);
		int w = 0;
		bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
		setbkcolor(3);
		setcolor(0);
		outtextxy(400 + w + 25, 220, "Them");
		
		w += (textwidth("Them") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua");
		
		w += (textwidth("Sua") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa");
		
		setfillstyle(1, 4);
		setbkcolor(4);
		w += (textwidth("Xoa") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua muc sach") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua muc sach");
		
		setfillstyle(1, 3);
		setbkcolor(3);
		w += (textwidth("Sua muc sach") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa muc sach") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa muc sach");
		
		w += (textwidth("Xoa muc sach") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Thoat");
	}
	else if(id == 35)
	{
		setfillstyle(1, 3);
		int w = 0;
		bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
		setbkcolor(3);
		setcolor(0);
		outtextxy(400 + w + 25, 220, "Them");
		
		
		w += (textwidth("Them") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua");
		
		w += (textwidth("Sua") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa");
		
		w += (textwidth("Xoa") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua muc sach") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua muc sach");
		
		setfillstyle(1, 4);
		setbkcolor(4);
		w += (textwidth("Sua muc sach") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa muc sach") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa muc sach");
		
		setfillstyle(1, 3);
		setbkcolor(3);
		w += (textwidth("Xoa muc sach") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Thoat");
	}
	else
	{
		setfillstyle(1, 3);
		int w = 0;
		bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
		setbkcolor(3);
		setcolor(0);
		outtextxy(400 + w + 25, 220, "Them");
		
		
		w += (textwidth("Them") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua");
		
		w += (textwidth("Sua") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa");
		
		w += (textwidth("Xoa") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Sua muc sach") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Sua muc sach");
		
		w += (textwidth("Sua muc sach") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Xoa muc sach") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Xoa muc sach");
		
		w += (textwidth("Xoa muc sach") + 50 + 50);
		bar(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250);
		outtextxy(400 + w + 25, 220, "Thoat");
	}
}

void VeThemXoaSua(int mapID[][hight]){
	setfillstyle(1, 3);
	int w = 0;
	bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
	setbkcolor(3);
	setcolor(0);
	outtextxy(400 + w + 25, 220, "Them");
	SetID(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250, 11, mapID);
	
	w += (textwidth("Them") + 50 + 50);
	bar(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250);
	outtextxy(400 + w + 25, 220, "Sua");
	SetID(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250, 12, mapID);
	
	w += (textwidth("Sua") + 50 + 50);
	bar(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250);
	outtextxy(400 + w + 25, 220, "Xoa");
	SetID(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250, 13, mapID);
	
	w += (textwidth("Xoa") + 50 + 50);
	bar(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250);
	outtextxy(400 + w + 25, 220, "Thoat");
	SetID(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250, 14, mapID);
}

void VeThemXoaSuaDauSach(int mapID[][hight]){
	setfillstyle(1, 3);
	int w = 0;
	bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
	setbkcolor(3);
	setcolor(0);
	outtextxy(400 + w + 25, 220, "Them");
	SetID(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250, 11, mapID);
	
	w += (textwidth("Them") + 50 + 50);
	bar(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250);
	outtextxy(400 + w + 25, 220, "Sua");
	SetID(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250, 12, mapID);
	
	w += (textwidth("Sua") + 50 + 50);
	bar(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250);
	outtextxy(400 + w + 25, 220, "Xoa");
	SetID(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250, 13, mapID);
	
	w += (textwidth("Xoa") + 50 + 50);
	bar(400 + w, 200, 400 + textwidth("Sua muc sach") + 50 + w, 250);
	outtextxy(400 + w + 25, 220, "Sua muc sach");
	SetID(400 + w, 200, 400 + textwidth("Sua muc sach") + 50 + w, 250, 34, mapID);
	
	w += (textwidth("Sua muc sach") + 50 + 50);
	bar(400 + w, 200, 400 + textwidth("Xoa muc sach") + 50 + w, 250);
	outtextxy(400 + w + 25, 220, "Xoa muc sach");
	SetID(400 + w, 200, 400 + textwidth("Xoa muc sach") + 50 + w, 250, 35, mapID);
	
	w += (textwidth("Xoa muc sach") + 50 + 50);
	bar(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250);
	outtextxy(400 + w + 25, 220, "Thoat");
	SetID(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250, 14, mapID);
}

void XoaIDThemXoaSua(int mapID[][hight]){
	int w = 0;
	SetID(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250, 0, mapID);
	w += (textwidth("Them") + 50 + 50);
	SetID(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250, 0, mapID);
	w += (textwidth("Sua") + 50 + 50);
	SetID(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250, 0, mapID);
	w += (textwidth("Xoa") + 50 + 50);
	SetID(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250, 0, mapID);
}

void XoaIDThemXoaSuaDauSach(int mapID[][hight]){
	int w = 0;
	SetID(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250, 0, mapID);
	w += (textwidth("Them") + 50 + 50);
	SetID(400 + w, 200, 400 + textwidth("Sua") + 50 + w, 250, 0, mapID);
	w += (textwidth("Sua") + 50 + 50);
	SetID(400 + w, 200, 400 + textwidth("Xoa") + 50 + w, 250, 0, mapID);
	w += (textwidth("Xoa") + 50 + 50);
	SetID(400 + w, 200, 400 + textwidth("Sua muc sach") + 50 + w, 250, 0, mapID);
	w += (textwidth("Sua muc sach") + 50 + 50);
	SetID(400 + w, 200, 400 + textwidth("Xoa muc sach") + 50 + w, 250, 0, mapID);
	w += (textwidth("Xoa muc sach") + 50 + 50);
	SetID(400 + w, 200, 400 + textwidth("Thoat") + 50 + w, 250, 0, mapID);
}

void VeBang(int cot){
	int y = 0;
	int x = 0;
	setcolor(0);
	for(int i = 0; i < 7; i++)
	{
		line(400, 250 + y, 1400, 250 + y);
		y += 50;	
	}
	line(400, 250 + y, 1400, 250 + y);
	for(int i = 0; i <= cot; i++)
	{
		line(400 + x, 250, 400 + x, 250 + y);
		x += (1400 - 400)/cot;
	}
}

void veTimKiem(int mapID[][hight]){
	setbkcolor(15);
	setcolor(0);
	rectangle(400, 300, 600, 350);
	SetID(400, 300, 600, 350, 21, mapID);
	setfillstyle(1, 3);
	bar(640, 300, 740, 350);
	SetID(640, 300, 740, 350, 22, mapID);
	setbkcolor(3);
	setcolor(0);
	outtextxy(690 - textwidth("Tim")/2, 320, "Tim");
	bar(760, 300, 860, 350);
	SetID(760, 300, 860, 350, 23, mapID);
	setbkcolor(3);
	setcolor(0);
	outtextxy(810 - textwidth("Thoat")/2, 320, "Thoat");
}

void veTimKiemDon(int mapID[][hight]){
	setbkcolor(15);
	setcolor(0);
	rectangle(400, 200, 700, 250);
	SetID(400, 200, 700, 250, 21, mapID);
	setfillstyle(1, 3);
	bar(740, 200, 840, 250);
	SetID(740, 200, 840, 250, 22, mapID);
	setbkcolor(3);
	setcolor(0);
	outtextxy(790 - textwidth("Tim")/2, 220, "Tim");
	bar(860, 200, 960, 250);
	SetID(860, 200, 960, 250, 23, mapID);
	setbkcolor(3);
	setcolor(0);
	outtextxy(910 - textwidth("Thoat")/2, 220, "Thoat");
}

// Nhap lieu
int Input(int x, int y, int theLoai, int len, char s[], int &id, int mapID[][hight])
{
	char c;
	int x1, y1;
	int IDXet = id;
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x1, y1);
			IDXet = mapID[x1][y1];
			clearmouseclick(WM_LBUTTONDOWN);	
		}
		if(id != IDXet)
		{
			id = IDXet;
			if(s[strlen(s) - 1] == ' ')	
				s[strlen(s) - 1] = '\0';
			return 1;
		}
		if(kbhit())
		{
			c = getch();
			if(c != 13)
			{
				if(c == 8 && strlen(s) != 0)
				{
					outtextxy(x + textwidth(s), y, " ");
					s[strlen(s) - 1] = '\0';
				}
				else
				{
					if(theLoai == 1)
					{
						if(c >= '0' && c <= '9')
						{
							if(strlen(s) < len)
							{
								strncat(s, &c, 1);	
								outtextxy(x, y, s);
							}
						}
					}
					else if(theLoai == 2)
					{
						if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
						{
							if(strlen(s) < len)
							{
								if(c >= 'a' && c <= 'z')
								{
									c = c- 32;
								}
								strncat(s, &c, 1);	
								outtextxy(x, y, s);
							}
						}
						if(c == ' ')
						{
							if(strlen(s) < len)
							{
								if(strlen(s) != 0 && s[strlen(s) - 1] != ' ')
								{
									strncat(s, &c, 1);	
									outtextxy(x, y, s);
								}
							}
							
						}
					}
					else if(theLoai == 4)
					{
						if(c >= '0' && c <= '1')
						{
							if(strlen(s) < len)
							{
								strncat(s, &c, 1);	
								outtextxy(x, y, s);
							}
						}
					}
					else if(theLoai == 5)
					{
						if(c >= '0' && c <= '2')
						{
							if(strlen(s) < len)
							{
								strncat(s, &c, 1);	
								outtextxy(x, y, s);
							}
						}
					}
					else if(theLoai == 6)
					{
						if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
						{
							if(strlen(s) < len)
							{
								if(c >= 'a' && c <= 'z')
								{
									c = c- 32;
								}
								strncat(s, &c, 1);	
								outtextxy(x, y, s);
							}
						}
					}
					else
					{
						if(c == ' ')
						{
							if(strlen(s) < len)
							{
								if(strlen(s) != 0 && s[strlen(s) - 1] != ' ')
								{
									strncat(s, &c, 1);	
									outtextxy(x, y, s);
								}
							}
							
						}
						else
							if(strlen(s) < len)
							{
								if(c >= 'a' && c <= 'z')
								{
									c = c- 32;
								}
								strncat(s, &c, 1);	
								outtextxy(x, y, s);
							}
					}
				}
			}
			else
			{
				id = 0;
				if(s[strlen(s)-1]==' ')
		    		s[strlen(s)-1]='\0';
				return 1;
			}
		}
		else
		{
				outtextxy(x + textwidth(s),y,"|");
				delay(20);
				outtextxy(x + textwidth(s),y," ");
				delay(20);
		}
	}
}


// In danh sach cac dau sach 

void HienThiDanhSachDauSach(int pageCurent, int totalPage, char hienThiTrang[], DanhSachDauSach dS, int sl, int y1, int h, int hienThi){
	
	if(hienThi == 1)
	{
		h = 0;
		y1 = 130;
		outtextxy(400 + textwidth("ISBN")/2 + h, 220 + 180, "ISBN");
		h += 100;
		outtextxy(400 + textwidth("Ten Sach")/2 + h, 220 + 180, "Ten Sach");
		h += 300;
		outtextxy(400 + textwidth("Tac Gia")/2 + h, 220 + 180, "Tac Gia");
		h += 300;
		outtextxy(400 + textwidth("The Loai")/2 + h, 220 + 180, "The Loai");
		h += 200;
		outtextxy(400 + textwidth("Nam XB")/2 + h, 220 + 180, "Nam XB");
		for(int i = 0; i < 5; i++)
		{
			if(i + 5*pageCurent >= sl)
				break;
			line(400, 250 + y1, 1400, 250 + y1);
			h = 0;
				//outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i].phai);
			char outPut[5];
			outtextxy(400 + 10, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 5*pageCurent]->ISBN);
			h += 100;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 5*pageCurent]->TenSach);
			h += 300;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 5*pageCurent]->TacGia);
			h += 300;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 5*pageCurent]->TheLoai);
			h += 200;
			ConvertIntToChar(outPut, dS.danhSachDauSach[i + 5*pageCurent]->NamXB);
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, outPut);
			y1 += 50;
		}
	}
	else
	{
		y1 = 30;
		h = 0;
		outtextxy(400 + textwidth("ISBN")/2 + h, 220 + 80, "ISBN");
		h += 100;
		outtextxy(400 + textwidth("Ten Sach")/2 + h, 220 + 80, "Ten Sach");
		h += 300;
		outtextxy(400 + textwidth("Tac Gia")/2 + h, 220 + 80, "Tac Gia");
		h += 300;
		outtextxy(400 + textwidth("The Loai")/2 + h, 220 + 80, "The Loai");
		h += 200;
		outtextxy(400 + textwidth("Nam XB")/2 + h, 220 + 80, "Nam XB");
		for(int i = 0; i < 6; i++)
		{
			if(i + 6*pageCurent >= sl)
				break;
			line(400, 250 + y1, 1400, 250 + y1);
			h = 0;
				//outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i].phai);
			char outPut[5];
			//ConvertIntToChar(outPut, );
			outtextxy(400 + 10, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 6*pageCurent]->ISBN);
			h += 100;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 6*pageCurent]->TenSach);
			h += 300;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 6*pageCurent]->TacGia);
			h += 300;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 6*pageCurent]->TheLoai);
			h += 200;
			ConvertIntToChar(outPut, dS.danhSachDauSach[i + 6*pageCurent]->NamXB);
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, outPut);
			y1 += 50;
		}
	}
	
	int x1 = 0;
	line(400, 250 + y1, 1400, 250 + y1);
	y1+=50;
	line(400, 250 + y1, 1400, 250 + y1);
	if(hienThi == 1)
		line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
	else
		line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	x1 += 100;
	for(int i = 0; i < 3; i++)
	{
		if(hienThi == 1)
			line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
		else
			line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
		x1 += 300;
	}
	x1 -= 100;
	if(hienThi == 1)
		line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
	else
		line(400 + x1, 250  + 30, 400 + x1, 250 + y1);
	x1 += 100;
	if(hienThi == 1)
		line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
	else
		line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	char page[8];
	page[0] = '\0';
	char tmp[4];
	ConvertIntToChar(tmp, pageCurent + 1);
	strcat(page, tmp);
	strcat(page, "/");
	memset(tmp, 0, 4);
	ConvertIntToChar(tmp, totalPage);
	strcat(page, tmp);
	strcat(hienThiTrang, page);
	if(hienThi == 1)
		outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650 + 50, hienThiTrang);
	else
		outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650 + 30, hienThiTrang);
}

void xoaDanhSachDauSach(int pageCurent, int totalPage, char hienThiTrang[], DanhSachDauSach dS, int sl, int y1, int h, int hienThi){
	setbkcolor(15);
	setcolor(15);
	y1 = 0;
	if(hienThi == 1)
	{
		h = 0;
		outtextxy(400 + textwidth("ISBN")/2 + h, 220 + 180, "ISBN");
		h += 100;
		outtextxy(400 + textwidth("Ten Sach")/2 + h, 220 + 180, "Ten Sach");
		h += 300;
		outtextxy(400 + textwidth("Tac Gia")/2 + h, 220 + 180, "Tac Gia");
		h += 300;
		outtextxy(400 + textwidth("The Loai")/2 + h, 220 + 180, "The Loai");
		h += 200;
		outtextxy(400 + textwidth("Nam XB")/2 + h, 220 + 180, "Nam XB");
		y1 = 130;
		for(int i = 0; i < 5; i++)
		{
			if(i + 5*pageCurent >= sl)
				break;
			line(400, 250 + y1, 1400, 250 + y1);
			h = 0;
				//outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i].phai);
			char outPut[5];
			//ConvertIntToChar(outPut, dS.danhSachDauSach[i + 5*pageCurent]->ISBN);
			outtextxy(400 + 10, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 5*pageCurent]->ISBN);
			h += 100;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 5*pageCurent]->TenSach);
			h += 300;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 5*pageCurent]->TacGia);
			h += 300;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 5*pageCurent]->TheLoai);
			h += 200;
			ConvertIntToChar(outPut, dS.danhSachDauSach[i + 5*pageCurent]->NamXB);
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, outPut);
			y1 += 50;
		}
	}
	else
	{
		y1 = 30;
		for(int i = 0; i < 6; i++)
		{
			if(i + 6*pageCurent >= sl)
				break;
			line(400, 250 + y1, 1400, 250 + y1);
			h = 0;
				//outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i].phai);
			char outPut[5];
			//ConvertIntToChar(outPut, );
			outtextxy(400 + 10, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 6*pageCurent]->ISBN);
			h += 100;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 6*pageCurent]->TenSach);
			h += 300;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 6*pageCurent]->TacGia);
			h += 300;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dS.danhSachDauSach[i + 6*pageCurent]->TheLoai);
			h += 200;
			ConvertIntToChar(outPut, dS.danhSachDauSach[i + 6*pageCurent]->NamXB);
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, outPut);
			y1 += 50;
		}
	}
	int x1 = 0;
	line(400, 250 + y1, 1400, 250 + y1);
	y1+=50;
	line(400, 250 + y1, 1400, 250 + y1);
	if(hienThi == 1)
		line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
	else
		line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	x1 += 100;
	for(int i = 0; i < 3; i++)
	{
		if(hienThi == 1)
			line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
		else
			line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
		x1 += 300;
	}
	x1 -= 100;
	if(hienThi == 1)
		line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
	else
		line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	x1 += 100;
	if(hienThi == 1)
		line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
	else
		line(400 + x1, 250, 400 + x1, 250 + y1);
	if(hienThi == 1)
		outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650 + 50, hienThiTrang);
	else
		outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650 + 30, hienThiTrang);
}

void InDanhSachDauSach(int mapID[][hight], DanhSachDauSach dS){
	if(dS.SLDauSach == 0)
	{
		MessageBox(NULL, "Danh  sach dau sach rong!", "Thong Bao", MB_OK);
		return;
	}
	quickSortDauSachHienThi(dS.danhSachDauSach, 0, dS.SLDauSach - 1);
	setfillstyle(1, 3);
	bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
	setbkcolor(3);
	setcolor(0);
	outtextxy(405, 205, "Thoat");
	setbkcolor(15);
	//outtextxy(400 + 500 - textwidth("Trang 1/2")/2, 650, "Trang 1/2");
	SetID(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230, 11, mapID);
	outtextxy(400 + 500 - textwidth("In danh sach dau sach")/2, 140, "In danh sach dau sach");
	
	
	// In du lieu
	int h = 0;
	int totalPage = dS.SLDauSach/7 + 1;
	if(dS.SLDauSach % 6 == 0)
		totalPage = dS.SLDauSach/6;
	else
		totalPage = dS.SLDauSach/6 + 1;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	int y1 = 0;
	// Ve Bang
	if(dS.SLDauSach < 7)
	{
		HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
	}
	else
	{
		SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + 30 + textheight("back"), 12, mapID);
		SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30+ textheight("next"), 13, mapID);
		outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, "back");
		outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, "next");
		HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
	}
	int x, y;
	int IDXet = 0;
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				//VeThemXoaSua(mapID);
				continue;
			}
			else if(IDXet == 11)
			{
				break;
			}
			else if(IDXet == 12)
			{
				//cout << "Vao";
				if(pageCurent > 0)
				{
					xoaDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
					pageCurent--;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
					
				}
			}
			else if(IDXet == 13)
			{
				//cout << "Vao!";
				if(pageCurent < totalPage - 1)
				{
					xoaDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
					pageCurent++;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
				}
			}
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			//IDtruoc = IDXet;
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 11)
			{
				setfillstyle(1, 4);
				bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(4);
				setcolor(0);
				outtextxy(405, 205, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(3);
				setcolor(0);
				outtextxy(405, 205, "Thoat");
			}
		}
		delay(100);
	}
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	SetID(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + 30 + textheight("back"), 12, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30 + textheight("next"), 13, mapID);
	quickSortTenSach(dS.danhSachDauSach, 0, dS.SLDauSach - 1);
}

// Doc Gia 
// Sua va them moi
void NhapDocGia(int x, int y,int mapID[][hight], DocGia *dg, DanhSachDocGia &dS, int arr1[], int arr2[], int them, int &nt, int &np)
{
	setbkcolor(15);
	setcolor(0);
	outtextxy(400 + x, 320 + y, "Nhap ho");
	rectangle(400 + x, 345 + y, 600 + x, 395 + y);
	outtextxy(800 + x, 320 + y, "Nhap ten");
	rectangle(800 + x, 345 + y, 1000 + x, 395 + y);
	outtextxy(400 + x, 450 + y, "Nhap phai");
	rectangle(400 + x, 475 + y, 600 + x, 525 + y);
	outtextxy(615 + x, 495 + y, "(NAM or NU)");
	outtextxy(800 + x, 450 + y, "Trang thai the");
	rectangle(800 + x, 475 + y, 1000 + x, 525 + y);
	outtextxy(1020 + x, 480 + y, "0. bi khoa");
	outtextxy(1020 + x, 495 + y, "1. dang hoat dong");
	setfillstyle(1, 3);
	bar(450 + x, 550 + y, 550 + x, 600 + y);
	bar(850 + x, 550 + y, 950 + x, 600 + y);
	setbkcolor(3);
	setcolor(0);
	outtextxy(500 - textwidth("Luu")/2 + x, 565 + y, "Luu");
	outtextxy(900 - textwidth("Thoat")/2 + x, 565 + y, "Thoat");
	//ten
	SetID(400 + x, 345 + y, 600 + x, 395 + y, 15, mapID);
	// so trang
	SetID(800 + x, 345 + y, 1000 + x, 395 + y, 16, mapID);
	// nam xb
	SetID(400 + x, 475 + y, 600 + x, 525 + y, 17, mapID);
	// the loai
	SetID(800 + x, 475 + y, 1000 + x, 525 + y, 18, mapID);
	// them
	SetID(450 + x, 550 + y, 550 + x, 600 + y, 19, mapID);
	// thoat
	SetID(850 + x, 550 + y, 950 + x, 600 + y, 20, mapID);
	if(them == 0)
	{
		setbkcolor(15);
		setcolor(0);
		outtextxy(405 + x, 365 + y, dg->ho);
		outtextxy(805 + x, 365 + y, dg->ten);
		outtextxy(405 + x, 495 + y, dg->phai);
		char S[2];
		S[0] = Inttochar(dg->trangThaiThe);
		S[1] = '\0';
		outtextxy(805 + x, 495 + y, S);
	}
	int xt, yt;
	int IDXet = 0;
	setbkcolor(15);
	setcolor(0);
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, xt, yt);
			IDXet = mapID[xt][yt];
			clearmouseclick(WM_LBUTTONDOWN);
			setbkcolor(15);
			setcolor(0);
			if(IDXet == 0)
			{
				continue;
			}
			else if(IDXet == 19)
			{
				//themDocGia:
				if(them == 1)
				{
					if(dg->ho[0] == '\0' || dg->ten[0] == '\0' || dg->trangThaiThe == -1)
					{
						MessageBox(NULL, "Vui long dien du thong tin", "Thong Bao", MB_OK);
						continue;
					}
					if(strcmp(dg->phai, "NAM") != 0 && strcmp(dg->phai, "NU") != 0)
					{
							MessageBox(NULL, "Gioi tinh chi nhan hai gia tri NAM va NU", "Thong Bao", MB_OK);
							continue;
					}
					dg->MaThe = TaoMaThe(dS.dsDocGia, arr1, arr2, nt, np);
					AddNodeOnTree(dS.dsDocGia, dg);
					dS.SLDocGia++;
					MessageBox(NULL, "Them Thanh Cong", "Thong Bao", MB_OK);
				}
				else
				{
					if(dg->ho[0] == '\0' || dg->ten[0] == '\0' || dg->trangThaiThe == -1)
					{
						MessageBox(NULL, "Vui long dien du thong tin", "Thong Bao", MB_OK);
						continue;
					}
					MessageBox(NULL, "Sua Thanh Cong", "Thong Bao", MB_OK);
				}
				break;
			}
			else if(IDXet == 15)
			{
				// ho
				hoDocGia:
				Input(405 + x, 365 + y, 2, 50, dg->ho, IDXet, mapID);
				if(IDXet == 16)
					goto tenDocGia;
				else if(IDXet == 17)
					goto phaiDocGia;
				else if(IDXet == 18)
					goto trangThaiDocGia;
			}
			else if(IDXet == 16)
			{
				// ten
				tenDocGia:
				Input(805 + x, 365 + y, 2, 20, dg->ten, IDXet, mapID);
				if(IDXet == 15)
					goto hoDocGia;
				else if(IDXet == 17)
					goto phaiDocGia;
				else if(IDXet == 18)
					goto trangThaiDocGia;
			}
			else if(IDXet == 17)
			{
				// Phai
				phaiDocGia:
				Input(405 + x, 495 + y, 2, 4, dg->phai, IDXet, mapID);
				if(IDXet == 16)
					goto tenDocGia;
				else if(IDXet == 15)
					goto hoDocGia;
				else if(IDXet == 18)
					goto trangThaiDocGia;
			}
			else if(IDXet == 18)
			{
				// trang thai
				trangThaiDocGia:
				char S[1];
				S[0] = '\0';
				Input(805 + x, 495 + y, 4, 1, S, IDXet, mapID);
				if(S[0] == '\0')
				{
					dg->trangThaiThe = -1;
				}
				else	dg->trangThaiThe = charToInt(S[0]);
				//cout << dg->trangThaiThe;
				if(IDXet == 16)
					goto tenDocGia;
				else if(IDXet == 15)
					goto hoDocGia;
				else if(IDXet == 17)
					goto phaiDocGia;
			}
			else if(IDXet == 20)
				break;
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, xt, yt);
			IDXet = mapID[xt][yt];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 19){
				setfillstyle(1, 4);
				bar(450 + x, 550 + y, 550 + x, 600 + y);
				setbkcolor(4);
				setcolor(0);
				outtextxy(500 - textwidth("Luu")/2 + x, 565 + y, "Luu");
				
				setfillstyle(1, 3);
				bar(850 + x, 550 + y, 950 + x, 600 + y);
				setbkcolor(3);
				setcolor(0);
				outtextxy(900 - textwidth("Thoat")/2 + x, 565 + y, "Thoat");
			}
			else if(IDXet == 20){
				setfillstyle(1, 3);
				bar(450 + x, 550 + y, 550 + x, 600 + y);
				setbkcolor(3);
				setcolor(0);
				outtextxy(500 - textwidth("Luu")/2 + x, 565 + y, "Luu");
				
				setfillstyle(1, 4);
				bar(850 + x, 550 + y, 950 + x, 600 + y);
				setbkcolor(4);
				setcolor(0);
				outtextxy(900 - textwidth("Thoat")/2 + x, 565 + y, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(450 + x, 550 + y, 550 + x, 600 + y);
				bar(850 + x, 550 + y, 950 + x, 600 + y);
				setbkcolor(3);
				setcolor(0);
				outtextxy(500 - textwidth("Luu")/2 + x, 565 + y, "Luu");
				outtextxy(900 - textwidth("Thoat")/2 + x, 565 + y, "Thoat");
			}
		}
		delay(100);
	}
	SetID(400 + x, 345 + y, 600 + x, 395 + y, 0, mapID);
	// so trang
	SetID(800 + x, 345 + y, 1000 + x, 395 + y, 0, mapID);
	// nam xb
	SetID(400 + x, 475 + y, 600 + x, 525 + y, 0, mapID);
	// the loai
	SetID(800 + x, 475 + y, 1000 + x, 525 + y, 0, mapID);
	// them
	SetID(450 + x, 550 + y, 550 + x, 600 + y, 0, mapID);
	// thoat
	SetID(850 + x, 550 + y, 950 + x, 600 + y, 0, mapID);
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	setfillstyle(1, 4);
	bar(30, 130 + 0, 230, 0 + 160);
	setbkcolor(4);
	setcolor(0);
	outtextxy(130 - textwidth("The doc gia")/2, 135 + 0, "The doc gia");
	setbkcolor(15);
	setcolor(0);
}

// Tim kiem sua va xoa
void TimKiemDocGia(int mapID[][hight], int dangXoa, int dangThem, DanhSachDocGia &dS, int arr1[], int arr2[], int &nt, int &np){
	setfillstyle(2, 2);
	setbkcolor(15);
	setcolor(0);
	outtextxy(400, 280, "Nhap ma doc gia");
	setfillstyle(1, 4);
	veTimKiem(mapID);
	int h = 0;
	setbkcolor(15);
	setcolor(0);
	// Set Du Lieu
	int n = 0;
	//cout << ds.SLDocGia;
	DocGia *DSDG[dS.SLDocGia];
	ChuyenDoiDuLieuDocGia(dS.dsDocGia, DSDG, n);
	int y1 = 50;
	int totalPage = 0;
	if(dS.SLDocGia % 5 == 0)
		totalPage = dS.SLDocGia/5;
	else
		totalPage = dS.SLDocGia/5 + 1;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	int id = 0;
	int hienThi = 1;
	if(dS.SLDocGia < 6)
	{	
		HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, hienThi);
	}
	else
	{
		SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 50, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"), 650 + 50 + textheight("back"), 25, mapID);
		SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 50, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 50 + textheight("next"), 26, mapID);
		outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 50, "back");
		outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 50, "next");
		HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, hienThi);
	}
	int x, y;
	int IDXet = 0;
	int maThe = 0;
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				continue;
			}
			else if(IDXet == 21)
			{
				char S[5];
				S[0] = '\0';
				setbkcolor(15);
				setcolor(0);
				Input(405, 320, 1, 5, S, IDXet, mapID);
				maThe = Convert(S);
			}
			else if(IDXet == 22)
			{
				//cout << maThe;
				DocGia *t = findDocGia(dS.dsDocGia, maThe);
				if(t == NULL){
					MessageBox(NULL, "Doc gia nay khong ton tai", "Thong Bao", MB_OK);
				}
				else
				{
					xoaHienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, hienThi);
					if(dS.SLDocGia >= 6)
					{	
						setbkcolor(15);
						setcolor(15);
						outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 50, "back");
						outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 50, "next");
						setbkcolor(15);
						setcolor(0);
					}
					if(dangXoa == 0)
					{
						//cout << t->ho;
						NhapDocGia(0, 120, mapID, t, dS, arr1, arr2, dangThem, nt, np);
						SetID(400, 300, 600, 350, 0, mapID);
						SetID(640, 300, 740, 350, 0, mapID);
						SetID(760, 300, 860, 350, 0, mapID);
						SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 50, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + 50 + textheight("back"), 0, mapID);
						SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 50, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 50 + textheight("next"), 0, mapID);
						return;
					}
					else
					{
						if(t->dSMuonTra->SLDS != 0)
						{
							MessageBox(NULL, "Doc gia nay da tung muon sach trong thu vien khong the xoa!", "Thong Bao", MB_OK);
						}
						else
							if(MessageBox(NULL, "Ban co that su muon xoa doc gia nay", "Xac Nhan", MB_YESNO) == 6)
							{
								XoaNodeDocGia(dS.dsDocGia, maThe);
								dS.SLDocGia--;
								break;
							}
					}	
				}
			}
			else if(IDXet == 25)
			{
				if(pageCurent == 0)
					continue;
				xoaHienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, hienThi);
				pageCurent--;
				setbkcolor(15);
				setcolor(0);
				int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
				memset(hienThiTrang, 0, length);
				strcat(hienThiTrang, "Trang ");
				HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, hienThi);
				//DrawMenu();
			}
			else if(IDXet == 26)
			{
				if(pageCurent == totalPage - 1)
					continue;
				xoaHienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, hienThi);
				pageCurent++;
				setbkcolor(15);
				setcolor(0);
				int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
				memset(hienThiTrang, 0, length);
				strcat(hienThiTrang, "Trang ");
				HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, hienThi);
				//DrawMenu();
			}
			else if(IDXet == 23)
				break;
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 22)
			{
				setfillstyle(1, 4);
				bar(640, 300, 740, 350);
				setbkcolor(4);
				setcolor(0);
				outtextxy(690 - textwidth("Tim")/2, 320, "Tim");
				setfillstyle(1, 3);
				bar(760, 300, 860, 350);
				setbkcolor(3);
				setcolor(0);
				outtextxy(810 - textwidth("Thoat")/2, 320, "Thoat");
			}
			else if(IDXet == 23)
			{
				setfillstyle(1, 3);
				bar(640, 300, 640, 350);
				setbkcolor(3);
				setcolor(0);
				outtextxy(690 - textwidth("Tim")/2, 320, "Tim");
				setfillstyle(1, 4);
				bar(760, 300, 860, 350);
				setbkcolor(4);
				setcolor(0);
				outtextxy(810 - textwidth("Thoat")/2, 320, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(640, 300, 740, 350);
				setbkcolor(3);
				setcolor(0);
				outtextxy(690 - textwidth("Tim")/2, 320, "Tim");
				bar(760, 300, 860, 350);
				outtextxy(810 - textwidth("Thoat")/2, 320, "Thoat");
			}
		}
		delay(100);
	}
	SetID(400, 300, 600, 350, 0, mapID);
	SetID(640, 300, 740, 350, 0, mapID);
	SetID(760, 300, 860, 350, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 50, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"), 650 + 50 + textheight("back"), 0, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 50, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 50 + textheight("next"), 0, mapID);
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	setfillstyle(1, 4);
	bar(30, 130 + 0, 230, 0 + 160);
	setbkcolor(4);
	setcolor(0);
	outtextxy(130 - textwidth("The doc gia")/2, 135 + 0, "The doc gia");
	setbkcolor(15);
	setcolor(0);
}

// Ham thuc hien chuc nang doc gia
void quanLyDocGia(int mapID[][hight], DanhSachDocGia &dSDG, int arr1[], int arr2[], int &nt, int &np){
	int x, y;
	int IDXet = 0;
	VeThemXoaSua(mapID);
	setbkcolor(15);
	setcolor(0);
	outtextxy(400 + 500 - textwidth("Quan ly doc gia")/2, 140, "Quan ly doc gia");
	int dangXoa = 0;
	int dangThem = 0;
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				continue;
			}
			else if(IDXet == 11)
			{
				dangThem = 1;
				DocGia *newDocGia = new DocGia;
				newDocGia->pLeft = NULL;
				newDocGia->pRight = NULL;
				newDocGia->ho[0] = '\0';
				newDocGia->ten[0] = '\0';
				newDocGia->phai[0] = '\0';
				newDocGia->trangThaiThe = -1;
				newDocGia->dSMuonTra = new DanhSachMuonTra;
				NhapDocGia(0, 0,mapID, newDocGia, dSDG, arr1, arr2, dangThem, nt, np);
				VeThemXoaSua(mapID);
				setbkcolor(15);
				setcolor(0);
				outtextxy(400 + 500 - textwidth("Quan ly doc gia")/2, 140, "Quan ly doc gia");
			}
			else if(IDXet == 12)
			{
				dangXoa = 0;
				dangThem = 0;
				TimKiemDocGia(mapID, dangXoa, dangThem, dSDG, arr1, arr2, nt, np);
				VeThemXoaSua(mapID);
				setbkcolor(15);
				setcolor(0);
				outtextxy(400 + 500 - textwidth("Quan ly doc gia")/2, 140, "Quan ly doc gia");
			}
			else if(IDXet == 13)
			{
				dangXoa = 1;
				TimKiemDocGia(mapID, dangXoa, dangThem, dSDG, arr1, arr2, nt, np);
				VeThemXoaSua(mapID);
				setbkcolor(15);
				setcolor(0);
				outtextxy(400 + 500 - textwidth("Quan ly doc gia")/2, 140, "Quan ly doc gia");
			}
			else if(IDXet == 14)
				break;
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			ThayDoiThemXoaSua(IDXet);
		}
		delay(100);
	}
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	XoaIDThemXoaSua(mapID);
}

// Hien thi danh sach doc gia

void HienThiDanhSachDocGia(int pageCurent, int totalPage, char hienThiTrang[], DocGia *DSDG[], int sl, int y1, int h, int hienThi){
	if(hienThi == 1)
	{
		int cot = 4;
		h = 0;
		outtextxy(400 + textwidth("Ma the")/2 + h, 220 + 100 + 80, "Ma the");
		h += (1400-400)/cot;
		outtextxy(400 + textwidth("Ho")/2 + h, 220 + 100 + 80, "Ho");
		h += (1400-400)/cot;
		outtextxy(400 + textwidth("Ten")/2 + h, 220 + 100 + 80, "Ten");
		h += (1400-400)/cot;
		outtextxy(400 + textwidth("Phai")/2 + h, 220 + 100 + 80, "Phai");
		y1 = 130;
		h = 0;
		for(int i = 0; i < 5; i++)
		{
			if(i + 5*pageCurent == sl)
				break;
			char s[6];
			s[0] = '\0';
			ConvertIntToChar(s, DSDG[i + 5*pageCurent]->MaThe);
			line(400, 250 + y1, 1400, 250 + y1);
			h = 0;
			outtextxy(400 + 10, 220 + 50 + 50 + y1, s);
			h += (1400-400)/4;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i + 5*pageCurent]->ho);
			h += (1400-400)/4;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i + 5*pageCurent]->ten);
			h += (1400-400)/4;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i + 5*pageCurent]->phai);
			y1 += 50;
		}
	}
	else
	{
		y1 = 30;
		h = 0;
		int cot = 4;
		outtextxy(400 + textwidth("Ma the")/2 + h, 220 + 80, "Ma the");
		h += (1400-400)/cot;
		outtextxy(400 + textwidth("Ho")/2 + h, 220 + 80, "Ho");
		h += (1400-400)/cot;
		outtextxy(400 + textwidth("Ten")/2 + h, 220 + 80, "Ten");
		h += (1400-400)/cot;
		outtextxy(400 + textwidth("Phai")/2 + h, 220 + 80, "Phai");
		h = 0;
		for(int i = 0; i < 6; i++)
		{
			if(i + 6*pageCurent == sl)
				break;
			char s[6];
			s[0] = '\0';
			ConvertIntToChar(s, DSDG[i + 6*pageCurent]->MaThe);
			line(400, 250 + y1, 1400, 250 + y1);
			h = 0;
			outtextxy(400 + 10, 220 + 50 + 50 + y1, s);
			h += (1400-400)/4;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i + 6*pageCurent]->ho);
			h += (1400-400)/4;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i + 6*pageCurent]->ten);
			h += (1400-400)/4;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i + 6*pageCurent]->phai);
			y1 += 50;
		}
	}
	int x1 = 0;
	line(400, 250 + y1, 1400, 250 + y1);
	y1+=50;
	line(400, 250 + y1, 1400, 250 + y1);
	for(int i = 0; i <= 4; i++)
	{
		if(hienThi == 1)
			line(400 + x1, 250 + 100 + 30, 400 + x1, 250 + y1);
		else
			line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
		x1 += (1400 - 400)/4;
	}
	char page[8];
	char tmp[4];
	page[0] = '\0';
	tmp[0] = '\0';
	ConvertIntToChar(tmp, pageCurent + 1);
	strcat(page, tmp);
	//int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);	
	strcat(page, "/");	
	memset(tmp, 0, 4);
	ConvertIntToChar(tmp, totalPage);
	strcat(page, tmp);
	strcat(hienThiTrang, page);
	if(hienThi == 1)
		outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650 + 50, hienThiTrang);
	else
		outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650 + 30, hienThiTrang);
}

void xoaHienThiDanhSachDocGia(int pageCurent, int totalPage, char hienThiTrang[], DocGia *DSDG[], int sl, int y1, int h, int hienThi){
	setbkcolor(15);
	setcolor(15);
	if(hienThi == 1)
	{
		y1 = 130;
		h = 0;
		int cot = 4;
		outtextxy(400 + textwidth("Ma the")/2 + h, 220 + 100 + 80, "Ma the");
		h += (1400-400)/cot;
		outtextxy(400 + textwidth("Ho")/2 + h, 220 + 100 + 80, "Ho");
		h += (1400-400)/cot;
		outtextxy(400 + textwidth("Ten")/2 + h, 220 + 100 + 80, "Ten");
		h += (1400-400)/cot;
		outtextxy(400 + textwidth("Phai")/2 + h, 220 + 100 + 80, "Phai");
		for(int i = 0; i < 5; i++)
		{
			if(i + 5*pageCurent >= sl)
				break;
			char s[6];
			ConvertIntToChar(s, DSDG[i + 5*pageCurent]->MaThe);
			line(400, 250 + y1, 1400, 250 + y1);
			h = 0;
			outtextxy(400 + 10, 220 + 50 + 50 + y1, s);
			h += (1400-400)/4;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i + 5*pageCurent]->ho);
			h += (1400-400)/4;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i + 5*pageCurent]->ten);
			h += (1400-400)/4;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i + 5*pageCurent]->phai);
			y1 += 50;
		}
	}
	else
	{
		//y1 = 0;
		y1 = 30;
		h = 0;
		int cot = 4;
		outtextxy(400 + textwidth("Ma the")/2 + h, 220 + 80, "Ma the");
		h += (1400-400)/cot;
		outtextxy(400 + textwidth("Ho")/2 + h, 220 + 80, "Ho");
		h += (1400-400)/cot;
		outtextxy(400 + textwidth("Ten")/2 + h, 220 + 80, "Ten");
		h += (1400-400)/cot;
		outtextxy(400 + textwidth("Phai")/2 + h, 220 + 80, "Phai");
		h = 0;
		for(int i = 0; i < 6; i++)
		{
			if(i + 6*pageCurent >= sl)
				break;
			char s[6];
			ConvertIntToChar(s, DSDG[i + 6*pageCurent]->MaThe);
			line(400, 250 + y1, 1400, 250 + y1);
			h = 0;
			outtextxy(400 + 10, 220 + 50 + 50 + y1, s);
			h += (1400-400)/4;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i + 6*pageCurent]->ho);
			h += (1400-400)/4;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i + 6*pageCurent]->ten);
			h += (1400-400)/4;
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i + 6*pageCurent]->phai);
			y1 += 50;
		}
	}
	
	int x1 = 0;
	line(400, 250 + y1, 1400, 250 + y1);
	y1+=50;
	line(400, 250 + y1, 1400, 250 + y1);
	for(int i = 0; i <= 4; i++)
	{
		if(hienThi == 1)
			line(400 + x1, 250 + 100 + 30, 400 + x1, 250 + y1);
		else
			line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
		x1 += (1400 - 400)/4;
	}
	if(hienThi == 1)
		outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650 + 50, hienThiTrang);
	else
		outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650 + 30, hienThiTrang);
}

void inDanhSachDocGia(int mapID[][hight], DanhSachDocGia ds){
	if(ds.SLDocGia == 0)
	{
		MessageBox(NULL, "Danh  sach doc gia rong!", "Thong Bao", MB_OK);
		return;
	}
	int cot = 4;
	//VeBang(4);
	setfillstyle(1, 3);
	bar(400, 200, 400 + textwidth("Sap xep theo ID") + 10, 230);
	setbkcolor(3);
	setcolor(0);
	outtextxy(405, 205, "Sap xep theo ID");
	int ySapXep = 400 + textwidth("Sap xep theo ID") + 10;
	bar(ySapXep + 50, 200, ySapXep + 50 + textwidth("Sap xep theo ten") + 10, 230);
	setbkcolor(3);
	setcolor(0);
	outtextxy(ySapXep + 50 + 5, 205, "Sap xep theo ten");
	int yThoat = ySapXep + 50 + textwidth("Sap xep theo ten") + 10;
	bar(yThoat + 50, 200, yThoat + 50 + textwidth("Thoat") + 10, 230);
	setbkcolor(3);
	setcolor(0);
	outtextxy(yThoat + 50 + 5, 205, "Thoat");
	
	setbkcolor(15);
	setcolor(0);
	outtextxy(400 + 500 - textwidth("In danh sach doc gia")/2, 140, "In danh sach doc gia");
	int h = 0;
	SetID(400, 200, 400 + textwidth("Sap xep theo ID") + 10, 230, 11, mapID);
	SetID(ySapXep + 50, 200, ySapXep + 50 + textwidth("Sap xep theo ten") + 10, 230, 12, mapID);
	SetID(yThoat + 50, 200, yThoat + 50 + textwidth("Thoat") + 10, 230, 31, mapID);
	// Set Du Lieu
	int n = 0;
	//cout << ds.SLDocGia;
	DocGia *DSDG[ds.SLDocGia];
	ChuyenDoiDuLieuDocGia(ds.dsDocGia, DSDG, n);
	int y1 = 0;
	int totalPage = 0;
	if(ds.SLDocGia % 6 == 0)
		totalPage = ds.SLDocGia/6;
	else
		totalPage = ds.SLDocGia/6 + 1;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	int id = 0;
	int hienThi = 0;
	if(ds.SLDocGia < 7)
	{	
		HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, ds.SLDocGia, y1, h, hienThi);
	}
	else
	{
		SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"), 650 + 30 + textheight("back"), 13, mapID);
		SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30 + textheight("next"), 14, mapID);
		outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, "back");
		outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, "next");
		HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, ds.SLDocGia, y1, h, hienThi);
	}
	// Nut Bam
	int x, y;
	int IDXet = 0;
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				continue;
			}
			if(IDXet == 11)
			{
				xoaHienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, ds.SLDocGia, y1, h, hienThi);
				setbkcolor(15);
				setcolor(0);
				quickSortDocGiaIDHienThi(DSDG, 0, ds.SLDocGia - 1);
				int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
				memset(hienThiTrang, 0, length);
				strcat(hienThiTrang, "Trang ");
				HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, ds.SLDocGia, y1, h, hienThi);
			}
			else if(IDXet == 31)
				break;
			else if(IDXet == 13)
			{
				if(pageCurent == 0)
					continue;
				xoaHienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, ds.SLDocGia, y1, h, hienThi);
				pageCurent--;
				setbkcolor(15);
				setcolor(0);
				int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
				memset(hienThiTrang, 0, length);
				strcat(hienThiTrang, "Trang ");
				HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, ds.SLDocGia, y1, h, hienThi);
				//DrawMenu();
			}
			else if(IDXet == 14)
			{
				if(pageCurent == totalPage - 1)
					continue;
				xoaHienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, ds.SLDocGia, y1, h, hienThi);
				pageCurent++;
				setbkcolor(15);
				setcolor(0);
				int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
				memset(hienThiTrang, 0, length);
				strcat(hienThiTrang, "Trang ");
				HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, ds.SLDocGia, y1, h, hienThi);
				//DrawMenu();
			}
			if(IDXet == 12)
			{
				xoaHienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, ds.SLDocGia, y1, h, hienThi);
				setbkcolor(15);
				setcolor(0);
				quickSortDocGiaTenHienThi(DSDG, 0, ds.SLDocGia - 1);
				int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
				memset(hienThiTrang, 0, length);
				strcat(hienThiTrang, "Trang ");
				HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, ds.SLDocGia, y1, h, hienThi);
			}
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			int h = 0;
			getmouseclick(WM_MOUSEMOVE, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 11){
				setfillstyle(1, 4);
				bar(400, 200, 400 + textwidth("Sap xep theo ID") + 10, 230);
				setbkcolor(4);
				setcolor(0);
				outtextxy(405, 205, "Sap xep theo ID");
				setfillstyle(1, 3);
				bar(yThoat + 50, 200, yThoat + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(3);
				setcolor(0);
				outtextxy(yThoat + 50 + 5, 205, "Thoat");
				bar(ySapXep + 50, 200, ySapXep + 50 + textwidth("Sap xep theo ten") + 10, 230);
				outtextxy(ySapXep + 50 + 5, 205, "Sap xep theo ten");
			}
			else if (IDXet == 31)
			{
				setfillstyle(1, 3);
				bar(400, 200, 400 + textwidth("Sap xep theo ID") + 10, 230);
				setbkcolor(3);
				setcolor(0);
				outtextxy(405, 205, "Sap xep theo ID");
				bar(ySapXep + 50, 200, ySapXep + 50 + textwidth("Sap xep theo ten") + 10, 230);
				outtextxy(ySapXep + 50 + 5, 205, "Sap xep theo ten");
				setfillstyle(1, 4);
				bar(yThoat + 50, 200, yThoat + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(4);
				setcolor(0);
				outtextxy(yThoat + 50 + 5, 205, "Thoat");
			}
			else if(IDXet == 12)
			{
				setfillstyle(1, 3);
				bar(400, 200, 400 + textwidth("Sap xep theo ID") + 10, 230);
				setbkcolor(3);
				setcolor(0);
				outtextxy(405, 205, "Sap xep theo ID");
				bar(yThoat + 50, 200, yThoat + 50 + textwidth("Thoat") + 10, 230);
				outtextxy(yThoat + 50 + 5, 205, "Thoat");
				setfillstyle(1, 4);
				setbkcolor(4);
				setcolor(0);
				bar(ySapXep + 50, 200, ySapXep + 50 + textwidth("Sap xep theo ten") + 10, 230);
				outtextxy(ySapXep + 50 + 5, 205, "Sap xep theo ten");
			}
			else
			{
				setfillstyle(1, 3);
				bar(400, 200, 400 + textwidth("Sap xep theo ID") + 10, 230);
				setbkcolor(3);
				setcolor(0);
				outtextxy(405, 205, "Sap xep theo ID");
				//setfillstyle(1, 3);
				bar(yThoat + 50, 200, yThoat + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(3);
				setcolor(0);
				outtextxy(yThoat + 50 + 5, 205, "Thoat");
				bar(ySapXep + 50, 200, ySapXep + 50 + textwidth("Sap xep theo ten") + 10, 230);
				outtextxy(ySapXep + 50 + 5, 205, "Sap xep theo ten");
			}
		}
		delay(100);
	}
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	SetID(400, 200, 400 + textwidth("Sap xep theo ID") + 10, 230, 0, mapID);
	SetID(ySapXep + 50, 200, ySapXep + 50 + textwidth("Sap xep theo ten") + 10, 230, 0, mapID);
	SetID(yThoat + 50, 200, yThoat + 50 + textwidth("Thoat") + 10, 230, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30,400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"), 650 + 30 + textheight("back"), 0, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 330, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30 + textheight("next"), 0, mapID);
}


// Nhap muc sach 

void themMucSach(int x, int y,int mapID[][hight], DauSach *dauSach, int &idDMSMax, int SL, DanhMucSach &dMS){
	// Them
	SetID(1100 + x, 475 + y, 1300 + x, 525 + y, 0, mapID);
	SetID(400 + x, 345 + y, 600 + x, 395 + y, 0, mapID);
	// so trang
	SetID(800 + x, 345 + y, 1000 + x, 395 + y, 0, mapID);
	// nam xb
	SetID(400 + x, 475 + y, 600 + x, 525 + y, 0, mapID);
	// the loai
	SetID(800 + x, 475 + y, 1000 + x, 525 + y, 0, mapID);
	// them
	SetID(450 + x, 550 + y, 550 + x, 600 + y, 0, mapID);
	// thoat
	SetID(850 + x, 550 + y, 950 + x, 600 + y, 0, mapID);
	// Ten tac gia 
	SetID(1100 + x, 345 + y, 1300 + x, 395 + y, 0, mapID);
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	setfillstyle(1, 4);
	bar(30, 130 + 120, 230, 120 + 160);
	setbkcolor(4);
	setcolor(0);
	outtextxy(130 - textwidth("Quan ly dau sach")/2, 135 + 120, "Quan ly dau sach");
	VeThemXoaSuaDauSach(mapID);
	setfillstyle(1, 4);
	int w = 0;
	bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
	setbkcolor(4);
	setcolor(0);
	outtextxy(400 + w + 25, 220, "Them");
	setbkcolor(15);
	setcolor(0);
	outtextxy(400 + 500 - textwidth("Quan ly dau sach")/2, 140, "Quan ly dau sach");
	//DrawMenu();
	
	// Thao tac
	setbkcolor(15);
	setcolor(0);
	outtextxy(400 + x, 320 + y - 120, "Nhap vi tri");
	rectangle(400 + x, 345 + y - 120, 600 + x, 395 + y - 120);
	setfillstyle(1, 3);
	bar(450 + x, 450 + y - 120, 550 + x, 500 + y - 120);
	bar(850 + x, 450 + y - 120, 1000 + x, 500 + y - 120);
	setbkcolor(3);
	setcolor(0);
	outtextxy(500 - textwidth("Them")/2 + x, 465 + y - 120, "Them");
	outtextxy(925 - textwidth("Them cho tat ca")/2 + x, 465 + y - 120, "Them cho tat ca");
	
	// Vi tri
	SetID(400 + x, 345 + y - 120, 600 + x, 395 + y - 120, 15, mapID);
	// trang thai
	//SetID(800 + x, 345 + y - 120, 1000 + x, 395 + y - 120, 16, mapID);
	// Them 1
	SetID(450 + x, 450 + y - 120, 550 + x, 500 + y - 120, 17, mapID);
	// them het
	SetID(850 + x, 450 + y - 120, 950 + x, 500 + y - 120, 18, mapID);
	int xt, yt;
	int IDXet = 0;
	char vitri[100];
	vitri[0] = '\0';
	//char trangThai[1];
	int indexThem = 0;
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, xt, yt);
			IDXet = mapID[xt][yt];
			clearmouseclick(WM_LBUTTONDOWN);
			setbkcolor(15);
			setcolor(0);
			if(IDXet == 0)
			{
				continue;
			}
			else if(IDXet == 15)
			{
				Input(405 + x, 365 + y - 120, 3, 100, vitri, IDXet, mapID);
			}
			else if(IDXet == 17)
			{
				MucSach *p = new MucSach;
				MucSach *q = new MucSach;
				p->maSach = idDMSMax;
				q->maSach = idDMSMax;
				idDMSMax++;
				memcpy(p->ViTri, vitri, sizeof(vitri));
				memcpy(q->ViTri, vitri, sizeof(vitri));
				p->TrangThai = 0;
				q->TrangThai = 0;
					
				p->pNext = NULL;
				q->pNext = NULL;
				themVaoCuoi(dauSach->dMS, p);
				themVaoCuoiDMS(dMS, q);
				indexThem++;
				//vitri[0] = '\0';
				MessageBox(NULL, "Them Thanh Cong", "Thong Bao", MB_OK);
				if(indexThem == SL)
					break;
			}
			else if(IDXet == 18)
			{
				for(int i = indexThem; i < SL; i++)
				{
					MucSach *p = new MucSach;
					MucSach *q = new MucSach;
					p->maSach = idDMSMax;
					q->maSach = idDMSMax;
					idDMSMax++;
					memcpy(p->ViTri, vitri, sizeof(vitri));
					memcpy(q->ViTri, vitri, sizeof(vitri));
					p->TrangThai = 0;
					q->TrangThai = 0;
					p->pNext = NULL;
					q->pNext = NULL;
					themVaoCuoi(dauSach->dMS, p);
					themVaoCuoiDMS(dMS, q);
				}
				MessageBox(NULL, "Them Thanh Cong", "Thong Bao", MB_OK);
				break;
			}
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, xt, yt);
			IDXet = mapID[xt][yt];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 17)
			{
				setfillstyle(1, 4);
				bar(450 + x, 450 + y - 120, 550 + x, 500 + y - 120);
				setbkcolor(4);
				setcolor(0);
				outtextxy(500 - textwidth("Them")/2 + x, 465 + y - 120, "Them");
				
				setfillstyle(1, 3);
				bar(850 + x, 450 + y- 120, 1000 + x, 500 + y- 120);
				setbkcolor(3);
				setcolor(0);
				outtextxy(925 - textwidth("Them cho tat ca")/2 + x, 465 + y- 120, "Them cho tat ca");
	
			}
			else if(IDXet == 18)
			{
				setfillstyle(1, 3);
				bar(450 + x, 450 + y- 120, 550 + x, 500 + y- 120);
				setbkcolor(3);
				setcolor(0);
				outtextxy(500 - textwidth("Them")/2 + x, 465 + y- 120, "Them");
				
				setfillstyle(1, 4);
				bar(850 + x, 450 + y- 120, 1000 + x, 500 + y- 120);
				setbkcolor(4);
				setcolor(0);
				outtextxy(925 - textwidth("Them cho tat ca")/2 + x, 465 + y- 120, "Them cho tat ca");
	
			}
			else
			{
				setfillstyle(1, 3);
				bar(450 + x, 450 + y - 120, 550 + x, 500 + y - 120);
				bar(850 + x, 450 + y - 120, 1000 + x, 500 + y - 120);
				setbkcolor(3);
				setcolor(0);
				outtextxy(500 - textwidth("Them")/2 + x, 465 + y - 120, "Them");
				outtextxy(925 - textwidth("Them cho tat ca")/2 + x, 465 + y - 120, "Them cho tat ca");
			}
		}
		delay(100);
	}
	// Vi tri
	SetID(400 + x, 345 + y - 120, 600 + x, 395 + y - 120, 0, mapID);
	// trang thai
	SetID(800 + x, 345 + y - 120, 1000 + x, 395 + y - 120, 0, mapID);
	// Them 1
	SetID(450 + x, 450 + y - 120, 550 + x, 500 + y - 120, 0, mapID);
	// them het
	SetID(850 + x, 450 + y - 120, 950 + x, 500 + y - 120, 0, mapID);
}



void suaMucSach(int x, int y,int mapID[][hight], DanhSachDauSach &dS, MucSach *mucSach){
	// Them
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	setfillstyle(1, 4);
	bar(30, 130 + 120, 230, 120 + 160);
	setbkcolor(4);
	setcolor(0);
	outtextxy(130 - textwidth("Quan ly dau sach")/2, 135 + 120, "Quan ly dau sach");
	VeThemXoaSuaDauSach(mapID);
	setfillstyle(1, 4);
	int w = 0;
	bar(400 + w, 200, 400 + textwidth("Them") + 50 + w, 250);
	setbkcolor(4);
	setcolor(0);
	outtextxy(400 + w + 25, 220, "Them");
	setbkcolor(15);
	setcolor(0);
	outtextxy(400 + 500 - textwidth("Quan ly dau sach")/2, 140, "Quan ly dau sach");
	//DrawMenu();
	
	// Thao tac
	setbkcolor(15);
	setcolor(0);
	outtextxy(400 + x, 320 + y - 120, "Nhap vi tri");
	rectangle(400 + x, 345 + y - 120, 600 + x, 395 + y - 120);
	
	setfillstyle(1, 3);
	bar(450 + x, 450 + y - 120, 550 + x, 500 + y - 120);
	bar(850 + x, 450 + y - 120, 1000 + x, 500 + y - 120);
	setbkcolor(3);
	setcolor(0);
	outtextxy(500 - textwidth("Sua")/2 + x, 465 + y - 120, "Sua");
	outtextxy(925 - textwidth("Thoat")/2 + x, 465 + y - 120, "Thoat");
	
	// Vi tri
	SetID(400 + x, 345 + y - 120, 600 + x, 395 + y - 120, 15, mapID);
	
	// Them 1
	SetID(450 + x, 450 + y - 120, 550 + x, 500 + y - 120, 17, mapID);
	// them het
	SetID(850 + x, 450 + y - 120, 950 + x, 500 + y - 120, 18, mapID);
	int xt, yt;
	int IDXet = 0;
	char vitri[100];
	vitri[0] = '\0';
	memcpy(vitri, mucSach->ViTri, sizeof(mucSach->ViTri));
	setbkcolor(15);
	setcolor(0);
	outtextxy(405 + x, 365 + y - 120, vitri);
	//char trangThai[1];
	//int indexThem = 0;
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, xt, yt);
			IDXet = mapID[xt][yt];
			clearmouseclick(WM_LBUTTONDOWN);
			setbkcolor(15);
			setcolor(0);
			if(IDXet == 0)
			{
				continue;
			}
			else if(IDXet == 15)
			{
				Input(405 + x, 365 + y - 120, 3, 100, vitri, IDXet, mapID);
			}
			else if(IDXet == 17)
			{
				if(MessageBox(NULL, "Ban that su muon hieu chinh muc sach nay", "Thong Bao", MB_YESNO) ==6)
				{
					memset(mucSach->ViTri, 0, 100);
					memcpy(mucSach->ViTri, vitri, sizeof(vitri));
					capNhatDauSachMucSach(mucSach, dS);
					MessageBox(NULL, "Hieu chinh Thanh Cong", "Thong Bao", MB_OK);
					break;
				}
			}
			else if(IDXet == 18)
			{
				break;
			}
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, xt, yt);
			IDXet = mapID[xt][yt];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 17)
			{
				setfillstyle(1, 4);
				bar(450 + x, 450 + y - 120, 550 + x, 500 + y - 120);
				setbkcolor(4);
				setcolor(0);
				outtextxy(500 - textwidth("Sua")/2 + x, 465 + y - 120, "Sua");
				
				setfillstyle(1, 3);
				bar(850 + x, 450 + y- 120, 1000 + x, 500 + y- 120);
				setbkcolor(3);
				setcolor(0);
				outtextxy(925 - textwidth("Thoat")/2 + x, 465 + y- 120, "Thoat");
	
			}
			else if(IDXet == 18)
			{
				setfillstyle(1, 3);
				bar(450 + x, 450 + y- 120, 550 + x, 500 + y- 120);
				setbkcolor(3);
				setcolor(0);
				outtextxy(500 - textwidth("Sua")/2 + x, 465 + y- 120, "Sua");
				
				setfillstyle(1, 4);
				bar(850 + x, 450 + y- 120, 1000 + x, 500 + y- 120);
				setbkcolor(4);
				setcolor(0);
				outtextxy(925 - textwidth("Thoat")/2 + x, 465 + y- 120, "Thoat");
	
			}
			else
			{
				setfillstyle(1, 3);
				bar(450 + x, 450 + y - 120, 550 + x, 500 + y - 120);
				bar(850 + x, 450 + y - 120, 1000 + x, 500 + y - 120);
				setbkcolor(3);
				setcolor(0);
				outtextxy(500 - textwidth("Sua")/2 + x, 465 + y - 120, "Sua");
				outtextxy(925 - textwidth("Thoat")/2 + x, 465 + y - 120, "Thoat");
			}
		}
		delay(100);
	}
	// Vi tri
	SetID(400 + x, 345 + y - 120, 600 + x, 395 + y - 120, 0, mapID);
	// trang thai
	SetID(800 + x, 345 + y - 120, 1000 + x, 395 + y - 120, 0, mapID);
	// Them 1
	SetID(450 + x, 450 + y - 120, 550 + x, 500 + y - 120, 0, mapID);
	// them het
	SetID(850 + x, 450 + y - 120, 950 + x, 500 + y - 120, 0, mapID);
}

// Nhap Dau Sach


void NhapDauSach(int x, int y,int mapID[][hight], int dangThem, DanhSachDauSach &dS, DauSach *dauSach, int &idDMSMax, DanhMucSach &dMS)
{
	setbkcolor(15);
	setcolor(0);
	outtextxy(400 + x, 320 + y, "Nhap ten sach");
	rectangle(400 + x, 345 + y, 700 + x, 395 + y);
	outtextxy(800 + x, 320 + y, "Nhap so trang");
	rectangle(800 + x, 345 + y, 1000 + x, 395 + y);
	outtextxy(400 + x, 450 + y, "Nhap nam xuat ban");
	rectangle(400 + x, 475 + y, 600 + x, 525 + y);
	outtextxy(800 + x, 450 + y, "Nhap the loai");
	rectangle(800 + x, 475 + y, 1000 + x, 525 + y);
	outtextxy(1100 + x, 320 + y, "Nhap ten tac gia");
	rectangle(1100 + x, 345 + y, 1300 + x, 395 + y);
	
	setfillstyle(1, 3);
	bar(450 + x, 550 + y, 550 + x, 600 + y);
	bar(850 + x, 550 + y, 950 + x, 600 + y);
	setbkcolor(3);
	setcolor(0);
	outtextxy(500 - textwidth("Luu")/2 + x, 565 + y, "Luu");
	outtextxy(900 - textwidth("Thoat")/2 + x, 565 + y, "Thoat");
	int SL = 0;
	if(dangThem == 1)
	{
		setbkcolor(15);
		setcolor(0);
		outtextxy(1100 + x, 450 + y, "Nhap so luong sach");
		rectangle(1100 + x, 475 + y, 1300 + x, 525 + y);
		SetID(1100 + x, 475 + y, 1300 + x, 525 + y, 25, mapID);
	}
	//ten
	SetID(400 + x, 345 + y, 700 + x, 395 + y, 15, mapID);
	// so trang
	SetID(800 + x, 345 + y, 1000 + x, 395 + y, 16, mapID);
	// nam xb
	SetID(400 + x, 475 + y, 600 + x, 525 + y, 17, mapID);
	// the loai
	SetID(800 + x, 475 + y, 1000 + x, 525 + y, 18, mapID);
	// them
	SetID(450 + x, 550 + y, 550 + x, 600 + y, 19, mapID);
	// thoat
	SetID(850 + x, 550 + y, 950 + x, 600 + y, 20, mapID);
	// Ten tac gia
	SetID(1100 + x, 345 + y, 1300 + x, 395 + y, 24, mapID);
	
	// Sua
	if(dangThem == 0)
	{
		setbkcolor(15);
		setcolor(0);
		outtextxy(405 + x, 365 + y, dauSach->TenSach);
		char S[100];
		ConvertIntToChar(S, dauSach->SoTrang);
		outtextxy(805 + x, 365 + y, S);
		ConvertIntToChar(S, dauSach->NamXB);
		outtextxy(405 + x, 495 + y, S);
		outtextxy(805 + x, 495 + y, dauSach->TheLoai);
		outtextxy(1105 + x, 365 + y, dauSach->TacGia);
	}
	
	int xt, yt;
	int IDXet = 0;
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, xt, yt);
			IDXet = mapID[xt][yt];
			clearmouseclick(WM_LBUTTONDOWN);
			setbkcolor(15);
			setcolor(0);
			if(IDXet == 0)
			{
				continue;
			}
			else if(IDXet == 19)
			{
				if(dauSach->TacGia[0] == '\0' || dauSach->TenSach[0] == '\0' || dauSach->TheLoai[0] == '\0' || dauSach->ISBN[0] == '\0')
				{
					MessageBox(NULL, "Vui long dien du thong tin", "Thong Bao", MB_OK);
					continue;
				}
				if(dauSach->NamXB == 0 || dauSach->SoTrang == 0)
				{
					MessageBox(NULL, "Nam xuat ban, So trang khong the bang khong hoac de trong!", "Thong Bao", MB_OK);
					continue;
				}
				if(dangThem == 1)
				{
					if(kiemTraISBN(dS, dauSach->ISBN))
					{
						MessageBox(NULL, "ISBN nay da duoc su dung!", "Thong Bao", MB_OK);
						continue;
					}
					themSach(dS, dauSach);
					MessageBox(NULL, "Them Thanh Cong", "Thong Bao", MB_OK);
					dauSach->dMS = new DanhMucSach;
					themMucSach(x, y, mapID, dauSach, idDMSMax, SL, dMS);
					break;
				}
				else
				{
					MessageBox(NULL, "Sua Thanh Cong", "Thong Bao", MB_OK);
					break;
				}
				
			}
			else if(IDXet == 15)
			{
				// ten sach
				tenSachGoTo:
				Input(405 + x, 365 + y, 3, 100, dauSach->TenSach, IDXet, mapID);
				if(IDXet == 16)
					goto trangSachGoTo;
				else if(IDXet == 17)
					goto namXBGoTo;
				else if(IDXet == 18)
					goto theloaiGoTo;
				else if(IDXet == 24)
					goto tacGiaGoTo;
				else if(IDXet == 25)
					goto soLuongDSMGoTo;
				else if(IDXet == 26)
					goto IBSN;
			}
			else if(IDXet == 16)
			{
				// trang sach
				trangSachGoTo:
				char S[6];
				S[0] = '\0';
				ConvertIntToChar(S, dauSach->SoTrang);
				outtextxy(805 + x, 365 + y, S);	
				Input(805 + x, 365 + y, 1, 6,S, IDXet, mapID);
				if(S[0] == '\0')
					dauSach->SoTrang = 0;
				else
					dauSach->SoTrang = Convert(S);
				if(IDXet == 15)
					goto tenSachGoTo;
				else if(IDXet == 17)
					goto namXBGoTo;
				else if(IDXet == 18)
					goto theloaiGoTo;
				else if(IDXet == 24)
					goto tacGiaGoTo;
				else if(IDXet == 25)
					goto soLuongDSMGoTo;
				else if(IDXet == 26)
					goto IBSN;
			}
			else if(IDXet == 17)
			{
				// nam xb
				namXBGoTo:
				char S[5];
				S[0] = '\0';
				if(dauSach->NamXB != 0)
				{
					ConvertIntToChar(S, dauSach->NamXB);
					outtextxy(405 + x, 495 + y, S);
				}
				Input(405 + x, 495 + y, 1, 4,S, IDXet, mapID);
				if(S[0] == '\0')
					dauSach->NamXB = 0;
				else
					dauSach->NamXB = Convert(S);
				if(IDXet == 15)
					goto tenSachGoTo;
				else if(IDXet == 16)
					goto trangSachGoTo;
				else if(IDXet == 18)
					goto theloaiGoTo;
				else if(IDXet == 24)
					goto tacGiaGoTo;
				else if(IDXet == 25)
					goto soLuongDSMGoTo;
				else if(IDXet == 26)
					goto IBSN;
			}
			else if(IDXet == 18)
			{
				theloaiGoTo:
				// the loai
				Input(805 + x, 495 + y, 2, 50, dauSach->TheLoai, IDXet, mapID);
				if(IDXet == 15)
					goto tenSachGoTo;
				else if(IDXet == 17)
					goto namXBGoTo;
				else if(IDXet == 16)
					goto trangSachGoTo;
				else if(IDXet == 24)
					goto tacGiaGoTo;
				else if(IDXet == 25)
					goto soLuongDSMGoTo;
				else if(IDXet == 26)
					goto IBSN;
			}
			else if(IDXet == 24)
			{
				tacGiaGoTo:
				// Tac gia
				Input(1105 + x, 365 + y, 2, 50, dauSach->TacGia, IDXet, mapID);
				if(IDXet == 15)
					goto tenSachGoTo;
				else if(IDXet == 17)
					goto namXBGoTo;
				else if(IDXet == 18)
					goto theloaiGoTo;
				else if(IDXet == 16)
					goto trangSachGoTo;
				else if(IDXet == 25)
					goto soLuongDSMGoTo;
				else if(IDXet == 26)
					goto IBSN;
			}
			else if(IDXet == 25){
				soLuongDSMGoTo:
				char S[5];
				S[0] = '\0';
				Input(1105 + x, 495 + y, 1, 5,S, IDXet, mapID);
				if(S[0] == '\0')
					SL = 0;
				else
					SL = Convert(S);
				if(IDXet == 15)
					goto tenSachGoTo;
				else if(IDXet == 17)
					goto namXBGoTo;
				else if(IDXet == 18)
					goto theloaiGoTo;
				else if(IDXet == 24)
					goto tacGiaGoTo;
				else if(IDXet == 16)
					goto trangSachGoTo;
				else if(IDXet == 26)
					goto IBSN;
			}
			else if(IDXet == 26){
				IBSN:
				Input(405, 365, 6, 10, dauSach->ISBN, IDXet, mapID);
				if(IDXet == 15)
					goto tenSachGoTo;
				else if(IDXet == 17)
					goto namXBGoTo;
				else if(IDXet == 18)
					goto theloaiGoTo;
				else if(IDXet == 24)
					goto tacGiaGoTo;
				else if(IDXet == 16)
					goto trangSachGoTo;
				else if(IDXet == 25)
					goto soLuongDSMGoTo;
			}
			else if(IDXet == 20)
				break;
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, xt, yt);
			IDXet = mapID[xt][yt];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 19){
				setfillstyle(1, 4);
				bar(450 + x, 550 + y, 550 + x, 600 + y);
				setbkcolor(4);
				setcolor(0);
				outtextxy(500 - textwidth("Luu")/2 + x, 565 + y, "Luu");
				
				setfillstyle(1, 3);
				bar(850 + x, 550 + y, 950 + x, 600 + y);
				setbkcolor(3);
				setcolor(0);
				outtextxy(900 - textwidth("Thoat")/2 + x, 565 + y, "Thoat");
			}
			else if(IDXet == 20){
				setfillstyle(1, 3);
				bar(450 + x, 550 + y, 550 + x, 600 + y);
				setbkcolor(3);
				setcolor(0);
				outtextxy(500 - textwidth("Luu")/2 + x, 565 + y, "Luu");
				
				setfillstyle(1, 4);
				bar(850 + x, 550 + y, 950 + x, 600 + y);
				setbkcolor(4);
				setcolor(0);
				outtextxy(900 - textwidth("Thoat")/2 + x, 565 + y, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(450 + x, 550 + y, 550 + x, 600 + y);
				bar(850 + x, 550 + y, 950 + x, 600 + y);
				setbkcolor(3);
				setcolor(0);
				outtextxy(500 - textwidth("Luu")/2 + x, 565 + y, "Luu");
				outtextxy(900 - textwidth("Thoat")/2 + x, 565 + y, "Thoat");
			}
		}
		delay(100);
	}
	if(dangThem == 1)
		SetID(1100 + x, 475 + y, 1300 + x, 525 + y, 0, mapID);
	SetID(400 + x, 345 + y, 600 + x, 395 + y, 0, mapID);
	// so trang
	SetID(800 + x, 345 + y, 1000 + x, 395 + y, 0, mapID);
	// nam xb
	SetID(400 + x, 475 + y, 600 + x, 525 + y, 0, mapID);
	// the loai
	SetID(800 + x, 475 + y, 1000 + x, 525 + y, 0, mapID);
	// them
	SetID(450 + x, 550 + y, 550 + x, 600 + y, 0, mapID);
	// thoat
	SetID(850 + x, 550 + y, 950 + x, 600 + y, 0, mapID);
	// Ten tac gia 
	SetID(1100 + x, 345 + y, 1300 + x, 395 + y, 0, mapID);
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	setfillstyle(1, 4);
	bar(30, 130 + 120, 230, 120 + 160);
	setbkcolor(4);
	setcolor(0);
	outtextxy(130 - textwidth("Quan ly dau sach")/2, 135 + 120, "Quan ly dau sach");
}

// tim kiem 

void TimKiemDauSach(int mapID[][hight], int dangXoa, int dangThem, DanhSachDauSach &dS, int &idDMSMax, DanhMucSach &dMS, DanhSachMuonTra dSMT){
	setfillstyle(2, 2);
	setbkcolor(15);
	setcolor(0);
	outtextxy(400, 280, "Nhap IBSN");
	setfillstyle(1, 4);
	veTimKiem(mapID);
	
	
	///////////////////////////
	setbkcolor(15);
	setcolor(0);
	int h = 0;
	int totalPage = 0;
	if(dS.SLDauSach % 5 == 0)
		totalPage = dS.SLDauSach/5;
	else
		totalPage = dS.SLDauSach/5 + 1;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	int y1 = 0;
	// Ve Bang
	if(dS.SLDauSach < 6)
	{
		HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 1);
	}
	else
	{
		SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 50, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + 50 + textheight("back"), 25, mapID);
		SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 50, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 50 + textheight("next"), 26, mapID);
		outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 50, "back");
		outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 50, "next");
		HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 1);
	}
	int x, y;
	int IDXet = 0;
	char ibsn[10];
	ibsn[0] = '\0';
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				continue;
			}
			else if(IDXet == 21)
			{
				setbkcolor(15);
				setcolor(0);
				Input(405, 320, 6, 10, ibsn, IDXet, mapID);
			}
			else if(IDXet == 22)
			{
				DauSach *dauSach = findDauSach(dS, ibsn);
				if(dauSach == NULL)
				{
					MessageBox(NULL, "Dau sach khong ton tai!", "Thong Bao", MB_OK);
					continue;
				}
				
				if(dangXoa == 0)
				{
					xoaDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 1);
					if(dS.SLDauSach >= 6)
					{	
						setbkcolor(15);
						setcolor(15);
						outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 50, "back");
						outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 50, "next");
						setbkcolor(15);
						setcolor(0);
					}
					NhapDauSach(0, 120, mapID, dangThem, dS, dauSach, idDMSMax, dMS);
					break;
				}
				else
				{
					int check = kiemTraXoaDauSach(dauSach->dMS, dSMT);
					//kiemTraXoa(dauSach->dMS, dSDG.dsDocGia, check);
					if(check != 0)
					{
						MessageBox(NULL, "Khong the xoa dau sach nay. Dau sach nay da co y nhat mot muc sanh da duoc muon", "Thong Bao", MB_OK);
						continue;
					}
					if(MessageBox(NULL, "Ban co that su muon xoa dau sach nay", "Xac Nhan", MB_YESNO) == 6)
					{
						xoaDauSach(dS, ibsn, dMS);
						MessageBox(NULL, "Xoa thanh cong", "Thong Bao", MB_OK);
						break;
					}
				}	
			}
			else if(IDXet == 25)
			{
				//cout << "Vao";
				if(pageCurent > 0)
				{
					xoaDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 1);
					pageCurent--;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 1);
					
				}
			}
			else if(IDXet == 26)
			{
				//cout << "Vao!";
				if(pageCurent < totalPage - 1)
				{
					xoaDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h,1);
					pageCurent++;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 1);
				}
			}
			else if(IDXet == 23)
				break;
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 22)
			{
				setfillstyle(1, 4);
				bar(640, 300, 740, 350);
				setbkcolor(4);
				setcolor(0);
				outtextxy(690 - textwidth("Tim")/2, 320, "Tim");
				setfillstyle(1, 3);
				bar(760, 300, 860, 350);
				setbkcolor(3);
				setcolor(0);
				outtextxy(810 - textwidth("Thoat")/2, 320, "Thoat");
			}
			else if(IDXet == 23)
			{
				setfillstyle(1, 3);
				bar(640, 300, 740, 350);
				setbkcolor(3);
				setcolor(0);
				outtextxy(690 - textwidth("Tim")/2, 320, "Tim");
				setfillstyle(1, 4);
				bar(760, 300, 860, 350);
				setbkcolor(4);
				setcolor(0);
				outtextxy(810 - textwidth("Thoat")/2, 320, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(640, 300, 740, 350);
				setbkcolor(3);
				setcolor(0);
				outtextxy(690 - textwidth("Tim")/2, 320, "Tim");
				bar(760, 300, 860, 350);
				outtextxy(810 - textwidth("Thoat")/2, 320, "Thoat");
			}
		}
		delay(100);
	}
	//xoaDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 1);
	SetID(400, 300, 600, 350, 0, mapID);
	SetID(640, 300, 740, 350, 0, mapID);
	SetID(760, 300, 860, 350, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 50, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + 50 + textheight("back"), 0, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 50, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 50 + textheight("next"), 0, mapID);
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	setfillstyle(1, 4);
	bar(30, 130 + 120, 230, 120 + 160);
	setbkcolor(4);
	setcolor(0);
	outtextxy(130 - textwidth("Quan ly dau sach")/2, 135 + 120, "Quan ly dau sach");
}


void HienThiDanhSachMucSachSuaXoa(int pageCurent, int totalPage, char hienThiTrang[], DanhSachDauSach dSDS,DanhMucSach dS, int sl, int y1, int h){
	y1 = 130;
	MucSach *p = dS.pHead;
	h = 0;
	outtextxy(400 + 10 + h, 250 + 20 + y1, "Ma sach");
	h += 150;
	outtextxy(400 + 10 + h, 250 + 20 + y1, "Vi tri");
	h += 250;
	outtextxy(400 + 10 + h, 250 + 20 + y1, "Ten sach");
	h += 300;
	outtextxy(400 + 10 + h, 250 + 20 + y1, "Trang thai");
	for(int i =0; i < 5*pageCurent; i++)
	{
		p = p->pNext;
	}		
	for(int i = 0; i < 5; i++)
	{
		
		if(p == NULL)
			break;
		line(400, 250 + y1, 1250, 250 + y1);
		h = 0;
			//outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i].phai);
		char outPut[5];
		memset(outPut, 0, 5);
		ConvertIntToChar(outPut, p->maSach);
		outtextxy(400 + 10, 250 + 50 + 20 + y1, outPut);
		h += 150;
		outtextxy(400 + 10 + h, 250 + 50 + 20 + y1, p->ViTri);
		h += 250;
		DauSach *dauSach = findDauSachTheoMaSach(dSDS, p->maSach);
		outtextxy(400 + 10 + h, 250 + 50 + 20 + y1, dauSach->TenSach);
		h += 300;
		if(p->TrangThai == 0)
			outtextxy(400 + 10 + h, 250 + 50 + 20 + y1, "Muon duoc");
		else if(p->TrangThai == 1)
			outtextxy(400 + 10 + h, 250 + 50 + 20 + y1, "Duoc muon");
		else
			outtextxy(400 + 10 + h, 250 + 50 + 20 + y1, "Thanh ly");
		//outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, outPut);
		y1 += 50;
		p = p->pNext;
	}
	int x1 = 0;
	line(400, 250 + y1, 1250, 250 + y1);
	y1+=50;
	line(400, 250 + y1, 1250, 250 + y1);
	line(400 + x1, 220 + 160, 400 + x1, 250 + y1);
	x1 += 150;
	line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
	x1 += 250;
	line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
	x1 += 300;
	line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
	x1 += 150;
	line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
	char page[8];
	page[0] = '\0';
	char tmp[4];
	ConvertIntToChar(tmp, pageCurent + 1);
	strcat(page, tmp);
	strcat(page, "/");
	memset(tmp, 0, 4);
	ConvertIntToChar(tmp, totalPage);
	strcat(page, tmp);
	strcat(hienThiTrang, page);
	outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 700, hienThiTrang);
}

void xoaDanhSachMucSachSuaXoa(int pageCurent, int totalPage, char hienThiTrang[], DanhSachDauSach dSDS, DanhMucSach dS, int sl, int y1, int h){
	setbkcolor(15);
	setcolor(15);
	y1 = 130;
	MucSach *p = dS.pHead;
	h = 0;
	outtextxy(400 + 10 + h, 250 + 20 + y1, "Ma sach");
	h += 150;
	outtextxy(400 + 10 + h, 250 + 20 + y1, "Vi tri");
	h += 250;
	outtextxy(400 + 10 + h, 250 + 20 + y1, "Ten sach");
	h += 300;
	outtextxy(400 + 10 + h, 250 + 20 + y1, "Trang thai");
	for(int i =0; i < 5*pageCurent; i++)
	{
		p = p->pNext;
	}		
	for(int i = 0; i < 5; i++)
	{
		
		if(p == NULL)
			break;
		line(400, 250 + y1, 1250, 250 + y1);
		h = 0;
			//outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i].phai);
		char outPut[5];
		memset(outPut, 0, 5);
		ConvertIntToChar(outPut, p->maSach);
		outtextxy(400 + 10, 250 + 50 + 20 + y1, outPut);
		h += 150;
		outtextxy(400 + 10 + h, 250 + 50 + 20 + y1, p->ViTri);
		h += 250;
		DauSach *dauSach = findDauSachTheoMaSach(dSDS, p->maSach);
		outtextxy(400 + 10 + h, 250 + 50 + 20 + y1, dauSach->TenSach);
		h += 300;
		if(p->TrangThai == 0)
			outtextxy(400 + 10 + h, 250 + 50 + 20 + y1, "Muon duoc");
		else if(p->TrangThai == 1)
			outtextxy(400 + 10 + h, 250 + 50 + 20 + y1, "Duoc muon");
		else
			outtextxy(400 + 10 + h, 250 + 50 + 20 + y1, "Thanh ly");
		//outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, outPut);
		y1 += 50;
		p = p->pNext;
	}
	int x1 = 0;
	line(400, 250 + y1, 1250, 250 + y1);
	y1+=50;
	line(400, 250 + y1, 1250, 250 + y1);
	line(400 + x1, 220 + 160, 400 + x1, 250 + y1);
	x1 += 150;
	line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
	x1 += 250;
	line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
	x1 += 300;
	line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
	x1 += 150;
	line(400 + x1, 250 + 130, 400 + x1, 250 + y1);
	outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 700, hienThiTrang);
}

void TimKiemMaSach(int mapID[][hight], int dangXoa, DanhSachDauSach &dS, DanhMucSach &dMS, DanhSachMuonTra dSMT){
	setfillstyle(2, 2);
	setbkcolor(15);
	setcolor(0);
	outtextxy(400, 280, "Nhap ma sach");
	setfillstyle(1, 4);
	veTimKiem(mapID);
	///////////////////////////
	setbkcolor(15);
	setcolor(0);
	int h = 0;
	int totalPage = 0;
	if(dMS.SLDms % 5 == 0)
		totalPage = dMS.SLDms/5;
	else
		totalPage = dMS.SLDms/5 + 1;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	int y1 = 0;
	// Ve Bang
	if(dMS.SLDms < 6)
	{
		HienThiDanhSachMucSachSuaXoa(pageCurent, totalPage, hienThiTrang, dS,dMS, dMS.SLDms, y1, h);
	}
	else
	{
		SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 50, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + 50 + textheight("back"), 25, mapID);
		SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 50, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 50 + textheight("next"), 26, mapID);
		outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 50, "back");
		outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 50, "next");
		HienThiDanhSachMucSachSuaXoa(pageCurent, totalPage, hienThiTrang, dS, dMS, dMS.SLDms, y1, h);
	}
	int x, y;
	int IDXet = 0;
	int maSach = 0;
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				continue;
			}
			else if(IDXet == 21)
			{
				setbkcolor(15);
				setcolor(0);
				char s[5];
				memset(s, 0, 5);
				ConvertIntToChar(s, maSach);
				Input(405, 320, 1, 5, s, IDXet, mapID);
				if(s[0] == '\0')
					maSach = 0;
				else
					maSach = Convert(s);
			}
			else if(IDXet == 22)
			{
				MucSach *mucSach = findMucSachByID(maSach, dMS);
				if(mucSach == NULL)
				{
					MessageBox(NULL, "Muc sach khong ton tai!", "Thong Bao", MB_OK);
					continue;
				}
				
				if(dangXoa == 0)
				{
					xoaDanhSachMucSachSuaXoa(pageCurent, totalPage, hienThiTrang, dS, dMS, dMS.SLDms, y1, h);
					suaMucSach(0, 120, mapID, dS, mucSach);
					// Nhap tim kiem
					break;
				}
				else
				{
					if(!kiemTraMucSachXoa(maSach, dSMT))
					{
						MessageBox(NULL, "Muc sach da tung duoc muon khong the xoa!", "Thong Bao", MB_OK);
						continue;
					}
					if(MessageBox(NULL, "Ban co that su muon xoa muc sach nay", "Xac Nhan", MB_YESNO) == 6)
					{
						cout << maSach;
						xoaMucSach(mucSach->maSach, dS, dMS);
						MessageBox(NULL, "Xoa thanh cong!", "Thong Bao", MB_OK);
						break;
					}
				}	
			}
			else if(IDXet == 25)
			{
				//cout << "Vao";
				if(pageCurent > 0)
				{
					xoaDanhSachMucSachSuaXoa(pageCurent, totalPage, hienThiTrang, dS, dMS, dMS.SLDms, y1, h);
					pageCurent--;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachMucSachSuaXoa(pageCurent, totalPage, hienThiTrang, dS, dMS, dMS.SLDms, y1, h);
				}
			}
			else if(IDXet == 26)
			{
				//cout << "Vao!";
				if(pageCurent < totalPage - 1)
				{
					xoaDanhSachMucSachSuaXoa(pageCurent, totalPage, hienThiTrang, dS, dMS, dMS.SLDms, y1, h);
					pageCurent++;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachMucSachSuaXoa(pageCurent, totalPage, hienThiTrang, dS, dMS, dMS.SLDms, y1, h);
				}
			}
			else if(IDXet == 23)
				break;
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 22)
			{
				setfillstyle(1, 4);
				bar(640, 300, 740, 350);
				setbkcolor(4);
				setcolor(0);
				outtextxy(690 - textwidth("Tim")/2, 320, "Tim");
				setfillstyle(1, 3);
				bar(760, 300, 860, 350);
				setbkcolor(3);
				setcolor(0);
				outtextxy(810 - textwidth("Thoat")/2, 320, "Thoat");
			}
			else if(IDXet == 23)
			{
				setfillstyle(1, 3);
				bar(640, 300, 740, 350);
				setbkcolor(3);
				setcolor(0);
				outtextxy(690 - textwidth("Tim")/2, 320, "Tim");
				setfillstyle(1, 4);
				bar(760, 300, 860, 350);
				setbkcolor(4);
				setcolor(0);
				outtextxy(810 - textwidth("Thoat")/2, 320, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(640, 300, 740, 350);
				setbkcolor(3);
				setcolor(0);
				outtextxy(690 - textwidth("Tim")/2, 320, "Tim");
				bar(760, 300, 860, 350);
				outtextxy(810 - textwidth("Thoat")/2, 320, "Thoat");
			}
		}
		delay(100);
	}
	//xoaDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 1);
	SetID(400, 300, 600, 350, 0, mapID);
	SetID(640, 300, 740, 350, 0, mapID);
	SetID(760, 300, 860, 350, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 50, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + 50 + textheight("back"), 0, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 50, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 50 + textheight("next"), 0, mapID);
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	setfillstyle(1, 4);
	bar(30, 130 + 120, 230, 120 + 160);
	setbkcolor(4);
	setcolor(0);
	outtextxy(130 - textwidth("Quan ly dau sach")/2, 135 + 120, "Quan ly dau sach");
}


// Menu Quan ly dau sach
void QuanLyDauSach(int mapID[][hight], DanhSachDauSach &dS, int &idDMSMax, DanhMucSach &dMS, DanhSachMuonTra dSMT){
	int x, y;
	int IDXet = 0;
	VeThemXoaSuaDauSach(mapID);
	setbkcolor(15);
	setcolor(0);
	outtextxy(400 + 500 - textwidth("Quan ly dau sach")/2, 140, "Quan ly dau sach");
	int dangXoa = 0;
	int dangThem = 0;
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				continue;
			}
			else if(IDXet == 11)
			{
				if(dS.SLDauSach == MAXDAUSACH)
				{
					MessageBox(NULL, "So dau sach da dat so luong toi da!", "Thong Bao", MB_OK);
					continue;
				}
				DauSach *dauSach = new DauSach;
				dauSach->TenSach[0] = '\0';
				dauSach->TacGia[0] = '\0';
				dauSach->TheLoai[0] = '\0';
				dauSach->NamXB = 0;
				dauSach->SoTrang = 0;
				dauSach->ISBN[0] = '\0';
				dangThem = 1;
				setbkcolor(15);
				setcolor(0);
				outtextxy(400, 320, "Nhap IBSN");
				rectangle(400, 345, 600, 395);
				SetID(400, 345, 600, 395, 26, mapID);
				NhapDauSach(0, 120, mapID, dangThem, dS, dauSach, idDMSMax, dMS);
				SetID(400, 345, 600, 395, 0, mapID);
				VeThemXoaSuaDauSach(mapID);
				setbkcolor(15);
				setcolor(0);
				outtextxy(400 + 500 - textwidth("Quan ly dau sach")/2, 140, "Quan ly dau sach");
			}
			else if(IDXet == 12)
			{
				dangThem = 0;
				dangXoa = 0;
				TimKiemDauSach(mapID, dangXoa, dangThem, dS, idDMSMax, dMS, dSMT);
				VeThemXoaSuaDauSach(mapID);
				setbkcolor(15);
				setcolor(0);
				outtextxy(400 + 500 - textwidth("Quan ly dau sach")/2, 140, "Quan ly dau sach");
			}
			else if(IDXet == 13)
			{
				dangThem = 0;
				dangXoa = 1;
				TimKiemDauSach(mapID, dangXoa, dangThem, dS, idDMSMax, dMS, dSMT);
				VeThemXoaSuaDauSach(mapID);
				setbkcolor(15);
				setcolor(0);
				outtextxy(400 + 500 - textwidth("Quan ly dau sach")/2, 140, "Quan ly dau sach");
			}
			else if(IDXet == 34)
			{
				TimKiemMaSach(mapID, 0, dS, dMS, dSMT);
				VeThemXoaSuaDauSach(mapID);
				setbkcolor(15);
				setcolor(0);
				outtextxy(400 + 500 - textwidth("Quan ly dau sach")/2, 140, "Quan ly dau sach");
			}
			else if(IDXet == 35)
			{
				TimKiemMaSach(mapID, 1, dS, dMS, dSMT);
				VeThemXoaSuaDauSach(mapID);
				setbkcolor(15);
				setcolor(0);
				outtextxy(400 + 500 - textwidth("Quan ly dau sach")/2, 140, "Quan ly dau sach");
			}
			else if(IDXet == 14)
				break;
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			ThayDoiThemXoaSuaDauSach(IDXet);
		}
		delay(100);
	}
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	XoaIDThemXoaSuaDauSach(mapID);
}
///////////////////////////////////////////////////////

// Tim kiem dau sach

void HienThiDanhSachMucSach(int pageCurent, int totalPage, char hienThiTrang[], DanhMucSach *dS, int sl, int y1, int h){
	y1 = 0;
	MucSach *p = dS->pHead;
	for(int i =0; i < 6*pageCurent; i++)
	{
		p = p->pNext;
	}
		
	for(int i = 0; i < 6; i++)
	{
		
		if(p == NULL)
			break;
		line(400, 280 + y1, 1150, 280 + y1);
		h = 0;
			//outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i].phai);
		char outPut[5];
		memset(outPut, 0, 5);
		ConvertIntToChar(outPut, p->maSach);
		outtextxy(400 + 10, 250 + 50 + 50 + y1, outPut);
		h += 150;
		outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, p->ViTri);
		h += 450;
		if(p->TrangThai == 0)
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "Muon duoc");
		else if(p->TrangThai == 1)
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "Duoc muon");
		else
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "Thanh ly");
		//outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, outPut);
		y1 += 50;
		p = p->pNext;
	}
	int x1 = 0;
	line(400, 280 + y1, 1150, 280 + y1);
	y1+=50;
	line(400, 280 + y1, 1150, 280 + y1);
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 150;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 450;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 150;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	char page[8];
	page[0] = '\0';
	char tmp[4];
	ConvertIntToChar(tmp, pageCurent + 1);
	strcat(page, tmp);
	strcat(page, "/");
	memset(tmp, 0, 4);
	ConvertIntToChar(tmp, totalPage);
	strcat(page, tmp);
	strcat(hienThiTrang, page);
	outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 680, hienThiTrang);
}

void xoaDanhSachMucSach(int pageCurent, int totalPage, char hienThiTrang[], DanhMucSach *dS, int sl, int y1, int h){
	setbkcolor(15);
	setcolor(15);
	y1 = 0;
	MucSach *p = dS->pHead;
	for(int i =0; i < 6*pageCurent; i++)
		p = p->pNext;
	for(int i = 0; i < 6; i++)
	{
		if(p == NULL)
			break;
		line(400, 280 + y1, 1150, 280 + y1);
		h = 0;
			//outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i].phai);
		char outPut[5];
		memset(outPut, 0, 5);
		ConvertIntToChar(outPut, p->maSach);
		outtextxy(400 + 10, 250 + 50 + 50 + y1, outPut);
		h += 150;
		outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, p->ViTri);
		h += 450;
		if(p->TrangThai == 0)
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "Muon duoc");
		else if(p->TrangThai == 1)
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "Duoc muon");
		else
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "Thanh ly");
		y1 += 50;
		p = p->pNext;
	}
	int x1 = 0;
	line(400, 280 + y1, 1150, 280 + y1);
	y1+=50;
	line(400, 280 + y1, 1150, 280 + y1);
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 150;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 450;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 150;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 680, hienThiTrang);
}

void hienThiThongTinDauSach(int mapID[][hight], DauSach *dauSach){
	setfillstyle(1, 3);
	bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
	setbkcolor(3);
	setcolor(0);
	outtextxy(405, 205, "Thoat");
	setbkcolor(15);
	SetID(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230, 11, mapID);
	outtextxy(400 + 500 - textwidth("Tim Thong Tin Dau Sach")/2, 140, "Tim Thong Tin Dau Sach");
	outtextxy(405, 205, "Thoat");
	// Xuat du lieu sach
	char tmp[100];
	tmp[0] = '\0';
	char convertSo[6];
	int xuatHien = 0;
	strcat(tmp, "ISBN: ");
	strcat(tmp, dauSach->ISBN);
	outtextxy(550, 205, tmp);
	xuatHien = 550 + textwidth(tmp) + 50;
	memset(tmp, 0, 100);
	strcat(tmp, "Ten sach: ");
	strcat(tmp, dauSach->TenSach);
	outtextxy(xuatHien, 205, tmp);
	xuatHien = xuatHien + textwidth(tmp) + 50;
	memset(tmp, 0, 100);
	strcat(tmp, "Nam XB: ");
	memset(convertSo, 0, 6);
	ConvertIntToChar(convertSo, dauSach->NamXB);
	strcat(tmp, convertSo);
	outtextxy(xuatHien, 205, tmp);
	xuatHien = xuatHien + textwidth(tmp) + 50;
	memset(tmp, 0, 100);
	strcat(tmp, "Tac gia: ");
	strcat(tmp, dauSach->TacGia);
	outtextxy(550, 235, tmp);
	xuatHien = 550 + textwidth(tmp) + 50;
	memset(tmp, 0, 100);
	strcat(tmp, "The loai: ");
	strcat(tmp, dauSach->TheLoai);
	outtextxy(xuatHien, 235, tmp);
	
	
	int totalPage = 0;
	if(dauSach->dMS->SLDms % 6 == 0)
		totalPage = dauSach->dMS->SLDms/6;
	else
		totalPage = dauSach->dMS->SLDms/6 + 1;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	int y1 = 0;
	int h = 0;
	//cout << dauSach->dMS->SLDms;
	if(dauSach->dMS->SLDms == 0)
		outtextxy(400 + 500 - textwidth("Dau sach khong ton tai muc sach!")/2, 400, "Dau sach khong ton tai muc sach!");
	else
		if(dauSach->dMS->SLDms < 7)
		{
			// In du lieu
			h = 0;
			outtextxy(400 + 10 + h, 250 + 50, "Ma Sach");
			h += 150;
			outtextxy(400 + 10 + h, 250 + 50, "Vi Tri");
			h += 450;
			outtextxy(400 + 10 + h, 250 + 50, "Trang Thai");
			HienThiDanhSachMucSach(pageCurent, totalPage, hienThiTrang, dauSach->dMS, dauSach->dMS->SLDms, y1, h);
			
		}
		else
		{
			h = 0;
			outtextxy(400 + 10 + h, 250 + 50, "Ma Sach");
			h += 150;
			outtextxy(400 + 10 + h, 250 + 50, "Vi Tri");
			h += 450;
			outtextxy(400 + 10 + h, 250 + 50, "Trang Thai");
			SetID(400 + 500 - textwidth("Trang 1/1") - 30, 680, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),680 + textheight("back"), 12, mapID);
			SetID(400 + 500 + textwidth("Trang 1/1") + 10, 680, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 680 + textheight("next"), 13, mapID);
			outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 680, "back");
			outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 680, "next");
			HienThiDanhSachMucSach(pageCurent, totalPage, hienThiTrang, dauSach->dMS, dauSach->dMS->SLDms, y1, h);
		}
	int x, y;
	int IDXet = 0;
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				//VeThemXoaSua(mapID);
				continue;
			}
			else if(IDXet == 11)
			{
				break;
			}
			else if(IDXet == 12)
			{
				//cout << "Vao";
				if(pageCurent > 0)
				{
					xoaDanhSachMucSach(pageCurent, totalPage, hienThiTrang, dauSach->dMS, dauSach->dMS->SLDms, y1, h);
					pageCurent--;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachMucSach(pageCurent, totalPage, hienThiTrang, dauSach->dMS, dauSach->dMS->SLDms, y1, h);
					//DrawMenu();
				}
			}
			else if(IDXet == 13)
			{
				//cout << "Vao!";
				if(pageCurent < totalPage - 1)
				{
					xoaDanhSachMucSach(pageCurent, totalPage, hienThiTrang, dauSach->dMS, dauSach->dMS->SLDms, y1, h);
					pageCurent++;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachMucSach(pageCurent, totalPage, hienThiTrang, dauSach->dMS, dauSach->dMS->SLDms, y1, h);
					//DrawMenu();
				}
			}
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			//IDtruoc = IDXet;
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 11)
			{
				setfillstyle(1, 4);
				bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(4);
				setcolor(0);
				outtextxy(405, 205, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(3);
				setcolor(0);
				outtextxy(405, 205, "Thoat");
			}
		}
		delay(100);
	}
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	SetID(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 680, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),680 + textheight("back"), 12, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 680, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 680 + textheight("next"), 13, mapID);
}

// Tim thong tin sach
void TimThongTinSach(int mapID[][hight], DanhSachDauSach dS){
	setfillstyle(2, 2);
	setbkcolor(15);
	setcolor(0);
	outtextxy(400, 180, "Nhap Ten Sach");
	setfillstyle(1, 4);
	veTimKiemDon(mapID);
	setbkcolor(15);
	setcolor(0);
	outtextxy(400 + 500 - textwidth("Tim Thong Tin Dau Sach")/2, 140, "Tim Thong Tin Dau Sach");
	
	///////////////////////////
	setbkcolor(15);
	setcolor(0);
	int h = 0;
	int totalPage = 0;
	if(dS.SLDauSach % 6)
		totalPage = dS.SLDauSach/6;
	else
		totalPage = dS.SLDauSach/6 + 1;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	int y1 = 0;
	// Ve Bang
	if(dS.SLDauSach < 7)
	{
		HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
	}
	else
	{
		SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 , 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + textheight("back"), 25, mapID);
		SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + textheight("next"), 26, mapID);
		outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 650, "back");
		outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 650, "next");
		HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
	}
	
	int x, y;
	int IDXet = 0;
	char ten[100];
	ten[0] = '\0';
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				continue;
			}
			else if(IDXet == 22)
			{
				int timKiem = timKiemNhiPhan(0, dS.SLDauSach - 1, dS, ten);
				if(timKiem == -1)
				{
					MessageBox(NULL, "Dau sach khong ton tai!", "Thong Bao", MB_OK);
				}
				else
				{
					SetID(400, 200, 700, 250, 0, mapID);
					SetID(740, 200, 840, 250, 0, mapID);
					SetID(860, 200, 960, 250, 0, mapID);
					SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + 30 + textheight("back"), 0, mapID);
					SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30 + textheight("next"), 0, mapID);
					//setbkcolor(15);
					setbkcolor(15);
					cleardevice();
					setcolor(0);
					DrawMenu();
					setfillstyle(1, 4);
					bar(30, 130 + 240, 230, 240 + 160);
					setbkcolor(4);
					setcolor(0);
					outtextxy(130 - textwidth("Tim thong tin sach")/2, 135 + 240, "Tim thong tin sach");
					outtextxy(400 + 500 - textwidth("Tim Thong Tin Dau Sach")/2, 140, "Tim Thong Tin Dau Sach");
					hienThiThongTinDauSach(mapID, dS.danhSachDauSach[timKiem]);
					return;
				}
			}
			else if(IDXet == 21)
			{
				setbkcolor(15);
				setcolor(0);
				Input(405, 220, 3, 100, ten, IDXet, mapID);
			}
			else if(IDXet == 25)
			{
				//cout << "Vao";
				if(pageCurent > 0)
				{
					xoaDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
					pageCurent--;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
					
				}
			}
			else if(IDXet == 26)
			{
				//cout << "Vao!";
				if(pageCurent < totalPage - 1)
				{
					xoaDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
					pageCurent++;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
				}
			}
			else if(IDXet == 23)
				break;
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 22)
			{
				setfillstyle(1, 4);
				bar(740, 200, 840, 250);
				setbkcolor(4);
				setcolor(0);
				outtextxy(790 - textwidth("Tim")/2, 220, "Tim");
				setfillstyle(1, 3);
				bar(860, 200, 960, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(910 - textwidth("Thoat")/2, 220, "Thoat");
			}
			else if(IDXet == 23)
			{
				setfillstyle(1, 3);
				bar(740, 200, 840, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(790 - textwidth("Tim")/2, 220, "Tim");
				setfillstyle(1, 4);
				bar(860, 200, 960, 250);
				setbkcolor(4);
				setcolor(0);
				outtextxy(910 - textwidth("Thoat")/2, 220, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(740, 200, 840, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(790 - textwidth("Tim")/2, 220, "Tim");
				bar(860, 200, 960, 250);
				outtextxy(910 - textwidth("Thoat")/2, 220, "Thoat");
			}
		}
		delay(100);
	}
	SetID(400, 200, 700, 250, 0, mapID);
	SetID(740, 200, 840, 250, 0, mapID);
	SetID(860, 200, 960, 250, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + 30 + textheight("back"), 0, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30 + textheight("next"), 0, mapID);
	//setbkcolor(15);
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
}

// ================================ Muon Sach ============================================//


void HienThiDanhSachMuonTra(int pageCurent, int totalPage, char hienThiTrang[], DanhSachMuonTra *dS, int sl, int y1, int h){
	y1 = 0;
	MuonTra *p = dS->pHead;
	for(int i =0; i < 6*pageCurent; i++)
		p = p->pNext;
	for(int i = 0; i < 6; i++)
	{
		if(i + 6*pageCurent >= sl)
			break;
		line(400, 280 + y1, 1200, 280 + y1);
		h = 0;
		//outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i].phai);
		char outPut[5];
		ConvertIntToChar(outPut, p->maSach);
		outtextxy(400 + 10, 250 + 50 + 50 + y1, outPut);
		h += 150;
		outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, p->NgayMuon);
		h += 250;
		outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, p->NgayTra);
		h+=250;
		//memset(outPut, 0, 5);
		if(p->trangThai == 0)
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "chua tra");
		else if(p->trangThai == 1)
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "da tra");
		else
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "lam mat");
		y1 += 50;
		p = p->pNext;
	}
	int x1 = 0;
	line(400, 280 + y1, 1200, 280 + y1);
	y1+=50;
	line(400, 280 + y1, 1200, 280 + y1);
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 150;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 250;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 250;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 150;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	char page[8];
	page[0] = '\0';
	char tmp[4];
	ConvertIntToChar(tmp, pageCurent + 1);
	strcat(page, tmp);
	strcat(page, "/");
	memset(tmp, 0, 4);
	ConvertIntToChar(tmp, totalPage);
	strcat(page, tmp);
	strcat(hienThiTrang, page);
	outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650, hienThiTrang);
}

void xoaDanhSachMuonTra(int pageCurent, int totalPage, char hienThiTrang[], DanhSachMuonTra *dS, int sl, int y1, int h){
	setbkcolor(15);
	setcolor(15);
	y1 = 0;
	MuonTra *p = dS->pHead;
	for(int i =0; i < 6*pageCurent; i++)
		p = p->pNext;
	for(int i = 0; i < 6; i++)
	{
		if(i + 6*pageCurent >= sl)
			break;
		line(400, 280 + y1, 1200, 280 + y1);
		h = 0;
		//outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i].phai);
		char outPut[5];
		ConvertIntToChar(outPut, p->maSach);
		outtextxy(400 + 10, 250 + 50 + 50 + y1, outPut);
		h += 150;
		outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, p->NgayMuon);
		h += 250;
		outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, p->NgayTra);
		h+=250;
		if(p->trangThai == 0)
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "chua tra");
		else if(p->trangThai == 1)
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "da tra");
		else
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "lam mat");
		y1 += 50;
		p = p->pNext;
	}
	int x1 = 0;
	line(400, 280 + y1, 1200, 280 + y1);
	y1+=50;
	line(400, 280 + y1, 1200, 280 + y1);
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 150;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 250;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 250;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 150;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650, hienThiTrang);
}

void hienThiDanhSachMucSachMuon(int pageCurent, int totalPage, char hienThiTrang[], DanhMucSach dMS, DanhSachDauSach dSDS, int sl, int y1, int h){
	y1 = 0;
	MucSach *p = dMS.pHead;
	for(int i =0; i < 6*pageCurent; i++)
		p = p->pNext;
	for(int i = 0; i < 6; i++)
	{
		if(i + 6*pageCurent >= sl)
			break;
		line(400, 280 + y1, 1300, 280 + y1);
		h = 0;
		//outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i].phai);
		char outPut[5];
		ConvertIntToChar(outPut, p->maSach);
		outtextxy(400 + 10, 250 + 50 + 50 + y1, outPut);
		h += 150;
		DauSach *dauSach = findDauSachTheoMaSach(dSDS, p->maSach);
		outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, dauSach->TenSach);
		h += 400;
		outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, dauSach->TheLoai);
		h+=200;
		//memset(outPut, 0, 5);
		if(p->TrangThai == 0)
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "Muon duoc");
		else if(p->TrangThai == 1)
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "Dang muon");
		else
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "Thanh ly");
		y1 += 50;
		p = p->pNext;
	}
	int x1 = 0;
	line(400, 280 + y1, 1300, 280 + y1);
	y1+=50;
	line(400, 280 + y1, 1300, 280 + y1);
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 150;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 400;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 200;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 150;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	char page[8];
	page[0] = '\0';
	char tmp[4];
	ConvertIntToChar(tmp, pageCurent + 1);
	strcat(page, tmp);
	strcat(page, "/");
	memset(tmp, 0, 4);
	ConvertIntToChar(tmp, totalPage);
	strcat(page, tmp);
	strcat(hienThiTrang, page);
	outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650 + 30, hienThiTrang);
}

void xoaHienThiDanhMucSachMuon(int pageCurent, int totalPage, char hienThiTrang[], DanhMucSach dMS, DanhSachDauSach dSDS, int sl, int y1, int h){
	setbkcolor(15);
	setcolor(15);
	y1 = 0;
	MucSach *p = dMS.pHead;
	for(int i =0; i < 6*pageCurent; i++)
		p = p->pNext;
	for(int i = 0; i < 6; i++)
	{
		if(i + 6*pageCurent >= sl)
			break;
		line(400, 280 + y1, 1300, 280 + y1);
		h = 0;
		//outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i].phai);
		char outPut[5];
		ConvertIntToChar(outPut, p->maSach);
		outtextxy(400 + 10, 250 + 50 + 50 + y1, outPut);
		h += 150;
		DauSach *dauSach = findDauSachTheoMaSach(dSDS, p->maSach);
		outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, dauSach->TenSach);
		h += 400;
		outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, dauSach->TheLoai);
		h+=200;
		//memset(outPut, 0, 5);
		if(p->TrangThai == 0)
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "Muon duoc");
		else if(p->TrangThai == 1)
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "Dang muon");
		else
			outtextxy(400 + 10 + h, 250 + 50 + 50 + y1, "Thanh ly");
		y1 += 50;
		p = p->pNext;
	}
	int x1 = 0;
	line(400, 280 + y1, 1300, 280 + y1);
	y1+=50;
	line(400, 280 + y1, 1300, 280 + y1);
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 150;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 400;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 200;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	x1 += 150;
	line(400 + x1, 280, 400 + x1, 280 + y1);
	outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650 + 30, hienThiTrang);
}

void nhapMuonSach(int x, int y, DanhSachMuonTra *dS, int mapID[][hight], DanhSachMuonTra &dSMT, DanhSachDauSach &dSDS, DanhMucSach &dMS){
	setbkcolor(15);
	setcolor(0);
	outtextxy(400 + x, 180 + y, "Nhap ma sach");
	rectangle(400 + x, 200 + y, 600 + x, 250 + y);
	
	outtextxy(650 + x, 180 + y, "Ngay muon");
	rectangle(650 + x, 200 + y, 690 + x, 250 + y);
	outtextxy(696 + x, 220 + y, "-");
	rectangle(710 + x, 200 + y, 750 + x, 250 + y);
	outtextxy(756 + x, 220 + y, "-");
	rectangle(770 + x, 200 + y, 850 + x, 250 + y);
	
	outtextxy(900 + x, 180 + y, "Ngay tra");
	rectangle(900 + x, 200 + y, 940 + x, 250 + y);
	outtextxy(948 + x, 220 + y, "-");
	rectangle(960 + x, 200 + y, 1000 + x, 250 + y);
	outtextxy(1008 + x, 220 + y, "-");
	rectangle(1020 + x, 200 + y, 1100 + x, 250 + y);
	
	outtextxy(400 + 500 - textwidth("Quan Ly Muon Sach")/2, 140, "Quan Ly Muon Sach");
	setfillstyle(1, 3);
	bar(1150 + x, 200 + y, 1250 + x, 250 + y);
	bar(1300 + x, 200 + y, 1400 + x, 250 + y);
	setbkcolor(3);
	setcolor(0);
	outtextxy(1200 - textwidth("Luu")/2 + x, 220 + y, "Luu");
	outtextxy(1350 - textwidth("Thoat")/2 + x, 220 + y, "Thoat");
	//ma
	SetID(400 + x, 200 + y, 600 + x, 250 + y, 15, mapID);
	// ngay muon
	SetID(650 + x, 200 + y, 690 + x, 250 + y, 16, mapID);
	// thang muon
	SetID(710 + x, 200 + y, 750 + x, 250 + y, 17, mapID);
	// nam muon
	SetID(770 + x, 200 + y, 850 + x, 250 + y, 18, mapID);
	// ngay tra
	SetID(900 + x, 200 + y, 940 + x, 250 + y, 21, mapID);
	// thang tra
	SetID(960 + x, 200 + y, 1000 + x, 250 + y, 22, mapID);
	// nam tra
	SetID(1020 + x, 200 + y, 1100 + x, 250 + y, 23, mapID);
	// them
	SetID(1150 + x, 200 + y, 1250 + x, 250 + y, 19, mapID);
	// thoat
	SetID(1300 + x, 200 + y, 1400 + x, 250 + y, 20, mapID);
	
	int xt, yt;
	int IDXet = 0;
	MuonTra *p = new MuonTra;
	MuonTra *q = new MuonTra;
	memset(q->NgayMuon, 0, 11);
	memset(q->NgayTra, 0, 11);
	p->maSach = 0;
	memset(p->NgayMuon, 0, 11);
	memset(p->NgayTra, 0, 11);
	// In du lieu
	setbkcolor(15);
	setcolor(0);
	int h = 0;
	outtextxy(400 + 10 + h, 250 + 50, "Ma Sach");
	h += 150;
	outtextxy(400 + 10 + h, 250 + 50, "Ten sach");
	h += 400;
	outtextxy(400 + 10 + h, 250 + 50, "The loai");
	h += 200;
	outtextxy(400 + 10 + h, 250 + 50, "Trang Thai");
	int totalPage = dMS.SLDms/7 + 1;
	if(dMS.SLDms % 6 == 0)
		totalPage = dMS.SLDms/6;
	else
		totalPage = dMS.SLDms/6 + 1;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	int y1 = 0;
	// Ve Bang
	if(dMS.SLDms < 7)
	{
		
		hienThiDanhSachMucSachMuon(pageCurent, totalPage, hienThiTrang, dMS, dSDS, dMS.SLDms, y1, h);
	}
	else
	{
		SetID(400 + 500 - textwidth("Trang 1/1") - 30, 680, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),680 + textheight("back"), 31, mapID);
		SetID(400 + 500 + textwidth("Trang 1/1") + 10, 680, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 680 + textheight("next"), 32, mapID);
		outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 680, "back");
		outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 680, "next");
		hienThiDanhSachMucSachMuon(pageCurent, totalPage, hienThiTrang, dMS, dSDS, dMS.SLDms, y1, h);
	}
	Ngay dateMuon;
	Ngay dateTra;
	dateMuon.ngay = 0;
	dateMuon.thang = 0;
	dateMuon.nam = 0;
	dateTra.thang = 0;
	dateTra.nam = 0;
	dateTra.ngay = 0;
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, xt, yt);
			IDXet = mapID[xt][yt];
			clearmouseclick(WM_LBUTTONDOWN);
			setbkcolor(15);
			setcolor(0);
			if(IDXet == 0)
			{
				continue;
			}
			else if(IDXet == 19)
			{
				if(checkNgayDauVao(dateMuon) != 0 || checkNgayDauVao(dateTra) != 0)
				{
					if(checkNgayDauVao(dateMuon) == 1 || checkNgayDauVao(dateTra) == 1)
						MessageBox(NULL, "Sai dinh dang ngay!", "Thong Bao", MB_OK);
					else if(checkNgayDauVao(dateMuon) == 2 || checkNgayDauVao(dateTra) == 2)
						MessageBox(NULL, "Vui long nhap thang nho hon 12!", "Thong Bao", MB_OK);
					else if(checkNgayDauVao(dateMuon) == 3 || checkNgayDauVao(dateTra) == 3)
						MessageBox(NULL, "Vui long nhap nam khong am!", "Thong Bao", MB_OK);
					else if(checkNgayDauVao(dateMuon) == 4 || checkNgayDauVao(dateTra) == 4)
						MessageBox(NULL, "Nhung thang 4, 6, 9, 11 chi co 30 ngay!", "Thong Bao", MB_OK);
					else if(checkNgayDauVao(dateMuon) == 5 || checkNgayDauVao(dateTra) == 5)
						MessageBox(NULL, "Thang 2 chi co toi da 29 ngay!", "Thong Bao", MB_OK);
					else if(checkNgayDauVao(dateMuon) == 6 || checkNgayDauVao(dateTra) == 6)
						MessageBox(NULL, "Thang 2 chi co toi da 28 ngay!", "Thong Bao", MB_OK);
					continue;
				}
				if(!checkNgayMuon(dateMuon, dateTra))
				{
					MessageBox(NULL, "Vui long nhap ngay tra lon hon ngay muon!", "Thong Bao", MB_OK);
					continue;
				}
				int check = checkMaSachThemMuon(dSDS, p->maSach);
				if(check != 3)
				{
					if(check == 0)
						MessageBox(NULL, "Ma sach khong ton tai", "Thong Bao", MB_OK);
					else if(check == 1)
						MessageBox(NULL, "Sach da bi thanh ly", "Thong Bao", MB_OK);
					else
						MessageBox(NULL, "Sach da co nguoi muon", "Thong Bao", MB_OK);
					continue;
				}
				if(checkHaiSachChungDauSach(p->maSach, dS, dSDS))
				{
					MessageBox(NULL, "Khong the muon 2 sach cung dau sach", "Thong Bao", MB_OK);
					continue;
				}
				//cout << dateTra.ngay;
				char tmp[4];
				tmp[0] = '\0';
				ConvertIntToChar(tmp, dateMuon.ngay);
				strcat(p->NgayMuon, tmp);
				strcat(p->NgayMuon, "-");
				memset(tmp, 0, 4);	
				ConvertIntToChar(tmp, dateMuon.thang);
				strcat(p->NgayMuon, tmp);
				strcat(p->NgayMuon, "-");
				memset(tmp, 0, 4);	
				int ngayTra = dateTra.ngay;
				ConvertIntToChar(tmp, dateMuon.nam);
				//cout << dateTra.ngay;
				
				strcat(p->NgayMuon, tmp);
				memset(tmp, 0, 4);
				cout << p->NgayMuon << endl;
				// Ngay tra
				
				ConvertIntToChar(tmp, ngayTra);
				strcat(p->NgayTra, tmp);
				strcat(p->NgayTra, "-");
				memset(tmp, 0, 4);	
				ConvertIntToChar(tmp, dateTra.thang);
				strcat(p->NgayTra, tmp);
				strcat(p->NgayTra, "-");
				memset(tmp, 0, 4);	
				ConvertIntToChar(tmp, dateTra.nam);
				
				//cout << dateMuon.ngay;
				strcat(p->NgayTra, tmp);
				memset(tmp, 0, 4);
				q->maSach = p->maSach;
				q->pNext = NULL;
				q->prev = NULL;
				p->pNext = NULL;
				p->prev = NULL;
				memcpy(q->NgayMuon, p->NgayMuon, 11);
				memcpy(q->NgayTra, p->NgayTra, 11);
				q->trangThai = p->trangThai = 0;
				//cout << q->NgayMuon << endl;
				capNhatMuon(dMS, dSDS, dSMT, dS, p, q);
				//cout << dSMT.SLDS;
				MessageBox(NULL, "Them Thanh Cong", "Thong Bao", MB_OK);
				break;
			}
			else if(IDXet == 15)
			{
				maSachMuonSach:
				char S[6];
				memset(S, 0, 6);
				ConvertIntToChar(S, p->maSach);
				//outtextxy(405 + x, 220 + y, S);	
				Input(405 + x, 220 + y, 1, 6,S, IDXet, mapID);
				if(S[0] == '\0')
					p->maSach = 0;
				else
					p->maSach = Convert(S);
				if(IDXet == 16)
					goto ngayMuonMuonSach;
				else if(IDXet == 17)
					goto thangMuonMuonSach;
				else if(IDXet == 18)
					goto namMuonMuonSach;
				else if(IDXet == 21)
					goto ngayTraMuonSach;
				else if(IDXet == 22)
					goto thangTraMuonSach;
				else if(IDXet == 23)
					goto namTraMuonSach;
			}
			else if(IDXet == 16)
			{
				ngayMuonMuonSach:
				// ngay muon
				char S[2];
				S[0] = '\0';
				ConvertIntToChar(S, dateMuon.ngay);
				Input(655 + x, 220 + y, 1, 2, S, IDXet, mapID);
				if(S[0] == '\0')
					dateMuon.ngay = 0;
				else
					dateMuon.ngay = Convert(S);
				if(IDXet == 15)
					goto maSachMuonSach;
				else if(IDXet == 17)
					goto thangMuonMuonSach;
				else if(IDXet == 18)
					goto namMuonMuonSach;
				else if(IDXet == 21)
					goto ngayTraMuonSach;
				else if(IDXet == 22)
					goto thangTraMuonSach;
				else if(IDXet == 23)
					goto namTraMuonSach;
			}
			else if(IDXet == 17)
			{
				thangMuonMuonSach:
				char S[2];
				S[0] = '\0';
				ConvertIntToChar(S, dateMuon.thang);
				Input(715 + x, 220 + y, 1, 2, S, IDXet, mapID);
				if(S[0] == '\0')
					dateMuon.thang = 0;
				else
					dateMuon.thang = Convert(S);
				if(IDXet == 15)
					goto maSachMuonSach;
				else if(IDXet == 16)
					goto ngayMuonMuonSach;
				else if(IDXet == 18)
					goto namMuonMuonSach;
				else if(IDXet == 21)
					goto ngayTraMuonSach;
				else if(IDXet == 22)
					goto thangTraMuonSach;
				else if(IDXet == 23)
					goto namTraMuonSach;
			}
			else if(IDXet == 18)
			{
				namMuonMuonSach:
				char S[4];
				S[0] = '\0';
				ConvertIntToChar(S, dateMuon.nam);
				Input(775 + x, 220 + y, 1, 4, S, IDXet, mapID);
				if(S[0] == '\0')
					dateMuon.nam = 0;
				else
					dateMuon.nam = Convert(S);
				if(IDXet == 15)
					goto maSachMuonSach;
				else if(IDXet == 17)
					goto thangMuonMuonSach;
				else if(IDXet == 16)
					goto ngayMuonMuonSach;
				else if(IDXet == 21)
					goto ngayTraMuonSach;
				else if(IDXet == 22)
					goto thangTraMuonSach;
				else if(IDXet == 23)
					goto namTraMuonSach;
			}
			else if(IDXet == 21)
			{
				ngayTraMuonSach:
				char S[2];
				S[0] = '\0';
				cout << dateTra.ngay;
				ConvertIntToChar(S, dateTra.ngay);
				Input(905 + x, 220 + y, 1, 2, S, IDXet, mapID);
				if(S[0] == '\0')
					dateTra.ngay = 0;
				else
					dateTra.ngay = Convert(S);
				//cout << dateTra.ngay;
				if(IDXet == 15)
					goto maSachMuonSach;
				else if(IDXet == 16)
					goto ngayMuonMuonSach;
				else if(IDXet == 18)
					goto namMuonMuonSach;
				else if(IDXet == 17)
					goto thangMuonMuonSach;
				else if(IDXet == 22)
					goto thangTraMuonSach;
				else if(IDXet == 23)
					goto namTraMuonSach;
				
			}
			else if(IDXet == 22)
			{
				thangTraMuonSach:
				char S[2];
				S[0] = '\0';
				ConvertIntToChar(S, dateTra.thang);
				Input(965 + x, 220 + y, 1, 2, S, IDXet, mapID);
				if(S[0] == '\0')
					dateTra.thang = 0;
				else
					dateTra.thang = Convert(S);
				if(IDXet == 15)
					goto maSachMuonSach;
				else if(IDXet == 16)
					goto ngayMuonMuonSach;
				else if(IDXet == 18)
					goto namMuonMuonSach;
				else if(IDXet == 21)
					goto ngayTraMuonSach;
				else if(IDXet == 17)
					goto thangMuonMuonSach;
				else if(IDXet == 23)
					goto namTraMuonSach;
			}
			else if (IDXet == 23)
			{
				namTraMuonSach:
				char S[4];
				S[0] = '\0';
				ConvertIntToChar(S, dateTra.nam);
				Input(1025 + x, 220 + y, 1, 4, S, IDXet, mapID);
				if(S[0] == '\0')
					dateTra.nam = 0;
				else
					dateTra.nam = Convert(S);
				if(IDXet == 15)
					goto maSachMuonSach;
				else if(IDXet == 16)
					goto ngayMuonMuonSach;
				else if(IDXet == 18)
					goto namMuonMuonSach;
				else if(IDXet == 21)
					goto ngayTraMuonSach;
				else if(IDXet == 22)
					goto thangTraMuonSach;
				else if(IDXet == 17)
					goto thangMuonMuonSach;
			}
			else if(IDXet == 31)
			{
				//cout << "Vao";
				if(pageCurent > 0)
				{
					xoaHienThiDanhMucSachMuon(pageCurent, totalPage, hienThiTrang, dMS, dSDS, dMS.SLDms, y1, h);
					pageCurent--;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					hienThiDanhSachMucSachMuon(pageCurent, totalPage, hienThiTrang, dMS, dSDS, dMS.SLDms, y1, h);
					//DrawMenu();
				}
			}
			else if(IDXet == 32)
			{
				//cout << "Vao!";
				if(pageCurent < totalPage - 1)
				{
					xoaHienThiDanhMucSachMuon(pageCurent, totalPage, hienThiTrang, dMS, dSDS, dMS.SLDms, y1, h);
					pageCurent++;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					hienThiDanhSachMucSachMuon(pageCurent, totalPage, hienThiTrang, dMS, dSDS, dMS.SLDms, y1, h);
					//DrawMenu();
				}
			}
			else if(IDXet == 20)
				break;
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, xt, yt);
			IDXet = mapID[xt][yt];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 19){
				setfillstyle(1, 4);
				bar(1150 + x, 200 + y, 1250 + x, 250 + y);
				setbkcolor(4);
				setcolor(0);
				outtextxy(1200 - textwidth("Luu")/2 + x, 220 + y, "Luu");
				
				setfillstyle(1, 3);
				bar(1300 + x, 200 + y, 1400 + x, 250 + y);
				setbkcolor(3);
				setcolor(0);
				outtextxy(1350 - textwidth("Thoat")/2 + x, 220 + y, "Thoat");
			}
			else if(IDXet == 20){
				setfillstyle(1, 3);
				bar(1150 + x, 200 + y, 1250 + x, 250 + y);
				setbkcolor(3);
				setcolor(0);
				outtextxy(1200 - textwidth("Luu")/2 + x, 220 + y, "Luu");
				
				setfillstyle(1, 4);
				bar(1300 + x, 200 + y, 1400 + x, 250 + y);
				setbkcolor(4);
				setcolor(0);
				outtextxy(1350 - textwidth("Thoat")/2 + x, 220 + y, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(1150 + x, 200 + y, 1250 + x, 250 + y);
				bar(1300 + x, 200 + y, 1400 + x, 250 + y);
				setbkcolor(3);
				setcolor(0);
				outtextxy(1200 - textwidth("Luu")/2 + x, 220 + y, "Luu");
				outtextxy(1350 - textwidth("Thoat")/2 + x, 220 + y, "Thoat");
			}
		}
		delay(100);
	}
	//ma
	SetID(400 + x, 200 + y, 600 + x, 250 + y, 0, mapID);
	// ngay muon
	SetID(650 + x, 200 + y, 690 + x, 250 + y, 0, mapID);
	// thang muon
	SetID(710 + x, 200 + y, 750 + x, 250 + y, 0, mapID);
	// nam muon
	SetID(770 + x, 200 + y, 850 + x, 250 + y, 0, mapID);
	// ngay tra
	SetID(900 + x, 200 + y, 940 + x, 250 + y, 0, mapID);
	// thang tra
	SetID(960 + x, 200 + y, 1000 + x, 250 + y, 0, mapID);
	// nam tra
	SetID(1020 + x, 200 + y, 1100 + x, 250 + y, 0, mapID);
	// them
	SetID(1150 + x, 200 + y, 1250 + x, 250 + y, 0, mapID);
	// thoat
	SetID(1300 + x, 200 + y, 1400 + x, 250 + y, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 680, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),680 + textheight("back"), 0, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 680, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 680 + textheight("next"), 0, mapID);
	//	outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 680, "back");
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
}

void hienThiThongTinDanhSachMuon(int mapID[][hight], DocGia *docGia, DanhSachMuonTra &dSMT, DanhSachDauSach &dSDS, DanhMucSach &dMS){
	
	setfillstyle(1, 3);
	setbkcolor(3);
	setcolor(0);
	bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
	//bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
	outtextxy(405, 205, "Thoat");

	bar(400, 240, 400 + 50 + textwidth("Muon sach") + 10, 270);
	outtextxy(405, 245, "Muon sach");
	// Xuat du lieu sach
	SetID(400, 240, 400 + 50 + textwidth("Muon sach") + 10, 270, 14, mapID);
	SetID(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230, 11, mapID);
	setbkcolor(15);
	setcolor(0);
	char tmp[100];
	tmp[0] = '\0';
	int xuatHien = 0;
	strcat(tmp, "Ho va ten: ");
	strcat(tmp, docGia->ho);
	strcat(tmp, " ");
	strcat(tmp, docGia->ten);
	outtextxy(550, 205, tmp);
	xuatHien = 550 + textwidth(tmp) + 50;
	memset(tmp, 0, 100);
	strcat(tmp, "Trang thai the: ");
	if(docGia->trangThaiThe == 0)
		strcat(tmp, "bi khoa.");
	else
		strcat(tmp, "dang hoat dong");
	outtextxy(xuatHien, 205, tmp);
	// In du lieu
	int h = 0;
	outtextxy(400 + 10 + h, 250 + 50, "Ma Sach");
	h += 150;
	outtextxy(400 + 10 + h, 250 + 50, "Ngay muon");
	h += 250;
	outtextxy(400 + 10 + h, 250 + 50, "Ngay tra");
	h += 250;
	outtextxy(400 + 10 + h, 250 + 50, "Trang Thai");
	int totalPage = 0;
	if(docGia->dSMuonTra->SLDS % 6 == 0)
		totalPage = docGia->dSMuonTra->SLDS/6;
	else
		totalPage = docGia->dSMuonTra->SLDS/6 + 1;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	int y1 = 0;
	// Ve Bang
	if(docGia->dSMuonTra->SLDS < 7)
	{
		HienThiDanhSachMuonTra(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, docGia->dSMuonTra->SLDS, y1, h);
	}
	else
	{
		SetID(400 + 500 - textwidth("Trang 1/1") - 30, 680, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),680 + textheight("back"), 12, mapID);
		SetID(400 + 500 + textwidth("Trang 1/1") + 10, 680, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 680 + textheight("next"), 13, mapID);
		outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 680, "back");
		outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 680, "next");
		HienThiDanhSachMuonTra(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, docGia->dSMuonTra->SLDS, y1, h);
	}
	int x, y;
	int IDXet = 0;
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				//VeThemXoaSua(mapID);
				continue;
			}
			else if(IDXet == 11)
			{
				break;
			}
			else if(IDXet == 12)
			{
				//cout << "Vao";
				if(pageCurent > 0)
				{
					xoaDanhSachMuonTra(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, docGia->dSMuonTra->SLDS, y1, h);
					pageCurent--;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachMuonTra(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, docGia->dSMuonTra->SLDS, y1, h);
					//DrawMenu();
				}
			}
			else if(IDXet == 13)
			{
				//cout << "Vao!";
				if(pageCurent < totalPage - 1)
				{
					xoaDanhSachMuonTra(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, docGia->dSMuonTra->SLDS, y1, h);
					pageCurent++;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachMuonTra(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, docGia->dSMuonTra->SLDS, y1, h);
					//DrawMenu();
				}
			}
			else if(IDXet == 14)
			{
				if(!checkThemMuonTraBa(docGia->dSMuonTra)){
					MessageBox(NULL, "Mot doc gia chi duoc phep muon to da 3 cuon sach!", "Thong Bao", MB_OK);
					continue;
				}
				if(docGia->trangThaiThe == 0){
					MessageBox(NULL, "The doc gia nay da bi khoa khong the muon sach!", "Thong Bao", MB_OK);
					continue;
				}
				setbkcolor(15);
				cleardevice();
				setcolor(0);
				DrawMenu();
				setfillstyle(1, 4);
				bar(30, 130 + 300, 230, 300 + 160);
				setbkcolor(4);
				setcolor(0);
				outtextxy(130 - textwidth("Quan ly muon sach")/2, 135 + 300, "Quan ly muon sach");
				SetID(400, 240, 400 + 50 + textwidth("Muon sach") + 10, 270, 0, mapID);
				SetID(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230, 0, mapID);
				SetID(400 + 500 - textwidth("Trang 1/1") - 30, 680, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),680 + textheight("back"), 12, mapID);
				SetID(400 + 500 + textwidth("Trang 1/1") + 10, 680, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 680 + textheight("next"), 13, mapID);
				nhapMuonSach(0, 0, docGia->dSMuonTra, mapID, dSMT, dSDS, dMS);
				cout << "qua";
				if(!kiemTraMuonBayNgay(docGia->dSMuonTra))
				{
					docGia->trangThaiThe = 0;
				}
				break;
			}
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			//IDtruoc = IDXet;
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 11)
			{
				setfillstyle(1, 4);
				bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(4);
				setcolor(0);
				outtextxy(405, 205, "Thoat");
				
				setfillstyle(1, 3);
				bar(400, 240, 400 + 50 + textwidth("Muon sach") + 10, 270);
				setbkcolor(3);
				setcolor(0);
				outtextxy(405, 245, "Muon sach");
			}
			else if(IDXet ==  14)
			{
				setfillstyle(1, 3);
				bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(3);
				setcolor(0);
				outtextxy(405, 205, "Thoat");
				
				setfillstyle(1, 4);
				bar(400, 240, 400 + 50 + textwidth("Muon sach") + 10, 270);
				setbkcolor(4);
				setcolor(0);
				outtextxy(405, 245, "Muon sach");
			}
			else
			{
				setfillstyle(1, 3);
				bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(3);
				setcolor(0);
				outtextxy(405, 205, "Thoat");
				bar(400, 240, 400 + 50 + textwidth("Muon sach") + 10, 270);
				outtextxy(405, 245, "Muon sach");
			}
		}
		delay(100);
	}
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	SetID(400, 240, 400 + 50 + textwidth("Muon sach") + 10, 270, 0, mapID);
	SetID(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 680, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),680 + textheight("back"), 12, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 680, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 680 + textheight("next"), 13, mapID);
}

// Muon sach 
void quanLyMuonSach(int mapID[][hight], DanhSachDocGia &dS, DanhSachMuonTra &dSMT, DanhSachDauSach &dSDS, DanhMucSach &dMS){
	quanLyMuonSach:
	setfillstyle(1, 4);
	bar(30, 130 + 300, 230, 300 + 160);
	setbkcolor(4);
	setcolor(0);
	outtextxy(130 - textwidth("Quan ly muon sach")/2, 135 + 300, "Quan ly muon sach");
	setfillstyle(2, 2);
	setbkcolor(15);
	setcolor(0);
	outtextxy(400, 180, "Nhap ma the doc gia");
	setfillstyle(1, 4);
	veTimKiemDon(mapID);
	setbkcolor(15);
	setcolor(0);
	outtextxy(400 + 500 - textwidth("Quan ly muon sach")/2, 140, "Quan ly muon sach");
	int h = 0;
	setbkcolor(15);
	setcolor(0);
	// Set Du Lieu
	int n = 0;
	//cout << ds.SLDocGia;
	DocGia *DSDG[dS.SLDocGia];
	ChuyenDoiDuLieuDocGia(dS.dsDocGia, DSDG, n);
	int y1;
	int totalPage = 0;
	if(dS.SLDocGia % 6 == 0)
		totalPage = dS.SLDocGia/6;
	else
		totalPage = dS.SLDocGia/6 + 1;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	if(dS.SLDocGia < 7)
	{	
		HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
	}
	else
	{
		SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"), 650 + 30 + textheight("back"), 25, mapID);
		SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30 + textheight("next"), 26, mapID);
		outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, "back");
		outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, "next");
		HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
	}
	int x, y;
	int IDXet = 0;
	int maThe = 0;
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				continue;
			}
			else if(IDXet == 22)
			{
				DocGia *dg = findDocGia(dS.dsDocGia, maThe);
				if(dg == NULL)
				{
					MessageBox(NULL, "Doc gia ton tai!", "Thong Bao", MB_OK);
					char S[5];
					setbkcolor(15);
					setcolor(15);
					ConvertIntToChar(S, maThe);
					outtextxy(405, 350, S);
					setbkcolor(15);
					setcolor(0);
					
				}
				else
				{
					SetID(400, 200, 700, 250, 0, mapID);
					SetID(740, 200, 840, 250, 0, mapID);
					SetID(860, 200, 960, 250, 0, mapID);
					setbkcolor(15);
					cleardevice();
					setcolor(0);
					DrawMenu();
					setfillstyle(1, 4);
					bar(30, 130 + 300, 230, 300 + 160);
					setbkcolor(4);
					setcolor(0);
					outtextxy(130 - textwidth("Quan ly muon sach")/2, 135 + 300, "Quan ly muon sach");
					setbkcolor(15);
					setcolor(0);
					outtextxy(400 + 500 - textwidth("Quan ly muon sach")/2, 140, "Quan ly muon sach");
					hienThiThongTinDanhSachMuon(mapID, dg, dSMT, dSDS, dMS);
					goto quanLyMuonSach;
				}
			}
			else if(IDXet == 21)
			{
				char S[5];
				S[0] = '\0';
				setbkcolor(15);
				setcolor(0);
				Input(405, 220, 1, 5, S, IDXet, mapID);
				if(S[0] == '\0')
				{
					maThe = -1;
				}
				else	
					maThe = Convert(S);
			}
			else if(IDXet == 25)
			{
				if(pageCurent == 0)
					continue;
				xoaHienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
				pageCurent--;
				setbkcolor(15);
				setcolor(0);
				int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
				memset(hienThiTrang, 0, length);
				strcat(hienThiTrang, "Trang ");
				HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
				//DrawMenu();
			}
			else if(IDXet == 26)
			{
				if(pageCurent == totalPage - 1)
					continue;
				xoaHienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
				pageCurent++;
				setbkcolor(15);
				setcolor(0);
				int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
				memset(hienThiTrang, 0, length);
				strcat(hienThiTrang, "Trang ");
				HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
				//DrawMenu();
			}
			else if(IDXet == 23)
				break;
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 22)
			{
				setfillstyle(1, 4);
				bar(740, 200, 840, 250);
				setbkcolor(4);
				setcolor(0);
				outtextxy(790 - textwidth("Tim")/2, 220, "Tim");
				setfillstyle(1, 3);
				bar(860, 200, 960, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(910 - textwidth("Thoat")/2, 220, "Thoat");
			}
			else if(IDXet == 23)
			{
				setfillstyle(1, 3);
				bar(740, 200, 840, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(790 - textwidth("Tim")/2, 220, "Tim");
				setfillstyle(1, 4);
				bar(860, 200, 960, 250);
				setbkcolor(4);
				setcolor(0);
				outtextxy(910 - textwidth("Thoat")/2, 220, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(740, 200, 840, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(790 - textwidth("Tim")/2, 220, "Tim");
				bar(860, 200, 960, 250);
				outtextxy(910 - textwidth("Thoat")/2, 220, "Thoat");
			}
		}
		delay(100);
	}
	SetID(400, 200, 700, 250, 0, mapID);
	SetID(740, 200, 840, 250, 0, mapID);
	SetID(860, 200, 960, 250, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"), 650 + 30 + textheight("back"), 0, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30 + textheight("next"), 0, mapID);
	//setbkcolor(15);
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
}

// Tra Sách


void hienThiThongTinDanhSachTra(int mapID[][hight], DocGia *docGia, DanhSachMuonTra &dSMT, DanhSachDauSach &dSDS, DanhMucSach &dMS){
	setfillstyle(2, 2);
	setbkcolor(15);
	setcolor(0);
	outtextxy(400, 180, "Nhap ma sach");
	rectangle(400, 200, 550, 250);
	SetID(400, 200, 550, 250, 11, mapID);
	

	outtextxy(600, 180, "Ngay muon");
	rectangle(600, 200, 640, 250);
	// Ngay
	SetID(600, 200, 640, 250, 14, mapID);
	outtextxy(646, 220, "-");
	rectangle(660, 200, 700, 250);
	// Thang
	SetID(660, 200, 700, 250, 15, mapID);
	outtextxy(706, 220, "-");
	rectangle(720, 200, 800, 250);
	//Nam
	SetID(720, 200, 800, 250, 16, mapID);
	outtextxy(400 + 500 - textwidth("Quan Ly Tra Sach")/2, 140, "Quan Ly Tra Sach");
	setfillstyle(1, 3);
	bar(830, 200, 910, 250);
	// Tra Sach
	SetID(830, 200, 910, 250, 17, mapID);
	bar(930, 200, 1000, 250);
	// Den
	SetID(930, 200, 1000, 250, 18, mapID);
	bar(1020, 200, 1090, 250);
	//thoat
	SetID(1020, 200, 1090, 250, 19, mapID);
	setbkcolor(3);
	setcolor(0);
	outtextxy(870 - textwidth("Tra Sach")/2, 220, "Tra Sach");
	outtextxy(965 - textwidth("Den")/2, 220, "Den");
	outtextxy(1055 - textwidth("Thoat")/2, 220, "Thoat");
	//bar(1020, 200, 1090, 250);
	setbkcolor(15);
	setcolor(0);
	// Xuat du lieu sach
	char tmp[100];
	tmp[0] = '\0';
	int xuatHien = 0;
	strcat(tmp, "Ho va ten: ");
	strcat(tmp, docGia->ho);
	strcat(tmp, " ");
	strcat(tmp, docGia->ten);
	outtextxy(1140, 205, tmp);
	xuatHien = 1140;
	memset(tmp, 0, 100);
	strcat(tmp, "Trang thai the: ");
	if(docGia->trangThaiThe == 0)
		strcat(tmp, "bi khoa.");
	else
		strcat(tmp, "dang hoat dong");
	//strcat(tmp, convertSo);
	outtextxy(xuatHien, 235, tmp);
	// In du lieu
	int h = 0;
	outtextxy(400 + 10 + h, 250 + 50, "Ma Sach");
	h += 150;
	outtextxy(400 + 10 + h, 250 + 50, "Ngay muon");
	h += 250;
	outtextxy(400 + 10 + h, 250 + 50, "Ngay tra");
	h += 250;
	outtextxy(400 + 10 + h, 250 + 50, "Trang Thai");
	int totalPage = 0;
	
	if(docGia->dSMuonTra->SLDS % 6 ==0)
		totalPage = docGia->dSMuonTra->SLDS/6;
	else
		totalPage = docGia->dSMuonTra->SLDS/6 + 1;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	int y1 = 0;
	// Ve Bang
	if(docGia->dSMuonTra->SLDS < 7)
	{
		HienThiDanhSachMuonTra(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, docGia->dSMuonTra->SLDS, y1, h);
	}
	else
	{
		SetID(400 + 500 - textwidth("Trang 1/1") - 30, 680, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),680 + textheight("back"), 12, mapID);
		SetID(400 + 500 + textwidth("Trang 1/1") + 10, 680, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 680 + textheight("next"), 13, mapID);
		outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 680, "back");
		outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 680, "next");
		HienThiDanhSachMuonTra(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, docGia->dSMuonTra->SLDS, y1, h);
	}
	setbkcolor(15);
	setcolor(0);
	int x, y;
	int IDXet = 0;
	int maSach = 0;
	Ngay dateMuon;
	int ngayMuon = 0;
	int thangMuon = 0;
	int namMuon = 0;
	char ngay[11];
	memset(ngay, 0, 11);
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				//VeThemXoaSua(mapID);
				continue;
			}
			else if(IDXet == 11)
			{
				maSachTraSach:
				setbkcolor(15);
				setcolor(0);
				char S[6];
				S[0] = '\0';
				ConvertIntToChar(S, maSach);
				outtextxy(405, 220, S);	
				Input(405, 220, 1, 6,S, IDXet, mapID);
				if(S[0] == '\0')
					maSach = 0;
				else
					maSach = Convert(S);
				if(IDXet == 14)
					goto ngayMuonTraSach;
				else if(IDXet == 15)
					goto thangMuonTraSach;
				else if(IDXet == 16)
					goto namMuonTraSach;
			}
			else if(IDXet == 12)
			{
				//cout << "Vao";
				if(pageCurent > 0)
				{
					xoaDanhSachMuonTra(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, docGia->dSMuonTra->SLDS, y1, h);
					pageCurent--;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachMuonTra(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, docGia->dSMuonTra->SLDS, y1, h);
					//DrawMenu();
				}
			}
			else if(IDXet == 13)
			{
				//cout << "Vao!";
				if(pageCurent < totalPage - 1)
				{
					xoaDanhSachMuonTra(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, docGia->dSMuonTra->SLDS, y1, h);
					pageCurent++;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachMuonTra(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, docGia->dSMuonTra->SLDS, y1, h);
					//DrawMenu();
				}
			}
			else if(IDXet == 14)
			{
				ngayMuonTraSach:
				// ngay muon
				setbkcolor(15);
				setcolor(0);
				char S[3];
				S[0] = '\0';
				memset(S, 0, 3);
				ConvertIntToChar(S, ngayMuon);
				Input(605, 220, 1, 2, S, IDXet, mapID);
				if(S[0] == '\0')
					ngayMuon = 0;
				else
					ngayMuon = Convert(S);
				if(IDXet == 11)
					goto maSachTraSach;
				else if(IDXet == 15)
					goto thangMuonTraSach;
				else if(IDXet == 16)
					goto namMuonTraSach;
			}
			else if(IDXet == 15)
			{
				thangMuonTraSach:
				char S[3];
				setbkcolor(15);
				setcolor(0);
				memset(S, 0, 3);
				ConvertIntToChar(S, thangMuon);
				Input(665, 220, 1, 2, S, IDXet, mapID);
				if(S[0] == '\0')
					thangMuon = 0;
				else
					thangMuon = Convert(S);
				if(IDXet == 11)
					goto maSachTraSach;
				else if(IDXet == 14)
					goto ngayMuonTraSach;
				else if(IDXet == 16)
					goto namMuonTraSach;

			}
			else if(IDXet == 16)
			{
				namMuonTraSach:
				setbkcolor(15);
				setcolor(0);
				char S[5];
				memset(S, 0, 5);
				ConvertIntToChar(S, namMuon);
				Input(725, 220, 1, 4, S, IDXet, mapID);
				if(S[0] == '\0')
					namMuon = 0;
				else
					namMuon = Convert(S);
				if(IDXet == 11)
					goto maSachTraSach;
				else if(IDXet == 15)
					goto thangMuonTraSach;
				else if(IDXet == 14)
					goto ngayMuonTraSach;
			}
			else if(IDXet == 17)
			{
				dateMuon.ngay = ngayMuon;
				dateMuon.thang = thangMuon;
				dateMuon.nam = namMuon;
				//cout << thangMuon;
				if(checkNgayDauVao(dateMuon) != 0)
				{
					if(checkNgayDauVao(dateMuon) == 1)
						MessageBox(NULL, "Sai dinh dang ngay!", "Thong Bao", MB_OK);
					else if(checkNgayDauVao(dateMuon) == 2)
						MessageBox(NULL, "Vui long nhap thang nho hon 12!", "Thong Bao", MB_OK);
					else if(checkNgayDauVao(dateMuon) == 3)
						MessageBox(NULL, "Vui long nhap nam khong am!", "Thong Bao", MB_OK);
					else if(checkNgayDauVao(dateMuon) == 4)
						MessageBox(NULL, "Nhung thang 4, 6, 9, 11 chi co 30 ngay!", "Thong Bao", MB_OK);
					else if(checkNgayDauVao(dateMuon) == 5)
						MessageBox(NULL, "Thang 2 chi co toi da 29 ngay!", "Thong Bao", MB_OK);
					else if(checkNgayDauVao(dateMuon) == 6)
						MessageBox(NULL, "Thang 2 chi co toi da 28 ngay!", "Thong Bao", MB_OK);
					continue;
				}
				memset(ngay, 0, 11);
				char tmp[4];
				tmp[0] = '\0';
				ConvertIntToChar(tmp, ngayMuon);
				strcat(ngay, tmp);
				strcat(ngay, "-");
				memset(tmp, 0, 4);
				
				ConvertIntToChar(tmp, thangMuon);
				strcat(ngay, tmp);
				strcat(ngay, "-");
				memset(tmp, 0, 4);	
				ConvertIntToChar(tmp, namMuon);
				strcat(ngay, tmp);
				//cout << ngay;
				cout << maSach << " " << ngay << " ";
				if(!kiemTraMuonTraCoTonTai(maSach, ngay, docGia->dSMuonTra))
				{
					MessageBox(NULL, "Muon tra khong ton tai!", "Thong Bao", MB_OK);
					continue;
				}
				capNhatTra(dMS, dSDS, dSMT, docGia->dSMuonTra, maSach, ngay, 0);
				MessageBox(NULL, "Tra sach thanh cong!", "Thong Bao", MB_OK);
				if(kiemTraMuonBayNgay(docGia->dSMuonTra))
				{
					docGia->trangThaiThe = 1;
				}
				break;
			}
			else if(IDXet == 18)
			{
				dateMuon.ngay = ngayMuon;
				dateMuon.thang = thangMuon;
				dateMuon.nam = namMuon;
				//cout << thangMuon;
				if(checkNgayDauVao(dateMuon) != 0)
				{
					if(checkNgayDauVao(dateMuon) == 1)
						MessageBox(NULL, "Sai dinh dang ngay!", "Thong Bao", MB_OK);
					else if(checkNgayDauVao(dateMuon) == 2)
						MessageBox(NULL, "Vui long nhap thang nho hon 12!", "Thong Bao", MB_OK);
					else if(checkNgayDauVao(dateMuon) == 3)
						MessageBox(NULL, "Vui long nhap nam khong am!", "Thong Bao", MB_OK);
					else if(checkNgayDauVao(dateMuon) == 4)
						MessageBox(NULL, "Nhung thang 4, 6, 9, 11 chi co 30 ngay!", "Thong Bao", MB_OK);
					else if(checkNgayDauVao(dateMuon) == 5)
						MessageBox(NULL, "Thang 2 chi co toi da 29 ngay!", "Thong Bao", MB_OK);
					else if(checkNgayDauVao(dateMuon) == 6)
						MessageBox(NULL, "Thang 2 chi co toi da 28 ngay!", "Thong Bao", MB_OK);
					continue;
				}
				memset(ngay, 0, 10);
				char tmp[4];
				tmp[0] = '\0';
				ConvertIntToChar(tmp, ngayMuon);
				strcat(ngay, tmp);
				strcat(ngay, "-");
				memset(tmp, 0, 4);
				
				ConvertIntToChar(tmp, thangMuon);
				strcat(ngay, tmp);
				strcat(ngay, "-");
				memset(tmp, 0, 4);	
				ConvertIntToChar(tmp, namMuon);
				strcat(ngay, tmp);
				//cout << ngay;
				cout << maSach << " " << ngay << " ";
				if(!kiemTraMuonTraCoTonTai(maSach, ngay, docGia->dSMuonTra))
				{
					MessageBox(NULL, "Muon tra khong ton tai!", "Thong Bao", MB_OK);
					continue;
				}
				capNhatTra(dMS, dSDS, dSMT, docGia->dSMuonTra, maSach, ngay, 1);
				MessageBox(NULL, "Den sach thanh cong!", "Thong Bao", MB_OK);
				if(kiemTraMuonBayNgay(docGia->dSMuonTra))
				{
					docGia->trangThaiThe = 1;
				}
				break;
			}
			else if(IDXet == 19)
				break;
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			//IDtruoc = IDXet;
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 17)
			{
				setfillstyle(1, 4);
				bar(830, 200, 910, 250);
				setbkcolor(4);
				setcolor(0);
				outtextxy(870 - textwidth("Tra Sach")/2, 220, "Tra Sach");
				
				setfillstyle(1, 3);
				bar(930, 200, 1000, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(965 - textwidth("Den")/2, 220, "Den");
				bar(1020, 200, 1090, 250);
				outtextxy(1055 - textwidth("Thoat")/2, 220, "Thoat");
			}
			else if(IDXet ==  18)
			{
				setfillstyle(1, 3);
				bar(830, 200, 910, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(870 - textwidth("Tra Sach")/2, 220, "Tra Sach");
				bar(1020, 200, 1090, 250);
				outtextxy(1055 - textwidth("Thoat")/2, 220, "Thoat");
				
				setfillstyle(1, 4);
				bar(930, 200, 1000, 250);
				setbkcolor(4);
				setcolor(0);
				outtextxy(965 - textwidth("Den")/2, 220, "Den");
			}
			else if(IDXet == 19)
			{
				setfillstyle(1, 3);
				bar(830, 200, 910, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(870 - textwidth("Tra Sach")/2, 220, "Tra Sach");
				bar(930, 200, 1000, 250);
				outtextxy(965 - textwidth("Den")/2, 220, "Den");
				
				setfillstyle(1, 4);
				setbkcolor(4);
				setcolor(0);
				bar(1020, 200, 1090, 250);
				outtextxy(1055 - textwidth("Thoat")/2, 220, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(830, 200, 910, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(870 - textwidth("Tra Sach")/2, 220, "Tra Sach");
				bar(930, 200, 1000, 250);
				outtextxy(965 - textwidth("Den")/2, 220, "Den");
				bar(1020, 200, 1090, 250);
				outtextxy(1055 - textwidth("Thoat")/2, 220, "Thoat");
			}
		}
		delay(100);
	}
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	SetID(400, 200, 550, 250, 0, mapID);
	SetID(600, 200, 640, 250, 0, mapID);
	SetID(660, 200, 700, 250, 0, mapID);
	SetID(720, 200, 800, 250, 0, mapID);
	SetID(830, 200, 910, 250, 0, mapID);
	//bar(930, 200, 1000, 250);
	SetID(930, 200, 1000, 250, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 680, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),680 + textheight("back"), 12, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 680, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 680 + textheight("next"), 13, mapID);
}

void quanLyTraSach(int mapID[][hight], DanhSachDocGia &dS, DanhSachMuonTra &dSMT, DanhSachDauSach &dSDS, DanhMucSach &dMS){
	quanLyTraSach:
	setfillstyle(1, 4);
	bar(30, 130 + 360, 230, 360 + 160);
	setbkcolor(4);
	setcolor(0);
	outtextxy(130 - textwidth("Quan ly tra sach")/2, 135 + 360, "Quan ly tra sach");
	setfillstyle(2, 2);
	setbkcolor(15);
	setcolor(0);
	outtextxy(400, 180, "Nhap ma the doc gia");
	setfillstyle(1, 4);
	veTimKiemDon(mapID);
	setbkcolor(15);
	setcolor(0);
	outtextxy(400 + 500 - textwidth("Quan ly tra sach")/2, 140, "Quan ly tra sach");
	int h = 0;
	setbkcolor(15);
	setcolor(0);
	// Set Du Lieu
	int n = 0;
	//cout << ds.SLDocGia;
	DocGia *DSDG[dS.SLDocGia];
	ChuyenDoiDuLieuDocGia(dS.dsDocGia, DSDG, n);
	int y1;
	int totalPage = 0;
	if(dS.SLDocGia % 6 == 0)
		totalPage = dS.SLDocGia/6;
	else
		totalPage = dS.SLDocGia/6 + 1;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	if(dS.SLDocGia < 7)
	{	
		HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
	}
	else
	{
		SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"), 650 + 30 + textheight("back"), 25, mapID);
		SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30 + textheight("next"), 26, mapID);
		outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, "back");
		outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, "next");
		HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
	}
	int x, y;
	int IDXet = 0;
	int maThe = 0;
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				continue;
			}
			else if(IDXet == 22)
			{
				DocGia *dg = findDocGia(dS.dsDocGia, maThe);
				if(dg == NULL)
				{
					MessageBox(NULL, "Doc gia ton tai!", "Thong Bao", MB_OK);
					char S[5];
					setbkcolor(15);
					setcolor(15);
					ConvertIntToChar(S, maThe);
					outtextxy(405, 350, S);
					setbkcolor(15);
					setcolor(0);
					
				}
				else
				{
					SetID(400, 200, 700, 250, 0, mapID);
					SetID(740, 200, 840, 250, 0, mapID);
					SetID(860, 200, 960, 250, 0, mapID);
					setbkcolor(15);
					cleardevice();
					setcolor(0);
					DrawMenu();
					setfillstyle(1, 4);
					bar(30, 130 + 360, 230, 360 + 160);
					setbkcolor(4);
					setcolor(0);
					outtextxy(130 - textwidth("Quan ly tra sach")/2, 135 + 360, "Quan ly tra sach");
					//outtextxy(400 + 500 - textwidth("Quan ly muon sach")/2, 140, "Quan ly muon sach");
					hienThiThongTinDanhSachTra(mapID, dg, dSMT, dSDS, dMS);
					goto quanLyTraSach;
				}
			}
			else if(IDXet == 21)
			{
				char S[5];
				S[0] = '\0';
				setbkcolor(15);
				setcolor(0);
				Input(405, 220, 1, 5, S, IDXet, mapID);
				if(S[0] == '\0')
				{
					maThe = -1;
				}
				else	
					maThe = Convert(S);
			}
			else if(IDXet == 25)
			{
				if(pageCurent == 0)
					continue;
				xoaHienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
				pageCurent--;
				setbkcolor(15);
				setcolor(0);
				int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
				memset(hienThiTrang, 0, length);
				strcat(hienThiTrang, "Trang ");
				HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
				//DrawMenu();
			}
			else if(IDXet == 26)
			{
				if(pageCurent == totalPage - 1)
					continue;
				xoaHienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
				pageCurent++;
				setbkcolor(15);
				setcolor(0);
				int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
				memset(hienThiTrang, 0, length);
				strcat(hienThiTrang, "Trang ");
				HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
				//DrawMenu();
			}
			else if(IDXet == 23)
				break;
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 22)
			{
				setfillstyle(1, 4);
				bar(740, 200, 840, 250);
				setbkcolor(4);
				setcolor(0);
				outtextxy(790 - textwidth("Tim")/2, 220, "Tim");
				setfillstyle(1, 3);
				bar(860, 200, 960, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(910 - textwidth("Thoat")/2, 220, "Thoat");
			}
			else if(IDXet == 23)
			{
				setfillstyle(1, 3);
				bar(740, 200, 840, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(790 - textwidth("Tim")/2, 220, "Tim");
				setfillstyle(1, 4);
				bar(860, 200, 960, 250);
				setbkcolor(4);
				setcolor(0);
				outtextxy(910 - textwidth("Thoat")/2, 220, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(740, 200, 840, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(790 - textwidth("Tim")/2, 220, "Tim");
				bar(860, 200, 960, 250);
				outtextxy(910 - textwidth("Thoat")/2, 220, "Thoat");
			}
		}
		delay(100);
	}
	SetID(400, 200, 700, 250, 0, mapID);
	SetID(740, 200, 840, 250, 0, mapID);
	SetID(860, 200, 960, 250, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"), 650 + 30 + textheight("back"), 0, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30 + textheight("next"), 0, mapID);
	//setbkcolor(15);
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
}


// menu thong ke


void hienThiDanhSachThongKeMuon(int pageCurent, int totalPage, char hienThiTrang[], DanhSachMuonTra *dS, DanhSachDauSach dSDS, int sl, int y1, int h){
	//y1 = 0;
	y1 = 30;
	h = 0;
	//int cot = 2;
	MuonTra *p = dS->pHead;
	int dem = 1;
	dem = dem*pageCurent;
	if(dem != 0)
	{
		int i = 0;
		while(p != NULL)
		{
			if(p->trangThai == 0)
				i++;
			if(i == 6*pageCurent)
				break;
			p = p->pNext;
		}
	}
	outtextxy(400 + textwidth("Ma sach")/2 + h, 220 + 80, "Ma sach");
	h += (1400-400)/2;
	outtextxy(400 + textwidth("Ten sach")/2 + h, 220 + 80, "Ten sach");
	h = 0;
	while(p != NULL)
	{
		int i = 0;
		if(p->trangThai == 0)
		{
			char s[6];
			ConvertIntToChar(s, p->maSach);
			line(400, 250 + y1, 1400, 250 + y1);
			h = 0;
			outtextxy(400 + 10, 220 + 50 + 50 + y1, s);
			h += (1400-400)/2;
			DauSach *dauSach = findDauSachTheoMaSach(dSDS, p->maSach);
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dauSach->TenSach);
			y1 += 50;
			i++;
		}
		if(i == 6)
			break;
		if(i + 6*pageCurent == sl)
			break;
		p = p->pNext;
	}
	int x1 = 0;
	line(400, 250 + y1, 1400, 250 + y1);
	y1+=50;
	line(400, 250 + y1, 1400, 250 + y1);
	for(int i = 0; i <= 2; i++)
	{
		line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
		x1 += (1400 - 400)/2;
	}
	char page[8];
	char tmp[4];
	page[0] = '\0';
	tmp[0] = '\0';
	ConvertIntToChar(tmp, pageCurent + 1);
	strcat(page, tmp);
	//int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);	
	strcat(page, "/");	
	memset(tmp, 0, 4);
	ConvertIntToChar(tmp, totalPage);
	strcat(page, tmp);
	strcat(hienThiTrang, page);
	outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650 + 30, hienThiTrang);
}

void xoaHienThiDanhSachThongKeMuon(int pageCurent, int totalPage, char hienThiTrang[], DanhSachMuonTra *dS, DanhSachDauSach dSDS, int sl, int y1, int h){
	setbkcolor(15);
	setcolor(15);
	y1 = 30;
	h = 0;
	//int cot = 2;
	MuonTra *p = dS->pHead;
	int dem = 1;
	dem = dem*pageCurent;
	if(dem != 0)
	{
		int i = 0;
		while(p != NULL)
		{
			if(p->trangThai == 0)
				i++;
			if(i == 6*pageCurent)
				break;
			p = p->pNext;
		}
	}
	outtextxy(400 + textwidth("Ma sach")/2 + h, 220 + 80, "Ma sach");
	h += (1400-400)/2;
	outtextxy(400 + textwidth("Ten sach")/2 + h, 220 + 80, "Ten sach");
	h = 0;
	while(p != NULL)
	{
		int i = 0;
		if(p->trangThai == 0)
		{
			char s[6];
			ConvertIntToChar(s, p->maSach);
			line(400, 250 + y1, 1400, 250 + y1);
			h = 0;
			outtextxy(400 + 10, 220 + 50 + 50 + y1, s);
			h += (1400-400)/2;
			DauSach *dauSach = findDauSachTheoMaSach(dSDS, p->maSach);
			outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dauSach->TenSach);
			y1 += 50;
			i++;
		}
		if(i == 6)
			break;
		if(i + 6*pageCurent == sl)
			break;
		p = p->pNext;
	}
	int x1 = 0;
	line(400, 250 + y1, 1400, 250 + y1);
	y1+=50;
	line(400, 250 + y1, 1400, 250 + y1);
	for(int i = 0; i <= 2; i++)
	{
		line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
		x1 += (1400 - 400)/2;
	}
	outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650 + 30, hienThiTrang);
}


void hienThiThongTinMuon(int mapID[][hight], int sl, DanhSachDauSach dSDS, DocGia *docGia){
	setfillstyle(1, 3);
	bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
	setbkcolor(3);
	setcolor(0);
	outtextxy(405, 205, "Thoat");
	setbkcolor(15);
	SetID(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230, 11, mapID);
	
	char tmp[100];
	tmp[0] = '\0';
	int xuatHien = 0;
	strcat(tmp, "Ho va ten: ");
	strcat(tmp, docGia->ho);
	strcat(tmp, " ");
	strcat(tmp, docGia->ten);
	outtextxy(650, 205, tmp);
	xuatHien = 650 + textwidth(tmp) + 50;
	memset(tmp, 0, 100);
	strcat(tmp, "Ma the: ");
	char outPut[5];
	outPut[0] = '\0';
	ConvertIntToChar(outPut, docGia->MaThe);
	strcat(tmp, outPut);
	outtextxy(xuatHien, 205, tmp);
	memset(tmp, 0, 100);
	strcat(tmp, "Trang thai the: ");
	if(docGia->trangThaiThe == 0)
		strcat(tmp, "bi khoa.");
	else
		strcat(tmp, "dang hoat dong");
	//strcat(tmp, convertSo);
	outtextxy(650, 235, tmp);
	
	// In du lieu
	int h = 0;
	int totalPage = 0;
	if(sl % 6 == 0)
		totalPage = sl/6;
	else
		totalPage = sl/6 + 1;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	int y1 = 0;
	// Ve Bang
	if(sl < 7)
	{
		hienThiDanhSachThongKeMuon(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, dSDS, sl, y1, h);
	}
	else
	{
		SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + 30 + textheight("back"), 12, mapID);
		SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30+ textheight("next"), 13, mapID);
		outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, "back");
		outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, "next");
		hienThiDanhSachThongKeMuon(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, dSDS, sl, y1, h);
	}
	int x, y;
	int IDXet = 0;
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				//VeThemXoaSua(mapID);
				continue;
			}
			else if(IDXet == 11)
			{
				break;
			}
			else if(IDXet == 12)
			{
				//cout << "Vao";
				if(pageCurent > 0)
				{
					xoaHienThiDanhSachThongKeMuon(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, dSDS, sl, y1, h);
					pageCurent--;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					hienThiDanhSachThongKeMuon(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, dSDS, sl, y1, h);
					
				}
			}
			else if(IDXet == 13)
			{
				//cout << "Vao!";
				if(pageCurent < totalPage - 1)
				{
					xoaHienThiDanhSachThongKeMuon(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, dSDS, sl, y1, h);
					pageCurent++;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					hienThiDanhSachThongKeMuon(pageCurent, totalPage, hienThiTrang, docGia->dSMuonTra, dSDS, sl, y1, h);
				}
			}
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			//IDtruoc = IDXet;
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 11)
			{
				setfillstyle(1, 4);
				bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(4);
				setcolor(0);
				outtextxy(405, 205, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(3);
				setcolor(0);
				outtextxy(405, 205, "Thoat");
			}
		}
		delay(100);
	}
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	SetID(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + 30 + textheight("back"), 12, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30 + textheight("next"), 13, mapID);
}

void thongKeDanhSachMuon(int mapID[][hight], DanhSachDocGia dS, DanhSachDauSach dSDS){
	thongKeSachMuon:
	setfillstyle(2, 2);
	setbkcolor(15);
	setcolor(0);
	outtextxy(400, 180, "Nhap ma the doc gia");
	setfillstyle(1, 4);
	veTimKiemDon(mapID);
	setbkcolor(15);
	setcolor(0);
	outtextxy(400 + 500 - textwidth("Thong ke sach ma doc gia x dang muon")/2, 140, "Thong ke sach ma doc gia x dang muon");
	int h = 0;
	setbkcolor(15);
	setcolor(0);
	// Set Du Lieu
	int n = 0;
	//cout << ds.SLDocGia;
	DocGia *DSDG[dS.SLDocGia];
	ChuyenDoiDuLieuDocGia(dS.dsDocGia, DSDG, n);
	int y1;
	int totalPage = 0;
	if(dS.SLDocGia % 6 == 0)
		totalPage = dS.SLDocGia/6;
	else
		totalPage = dS.SLDocGia/6 + 1;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	if(dS.SLDocGia < 7)
	{	
		HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
	}
	else
	{
		SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"), 650 + 30 + textheight("back"), 25, mapID);
		SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30 + textheight("next"), 26, mapID);
		outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, "back");
		outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, "next");
		HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
	}
	int x, y;
	int IDXet = 0;
	int maThe = 0;
	int doDai = 0;
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				continue;
			}
			else if(IDXet == 22)
			{
				DocGia *dg = findDocGia(dS.dsDocGia, maThe);
				if(dg == NULL)
				{
					MessageBox(NULL, "Doc gia ton tai!", "Thong Bao", MB_OK);
					char S[5];
					setbkcolor(15);
					setcolor(0);
					ConvertIntToChar(S, maThe);
					outtextxy(405, 220, S);
					setbkcolor(15);
					setcolor(0);
				}
				else
				{
					int sl = demSoMuonTraDangMuon(dg->dSMuonTra);
					//chuaHoaDuLieuInRaCauH(dSMT, dg->dSMuonTra);
					if(sl == 0)
					{
						MessageBox(NULL, "Doc gia nay khong muon cuon sach nao!", "Thong Bao", MB_OK);
						continue;
					}
					SetID(400, 200, 700, 250, 0, mapID);
					SetID(740, 200, 840, 250, 0, mapID);
					SetID(860, 200, 960, 250, 0, mapID);
					setbkcolor(15);
					cleardevice();
					setcolor(0);
					DrawMenu();
					setfillstyle(1, 4);
					bar(30, 130 + 420, 230, 420 + 160);
					setbkcolor(4);
					setcolor(0);
					outtextxy(130 - textwidth("Thong ke sach")/2, 135 + 420, "Thong ke sach");
					setbkcolor(15);
					setcolor(0);
					outtextxy(400 + 500 - textwidth("Thong ke sach ma doc gia x dang muon")/2, 140, "Thong ke sach ma doc gia x dang muon");
					hienThiThongTinMuon(mapID, sl, dSDS, dg);
					goto thongKeSachMuon;
				}
			}
			else if(IDXet == 21)
			{
				char S[5];
				S[0] = '\0';
				ConvertIntToChar(S, maThe);
				setbkcolor(15);
				setcolor(0);
				Input(405, 220, 1, 5, S, IDXet, mapID);
				if(S[0] == '\0')
				{
					maThe = 0;
				}
				else	
					maThe = Convert(S);
			}
			else if(IDXet == 25)
			{
				if(pageCurent == 0)
					continue;
				xoaHienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
				pageCurent--;
				setbkcolor(15);
				setcolor(0);
				int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
				memset(hienThiTrang, 0, length);
				strcat(hienThiTrang, "Trang ");
				HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
				//DrawMenu();
			}
			else if(IDXet == 26)
			{
				if(pageCurent == totalPage - 1)
					continue;
				xoaHienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
				pageCurent++;
				setbkcolor(15);
				setcolor(0);
				int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
				memset(hienThiTrang, 0, length);
				strcat(hienThiTrang, "Trang ");
				HienThiDanhSachDocGia(pageCurent, totalPage, hienThiTrang, DSDG, dS.SLDocGia, y1, h, 0);
				//DrawMenu();
			}
			else if(IDXet == 23)
				break;
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 22)
			{
				setfillstyle(1, 4);
				bar(740, 200, 840, 250);
				setbkcolor(4);
				setcolor(0);
				outtextxy(790 - textwidth("Tim")/2, 220, "Tim");
				setfillstyle(1, 3);
				bar(860, 200, 960, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(910 - textwidth("Thoat")/2, 220, "Thoat");
			}
			else if(IDXet == 23)
			{
				setfillstyle(1, 3);
				bar(740, 200, 840, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(790 - textwidth("Tim")/2, 220, "Tim");
				setfillstyle(1, 4);
				bar(860, 200, 960, 250);
				setbkcolor(4);
				setcolor(0);
				outtextxy(910 - textwidth("Thoat")/2, 220, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(740, 200, 840, 250);
				setbkcolor(3);
				setcolor(0);
				outtextxy(790 - textwidth("Tim")/2, 220, "Tim");
				bar(860, 200, 960, 250);
				outtextxy(910 - textwidth("Thoat")/2, 220, "Thoat");
			}
		}
		delay(100);
	}
	SetID(400, 200, 700, 250, 0, mapID);
	SetID(740, 200, 840, 250, 0, mapID);
	SetID(860, 200, 960, 250, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"), 650 + 30 + textheight("back"), 0, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30 + textheight("next"), 0, mapID);
	//setbkcolor(15);
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
}


// Cau i

// Hien thi cau i

void HienThiDanhSachQuaHan(int pageCurent, int totalPage, char hienThiTrang[], DanhSachDauSach dS, DocGia *dSDG, int *dSQuaHan, int sl, int y1, int h){
	y1 = 30;
	h = 0;
	outtextxy(400 + 10 + h, 220 + 80, "Ma the");
	h += 100;
	outtextxy(400 + 10 + h, 220 + 80, "Ho va ten");
	h += 200;
	outtextxy(400 + 10 + h, 220 + 80, "Ma sach");
	h += 100;
	outtextxy(400 + 10 + h, 220 + 80, "Ten sach");
	h += 300;
	outtextxy(400 + 10 + h, 220 + 80, "Ngay muon");
	h += 120;
	outtextxy(400 + 10 + h, 220 + 80, "So ngay qua han");
	for(int i = 0; i < 6; i++)
	{
		if(i + 6*pageCurent >= sl)
			break;
		line(400, 250 + y1, 1400, 250 + y1);
		h = 0;
		//outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i].phai);
		char outPut[5];
		outPut[0] = '\0';
		ConvertIntToChar(outPut, dSDG[i + 6*pageCurent].MaThe);
		outtextxy(400 + 10, 220 + 50 + 50 + y1, outPut);
		h += 100;
		char tmp[100];
		tmp[0] = '\0';
		strcat(tmp, dSDG[i + 6*pageCurent].ho);
		strcat(tmp, " ");
		strcat(tmp, dSDG[i + 6*pageCurent].ten);
		outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, tmp);
		h += 200;
		memset(outPut, 0, 5);
		ConvertIntToChar(outPut, dSDG[i + 6*pageCurent].dSMuonTra->pHead->maSach);
		outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, outPut);
		h += 100;
		DauSach *dauSach = findDauSachTheoMaSach(dS, dSDG[i + 6*pageCurent].dSMuonTra->pHead->maSach);
		outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dauSach->TenSach);
		h += 300;
		//ConvertIntToChar(outPut, dS.danhSachDauSach[i + 6*pageCurent]->NamXB);
		outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dSDG[i + 6*pageCurent].dSMuonTra->pHead->NgayMuon);
		h += 120;
		memset(outPut, 0, 5);
		ConvertIntToChar(outPut, dSQuaHan[i + 6*pageCurent]);
		outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, outPut);
		y1 += 50;
	}
	
	int x1 = 0;
	line(400, 250 + y1, 1400, 250 + y1);
	y1+=50;
	line(400, 250 + y1, 1400, 250 + y1);
	line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	x1 += 100;
	line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	x1 += 200;
	line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	x1 += 100;
	line(400 + x1, 250  + 30, 400 + x1, 250 + y1);
	x1 += 300;
	line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	x1 += 120;
	line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	x1 += 180;
	line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	char page[8];
	page[0] = '\0';
	char tmp[4];
	ConvertIntToChar(tmp, pageCurent + 1);
	strcat(page, tmp);
	strcat(page, "/");
	memset(tmp, 0, 4);
	ConvertIntToChar(tmp, totalPage);
	strcat(page, tmp);
	strcat(hienThiTrang, page);
	outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650 + 30, hienThiTrang);
}


// Xoa hien thi cau i

void xoaHienThiDanhSachQuaHan(int pageCurent, int totalPage, char hienThiTrang[], DanhSachDauSach dS, DocGia *dSDG, int *dSQuaHan, int sl, int y1, int h){
	setbkcolor(15);
	setcolor(15);
	y1 = 30;
	h = 0;
	outtextxy(400 + 10 + h, 220 + 80, "Ma the");
	h += 100;
	outtextxy(400 + 10 + h, 220 + 80, "Ho va ten");
	h += 200;
	outtextxy(400 + 10 + h, 220 + 80, "Ma sach");
	h += 100;
	outtextxy(400 + 10 + h, 220 + 80, "Ten sach");
	h += 300;
	outtextxy(400 + 10 + h, 220 + 80, "Ngay muon");
	h += 120;
	outtextxy(400 + 10 + h, 220 + 80, "So ngay qua han");
	for(int i = 0; i < 6; i++)
	{
		if(i + 6*pageCurent >= sl)
			break;
		line(400, 250 + y1, 1400, 250 + y1);
		h = 0;
		//outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, DSDG[i].phai);
		char outPut[5];
		outPut[0] = '\0';
		ConvertIntToChar(outPut, dSDG[i + 6*pageCurent].MaThe);
		outtextxy(400 + 10, 220 + 50 + 50 + y1, outPut);
		h += 100;
		char tmp[100];
		tmp[0] = '\0';
		strcat(tmp, dSDG[i + 6*pageCurent].ho);
		strcat(tmp, " ");
		strcat(tmp, dSDG[i + 6*pageCurent].ten);
		outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, tmp);
		h += 200;
		memset(outPut, 0, 5);
		ConvertIntToChar(outPut, dSDG[i + 6*pageCurent].dSMuonTra->pHead->maSach);
		outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, outPut);
		h += 100;
		DauSach *dauSach = findDauSachTheoMaSach(dS, dSDG[i + 6*pageCurent].dSMuonTra->pHead->maSach);
		outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dauSach->TenSach);
		h += 300;
		//ConvertIntToChar(outPut, dS.danhSachDauSach[i + 6*pageCurent]->NamXB);
		outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, dSDG[i + 6*pageCurent].dSMuonTra->pHead->NgayMuon);
		h += 120;
		memset(outPut, 0, 5);
		ConvertIntToChar(outPut, dSQuaHan[i + 6*pageCurent]);
		outtextxy(400 + 10 + h, 220 + 50 + 50 + y1, outPut);
		y1 += 50;
	}
	
	int x1 = 0;
	line(400, 250 + y1, 1400, 250 + y1);
	y1+=50;
	line(400, 250 + y1, 1400, 250 + y1);
	line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	x1 += 100;
	line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	x1 += 200;
	line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	x1 += 100;
	line(400 + x1, 250  + 30, 400 + x1, 250 + y1);
	x1 += 300;
	line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	x1 += 120;
	line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	x1 += 180;
	line(400 + x1, 250 + 30, 400 + x1, 250 + y1);
	outtextxy(400 + 500 - textwidth(hienThiTrang)/2, 650 + 30, hienThiTrang);
}

void InDanhSachDocGiaMuonQuaHan(int mapID[][hight], DanhSachDauSach dSDS, DanhSachDocGia dSDG, int max)
{
	int n = 0;
	DocGia danhSachDocGia[max];
	int dSQuaHan[max];
	ChuyenDoiDuLieuDocGiaCauI(dSDG.dsDocGia, danhSachDocGia, n, dSQuaHan);
	if(n == 0)
	{
		MessageBox(NULL, "Khong co doc gia nao muon qua han!", "Thong Bao", MB_OK);
		return;
	}
	//quickSortDauSachHienThi(dS.danhSachDauSach, 0, dS.SLDauSach - 1);
	setfillstyle(1, 3);
	bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
	setbkcolor(3);
	setcolor(0);
	outtextxy(405, 205, "Thoat");
	setbkcolor(15);
	//outtextxy(400 + 500 - textwidth("Trang 1/2")/2, 650, "Trang 1/2");
	SetID(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230, 11, mapID);
	outtextxy(400 + 500 - textwidth("In danh sach doc gia muon qua han")/2, 140, "In danh sach doc gia muon qua han");
	
	
	// In du lieu
	int h = 0;
	int totalPage = 0;
	if(n % 6 == 0)
		totalPage = n/6;
	else
		totalPage = n/6 + 1;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	int y1 = 0;
	// Ve Bang
	if(n < 7)
	{
		HienThiDanhSachQuaHan(pageCurent, totalPage, hienThiTrang, dSDS, danhSachDocGia, dSQuaHan, n, y1, h);
	}
	else
	{
		SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + 30 + textheight("back"), 12, mapID);
		SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30+ textheight("next"), 13, mapID);
		outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, "back");
		outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, "next");
		HienThiDanhSachQuaHan(pageCurent, totalPage, hienThiTrang, dSDS, danhSachDocGia, dSQuaHan, n, y1, h);
	}
	int x, y;
	int IDXet = 0;
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				//VeThemXoaSua(mapID);
				continue;
			}
			else if(IDXet == 11)
			{
				break;
			}
			else if(IDXet == 12)
			{
				//cout << "Vao";
				if(pageCurent > 0)
				{
					xoaHienThiDanhSachQuaHan(pageCurent, totalPage, hienThiTrang, dSDS, danhSachDocGia, dSQuaHan, n, y1, h);
					pageCurent--;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachQuaHan(pageCurent, totalPage, hienThiTrang, dSDS, danhSachDocGia, dSQuaHan, n, y1, h);
					
				}
			}
			else if(IDXet == 13)
			{
				//cout << "Vao!";
				if(pageCurent < totalPage - 1)
				{
					xoaHienThiDanhSachQuaHan(pageCurent, totalPage, hienThiTrang, dSDS, danhSachDocGia, dSQuaHan, n, y1, h);
					pageCurent++;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					HienThiDanhSachQuaHan(pageCurent, totalPage, hienThiTrang, dSDS, danhSachDocGia, dSQuaHan, n, y1, h);
				}
			}
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			//IDtruoc = IDXet;
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 11)
			{
				setfillstyle(1, 4);
				bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(4);
				setcolor(0);
				outtextxy(405, 205, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(3);
				setcolor(0);
				outtextxy(405, 205, "Thoat");
			}
		}
		delay(100);
	}
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	SetID(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + 30 + textheight("back"), 12, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30 + textheight("next"), 13, mapID);
}

// cau j

void InDanhSachDauSachTop(int mapID[][hight], DanhSachDauSach dS, DanhSachMuonTra dSMT){
	if(dS.SLDauSach == 0)
	{
		MessageBox(NULL, "Danh  sach dau sach rong!", "Thong Bao", MB_OK);
		return;
	}
	quickSortMuonTraDauSach(dS.danhSachDauSach, 0, dS.SLDauSach - 1, dSMT);
	setfillstyle(1, 3);
	bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
	setbkcolor(3);
	setcolor(0);
	outtextxy(405, 205, "Thoat");
	setbkcolor(15);
	//outtextxy(400 + 500 - textwidth("Trang 1/2")/2, 650, "Trang 1/2");
	SetID(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230, 11, mapID);
	outtextxy(400 + 500 - textwidth("In danh sach top 10 dau sach")/2, 140, "In danh sach top 10 dau sach");
	
	
	// In du lieu
	int h = 0;
	int totalPage = 0;
	if(dS.SLDauSach < 11)
		totalPage = dS.SLDauSach/7 + 1;
	else
		totalPage = 2;
	int pageCurent = 0;
	char hienThiTrang[] = "Trang ";
	int y1 = 0;
	// Ve Bang
	if(dS.SLDauSach < 7)
	{
		HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
	}
	else
	{
		SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + 30 + textheight("back"), 12, mapID);
		SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30+ textheight("next"), 13, mapID);
		outtextxy(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, "back");
		outtextxy(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, "next");
		if(dS.SLDauSach < 10)
			HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
		else
			HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, 10, y1, h, 0);
	}
	int x, y;
	int IDXet = 0;
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 0)
			{
				//VeThemXoaSua(mapID);
				continue;
			}
			else if(IDXet == 11)
			{
				break;
			}
			else if(IDXet == 12)
			{
				//cout << "Vao";
				if(pageCurent > 0)
				{
					xoaDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 3);
					pageCurent--;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					if(dS.SLDauSach < 10)
						HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
					else
						HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, 10, y1, h, 0);
								
				}
			}
			else if(IDXet == 13)
			{
				//cout << "Vao!";
				if(pageCurent < totalPage - 1)
				{
					xoaDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 3);
					pageCurent++;
					setbkcolor(15);
					setcolor(0);
					int length = sizeof(hienThiTrang) / sizeof(hienThiTrang[0]);
					memset(hienThiTrang, 0, length);
					strcat(hienThiTrang, "Trang ");
					if(dS.SLDauSach < 10)
						HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, dS.SLDauSach, y1, h, 0);
					else
						HienThiDanhSachDauSach(pageCurent, totalPage, hienThiTrang, dS, 10, y1, h, 0);
				}
			}
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			//IDtruoc = IDXet;
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 11)
			{
				setfillstyle(1, 4);
				bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(4);
				setcolor(0);
				outtextxy(405, 205, "Thoat");
			}
			else
			{
				setfillstyle(1, 3);
				bar(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230);
				setbkcolor(3);
				setcolor(0);
				outtextxy(405, 205, "Thoat");
			}
		}
		delay(100);
	}
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	DrawMenu();
	SetID(400, 200, 400 + 50 + textwidth("Thoat") + 10, 230, 0, mapID);
	SetID(400 + 500 - textwidth("Trang 1/1") - 30, 650 + 30, 400 + 500 - textwidth("Trang 1/1") - 30 + textwidth("back"),650 + 30 + textheight("back"), 12, mapID);
	SetID(400 + 500 + textwidth("Trang 1/1") + 10, 650 + 30, 400 + 500 + textwidth("Trang 1/1") + 10 + textwidth("next"), 650 + 30 + textheight("next"), 13, mapID);
	quickSortTenSach(dS.danhSachDauSach, 0, dS.SLDauSach - 1);
}
// Menu

void Menu(int mapID[][hight], DanhSachDocGia &dSDG, DanhSachDauSach &dSDS, DanhSachMuonTra &dSMT, DanhMucSach &dMS, int &idDMSMax, int arr1[], int arr2[], int &nt, int &np){
	int x, y;
	int IDXet = 0;
	int IDtruoc = 0;
	DrawMenu();
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			IDXet = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			if(IDXet == 1)
			{
				quanLyDocGia(mapID, dSDG, arr1, arr2, nt, np);
			}
			else if(IDXet == 2){
				inDanhSachDocGia(mapID, dSDG);
			}
			else if(IDXet == 3)
			{
				QuanLyDauSach(mapID, dSDS, idDMSMax, dMS, dSMT);				
			}
			else if(IDXet == 4)
			{
				InDanhSachDauSach(mapID, dSDS);
			}
			else if(IDXet == 5)
			{
				TimThongTinSach(mapID, dSDS);
			}
			else if(IDXet == 6)
			{
				quanLyMuonSach(mapID, dSDG, dSMT, dSDS, dMS);
			}
			else if(IDXet == 7)
			{
				quanLyTraSach(mapID, dSDG, dSMT, dSDS, dMS);
			}
			else if(IDXet == 8)
			{
				thongKeDanhSachMuon(mapID, dSDG, dSDS);
			}
			else if(IDXet == 9)
			{
				InDanhSachDocGiaMuonQuaHan(mapID, dSDS, dSDG, dSMT.SLDS);
			}
			else if(IDXet == 10)
			{
				InDanhSachDauSachTop(mapID, dSDS, dSMT);
			}
			else if(IDXet == 99)
				break;
		}
		if(ismouseclick(WM_MOUSEMOVE)){
			int h = 0;
			getmouseclick(WM_MOUSEMOVE, x, y);
			IDtruoc = IDXet;
			IDXet = mapID[x][y];
			clearmouseclick(WM_MOUSEMOVE);
			if(IDXet == 99)
			{
				setfillstyle(1, 4);
				bar(30, 20, 230, 80);
				setbkcolor(4);
				setcolor(0);
				outtextxy(130 - textwidth("Thoat")/2, 40, "Thoat");
				continue;
			}
			for(int i = 0; i < 10; i++){
				if(IDXet == i + 1){
					setfillstyle(1, 4);
					bar(30, 130 + h, 230, h + 160);
					setbkcolor(4);
					setcolor(0);
					if(i+1 == 1){
						outtextxy(130 - textwidth("The doc gia")/2, 135 + h, "The doc gia");
					}
					else if(i+1 == 2){
						outtextxy(130 - textwidth("In danh sach doc gia")/2, 135 + h, "In danh sach doc gia");
					}
					else if(i+1 == 3){
						outtextxy(130 - textwidth("Quan ly dau sach")/2, 135 + h, "Quan ly dau sach");
					}
					else if(i+1 == 4){
						outtextxy(130 - textwidth("In danh sach dau sach")/2, 135 + h, "In danh sach dau sach");
					}
					else if(i+1 == 5){
						outtextxy(130 - textwidth("Tim thong tin sach")/2, 135 + h, "Tim thong tin sach");
					}
					else if(i+1 == 6){
						outtextxy(130 - textwidth("Quan ly muon sach")/2, 135 + h, "Quan ly muon sach");
					}
					else if(i+1 == 7){
						outtextxy(130 - textwidth("Quan ly tra sach")/2, 135 + h, "Quan ly tra sach");
					}
					else if(i+1 == 8){
						outtextxy(130 - textwidth("Thong ke sach")/2, 135 + h, "Thong ke sach");
					}
					else if(i+1 == 9){
						outtextxy(130 - textwidth("In danh sach doc gia")/2, 135 + h, "In danh sach doc gia");
					}
					else
					{
						outtextxy(130 - textwidth("Top 10 dau sach")/2, 135 + h, "Top 10 dau sach");
					}
				}
				if(IDXet == IDtruoc)
				{
					h += 60;
					continue;
				}	
				if(IDtruoc == i+1){
					setfillstyle(1, 3);
					bar(30, 130 + h, 230, h + 160);
					//setcolor(0);
					IDtruoc = 0;
					setbkcolor(3);
					setcolor(0);
					if(i+1 == 1){
						outtextxy(130 - textwidth("The doc gia")/2, 135 + h, "The doc gia");
					}
					else if(i+1 == 2){
						outtextxy(130 - textwidth("In danh sach doc gia")/2, 135 + h, "In danh sach doc gia");
					}
					else if(i+1 == 3){
						outtextxy(130 - textwidth("Quan ly dau sach")/2, 135 + h, "Quan ly dau sach");
					}
					else if(i+1 == 4){
						outtextxy(130 - textwidth("In danh sach dau sach")/2, 135 + h, "In danh sach dau sach");
					}
					else if(i+1 == 5){
						outtextxy(130 - textwidth("Tim thong tin sach")/2, 135 + h, "Tim thong tin sach");
					}
					else if(i+1 == 6){
						outtextxy(130 - textwidth("Quan ly muon sach")/2, 135 + h, "Quan ly muon sach");
					}
					else if(i+1 == 7){
						outtextxy(130 - textwidth("Quan ly tra sach")/2, 135 + h, "Quan ly tra sach");
					}
					else if(i+1 == 8){
						outtextxy(130 - textwidth("Thong ke sach")/2, 135 + h, "Thong ke sach");
					}
					else if(i+1 == 9){
						outtextxy(130 - textwidth("In danh sach doc gia")/2, 135 + h, "In danh sach doc gia");
					}
					else
					{
						outtextxy(130 - textwidth("Top 10 dau sach")/2, 135 + h, "Top 10 dau sach");
					}
				}
				h += 60;
			}
			if(IDtruoc == 99)
			{
				setfillstyle(1, 3);
				bar(30, 20, 230, 80);
				setbkcolor(3);
				setcolor(0);
				outtextxy(130 - textwidth("Thoat")/2, 40, "Thoat");
			}
		}
		delay(100);
	}
}


