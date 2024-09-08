#include "fAx7734.h"

inline int fAx7734(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax7734.data[i][j] = 2*bmats.A_11_1.data[i][j] + 2*bmats.A_11_10.data[i][j] - 15*bmats.A_11_11.data[i][j] + 2*bmats.A_11_12.data[i][j] + 2*bmats.A_11_13.data[i][j] + 2*bmats.A_11_14.data[i][j] + 2*bmats.A_11_2.data[i][j] + 2*bmats.A_11_3.data[i][j] + 2*bmats.A_11_4.data[i][j] + 2*bmats.A_11_5.data[i][j] + 2*bmats.A_11_6.data[i][j] + 2*bmats.A_11_7.data[i][j] + 2*bmats.A_11_8.data[i][j] + 2*bmats.A_11_9.data[i][j];
        }
    }
    return 0;
}
