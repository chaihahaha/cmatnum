#include "fAx3539.h"

inline int fAx3539(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3539.data[i][j] = -10*bmats.A_10_10.data[i][j] + 2*bmats.A_10_11.data[i][j] + 2*bmats.A_10_2.data[i][j] + 2*bmats.A_10_3.data[i][j] + 2*bmats.A_10_4.data[i][j] + 2*bmats.A_10_5.data[i][j] + 2*bmats.A_10_6.data[i][j] + 2*bmats.A_10_7.data[i][j] + 2*bmats.A_10_8.data[i][j];
        }
    }
    return 0;
}
