#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include "Lib.h"
#include<sstream>
#include <stdio.h>
#include <iomanip>
#include"Macro.h"
//#include <conio.h>
//#include <stdio.h>
//#include <conio.h>
//#include<string>
//#include <iostream>  
//#include<ctime>
//#include<cstring>
//#include<string>
//#include <fstream>

using namespace std;

#define MAX_CT_HD 20
#define MAX_NV 500
#define MAX_VT_GIA 100

typedef unsigned int uint;
//===============================VAT TU======================
struct VatTu
{
	string MAVT;
	string ten;
	string don_vi_tinh;
	uint so_luong_ton;
	bool trong_hoa_don;
};
typedef struct VatTu VAT_TU;



struct Node_vt

{
	VAT_TU VT;
	struct Node_vt* left;
	struct Node_vt* right;
};
typedef Node_vt NODE_VT;
typedef NODE_VT* TREE_VT;

//===============================HOA DON======================
struct ngay_lap_hd
{
	int Ngay;
	int Thang;
	int Nam;
};
typedef struct ngay_lap_hd NGAY_LAP_HD;
struct chi_tiet_hd
{
	string MAVT;
	int so_luong;
	int thue;
	int don_gia;
};
typedef struct chi_tiet_hd CHI_TIET_HOA_DON;

struct ds_ct_hd
{
	CHI_TIET_HOA_DON ds[MAX_CT_HD];
	int n = 0;
};
typedef struct ds_ct_hd DS_CT_HD;
struct hoa_don
{
	string MAHD;
	NGAY_LAP_HD ngay_lap_hd;
	char loai;
	DS_CT_HD ds_ct_hd;
	uint tong_tien;
};
typedef struct hoa_don HOA_DON;

struct node_hd
{
	HOA_DON HD;
	struct node_hd* next;
};
typedef struct node_hd NODE_HD;

struct ds_hd
{
	NODE_HD* pHead = NULL;
	NODE_HD* pTail = NULL;
};
typedef ds_hd DS_HD;

//===============================NHAN VIEN======================
struct NhanVien
{

	uint MANV;
	string ho;
	string ten;
	uint gioitinh;
	DS_HD ds_hd;
};
typedef struct NhanVien NHAN_VIEN;


struct ds_nv
{
	NHAN_VIEN* ds[MAX_NV];
	int n = 0;
};
typedef struct ds_nv DS_NV;
//===============================OTHER======================

struct temp_list
{
	uint index;
	string ten;
	string MAVT;
};
typedef struct temp_list TEMP_LIST;

struct node_temp_list
{
	TEMP_LIST tl;
	struct node_temp_list* next;
};
typedef node_temp_list NODE_TEMP_LIST;

struct list_temp_list
{
	NODE_TEMP_LIST* pHead;
	NODE_TEMP_LIST* pTail;
};
typedef struct list_temp_list LIST_TEMP_LIST;

struct vat_tu_gia
{
	string MAVT;
	uint gia = 0;
};
typedef struct vat_tu_gia VAT_TU_GIA;
struct ds_vat_tu_gia
{
	VAT_TU_GIA* ds[500];
	uint n = 0;
};
typedef struct ds_vat_tu_gia DS_VAT_TU_GIA;


//#endif
