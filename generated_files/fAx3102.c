#include "fAx3102.h"

inline int fAx3102(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3102.data[i][j] = bmats.A_10_21.data[i][j] - 11*bmats.A_10_22.data[i][j] + bmats.A_11_21.data[i][j] - 11*bmats.A_11_22.data[i][j] + bmats.A_1_21.data[i][j] - 11*bmats.A_1_22.data[i][j] + bmats.A_2_21.data[i][j] - 11*bmats.A_2_22.data[i][j] + bmats.A_3_21.data[i][j] - 11*bmats.A_3_22.data[i][j] + bmats.A_4_21.data[i][j] - 11*bmats.A_4_22.data[i][j] + bmats.A_5_21.data[i][j] - 11*bmats.A_5_22.data[i][j] + bmats.A_6_21.data[i][j] - 11*bmats.A_6_22.data[i][j] + bmats.A_7_21.data[i][j] - 11*bmats.A_7_22.data[i][j] + bmats.A_8_21.data[i][j] - 11*bmats.A_8_22.data[i][j] + bmats.A_9_21.data[i][j] - 11*bmats.A_9_22.data[i][j] + bmats.Ax2.data[i][j] + bmats.Ax219.data[i][j] + bmats.Ax274.data[i][j] + bmats.Ax329.data[i][j] + bmats.Ax505.data[i][j] + bmats.Ax509.data[i][j] + bmats.Ax561.data[i][j] + bmats.Ax636.data[i][j] + bmats.Ax658.data[i][j] + bmats.Ax732.data[i][j] + bmats.Ax786.data[i][j];
        }
    }
    return 0;
}
