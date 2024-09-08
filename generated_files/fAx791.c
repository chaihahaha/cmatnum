#include "fAx791.h"

inline int fAx791(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax791.data[i][j] = -16*bmats.A_10_31.data[i][j] + bmats.A_10_32.data[i][j] - 16*bmats.A_11_31.data[i][j] + bmats.A_11_32.data[i][j] - 16*bmats.A_12_31.data[i][j] + bmats.A_12_32.data[i][j] - 16*bmats.A_13_31.data[i][j] + bmats.A_13_32.data[i][j] - 16*bmats.A_14_31.data[i][j] + bmats.A_14_32.data[i][j] - 16*bmats.A_15_31.data[i][j] + bmats.A_15_32.data[i][j] - 16*bmats.A_16_31.data[i][j] + bmats.A_16_32.data[i][j] - 16*bmats.A_1_31.data[i][j] + bmats.A_1_32.data[i][j] - 16*bmats.A_2_31.data[i][j] + bmats.A_2_32.data[i][j] - 16*bmats.A_3_31.data[i][j] + bmats.A_3_32.data[i][j] - 16*bmats.A_4_31.data[i][j] + bmats.A_4_32.data[i][j] - 16*bmats.A_5_31.data[i][j] + bmats.A_5_32.data[i][j] - 16*bmats.A_6_31.data[i][j] + bmats.A_6_32.data[i][j] - 16*bmats.A_7_31.data[i][j] + bmats.A_7_32.data[i][j] - 16*bmats.A_8_31.data[i][j] + bmats.A_8_32.data[i][j] - 16*bmats.A_9_31.data[i][j] + bmats.A_9_32.data[i][j] + bmats.Ax645.data[i][j] + bmats.Ax745.data[i][j] + bmats.Ax748.data[i][j] + bmats.Ax751.data[i][j] + bmats.Ax754.data[i][j] + bmats.Ax757.data[i][j] + bmats.Ax760.data[i][j] + bmats.Ax763.data[i][j] + bmats.Ax766.data[i][j] + bmats.Ax769.data[i][j] + bmats.Ax772.data[i][j] + bmats.Ax775.data[i][j] + bmats.Ax778.data[i][j] + bmats.Ax781.data[i][j] + bmats.Ax784.data[i][j] + bmats.Ax789.data[i][j];
        }
    }
    return 0;
}
