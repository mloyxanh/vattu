#pragma once

#include"Hoa_DON.h"
// ////////////////////////////////////////  GHI FILE ///////////////////////////////////////////////////////
void Duyet_Cay_Ghi(TREE_VT t, fstream& file_vt)
{
	if (t == NULL) return;
	else
	{
		Duyet_Cay_Ghi(t->left, file_vt);
		file_vt << t->VT.MAVT << '\n';
		file_vt << t->VT.ten << '\n';
		file_vt << t->VT.don_vi_tinh << '\n';
		file_vt << t->VT.so_luong_ton << '\n';
		file_vt << t->VT.trong_hoa_don << '\n';
		Duyet_Cay_Ghi(t->right, file_vt);
	}
}
void Ghi_File_VT(TREE_VT t)
{
	fstream file_vt;
	file_vt.open(".\\file\\danhsachvattu.txt", ios::out);
	if (!file_vt) cout << "KHONG MO DUOC FILE GHI !!!";
	else
	{
		file_vt << countVT(t) << endl;
		Duyet_Cay_Ghi(t, file_vt);
	}
	file_vt.close();
}
void Doc_File_VT(TREE_VT& t)
{
	fstream file_vt;
	VAT_TU p;
	int countvt;
	string temp;
	file_vt.open(".\\file\\danhsachvattu.txt", ios::in);
	if (!file_vt) return;
	if (file_vt.is_open())
	{
		file_vt >> countvt;
		getline(file_vt, temp);
		for (int i = 0; i < countvt; i++)
		{
			getline(file_vt, p.MAVT);
			getline(file_vt, p.ten);
			getline(file_vt, p.don_vi_tinh);
			file_vt >> p.so_luong_ton;
			getline(file_vt, temp);
			file_vt >> p.trong_hoa_don;
			getline(file_vt, temp);
			insertVTToTree(t, p);
		}
	}
}

void Ghi_File_NV(DS_NV ds)
{
	fstream file_nv;
	file_nv.open(".\\file\\danhsachnhanvien.txt", ios::out);
	file_nv << ds.n << '\n';
	for (int i = 0; i < ds.n; i++)
	{
		file_nv << ds.ds[i]->MANV << '\n';
		file_nv << ds.ds[i]->ho << '\n';
		file_nv << ds.ds[i]->ten << '\n';
		file_nv << ds.ds[i]->gioitinh;
		if (countds_hd(ds.ds[i]->ds_hd) != 0) file_nv << '\n';
		else file_nv << '\n' << -1 << '\n';
		if (ds.ds[i]->ds_hd.pHead != NULL)
		{
			NODE_HD* p = ds.ds[i]->ds_hd.pHead;
			file_nv << countds_hd(ds.ds[i]->ds_hd) << '\n';
			for (p; p != NULL; p = p->next)
			{
				file_nv << p->HD.MAHD << '\n';
				file_nv << p->HD.ngay_lap_hd.Ngay << '\n';
				file_nv << p->HD.ngay_lap_hd.Thang << '\n';
				file_nv << p->HD.ngay_lap_hd.Nam << '\n';
				file_nv << p->HD.loai << '\n';
				file_nv << p->HD.tong_tien << '\n';
				file_nv << p->HD.ds_ct_hd.n << '\n';
				for (int j = 0; j < p->HD.ds_ct_hd.n; j++)
				{
					file_nv << p->HD.ds_ct_hd.ds[j].MAVT << '\n';
					file_nv << p->HD.ds_ct_hd.ds[j].so_luong << '\n';
					file_nv << p->HD.ds_ct_hd.ds[j].don_gia << '\n';
					file_nv << p->HD.ds_ct_hd.ds[j].thue << '\n';
				}
			}
		}
	}
}
void Doc_File_NV(DS_NV& ds)
{
	fstream file_nv;
	string temp;
	int countds_nv = 0, countds_hd = 0, countds_ct_hd = 0;
	file_nv.open(".\\file\\danhsachnhanvien.txt", ios::in);
	if (file_nv.is_open())
	{
		file_nv >> countds_nv;
		getline(file_nv, temp);
		for (int i = 0; i < countds_nv; i++)
		{
			NHAN_VIEN* nv = new NHAN_VIEN;
			file_nv >> nv->MANV;
			getline(file_nv, temp);
			getline(file_nv, nv->ho);
			getline(file_nv, nv->ten);
			file_nv >> nv->gioitinh;
			getline(file_nv, temp);

			file_nv >> countds_hd;
			getline(file_nv, temp);
			DS_HD dshd;
			if (countds_hd != -1)
				for (int j = 0; j < countds_hd; j++)
				{
					HOA_DON p;
					getline(file_nv, p.MAHD);
					file_nv >> p.ngay_lap_hd.Ngay;
					getline(file_nv, temp);
					file_nv >> p.ngay_lap_hd.Thang;
					getline(file_nv, temp);
					file_nv >> p.ngay_lap_hd.Nam;
					getline(file_nv, temp);
					file_nv >> p.loai;

					file_nv >> p.tong_tien;
					getline(file_nv, temp);
					file_nv >> countds_ct_hd;
					getline(file_nv, temp);
					for (int l = 0; l < countds_ct_hd; l++)
					{
						CHI_TIET_HOA_DON k;
						getline(file_nv, p.ds_ct_hd.ds[l].MAVT);
						file_nv >> p.ds_ct_hd.ds[l].so_luong;
						getline(file_nv, temp);
						file_nv >> p.ds_ct_hd.ds[l].don_gia;
						getline(file_nv, temp);
						file_nv >> p.ds_ct_hd.ds[l].thue;
						getline(file_nv, temp);
						p.ds_ct_hd.n++;
					}
					Them_HD_Vao_DS(p, dshd);
				}
			nv->ds_hd = dshd;
			ds.ds[i] = nv;
			ds.n++;
		}
	}
	file_nv.close();
}
