#pragma once

#include"struct.h"


void normalBGColor();
void XoaMotDong(int width);
void XoaMotVung(int x, int y, int ndoc, int width);

///////////////////////////////////////MENU CHINH///////////////////////////////////////
void EffectiveMenu(int pos, int flag);
void CreateBox(int x, int y, string text, int length);
void MainMenu(string key[], int nKey);
int ChooseMainMenu(int nKey);
void chuChay(char dChu[], int x, int y);
void VeKhungMenu();
void ManHinhChinh();
///////////////////////////////////////MENU VAT TU//////////////////////////////////////////
void EffectiveMenu_VatTu(int pos, int flag);
void Menu_Vat_Tu(string key[], int nKey);
///////////////////////////////////////MENU NHAN VIEN//////////////////////////////////////
void EffectiveMenu_Nhan_Vien(int pos, int flag);
void Menu_Nhan_Vien(string key[], int nKey);
///////////////////////////////////////MENU HOA DON///////////////////////////////////////
void EffectiveMenu_Hoa_Don(int pos, int flag);
void Menu_Hoa_Don(string key[], int nKey);
///////////////////////////////////////MENU BOTTON///////////////////////////////////////
void EffectiveSubMenu(string key[], int xSubMenu, int ykey[], int nkey, int pos, int flag);
void HighLight1(string key, int index, int x, int y[], int newColor, int oldColor);
void SubMainMenu1(string key[], int nKey);
void SubMainMenu2(string key[], int nKey);
void SubMainMenu3(string key[], int nKey);
void SubMainMenu4(string key[], int nKey);
int ChooseSubMenu(string key[], int xSubMenu, int ykey[], int nkey);
void DisplayVT(string key[], int nKey, int xDisplay[]);
void DisplayHD(string key[], int nKey, int xDisplay[], string MANV, string fullName, string so_hd, string ngay, string thang, string nam, char loai);
void DisplayCTHD(string key[], int nKey, int xDisplay[], int yDisplay_CTHD[]);
void BangGuides(int x, int y, int nngang, string key[], int nkey);
void BangNhap(int x, int y, int nngang, string key[], int nkey);
void Xoa_OutNV_1line(int locate);
void Xoa_OutCTHD_1line(int locate);
void Xoa_OutNV_29lines();
void Xoa_OutCTHD_18lines();

void normalBGColor()
{
	SetColor(4);//tim;
	SetBGColor(7);//xam;
}
void XoaMotDong(int width)
{
	SetBGColor(WHITE);
	cout << " " << setw(width) << setfill(' ') << " ";
}

void XoaMotVung(int x, int y, int ndoc, int width)
{
	for (int i = 0; i < ndoc; i++)
	{
		gotoxy(x, y + i);
		XoaMotDong(width);
	}
}
///////////////////////////////////////MENU TOP///////////////////////////////////////
void EffectiveMenu(int pos, int flag)
{
	// 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
	if (flag == 1)
	{


		ShowCur(false);
		gotoxy(xMainMenus[pos + 1] - 1, yMainMenu);
		SetBGColor(15); //nen chu khi chon
		SetColor(4);	//mau chu khi chon
		cout << keyMainMenu[pos + 1];

		gotoxy(xMainMenus[(pos + 3) % 4 + 1] - 1, yMainMenu);
		normalBGColor();
		cout << keyMainMenu[(pos + 3) % 4 + 1];
	}
	else if (flag == 2) {

		// 0 ---> 1; 1 ---> 2; 2 ----> 3 ; 3 ---> 0
		ShowCur(false);

		gotoxy(xMainMenus[pos + 1] - 1, yMainMenu);
		SetBGColor(15); //nen chu khi chon
		SetColor(4);	//mau chu khi chon
		cout << keyMainMenu[pos + 1];

		gotoxy(xMainMenus[(pos + 1) % 4 + 1] - 1, yMainMenu);
		normalBGColor();
		cout << keyMainMenu[(pos + 1) % 4 + 1];
	}
}
void CreateBox(int x, int y, string text, int length)
{
	gotoxy(x - 2, y - 1);
	cout << char(201) << setw(length) << setfill(char(205)) << char(205) << char(187);

	gotoxy(x - 2, y);
	cout << char(186) << text << setw(length - text.length() + 1) << setfill(' ') << char(186);

	gotoxy(x - 2, y + 1);
	cout << char(200) << setw(length) << setfill(char(205)) << char(205) << char(188);
}
void MainMenu(string key[], int nKey)
{
	SetBGColor(15);
	SetColor(2);
	CreateBox(xMainMenus[0], yMainMenu, key[0], (int)key[0].length());
	normalBGColor();
	for (int i = 1; i < nKey; i++)
	{
		CreateBox(xMainMenus[i], yMainMenu, key[i], (int)key[i].length());
	}
}
int ChooseMainMenu(int nKey)
{
	int currposMainMenu = -1;
	ShowCur(false);

	int kb_hit;
	while (true)
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
			{
				kb_hit = _getch();
			}

			switch (kb_hit)
			{
			case KEY_LEFT:


				if (currposMainMenu > 0)
				{
					currposMainMenu = currposMainMenu - 1;
				}
				else {
					currposMainMenu = nKey - 2;
				}

				EffectiveMenu(currposMainMenu, 2);
				break;

			case KEY_RIGHT: //key right

				if (currposMainMenu < nKey - 2)
				{
					currposMainMenu = currposMainMenu + 1;
				}
				else {
					currposMainMenu = 0;//move to first value in menu system
				}
				EffectiveMenu(currposMainMenu, 1);
				break;

			case ENTER: //enter

				return currposMainMenu;

			}
		}
	}

}

void chuChay(char dChu[], int x, int y)
{
	SetColor(WHITE);
	ShowCur(false);
	char c[80];
	int length = (int)strlen(dChu);
	for (int i = 0; i < length; i++) {
		strncpy(c, dChu + i, 80);  // copy tu phan tu thu i den cuoi chuoi
		c[79] = '\0';
		Sleep(200);
		gotoxy(x, y);
		SetColor(18);//XANH LUC;
		SetBGColor(7);//xam;
		cout << "                                                                                ";
		gotoxy(x, y); // vi tri de in dong chu chay
		cout << c;
		if (i == length - 1) i = 0;  // chay vo han

		if (_kbhit()) {
			normalBGColor();
			return;  // Co phim nhan vao thi dung
		}
	}
}

void VeKhungMenu()
{
	ShowCur(false);
	int i;
	gotoxy(xOrdinal, yOrdinal);
	// ve hang ngang tren
	for (i = 0; i <= xMax; i++)
	{
		SetColor(maukhung);
		cout << char(219);
	}

	// ve hang ngang duoi1
	gotoxy(xOrdinal, yOrdinal + 11);
	for (i = 0; i <= xMax; i++)
	{
		SetColor(maukhung);
		cout << char(219);
	}


	// ve hang ngang duoi2
	gotoxy(xOrdinal, yOrdinal + 15);
	for (i = 0; i <= xMax; i++)
	{
		SetColor(maukhung);
		cout << char(219);
	}
	// ve hang ngang duoi3
	gotoxy(xOrdinal, yOrdinal + 37);
	for (i = 0; i <= xMax; i++)
	{
		SetColor(maukhung);
		cout << char(219);
	}

	// ve hang doc trai
	for (int i = 0; i < yOrdinal + 37; i++)
	{
		gotoxy(xOrdinal, yOrdinal + i);
		SetBGColor(maukhung);
		cout << "  ";
	}

	// ve hang doc phai
	for (int i = 0; i < yOrdinal + 37; i++)
	{
		gotoxy(xMax - 1, yOrdinal + i);
		SetBGColor(maukhung);
		cout << "   ";
	}
}
void ManHinhChinh()
{
	clrscr();
	ShowCur(false);
	VeKhungMenu();

	normalBGColor();
	MainMenu(keyMainMenu, 5);
	normalBGColor();

	string a;
	int y = 2;

	// lay tu file va chi doc
	ifstream file;
	file.open(".\\file\\QuanLyThuVien.txt", ios::in);

	// Kiem tra xem file co ket noi duoc hay khong?
	if (file.good())
	{
		while (!file.eof()) {
			getline(file, a);
			SetColor(1 + rand() % 6);
			Sleep(20);
			gotoxy(30, y++);
			cout << a << endl;
		}
	}
	else  //Tra ve loi
	{
		cout << "Lien ket voi File QuanlyThuVien khong thanh cong! " << "\n";
	}

	normalBGColor();
	SetBGColor(BLACK);

	// set khung


	chuChay(dongChuChay, xOrdinal + 30, yOrdinal + 35);
	return;
}
//==============================Menubentrongvattu======================================



void EffectiveMenu_VatTu(int pos, int flag)
{
	// 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
	if (flag == 1)
	{
		ShowCur(false);
		gotoxy(xMainMenus_Vat_Tu[pos + 1] - 1, yMainMenu_Vat_Tu);
		SetBGColor(15); //nen chu khi chon
		SetColor(4);	//mau chu khi chon
		cout << keymenu_vat_tu[pos + 1];

		gotoxy(xMainMenus_Vat_Tu[(pos + 3) % 4 + 1] - 1, yMainMenu_Vat_Tu);
		normalBGColor();
		cout << keymenu_vat_tu[(pos + 3) % 4 + 1];
	}
	else if (flag == 2) {

		// 0 ---> 1; 1 ---> 2; 2 ----> 3 ; 3 ---> 0
		ShowCur(false);

		gotoxy(xMainMenus_Vat_Tu[pos + 1] - 1, yMainMenu_Vat_Tu);
		SetBGColor(15); //nen chu khi chon
		SetColor(4);	//mau chu khi chon
		cout << keymenu_vat_tu[pos + 1];

		gotoxy(xMainMenus_Vat_Tu[(pos + 1) % 4 + 1] - 1, yMainMenu_Vat_Tu);
		normalBGColor();
		cout << keymenu_vat_tu[(pos + 1) % 4 + 1];
	}
}

void Menu_Vat_Tu(string key[], int nKey)
{
	SetBGColor(15);
	SetColor(2);
	CreateBox(xMainMenus_Vat_Tu[0], yMainMenu_Vat_Tu, key[0], (int)key[0].length());
	normalBGColor();
	for (int i = 1; i < nKey; i++)
	{
		CreateBox(xMainMenus_Vat_Tu[i], yMainMenu_Vat_Tu, key[i], (int)key[i].length());
	}
}

//==============================Menubentrongnhanvien======================================



void EffectiveMenu_Nhan_Vien(int pos, int flag)
{
	// 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
	if (flag == 1)
	{
		ShowCur(false);
		gotoxy(xMainMenus_Nhan_Vien[pos + 1] - 1, yMainMenu_Nhan_Vien);
		SetBGColor(15); //nen chu khi chon
		SetColor(4);	//mau chu khi chon
		cout << keymenu_nhan_vien[pos + 1];

		gotoxy(xMainMenus_Nhan_Vien[(pos + 3) % 4 + 1] - 1, yMainMenu_Nhan_Vien);
		normalBGColor();
		cout << keymenu_nhan_vien[(pos + 3) % 4 + 1];
	}
	else if (flag == 2) {

		// 0 ---> 1; 1 ---> 2; 2 ----> 3 ; 3 ---> 0
		ShowCur(false);

		gotoxy(xMainMenus_Nhan_Vien[pos + 1] - 1, yMainMenu_Nhan_Vien);
		SetBGColor(15); //nen chu khi chon
		SetColor(4);	//mau chu khi chon
		cout << keymenu_nhan_vien[pos + 1];

		gotoxy(xMainMenus_Nhan_Vien[(pos + 1) % 4 + 1] - 1, yMainMenu_Nhan_Vien);
		normalBGColor();
		cout << keymenu_nhan_vien[(pos + 1) % 4 + 1];
	}
}

void Menu_Nhan_Vien(string key[], int nKey)
{
	SetBGColor(15);
	SetColor(2);
	CreateBox(xMainMenus_Nhan_Vien[0], yMainMenu_Nhan_Vien, key[0], (int)key[0].length());
	normalBGColor();
	for (int i = 1; i < nKey; i++)
	{
		CreateBox(xMainMenus_Nhan_Vien[i], yMainMenu_Nhan_Vien, key[i], (int)key[i].length());
	}
}

//==============================Menubentronghoadon======================================


void EffectiveMenu_Hoa_Don(int pos, int flag)
{
	// 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
	if (flag == 1)
	{
		ShowCur(false);
		gotoxy(xMainMenus_Hoa_Don[pos + 1] - 1, yMainMenu_Hoa_Don);
		SetBGColor(15); //nen chu khi chon
		SetColor(4);	//mau chu khi chon
		cout << keymenu_hoa_don[pos + 1];

		gotoxy(xMainMenus_Hoa_Don[(pos + 5) % 6 + 1] - 1, yMainMenu_Hoa_Don);
		normalBGColor();
		cout << keymenu_hoa_don[(pos + 5) % 6 + 1];
	}
	else if (flag == 2) {

		// 0 ---> 1; 1 ---> 2; 2 ----> 3 ; 3 ---> 0
		ShowCur(false);

		gotoxy(xMainMenus_Hoa_Don[pos + 1] - 1, yMainMenu_Hoa_Don);
		SetBGColor(15); //nen chu khi chon
		SetColor(4);	//mau chu khi chon
		cout << keymenu_hoa_don[pos + 1];

		gotoxy(xMainMenus_Hoa_Don[(pos + 1) % 6 + 1] - 1, yMainMenu_Hoa_Don);
		normalBGColor();
		cout << keymenu_hoa_don[(pos + 1) % 6 + 1];
	}
}

void Menu_Hoa_Don(string key[], int nKey)
{
	SetBGColor(15);
	SetColor(2);
	CreateBox(xMainMenus_Hoa_Don[0], yMainMenu_Hoa_Don, key[0], (int)key[0].length());
	normalBGColor();
	for (int i = 1; i < nKey; i++)
	{
		CreateBox(xMainMenus_Hoa_Don[i], yMainMenu_Hoa_Don, key[i], (int)key[i].length());
	}
}
//===================================MENU_DUOI==============================




void EffectiveSubMenu(string key[], int xSubMenu, int ykey[], int nkey, int pos, int flag)
{
	// 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
	if (flag == 1)
	{
		ShowCur(false);

		gotoxy(xSubMenu - 1, ykey[pos]);
		SetBGColor(15); //nen chu khi chon
		SetColor(1);	//mau chu khi chon
		cout << key[pos];

		gotoxy(xSubMenu - 1, ykey[(pos + nkey - 1) % nkey]);
		SetBGColor(7); // nen chu sau khi chon
		SetColor(16);	//mau chu sau khi chon
		cout << key[(pos + nkey - 1) % nkey];
	}
	else if (flag == 2)
	{
		// 0 ---> 1; 1 ---> 2; 2 ----> 3 ; 3 ---> 0
		ShowCur(false);

		gotoxy(xSubMenu - 1, ykey[pos]);
		SetBGColor(15);
		SetColor(1);
		cout << key[pos];

		gotoxy(xSubMenu - 1, ykey[(pos + 1) % nkey]);
		SetBGColor(7);
		SetColor(16);
		cout << key[(pos + 1) % nkey];
	}
}

void HighLight1(string key, int index, int x, int y[], int newColor, int oldColor)
{
	// den dia chi can highlight
	gotoxy(x - 1, y[index]);
	SetBGColor(newColor);
	SetColor(16); // mau chu dau tien;
	cout << key;
	SetBGColor(oldColor);
}

void SubMainMenu1(string key[], int nKey)
{
	normalBGColor();
	SetBGColor(7); //mau nen khung
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xSubMainMenus1, ySubMainMenus1[i], key[i], (int)key[i].length());
	}
	HighLight1(keySubMainMenu1[0], 0, xSubMainMenus1, ySubMainMenus1, 15, 1);
	ShowCur(false);
}

void SubMainMenu2(string key[], int nKey)
{
	normalBGColor();
	SetBGColor(7);
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xSubMainMenus2, ySubMainMenus2[i], key[i], (int)key[i].length());
	}
	HighLight1(keySubMainMenu2[0], 0, xSubMainMenus2, ySubMainMenus2, 15, AQUA);
	ShowCur(false);
}
void SubMainMenu3(string key[], int nKey)
{
	normalBGColor();
	SetBGColor(7);
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xSubMainMenus3, ySubMainMenus3[i], key[i], (int)key[i].length());
	}
	HighLight1(keySubMainMenu3[0], 0, xSubMainMenus3, ySubMainMenus3, 15, AQUA);
	ShowCur(false);
}
void SubMainMenu4(string key[], int nKey)
{
	normalBGColor();
	SetBGColor(7); //mau nen khung
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xSubMainMenus4, ySubMainMenus4[i], key[i], (int)key[i].length());
	}
	HighLight1(keySubMainMenu4[0], 0, xSubMainMenus4, ySubMainMenus4, 15, 1);
	ShowCur(false);
}
int ChooseSubMenu(string key[], int xSubMenu, int ykey[], int nkey)
{
	int currposSubMainMenu = 0;
	ShowCur(false);

	int kb_hit;
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
				if (currposSubMainMenu > 0)
				{
					currposSubMainMenu = currposSubMainMenu - 1;
				}
				else {
					currposSubMainMenu = nkey - 1;
				}

				EffectiveSubMenu(key, xSubMenu, ykey, nkey, currposSubMainMenu, 2);

				break;

			case KEY_DOWN:
				if (currposSubMainMenu < nkey - 1)
				{
					currposSubMainMenu = currposSubMainMenu + 1;
				}
				else {
					currposSubMainMenu = 0;
				}

				EffectiveSubMenu(key, xSubMenu, ykey, nkey, currposSubMainMenu, 1);

				break;

			case ESC:

				return -1;

			case ENTER:

				return currposSubMainMenu;
			}
		}
	}
}

void DisplayVT(string key[], int nKey, int xDisplay[])
{
	ShowCur(true);
	normalBGColor();

	// hien thi cac danh muc trong bang hien thi
	for (int i = 0; i < nKey; i++)
	{
		gotoxy(xDisplay[i] + 3, yDisplay + 1);
		cout << key[i];
	}

	//hien thi cot hai ben
	SetColor(BLACK);
	for (int j = yDisplay; j <= yDisplay + 32; j++)
	{
		for (int i = 0; i < nKey + 1; i++)
		{
			gotoxy(xDisplay[i], j);

			cout << char(186);
		}
	}

	//hien thi dong hai ben
	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++)
	{
		gotoxy(i, yDisplay);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
			cout << char(203);//nga 3
		else if (i == xDisplay[0])
		{
			cout << char(201); //moc phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(187);//moc trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplay + 2);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
			cout << char(206); //nga 4
		else if (i == xDisplay[0])
		{
			cout << char(204); //nga 3 sang phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(185);//nga 3 sang trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplay + 32);
		if (i == xDisplay[nKey])
		{
			cout << char(188); //nga 3 sang trai
		}
		else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
			cout << char(202);
		else if (i == xDisplay[0])
			cout << char(200); //nga 3 sang phai
		else
		{
			cout << char(205); //duong thang ngang
		}
	}
}

void DisplayHD(string key[], int nKey, int xDisplay[], string MANV, string fullName, string so_hd, string ngay, string thang, string nam, char loai)
{
	ShowCur(true);
	normalBGColor();

	//hien thi cot hai ben 
	// cua hoa don
	SetColor(BLACK);

	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++)
	{
		// cuoi
		gotoxy(i, yDisplay);
		if (i == xDisplay[0])
		{
			cout << char(201);
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(187);
		}
		else
		{
			cout << char(205);
		}
		// HOAN THANH XONG VE HOA DON THOI . CON LAM BANG CHI TIET HOA DON RIENG 
	}




	for (int j = yDisplay + 1; j <= yDisplay + 10; j++)
	{
		// giua
		gotoxy(xDisplay[0], j);
		cout << char(186);
		gotoxy(xDisplay[5], j);
		cout << char(186);

	}
	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++)
	{
		// cuoi
		gotoxy(i, yDisplay + 11);
		if (i == xDisplay[0])
		{
			cout << char(200);
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(188);
		}
		else
		{
			cout << char(205);
		}
	}
	gotoxy(xDisplay[0] + 1, yDisplay + 1);
	cout << "SO HOA DON: " << so_hd;
	gotoxy(xDisplay[0] + 1, yDisplay + 3);
	cout << "MA NHAN VIEN: " << MANV;
	gotoxy(xDisplay[0] + 1, yDisplay + 5);
	cout << "TEN NHAN VIEN: " << fullName;
	gotoxy(xDisplay[0] + 1, yDisplay + 7);
	cout << "NGAY: " << ngay;
	int x = wherex();
	gotoxy(x + 10, yDisplay + 7);
	cout << "THANG: " << thang;
	x = wherex();
	gotoxy(x + 10, yDisplay + 7);
	cout << "NAM: " << nam;
	if (loai == 'N' || loai == 'n')
	{
		gotoxy(xDisplay[0] + 1, yDisplay + 9);
		cout << "LOAI: " << "NHAP";

	}
	else if (loai == 'X' || loai == 'x')
	{
		gotoxy(xDisplay[0] + 1, yDisplay + 9);
		cout << "LOAI: " << "XUAT";
	}
	else
	{
		gotoxy(xDisplay[0] + 1, yDisplay + 9);
		cout << "LOAI: ";
	}

}

void DisplayCTHD(string key[], int nKey, int xDisplay[], int yDisplay_CTHD[])
{
	ShowCur(true);
	normalBGColor();

	// hien thi cac danh muc trong bang hien thi
	for (int i = 0; i < nKey; i++)
	{
		gotoxy(xDisplay[i] + 3, yDisplay_CTHD[0] + 1);
		cout << key[i];
	}
	gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[3] - 1);
	cout << "TONG: ";
	//hien thi cot hai ben
	SetColor(BLACK);
	for (int j = yDisplay_CTHD[0]; j <= yDisplay_CTHD[2]; j++)
	{
		for (int i = 0; i < nKey + 1; i++)
		{
			gotoxy(xDisplay[i], j);

			cout << char(186);
		}
	}

	//hien thi dong hai ben
	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++)
	{
		gotoxy(i, yDisplay_CTHD[0]);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
			cout << char(203);//nga 3
		else if (i == xDisplay[0])
		{
			cout << char(204); //moc phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(185);//moc trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplay_CTHD[0] + 2);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
			cout << char(206); //nga 4
		else if (i == xDisplay[0])
		{
			cout << char(204); //nga 3 sang phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(185);//nga 3 sang trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplay_CTHD[2] + 1);
		if (i == xDisplay[nKey])
		{
			cout << char(188); //nga 3 sang trai
		}
		else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
			cout << char(202);
		else if (i == xDisplay[0])
			cout << char(200); //nga 3 sang phai
		else
		{
			cout << char(205); //duong thang ngang
		}
	}

	// VE KHUNG THANH TOAN
	for (int i = xDisplayDS[0]; i <= xDisplayDS[nKey]; i++)
	{
		if (i == xDisplayDS[0])
		{
			gotoxy(i, yDisplay_CTHD[2] + 1);
			cout << char(204);
			gotoxy(i, yDisplay_CTHD[2] + 2);
			cout << char(186);
			gotoxy(i, yDisplay_CTHD[3]);
			cout << char(200);
		}
		else if (i == xDisplayDS[1] || i == xDisplayDS[2] || i == xDisplayDS[3] || i == xDisplayDS[4])
		{
			gotoxy(i, yDisplay_CTHD[2] + 1);
			cout << char(202);

			gotoxy(i, yDisplay_CTHD[3]);
			cout << char(205);
		}
		else if (i == xDisplayDS[nKey])
		{
			gotoxy(i, yDisplay_CTHD[2] + 1);
			cout << char(185);
			gotoxy(i, yDisplay_CTHD[2] + 2);
			cout << char(186);
			gotoxy(i, yDisplay_CTHD[3]);
			cout << char(188);
		}
		else
		{
			gotoxy(i, yDisplay_CTHD[2] + 1);
			cout << char(205);

			gotoxy(i, yDisplay_CTHD[3]);
			cout << char(205);
		}


	}



}


void BangGuides(int x, int y, int nngang, string key[], int nkey)
{
	int i;
	// ve khung
	SetBGColor(BLACK);
	SetColor(GREEN);
	for (i = 0; i < nkey + 2; i++)
	{
		gotoxy(x, y + i);
		if (i == 0)
		{
			cout << char(218) << setw(nngang) << setfill(char(196)) << char(191);
		}
		else if (i == nkey + 1)
		{
			cout << char(192) << setw(nngang) << setfill(char(196)) << char(217);
		}
		else {
			cout << char(245);
			cout << key[i - 1];
			gotoxy(x + nngang, y + i);
			cout << char(245);
		}
	}
	normalBGColor();
}

void BangNhap(int x, int y, int nngang, string key[], int nkey)
{
	int i;
	// ve khung
	SetBGColor(BLACK);
	SetColor(WHITE);
	for (i = 0; i < nkey + 2; i++)
	{
		gotoxy(x, y + i);
		if (i == 0)
		{
			cout << char(218) << setw(nngang) << setfill(char(196)) << char(191);
		}
		else if (i == nkey + 1)
		{
			cout << char(192) << setw(nngang) << setfill(char(196)) << char(217);
		}
		else {
			cout << char(245);
			cout << key[i - 1];
			gotoxy(x + nngang, y + i);
			cout << char(245);
		}
	}
	normalBGColor();
}

void Xoa_OutNV_1line(int locate)
{
	gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + locate);
	cout << setw(xDisplayDS[1] - xDisplayDS[0] - 1) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[1] + 1, yDisplay + 3 + locate);
	cout << setw(xDisplayDS[2] - xDisplayDS[1] - 1) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[2] + 2, yDisplay + 3 + locate);
	cout << setw(xDisplayDS[3] - xDisplayDS[2] - 3) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[3] + 3, yDisplay + 3 + locate);
	cout << setw(xDisplayDS[4] - xDisplayDS[3] - 3) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[4] + 3, yDisplay + 3 + locate);
	cout << setw(xDisplayDS[5] - xDisplayDS[4] - 3) << setfill(' ') << ' ';
}
void Xoa_OutDSHD_1line(int locate)
{
	gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + locate);
	cout << setw(xDisplayDS[1] - xDisplayDS[0] - 5) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[1] + 1, yDisplay + 3 + locate);
	cout << setw(xDisplayDS[2] - xDisplayDS[1] - 4) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[2] + 4, yDisplay + 3 + locate);
	cout << setw(xDisplayDS[3] - xDisplayDS[2] - 6) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[3] + 3, yDisplay + 3 + locate);
	cout << setw(xDisplayDS[3] - xDisplayDS[3] + 15) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[3] + 25, yDisplay + 3 + locate);
	cout << setw(xDisplayDS[5] - xDisplayDS[4] - 3) << setfill(' ') << ' ';
}
void Xoa_OutCTHD_1line(int locate)
{
	gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[1] + locate);
	cout << setw(xDisplayDS[1] - xDisplayDS[0] - 1) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[1] + 1, yDisplay_CTHD[1] + locate);
	cout << setw(xDisplayDS[2] - xDisplayDS[1] - 1) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[2] + 4, yDisplay_CTHD[1] + locate);
	cout << setw(xDisplayDS[3] - xDisplayDS[2] - 5) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[3] + 3, yDisplay_CTHD[1] + locate);
	cout << setw(xDisplayDS[4] - xDisplayDS[3] - 3) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[4] + 3, yDisplay_CTHD[1] + locate);
	cout << setw(xDisplayDS[5] - xDisplayDS[4] - 3) << setfill(' ') << ' ';
}
void Xoa_OutDSHD_29lines()
{
	for (int i = 0; i < NUMBER_LINES; i++)
	{
		Xoa_OutDSHD_1line(i);
	}
}
void Xoa_OutNV_29lines()
{
	for (int i = 0; i < NUMBER_LINES; i++)
	{
		Xoa_OutNV_1line(i);
	}
}

void Xoa_OutCTHD_18lines()
{
	for (int i = 0; i < NUMBER_LINES_CTHD; i++)
	{
		Xoa_OutCTHD_1line(i);
	}
}


