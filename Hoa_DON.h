#pragma once
#include"Vattu.h"
#include"Nhanvien.h"
//////////////////////////HOA DON VA CHI TIET HOA DON////////////////////////////////////
/////////////////HOA DON ///////////////
string Tao_Ma_HD(DS_NV ds_nv);
void Them_HD_Vao_DS(HOA_DON hd, DS_HD& ds_hd);
void NhapNgay(string& result, int choice, int& ordinal, bool& isSave, bool& isEscape);
int countds_hd(DS_HD ds);
void Nhap_HD(TREE_VT t, DS_NV ds_nv, NHAN_VIEN* nv, HOA_DON& hd);
NHAN_VIEN* Find_NV(DS_NV ds_nv, NODE_HD* node_hd);
////////////CHI TIET HOA DON ///////////
int Full_CTHD(DS_CT_HD ds);
int Insert_CTHD(DS_CT_HD& ds, CHI_TIET_HOA_DON cthd);
void Output_CTHD(TREE_VT t, CHI_TIET_HOA_DON cthd);
void OutputCTHD_PerPage(DS_CT_HD ds_cthd, LIST_TEMP_LIST l, int index);
int Output_ListCTHD(TREE_VT t, DS_CT_HD& ds_ct_hd, CHI_TIET_HOA_DON& cthd, int& tttrang, NHAN_VIEN* nv);
int ChooseItems_CTHD(TREE_VT t, DS_CT_HD& ds_ct_hd, int& tttrang, int tongtrang);
void Update_CTHD(HOA_DON hd, DS_CT_HD& ds_ct_hd, CHI_TIET_HOA_DON& cthd, bool isEdited, TREE_VT t, int& pos);

///////////NHAN VIEN LAP HOA DON///////
NHAN_VIEN* Menu_NV_Lap_HD(DS_NV ds);
void Menu_HD(TREE_VT t, DS_NV ds_nv, NHAN_VIEN* nv);
void Menu_CTHD(TREE_VT t, NHAN_VIEN* nv, HOA_DON& hd);


//////////TIM KIEM VAT TU TRONG LUC LAP HOA DON /////////////////////////
void Menu_Tim_Kiem_VT(TREE_VT t);
void Create_Temp_Search_List(TREE_VT t, LIST_TEMP_LIST& l, int& index, string Key);
int countVT_TempList(LIST_TEMP_LIST l);
void NhapTenVT_TimKiem(string& result, int& ordinal, bool& isSave, bool& isEscape);
int Output_SearchVT_List(TREE_VT t, int& tttrang);
void Bang_Nhap_Ten_VT(TREE_VT t, LIST_TEMP_LIST& l, bool& kt);

/////////////////IN HOA DON KHOANG NGAY////////////
void NhapNgay2(string& result, int choice, int& ordinal, bool& isSave, bool& isEscape);
void OutputHD_PerPage(DS_NV ds, int index, ngay_lap_hd NgayTruoc, ngay_lap_hd NgaySau);
void OutputCTHD_PerPage(TREE_VT t, DS_CT_HD ds_ct_hd, int index);
void Nhap_Khoang_Ngay(NGAY_LAP_HD& NgayTruoc, NGAY_LAP_HD& NgaySau, bool& isEscape);
void Menu_IN_DS_HD(DS_NV ds_nv);
void Ds_HD_Temp(DS_HD& ds_hd_temp, DS_NV ds_nv);
void Ds_VT_Gia(TREE_VT t, DS_VAT_TU_GIA& ds_vt_gia);
void GiaiPhongVTGia(DS_VAT_TU_GIA& ds_vt_gia);
void Menu_IN_10_VT(TREE_VT t, DS_NV ds_nv);

/////////////////IN HOA DON THEO MA HOA DON////////////
void NhapTenHD_TimKiem(string& result, int& ordinal, bool& isSave, bool& isEscape);
void Bang_Nhap_Ten_HD(TREE_VT t, DS_NV ds_nv, bool& kt);
int Output_SearchHD_List(TREE_VT t, DS_NV ds_nv);
void Menu_Tim_Kiem_HD(TREE_VT t, DS_NV ds_nv);
string int_to_string(int a);
void GiaiPhongDSHD(DS_HD& ds_hd);
///////////////////NGAY THANG NAM//////////////////////
int KiemTraNam(int yy, int mm);
void SoNgayTrongThang(int yy, int mm, int a[13]);
int KiemTraNgay(int dd, int mm, int yy);
int kiem_tra_truoc_hien_tai(int dd, int mm, int yy);
int kiem_tra_khoang_ngay(ngay_lap_hd ngay_truoc, ngay_lap_hd ngay_sau);
int kiem_tra_ngay_hd(ngay_lap_hd ngay_ht, ngay_lap_hd ngay_truoc, ngay_lap_hd ngay_sau);


string int_to_string(int a)
{
	stringstream s;
	s << a;
	string str = s.str();
	return str;
}


void Output_CTHD(TREE_VT t, CHI_TIET_HOA_DON cthd)
{
	Xoa_OutCTHD_1line(locate);
	gotoxy(xDisplayDS[0] + 3, yDisplay_CTHD[1] + locate);
	cout << cthd.MAVT;
	gotoxy(xDisplayDS[1] + 1, yDisplay_CTHD[1] + locate);
	NODE_VT* vt_temp = find_VT(t, cthd.MAVT);
	cout << vt_temp->VT.ten;
	gotoxy(xDisplayDS[2] + 4, yDisplay_CTHD[1] + locate);
	cout << cthd.so_luong;
	gotoxy(xDisplayDS[3] + 3, yDisplay_CTHD[1] + locate);
	cout << cthd.thue;
	gotoxy(xDisplayDS[4] + 3, yDisplay_CTHD[1] + locate);
	cout << cthd.don_gia;
	locate++;
}
void Them_HD_Vao_DS(HOA_DON hd, DS_HD& ds_hd)
{
	NODE_HD* p = new NODE_HD;

	p->HD = hd;
	p->next = NULL;
	if (ds_hd.pHead == NULL)
	{
		ds_hd.pHead = ds_hd.pTail = p;
	}
	else
	{
		ds_hd.pTail->next = p;
		ds_hd.pTail = p;
	}
}
void GiaiPhongDSHD(DS_HD& ds_hd)
{
	NODE_HD* p;
	while (ds_hd.pHead != NULL)
	{
		p = ds_hd.pHead;
		ds_hd.pHead = ds_hd.pHead->next;
		delete p;
	}
}
void NhapNgay(string& result, int choice, int& ordinal, bool& isSave, bool& isEscape)
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
			if (((kb_hit >= 48 && kb_hit <= 57))
				&& count < ((choice == 2) ? MAX_NAM : MAX_NGAY) && count >= 0)
			{
				// xoa dong thong bao
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				cout << setw(60) << setfill(' ') << " ";
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
				// xay ra 3 truong hop 
				if (choice == 0) // nhap ngay
				{
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
				else if (choice == 1) // nhap thang
				{
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
				else if (choice == 2) // nhap nam
				{
					if (kb_hit == KEY_UP)
					{
						ordinal = 1;
						return;
					}
					else
					{
						ordinal = 3;
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
					ordinal = 3;
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
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				if (choice == 0 || choice == 1)
				{
					cout << " TOI DA " << MAX_NGAY << " CHU SO !!!";
				}
				else
				{
					cout << " TOI DA " << MAX_NAM << " CHU SO !!!";
				}

				normalBGColor();
				gotoxy(x, y);
			}
		}

	}
}
int countds_hd(DS_HD ds)

{
	int count = 0;
	for (NODE_HD* k = ds.pHead; k != NULL; k = k->next)
	{
		count++;
	}
	return count;
}
int Full_CTHD(DS_CT_HD ds)
{
	return ds.n == MAX_CT_HD;
}
int Insert_CTHD(DS_CT_HD& ds, CHI_TIET_HOA_DON cthd)
{
	if (Full_CTHD(ds))
		return 0;
	ds.ds[ds.n++] = cthd;
	return 1;
}
void Update_CTHD(HOA_DON hd, DS_CT_HD& ds_ct_hd, CHI_TIET_HOA_DON& cthd, bool isEdited, TREE_VT t, int& pos)
{
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();

	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 0;
	bool isSave = false;
	bool isEscape = false;

	// chieu dai bang nhap
	int nngang = (int)keyBangNhapCTHD[0].length();

	// cac bien luu tru tam thoi
	string MAVT = "VT";
	string so_luong = "";
	string thue = "";
	string don_gia = "";

	CreateBox(X_NOTIFY + 3, Y_NOTIFY, "NOTIFICATIONS:  ", 59);
	BangNhap(xDisplayDS[5] + 7, yDisplay, nngang, keyBangNhapCTHD, 10);
	BangGuides(xDisplayDS[5] + 7, yDisplay + 20, nngang, keyGuideCTHD, 5);

	//////////// DE SUA CHI TIET HOA DON. LAM SAU....
	if (isEdited)
	{
		// chinh sua thue, so luong, don gia
		MAVT = cthd.MAVT;
		thue = int_to_string(cthd.thue);
		so_luong = int_to_string(cthd.so_luong);
		don_gia = int_to_string(cthd.don_gia);
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);
		cout << MAVT;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);
		cout << thue;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
		cout << so_luong;
		gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 9);
		cout << don_gia;
	}

	while (true) {

		if (isEdited)
		{

			switch (ordinal)
			{
			case 0: // thue
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);
				NhapSoLuongTon(thue, NHAP_THUE_EDITED, ordinal, isSave, isEscape); // tương tự như trên
				break;
			case 1:
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
				NhapSoLuongTon(so_luong, NHAP_SO_LUONG_EDITED, ordinal, isSave, isEscape); // tương tự như trên
				break;
			case 2:
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 9);
				NhapSoLuongTon(don_gia, NHAP_DON_GIA_EDITED, ordinal, isSave, isEscape);
				break;
			}
		}
		else  // not edited
		{
			switch (ordinal)
			{
			case 0: // nhap ma vat tu
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);
				Nhap_Ma_VT(MAVT, ordinal, isSave, isEscape);
				break;
			case 1: // thue
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);
				NhapSoLuongTon(thue, NHAP_THUE, ordinal, isSave, isEscape); // tương tự như trên
				break;
			case 2: // nhap so luong
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
				NhapSoLuongTon(so_luong, NHAP_SO_LUONG, ordinal, isSave, isEscape); // tương tự như trên
				break;
			case 3:
				gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 9);
				NhapSoLuongTon(don_gia, NHAP_DON_GIA, ordinal, isSave, isEscape);
				break;
			}

		}



		// check Save
		if (isSave)
		{
			// cap nhat lai flag
			isSave = false;

			// check rong;
			if (MAVT.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}
			else if (thue.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}
			else if (so_luong.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}
			else if (don_gia.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 3;
				continue;
			}

			// kiem tra trong vat tu co ton tai ma vat tu
			if (MAVT.length() != 0)
			{
				NODE_VT* vt_temp = find_VT(t, MAVT);
				if (vt_temp == NULL)
				{
					gotoxy(X_NOTIFY + 17, Y_NOTIFY);
					SetColor(BLUE);
					cout << "MA VAT TU KHONG TON TAI !!! ";
					normalBGColor();
					ordinal = 0;
					continue;
				}
				else // Kiểm tra xem trong chi tiết hoá đơn đã tồn tại chi tiết này chưa 
				{
					if (!isEdited)
					{
						for (int i = 0; i < ds_ct_hd.n; i++)
						{
							if (ds_ct_hd.ds[i].MAVT == vt_temp->VT.MAVT)
							{
								// cập nhật vị trí trùng trong chi tiết hoá đơn 
								pos = i;
								// in thông báo
								for (int i = 0; i < 5; i++)
								{
									SetColor(BLUE);
									gotoxy(X_NOTIFY + 17, Y_NOTIFY);
									Sleep(100);
									cout << "CHI TIET NAY DA CO TRONG HOA DON. HAY CHINH SUA";
									Sleep(500);
								}
								XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
								return;
							}
						}
					}

				}

			}

			// kiểm tra nếu loại hoá đơn là xuất thì kiểm trong kho còn đủ hàng không
			if (hd.loai == 'x' || hd.loai == 'X')
			{
				if (so_luong.length() != 0) // nếu nhập số lượng không trống
				{
					NODE_VT* vt_temp = find_VT(t, MAVT); // chắc chắn tồn tại mã vật tư 
					int so_luong_temp = atoi(so_luong.c_str());
					if (so_luong_temp > vt_temp->VT.so_luong_ton)
					{
						gotoxy(X_NOTIFY + 17, Y_NOTIFY);
						SetColor(BLUE);
						cout << "SO LUONG TRONG KHO KHONG DU (CON LAI: " << vt_temp->VT.so_luong_ton << ").";
						normalBGColor();
						if (isEdited)
						{
							ordinal = 1;
							continue;
						}
						ordinal = 2;
						continue;
					}
				}
			}



			cthd.MAVT = MAVT;
			cthd.thue = atoi(thue.c_str());
			cthd.so_luong = atoi(so_luong.c_str());
			cthd.don_gia = atoi(don_gia.c_str());






			//  CHINH SUA THI KHONG THEM
				 // thuật toán thêm vào danh sách chi tiet hoa don
			if (!isEdited)
			{
				int temp = Insert_CTHD(ds_ct_hd, cthd);
				if (temp == 0)
				{
					// thong bao ra.
					for (int i = 0; i < 5; i++)
					{
						SetColor(BLUE);
						gotoxy(X_NOTIFY + 17, Y_NOTIFY);
						Sleep(100);
						cout << "BO NHO DA DAY .KHONG THEM CHI TIET MOI VAO DUOC!";
						Sleep(500);
					}
				}
				else
				{
					// In dong thong bao .
					for (int i = 0; i < 5; i++)
					{
						SetColor(BLUE);
						gotoxy(X_NOTIFY + 17, Y_NOTIFY);
						Sleep(100);
						cout << "           SUCCESSFULLY !!! ";
					}
				}
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
void Nhap_HD(TREE_VT t, DS_NV ds_nv, NHAN_VIEN* nv, HOA_DON& hd)
{
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();

	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 0;
	bool isSave = false;
	bool isEscape = false;

	// chieu dai bang nhap
	int nngang = (int)keyBangNhapHD[0].length();

	// cac bien luu tru tam thoi
	time_t now = time(0);

	tm* ltm = localtime(&now);

	string ngay = "";
	string thang = "";
	string nam = "";
	uint loai = 3;
	string MAHD;

	CreateBox(X_NOTIFY + 3, Y_NOTIFY, "NOTIFICATIONS:  ", 48);
	BangNhap(xDisplayDS[5] + 7, yDisplay, nngang, keyBangNhapHD, 12);
	BangGuides(xDisplayDS[5] + 7, yDisplay + 20, nngang, keyGuideHD, 3);

	MAHD = Tao_Ma_HD(ds_nv);

	gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);
	cout << MAHD;


	// so lan quay lai nhap ngay, thang, nam
	bool kt_ngay = 1;
	bool kt_thang = 1;
	bool kt_nam = 1;

	while (true) {

		switch (ordinal)
		{

		case 0:
			if (kt_ngay == 1)
			{
				ngay = int_to_string(ltm->tm_mday);
				kt_ngay = 0;
			}
			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 5);
			NhapNgay(ngay, NHAP_NGAY, ordinal, isSave, isEscape);
			break;
		case 1:
			if (kt_thang == 1)
			{
				thang = int_to_string(1 + ltm->tm_mon);
				kt_thang = 0;
			}

			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 7);
			NhapNgay(thang, NHAP_THANG, ordinal, isSave, isEscape);
			break;
		case 2:
			if (kt_nam == 1)
			{
				nam = int_to_string(1900 + ltm->tm_year);
				kt_nam = 0;
			}
			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 9);
			NhapNgay(nam, NHAP_NAM, ordinal, isSave, isEscape);
			break;
		case 3:
			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 11);
			Nhap(loai, NHAP_LOAI, ordinal, isSave, isEscape);
			break;
		}

		// check Save
		if (isSave)
		{
			// cap nhat lai flag
			isSave = false;

			// check rong;
			if (ngay.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}
			else if (thang.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}
			else if (nam.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}
			else if (loai == 3)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 3;
				continue;
			}

			if (atoi(nam.c_str()) > 2000)
			{
				if (atoi(thang.c_str()) > 0 && atoi(thang.c_str()) <= 12)
				{
					if (KiemTraNgay(atoi(ngay.c_str()), atoi(thang.c_str()), atoi(nam.c_str())) == 1)
					{

						if (kiem_tra_truoc_hien_tai(atoi(ngay.c_str()), atoi(thang.c_str()), atoi(nam.c_str())) != 1)

						{
							gotoxy(X_NOTIFY + 17, Y_NOTIFY);
							SetColor(BLUE);
							cout << "NHAP THOI GIAN TRUOC HOAC BANG HT";
							normalBGColor();

							// quay lai va dien vao truong du lieu do
							ordinal = 0;
							continue;
						}

					}
					else
					{
						gotoxy(X_NOTIFY + 17, Y_NOTIFY);
						SetColor(BLUE);
						cout << "DINH DANG NGAY SAI !!!                     ";
						normalBGColor();

						// quay lai va dien vao truong du lieu do
						ordinal = 0;
						continue;
					}
				}
				else
				{
					gotoxy(X_NOTIFY + 17, Y_NOTIFY);
					SetColor(BLUE);
					cout << "NHAP THANG KHONG PHU HOP !!!               ";
					normalBGColor();

					// quay lai va dien vao truong du lieu do
					ordinal = 1;
					continue;
				}
			}
			else
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "NHAP NAM KHONG PHU HOP !!!                 ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}


			hd.MAHD = MAHD;
			hd.ngay_lap_hd.Ngay = atoi(ngay.c_str());
			hd.ngay_lap_hd.Thang = atoi(thang.c_str());
			hd.ngay_lap_hd.Nam = atoi(nam.c_str());
			hd.loai = (char)loai;

			// In dong thong bao .
			for (int i = 0; i < 5; i++)
			{
				SetColor(BLUE);
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				Sleep(100);
				cout << "    SUCCESSFULLY !!!                 ";
			}
			normalBGColor();
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
			system("cls");
			string fullName = nv->ho + " " + nv->ten;
			DisplayHD(keyDisplayCTHD, 5, xDisplayDS, int_to_string(nv->MANV), fullName, MAHD, ngay, thang, nam, loai);
			// lam menu them chi tiet hoa don trong day
			DisplayCTHD(keyDisplayCTHD, 5, xDisplayDS, yDisplay_CTHD);
			// menu chi tiet hoa do
			Menu_CTHD(t, nv, hd);
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
int Output_ListCTHD(TREE_VT t, HOA_DON& hd, CHI_TIET_HOA_DON& cthd, int& tttrang, NHAN_VIEN* nv)
{
	int choose;
	bool check;

	// nCTHD la so CTHD hien co
	int nCTHD = (hd.ds_ct_hd.n);

	// thu tu trang
	int tongtrang;
	tongtrang = (nCTHD / NUMBER_LINES_CTHD) + 1;
	OutputCTHD_PerPage(t, hd.ds_ct_hd, tttrang);

	int kb_hit;
	int currposMainMenu = -1;
	int nKey = 7;
	do
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			int pos = -1;
			switch (kb_hit)
			{
			case PAGE_UP: // di ve trang truoc
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				OutputCTHD_PerPage(t, hd.ds_ct_hd, tttrang);
				break;

			case PAGE_DOWN:
				(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
				OutputCTHD_PerPage(t, hd.ds_ct_hd, tttrang);
				break;

			case KEY_F2: // them
			{

				Update_CTHD(hd, hd.ds_ct_hd, cthd, false, t, pos);
				if (pos > -1) // neu pos >=0 thi dua tu dong den vi tri edit
				{
					int temp = -1; // temp cua pos
					Update_CTHD(hd, hd.ds_ct_hd, hd.ds_ct_hd.ds[pos], true, t, temp);
				}
				return 1;
			}
			case KEY_F3: // sua
			{
				choose = ChooseItems_CTHD(t, hd.ds_ct_hd, tttrang, tongtrang);

				if (choose < hd.ds_ct_hd.n)
				{
					int temp = -1; // temp cua pos
					Update_CTHD(hd, hd.ds_ct_hd, hd.ds_ct_hd.ds[choose], true, t, temp);
					return 1;
				}
				return 1;
			}
			case KEY_F5: // tim kiem vat tu
			{
				Menu_Tim_Kiem_VT(t);
				return 1;
			}

			case KEY_F4: // xoa
			{
				choose = ChooseItems_CTHD(t, hd.ds_ct_hd, tttrang, tongtrang);


				if (choose < hd.ds_ct_hd.n)
				{
					for (int i = choose; i < hd.ds_ct_hd.n; i++) // xoa vi tri thu i
					{
						hd.ds_ct_hd.ds[i] = hd.ds_ct_hd.ds[i + 1];
					}
					hd.ds_ct_hd.n--;
				}
				return 1;
			}

			case KEY_F7: // thanh toan
			{
				hd.tong_tien = 0;
				if (hd.ds_ct_hd.n == 0)
				{
					for (int i = 0; i < 5; i++)
					{
						gotoxy(X_NOTIFY + 17, Y_NOTIFY);
						SetColor(BLUE);
						Sleep(100);
						cout << "HOA DON CHUA NHAP VAT TU !!!";
						Sleep(500);
					}
					normalBGColor();
					continue;
				}

				for (int i = 0; i < hd.ds_ct_hd.n; i++)
				{
					hd.tong_tien += ((hd.ds_ct_hd.ds[i].so_luong * hd.ds_ct_hd.ds[i].don_gia) * (1 + ((float)hd.ds_ct_hd.ds[i].thue / 100)));
				}
				gotoxy(xDisplayDS[0] + 8, yDisplay_CTHD[3] - 1);
				SetColor(REG_DWORD);
				cout << std::fixed << hd.tong_tien;
				system("pause");
				Them_HD_Vao_DS(hd, nv->ds_hd);
				Cap_Nhat_Vat_Tu(t, hd, hd.ds_ct_hd);
				return 0;
			}
			case ESC:
			{
				return 0;
			}
			case KEY_LEFT:


				if (currposMainMenu > 0)
				{
					currposMainMenu = currposMainMenu - 1;
				}
				else {
					currposMainMenu = nKey - 2;
				}

				EffectiveMenu_Hoa_Don(currposMainMenu, 2);
				break;

			case KEY_RIGHT: //key right

				if (currposMainMenu < nKey - 2)
				{
					currposMainMenu = currposMainMenu + 1;
				}
				else {
					currposMainMenu = 0;//move to first value in menu system
				}
				EffectiveMenu_Hoa_Don(currposMainMenu, 1);
				break;

			case ENTER: //enter

				switch (currposMainMenu)
				{
				case 0:

					Update_CTHD(hd, hd.ds_ct_hd, cthd, false, t, pos);
					if (pos > -1)
					{
						int temp = -1; // temp cua pos
						Update_CTHD(hd, hd.ds_ct_hd, hd.ds_ct_hd.ds[pos], true, t, temp);
					}
					return 1;

				case 1:
					choose = ChooseItems_CTHD(t, hd.ds_ct_hd, tttrang, tongtrang);
					gotoxy(100, 35);
					cout << hd.ds_ct_hd.ds[0].don_gia << hd.ds_ct_hd.ds[0].thue;
					if (choose < hd.ds_ct_hd.n)
					{
						int temp = -1; // temp cua pos
						Update_CTHD(hd, hd.ds_ct_hd, hd.ds_ct_hd.ds[choose], true, t, temp);
						return 1;
					}
					return 1;

				case 2:
					choose = ChooseItems_CTHD(t, hd.ds_ct_hd, tttrang, tongtrang);


					if (choose < hd.ds_ct_hd.n)
					{
						for (int i = choose; i < hd.ds_ct_hd.n; i++) // xoa vi tri thu i
						{
							hd.ds_ct_hd.ds[i] = hd.ds_ct_hd.ds[i + 1];
						}
						hd.ds_ct_hd.n--;
					}
					return 1;
				case 3:
					Menu_Tim_Kiem_VT(t);
					return 1;
				case 4:
					hd.tong_tien = 0;
					if (hd.ds_ct_hd.n == 0)
					{
						for (int i = 0; i < 5; i++)
						{
							gotoxy(X_NOTIFY + 17, Y_NOTIFY);
							SetColor(BLUE);
							Sleep(100);
							cout << "HOA DON CHUA NHAP VAT TU !!!";
							Sleep(500);
						}
						normalBGColor();
						continue;
					}

					for (int i = 0; i < hd.ds_ct_hd.n; i++)
					{
						hd.tong_tien += ((hd.ds_ct_hd.ds[i].so_luong * hd.ds_ct_hd.ds[i].don_gia) * (1 + ((float)hd.ds_ct_hd.ds[i].thue / 100)));
					}
					gotoxy(xDisplayDS[0] + 8, yDisplay_CTHD[3] - 1);
					SetColor(REG_DWORD);
					cout << std::fixed << hd.tong_tien;
					system("pause");
					Them_HD_Vao_DS(hd, nv->ds_hd);
					Cap_Nhat_Vat_Tu(t, hd, hd.ds_ct_hd);
					return 0;
				case 5: return 0;


				}

			}

		}
		ShowCur(false);
		SetColor(BLACK);
		gotoxy(1, 38);
		cout << "Trang " << tttrang << "/" << tongtrang;
	} while (true);


}

NHAN_VIEN* Menu_NV_Lap_HD(DS_NV ds)
{
	clrscr();
	gotoxy(15, 1);
	cout << "~~~CHON NHAN VIEN LAP HOA DON~~~ ";
	normalBGColor();

	int nDS = ds.n + 1;
	int choose;

	gotoxy(3, yHotkey);
	SetColor(BLACK);
	cout << "ESC-Thoat, Enter-Chon Nhan Vien Lap ,PgUP, PgDn";
	normalBGColor();

	// thu tu trang
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;

label1:
	XoaMotVung(79, yDisplay, 30, 53);
	DisplayVT(keyDisplayNV, 4, xDisplayDS);
	OutputNV_PerPage(ds, tttrang);
	int kb_hit;
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

			case ESC:
				return NULL;

			default:
				choose = ChooseItems_NV(ds, tttrang, tongtrang);
				if (choose > ds.n || choose < 0)
					goto label1;
				return ds.ds[choose];

			}


		}
	} while (true);
}
void Menu_HD(TREE_VT t, DS_NV ds_nv, NHAN_VIEN* nv)
{
	clrscr();
	normalBGColor();


	clrscr();
	gotoxy(26, 1);
	cout << "~~~ LAP HOA DON ~~~ ";


	gotoxy(3, yHotkey);
	SetColor(BLACK);
	cout << "ESC-Thoat, F10 - Luu";

	normalBGColor();

	HOA_DON hd;

	int index = 0;
	string fullName = nv->ho + " " + nv->ten;

	DisplayHD(keyDisplayCTHD, 5, xDisplayDS, int_to_string(nv->MANV), fullName, "", "", "", "", 3);
	Nhap_HD(t, ds_nv, nv, hd);
}
void Menu_CTHD(TREE_VT t, NHAN_VIEN* nv, HOA_DON& hd)
{
	int tttrang = 1;
	int esc = 1;

	do
	{
		clrscr();
		DisplayHD(keyBangNhapHD, 5, xDisplayDS, int_to_string(nv->MANV), nv->ho + " " + nv->ten, hd.MAHD, int_to_string(hd.ngay_lap_hd.Ngay), int_to_string(hd.ngay_lap_hd.Thang), int_to_string(hd.ngay_lap_hd.Nam), hd.loai);
		DisplayCTHD(keyDisplayCTHD, 5, xDisplayDS, yDisplay_CTHD);
		gotoxy(135, yHotkey + 3);
		SetColor(GREEN);
		cout << "F10-LUU";
		Menu_Hoa_Don(keymenu_hoa_don, 7);
		normalBGColor();
		CHI_TIET_HOA_DON cthd;
		int index = 0;


		esc = Output_ListCTHD(t, hd, cthd, tttrang, nv);

	} while (esc);

}
int ChooseItems_CTHD(TREE_VT t, DS_CT_HD& ds_ct_hd, int& tttrang, int tongtrang)
{

	int kb_hit;
	int pos = 0;
	SetColor(REG_DWORD);
	gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[1] + pos);
	cout << "<<";
	gotoxy(xDisplayDS[0] + 2 + 7, yDisplay_CTHD[1] + pos);
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
				gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[1] + pos);
				cout << "  ";
				gotoxy(xDisplayDS[0] + 2 + 7, yDisplay_CTHD[1] + pos);
				cout << "  ";

				(pos > 0) ? pos-- : pos = 17;

				// to mau muc moi
				gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[1] + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 2 + 7, yDisplay_CTHD[1] + pos);
				cout << ">>";
				break;

			case KEY_DOWN:
				// xoa muc truoc
				gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[1] + pos);
				cout << "  ";
				gotoxy(xDisplayDS[0] + 2 + 7, yDisplay_CTHD[1] + pos);
				cout << "  ";

				(pos < NUMBER_LINES_CTHD - 1) ? pos++ : pos = 0;

				// to mau muc moi
				gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[1] + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 2 + 7, yDisplay_CTHD[1] + pos);
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
				OutputCTHD_PerPage(t, ds_ct_hd, tttrang);

				// high light hang dau.
				pos = 0;
				SetColor(REG_DWORD);
				gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[1] + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 2 + 7, yDisplay_CTHD[1] + pos);
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

				OutputCTHD_PerPage(t, ds_ct_hd, tttrang);

				// high light hang dau.
				pos = 0;
				SetColor(REG_DWORD);
				gotoxy(xDisplayDS[0] + 1, yDisplay_CTHD[1] + pos);
				cout << "<<";
				gotoxy(xDisplayDS[0] + 2 + 7, yDisplay_CTHD[1] + pos);
				cout << ">>";
				break;
			case ENTER:

				// tra ve vi tri pos.
				return (tttrang == 1) ? pos : pos + (tttrang - 1) * NUMBER_LINES_CTHD;
			}
		}
		ShowCur(false);
		SetColor(WHITE);
		normalBGColor();
	}
}
////////////////// TIM KIEM VAT TU TRONG LUC LAP HOA DON /////////////////////////
void Menu_Tim_Kiem_VT(TREE_VT t)
{
	clrscr();
	normalBGColor();
	int tttrang = 1;
	int esc = 1;

	do
	{
		clrscr();
		gotoxy(26, 1);
		cout << "~~~DANH SACH VAT TU SAU KHI TIM KIEM~~~ ";

		gotoxy(3, yHotkey);
		SetColor(BLACK);
		cout << "ESC-Thoat, F10 - Tim Kiem";

		normalBGColor();

		// cho nay thay doi cau truc DSLK TEMPLIST bang Mang cap phat dong hay hon...

		DisplayVT(keyDisplayVT, 5, xDisplayDS);
		esc = Output_SearchVT_List(t, tttrang);


	} while (esc);

}
void Create_Temp_Search_List(TREE_VT t, LIST_TEMP_LIST& l, int& index, string Key)
{
	if (t == NULL)
		return;
	Create_Temp_Search_List(t->left, l, index, Key);
	if (t->VT.ten.find(Key) != string::npos) // tim thay
		addTailList_Temp_List(l, index++, t->VT.MAVT, t->VT.ten);
	Create_Temp_Search_List(t->right, l, index, Key);
}
int countVT_TempList(LIST_TEMP_LIST l)
{
	int tong = 0;
	for (NODE_TEMP_LIST* n = l.pHead; n != NULL; n = n->next)
		tong += 1;
	return tong;
}
void NhapTenVT_TimKiem(string& result, int& ordinal, bool& isSave, bool& isEscape)
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
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
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
					ordinal = 0;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 0;
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
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "TOI DA 20 KY TU, CHI LAY KY TU CHU VA SO!!!";
				normalBGColor();
				gotoxy(x, y);
			}
		}

	}

}
int Output_SearchVT_List(TREE_VT t, int& tttrang)
{
	LIST_TEMP_LIST l;
	initList_Temp_List(l);


	int currposMainMenu = -1;
	bool kt = false; // thoat khoi tim kiem
	ShowCur(false);
	Bang_Nhap_Ten_VT(t, l, kt);
	// nNV la so NV hien co trong cay
	int nVT = countVT_TempList(l);


	// thu tu trang
	int tongtrang;
	tongtrang = (nVT / NUMBER_LINES) + 1;
	OutputVT_PerPage(t, l, tttrang);
	ShowCur(false);
	if (!kt)
	{
		_getch(); // dung man hinh
	}


	ClearAll_Temp_List(l);
	if (kt)
	{
		return 0;
	}
	else
		return 1;



}
void Bang_Nhap_Ten_VT(TREE_VT t, LIST_TEMP_LIST& l, bool& kt)
{
	ShowCur(true);
	normalBGColor();

	int ordinal = 0;
	bool isSave = false; // tien hanh tim kiem
	bool isEscape = false;

	// chieu dai bang nhap 
	int nngang = (int)keyBangNhapTimKiemVT[0].length();

	// bien key de tim kiem nhung vat tu co ten = key
	string key = "";
	CreateBox(X_NOTIFY + 3, Y_NOTIFY, "NOTIFICATIONS:  ", 62);
	BangNhap(xDisplayDS[5] + 7, yDisplay, nngang, keyBangNhapTimKiemVT, 4);
	BangGuides(xDisplayDS[5] + 7, yDisplay + 20, nngang, keyGuideTimKiemVT, 3);


	while (true)
	{
		switch (ordinal)
		{
		case 0:
			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);
			NhapTenVT_TimKiem(key, ordinal, isSave, isEscape);
			break;
		}

		if (isSave)
		{
			isSave = false;

			// check rong
			if (key.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}

			// chen thuat toan tim kiem cay lay nhung vat tu ma co ky tu la Key
			int index = 0; // 
			Create_Temp_Search_List(t, l, index, key);
			for (int i = 0; i < 5; i++)
			{
				SetColor(BLUE);
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				Sleep(100);
				cout << "           SUCCESSFULLY !!! ";
			}
			return;

		}


		if (isEscape)
		{
			kt = true;
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
			return;
		}
	}

}
string Tao_Ma_HD(DS_NV ds_nv)
{
	bool kt_hd = false;

	// duyệt qua từng nhân viên, coi đã có nhân viên nào lập hoá đơn chưa
	for (int i = 0; i < ds_nv.n; i++)
	{
		if (ds_nv.ds[i]->ds_hd.pHead != NULL) // neu co hoa don trong do
		{
			kt_hd = true;
			break;
		}
	}


	// nếu có, tạo danh sách liên kết đơn tạm để nối tất cả hoá đơn đó lại, duyệt tìm mã hoá đơn max
	if (kt_hd)
	{
		DS_HD ds_hd_temp;
		// lay toan bo hoa don dang co cua moi nhan vien
		for (int i = 0; i < ds_nv.n; i++)
		{
			if (ds_nv.ds[i]->ds_hd.pHead != NULL)
			{
				NODE_HD* p = ds_nv.ds[i]->ds_hd.pHead;
				for (p; p != NULL; p = p->next)
				{
					Them_HD_Vao_DS(p->HD, ds_hd_temp);
				}
			}
		}


		// tim max
		string max_temp = ds_hd_temp.pHead->HD.MAHD.substr(2); // lay tu sau HD tro ve
		// duyet tung thang de so sanh voi max
		for (NODE_HD* n = ds_hd_temp.pHead; n != NULL; n = n->next)
		{
			string cur = n->HD.MAHD.substr(2);

			if (atoi(max_temp.c_str()) < atoi(cur.c_str()))
			{
				max_temp = cur;
			}
		}
		max_temp = int_to_string(atoi(max_temp.c_str()) + 1);
		// ket qua
		string result = "HD" + max_temp;
		return result;

	}
	else // nếu không, cho mã hoá đơn của nó là HD0
	{
		string result = "HD0";
		return result;
	}

}
//============================IN HOA DON KHOANG NGAY================
void OutputHD_PerPage(DS_NV ds_nv, DS_HD ds_hd_temp, int index)
{
	ShowCur(false);
	Xoa_OutDSHD_29lines();
	SetColor(BLACK);
	locate = 0;
	index--;

	NODE_HD* p = ds_hd_temp.pHead;
	for (int i = 1; i <= NUMBER_LINES * index; i++) p = p->next;
	for (int i = NUMBER_LINES * index; p != NULL && i < NUMBER_LINES * (index + 1); i++)
	{
		Xoa_OutDSHD_1line(locate);
		gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + locate);
		cout << p->HD.MAHD;
		gotoxy(xDisplayDS[1] + 1, yDisplay + 3 + locate);
		cout << p->HD.ngay_lap_hd.Ngay << "/" << p->HD.ngay_lap_hd.Thang << "/" << p->HD.ngay_lap_hd.Nam;
		gotoxy(xDisplayDS[2] + 4, yDisplay + 3 + locate);
		(p->HD.loai == 'X' || p->HD.loai == 'x') ? cout << "XUAT" : cout << "NHAP";
		gotoxy(xDisplayDS[3] + 3, yDisplay + 3 + locate);
		NHAN_VIEN* q = Find_NV(ds_nv, p);
		cout << q->ho << " " << q->ten;
		gotoxy(xDisplayDS[3] + 25, yDisplay + 3 + locate);
		cout << p->HD.tong_tien;
		locate++;
		p = p->next;
	}

}
NHAN_VIEN* Find_NV(DS_NV ds_nv, NODE_HD* node_hd)
{
	string b = node_hd->HD.MAHD.substr(2);
	for (int i = 0; i < ds_nv.n; i++)
	{
		if (ds_nv.ds[i]->ds_hd.pHead != NULL)
		{
			NODE_HD* p = ds_nv.ds[i]->ds_hd.pHead;
			for (p; p != NULL; p = p->next)
			{
				string a = p->HD.MAHD.substr(2);

				if (atoi(a.c_str()) == atoi(b.c_str()))
				{
					return ds_nv.ds[i];
				}
			}
		}

	}
}
void OutputCTHD_PerPage(TREE_VT t, DS_CT_HD ds_ct_hd, int index)
{
	ShowCur(false);
	Xoa_OutCTHD_18lines();
	SetColor(BLACK);
	locate = 0;
	index--;
	if (ds_ct_hd.n == -1)
		return;
	for (int i = NUMBER_LINES_CTHD * index; i < NUMBER_LINES_CTHD * (1 + index) && i < ds_ct_hd.n; i++)
	{
		Output_CTHD(t, ds_ct_hd.ds[i]);
	}
}


//============================nhapngaythangnam=================
int KiemTraNam(int yy, int mm) {
	bool check;
	if (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)) {
		check = 0;
	}
	else check = 1;
	return check;
}
void SoNgayTrongThang(int yy, int mm, int a[13]) {
	int i;
	for (i = 1; i <= 12; i++) {
		if (i <= 7)
			if (i % 2 != 0) a[i] = 31;
			else a[i] = 30;
		if (i >= 8)
			if (i % 2 == 0) a[i] = 31;
			else a[i] = 30;
		if (i == 2)
			if (KiemTraNam(yy, mm) == 0) a[i] = 29;
			else a[i] = 28;
	}
}
int KiemTraNgay(int dd, int mm, int yy) {
	bool check;
	int a[13];
	SoNgayTrongThang(yy, mm, a);
	if (dd <= a[mm] && dd > 0)
		check = 1;
	else check = 0;
	return check;
}
int kiem_tra_truoc_hien_tai(int dd, int mm, int yy)
{

	time_t now = time(0);

	tm* ltm = localtime(&now);
	int ddht = ltm->tm_mday;
	int mmht = 1 + ltm->tm_mon;
	int yyht = 1900 + ltm->tm_year;

	if (yy < yyht) return 1;
	else if (yy == yyht)
	{
		if (mm < mmht) return 1;
		else if (mm == mmht) if (dd <= ddht) return 1; else return -1;
	}
	return -1;

}
int kiem_tra_khoang_ngay(ngay_lap_hd ngay_truoc, ngay_lap_hd ngay_sau)
{
	if (ngay_truoc.Nam < ngay_sau.Nam) return 1;
	else if (ngay_truoc.Nam == ngay_sau.Nam)
	{
		if (ngay_truoc.Thang < ngay_sau.Thang) return 1;
		else if (ngay_truoc.Thang == ngay_sau.Thang) if (ngay_truoc.Ngay <= ngay_sau.Ngay) return 1; else return -1;
	}
	return -1;
}
int kiem_tra_ngay_hd(ngay_lap_hd ngay_ht, ngay_lap_hd ngay_truoc, ngay_lap_hd ngay_sau)
{
	if (kiem_tra_khoang_ngay(ngay_truoc, ngay_ht) == 1 && kiem_tra_khoang_ngay(ngay_ht, ngay_sau) == 1)
		return 1;
	else
		return -1;
}
//=============================NGAY========================
void NhapNgay2(string& result, int choice, int& ordinal, bool& isSave, bool& isEscape)
{
	// bien dem so chu da duoc nhap vao cho result
	int x, y;
	x = wherex();
	y = wherey();
	XoaMotDong(5);
	gotoxy(x, y);
	cout << result;
	int count = (int)result.length();

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

			if (((kb_hit >= 48 && kb_hit <= 57))
				&& count < ((choice == 2 || choice == 5) ? MAX_NAM : MAX_NGAY) && count >= 0)
			{
				// xoa dong thong bao
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				cout << setw(60) << setfill(' ') << " ";
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
				// xay ra 3 truong hop 
				if (choice == 0) // nhap ngay
				{
					if (kb_hit == KEY_LEFT)
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
				else if (choice == 1) // nhap thang
				{
					if (kb_hit == KEY_LEFT)
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
				else if (choice == 2) // nhap nam
				{
					if (kb_hit == KEY_LEFT)
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
				else if (choice == 3) // nhap ngay
				{
					if (kb_hit == KEY_LEFT)
					{
						ordinal = 5;
						return;
					}
					else
					{
						ordinal = 4;
						return;
					}
				}
				else if (choice == 4) // nhap thang
				{
					if (kb_hit == KEY_LEFT)
					{
						ordinal = 3;
						return;
					}
					else
					{
						ordinal = 5;
						return;
					}
				}
				else if (choice == 5) // nhap nam
				{
					if (kb_hit == KEY_LEFT)
					{
						ordinal = 4;
						return;
					}
					else
					{
						ordinal = 3;
						return;
					}
				}

			}
			else if (kb_hit == ENTER)
			{
				if (choice == 0)
				{
					ordinal = 3;
					return;
				}
				else if (choice == 1)
				{
					ordinal = 4;
					return;
				}
				else if (choice == 2)
				{
					ordinal = 5;
					return;
				}
				else if (choice == 3)
				{
					ordinal = 0;
					return;
				}
				else if (choice == 4)
				{
					ordinal = 1;
					return;
				}
				else if (choice == 5)
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
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				if (choice == 0 || choice == 1)
				{
					cout << " TOI DA " << MAX_NGAY << " CHU SO !!!";
				}
				else
				{
					cout << " TOI DA " << MAX_NAM << " CHU SO !!!";
				}

				normalBGColor();
				gotoxy(x, y);

			}
		}

	}
}
///////////////////////////////////////////   IN HD   ////////////////////////////////////////////////


void Nhap_Khoang_Ngay(NGAY_LAP_HD& NgayTruoc, NGAY_LAP_HD& NgaySau, bool& isEscape)
{
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();

	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 0;
	bool isSave = false;

	// chieu dai bang nhap
	int nngang = (int)keyBangNhapHD[0].length();

	// cac bien luu tru tam thoi
	time_t now = time(0);

	tm* ltm = localtime(&now);

	string ngaytruoc = "", thangtruoc = "", namtruoc = "";
	string ngaysau = "", thangsau = "", namsau = "";
	uint loai = 3;
	string MAHD;

	CreateBox(X_NOTIFY + 3, Y_NOTIFY, "NOTIFICATIONS:  ", 48);
	BangNhap(xDisplayDS[5] + 5, yDisplay, nngang, keyBangNhapHD1, 7);

	// so lan quay lai nhap ngay, thang, nam
	bool kt_ngay = 1;
	bool kt_thang = 1;
	bool kt_nam = 1;
	bool kt_ngay2 = 1;
	bool kt_thang2 = 1;
	bool kt_nam2 = 1;

	while (true) {

		switch (ordinal)
		{

		case 0:
			if (kt_ngay == 1)
			{
				ngaytruoc = int_to_string(ltm->tm_mday);
				kt_ngay = 0;
			}
			gotoxy((xDisplayDS[5] + 7 + nngang / 3), yDisplay + 4);
			NhapNgay2(ngaytruoc, NHAP_NGAY, ordinal, isSave, isEscape);
			break;
		case 1:
			if (kt_thang == 1)
			{
				thangtruoc = int_to_string(1 + ltm->tm_mon);
				kt_thang = 0;
			}

			gotoxy((xDisplayDS[5] + 7 + nngang / 2 + 2), yDisplay + 4);
			NhapNgay2(thangtruoc, NHAP_THANG, ordinal, isSave, isEscape);
			break;
		case 2:
			if (kt_nam == 1)
			{
				namtruoc = int_to_string(1900 + ltm->tm_year);
				kt_nam = 0;
			}
			gotoxy((xDisplayDS[5] + 7 + nngang / 2 + 10), yDisplay + 4);
			NhapNgay2(namtruoc, NHAP_NAM, ordinal, isSave, isEscape);
			break;
		case 3:
			if (kt_ngay2 == 1)
			{
				ngaysau = int_to_string(ltm->tm_mday);
				kt_ngay2 = 0;
			}
			gotoxy((xDisplayDS[5] + 7 + nngang / 3), yDisplay + 6);
			NhapNgay2(ngaysau, 3, ordinal, isSave, isEscape);
			break;
		case 4:
			if (kt_thang2 == 1)
			{
				thangsau = int_to_string(1 + ltm->tm_mon);
				kt_thang2 = 0;
			}

			gotoxy((xDisplayDS[5] + 7 + nngang / 2 + 2), yDisplay + 6);
			NhapNgay2(thangsau, 4, ordinal, isSave, isEscape);
			break;
		case 5:
			if (kt_nam2 == 1)
			{
				namsau = int_to_string(1900 + ltm->tm_year);
				kt_nam2 = 0;
			}
			gotoxy((xDisplayDS[5] + 7 + nngang / 2 + 10), yDisplay + 6);
			NhapNgay2(namsau, 5, ordinal, isSave, isEscape);
			break;

		}

		// check Save
		if (isSave)
		{
			// cap nhat lai flag
			isSave = false;

			// check rong;
			if (ngaytruoc.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}
			else if (thangtruoc.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}
			else if (namtruoc.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}

			if (atoi(namtruoc.c_str()) > 2000)
			{
				if (atoi(thangtruoc.c_str()) > 0 && atoi(thangtruoc.c_str()) <= 12)
				{
					if (KiemTraNgay(atoi(ngaytruoc.c_str()), atoi(thangtruoc.c_str()), atoi(namtruoc.c_str())) == 1)
					{

						if (kiem_tra_truoc_hien_tai(atoi(ngaytruoc.c_str()), atoi(thangtruoc.c_str()), atoi(namtruoc.c_str())) != 1)

						{
							gotoxy(X_NOTIFY + 17, Y_NOTIFY);
							SetColor(BLUE);
							cout << "NHAP THOI GIAN TRUOC HOAC BANG HT";
							normalBGColor();

							// quay lai va dien vao truong du lieu do
							ordinal = 0;
							continue;
						}

					}
					else
					{
						gotoxy(X_NOTIFY + 17, Y_NOTIFY);
						SetColor(BLUE);
						cout << "DINH DANG NGAY SAI !!!                     ";
						normalBGColor();

						// quay lai va dien vao truong du lieu do
						ordinal = 0;
						continue;
					}
				}
				else
				{
					gotoxy(X_NOTIFY + 17, Y_NOTIFY);
					SetColor(BLUE);
					cout << "NHAP THANG KHONG PHU HOP !!!               ";
					normalBGColor();

					// quay lai va dien vao truong du lieu do
					ordinal = 1;
					continue;
				}
			}
			else
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "NHAP NAM KHONG PHU HOP !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}

			if (atoi(namsau.c_str()) > 2000)
			{
				if (atoi(thangsau.c_str()) > 0 && atoi(thangsau.c_str()) <= 12)
				{
					if (KiemTraNgay(atoi(ngaysau.c_str()), atoi(thangsau.c_str()), atoi(namsau.c_str())) == 1)
					{

						if (kiem_tra_truoc_hien_tai(atoi(ngaysau.c_str()), atoi(thangsau.c_str()), atoi(namsau.c_str())) != 1)

						{
							gotoxy(X_NOTIFY + 17, Y_NOTIFY);
							SetColor(BLUE);
							cout << "NHAP THOI GIAN TRUOC HOAC BANG HIEN TAI !!!";
							normalBGColor();

							// quay lai va dien vao truong du lieu do
							ordinal = 3;
							continue;
						}

					}
					else
					{
						gotoxy(X_NOTIFY + 17, Y_NOTIFY);
						SetColor(BLUE);
						cout << "DINH DANG NGAY SAI !!!                     ";
						normalBGColor();

						// quay lai va dien vao truong du lieu do
						ordinal = 3;
						continue;
					}
				}
				else
				{
					gotoxy(X_NOTIFY + 17, Y_NOTIFY);
					SetColor(BLUE);
					cout << "NHAP THANG KHONG PHU HOP !!!               ";
					normalBGColor();

					// quay lai va dien vao truong du lieu do
					ordinal = 4;
					continue;
				}
			}
			else
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "NHAP NAM KHONG PHU HOP !!!";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 5;
				continue;
			}



			NgayTruoc.Ngay = atoi(ngaytruoc.c_str());
			NgayTruoc.Thang = atoi(thangtruoc.c_str());
			NgayTruoc.Nam = atoi(namtruoc.c_str());
			NgaySau.Ngay = atoi(ngaysau.c_str());
			NgaySau.Thang = atoi(thangsau.c_str());
			NgaySau.Nam = atoi(namsau.c_str());
			if (kiem_tra_khoang_ngay(NgayTruoc, NgaySau) == -1)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "HAI MOC THOI GIAN KHONG PHU HOP !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}
			// In dong thong bao .
			for (int i = 0; i < 5; i++)
			{
				SetColor(BLUE);
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				Sleep(100);
				cout << "           SUCCESSFULLY !!! ";
			}
			normalBGColor();
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
			system("cls");
			return;
		}

		if (isEscape)
		{
			clrscr();
			return;
		}
	}
	ShowCur(false);
}
void Menu_IN_DS_HD(DS_NV ds_nv)
{
	NGAY_LAP_HD NgayTruoc, NgaySau;
	clrscr();
	gotoxy(3, yHotkey);
	SetColor(BLACK);
	cout << "ESC-Thoat, F10 - Tim Kiem";
	normalBGColor();
	HOA_DON hd;
	int index = 0;
	bool isEscape = false;
	Nhap_Khoang_Ngay(NgayTruoc, NgaySau, isEscape);
	if (isEscape)
		return;

	DS_HD ds_hd_temp;
	if (ds_nv.n == 0)
	{
		return;
	}
	for (int i = 0; i < ds_nv.n; i++)
	{
		NODE_HD* p = ds_nv.ds[i]->ds_hd.pHead;
		for (p; p != NULL; p = p->next)
		{
			if (kiem_tra_ngay_hd(p->HD.ngay_lap_hd, NgayTruoc, NgaySau) == 1)
			{
				HOA_DON q;
				q.MAHD = p->HD.MAHD;
				q.ngay_lap_hd = p->HD.ngay_lap_hd;
				q.loai = p->HD.loai;
				q.tong_tien = p->HD.tong_tien;
				Them_HD_Vao_DS(q, ds_hd_temp);
			}
		}
	}
	NODE_HD* p = ds_hd_temp.pHead;
	for (p; p != NULL; p = p->next)
	{
		for (NODE_HD* q = p->next; q != NULL; q = q->next)
		{
			if (kiem_tra_khoang_ngay(p->HD.ngay_lap_hd, q->HD.ngay_lap_hd) == -1)
			{
				HOA_DON temp = p->HD;
				p->HD = q->HD;
				q->HD = temp;

			}
		}
	}

	int nDS = countds_hd(ds_hd_temp);
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;

	clrscr();
	normalBGColor();
	gotoxy(26, 1);
	cout << "BANG LIET KE DANH SACH HOA DON " << "TU NGAY : " << NgayTruoc.Ngay << "/" << NgayTruoc.Thang << "/" << NgayTruoc.Nam << " DEN NGAY: " << NgaySau.Ngay << "/" << NgaySau.Thang << "/" << NgaySau.Nam;
	gotoxy(3, yHotkey);
	SetColor(BLACK);
	cout << "ESC-Thoat";
	DisplayVT(keyDisplayHD, 5, xDisplay_IN_DS_HD);
	OutputHD_PerPage(ds_nv, ds_hd_temp, tttrang);
	do
	{
		if (_kbhit())
		{
			int kbhit = _getch();
			switch (kbhit)
			{
			case PAGE_UP:
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				OutputHD_PerPage(ds_nv, ds_hd_temp, tttrang);
				break;

			case PAGE_DOWN:
				(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
				OutputHD_PerPage(ds_nv, ds_hd_temp, tttrang);
				break;
			case ESC:
				GiaiPhongDSHD(ds_hd_temp);
				return;

			}
		}
		ShowCur(false);
		gotoxy(3, 36);
		cout << "Trang " << tttrang << " /" << tongtrang << "  " << "PagUP-Trang Truoc, PagDn-Trang Sau";
	} while (1);

	system("pause");
}
void Ds_HD_Temp(DS_HD& ds_hd_temp, DS_NV ds_nv)
{
	for (int i = 0; i < ds_nv.n; i++)
	{
		NODE_HD* p = ds_nv.ds[i]->ds_hd.pHead;
		for (p; p != NULL; p = p->next)
		{
			Them_HD_Vao_DS(p->HD, ds_hd_temp);
		}
	}
}
void Ds_VT_Gia(TREE_VT t, DS_VAT_TU_GIA& ds_vt_gia)
{
	if (t == NULL) return;
	else
	{
		Ds_VT_Gia(t->left, ds_vt_gia);
		VAT_TU_GIA* p = new VAT_TU_GIA;
		p->MAVT = t->VT.MAVT;
		ds_vt_gia.ds[ds_vt_gia.n++] = p;
		Ds_VT_Gia(t->right, ds_vt_gia);
	}
}
void GiaiPhongVTGia(DS_VAT_TU_GIA& ds_vt_gia)
{
	for (int i = 0; i < ds_vt_gia.n; i++)
	{
		delete ds_vt_gia.ds[i];
	}
}
void Menu_IN_10_VT(TREE_VT t, DS_NV ds_nv)
{
	NODE_HD* p;
	DS_HD ds_hd_temp;
	ngay_lap_hd NgayTruoc, NgaySau;
	DS_VAT_TU_GIA ds_vt_gia_loi, ds_vt_gia_nhap, ds_vt_gia_xuat;
	gotoxy(3, yHotkey);
	SetColor(BLACK);
	cout << "ESC-Thoat, F10 - Tim Kiem";

	Ds_HD_Temp(ds_hd_temp, ds_nv);
	Ds_VT_Gia(t, ds_vt_gia_loi);
	Ds_VT_Gia(t, ds_vt_gia_nhap);
	Ds_VT_Gia(t, ds_vt_gia_xuat);




	bool isEscape = false;
	Nhap_Khoang_Ngay(NgayTruoc, NgaySau, isEscape);

	if (isEscape)
		return;

	for (NODE_HD* p = ds_hd_temp.pHead; p != NULL; p = p->next)
	{
		if (kiem_tra_ngay_hd(p->HD.ngay_lap_hd, NgayTruoc, NgaySau) == 1)
		{
			if (p->HD.loai == 'N' || p->HD.loai == 'n')
			{
				for (int j = 0; j < ds_vt_gia_nhap.n; j++)

				{
					string b = ds_vt_gia_nhap.ds[j]->MAVT.substr(2);
					for (int i = 0; i < p->HD.ds_ct_hd.n; i++)
					{
						string a = p->HD.ds_ct_hd.ds[i].MAVT.substr(2);

						if (atoi(a.c_str()) == atoi(b.c_str()))
						{

							ds_vt_gia_nhap.ds[j]->gia += (p->HD.ds_ct_hd.ds[i].so_luong * p->HD.ds_ct_hd.ds[i].don_gia * (1 + (double)p->HD.ds_ct_hd.ds[i].thue / 100));


						}


					}
				}
			}
			else
			{
				for (int j = 0; j < ds_vt_gia_xuat.n; j++)

				{
					string b = ds_vt_gia_xuat.ds[j]->MAVT.substr(2);

					for (int i = 0; i < p->HD.ds_ct_hd.n; i++)
					{
						string a = p->HD.ds_ct_hd.ds[i].MAVT.substr(2);

						if (atoi(a.c_str()) == atoi(b.c_str()))
						{

							ds_vt_gia_xuat.ds[j]->gia += (p->HD.ds_ct_hd.ds[i].so_luong * p->HD.ds_ct_hd.ds[i].don_gia * (1 + (double)p->HD.ds_ct_hd.ds[i].thue / 100));

						}
					}
				}
			}

		}
	}




	for (int i = 0; i < ds_vt_gia_loi.n; i++)
	{
		if (ds_vt_gia_nhap.ds[i]->gia < ds_vt_gia_xuat.ds[i]->gia)
			ds_vt_gia_loi.ds[i]->gia = ds_vt_gia_xuat.ds[i]->gia - ds_vt_gia_nhap.ds[i]->gia;
	}


	for (int i = 0; i < ds_vt_gia_loi.n; i++)
	{
		for (int j = i; j < ds_vt_gia_loi.n; j++)
		{
			if (ds_vt_gia_loi.ds[i]->gia < ds_vt_gia_loi.ds[j]->gia)
			{
				VAT_TU_GIA* temp;
				temp = ds_vt_gia_loi.ds[i];
				ds_vt_gia_loi.ds[i] = ds_vt_gia_loi.ds[j];
				ds_vt_gia_loi.ds[j] = temp;
			}
		}
	}
	ShowCur(false);

	locate = 0;
	gotoxy(2, 1);
	cout << "TOP 10 VAT TU CO DOANH THU CAO NHAT TRONG KHOANG THOI GIAN " << "TU NGAY : " << NgayTruoc.Ngay << "/" << NgayTruoc.Thang << "/" << NgayTruoc.Nam << " DEN NGAY: " << NgaySau.Ngay << "/" << NgaySau.Thang << "/" << NgaySau.Nam;
	gotoxy(3, yHotkey);
	SetColor(BLACK);
	cout << "ESC-Thoat";
	DisplayVT(keyDisplayTop10, 3, xDisplayTop10);
	for (int i = 0; i < ds_vt_gia_loi.n && i < 10; i++)
	{

		gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + locate);
		cout << ds_vt_gia_loi.ds[i]->MAVT;

		gotoxy(xDisplayDS[1] + 1, yDisplay + 3 + locate);
		cout << find_VT(t, ds_vt_gia_loi.ds[i]->MAVT)->VT.ten;

		gotoxy(xDisplayDS[2] + 2, yDisplay + 3 + locate);
		cout << ds_vt_gia_loi.ds[i]->gia;

		locate++;
	}
	GiaiPhongVTGia(ds_vt_gia_loi);
	GiaiPhongVTGia(ds_vt_gia_nhap);
	GiaiPhongVTGia(ds_vt_gia_xuat);
	gotoxy(100, 35);
	cout << endl;
	system("pause");

}

void NhapTenHD_TimKiem(string& result, int& ordinal, bool& isSave, bool& isEscape)
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
			// chi nhan chu thuong hoac  chu in hoa, chu so  va dau cach
			// chi nhap ten vat tu toi da 19 ky tu.
			if ((kb_hit >= 48 && kb_hit <= 57) && count < MAX_TEN_VT && count >= 0)
			{
				// xoa dong thong bao
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				if (kb_hit != SPACE)
				{
					count++;
					cout << (char)kb_hit;
					result += (char)kb_hit;
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
					ordinal = 0;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 0;
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
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "TOI DA 20 KY TU, CHI LAY KY TU SO!!!";
				normalBGColor();
				gotoxy(x, y);
			}
		}

	}

}
void Bang_Nhap_Ten_HD(TREE_VT t, DS_NV ds_nv, bool& kt)
{
	ShowCur(true);
	normalBGColor();

	int ordinal = 0;
	bool isSave = false; // tien hanh tim kiem
	bool isEscape = false;
	bool found = false;

	// chieu dai bang nhap 
	int nngang = (int)keyBangNhapTimKiemHD[0].length();

	// bien key de tim kiem nhung vat tu co ten = key
	string key = "HD";
	string ma_so_hd = "";
	CreateBox(xDisplayDS[5] + 9, Y_NOTIFY, "NOTIFICATIONS:  ", 62);
	BangNhap(xDisplayDS[5] + 7, yDisplay, nngang, keyBangNhapTimKiemHD, 4);

	while (true)
	{
		switch (ordinal)
		{
		case 0:
			gotoxy((xDisplayDS[5] + 7 + nngang / 2), yDisplay + 3);
			cout << key;
			gotoxy((xDisplayDS[5] + 9 + nngang / 2), yDisplay + 3);
			NhapTenHD_TimKiem(ma_so_hd, ordinal, isSave, isEscape);
			break;
		}

		if (isSave)
		{
			isSave = false;

			// check rong
			if (ma_so_hd.length() == 0)
			{
				gotoxy(X_NOTIFY + 17, Y_NOTIFY);
				SetColor(BLUE);
				cout << "HAY NHAP VAO SO HOA DON !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}

			// chen thuat toan tim kiem cay lay nhung vat tu ma co ky tu la Key 
			for (int i = 0; i < (ds_nv.n); i++)
			{
				if (ds_nv.ds[i]->ds_hd.pHead != NULL)
				{
					NODE_HD* p = ds_nv.ds[i]->ds_hd.pHead;
					for (p; p != NULL; p = p->next)
					{
						string a = p->HD.MAHD.substr(2);

						if (a.compare(ma_so_hd) == 0)
						{
							int tttrang = 1;
							int tongtrang = (p->HD.ds_ct_hd.n / NUMBER_LINES_CTHD) + 1;
							normalBGColor();
							XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 60);
							system("cls");
							gotoxy(23, 1);
							cout << "~~~HOA DON SAU KHI TIM KIEM~~~ ";
							SetColor(BLACK);
							gotoxy(20, 38);
							cout << "PAGE UP-TRANG TRUOC, PAGE DOWN-TRANG SAU";

							string fullName = ds_nv.ds[i]->ho + " " + ds_nv.ds[i]->ten;
							DisplayHD(keyDisplayCTHD, 5, xDisplayDS, int_to_string(ds_nv.ds[i]->MANV), fullName, p->HD.MAHD, int_to_string(p->HD.ngay_lap_hd.Ngay), int_to_string(p->HD.ngay_lap_hd.Thang), int_to_string(p->HD.ngay_lap_hd.Nam), p->HD.loai);
							// lam menu them chi tiet hoa don trong day
							DisplayCTHD(keyDisplayCTHD, 5, xDisplayDS, yDisplay_CTHD);
							// menu chi tiet hoa do
							OutputCTHD_PerPage(t, p->HD.ds_ct_hd, tttrang);
							gotoxy(xDisplayDS[0] + 8, yDisplay_CTHD[3] - 1);
							SetColor(REG_DWORD);
							cout << std::fixed << p->HD.tong_tien;

							CreateBox(xDisplayDS[5] + 9, Y_NOTIFY, "NOTIFICATIONS:  ", 62);
							for (int i = 0; i < 5; i++)
							{
								SetColor(BLUE);
								gotoxy(X_NOTIFY + 17, Y_NOTIFY);
								Sleep(100);
								cout << "AN ESC DE QUAY LAI !!!";
							}
							normalBGColor();
							int kb_hit;
							bool exit = false;
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
										OutputCTHD_PerPage(t, p->HD.ds_ct_hd, tttrang);
										break;

									case PAGE_DOWN:
										(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
										OutputCTHD_PerPage(t, p->HD.ds_ct_hd, tttrang);
										break;

									case ESC:
										exit = true;
									}
								}
								ShowCur(false);
								SetColor(BLACK);
								gotoxy(3, 38);
								cout << "Trang " << tttrang << "/" << tongtrang;
							} while (!exit);
							XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 80);
							return;
						}
					}
				}
			}

			if (!found)
			{
				for (int i = 0; i < 5; i++)
				{
					SetColor(BLUE);
					gotoxy(X_NOTIFY + 17, Y_NOTIFY);
					Sleep(100);
					cout << "MA HOA DON KHONG TON TAI.                ";
					Sleep(500);
				}
				normalBGColor();
				XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 80);
				return;
			}
		}


		if (isEscape)
		{
			kt = true;
			XoaMotVung(xDisplayDS[5] + 7, yDisplay, 30, 80);
			return;
		}
	}

}
int Output_SearchHD_List(TREE_VT t, DS_NV ds_nv)
{
	int currposMainMenu = -1;
	bool kt = false; // thoat khoi tim kiem
	ShowCur(false);
	Bang_Nhap_Ten_HD(t, ds_nv, kt);

	// thu tu trang
	ShowCur(false);
	if (kt)
	{
		normalBGColor();
		clrscr();
		return 0;
	}
	else
		return 1;

}
void Menu_Tim_Kiem_HD(TREE_VT t, DS_NV ds_nv)
{
	clrscr();
	normalBGColor();
	int tttrang = 1;
	int esc = 1;

	do
	{
		clrscr();
		gotoxy(23, 1);
		cout << "~~~HOA DON SAU KHI TIM KIEM~~~ ";
		DisplayHD(keyDisplayCTHD, 5, xDisplayDS, "", "", "", "", "", "", 3);
		gotoxy(3, yHotkey);
		SetColor(BLACK);
		cout << "ESC-Thoat, F10 - Tim Kiem";

		normalBGColor();

		// cho nay thay doi cau truc DSLK TEMPLIST bang Mang cap phat dong hay hon...


		esc = Output_SearchHD_List(t, ds_nv);

	} while (esc);

}








