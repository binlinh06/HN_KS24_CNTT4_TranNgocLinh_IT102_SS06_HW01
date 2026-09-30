#include <stdio.h>
#include <string.h>

#define MAX_PHIEU 50
#define TIEN_PHAT_MOI_NGAY 5000

int main() {
    char maPhieu[MAX_PHIEU][20];
    int ngayQuaHan[MAX_PHIEU];
    int soLuong = 3;
    int luaChon;

    // Dữ liệu mẫu
    strcpy(maPhieu[0], "PM101");
    ngayQuaHan[0] = 0;

    strcpy(maPhieu[1], "PM102");
    ngayQuaHan[1] = 3;

    strcpy(maPhieu[2], "PM103");
    ngayQuaHan[2] = 5;

    do {
        printf("\n");
        printf("--- HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");

        scanf("%d", &luaChon);

        // Xoa ky tu '\n' con lai trong bo dem
        while (getchar() != '\n');

        switch (luaChon) {

            // =========================================
            // 1. XEM DANH SACH
            // =========================================
            case 1: {
                printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
                printf("%-5s %-15s %-20s %-20s\n",
                       "STT", "Ma Phieu", "So Ngay Qua Han", "Tien Phat (VND)");

                printf("--------------------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {
                    int tienPhat = ngayQuaHan[i] * TIEN_PHAT_MOI_NGAY;

                    printf("%-5d %-15s %-20d %-20d\n",
                           i + 1,
                           maPhieu[i],
                           ngayQuaHan[i],
                           tienPhat);
                }

                printf("--------------------------------------------------------------\n");
                printf("Tong so phieu: %d\n", soLuong);

                break;
            }

            // =========================================
            // 2. THEM MOI PHIEU MUON
            // =========================================
            case 2: {
                if (soLuong >= MAX_PHIEU) {
                    printf("Loi: Danh sach phieu muon da day, khong the them!\n");
                    break;
                }

                printf("Nhap ma phieu muon moi: ");
                scanf("%19s", maPhieu[soLuong]);

                // Moi phieu moi mac dinh 0 ngay qua han
                ngayQuaHan[soLuong] = 0;

                soLuong++;

                printf("Them phieu muon thanh cong!\n");
                printf("So ngay qua han ban dau: 0 ngay.\n");

                break;
            }

            // =========================================
            // 3. CAP NHAT SO NGAY QUA HAN
            // =========================================
            case 3: {
                char maCanTim[20];
                int viTri = -1;
                int ngayMoi;

                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%19s", maCanTim);

                // Tim kiem tuyen tinh bang strcmp()
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maCanTim) == 0) {
                        viTri = i;
                        break;
                    }
                }

                if (viTri == -1) {
                    printf("Loi: Khong tim thay phieu muon '%s'!\n", maCanTim);
                    break;
                }

                printf("Tim thay phieu muon '%s' tai vi tri index %d.\n",
                       maPhieu[viTri], viTri);

                // Nhap so ngay qua han va kiem tra
                do {
                    printf("Nhap so ngay qua han moi: ");
                    scanf("%d", &ngayMoi);

                    if (ngayMoi < 0) {
                        printf("Loi: So ngay qua han phai >= 0. Vui long nhap lai!\n");
                    }

                    while (getchar() != '\n');

                } while (ngayMoi < 0);

                ngayQuaHan[viTri] = ngayMoi;

                printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n",
                       maPhieu[viTri], ngayQuaHan[viTri]);

                break;
            }

            // =========================================
            // 0. THOAT
            // =========================================
            case 0:
                printf("\nCam on ban da su dung he thong LIBRARY_WMS!\n");
                printf("Tam biet!\n");
                break;

            // =========================================
            // LUA CHON KHONG HOP LE
            // =========================================
            default:
                printf("Loi: Chuc nang khong hop le! Vui long chon lai.\n");
        }

    } while (luaChon != 0);

    return 0;
}