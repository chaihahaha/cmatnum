#include "fAx8384.h"

inline int fAx8384(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax8384.data[i][j] = 2*bmats.A_8_1.data[i][j] + 2*bmats.A_8_10.data[i][j] + 2*bmats.A_8_11.data[i][j] + 2*bmats.A_8_12.data[i][j] + 2*bmats.A_8_13.data[i][j] + 2*bmats.A_8_14.data[i][j] + 2*bmats.A_8_15.data[i][j] + 2*bmats.A_8_16.data[i][j] + 2*bmats.A_8_2.data[i][j] + 2*bmats.A_8_3.data[i][j] + 2*bmats.A_8_4.data[i][j] + 2*bmats.A_8_7.data[i][j] - 15*bmats.A_8_8.data[i][j] + 2*bmats.A_8_9.data[i][j];
        }
    }
    return 0;
}
