#include "fAx7278.h"

inline int fAx7278(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax7278.data[i][j] = 2*bmats.A_7_1.data[i][j] + 2*bmats.A_7_12.data[i][j] + 2*bmats.A_7_13.data[i][j] + 2*bmats.A_7_14.data[i][j] + 2*bmats.A_7_15.data[i][j] + 2*bmats.A_7_16.data[i][j] + 2*bmats.A_7_2.data[i][j] + 2*bmats.A_7_3.data[i][j] + 2*bmats.A_7_4.data[i][j] + 2*bmats.A_7_5.data[i][j] + 2*bmats.A_7_6.data[i][j] - 15*bmats.A_7_7.data[i][j] + 2*bmats.A_7_8.data[i][j] + 2*bmats.A_7_9.data[i][j];
        }
    }
    return 0;
}
