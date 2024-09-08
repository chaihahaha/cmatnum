#include "fAx3657.h"

inline int fAx3657(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3657.data[i][j] = 2*bmats.A_3_10.data[i][j] + 2*bmats.A_3_11.data[i][j] - 10*bmats.A_3_3.data[i][j] + 2*bmats.A_3_4.data[i][j] + 2*bmats.A_3_5.data[i][j] + 2*bmats.A_3_6.data[i][j] + 2*bmats.A_3_7.data[i][j] + 2*bmats.A_3_8.data[i][j] + 2*bmats.A_3_9.data[i][j];
        }
    }
    return 0;
}
