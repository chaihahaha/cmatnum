#include "fAx3289.h"

inline int fAx3289(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3289.data[i][j] = -11*bmats.A_10_8.data[i][j] + bmats.A_10_9.data[i][j] - 11*bmats.A_11_8.data[i][j] + bmats.A_11_9.data[i][j] - 11*bmats.A_1_8.data[i][j] + bmats.A_1_9.data[i][j] - 11*bmats.A_2_8.data[i][j] + bmats.A_2_9.data[i][j] - 11*bmats.A_3_8.data[i][j] + bmats.A_3_9.data[i][j] - 11*bmats.A_6_8.data[i][j] + bmats.A_6_9.data[i][j] - 11*bmats.A_7_8.data[i][j] + bmats.A_7_9.data[i][j] - 12*bmats.A_8_8.data[i][j] - 11*bmats.A_9_8.data[i][j] + bmats.A_9_9.data[i][j] + bmats.Ax1490.data[i][j] + bmats.Ax1679.data[i][j] + bmats.Ax1765.data[i][j] + bmats.Ax3128.data[i][j] + bmats.Ax3130.data[i][j] + bmats.Ax3132.data[i][j] + bmats.Ax3134.data[i][j] + bmats.Ax426.data[i][j];
        }
    }
    return 0;
}
