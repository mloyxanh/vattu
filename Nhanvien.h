#pragma once
#pragma once

#include"Vattu.h"
////////////////////////////NHAN VIEN ///////////////////////////////
void NhapHo(string& result, int& ordinal, bool& isSave, bool& isEscape);
void NhapTen(string& result, int& ordinal, bool& isSave, bool& isEscape);
void Nhap(uint& result, int choice, int& ordinal, bool& isSave, bool& isEscape);

void Update_NV(DS_NV& ds, NHAN_VIEN* nv, bool isEdited);
int Insert_NV(DS_NV& ds, NHAN_VIEN* nv);
int Full_NV(DS_NV ds);
void Xoa_NV(DS_NV& ds, int index);
void OutputNV_PerPage(DS_NV ds_nv, int index);
int ChooseItems_NV(DS_NV& ds_nv, int& tttrang, int tongtrang); ////// DUNG CHO CA NHAN VIEN VA HOA DON
void Menu_NV(DS_NV& ds);
///////////  TOI UU MA NV /////////////////
uint Tao_Ma_NV(DS_NV ds_nv);
int BinarySearch(DS_NV ds_nv, int start, int end, uint key);
int Partition_Ma(DS_NV& ds_nv, int left, int right);
void Sap_Xep_NV_Ma(DS_NV& ds_nv, int left, int right);
void Sap_Xep_NV(DS_NV& ds_nv);

int Partition_Name(DS_NV& ds_nv, int left, int right);
void Sap_Xep_NV_Name(DS_NV& ds_nv, int left, int right);
void Sap_Xep_NV_Name(DS_NV& ds_nv);
void Menu_In_DS_NV(DS_NV ds);
void GiaiPhongNV(DS_NV& ds_nv);


void GiaiPhongNV(DS_NV& ds_nv)
{
	for (int i = 0; i < ds_nv.n; i++)
	{
		while (ds_nv.ds[i]->ds_hd.pHead != NULL)
		{
			NODE_HD* p = ds_nv.ds[i]->ds_hd.pHead;
			ds_nv.ds[i]->ds_hd.pHead = ds_nv.ds[i]->ds_hd.pHead->next;
			delete p;
		}
		delete ds_nv.ds[i];
	}
}

void Output_NV(NHAN_VIEN* nv)
{

	Xoa_OutNV_1line(locate);
	gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + locate);
	cout << nv->MANV;
	gotoxy(xDisplayDS[1] + 1, yDisplay + 3 + locate);
	cout << nv->ho;
	gotoxy(xDisplayDS[2] + 4, yDisplay + 3 + locate);
	cout << nv->ten;
	gotoxy(xDisplayDS[3] + 3, yDisplay + 3 + locate);
	(nv->gioitinh == 0) ? cout << "NAM" : cout << "NU";
	locate++;
}

void NhapHo(string& result, int& ordinal, bool& isSave, bool& isEscape)
{

	// bien dem so chu da duoc nhap vao cho result
	cout << result;
	int count = (int)result.length();
	int x, y;
	// bien co hieu
	int nSpace = 0;

	while (true)
	{
		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa va dau cach
			// chi nhap ho toi da 15 ky tu.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || kb_hit == SPACE)
				&& count < MAX_HO && count >= 0)
			{
				// xoa dong thong bao
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);

				if (nSpace == 1 && kb_hit == SPACE)
				{
					count++;
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 0;
				}
				else if (kb_hit != SPACE)
				{
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 1;
				}

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					ordinal = 2;
					return;
				}
				else
				{
					ordinal = 1;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 1;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << " TOI DA 16 KY TU, CHI LAY KY TU CHU !!!";
				normalBGColor();
				gotoxy(x, y);
			}
		}

	}
}

void NhapTen(string& result, int& ordinal, bool& isSave, bool& isEscape)
{
	// bien dem so chu da duoc nhap vao cho result
	cout << result;
	int count = (int)result.length();
	int x, y;
	while (true)
	{
		x = wherex();
		y = wherey();

		while (_kbhit())
		{
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa.
			// chi nhap ten toi da 7 ky tu, vi tu dai nhat tieng viet chi la 7.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122)) && count < MAX_TEN)
			{
				count++;

				// xoa dong thong bao
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);

				// chuyen qua in hoa
				kb_hit = toupper((char)kb_hit);
				cout << (char)kb_hit;
				result += (char)kb_hit;
			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					ordinal = 0;
					return;
				}
				else
				{
					ordinal = 2;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 2;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);

			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "TOI DA 7 KY TU, CHI LAY KY TU CHU !!!      ";
				normalBGColor();
				gotoxy(x, y);
			}
		}
	}
}

void Update_NV(DS_NV& ds, NHAN_VIEN* nv, bool isEdited)
{
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();

	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 0;
	bool isSave = false;
	bool isEscape = false;

	// chieu dai bang nhap
	int nngang = (int)keyBangNhapNV[0].length();

	// cac bien luu tru tam thoi
	string ho = "";
	string ten = "";
	uint phai = 3;
	uint MANV;

	CreateBox(X_NOTIFY + 3, Y_NOTIFY, "NOTIFICATIONS:  ", 59);
	BangNhap(xDisplayDS[5] + 7, yDisplay, nngang, keyBangNhapNV, 10);
	BangGuides(xDisplayDS[5] + 7, yDisplay + 20, nngang, keyGuideNV, 5);

	if (isEdited)
	{
		ho = nv->ho;
		ten = nv->ten;
		phai = nv->gioitinh;
		MANV = nv->MANV;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);
		cout << MANV;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);
		cout << ho;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
		cout << ten;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 9);
		(phai == 0) ? cout << phai << ":  NAM" : cout << phai << ":  NU";
	}
	if (!isEdited)
	{
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);
		MANV = Tao_Ma_NV(ds);
		cout << MANV;

	}




	while (true) {

		switch (ordinal)
		{
		case 0:
			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);
			NhapHo(ho, ordinal, isSave, isEscape);
			break;
		case 1:
			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
			NhapTen(ten, ordinal, isSave, isEscape);
			break;
		case 2:
			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 9);
			Nhap(phai, NHAP_PHAI, ordinal, isSave, isEscape);
			break;
		}
		// check Save
		if (isSave)
		{
			// cap nhat lai flag
			isSave = false;

			// check rong;
			if (ho.length() == 0)
			{
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}
			else if (ten.length() == 0)
			{
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}
			else if (phai == 3)
			{
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}

			nv->MANV = MANV;
			format_string(ho);
			nv->ho = ho;
			nv->ten = ten;
			nv->gioitinh = phai;

			if (isEdited)
			{
				NHAN_VIEN* temp;
				for (int i = 0; i < ds.n; i++)
				{
					if (ds.ds[i]->MANV == MANV)
					{
						temp = ds.ds[i];
						break;
					}
				}
			}
			else
			{
				int temp = Insert_NV(ds, nv);
				if (temp == 0)
				{
					// thong bao ra.
					for (int i = 0; i < 5; i++)
					{
						SetColor(BLUE);
						gotoxy(X_NOTIFY + 15, Y_NOTIFY);
						Sleep(100);
						cout << "BO NHO DA DAY .KHONG THEM NHAN VIEN MOI VAO DUOC!";
						Sleep(500);

					}
				}
				else
				{
					// In dong thong bao .
					for (int i = 0; i < 5; i++)
					{
						SetColor(BLUE);
						gotoxy(X_NOTIFY + 15, Y_NOTIFY);
						Sleep(100);
						cout << "           SUCCESSFULLY !!! ";

					}
				}
			}

			normalBGColor();
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 70);
			return;
		}

		if (isEscape)
		{

			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 70);
			return;
		}
	}
	ShowCur(false);
}

int Insert_NV(DS_NV& ds_nv, NHAN_VIEN* nv)
{
	if (Full_NV(ds_nv))
		return 0;
	ds_nv.ds[ds_nv.n++] = nv;
	return 1;
}


int Full_NV(DS_NV ds_nv)
{
	return ds_nv.n == MAX_NV;
}

void Xoa_NV(DS_NV& ds, int index)
{
	if (ds.n == 0)
		return;

	NHAN_VIEN* temp = ds.ds[index];
	for (int i = index + 1; i < ds.n; i++)
	{
		ds.ds[i - 1] = ds.ds[i];
	}
	ds.n--;
}


void OutputNV_PerPage(DS_NV ds_nv, int index)
{
	ShowCur(false);
	Xoa_OutNV_29lines();
	SetColor(BLACK);
	locate = 0;
	index--;
	if (ds_nv.n == 0)
	{
		return;
	}
	for (int i = NUMBER_LINES * index; i < NUMBER_LINES * (index + 1) && i < ds_nv.n; i++)
	{
		Output_NV(ds_nv.ds[i]);
	}
}

void Menu_NV(DS_NV& ds)
{
	clrscr();
	gotoxy(16, 1);
	cout << "~~~CAP NHAT NHAN VIEN~~~ ";
	normalBGColor();

	int nDS = ds.n;
	int choose;
	NHAN_VIEN* nv;


	normalBGColor();

	// thu tu trang
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
	Menu_Nhan_Vien(keymenu_nhan_vien, 5);
label1:
	XoaMotVung(79, yDisplay, 30, 53);
	DisplayVT(keyDisplayNV, 4, xDisplayDS);
	Sap_Xep_NV(ds);
	OutputNV_PerPage(ds, tttrang);
	int kb_hit;
	int currposMainMenu = -1;
	int nKey = 5;
	do
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit)
			{
			case PAGE_UP:
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				OutputNV_PerPage(ds, tttrang);
				break;

			case PAGE_DOWN:
				(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
				OutputNV_PerPage(ds, tttrang);
				break;

			case KEY_F2:
				nv = new NHAN_VIEN;
				if (nv == NULL)
					goto label1;
				Update_NV(ds, nv, false);
				goto label1;

			case KEY_F3:
				choose = ChooseItems_NV(ds, tttrang, tongtrang);
				if (choose > ds.n - 1 || choose < 0)
					goto label1;
				Update_NV(ds, ds.ds[choose], true);
				goto label1;

			case KEY_F4:
				choose = ChooseItems_NV(ds, tttrang, tongtrang);
				if (choose > ds.n - 1 || choose < 0)
					goto label1;
				Xoa_NV(ds, choose);
				goto label1;
			case ESC:
				return;
			case KEY_LEFT:


				if (currposMainMenu > 0)
				{
					currposMainMenu = currposMainMenu - 1;
				}
				else {
					currposMainMenu = nKey - 2;
				}

				EffectiveMenu_Nhan_Vien(currposMainMenu, 2);
				break;

			case KEY_RIGHT: //key right

				if (currposMainMenu < nKey - 2)
				{
					currposMainMenu = currposMainMenu + 1;
				}
				else {
					currposMainMenu = 0;//move to first value in menu system
				}
				EffectiveMenu_Nhan_Vien(currposMainMenu, 1);
				break;

			case ENTER: //enter

				switch (currposMainMenu)
				{
				case 0: //f2
					nv = new NHAN_VIEN;
					if (nv == NULL)
						goto label1;
					Update_NV(ds, nv, false);
					goto label1;
				case 1: //f3
					choose = ChooseItems_NV(ds, tttrang, tongtrang);
					if (choose > ds.n - 1 || choose < 0)
						goto label1;
					Update_NV(ds, ds.ds[choose], true);
					goto label1;
				case 2: //f4
					choose = ChooseItems_NV(ds, tttrang, tongtrang);
					if (choose > ds.n - 1 || choose < 0)
						goto label1;
					Xoa_NV(ds, choose);
					goto label1;
				case 3:

					return;
				}

			}


		}

		gotoxy(3, 36);
		SetColor(BLACK);
		cout << "Trang " << tttrang << " / " << tongtrang;
		gotoxy(135, yHotkey + 1);
		SetColor(GREEN);
		cout << "F10-LUU";


	} while (true);

}

int ChooseItems_NV(DS_NV& ds_nv, int& tttrang, int tongtrang)
{
	int pos = 0;
	int kb_hit;
	pos = 0;
	SetColor(REG_DWORD);
	gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
	cout << "<<";
	gotoxy(xDisplayDS[0] + 2 + 6, yDisplay + 3 + pos);
	cout << ">>";

	while (true)
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit)
			{
			case KEY_UP:
				// xoa muc truoc
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "  ";
				gotoxy(xDisplayDS[0] + 2 + 6, yDisplay + 3 + pos);
				cout << "  ";

				(pos > 0) ? pos-- : pos = 28;

				// to mau muc moi
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 2 + 6, yDisplay + 3 + pos);
				cout << ">>";
				break;

			case KEY_DOWN:
				// xoa muc truoc
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "  ";
				gotoxy(xDisplayDS[0] + 2 + 6, yDisplay + 3 + pos);
				cout << "  ";

				(pos < NUMBER_LINES - 1) ? pos++ : pos = 0;

				// to mau muc moi
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 2 + 6, yDisplay + 3 + pos);
				cout << ">>";
				break;

			case PAGE_UP:
				if (tttrang > 1)
				{
					tttrang--;
				}
				else
				{
					tttrang = tongtrang;
				}
				OutputNV_PerPage(ds_nv, tttrang);

				// high light hang dau.
				pos = 0;
				SetColor(REG_DWORD);
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 2 + 6, yDisplay + 3 + pos);
				cout << ">>";
				break;

			case PAGE_DOWN:
				if (tttrang < tongtrang)
				{
					tttrang++;
				}
				else
				{
					tttrang = 1;

				}

				OutputNV_PerPage(ds_nv, tttrang);

				// high light hang dau.
				pos = 0;
				SetColor(REG_DWORD);
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 2 + 6, yDisplay + 3 + pos);
				cout << ">>";
				break;

			case ENTER:

				// tra ve vi tri pos.
				return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1) * NUMBER_LINES;
			case ESC:
				return -1;
			}
		}
		ShowCur(false);
		SetColor(BLACK);
		normalBGColor();
	}
}

void Nhap(uint& result, int choice, int& ordinal, bool& isSave, bool& isEscape)
{
	//cout << result;
	int count = 0;

	// giu lai vi tri ban dau
	int x = wherex() - 1, y = wherey();

	while (true)
	{
		while (_kbhit())
		{
			int kb_hit;
			if (choice == 0) // nhap phai
			{
				kb_hit = _getch();
				if ((kb_hit == 48 || kb_hit == 49) && count < 1)
				{
					count++;
					result = kb_hit - 48;
					if (choice == 0)
					{
						// xoa dong thong bao
						gotoxy(X_NOTIFY + 15, Y_NOTIFY);
						cout << setw(42) << setfill(' ') << " ";
						gotoxy(x, y);
						(result == 0) ? cout << result << ":  NAM" : cout << result << ":  NU";
					}


				}
			}
			else if (choice == 3)
			{
				kb_hit = _getch();
				if ((kb_hit == 78 || kb_hit == 88 || kb_hit == 110 || kb_hit == 120) && count < 1)
				{
					count++;
					result = kb_hit;

					// xoa dong thong bao
					gotoxy(X_NOTIFY + 15, Y_NOTIFY);
					cout << setw(42) << setfill(' ') << " ";
					gotoxy(x, y);
					if (kb_hit == 78 || kb_hit == 110)
					{
						cout << (char)(78) << ": NHAP ";
					}
					else if (kb_hit == 88 || kb_hit == 120)
						cout << (char)(88) << ": XUAT";


				}
			}

			if (kb_hit == 224)
			{
				kb_hit = _getch();
				// cho nay xay ra hai truong hop
				if (choice == 0)
				{
					if (kb_hit == KEY_UP)
					{
						ordinal = 1;
						return;
					}
					else
					{
						ordinal = 0;
						return;
					}
				}
				else if (choice == 1)
				{
					if (kb_hit == KEY_UP)
					{
						ordinal = 2;
						return;
					}
					else
					{
						ordinal = 0;
						return;
					}
				}
				else if (choice == 3)
				{
					if (kb_hit == KEY_UP)
					{
						ordinal = 2;
						return;
					}
					else
					{
						ordinal = 0;
						return;
					}
				}
			}
			else if (kb_hit == ENTER)
			{
				if (choice == 0)
				{
					ordinal = 0;
					return;
				}
				else if (choice == 1 || choice == 3)
				{
					ordinal = 0;
					return;
				}

			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				gotoxy(x, y);
				result = 3;
				cout << " " << setw(15) << setfill(' ') << " ";
				count--;
				// chuyen ve vi tri ban dau.
				gotoxy(x, y);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {

				if (choice == 1)
				{
					gotoxy(X_NOTIFY + 17, Y_NOTIFY);
					SetColor(BLUE);
					cout << "NHAP 0 HOAC 1,Backspace DE XOA !!!";
					normalBGColor();
					gotoxy(x, y);
				}
				if (choice == 3)
				{
					gotoxy(X_NOTIFY + 17, Y_NOTIFY);
					SetColor(BLUE);
					cout << "NHAP N HOAC X,Backspace DE XOA !!!";
					normalBGColor();
					gotoxy(x, y);
				}
			}
		}
	}
}

uint Tao_Ma_NV(DS_NV ds_nv)
{

	uint max = 0;


	while (BinarySearch(ds_nv, 0, ds_nv.n - 1, max) != -1)
	{
		++max;
	}
	return max;

}

int BinarySearch(DS_NV ds_nv, int start, int end, uint key)
{
	if (end >= start)
	{
		int mid = start + (end - start) / 2;

		if (ds_nv.ds[mid]->MANV == key)
			return mid;
		if (ds_nv.ds[mid]->MANV > key)
			return BinarySearch(ds_nv, start, mid - 1, key);

		return BinarySearch(ds_nv, mid + 1, end, key);
	}
	return -1;
}

int Partition_Ma(DS_NV& ds_nv, int left, int right)
{
	int pivot = ds_nv.ds[right]->MANV;
	int vt = left - 1;
	for (int i = left; i <= right - 1; i++)
	{
		if (ds_nv.ds[i]->MANV < pivot)
		{
			vt++;
			NHAN_VIEN* temp = ds_nv.ds[vt];
			ds_nv.ds[vt] = ds_nv.ds[i];
			ds_nv.ds[i] = temp;
		}
	}
	vt++;
	NHAN_VIEN* temp = ds_nv.ds[vt];
	ds_nv.ds[vt] = ds_nv.ds[right];
	ds_nv.ds[right] = temp;
	return vt;

}
void Sap_Xep_NV_Ma(DS_NV& ds_nv, int left, int right)
{
	if (left < right)
	{
		int ipivot = Partition_Ma(ds_nv, left, right);
		Sap_Xep_NV_Ma(ds_nv, left, ipivot - 1);
		Sap_Xep_NV_Ma(ds_nv, ipivot + 1, right);
	}
}
void Sap_Xep_NV(DS_NV& ds_nv)
{
	Sap_Xep_NV_Ma(ds_nv, 0, ds_nv.n - 1);
}

int Partition_Name(DS_NV& ds_nv, int left, int right)
{
	int vt = left - 1;
	for (int i = left; i <= right - 1; i++)
	{
		if (ds_nv.ds[i]->ten.length() < ds_nv.ds[right]->ten.length())
		{
			vt++;
			NHAN_VIEN* temp = ds_nv.ds[vt];
			ds_nv.ds[vt] = ds_nv.ds[i];
			ds_nv.ds[i] = temp;
		}
		else if (ds_nv.ds[i]->ho.length() < ds_nv.ds[right]->ho.length() &&
			ds_nv.ds[i]->ten.length() == ds_nv.ds[right]->ten.length())
		{
			vt++;
			NHAN_VIEN* temp = ds_nv.ds[vt];
			ds_nv.ds[vt] = ds_nv.ds[i];
			ds_nv.ds[i] = temp;
		}
	}
	vt++;
	NHAN_VIEN* temp = ds_nv.ds[vt];
	ds_nv.ds[vt] = ds_nv.ds[right];
	ds_nv.ds[right] = temp;
	return vt;

}
void Sap_Xep_NV_Name(DS_NV& ds_nv, int left, int right)
{
	if (left < right)
	{
		int ipivot = Partition_Name(ds_nv, left, right);
		Sap_Xep_NV_Name(ds_nv, left, ipivot - 1);
		Sap_Xep_NV_Name(ds_nv, ipivot + 1, right);
	}
}
void Sap_Xep_NV_Name(DS_NV& ds_nv)
{
	Sap_Xep_NV_Name(ds_nv, 0, ds_nv.n - 1);
}
void Menu_In_DS_NV(DS_NV ds)
{
	clrscr();
	gotoxy(16, 1);
	SetColor(REG_DWORD);
	cout << "~~~DANH SACH NHAN VIEN~~~";
	SetColor(BLACK);
	normalBGColor();

	int nDS = ds.n;
	int choose;


	normalBGColor();

	// thu tu trang
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
label1:
	XoaMotVung(79, yDisplay, 30, 53);
	DisplayVT(keyDisplayNV, 4, xDisplayDS);
	Sap_Xep_NV_Name(ds);
	OutputNV_PerPage(ds, tttrang);
	int kb_hit;
	int currposMainMenu = -1;
	int nKey = 5;
	do
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit)
			{
			case PAGE_UP:
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				OutputNV_PerPage(ds, tttrang);
				break;

			case PAGE_DOWN:
				(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
				OutputNV_PerPage(ds, tttrang);
				break;
			case ESC: return;


			}


		}


		gotoxy(3, yHotkey + 1);
		SetColor(BLACK);
		cout << "Trang " << tttrang << " /" << tongtrang << "  " << "PagUP-Trang Truoc, PagDn-Trang Sau";


	} while (true);
}
