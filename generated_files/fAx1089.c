#include "fAx1089.h"

inline int fAx1089(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1089.data[i][j] = bmats.A_10_4.data[i][j] - 11*bmats.A_10_5.data[i][j] + bmats.A_11_4.data[i][j] - 11*bmats.A_11_5.data[i][j] + bmats.A_1_4.data[i][j] - 11*bmats.A_1_5.data[i][j] + bmats.A_2_4.data[i][j] - 11*bmats.A_2_5.data[i][j] + bmats.A_3_4.data[i][j] - 11*bmats.A_3_5.data[i][j] + bmats.A_4_4.data[i][j] - 11*bmats.A_4_5.data[i][j] - 12*bmats.A_5_5.data[i][j] + bmats.A_8_4.data[i][j] - 11*bmats.A_8_5.data[i][j] + bmats.A_9_4.data[i][j] - 11*bmats.A_9_5.data[i][j] + bmats.Ax882.data[i][j] + bmats.Ax885.data[i][j] + bmats.Ax888.data[i][j] + bmats.Ax891.data[i][j] + bmats.Ax894.data[i][j] + bmats.Ax897.data[i][j] + bmats.Ax900.data[i][j] + bmats.Ax903.data[i][j];
        }
    }
    return 0;
}
