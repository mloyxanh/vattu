#pragma once
#pragma once

#include"struct.h"




///////////////////////////////// VAT TU ///////////////////////////
void initTree_VT(TREE_VT& t);
bool isEmpty(TREE_VT t);
NODE_VT* getNodeVT(VAT_TU vt);
void insertVTToTree(TREE_VT& t, VAT_TU vt);
int countVT(TREE_VT t);
bool Check_MAVT(TREE_VT t, string MAVT);
NODE_VT* findMin(TREE_VT t);
NODE_VT* find_VT(TREE_VT t, string MAVT);
bool IsDeleted_VT(TREE_VT& t, VAT_TU nv);
void initList_Temp_List(LIST_TEMP_LIST& l);
void Cap_Nhat_Vat_Tu(TREE_VT& t, HOA_DON hd, DS_CT_HD ds_ct_hd);
void NhapTenVT(string& result, int& ordinal, bool& isSave, bool& isEscape, bool isEdited);
void Update_VT(TREE_VT& t, VAT_TU& vt, bool isEdited);
void OutputVT_PerPage(TREE_VT t, LIST_TEMP_LIST l, int index);
int Output_ListVT(TREE_VT& t, LIST_TEMP_LIST& l, VAT_TU& vt, int& tttrang);
void Menu_VT(TREE_VT& t);
void Create_Temp_List(TREE_VT t, LIST_TEMP_LIST& l, int& index);
void ClearAll_Temp_List(LIST_TEMP_LIST& l);
NODE_TEMP_LIST* Middle(NODE_TEMP_LIST* start, NODE_TEMP_LIST* last);
NODE_TEMP_LIST* binarySearch_Temp_List(LIST_TEMP_LIST l, uint index);
int ChooseItems(TREE_VT& t, LIST_TEMP_LIST& l, int tttrang, int tongtrang);
void NhapDonViTinh(string& result, int& ordinal, bool& isSave, bool& isEscape, bool isEdited);
void NhapSoLuongTon(string& result, int choice, int& ordinal, bool& isSave, bool& isEscape);
void Output_VT(NODE_VT* vt);
NODE_TEMP_LIST* getNode_Temp_List(uint index, string MAVT, string ten);
void addTailList_Temp_List(LIST_TEMP_LIST& l, uint index, string MAVT, string ten);
void Sort_Temp_list_Name(LIST_TEMP_LIST& l);
/////////// RANDOM VT  ///////////////
string Tao_Ma_VT(TREE_VT t);
bool Kiem_Tra_Trung_MAVT(TREE_VT t, string key);
int So_Sanh_Ma_VT(string a, string b);
void Nhap_Ma_VT(string& result, int& ordinal, bool& isSave, bool& isEscape);
int Output_ListVT_TEN(TREE_VT& t, LIST_TEMP_LIST& l, VAT_TU& vt, int& tttrang);
void Menu_In_DS_VT(TREE_VT& t);
void GiaiPhongTree(TREE_VT& t);

void format_string(string& a)
{
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	while (a[a.length() - 1] == ' ')
	{
		a.erase(a.begin() + a.length() - 1);

	}
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{

			a.erase(a.begin() + i + 1);
			i--;
		}

	}
}


void initTree_VT(TREE_VT& t)
{
	t = NULL;
}
bool isEmpty(TREE_VT t)
{
	return t == NULL;
}
NODE_VT* getNodeVT(VAT_TU vt)
{
	NODE_VT* p = new NODE_VT;
	p->VT = vt;
	p->left = p->right = NULL;
	return p;
}
void insertVTToTree(TREE_VT& t, VAT_TU vt)
{
	if (t == NULL)
	{
		t = getNodeVT(vt);
	}
	else if (vt.MAVT < t->VT.MAVT)
	{
		insertVTToTree(t->left, vt);
	}
	else if (vt.MAVT > t->VT.MAVT)
	{
		insertVTToTree(t->right, vt);
	}
}
void GiaiPhongTree(TREE_VT& t)
{
	if (t == NULL) return;
	else
	{
		GiaiPhongTree(t->left);
		GiaiPhongTree(t->right);
		delete t;
	}
}
int countVT(TREE_VT t)
{
	int c = 1;
	if (t == NULL)
		return 0;
	else
	{
		c += countVT(t->left);
		c += countVT(t->right);
		return c;
	}
}
bool Check_MAVT(TREE_VT t, string MAVT)
{
	if (t == NULL)
		return false;
	else if (So_Sanh_Ma_VT(t->VT.MAVT, MAVT) == 0)
		return true;
	else if (So_Sanh_Ma_VT(MAVT, t->VT.MAVT) < 0)
	{
		return Check_MAVT(t->left, MAVT);
	}
	else
		return Check_MAVT(t->right, MAVT);
}


NODE_VT* findMin(TREE_VT t)
{
	while (t->left != NULL)
		t = t->left;
	return t;
}
NODE_VT* find_VT(TREE_VT t, string MAVT)
{
	while (t != NULL && So_Sanh_Ma_VT(MAVT, t->VT.MAVT) != 0)
	{
		if (MAVT < t->VT.MAVT)
			t = t->left;
		else
			t = t->right;
	}
	return t;
}
bool IsDeleted_VT(TREE_VT& t, VAT_TU vt)
{
	if (t == NULL)
		return false;
	else
	{
		if (vt.MAVT > t->VT.MAVT)
			return IsDeleted_VT(t->right, vt);
		else if (vt.MAVT < t->VT.MAVT)
			return IsDeleted_VT(t->left, vt);
		else
		{
			// case 1: No child
			if (t->left == NULL && t->right == NULL)
			{
				delete t;
				t = NULL;
			}
			// case 2: 1 child
			else if (t->right == NULL)
			{
				NODE_VT* temp = t;
				t = t->left;
				delete temp;
			}
			else if (t->left == NULL)
			{
				NODE_VT* temp = t;
				t = t->right;
				delete temp;
			}
			// case 3: 2 child
			else
			{
				NODE_VT* temp = findMin(t->right);
				t->VT = temp->VT;
				return IsDeleted_VT(t->right, temp->VT);
			}
			return true;
		}
	}
}
void initList_Temp_List(LIST_TEMP_LIST& l)
{
	l.pHead = l.pTail = NULL;
}
void Cap_Nhat_Vat_Tu(TREE_VT& t, HOA_DON hd, DS_CT_HD ds_ct_hd)
{
	if (hd.loai == 'X' || hd.loai == 'x') // xuat
	{
		for (int i = 0; i < ds_ct_hd.n; i++)
		{
			NODE_VT* vt_temp = find_VT(t, ds_ct_hd.ds[i].MAVT);
			vt_temp->VT.so_luong_ton -= ds_ct_hd.ds[i].so_luong;
			vt_temp->VT.trong_hoa_don = true;
		}
	}
	else // nhap
	{
		for (int i = 0; i < ds_ct_hd.n; i++)
		{
			NODE_VT* vt_temp = find_VT(t, ds_ct_hd.ds[i].MAVT);
			vt_temp->VT.so_luong_ton += ds_ct_hd.ds[i].so_luong;
			vt_temp->VT.trong_hoa_don = true;
		}
	}
}
void NhapTenVT(string& result, int& ordinal, bool& isSave, bool& isEscape, bool isEdited)
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
			// chi nhan chu thuong hoac  chu in hoa, chu so  va dau cach
			// chi nhap ten vat tu toi da 19 ky tu.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || (kb_hit >= 48 && kb_hit <= 57) || kb_hit == SPACE)
				&& count < MAX_TEN_VT && count >= 0)
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
					if (isEdited)
					{
						ordinal = 1;
						return;
					}
					else
					{
						ordinal = 2;
						return;
					}

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
				cout << "TOI DA 20 KY TU, CHI LAY KY TU CHU VA SO!!!";
				normalBGColor();
				gotoxy(x, y);
			}
		}

	}

}
void Update_VT(TREE_VT& t, VAT_TU& vt, bool isEdited)
{
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();

	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 0;
	bool isSave = false;
	bool isEscape = false;

	// chieu dai bang nhap
	int nngang = (int)keyBangNhapVT[0].length();

	// cac bien luu tru tam thoi
	string ten = "";
	string don_vi_tinh = "";
	string temp_so_luong_ton = "";
	uint so_luong_ton;
	string MAVT;

	CreateBox(X_NOTIFY + 3, Y_NOTIFY, "NOTIFICATIONS:  ", 59);
	BangNhap(xDisplayDS[5] + 7, yDisplay, nngang, keyBangNhapVT, 10);
	BangGuides(xDisplayDS[5] + 7, yDisplay + 20, nngang, keyGuideVT, 5);

	if (isEdited)
	{
		ten = vt.ten;
		don_vi_tinh = vt.don_vi_tinh;
		so_luong_ton = vt.so_luong_ton;
		MAVT = vt.MAVT;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);
		cout << MAVT;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);
		cout << ten;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
		cout << don_vi_tinh;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 9);
		cout << so_luong_ton;
	}
	if (!isEdited)
	{
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);
		MAVT = Tao_Ma_VT(t);
		cout << MAVT;
	}

	while (true) {
		if (isEdited)
		{
			switch (ordinal)
			{

			case 0:
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);
				NhapTenVT(ten, ordinal, isSave, isEscape, isEdited);
				break;
			case 1:
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
				NhapDonViTinh(don_vi_tinh, ordinal, isSave, isEscape, isEdited);
				break;
			}
		}
		else
		{
			switch (ordinal)
			{

			case 0:
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);
				NhapTenVT(ten, ordinal, isSave, isEscape, isEdited);
				break;
			case 1:
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
				NhapDonViTinh(don_vi_tinh, ordinal, isSave, isEscape, isEdited);
				break;
			case 2:
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 9);
				NhapSoLuongTon(temp_so_luong_ton, NHAP_SO_LUONG_TON, ordinal, isSave, isEscape);
				for (int i = 0; i < temp_so_luong_ton.length(); i++)
					so_luong_ton = atoi(temp_so_luong_ton.c_str());
				break;
			}
		}

		// check Save
		if (isSave)
		{
			// cap nhat lai flag
			isSave = false;

			// check rong;
			if (ten.length() == 0)
			{
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}
			else if (don_vi_tinh.length() == 0)
			{
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}
			if (!isEdited)
			{
				if (temp_so_luong_ton.length() == 0)
				{
					gotoxy(X_NOTIFY + 15, Y_NOTIFY);
					SetColor(BLUE);
					cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
					normalBGColor();
					// quay lai va dien vao truong du lieu do
					ordinal = 2;
					continue;
				}
			}



			vt.MAVT = MAVT;
			format_string(ten);
			vt.ten = ten;
			vt.don_vi_tinh = don_vi_tinh;
			vt.so_luong_ton = so_luong_ton;
			vt.trong_hoa_don = false;

			if (isEdited)
			{
				NODE_VT* p = find_VT(t, MAVT);
				p->VT = vt;
			}
			else
			{
				// thuật toán thêm vào danh sách vật tư
				insertVTToTree(t, vt);
			}

			// In dong thong bao .
			for (int i = 0; i < 5; i++)
			{
				SetColor(BLUE);
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				Sleep(100);
				cout << "           SUCCESSFULLY !!! ";
			}
			normalBGColor();
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
			return;
		}

		if (isEscape)
		{
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
			return;
		}
	}
	ShowCur(false);
}
void OutputVT_PerPage(TREE_VT t, LIST_TEMP_LIST l, int index)
{
	Xoa_OutNV_29lines();
	SetColor(BLACK);
	locate = 0;
	NODE_TEMP_LIST* temp1 = NULL;
	NODE_VT* temp2 = NULL;
	index--;
	for (int i = NUMBER_LINES * index; i < NUMBER_LINES * (index + 1); i++)
	{
		temp1 = binarySearch_Temp_List(l, i);
		if (temp1 == NULL)
			return;
		temp2 = find_VT(t, temp1->tl.MAVT);
		Output_VT(temp2);
	}
}
int Output_ListVT(TREE_VT& t, LIST_TEMP_LIST& l, VAT_TU& vt, int& tttrang)
{
	NODE_TEMP_LIST* temp1 = NULL;
	NODE_VT* temp2 = NULL;
	int choose;
	bool check;

	// nNV la so NV hien co trong cay
	int nVT = countVT(t);

	// thu tu trang
	int tongtrang;
	tongtrang = (nVT / NUMBER_LINES) + 1;
	OutputVT_PerPage(t, l, tttrang);

	int kb_hit;
	int currposMainMenu = -1;
	int nKey = 5;
	ShowCur(false);
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
				OutputVT_PerPage(t, l, tttrang);
				break;

			case PAGE_DOWN:
				(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
				OutputVT_PerPage(t, l, tttrang);
				break;
			case KEY_F2: // them
				Update_VT(t, vt, false);
				ClearAll_Temp_List(l);
				return 1;
			case KEY_F3: // sua
				choose = ChooseItems(t, l, tttrang, tongtrang);
				temp1 = binarySearch_Temp_List(l, choose);
				if (temp1 == NULL)
					return 1;
				else
				{
					temp2 = find_VT(t, temp1->tl.MAVT);
					Update_VT(t, temp2->VT, true);
					ClearAll_Temp_List(l);
					return 1;
				}
			case KEY_F4: // xoa
				choose = ChooseItems(t, l, tttrang, tongtrang);
				temp1 = binarySearch_Temp_List(l, choose);
				if (temp1 == NULL)
				{
					return 1;
				}
				else
				{
					temp2 = find_VT(t, temp1->tl.MAVT);
					if (temp2->VT.trong_hoa_don)
					{
						CreateBox(X_NOTIFY, Y_NOTIFY, "NOTIFICATIONS:  ", 59);
						// In dong thong bao .
						for (int i = 0; i < 5; i++)
						{
							SetColor(BLUE);
							gotoxy(X_NOTIFY + 15, Y_NOTIFY);
							Sleep(100);
							cout << " VAT TU DA CO TRONG HOA DON. KHONG THE XOA";
							Sleep(500);
						}
						XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
						ClearAll_Temp_List(l);
						return 1;
					}
					check = IsDeleted_VT(t, temp2->VT);
					ClearAll_Temp_List(l);
					return 1;
				}
			case ESC:
				ClearAll_Temp_List(l);
				return 0;

			case KEY_LEFT:


				if (currposMainMenu > 0)
				{
					currposMainMenu = currposMainMenu - 1;
				}
				else {
					currposMainMenu = nKey - 2;
				}

				EffectiveMenu_VatTu(currposMainMenu, 2);
				break;

			case KEY_RIGHT: //key right

				if (currposMainMenu < nKey - 2)
				{
					currposMainMenu = currposMainMenu + 1;
				}
				else {
					currposMainMenu = 0;//move to first value in menu system
				}
				EffectiveMenu_VatTu(currposMainMenu, 1);
				break;

			case ENTER: //enter

				switch (currposMainMenu)
				{
				case 0:
					Update_VT(t, vt, false);
					ClearAll_Temp_List(l);
					return 1;
				case 1:
					choose = ChooseItems(t, l, tttrang, tongtrang);
					temp1 = binarySearch_Temp_List(l, choose);
					if (temp1 == NULL)
						return 1;
					else
					{
						temp2 = find_VT(t, temp1->tl.MAVT);
						Update_VT(t, temp2->VT, true);
						ClearAll_Temp_List(l);
						return 1;
					}
				case 2:
					choose = ChooseItems(t, l, tttrang, tongtrang);
					temp1 = binarySearch_Temp_List(l, choose);
					if (temp1 == NULL)
					{
						return 1;
					}
					else
					{
						temp2 = find_VT(t, temp1->tl.MAVT);
						if (temp2->VT.trong_hoa_don)
						{
							CreateBox(X_NOTIFY, Y_NOTIFY, "NOTIFICATIONS:  ", 59);
							// In dong thong bao .
							for (int i = 0; i < 5; i++)
							{
								SetColor(BLUE);
								gotoxy(X_NOTIFY + 15, Y_NOTIFY);
								Sleep(100);
								cout << " VAT TU DA CO TRONG HOA DON. KHONG THE XOA";
								Sleep(500);
							}
							XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
							ClearAll_Temp_List(l);
							return 1;
						}
						check = IsDeleted_VT(t, temp2->VT);
						ClearAll_Temp_List(l);
						return 1;
					}
				case 3:
					ClearAll_Temp_List(l);
					return 0;
				}

			}

		}

		ShowCur(false);
		gotoxy(3, 36);
		SetColor(BLACK);
		cout << "Trang " << tttrang << " / " << tongtrang;
		gotoxy(135, yHotkey + 1);
		SetColor(GREEN);
		cout << "F10-LUU";



	} while (true);






}
void Menu_VT(TREE_VT& t)
{
	clrscr();
	normalBGColor();
	int tttrang = 1;
	int esc = 1;

	do
	{
		clrscr();
		gotoxy(26, 1);
		cout << "~~~CAP NHAT VAT TU~~~ ";

		//gotoxy(3, yHotkey );
		//SetColor(BLACK);
		//cout << "ESC-Thoat, F2 - Them, F3 - Sua, F4 - Xoa, F10 - Luu, PgUP, PgDn";

		normalBGColor();
		VAT_TU vt;
		int index = 0;


		LIST_TEMP_LIST l;
		initList_Temp_List(l);
		Create_Temp_List(t, l, index);
		DisplayVT(keyDisplayVT, 5, xDisplayDS);
		Menu_Vat_Tu(keymenu_vat_tu, 5);
		esc = Output_ListVT(t, l, vt, tttrang);

	} while (esc);

}
void Create_Temp_List(TREE_VT t, LIST_TEMP_LIST& l, int& index)
{
	if (t == NULL) return;
	Create_Temp_List(t->left, l, index);
	addTailList_Temp_List(l, index++, t->VT.MAVT, t->VT.ten);
	Create_Temp_List(t->right, l, index);
}
void ClearAll_Temp_List(LIST_TEMP_LIST& l)
{
	NODE_TEMP_LIST* p;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->next;
		delete p;
	}
}
NODE_TEMP_LIST* Middle(NODE_TEMP_LIST* start, NODE_TEMP_LIST* last)
{
	if (start == NULL) // rong
		return NULL;
	if (start->next == NULL) // 1 phan tu
		return start;

	NODE_TEMP_LIST* slow = start;
	NODE_TEMP_LIST* fast = start;
	while (fast != last)
	{
		fast = fast->next;
		if (fast != last)
		{
			slow = slow->next;
			fast = fast->next;
		}

	}
	return slow;
}
NODE_TEMP_LIST* binarySearch_Temp_List(LIST_TEMP_LIST l, uint index)
{
	NODE_TEMP_LIST* start = l.pHead;
	NODE_TEMP_LIST* last = NULL;
	do
	{
		// Find middle
		NODE_TEMP_LIST* mid = Middle(start, last);
		// if middle is empty
		if (mid == NULL)
			return NULL;

		// if value is present at middle
		if (mid->tl.index == index)
			return mid;
		// if value is more than mid
		else if (mid->tl.index < index)
			start = mid->next;
		// if value is less than mid
		else
			last = mid;
	} while (last == NULL || last != start);
	return NULL; // value not present
}
int ChooseItems(TREE_VT& t, LIST_TEMP_LIST& l, int tttrang, int tongtrang)
{
	int pos = 0;
	int kb_hit;
	pos = 0;
	SetColor(REG_DWORD);
	gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
	cout << "<<";
	gotoxy(xDisplayDS[0] + 9, yDisplay + 3 + pos);
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
				gotoxy(xDisplayDS[0] + 9, yDisplay + 3 + pos);
				cout << "  ";

				(pos > 0) ? pos-- : pos = 28;

				// to mau muc moi
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 9, yDisplay + 3 + pos);
				cout << ">>";
				break;

			case KEY_DOWN:
				// xoa muc truoc
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "  ";
				gotoxy(xDisplayDS[0] + 9, yDisplay + 3 + pos);
				cout << "  ";

				(pos < NUMBER_LINES - 1) ? pos++ : pos = 0;

				// to mau muc moi
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 9, yDisplay + 3 + pos);
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
				OutputVT_PerPage(t, l, tttrang);

				// high light hang dau.
				pos = 0;
				SetColor(LIGHT_GREEN);
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 9, yDisplay + 3 + pos);
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

				OutputVT_PerPage(t, l, tttrang);

				// high light hang dau.
				pos = 0;
				SetColor(LIGHT_GREEN);
				gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 9, yDisplay + 3 + pos);
				cout << ">>";
				break;

			case ENTER:

				// tra ve vi tri pos.
				return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1) * NUMBER_LINES;
			}
		}
		ShowCur(false);
		SetColor(WHITE);
		gotoxy(30, 36);
		cout << "Trang " << tttrang << " / " << tongtrang;
		normalBGColor();
	}
}
void NhapDonViTinh(string& result, int& ordinal, bool& isSave, bool& isEscape, bool isEdited)
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
			// chi nhan chu thuong va dau cach
			// chi nhap ten vat tu toi da 10 ky tu.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || kb_hit == SPACE)
				&& count < MAX_DVT && count >= 0)
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
					ordinal = 0;
					return;
				}
				else
				{
					if (isEdited)
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
			}
			else if (kb_hit == ENTER)
			{
				if (isEdited)
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
				cout << " TOI DA 10 KY TU,CHI LAY KY TU CHU!!!      ";
				normalBGColor();
				gotoxy(x, y);
			}
		}

	}
}
void NhapSoLuongTon(string& result, int choice, int& ordinal, bool& isSave, bool& isEscape)
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
			// chi nhan chu so
			// chi nhap so luong ton toi da 6 chu so.
			if (((kb_hit >= 48 && kb_hit <= 57)) && count < (choice == 1 ? MAX_THUE : MAX_SLT) && count >= 0)
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
					if (choice == 0)
					{
						ordinal = 3;
						return;
					}
					else if (choice == 1)
					{
						ordinal = 0;
						return;
					}
					else if (choice == 2 || choice == 5)
					{
						ordinal = 1;
						return;
					}
					else if (choice == 3) // nhap don gia trong chi tiet hoa don
					{
						ordinal = 2;
						return;
					}
					else if (choice == 10) // nhập thuế có edit
					{
						ordinal = 2;
						return;
					}
					else if (choice == 11) // nhập số lượng có edit
					{
						ordinal = 0;
						return;
					}
					else if (choice == 12) // nhập đơn giá có edit
					{
						ordinal = 1;
						return;
					}
				}
				else // key down
				{
					if (choice == 0) // ma vat tu
					{
						ordinal = 1;
						return;
					}
					else if (choice == 1) // thue
					{
						ordinal = 2;
						return;
					}
					else if (choice == 2) // so luong ton
					{
						ordinal = 0;
						return;
					}
					else if (choice == 5) // so luong trong chi tiet hoa don
					{
						ordinal = 3;
						return;
					}
					else if (choice == 3) // don gia trong chi tiet hoa don
					{
						ordinal = 0;
						return;
					}
					else if (choice == 11) //  số lượng có edit
					{
						ordinal = 2;
						return;
					}
					else if (choice == 10) // thuế edit
					{
						ordinal = 1;
						return;
					}
					else if (choice == 12) // don gia co edit
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
					ordinal = 1;
					return;
				}
				else if (choice == 1)
				{
					ordinal = 2;
					return;
				}
				else if (choice == 2)
				{
					ordinal = 0;
					return;
				}
				else if (choice == 5)
				{
					ordinal = 3;
					return;
				}
				else if (choice == 3)
				{
					ordinal = 0;
					return;
				}
				else if (choice == 11) //  số lượng có edit
				{
					ordinal = 2;
					return;
				}
				else if (choice == 10) // thuế edit
				{
					ordinal = 1;
					return;
				}
				else if (choice == 12) // don gia co edit
				{
					ordinal = 0;
					return;
				}
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
				cout << " TOI DA 9 CHU SO !!!                        ";
				normalBGColor();
				gotoxy(x, y);
			}
		}

	}
}
/////////// RANDOM VT  ///////////////
string Tao_Ma_VT(TREE_VT t)
{
	string result = "VT0000";
	do
	{
		result[2] = rand() % (57 - 49 + 1) + 49;
		for (int i = 3; i < result.length(); i++)
		{
			result[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (Kiem_Tra_Trung_MAVT(t, result));
	return result;
}
bool Kiem_Tra_Trung_MAVT(TREE_VT t, string key)
{
	if (t == NULL)
		return false;
	if (So_Sanh_Ma_VT(key, t->VT.MAVT) > 0)
		return Kiem_Tra_Trung_MAVT(t->right, key);
	else if (So_Sanh_Ma_VT(key, t->VT.MAVT) < 0)
		return Kiem_Tra_Trung_MAVT(t->left, key);
	else // ton tai
		return true;
}

int So_Sanh_Ma_VT(string a, string b)
{
	// cat chuoi lay ma vat tu
	string  temp_a = a.substr(2);
	string temp_b = b.substr(2);
	int so_a = atoi(temp_a.c_str());
	int so_b = atoi(temp_b.c_str());
	if (so_a > so_b)
		return 1;
	else if (so_a < so_b)
		return -1;
	else
		return 0;
}

void Nhap_Ma_VT(string& result, int& ordinal, bool& isSave, bool& isEscape)
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
			// chi nhan chu thuong hoac  chu in hoa, chu so  va dau cach
			// chi nhap ten vat tu toi da 19 ky tu.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || (kb_hit >= 48 && kb_hit <= 57))
				&& count < MAX_MA_VT && count >= 0)
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
					ordinal = 3;
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
				cout << "TOI DA " << MAX_MA_VT << " KY TU, CHI LAY KY TU CHU VA SO!!!";
				normalBGColor();
				gotoxy(x, y);
			}
		}

	}
}

///////////////////////////////////////////IN DS VT//////////////////////////////////////////////////

int Output_ListVT_TEN(TREE_VT& t, LIST_TEMP_LIST& l, VAT_TU& vt, int& tttrang)
{


	// nNV la so NV hien co trong cay
	int nVT = countVT(t);

	// thu tu trang
	int tongtrang;
	tongtrang = (nVT / NUMBER_LINES) + 1;
	OutputVT_PerPage(t, l, tttrang);

	int kb_hit;
	ShowCur(false);
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
				OutputVT_PerPage(t, l, tttrang);
				break;

			case PAGE_DOWN:
				(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
				OutputVT_PerPage(t, l, tttrang);
				break;
			case ESC:
				ClearAll_Temp_List(l);
				return 0;

			}

		}

		ShowCur(false);
		gotoxy(3, 36);
		SetColor(BLACK);
		cout << "Trang " << tttrang << " /" << tongtrang << "  " << "PagUP-Trang Truoc, PagDn-Trang Sau";



	} while (true);

}


void Menu_In_DS_VT(TREE_VT& t)
{

	clrscr();
	normalBGColor();
	int tttrang = 1;
	int esc = 1;

	do
	{
		clrscr();
		gotoxy(25, 1);
		cout << "~~~DANH SACH VAT TU~~~";


		normalBGColor();
		VAT_TU vt;
		int index = 0;

		// cho nay thay doi cau truc DSLK TEMPLIST bang Mang cap phat dong hay hon...
		LIST_TEMP_LIST l;
		initList_Temp_List(l);
		Create_Temp_List(t, l, index);
		Sort_Temp_list_Name(l);
		DisplayVT(keyDisplayVT, 5, xDisplayDS);
		esc = Output_ListVT_TEN(t, l, vt, tttrang);

	} while (esc);

}

void Output_VT(NODE_VT* vt)
{
	Xoa_OutNV_1line(locate);
	gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + locate);
	cout << vt->VT.MAVT;
	gotoxy(xDisplayDS[1] + 1, yDisplay + 3 + locate);
	cout << vt->VT.ten;
	gotoxy(xDisplayDS[2] + 2, yDisplay + 3 + locate);
	cout << vt->VT.don_vi_tinh;
	gotoxy(xDisplayDS[3] + 3, yDisplay + 3 + locate);
	cout << vt->VT.so_luong_ton;
	gotoxy(xDisplayDS[4] + 4, yDisplay + 3 + locate);
	(vt->VT.trong_hoa_don == true) ? cout << "CO" : cout << "KHONG";
	locate++;
}

NODE_TEMP_LIST* getNode_Temp_List(uint index, string MAVT, string ten)
{
	NODE_TEMP_LIST* p = new NODE_TEMP_LIST;
	p->tl.index = index;
	p->tl.MAVT = MAVT;
	p->tl.ten = ten;
	p->next = NULL;
	return p;
}
void addTailList_Temp_List(LIST_TEMP_LIST& l, uint index, string MAVT, string ten)
{
	NODE_TEMP_LIST* p = getNode_Temp_List(index, MAVT, ten);
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->next = p;
		l.pTail = p;
	}
}

void Sort_Temp_list_Name(LIST_TEMP_LIST& l)
{
	if (l.pHead == NULL) return;
	NODE_TEMP_LIST* p1, * p2;
	for (p1 = l.pHead; p1 != NULL; p1 = p1->next)
	{
		for (p2 = p1->next; p2 != NULL; p2 = p2->next)
		{
			if (p1->tl.ten.length() > p2->tl.ten.length())
			{
				TEMP_LIST temp, temp2;
				temp.ten = p1->tl.ten;
				p1->tl.ten = p2->tl.ten;
				p2->tl.ten = temp.ten;
				temp2.MAVT = p1->tl.MAVT;
				p1->tl.MAVT = p2->tl.MAVT;
				p2->tl.MAVT = temp2.MAVT;
			}
		}
	}

}



