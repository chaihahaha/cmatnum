#include "fAx7772.h"

inline int fAx7772(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax7772.data[i][j] = -15*bmats.A_1_1.data[i][j] + 2*bmats.A_1_10.data[i][j] + 2*bmats.A_1_11.data[i][j] + 2*bmats.A_1_12.data[i][j] + 2*bmats.A_1_13.data[i][j] + 2*bmats.A_1_14.data[i][j] + 2*bmats.A_1_2.data[i][j] + 2*bmats.A_1_3.data[i][j] + 2*bmats.A_1_4.data[i][j] + 2*bmats.A_1_5.data[i][j] + 2*bmats.A_1_6.data[i][j] + 2*bmats.A_1_7.data[i][j] + 2*bmats.A_1_8.data[i][j] + 2*bmats.A_1_9.data[i][j];
        }
    }
    return 0;
}
