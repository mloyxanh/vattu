
#include"VE.h"
#include"GHI_DOC.h"
#include"Hoa_DON.h"
using namespace std;
int main()
{
	resizeConsole(GWIDTH, GHEIGHT);
	srand(time(NULL));
	TREE_VT t;
	DS_NV ds_nv;
	HOA_DON hd;
	NHAN_VIEN* nv;
	initTree_VT(t);
	Doc_File_VT(t);
	Doc_File_NV(ds_nv);

	while (true)
	{
		int result;
		normalBGColor();
		system("cls");
		ManHinhChinh();
		MainMenu(keyMainMenu, 5);
		int type = ChooseMainMenu(5);
		gotoxy(100, 30);
		cout << " ESC: Ve Menu Chinh";
		switch (type)
		{
		case 0:
			SubMainMenu1(keySubMainMenu1, 2);
			result = ChooseSubMenu(keySubMainMenu1, xSubMainMenus1, ySubMainMenus1, 2);
			if (result == 0)
			{
				normalBGColor();
				system("cls");
				Menu_VT(t);
			}
			else if (result == 1)
			{
				Menu_In_DS_VT(t);
			}
			break;
		case 1:
			SubMainMenu2(keySubMainMenu2, 2);
			result = ChooseSubMenu(keySubMainMenu2, xSubMainMenus2, ySubMainMenus2, 2);
			if (result == 0)
			{
				normalBGColor();
				system("cls");
				Menu_NV(ds_nv);
			}
			else if (result == 1)
			{
				Menu_In_DS_NV(ds_nv);
			}
			break;
		case 2:
			SubMainMenu3(keySubMainMenu3, 3);
			result = ChooseSubMenu(keySubMainMenu3, xSubMainMenus3, ySubMainMenus3, 3);
			if (result == 0)
			{
				clrscr();
				normalBGColor();
				int esc = 1;
				while (esc)
				{
					nv = Menu_NV_Lap_HD(ds_nv);
					if (nv != NULL)
					{
						Menu_HD(t, ds_nv, nv);
					}
					if (_kbhit)

					{
						int kbhit = _getch();
						if (kbhit == ESC) esc = 0;
					}
				}
			}
			else if (result == 1)
			{
				Menu_Tim_Kiem_HD(t, ds_nv);

			}
			else if (result == 2)
			{
				clrscr();
				normalBGColor();
				int result2;
				SubMainMenu4(keySubMainMenu4, 2);
				result2 = ChooseSubMenu(keySubMainMenu4, xSubMainMenus4, ySubMainMenus4, 2);
				if (result2 == 0)
				{
					normalBGColor();
					clrscr();
					Menu_IN_DS_HD(ds_nv);
				}
				else
				{
					normalBGColor();
					clrscr();
					Menu_IN_10_VT(t, ds_nv);
				}
			}
			break;
		case 3:
		{
			Ghi_File_VT(t);
			Ghi_File_NV(ds_nv);
			GiaiPhongTree(t);
			GiaiPhongNV(ds_nv);
			return 0;
		}
		break;
		}

	}
	system("pause");
	return 0;
}