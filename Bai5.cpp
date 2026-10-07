#include <stdio.h>
#include <string.h>

struct VeMayBay {
    char maDatCho[10];
    char tenHanhKhach[50];
    int hangVe;
    float khoiLuongHanhLy;
    double tongTienVe;
};

int main() {
    struct VeMayBay danhSachVe[100];
    int soLuong = 0;
    int luaChon;

    do {
        printf("================ HE THONG QUAN LY VE MAY BAY VIETJET / VIETNAM AIRLINES ================\n");
        printf("1. Them moi ve may bay (Create)\n");
        printf("2. Hien thi danh sach ve may bay (Read)\n");
        printf("3. Cap nhat hang ve va hanh ly theo ma PNR (Update)\n");
        printf("4. Huy / Xoa ve may bay theo ma PNR (Delete)\n");
        printf("5. Thong ke tong doanh thu va ve co tien thanh toan cao nhat\n");
        printf("6. Thoat chuong trinh\n");
        printf("======================================================================================\n");
        printf("Lua chon cua ban (1-6): ");
        
        if (scanf("%d", &luaChon) != 1) {
            break;
        }
        getchar();

        if (luaChon == 1) {
            if (soLuong >= 100) {
                printf("LOI: Danh sach ve da den gioi han toi da (100)!\n\n");
            } else {
                char tempMa[10];
                printf("\n--- THEM MOI VE MAY BAY ---\n");
                printf("Nhap ma PNR dat cho: ");
                scanf("%s", tempMa);
                getchar();

                int trung = 0;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(danhSachVe[i].maDatCho, tempMa) == 0) {
                        trung = 1;
                        break;
                    }
                }

                if (trung) {
                    printf("LOI: Ma PNR %s da ton tai trong he thong!\n\n", tempMa);
                } else {
                    strcpy(danhSachVe[soLuong].maDatCho, tempMa);
                    printf("Nhap ho ten hanh khach: ");
                    fgets(danhSachVe[soLuong].tenHanhKhach, sizeof(danhSachVe[soLuong].tenHanhKhach), stdin);
                    danhSachVe[soLuong].tenHanhKhach[strcspn(danhSachVe[soLuong].tenHanhKhach, "\n")] = 0;

                    printf("Nhap hang ve (1-Eco, 2-Deluxe, 3-Business): ");
                    scanf("%d", &danhSachVe[soLuong].hangVe);

                    printf("Nhap khoi luong hanh ly ky gui (kg): ");
                    scanf("%f", &danhSachVe[soLuong].khoiLuongHanhLy);
                    getchar();

                    double giaCoBan = 0;
                    if (danhSachVe[soLuong].hangVe == 1) {
                        giaCoBan = 1200000;
                    } else if (danhSachVe[soLuong].hangVe == 2) {
                        giaCoBan = 2500000;
                    } else if (danhSachVe[soLuong].hangVe == 3) {
                        giaCoBan = 5000000;
                    }

                    double phuPhi = 0;
                    if (danhSachVe[soLuong].hangVe == 1 || danhSachVe[soLuong].hangVe == 2) {
                        if (danhSachVe[soLuong].khoiLuongHanhLy > 7.0) {
                            phuPhi = (danhSachVe[soLuong].khoiLuongHanhLy - 7.0) * 50000;
                        }
                    }

                    danhSachVe[soLuong].tongTienVe = giaCoBan + phuPhi;
                    soLuong++;
                    printf("\n--> Them moi ve may bay thanh cong! Tong tien ve: %.0lf VND.\n\n", danhSachVe[soLuong - 1].tongTienVe);
                }
            }
        } else if (luaChon == 2) {
            if (soLuong == 0) {
                printf("\nHien tai chua co ve may bay nao trong he thong.\n\n");
            } else {
                printf("\n%-10s %-22s %-12s %12s %18s\n", "Ma PNR", "Ho Ten Hanh Khach", "Hang Ve", "Hanh Ly (kg)", "Tong Tien (VND)");
                for (int i = 0; i < soLuong; i++) {
                    char tenHang[20];
                    if (danhSachVe[i].hangVe == 1) {
                        strcpy(tenHang, "Eco");
                    } else if (danhSachVe[i].hangVe == 2) {
                        strcpy(tenHang, "Deluxe");
                    } else {
                        strcpy(tenHang, "Business");
                    }
                    printf("%-10s %-22s %-12s %12.1f %18.0lf\n", 
                           danhSachVe[i].maDatCho, 
                           danhSachVe[i].tenHanhKhach, 
                           tenHang, 
                           danhSachVe[i].khoiLuongHanhLy, 
                           danhSachVe[i].tongTienVe);
                }
                printf("\n");
            }
        } else if (luaChon == 3) {
            char tempMa[10];
            printf("\n--- CAP NHAT VE MAY BAY ---\n");
            printf("Nhap ma PNR can sua: ");
            scanf("%s", tempMa);
            getchar();

            int viTri = -1;
            for (int i = 0; i < soLuong; i++) {
                if (strcmp(danhSachVe[i].maDatCho, tempMa) == 0) {
                    viTri = i;
                    break;
                }
            }

            if (viTri == -1) {
                printf("LOI: Khong tim thay ve may bay co ma PNR %s!\n\n", tempMa);
            } else {
                printf("Nhap hang ve moi (1-Eco, 2-Deluxe, 3-Business): ");
                scanf("%d", &danhSachVe[viTri].hangVe);
                printf("Nhap khoi luong hanh ly ky gui moi (kg): ");
                scanf("%f", &danhSachVe[viTri].khoiLuongHanhLy);
                getchar();

                double giaCoBan = 0;
                if (danhSachVe[viTri].hangVe == 1) {
                    giaCoBan = 1200000;
                } else if (danhSachVe[viTri].hangVe == 2) {
                    giaCoBan = 2500000;
                } else if (danhSachVe[viTri].hangVe == 3) {
                    giaCoBan = 5000000;
                }

                double phuPhi = 0;
                if (danhSachVe[viTri].hangVe == 1 || danhSachVe[viTri].hangVe == 2) {
                    if (danhSachVe[viTri].khoiLuongHanhLy > 7.0) {
                        phuPhi = (danhSachVe[viTri].khoiLuongHanhLy - 7.0) * 50000;
                    }
                }

                danhSachVe[viTri].tongTienVe = giaCoBan + phuPhi;
                printf("\n--> Cap nhat ve %s thanh cong! Tong tien moi: %.0lf VND.\n\n", tempMa, danhSachVe[viTri].tongTienVe);
            }
        } else if (luaChon == 4) {
            char tempMa[10];
            printf("\n--- HUY / XOA VE MAY BAY ---\n");
            printf("Nhap ma PNR can huy xoa: ");
            scanf("%s", tempMa);
            getchar();

            int k = -1;
            for (int i = 0; i < soLuong; i++) {
                if (strcmp(danhSachVe[i].maDatCho, tempMa) == 0) {
                    k = i;
                    break;
                }
            }

            if (k == -1) {
                printf("LOI: Khong tim thay ve may bay co ma PNR %s!\n\n", tempMa);
            } else {
                for (int j = k; j < soLuong - 1; j++) {
                    danhSachVe[j] = danhSachVe[j + 1];
                }
                soLuong--;
                printf("--> Da huy va xoa ve [%s] thanh cong!\n\n", tempMa);
            }
        } else if (luaChon == 5) {
            if (soLuong == 0) {
                printf("\nHien tai chua co ve may bay nao trong he thong.\n\n");
            } else {
                double tongDoanhThu = 0;
                int maxIdx = 0;
                for (int i = 0; i < soLuong; i++) {
                    tongDoanhThu += danhSachVe[i].tongTienVe;
                    if (danhSachVe[i].tongTienVe > danhSachVe[maxIdx].tongTienVe) {
                        maxIdx = i;
                    }
                }
                printf("\n--- THONG KE FINTECH & DOANH THU ---\n");
                printf("Tong doanh thu cac ve hien tai: %.0lf VND\n", tongDoanhThu);
                printf("Thong tin ve co tong tien cao nhat:\n");
                printf("- Ma PNR: %s\n", danhSachVe[maxIdx].maDatCho);
                printf("- Hanh khach: %s\n", danhSachVe[maxIdx].tenHanhKhach);
                printf("- Tong tien: %.0lf VND\n\n", danhSachVe[maxIdx].tongTienVe);
            }
        } else if (luaChon == 6) {
            printf("Da thoat chuong trinh.\n");
            break;
        } else {
            printf("Lua chon khong hop le. Vui long chon lai tu 1 den 6.\n\n");
        }

    } while (luaChon != 6);

    return 0;
}
